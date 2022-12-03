/*
m_FireplaceRadius = is how far the fireplace light shines

m_FireplaceBrightness = is how bright it is

TimeBeforeSmelting = how many seconds before the smelter locks when said variables are met

SetTemperature = how Hot the Furnace will show in Celsius, in the futrue will affect how much heat it provides to said area and also dmg to player if player is too close

ItemGoesHere().GetQuantity() >=  // this is a call to check how much of an item thats just before this to have before starting the smelting operation, if the number is below the number you put just after the >= sign it will not trigger the function(ItemGoesHere = the name of the item you wish to check for quantity off). 

Lock(#) = how long the smelters function will lock the attachments and inventory (if present) of said smelter. when its done in its timer it will unlock and show the contents.

Note 
*/

class ND_Charcoal extends ItemBase
{
	override void InitItemVariables()
	{
		super.InitItemVariables();
		can_this_be_combined = true;
	};
	override bool CanPutAsAttachment( EntityAI parent )
	{
		//if ( parent.IsKindOf("ND_Smelter") || parent.IsKindOf("ND_ImprovedSmelter") )
		//{
		//	return false;
		//}
		return true;
	}
};
class ND_SplitWood extends ItemBase{};
class ND_UnFiredBricks extends ItemBase{};
class ND_FiredBricks extends ItemBase{};
class SmelterBase extends ItemBase
{
	bool IsNDLocked()
	{
		return false;
	};
};

class ND_Smelter extends SmelterBase
{	

	protected FireplaceLight m_Light; // Light entity

	protected int PARTICLE_Smoke_Start 			= ParticleList.SmelterSmoke;
	protected int PARTICLE_Smoke_Startidle 		= ParticleList.SmelterSmokeIdle;
	protected int PARTICLE_Fire_START           = ParticleList.SmelterFire;
	protected Particle m_ParticleSmokeStart;
	protected Particle m_ParticleSmokeIdle;
	protected Particle m_PaticleFireStart;
	
	protected int					m_FirePointIndex = 1;	//limited to 1 decimal place (1-9)
	
	static const string FIREPOINT_FIRE_POSITION 	= "fireplace_point";
	static const string FIREPOINT_SMOKE_POSITION 	= "fireplace_smoke";
	static const string FIREPOINT_SMOKEIDLE_POSITION = "fireplace_smoke_idle";
	static const string FIREPOINT_LIGHT_POSITION    = "fireplace_light";
	static float m_FireplaceRadius = 5;
	static float m_FireplaceBrightness = 2.75;
	ref Timer m_FurnaceSmeltTime;
	ref Timer m_TimeBeforeSmelting;
	private bool m_IsLocked = false;
	protected bool m_IsNDLocked = false;
	bool m_IsCurrentlySmelting = false;
	protected bool ActionCondition
	protected bool m_IsIgnited;
	protected ref Timer m_HeatingTimer;
	protected ref Timer m_CoolingTimer;
	const string OBJECT_CLUTTER_CUTTER 	= "ClutterCutterFireplace";

	float Smelt_Temp_Iron = GetSmelterSettings().CrudeSmeltIronSmeltTemperature;
	float Time_To_Smelt_Iron = GetSmelterSettings().CrudeTimeToSmeltIron;
	float Smelt_Iron_EfficiencyMin = GetSmelterSettings().CrudeSmeltIronEfficiencyMin;
	float Smelt_Iron_EfficiencyMax = GetSmelterSettings().CrudeSmeltIronEfficiencyMax;
	float Time_To_Smelt_PureIron = GetSmelterSettings().CrudeTimeToSmeltPureIron;
	float Smelt_PureIron_EfficiencyMin = GetSmelterSettings().CrudeSmeltPureIronEfficiencyMin;
	float Smelt_PureIron_EfficiencyMax = GetSmelterSettings().CrudeSmeltPureIronEfficiencyMax;
	float Time_To_Smelt_Charcoal = GetSmelterSettings().CrudeSmelterTimeToSmeltCharcoal;
	float HeatingRate = GetSmelterSettings().CrudeSmelterHeatingRate;
	float CoolingRate = GetSmelterSettings().CrudeSmelterCoolingRate;
	float Time_To_Fire_Clay = GetSmelterSettings().CrudeCureClayItems;
	
	#ifdef AM_MOD_221
	int TimeToSmeltTips = GetAmmoSmelting().Time_To_Smelt_Tips;
	int TimeToSmeltCasing = GetAmmoSmelting().Time_To_Smelt_Casing;
	int EfficiencyMin = GetAmmoSmelting().Smelter_Efficiency_Min;  
    int EfficiencyMax = GetAmmoSmelting().Smelter_Efficiency_Max;
	#endif
	
	override bool CanHaveTemperature()
	{
		return true;
	};
	
	int HeatingTemp = 0;
	bool SmeltTimerRunning = 0;
	
	
	void ND_Smelter()
	{
		m_FurnaceSmeltTime = new Timer();
		m_TimeBeforeSmelting = new Timer();
		RegisterNetSyncVariableBool("m_IsNDLocked");
		RegisterNetSyncVariableFloat("m_FurnaceSmeltTime");
		LockSmelting(false);

		if(!m_FurnaceSmeltTime)
			SmeltTimerRunning = 0;
		else
			SmeltTimerRunning = 1;
	};		
	FireplaceLight GetLightEntity()
	{
		return m_Light;
	}
	
	void SetLightEntity( FireplaceLight light )
	{
		m_Light = light;
	}


	
	override bool IsNDLocked()
	{
		if(m_IsNDLocked == true)
		{
			return true;
		}
		else
		{
			return false;
		};
		
		SetSynchDirty();
	};

	void TimeBeforeSmelting( float actiontime)
	{
		m_TimeBeforeSmelting.Run(actiontime, this, "DoNothing", NULL, false);
	}
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
	}
	protected bool StopParticle( out Particle particle )
	{
		if ( particle && GetGame() && ( !GetGame().IsMultiplayer() || GetGame().IsClient() ) )
		{
			particle.Stop();
			particle = NULL;
			
			return true;
		}
		
		return false;
	}
	bool IsItemTypeAttached( typename item_type )
	{
		if ( GetAttachmentByType( item_type ) )
		{
			return true;
		}
		
		return false;
	}
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
	}

	
	
	override bool NameOverride(out string output)
	{
		if ( m_IsNDLocked == true )
		{
			output = "Currently Smelting";  //changes object displayed name if in 'gate' state
			output.ToUpper();
			return true;
		}
		return false;
	};
	override bool DescriptionOverride(out string output)
	{
		if ( m_IsNDLocked == true )
		{
			output ="Smelting In Progress";
			output.ToUpper();
			return true;
		}
		return false;
	};
	
	void Lock(float actiontime)
	{	
		m_IsNDLocked = true;
		SmeltTimerRunning = 1;
		SetSynchDirty();
		m_FurnaceSmeltTime.Run(actiontime, this, "Unlock", NULL,false);
		LockSmelting(true);
		//if(GetGame().IsClient() || !GetGame().IsMultiplayer())
		//{

		//};

	};
	
	void Unlock()
	{
		m_IsNDLocked = false;
		SmeltTimerRunning = 0;
		SetSynchDirty();
		LockSmelting(false);
		m_FurnaceSmeltTime.Stop();

		//PlayParticle( m_ParticleSmokeIdle, PARTICLE_Smoke_Startidle, GetMemoryPointPos("fireplace_smoke") );
		//StopParticle(m_ParticleSmokeStart);
	};

	
	protected void ParticleSmokeStart()
	{
		PlayParticle( m_ParticleSmokeStart, PARTICLE_Smoke_Start, GetMemoryPointPos("fireplace_smoke") );
	}
	protected void ParticleSmokeStartIdle()
	{
		PlayParticle( m_ParticleSmokeIdle, PARTICLE_Smoke_Startidle, GetMemoryPointPos("fireplace_smoke_idle") );
	}
	

	override void OnWork( float consumed_energy  )
	{
		
		if ( GetGame() && GetGame().IsServer()  )
		{
			Lockcoal(true);
			if(GetMoltenMetalBase())
			{
				AddTemperatureToCrucibleByFire();
			}
			#ifdef AM_MOD_221
			else if (GetMoltenBrass() || GetMoltenLead())
			{
				AddTemperatureToCrucibleByFire();
			};
			#endif

			if (GetClayCrucibleBase() || GetCrucibleMetalBase() ||GetFirewood() || GetUnFiredBricks() || GetClayIncasedIngot() || GetUnfiredCrucible())
			{
				Smelt();		
			}
			#ifdef AM_MOD_221
			else if ( GetTheTip() || GetCasing() || GetLead() || GetClayCasing() || GetClayTheTip() || GetClayLead() )
			{
				AddTemperatureToCrucibleByFire();
			};
			#endif
		};
		//Print("m_IsNDLocked = " + m_IsNDLocked + " && IsNDLocked = " + IsNDLocked())
		
		if(SmeltTimerRunning == 1 && !IsNDLocked())
		{
			Unlock();
			//Print("SmeltTimerRunning = " + SmeltTimerRunning)
			//Print("Unlocked Triggered = false?? " + IsNDLocked())
		};
		
		
			
	};
	override void OnWorkStart()
	{
		StartHeating();
		StopCooling();
		if ( !GetLightEntity() && (!GetGame().IsMultiplayer() || GetGame().IsClient() ) )
		{
		   PlayParticle( m_PaticleFireStart, PARTICLE_Fire_START, GetMemoryPointPos("fireplace_point") );
		   PlayParticle( m_ParticleSmokeStart, PARTICLE_Smoke_Start, GetMemoryPointPos("fireplace_smoke") );
		   SetLightEntity( FireplaceLight.Cast( ScriptedLightBase.CreateLight(FireplaceLight, GetMemoryPointPos("fireplace_light") ) ) );
		   GetLightEntity().AttachOnMemoryPoint(this, "fireplace_light");
		}

	}
	override void OnWorkStop()
	{
		m_IsCurrentlySmelting = false;
		StopParticle(m_PaticleFireStart);
		StopParticle(m_ParticleSmokeStart);
		StopParticle(m_ParticleSmokeIdle);
		GetLightEntity().FadeOut();
		Lockcoal(false);
		StopHeating();
		StartCooling();
		

	};
	//protected void BurnItemsInFireplace()
	//{
	//	//! cargo
	//	CargoBase cargo = GetInventory().GetCargo();
	//	for (int i = 0; i < cargo.GetItemCount(); i++)
	//	{
	//		ItemBase item = ItemBase.Cast(cargo.GetItem(i));
	//
	//		//add temperature
	//		AddTemperatureToItemByFire(item);
	//	}
	//	
	//	//! attachments
	//	for (int j = 0; j < GetInventory().AttachmentCount(); ++j)
	//	{
	//		ItemBase attachment = ItemBase.Cast(GetInventory().GetAttachmentFromIndex(j));
	//
	//		//add temperature
	//		AddTemperatureToItemByFire(attachment);
	//	}
	//};
	void AddTemperatureToCrucibleByFire()
	{
		int DividingTemp = 12;
		float HeatingTemp = GetTemperature();
		
		float FinalTemp = HeatingTemp/DividingTemp;
		
		Print("Crucible Heated by = " + FinalTemp + " + " + HeatingRate);
		
		float temperature = FinalTemp + HeatingRate;
		if(GetMoltenMetalBase())
		{
			GetMoltenMetalBase().AddTemperature(FinalTemp);
		};
		#ifdef AM_MOD_221
		if(GetMoltenBrass())
		{
			GetMoltenBrass().AddTemperature(FinalTemp);
		}
		else
		{
			GetMoltenLead().AddTemperature(FinalTemp);
		};
		#endif
	};


	protected void StartHeating()
	{		
		m_HeatingTimer = new Timer ( CALL_CATEGORY_GAMEPLAY );
		m_HeatingTimer.Run ( 2, this, "Heating", NULL, true );	
	}

	protected void StopHeating()
	{
		m_HeatingTimer.Stop();
		m_HeatingTimer = NULL;
	}
	protected void StartCooling()
	{
		if ( m_HeatingTimer )
		{
			m_HeatingTimer.Stop();
			m_HeatingTimer = NULL;
		}
		
		m_CoolingTimer = new Timer( CALL_CATEGORY_GAMEPLAY );
		m_CoolingTimer.Run( 2, this, "Cooling", NULL, true );		// true param loops
	}
	void Cooling()
	{
		if(GetGame().IsServer())
		{
			float temperature = GetTemperature();
			temperature = temperature - CoolingRate;
	
			SetTemperature(temperature);
	
			if ( GetTemperature() == 1)
			{
				StopCooling();
				m_CoolingTimer.Stop();
				m_CoolingTimer = NULL;
				//Print("zxd");
			}
		};
	};
	void StopCooling()
	{
		//Stop cooling
		m_CoolingTimer.Stop();
		m_CoolingTimer = NULL;

	}

	//Do heating
	protected void Heating()
	{
			float temperature = GetTemperature();
			temperature = temperature + HeatingRate;
			SetTemperature( temperature + 30 );

		
	}
	
	void Lockcoal(bool do_lock)
	{
		ItemBase StackedCoal = GetStackCoal();
		
		if (StackedCoal)
		{
			if (do_lock)
			{
				StackedCoal.LockToParent();
			}
			else
			{
				StackedCoal.UnlockFromParent();
			}
		}
	};
    void LockSmelting(bool do_lock)
    {
        ItemBase MoltenMetal = GetMoltenMetalBase();
        ItemBase HotCharcoal = GetCharcoal();
        ItemBase HotBricks = GetFiredBricks();
        if (do_lock)
        {
            if ( MoltenMetal )
			{
		
                MoltenMetal.LockToParent();
            }
            if ( HotCharcoal)
			{
		
                 HotCharcoal.LockToParent();
            }
            if (HotBricks)
			{
		
                 HotBricks.LockToParent();
            }
        }
        else
        {
            if ( MoltenMetal )
			{
		
                 MoltenMetal.UnlockFromParent();
            }
            if ( HotCharcoal)
			{
		
                 HotCharcoal.UnlockFromParent();
            }
            if ( HotBricks)
			{
		
                 HotBricks.UnlockFromParent();
            }
        };
		#ifdef AM_MOD_221
		ItemBase MoltenLead = GetMoltenLead();
		ItemBase MoltenBrass = GetMoltenBrass();
        if (do_lock)
        {
            if ( MoltenLead )
			{
		
                MoltenLead.LockToParent();
            }
            if ( MoltenBrass)
			{
		
                 MoltenBrass.LockToParent();
            }
			/*
            if (HotBricks)
			{
		
                 HotBricks.LockToParent();
            }
			*/
        }
		else
		{
		    if ( MoltenLead )
			{
                MoltenLead.UnlockFromParent();
            }
            if ( MoltenBrass)
			{
                 MoltenBrass.UnlockFromParent();
            }
			/*
            if (HotBricks)
			{
		
                 HotBricks.UnlockFromParent();
            }
			*/
		};
		#endif
    };


	ND_ClayCrucibleBase GetClayCrucibleBase()
	{
		return ND_ClayCrucibleBase.Cast( GetAttachmentByType (ND_ClayCrucibleBase) );
	};
	ND_CrucibleBase GetCrucibleMetalBase()
	{
		return ND_CrucibleBase.Cast( GetAttachmentByType (ND_CrucibleBase) );
	};
	ND_ClayMoltenCrucible GetClayMoltenMetalBase()
	{
		return ND_ClayMoltenCrucible.Cast( GetAttachmentByType (ND_ClayMoltenCrucible) );
	};
	
	ND_MoltenCrucible GetMoltenMetalBase()
	{
		return ND_MoltenCrucible.Cast( GetAttachmentByType (ND_MoltenCrucible) );
	};	
	ND_UnfiredClayEmptyCrucible GetUnfiredCrucible()
	{
		return ND_UnfiredClayEmptyCrucible.Cast( GetAttachmentByType (ND_UnfiredClayEmptyCrucible) );
	}
	ND_FiredBricks GetFiredBricks()
	{
		return ND_FiredBricks.Cast( GetAttachmentByType (ND_FiredBricks) );
	}
	ND_UnFiredBricks GetUnFiredBricks()
	{
		return ND_UnFiredBricks.Cast( GetAttachmentByType (ND_UnFiredBricks) );
	}
	ND_SplitWood GetFirewood()
	{
		return ND_SplitWood.Cast(GetAttachmentByType(ND_SplitWood) );
	}
	ND_Charcoal GetCharcoal()
	{
		return ND_Charcoal.Cast(GetAttachmentByType(ND_Charcoal) );
	}
	ND_StackedCoal GetStackCoal()
	{
		return ND_StackedCoal.Cast( GetAttachmentByType(ND_StackedCoal) );
	}
	
	ND_CrucibleOreCopper GetCopper()
	{
		return ND_CrucibleOreCopper.Cast( GetAttachmentByType(ND_CrucibleOreCopper) );
	}

	ND_CrucibleOreZinc GetZinc()
	{
		return ND_CrucibleOreZinc.Cast( GetAttachmentByType(ND_CrucibleOreZinc) );
	}

	ND_CrucibleOreIron GetIron()
	{
		return ND_CrucibleOreIron.Cast( GetAttachmentByType(ND_CrucibleOreIron) );
	}

	ND_CrucibleOreLead GetLead()
	{
		return ND_CrucibleOreLead.Cast( GetAttachmentByType(ND_CrucibleOreLead) );
	}
	ND_ClayCrucibleMoltenCopper GetClayMoltenCopper()
	{
		return ND_ClayCrucibleMoltenCopper.Cast( GetAttachmentByType( ND_ClayCrucibleMoltenCopper ) );
	}
#ifdef AM_MOD_221
	CrucibleFilledTips GetTheTip()
	{
		return CrucibleFilledTips.Cast( GetAttachmentByType(CrucibleFilledTips) );
	}

	CrucibleFilledCasing GetCasing()
	{
		return CrucibleFilledCasing.Cast( GetAttachmentByType(CrucibleFilledCasing) );
	}

	CrucibleMoltenBrass GetMoltenBrass()
	{	
		return CrucibleMoltenBrass.Cast( GetAttachmentByType( CrucibleMoltenBrass ));
	}
	CrucibleMoltenLead GetMoltenLead()
	{
		return CrucibleMoltenLead.Cast( GetAttachmentByType( CrucibleMoltenLead ) );
	}
	ND_ClayCrucibleMoltenBrass GetClayMoltenBrass()
	{
		return ND_ClayCrucibleMoltenBrass.Cast( GetAttachmentByType( ND_ClayCrucibleMoltenBrass ));
	}

	ND_ClayCrucibleMoltenLead GetClayMoltenLead()
	{
		return ND_ClayCrucibleMoltenLead.Cast( GetAttachmentByType( ND_ClayCrucibleMoltenLead ) );
	}
#endif
	ND_CrucibleMoltenCopper GetMoltenCopper()
	{
		return ND_CrucibleMoltenCopper.Cast( GetAttachmentByType( ND_CrucibleMoltenCopper ) );
	}

	ND_CrucibleMoltenZinc GetMoltenZinc()
	{
		return ND_CrucibleMoltenZinc.Cast( GetAttachmentByType( ND_CrucibleMoltenZinc ) );
	}
	ND_CrucibleMoltenIron GetMoltenPureIron()
	{
		return ND_CrucibleMoltenIron.Cast ( GetAttachmentByType (ND_CrucibleMoltenIron) );
	}

	ND_CrucibleMoltenImpureIron GetMoltenIron()
	{
		return ND_CrucibleMoltenImpureIron.Cast( GetAttachmentByType( ND_CrucibleMoltenImpureIron ) );
	}
	ND_CrucibleMoltenPigIron GetMoltenPigIron()
	{
		return ND_CrucibleMoltenPigIron.Cast ( GetAttachmentByType (ND_CrucibleMoltenPigIron) );
	}
	ND_ClayCrucibleOreCopper GetClayCopper()
	{
		return ND_ClayCrucibleOreCopper.Cast( GetAttachmentByType(ND_ClayCrucibleOreCopper) );
	}

	ND_ClayCrucibleOreZinc GetClayZinc()
	{
		return ND_ClayCrucibleOreZinc.Cast( GetAttachmentByType(ND_ClayCrucibleOreZinc) );
	}

	ND_ClayCrucibleOreIron GetClayIron()
	{
		return ND_ClayCrucibleOreIron.Cast( GetAttachmentByType(ND_ClayCrucibleOreIron) );
	}

	ND_ClayCrucibleOreLead GetClayLead()
	{
		return ND_ClayCrucibleOreLead.Cast( GetAttachmentByType(ND_ClayCrucibleOreLead) );
	}

	ND_ClayCrucibleFilledTips GetClayTheTip()
	{
		return ND_ClayCrucibleFilledTips.Cast( GetAttachmentByType(ND_ClayCrucibleFilledTips) );
	}

	ND_ClayCrucibleFilledCasing GetClayCasing()
	{
		return ND_ClayCrucibleFilledCasing.Cast( GetAttachmentByType(ND_ClayCrucibleFilledCasing) );
	}
	ND_ClayCrucibleMoltenZinc GetClayMoltenZinc()
	{
		return ND_ClayCrucibleMoltenZinc.Cast( GetAttachmentByType( ND_ClayCrucibleMoltenZinc ) );
	}
	ND_ClayCrucibleMoltenIron GetClayMoltenPureIron()
	{
		return ND_ClayCrucibleMoltenIron.Cast( GetAttachmentByType( ND_ClayCrucibleMoltenIron ) );
	}
	ND_ClayCrucibleMoltenImpureIron GetClayMoltenIron()
	{
		return ND_ClayCrucibleMoltenImpureIron.Cast( GetAttachmentByType( ND_ClayCrucibleMoltenImpureIron ) );
	}
	ND_ClayCrucibleMoltenPigIron GetClayMoltenPigIron()
	{
		return ND_ClayCrucibleMoltenPigIron.Cast ( GetAttachmentByType (ND_ClayCrucibleMoltenPigIron) );
	}

	ND_IncasedIngot GetClayIncasedIngot()
	{
		return ND_IncasedIngot.Cast( GetAttachmentByType( ND_IncasedIngot ) );
	}
	
	typename ATTACHMENT_METALCRUCIBLEPUREIRON = ND_CruciblePureIron;
	
	ND_CruciblePureIron GetCruciblePureIron()
	{
		return ND_CruciblePureIron.Cast( GetAttachmentByType( ATTACHMENT_METALCRUCIBLEPUREIRON ) );
	}
	ND_ClayCruciblePureIron GetClayCruciblePureIron()
	{
		return ND_ClayCruciblePureIron.Cast( GetAttachmentByType( ND_ClayCruciblePureIron ) );
	}
	void Smelt()
	{
		float percentage 10;
		
		ItemBase thing = ItemBase.Cast(FindAttachmentBySlotName("CrucibleOutput"));
	  
	    if (GetClayIron() || GetIron() || GetCruciblePureIron() || GetClayCruciblePureIron() || GetFirewood() || GetUnFiredBricks() || GetClayIncasedIngot() || GetUnfiredCrucible() ) //Has no outputs, disabled other smelting operations if Molten metal above is present.
	    {
			if ( GetClayIncasedIngot() && GetStackCoal().GetQuantity() >=Time_To_Smelt_PureIron && GetTemperature() >= Smelt_Temp_Iron && !thing  ) // after the timer for attaching items is over and the requisite item is attached
			{
				GetInventory().CreateAttachment("ND_IronIngot"); // attachment must be created before inventory is locked
				Lock(Time_To_Smelt_PureIron);
				GetGame().ObjectDelete(GetClayIncasedIngot() );
			}
			#ifdef AM_MOD_221
			else if ( GetCopper() && GetStackCoal().GetQuantity() >=TimeToSmeltCasing && GetTemperature() >= 1100 && !thing   ) // after the timer for attaching items is over and the requisite item is attached
			{	
				
				float copperQuantity = GetCopper().GetQuantity(); //Finds Copper, then the Quantity.
				if ( GetZinc() && IsItemTypeAttached ( ND_StackedCoal ) ) // checks if Zinc is attached
				{
					GetInventory().CreateAttachment("CrucibleMoltenBrass"); //Produces Brass in the output slot
					GetInventory().CreateAttachment("ND_EmptyCrucible");
					float moltenZincQuantity = (percentage + Math.RandomInt(EfficiencyMin,EfficiencyMax) ) / 100 * copperQuantity;
					GetMoltenBrass().SetQuantity(moltenZincQuantity)
					GetGame().ObjectDelete( GetZinc() ); //Deletes the zinc ore if it goes tho this IF statement GetMoltenBrass().SetQuantity( copperQuantity ) //sets the Brass Quantity to that or equal t the coppers init 
				}
				else //secondary if check, just not called IF
				{
					GetInventory().CreateAttachment("ND_CrucibleMoltenCopper"); // Produces melted Copper if zinc isnt attached
					float moltenCopperQuantity = (percentage + Math.RandomInt(EfficiencyMin,EfficiencyMax) ) / 100 * copperQuantity;
					GetMoltenCopper().SetQuantity( moltenCopperQuantity ) // makes copper ore quantity transfer to molten copper quantity
				}
			  	GetGame().ObjectDelete( GetCopper() ); //deletes copper ore after function is started
				Lock(TimeToSmeltCasing); //700
				
			}
			#endif
			else if ( GetCruciblePureIron() && GetStackCoal().GetQuantity() >=Time_To_Smelt_PureIron && GetTemperature() >= Smelt_Temp_Iron && !thing ) // after the timer for attaching items is over and the requisite item is attached
			{
				
				float PureIronQuantity = GetCruciblePureIron().GetQuantity();
				GetInventory().CreateAttachment("ND_CrucibleMoltenIron"); // attachment must be created before inventory is locked
				float moltenPureIronQuantity = (percentage + Math.RandomInt(Smelt_PureIron_EfficiencyMin,Smelt_PureIron_EfficiencyMax) ) / 100 * PureIronQuantity;
				GetMoltenPureIron().SetQuantity(moltenPureIronQuantity);
				Lock(Time_To_Smelt_PureIron); //1800
				GetGame().ObjectDelete(GetCruciblePureIron() );
			}
			else if ( GetIron() && GetStackCoal().GetQuantity() >=Time_To_Smelt_Iron && GetTemperature() >= Smelt_Temp_Iron && !thing ) // after the timer for attaching items is over and the requisite item is attached
			{
				float IronQuantity = GetIron().GetQuantity();
				GetInventory().CreateAttachment("ND_CrucibleMoltenPigIron"); // attachment must be created before inventory is locked
				float moltenIronQuantity = (percentage + Math.RandomInt(Smelt_Iron_EfficiencyMin,Smelt_Iron_EfficiencyMax) ) / 100 * IronQuantity;
				GetMoltenPigIron().SetQuantity(moltenIronQuantity);
				Lock(Time_To_Smelt_Iron);
				GetGame().ObjectDelete(GetIron() );
			}
			else if ( GetFirewood() && GetStackCoal().GetQuantity() >=Time_To_Smelt_Charcoal && GetTemperature() >= 100 && !thing ) // after the timer for attaching items is over and the requisite item is attached
			{
				float FireWoodQuantity = GetFirewood().GetQuantity();
				GetInventory().CreateAttachment("ND_Charcoal"); // attachment must be created before inventory is locked
				float CharcoalQuantity = (percentage + Math.RandomInt(50,100) ) / 100 * FireWoodQuantity;
				GetCharcoal().SetQuantity( CharcoalQuantity);
				Lock(Time_To_Smelt_Charcoal);
				GetGame().ObjectDelete(GetFirewood() );
			}
			else if ( GetUnFiredBricks().GetQuantity() == 10 && GetStackCoal().GetQuantity() >=Time_To_Fire_Clay && GetTemperature() >= 95)// after the timer for attaching items is over and the requisite item is attached
			{
				
				if(thing.GetQuantity() <= 90);
				{
					float UnFiredBricksQuantity = GetUnFiredBricks().GetQuantity();
					GetInventory().CreateAttachment("ND_FiredBricks"); // attachment must be created before inventory is locked
					GetFiredBricks().AddQuantity( UnFiredBricksQuantity);
					Lock(Time_To_Fire_Clay);
					GetGame().ObjectDelete(GetUnFiredBricks() );
				}
			}
			//////////////////////////////////// Clay Crucibles
			#ifdef AM_MOD_221
			else if ( GetClayCopper() && GetStackCoal().GetQuantity() >=TimeToSmeltCasing && GetTemperature() >= 1100 && !thing   ) // after the timer for attaching items is over and the requisite item is attached
			{	
				
				float copperClayQuantity = GetClayCopper().GetQuantity(); //Finds Copper, then the Quantity.
				if ( GetClayZinc() && IsItemTypeAttached ( ND_StackedCoal ) ) // checks if Zinc is attached
				{
					GetInventory().CreateAttachment("ND_ClayCrucibleMoltenBrass"); //Produces Brass in the output slot
					float moltenClayZincQuantity = (percentage + Math.RandomInt(EfficiencyMin,EfficiencyMax) ) / 100 * copperClayQuantity;
					GetClayMoltenBrass().SetQuantity(moltenClayZincQuantity)
					GetGame().ObjectDelete( GetClayZinc() ); //Deletes the zinc ore if it goes tho this IF statement GetClayMoltenBrass().SetQuantity( copperQuantity ) //sets the Brass Quantity to that or equal t the coppers init 
				}
				else //secondary if check, just not called IF
				{
					GetInventory().CreateAttachment("ND_ClayCrucibleMoltenCopper"); // Produces melted Copper if zinc isnt attached
					float moltenClayCopperQuantity = (percentage + Math.RandomInt(EfficiencyMin,EfficiencyMax) ) / 100 * copperClayQuantity;
					GetClayMoltenCopper().SetQuantity( moltenClayCopperQuantity ) // makes copper ore quantity transfer to molten copper quantity
				}
			  	GetGame().ObjectDelete( GetClayCopper() ); //deletes copper ore after function is started
				Lock(TimeToSmeltCasing); //Locks until procces is done # is the how it takes before unlocking.
				
			}
			#endif
			else if ( GetClayCruciblePureIron() && GetStackCoal().GetQuantity() >=Time_To_Smelt_Iron && GetTemperature() >= Smelt_Temp_Iron && !thing ) // after the timer for attaching items is over and the requisite item is attached
			{
				float PureClayIronQuantity = GetClayCruciblePureIron().GetQuantity();
				GetInventory().CreateAttachment("ND_ClayCrucibleMoltenIron"); // attachment must be created before inventory is locked
				float moltenClayPureIronQuantity = (percentage + Math.RandomInt(Smelt_PureIron_EfficiencyMin,Smelt_PureIron_EfficiencyMax) ) / 100 * PureClayIronQuantity;
				GetClayMoltenPureIron().SetQuantity(moltenClayPureIronQuantity);
				Lock(Time_To_Smelt_Iron); //1800
				GetGame().ObjectDelete(GetClayCruciblePureIron() );
			}
			else if ( GetClayIron() && GetStackCoal().GetQuantity() >=Time_To_Smelt_Iron && GetTemperature() >= Smelt_Temp_Iron && !thing ) // after the timer for attaching items is over and the requisite item is attached
			{
				float IronClayQuantity = GetClayIron().GetQuantity();
				GetInventory().CreateAttachment("ND_ClayCrucibleMoltenPigIron"); // attachment must be created before inventory is locked
				float moltenClayIronQuantity = (percentage + Math.RandomInt(Smelt_Iron_EfficiencyMin,Smelt_Iron_EfficiencyMax) ) / 100 * IronClayQuantity;
				GetMoltenPigIron().SetQuantity(moltenClayIronQuantity);
				Lock(Time_To_Smelt_Iron);
				GetGame().ObjectDelete(GetClayIron() );
			}
			else if ( GetUnfiredCrucible() && GetStackCoal().GetQuantity() >= Time_To_Fire_Clay && GetTemperature() >= 350 && !thing ) // after the timer for attaching items is over and the requisite item is attached
			{
				
				GetInventory().CreateAttachment("ND_ClayEmptyCrucible"); // attachment must be created before inventory is locked
				Lock(Time_To_Fire_Clay);
				GetGame().ObjectDelete(GetUnfiredCrucible() );
			};
	    }
		#ifdef AM_MOD_221
		else if(GetTheTip() || GetCasing() || GetLead() || GetClayCasing() || GetClayTheTip() || GetClayLead() )
		{
			if ( GetCasing()  && GetStackCoal().GetQuantity() >=650 && GetTemperature() >= 1100 && !thing ) // after the timer for attaching items is over and the requisite item is attached
			{
				float CasingQuantity = GetCasing().GetQuantity();
				GetInventory().CreateAttachment ("CrucibleMoltenBrass"); // attachment must be created before inventory is locked
				float moltenBrassQuantity = (percentage + Math.RandomInt(100,100) ) / 100 * CasingQuantity;
				GetMoltenBrass().SetQuantity (moltenBrassQuantity);
				//GetCasing().SetQuantity( CasingQuantity )
				Lock(TimeToSmeltCasing);
				GetGame().ObjectDelete(GetCasing() );
			};
		
			if ( GetTheTip() && GetStackCoal().GetQuantity() >=450 && GetTemperature() >= 350 && !thing ) // after the timer for attaching items is over and the requisite item is attached
			{
				float TipQuantity = GetTheTip().GetQuantity();
				GetInventory().CreateAttachment("CrucibleMoltenLead"); // attachment must be created before inventory is locked
				float moltenLeadQuantity2 = (percentage + Math.RandomInt(100,100) ) / 100 * TipQuantity;
				GetMoltenLead().SetQuantity (moltenLeadQuantity2);
				Lock(TimeToSmeltTips);
				GetGame().ObjectDelete(GetTheTip() );
			};
			if ( GetLead() && GetStackCoal().GetQuantity() >=500 && GetTemperature() >= 350  && !thing  ) // after the timer for attaching items is over and the requisite item is attached
			{
				float LeadQuantity = GetLead().GetQuantity();
				GetInventory().CreateAttachment("CrucibleMoltenLead"); // attachment must be created before inventory is locked
				float moltenLeadQuantity1 = (percentage + Math.RandomInt(45,60) ) / 100 * LeadQuantity;
				GetMoltenLead().SetQuantity( moltenLeadQuantity1 )
				Lock(TimeToSmeltTips);//500
				GetGame().ObjectDelete(GetLead());
			};
			// Clay Ammo Smelting
			if ( GetClayCasing()  && GetStackCoal().GetQuantity() >=650 && GetTemperature() >= 1100 && !thing  ) // after the timer for attaching items is over and the requisite item is attached
			{
				float CasingClayQuantity = GetClayCasing().GetQuantity();
				GetInventory().CreateAttachment ("ND_ClayCrucibleMoltenBrass"); // attachment must be created before inventory is locked
				float moltenClayBrassQuantity = (percentage + Math.RandomInt(30,50) ) / 100 * CasingClayQuantity;
				GetClayMoltenBrass().SetQuantity (moltenClayBrassQuantity);
				GetClayCasing().SetQuantity( CasingQuantity )
				Lock(TimeToSmeltCasing);
				GetGame().ObjectDelete(GetClayCasing() );
			};
		
			if ( GetClayTheTip() && GetStackCoal().GetQuantity() >=450 && GetTemperature() >= 350 && !thing  ) // after the timer for attaching items is over and the requisite item is attached
			{
				float TipClayQuantity = GetClayTheTip().GetQuantity();
				GetInventory().CreateAttachment("ND_ClayCrucibleMoltenLead"); // attachment must be created before inventory is locked
				float moltenClayLeadQuantity2 = (percentage + Math.RandomInt(30,50) ) / 100 * TipClayQuantity;
				GetClayMoltenLead().SetQuantity (moltenClayLeadQuantity2);
				Lock(TimeToSmeltTips);
				GetGame().ObjectDelete(GetClayTheTip() );
			};
			
			if ( GetClayLead() && GetStackCoal().GetQuantity() >=500 && GetTemperature() >= 350 && !thing  ) // after the timer for attaching items is over and the requisite item is attached
			{
				float LeadClayQuantity = GetClayLead().GetQuantity();
				GetInventory().CreateAttachment("ND_ClayCrucibleMoltenLead"); // attachment must be created before inventory is locked
				float moltenClayLeadQuantity1 = (percentage + Math.RandomInt(45,60) ) / 100 * LeadClayQuantity;
				GetClayMoltenLead().SetQuantity( moltenClayLeadQuantity1 )
				Lock(TimeToSmeltTips);//500
				GetGame().ObjectDelete(GetClayLead());
			};
		};
		#endif		
	};

};