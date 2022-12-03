/*
m_FireplaceRadius = is how far the fireplace light shines

m_FireplaceBrightness = is how bright it is

TimeBeforeSmelting = how many seconds before the smelter locks when said variables are met

SetTemperature = how Hot the Furnace will show in Celsius, in the futrue will affect how much heat it provides to said area and also dmg to player if player is too close

ItemGoesHere().GetQuantity() >=  // this is a call to check how much of an item thats just before this to have before starting the smelting operation, if the number is below the number you put just after the >= sign it will not trigger the function(ItemGoesHere = the name of the item you wish to check for quantity off). 

Lock(#) = how long the smelters function will lock the attachments and inventory (if present) of said smelter. when its done in its timer it will unlock and show the contents.

Note 
*/
class ND_ImprovedSmelter extends ND_Smelter
{		
	void ND_ImprovedSmelter()
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
		
		
		
		Smelt_Temp_Iron = GetSmelterSettings().ImprovedSmeltIronSmeltTemperature;
		Time_To_Smelt_Iron = GetSmelterSettings().ImprovedTimeToSmeltIron;
		Smelt_Iron_EfficiencyMin = GetSmelterSettings().ImprovedSmeltIronEfficiencyMin;
		Smelt_Iron_EfficiencyMax = GetSmelterSettings().ImprovedSmeltIronEfficiencyMax;
		Time_To_Smelt_PureIron = GetSmelterSettings().ImprovedTimeToSmeltPureIron;
		Smelt_PureIron_EfficiencyMin = GetSmelterSettings().ImprovedSmeltPureIronEfficiencyMin;
		Smelt_PureIron_EfficiencyMax = GetSmelterSettings().ImprovedSmeltPureIronEfficiencyMax;
		Time_To_Smelt_Charcoal = GetSmelterSettings().ImprovedSmelterTimeToSmeltCharcoal;
		HeatingRate = GetSmelterSettings().ImprovedSmelterHeatingRate;
		CoolingRate = GetSmelterSettings().ImprovedSmelterCoolingRate;
		Time_To_Fire_Clay = GetSmelterSettings().ImprovedCureClayItems;
		
		
		#ifdef AM_MOD_221
		TimeToSmeltTips = GetAmmoSmelting().Time_To_Smelt_Tips;
		TimeToSmeltCasing = GetAmmoSmelting().Time_To_Smelt_Casing;
		EfficiencyMin = GetAmmoSmelting().Smelter_Efficiency_Min;  
		EfficiencyMax = GetAmmoSmelting().Smelter_Efficiency_Max;
		#endif
		
		
		
	};
	
	FireplaceLight GetLightEntity()
	{
		return m_Light;
	}
	
	void SetLightEntity( FireplaceLight light )
	{
		m_Light = light;
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
	
	override void AddTemperatureToCrucibleByFire()
	{
		super.AddTemperatureToCrucibleByFire();
		int DividingTemp = 10;
	};
	override void Smelt()
	{
		float percentage 10;
		
		ItemBase thing = ItemBase.Cast(FindAttachmentBySlotName("CrucibleOutput"));
	  
	    if (GetClayIron() || GetIron() || GetCruciblePureIron() || GetClayCruciblePureIron() || GetFirewood() || GetUnFiredBricks() || GetClayIncasedIngot() || GetUnfiredCrucible()  ) //Has no outputs, disabled other smelting operations if Molten metal above is present.
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
				GetInventory().CreateAttachment("ND_CrucibleMoltenImpureIron"); // attachment must be created before inventory is locked
				float moltenIronQuantity = (percentage + Math.RandomInt(Smelt_Iron_EfficiencyMin,Smelt_Iron_EfficiencyMax) ) / 100 * IronQuantity;
				GetMoltenIron().SetQuantity(moltenIronQuantity);
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
				GetClayMoltenIron().SetQuantity(moltenClayPureIronQuantity);
				Lock(Time_To_Smelt_Iron); //1800
				GetGame().ObjectDelete(GetClayCruciblePureIron() );
			}
			else if ( GetClayIron() && GetStackCoal().GetQuantity() >=Time_To_Smelt_Iron && GetTemperature() >= Smelt_Temp_Iron && !thing ) // after the timer for attaching items is over and the requisite item is attached
			{
				float IronClayQuantity = GetClayIron().GetQuantity();
				GetInventory().CreateAttachment("ND_ClayCrucibleMoltenImpureIron"); // attachment must be created before inventory is locked
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