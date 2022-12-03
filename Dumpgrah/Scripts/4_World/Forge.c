/*
m_FireplaceRadius = is how far the fireplace light shines

m_FireplaceBrightness = is how bright it is

TimeBeforeSmelting = how many seconds before the smelter locks when said variables are met

SetTemperature = how Hot the Furnace will show in Celsius, in the futrue will affect how much heat it provides to said area and also dmg to player if player is too close

ItemGoesHere().GetQuantity() >=  // this is a call to check how much of an item thats just before this to have before starting the smelting operation, if the number is below the number you put just after the >= sign it will not trigger the function(ItemGoesHere = the name of the item you wish to check for quantity off). 

Lock(#) = how long the smelters function will lock the attachments and inventory (if present) of said smelter. when its done in its timer it will unlock and show the contents.

Note 
*/
class ND_ForgewHood extends ND_ForgeBase
{

	override void OnWork( float consumed_energy  )
	{
		
		if ( GetGame() && GetGame().IsServer()  )
		{
			StartHeating();
			float temperature = GetTemperature();
			temperature = temperature + 35;
			SetTemperature( temperature );
			
			TransferHeatToNearPlayers();
			BurnItemsInFireplace();
			CreateAreaDamage();


		}		
	};
	protected void StartHeating()
	{		
		m_HeatingTimer = new Timer ( CALL_CATEGORY_GAMEPLAY );
		m_HeatingTimer.Run ( 3, this, "Heating", NULL, true );	
	};
	protected void StopCooling()
	{
		//Stop cooling
		m_CoolingTimer.Stop();
		m_CoolingTimer = NULL;

	
	};
	protected void TransferHeatToNearPlayers()
	{
		float distance;

		ref array<Object> nearest_objects = new array<Object>;
		ref array<CargoBase> proxy_cargos = new array<CargoBase>;

		GetGame().GetObjectsAtPosition ( GetPosition(), 8, nearest_objects, proxy_cargos ); 

		for ( int i = 0; i < nearest_objects.Count(); i++ )
		{
			Object nearest_object = nearest_objects.Get(i);
			
			//! heat transfer to player
			if ( nearest_object.IsInherited( PlayerBase ) )
			{
				PlayerBase player = PlayerBase.Cast( nearest_object );
				distance = vector.Distance( player.GetPosition(), GetPosition() );
				distance = Math.Max( distance, 0.1 );	//min distance cannot be 0 (division by zero)
				float temperature = 0;
				
				//! heat transfer through air to player ( anv temperature )
				if ( distance > 0.005 )
				{
					float distFactor = 1 - (distance/8);
					temperature = GetTemperature() * ( 0.030 * distFactor);
				}
				else
					temperature = GetTemperature() * ( 0.030 );
				
				player.AddToEnvironmentTemperature( temperature );
			}
			//! heat transfer to items (not in player possession)
			else if ( nearest_object != this && nearest_object.IsInherited( ItemBase ) && nearest_object.GetParent() == null )
			{
				ItemBase item = ItemBase.Cast( nearest_object );
				float wetness = item.GetWet();

				//! drying of items around the fireplace (based on distance)
				if ( wetness > 0 )
				{
					distance = vector.Distance( item.GetPosition(), GetPosition() );
					distance = Math.Max( distance, 0.1 );	//min distance cannot be 0 (division by zero)
					
					wetness = wetness * ( 0.030 / distance );
					wetness = Math.Clamp( wetness, item.GetWetMin(), item.GetWetMax() );
					item.AddWet( -wetness );
				}
			}
		}
	};
};
class ND_ForgeBase extends ItemBase
{	

	protected FireplaceLight m_Light; // Light entity

	protected int PARTICLE_Smoke_Start 			= ParticleList.ForgeSmoke;
	protected int PARTICLE_Fire_START           = ParticleList.SmelterFire;
	protected Particle m_ParticleSmokeStart;
	protected Particle m_PaticleFireStart;

		
	protected int					m_FirePointIndex = 1;	//limited to 1 decimal place (1-9)
	
	static const string FIREPOINT_FIRE_POSITION 	= "fireplace_point";
	static const string FIREPOINT_SMOKE_POSITION 	= "fireplace_smoke";
	static const string FIREPOINT_LIGHT_POSITION    = "fireplace_light";
	static float m_FireplaceRadius = 5;
	static float m_FireplaceBrightness = 2.75;
	private ref Timer m_FurnaceSmeltTime;
	ref Timer m_TimeBeforeSmelting;
	private bool m_IsLocked = false;
	bool m_IsCurrentlySmelting = false;
	protected bool ActionCondition
	protected ref Timer m_HeatingTimer;
	protected ref Timer m_CoolingTimer;
	protected ref AreaDamageBase 		m_AreaForgeDamage;
	
	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();

		if( GetCompEM().IsWorking() && !m_AreaForgeDamage )
		{
			CreateAreaDamage();
		}
		else if ( !GetCompEM().IsWorking() && m_AreaForgeDamage )
		{
			DestroyAreaDamage();
		}

	}
	void ND_ForgeBase()
	{
		m_FurnaceSmeltTime = new Timer();
		m_TimeBeforeSmelting = new Timer();
		
	};
	override void EEInit()
	{
		ShowSimpleSelection("HotCoals", 0);
		ShowSimpleSelection("HotCoalsBurning", 0);
	};
	
	private void ShowSimpleSelection(string selectionName, bool hide = false)
    {
        TStringArray selectionNames = new TStringArray;
        ConfigGetTextArray("simpleHiddenSelections",selectionNames);
        int selectionId = selectionNames.Find(selectionName);
        SetSimpleHiddenSelectionState(selectionId, hide);
    };
	
	FireplaceLight GetLightEntity()
	{
		return m_Light;
	};
	
	void SetLightEntity( FireplaceLight light )
	{
		m_Light = light;
	};
	
	bool IsLocked()
	{
		return m_IsLocked;

	};

	void TimeBeforeSmelting( float actiontime)
	{
		m_TimeBeforeSmelting.Run(actiontime, this, "DoNothing", NULL, false);
	};
	
	void DoNothing() // timer required 
	{
		
	}

	protected bool PlayParticle( out Particle particle, int particle_type, vector local_pos )
	{
		if ( !particle && GetGame() && ( !GetGame().IsMultiplayer() || GetGame().IsClient() ) )
		{
			particle = Particle.PlayOnObject( particle_type, this, local_pos );
			
			return true;
		}
		
		return false;
	};
	
	protected bool StopParticle( out Particle particle )
	{
		if ( particle && GetGame() && ( !GetGame().IsMultiplayer() || GetGame().IsClient() ) )
		{
			particle.Stop();
			particle = NULL;
			
			return true;
		}
		
		return false;
	};
	
	bool IsItemTypeAttached( typename item_type )
	{
		if ( GetAttachmentByType( item_type ) )
		{
			return true;
		}
		
		return false;
	};
	
	//Has attachments of required quantity
	bool IsItemAttachedQuantity( typename item_type, float quantity )
	{
		ItemBase item = ItemBase.Cast( GetAttachmentByType( item_type ) );
		
		if ( item.GetQuantity() >= quantity )
		{
			GetLightEntity().SetInteriorMode();
			return true;
		}
		
		return false;
	};


	override void EEItemAttached(EntityAI item, string slot_name)
	{
		super.EEItemAttached(item,slot_name);
		ND_IngotBase Ingot = ND_IngotBase.Cast( item.GetAttachmentByType(ND_IngotBase) );
		if(slot_name == "ND_Coal")
		{
			if ( item.IsKindOf("ND_StackedCoal") || item.IsKindOf("ND_Charcoal")) // any attachment but coal
			{
				SetTemperature(1);
				StopCooling();
				ShowSimpleSelection("HotCoals", 1);
				ShowSimpleSelection("HotCoalsBurning", 0);
			};
		};
	};
	
	override void EEItemDetached(EntityAI item, string slot_name)
	{
		super.EEItemDetached(item, slot_name);
		PlayerBase player;
		if(slot_name == "ND_Coal")
		{
			if ( item.IsKindOf("ND_StackedCoal") || item.IsKindOf("ND_Charcoal")) // any attachment but coal
			{
				ShowSimpleSelection("HotCoals", 0);
				ShowSimpleSelection("HotCoalsBurning", 0);
			};
		};
	};

	void Lock(float actiontime)
	{	

		m_IsLocked = true;
		m_FurnaceSmeltTime.Run(actiontime, this, "Unlock", NULL,false);
		GetInventory().LockInventory(HIDE_INV_FROM_SCRIPT);
		//RemoveAction(ActionTurnOffWhileOnGround) = false;
		if(GetGame().IsClient() || !GetGame().IsMultiplayer())
		{
		  ParticleSmokeStart();
		}

	};

	
	protected void ParticleSmokeStart()
	{
		PlayParticle( m_ParticleSmokeStart, PARTICLE_Smoke_Start, GetMemoryPointPos("fireplace_smoke") );
	};
	
	
	void Unlock()
	{
		m_IsLocked = false;
		GetInventory().UnlockInventory(HIDE_INV_FROM_SCRIPT);
		
	};

	override void OnWork( float consumed_energy  )
	{
		
		if ( GetGame() && GetGame().IsServer()  )
		{
			StartHeating();
			float temperature = GetTemperature();
			temperature = temperature + 10;
			SetTemperature( temperature );
			TransferHeatToNearPlayers();
			BurnItemsInFireplace();
			CreateAreaDamage();
		}		
	};
	
	override void OnWorkStart()
	{

		if ( !GetLightEntity() && (!GetGame().IsMultiplayer() || GetGame().IsClient() ) )
		{
		   PlayParticle( m_PaticleFireStart, PARTICLE_Fire_START, GetMemoryPointPos("fireplace_point") );
		   PlayParticle( m_ParticleSmokeStart, PARTICLE_Smoke_Start, GetMemoryPointPos("fireplace_smoke") );
		   SetLightEntity( FireplaceLight.Cast( ScriptedLightBase.CreateLight(FireplaceLight, GetMemoryPointPos("fireplace_light") ) ) );
		   GetLightEntity().AttachOnMemoryPoint(this, "fireplace_light");
		   TransferHeatToNearPlayers();	
		   ShowSimpleSelection("HotCoalsBurning", 1);
		   ShowSimpleSelection("HotCoals", 0);
		
		}
		Lockcoal(true);

	};
	
	override void OnWorkStop()
	{
		m_IsCurrentlySmelting = false;
		StopParticle(m_PaticleFireStart);
		StopParticle(m_ParticleSmokeStart);
		GetLightEntity().FadeOut();
		Lockcoal(false);
		StopHeating();
		StartCooling();
		ShowSimpleSelection("HotCoalsBurning", 0);
		ShowSimpleSelection("HotCoals", 1);

		
	};
	
	protected void TransferHeatToNearPlayers()
	{
		float distance;

		ref array<Object> nearest_objects = new array<Object>;
		ref array<CargoBase> proxy_cargos = new array<CargoBase>;

		GetGame().GetObjectsAtPosition ( GetPosition(), 8, nearest_objects, proxy_cargos ); 

		for ( int i = 0; i < nearest_objects.Count(); i++ )
		{
			Object nearest_object = nearest_objects.Get(i);
			
			//! heat transfer to player
			if ( nearest_object.IsInherited( PlayerBase ) )
			{
				PlayerBase player = PlayerBase.Cast( nearest_object );
				distance = vector.Distance( player.GetPosition(), GetPosition() );
				distance = Math.Max( distance, 0.1 );	//min distance cannot be 0 (division by zero)
				float temperature = 0;
				
				//! heat transfer through air to player ( anv temperature )
				if ( distance > 0.1 )
				{
					float distFactor = 1 - (distance/8);
					temperature = GetTemperature() * ( 0.025 * distFactor);
				}
				else
					temperature = GetTemperature() * ( 0.025 );
				
				player.AddToEnvironmentTemperature( temperature );
			}
			//! heat transfer to items (not in player possession)
			else if ( nearest_object != this && nearest_object.IsInherited( ItemBase ) && nearest_object.GetParent() == null )
			{
				ItemBase item = ItemBase.Cast( nearest_object );
				float wetness = item.GetWet();

				//! drying of items around the fireplace (based on distance)
				if ( wetness > 0 )
				{
					distance = vector.Distance( item.GetPosition(), GetPosition() );
					distance = Math.Max( distance, 0.1 );	//min distance cannot be 0 (division by zero)
					
					wetness = wetness * ( 0.030 / distance );
					wetness = Math.Clamp( wetness, item.GetWetMin(), item.GetWetMax() );
					item.AddWet( -wetness );
				}
			}
		}
	};
	
	protected void StartHeating()
	{		
		m_HeatingTimer = new Timer ( CALL_CATEGORY_GAMEPLAY );
		m_HeatingTimer.Run ( 5, this, "Heating", NULL, true );	
	};

	protected void StopHeating()
	{
		m_HeatingTimer.Stop();
		m_HeatingTimer = NULL;
	};
	
	void StartCooling()
	{
		if ( m_HeatingTimer )
		{
			m_HeatingTimer.Stop();
			m_HeatingTimer = NULL;
		}
		
		m_CoolingTimer = new Timer( CALL_CATEGORY_GAMEPLAY );
		m_CoolingTimer.Run( 5, this, "Cooling", NULL, true );		// true param loops
	};
	
	void Cooling()
	{
		float temperature = GetTemperature();
		temperature = temperature - 12;

		SetTemperature(temperature);
		
		if ( GetTemperature() == 1)
		{
			m_CoolingTimer.Stop();
			m_CoolingTimer = NULL;
			//Print("zxd");
		}
	};
	
	protected void StopCooling()
	{
		//Stop cooling
		m_CoolingTimer.Stop();
		m_CoolingTimer = NULL;

	
	};
	
	//Do heating
	protected void Heating()
	{

		float temperature = GetTemperature();
		temperature = temperature + 20;
		SetTemperature( temperature );
	};
	
	void Lockcoal(bool do_lock)
	{
		ItemBase StackedCoal = GetStackCoal();
		ItemBase StackedCharcoal = GetCharcoal();
		
		if (StackedCoal|| StackedCharcoal)
		{
			if (do_lock)
			{
				if(StackedCoal)
				{
					StackedCoal.LockToParent();
				}
				else if(StackedCharcoal)
				{
					StackedCharcoal.LockToParent();
				};
			}
			else
			{
				if(StackedCoal)
				{
					StackedCoal.UnlockFromParent();
				}
				else if(StackedCharcoal)
				{
					StackedCharcoal.UnlockFromParent();
				};
			};
		}
	}
	
	ND_StackedCoal GetStackCoal()
	{
		return ND_StackedCoal.Cast( GetAttachmentByType(ND_StackedCoal) );
	}
	ND_Charcoal GetCharcoal()
	{
		return ND_Charcoal.Cast( GetAttachmentByType(ND_Charcoal) );
	}
	protected void BurnItemsInFireplace()
	{

		
		//Fuel (only) attachments
		for ( int j = 0; j < GetInventory().AttachmentCount(); ++j )
		{
			ItemBase attachment = ItemBase.Cast( GetInventory().GetAttachmentFromIndex( j ) );

			//add temperature
			AddTemperatureToItemByFire( attachment );
		
		}
	};
	
		//add temperature to item by fire
	protected void AddTemperatureToItemByFire( ItemBase item )
	{
		if ( item.GetTemperatureMax())
		{
			float temperature = item.GetTemperature();
			temperature = temperature + 5;
			item.SetTemperature( temperature );
		}
	};
	
	void CreateAreaDamage()
	{
		//destroy area damage if some already exists
		DestroyAreaDamage();
		
		//create new area damage
		m_AreaForgeDamage = new AreaDamageRegularDeferred( this );
		m_AreaForgeDamage.SetExtents("-0.25 0 -0.25", "0.25 1.8 0.25");
		m_AreaForgeDamage.SetLoopInterval( 0.5 );
		m_AreaForgeDamage.SetDeferDuration( 0.5 );
		m_AreaForgeDamage.SetHitZones( { "Head","Torso","LeftHand","LeftLeg","LeftFoot","RightHand","RightLeg","RightFoot" } );
		m_AreaForgeDamage.SetAmmoName( "FireDamage" );
		m_AreaForgeDamage.Spawn();
	}
	
	void DestroyAreaDamage()
	{
		if ( m_AreaForgeDamage ) 
		{
			m_AreaForgeDamage.Destroy();
		}
	}
	
	override bool CanPutIntoHands( EntityAI parent )
    {
        super.CanPutIntoHands( parent );    

        //if ( GetInventory().AttachmentCount() == 0)
        //{
        //    return true;
        //}
		if (GetInventory().AttachmentCount() > 0)
		{
			return false;
		}
        return true;

    }
	override bool CanPutInCargo( EntityAI parent )
    {
		super.CanPutInCargo(parent);
		if ( GetTemperature() >=1 && GetInventory().AttachmentCount() >= 0)
		{
			return false;
		}
        return true;
    }
	
	override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" )
	{		
		super.OnPlacementComplete( player, position, orientation );
		SetTemperature(0);

		SetIsPlaceSound( true );
	}
	override string GetPlaceSoundset()
	{
		return "placeBarrel_SoundSet";
	}

	
	override void SetActions()
	{
		super.SetActions();

		//AddAction(ActionSmotherSmelter);
		//AddAction(ActionTurnOnWhileOnGround);
		AddAction(ActionTogglePlaceObject);
		AddAction(ActionPlaceObject);
		AddAction(ActionAttach);
		AddAction(ActionDetach);
		AddAction(ActionAttachOnProxy);
	}
	//Tips.GetQuantity() == Tips.GetQuantityMax() && !m_TimeBeforeSmelting.IsRunning()
};
