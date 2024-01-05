class ND_ClayCrucibleBase extends ItemBase
{
	void ND_ClayCrucibleBase()
	{
		SetTemperature(0);
	}
	
};
class ND_UnfiredClayEmptyCrucible extends ND_ClayCrucibleBase{}
class ND_ClayMoltenCrucible extends ND_MoltenCrucible
{
	#ifdef AM_MOD_221
	string GetTendancyText(){};
	string GetRifleTendancyText(){};
	string GetPistolTendancyText(){}
	void StepTendancy(){};
	void StepCasingRifleTendancy(){};
	void StepCasingPistolTendancy(){};
	void StepTipsRifleTendancy(){};
	void StepTipsPistolTendancy(){};
	#endif
	void ND_ClayMoltenCrucible()
	{
		SetTemperature(1650);
	};

	override bool CanPutIntoHands(EntityAI parent)
    {
        if ( parent.FindAttachmentBySlotName( "Gloves" ))
        {
            return true;
        }
		if ( GetTemperature() <= 80)
		{
			return true;
		}
		return false;
    }
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionEmptyCrucible);
		AddAction(ActionEmptyCrucibleinhands);
	};
};
class ND_EmptyCrucible extends ND_ClayCrucibleBase{};
class ND_CrucibleBase extends ItemBase
{
	void ND_CrucibleBase()
	{
		SetTemperature(0);
	};
	
	void Empty() {}
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionEmptyCrucible);
	};
	override bool CanPutIntoHands(EntityAI parent)
    {
        if ( parent.FindAttachmentBySlotName( "Gloves" ))
        {
            return true;
        }
		if ( GetTemperature() <= 80)
		{
			return true;
		}
		return false;
    };
	
};
class ND_MoltenCrucible extends ND_CrucibleBase
{
	protected ref UniversalTemperatureSource m_UTSource;
	protected ref UniversalTemperatureSourceSettings m_UTSSettings;
	protected ref UniversalTemperatureSourceLambdaConstant m_UTSLConst;
	
	
	void ND_MoltenCrucible()
	{
		SetTemperature(1650);
	};
	
	override void EEInit()
	{		
		super.EEInit();
		
		if (GetGame().IsServer() || !GetGame().IsMultiplayer())
		{
 			m_UTSSettings 					= new UniversalTemperatureSourceSettings();
			m_UTSSettings.m_ManualUpdate	= true;
			m_UTSSettings.m_TemperatureMin	= 0;
			m_UTSSettings.m_TemperatureMax	= 1000;
			m_UTSSettings.m_RangeFull		= 1;
			m_UTSSettings.m_RangeMax		= 2;
			m_UTSSettings.m_TemperatureCap	= 10;
			
			m_UTSLConst						= new UniversalTemperatureSourceLambdaConstant();
			m_UTSource						= new UniversalTemperatureSource(this, m_UTSSettings, m_UTSLConst);
		}		
	}
	//override void Empty()
	//{
	//	Object targetObject;
	//	PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
	//	ReplaceEdibleWithNew("ND_EmptyCrucible");
	//};
	
	override bool CanHaveTemperature()
	{
		return true;
	}
	
	override void Open()
	{
		Object targetObject;
		PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
		ND_MoltenCrucible Crucible = ND_MoltenCrucible.Cast( targetObject );

		ReplaceEdibleWithNew("ND_EmptyCrucible");
	
	};
	protected ref Timer m_CoolingTimer;
	
	protected void StartCooling()
	{		
		m_CoolingTimer = new Timer( CALL_CATEGORY_GAMEPLAY );
		m_CoolingTimer.Run( 3, this, "Cooling", NULL, true );		// true param loops
	};
	
	void Cooling()
	{
		float temperature = GetTemperature();
		temperature = temperature - 4;

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

	override void OnWasAttached(EntityAI parent, int slot_id)
	{
		super.OnWasAttached(parent, slot_id);
		StopCooling();
	};
	
	override void OnWasDetached(EntityAI parent, int slot_id)
	{
		super.OnWasDetached(parent,slot_id);
	
		StartCooling();
	};
	
	void ReplaceEdibleWithNew (string typeName)
	{
		PlayerBase player = PlayerBase.Cast(GetHierarchyRootPlayer());
		if (player)
		{
			ReplaceEdibleWithNewLambda lambda = new ReplaceEdibleWithNewLambda(this, typeName, player);
			player.ServerReplaceItemInHandsWithNew(lambda);
		}
		else
			Error("ReplaceEdibleWithNew - cannot use edible without player");
	};
	override bool CanPutIntoHands(EntityAI parent)
    {
        if ( parent.FindAttachmentBySlotName( "Gloves" ))
        {
            return true;
        }
		if ( GetTemperature() <= 80)
		{
			return true;
		}
		return false;
    };
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionEmptyCrucible101);
	};
}
class ND_ClayEmptyCrucible extends ND_CrucibleBase{};
class ND_CruciblePureIron extends ND_CrucibleBase{};
class ND_StackedCoal extends ItemBase{};
class ND_CrucibleOreCopper extends ND_CrucibleBase{};
class ND_CrucibleOreZinc extends ND_CrucibleBase{};
class ND_CrucibleOreIron extends ND_CrucibleBase{};
class ND_CrucibleOreLead extends ND_CrucibleBase{};

class ND_CrucibleMoltenCopper extends ND_MoltenCrucible
{
	void ND_CrucibleMoltenCopper()
	{
		if(GetTemperature() >=80)
		{
			StartCooling();
		}
		if(GetTemperature() >=0)
		{
			StopCooling();
		}
		StartCooling();
		
	};
	override void OnWasAttached(EntityAI parent, int slot_id)
	{
		super.OnWasAttached(parent,slot_id);
		StopCooling();
	};
	override void OnWasDetached(EntityAI parent, int slot_id)
	{
		super.OnWasDetached(parent,slot_id);
		StartCooling();
	};
	
	protected override void StartCooling()
	{
		m_CoolingTimer = new Timer( CALL_CATEGORY_GAMEPLAY );
		m_CoolingTimer.Run( 1, this, "Cooling", NULL, true );		// true param loops
	};


	void Cooling()
	{
		if (GetTemperature() >= 1)
		{
			float temperature = GetTemperature();
			temperature = temperature - 3;
		}

		SetTemperature(temperature);

		if ( GetTemperature() <= 1)
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
    override bool CanPutIntoHands(EntityAI parent)
    {
		if(GetTemperature() <=80)
		{
			return true;
		}
        if ( parent.FindAttachmentBySlotName( "Gloves" ) && GetTemperature() >= 80)
        {
            return true;
        }
		return false;
    };
};
class ND_CrucibleMoltenZinc extends ND_MoltenCrucible
{
	void ND_CrucibleMoltenZinc()
	{
		if(GetTemperature() >=80)
		{
			StartCooling();
		}
		if(GetTemperature() >=0)
		{
			StopCooling();
		}
		StartCooling();
		
	};
	override void OnWasAttached(EntityAI parent, int slot_id)
	{
		super.OnWasAttached(parent,slot_id);
		StopCooling();
	};
	override void OnWasDetached(EntityAI parent, int slot_id)
	{
		super.OnWasDetached(parent,slot_id);
		StartCooling();
	};
	
	protected override void StartCooling()
	{

		
		m_CoolingTimer = new Timer( CALL_CATEGORY_GAMEPLAY );
		m_CoolingTimer.Run( 1, this, "Cooling", NULL, true );		// true param loops
	};

	void Cooling()
	{
		if (GetTemperature() >= 1)
		{
			float temperature = GetTemperature();
			temperature = temperature - 3;
		}

		SetTemperature(temperature);

		if ( GetTemperature() <= 1)
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
    override bool CanPutIntoHands(EntityAI parent)
    {
		if(GetTemperature() <=80)
		{
			return true;
		}
        if ( parent.FindAttachmentBySlotName( "Gloves" ) && GetTemperature() >= 80)
        {
            return true;
        }
		return false;
    };
};
class ND_CrucibleMoltenIron extends ND_MoltenCrucible
{
	void ND_CrucibleMoltenIron()
	{
		if(GetTemperature() >=80)
		{
			StartCooling();
		}
		if(GetTemperature() >=0)
		{
			StopCooling();
		}
		StartCooling();
		
	};
    override bool CanPutIntoHands(EntityAI parent)
    {
		if(GetTemperature() <=80)
		{
			return true;
		}
        if ( parent.FindAttachmentBySlotName( "Gloves" ) && GetTemperature() >= 80)
        {
            return true;
        }
		return false;
    };
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionFillAnvilMold);
		AddAction(ActionFillIngotMold);
		AddAction(ActionFillBarMold);
		AddAction(ActionFillNuggetMold);
		AddAction(ActionEmptyCrucible);
	};
};
class ND_CrucibleMoltenImpureIron extends ND_MoltenCrucible
{
	void ND_CrucibleMoltenIron()
	{
		if(GetTemperature() >=80)
		{
			StartCooling();
		}
		if(GetTemperature() >=0)
		{
			StopCooling();
		}
		StartCooling();
		
	};
		override void OnWasAttached(EntityAI parent, int slot_id)
	{
		super.OnWasAttached(parent,slot_id);
		StopCooling();
	};
	override void OnWasDetached(EntityAI parent, int slot_id)
	{
		super.OnWasDetached(parent,slot_id);
		StartCooling();
	};
	
	protected override void StartCooling()
	{

		
		m_CoolingTimer = new Timer( CALL_CATEGORY_GAMEPLAY );
		m_CoolingTimer.Run( 1, this, "Cooling", NULL, true );		// true param loops
	};


	void Cooling()
	{
		if (GetTemperature() >= 1)
		{
			float temperature = GetTemperature();
			temperature = temperature - 3;
		}

		SetTemperature(temperature);

		if ( GetTemperature() <= 1)
		{
			m_CoolingTimer.Stop();
			m_CoolingTimer = NULL;
			//Print("zxd");
		}
	};


	
	void ReplaceEdibleWithNew (string typeName)
	{
		PlayerBase player = PlayerBase.Cast(GetHierarchyRootPlayer());
		if (player)
		{
			ReplaceEdibleWithNewLambda lambda = new ReplaceEdibleWithNewLambda(this, typeName, player);
			player.ServerReplaceItemInHandsWithNew(lambda);
		}
		else
			Error("ReplaceEdibleWithNew - cannot use edible without player");
	};
	protected void StopCooling()
	{
		//Stop cooling
		m_CoolingTimer.Stop();
		m_CoolingTimer = NULL;

	
	};
    override bool CanPutIntoHands(EntityAI parent)
    {
		if(GetTemperature() <=80)
		{
			return true;
		}
        if ( parent.FindAttachmentBySlotName( "Gloves" ) && GetTemperature() >= 80)
        {
            return true;
        }
		return false;
    };
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionFillAnvilMold);
		AddAction(ActionFillIngotMold);
		AddAction(ActionFillBarMold);
		AddAction(ActionFillNuggetMold);
		AddAction(ActionEmptyCrucible);
	};
};
class ND_CrucibleMoltenPigIron extends ND_MoltenCrucible
{
	void ND_CrucibleMoltenPigIron()
	{
		if(GetTemperature() >=80)
		{
			StartCooling();
		}
		if(GetTemperature() >=0)
		{
			StopCooling();
		}
		StartCooling();
		
	};
		override void OnWasAttached(EntityAI parent, int slot_id)
	{
		super.OnWasAttached(parent,slot_id);
		StopCooling();
	};
	override void OnWasDetached(EntityAI parent, int slot_id)
	{
		super.OnWasDetached(parent,slot_id);
		StartCooling();
	};
	
	protected override void StartCooling()
	{

		
		m_CoolingTimer = new Timer( CALL_CATEGORY_GAMEPLAY );
		m_CoolingTimer.Run( 1, this, "Cooling", NULL, true );		// true param loops
	};


	void Cooling()
	{
		if (GetTemperature() >= 1)
		{
			float temperature = GetTemperature();
			temperature = temperature - 3;
		}

		SetTemperature(temperature);

		if ( GetTemperature() <= 1)
		{
			m_CoolingTimer.Stop();
			m_CoolingTimer = NULL;
			//Print("zxd");
		}
	};


	
	void ReplaceEdibleWithNew (string typeName)
	{
		PlayerBase player = PlayerBase.Cast(GetHierarchyRootPlayer());
		if (player)
		{
			ReplaceEdibleWithNewLambda lambda = new ReplaceEdibleWithNewLambda(this, typeName, player);
			player.ServerReplaceItemInHandsWithNew(lambda);
		}
		else
			Error("ReplaceEdibleWithNew - cannot use edible without player");
	};
	protected void StopCooling()
	{
		//Stop cooling
		m_CoolingTimer.Stop();
		m_CoolingTimer = NULL;

	
	};
    override bool CanPutIntoHands(EntityAI parent)
    {
		if(GetTemperature() <=80)
		{
			return true;
		}
        if ( parent.FindAttachmentBySlotName( "Gloves" ) && GetTemperature() >= 80)
        {
            return true;
        }
		return false;
    };
	ND_CrucibleMoltenPigIron GetCrucibleMoltenPigIron()
	{
		return ND_CrucibleMoltenPigIron.Cast( GetAttachmentByType( ND_CrucibleMoltenPigIron ) );
	};

	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionFillAnvilMold);
		AddAction(ActionFillIngotMold);
		AddAction(ActionFillBarMold);
		AddAction(ActionFillNuggetMold);
		AddAction(ActionEmptyCrucible);
	};
};

class ND_ClayCrucibleOreCopper extends ND_ClayCrucibleBase{};
class ND_ClayCrucibleOreZinc extends ND_ClayCrucibleBase{};
class ND_ClayCruciblePureIron extends ND_ClayCrucibleBase{};
class ND_ClayCrucibleOreIron extends ND_ClayCrucibleBase{};
class ND_ClayCrucibleOreLead extends ND_ClayCrucibleBase{};
class ND_ClayCrucibleFilledCasing extends ND_ClayCrucibleBase{};
class ND_ClayCrucibleFilledTips extends ND_ClayCrucibleBase{};
#ifdef AM_MOD_221
class ND_ClayCrucibleMoltenLead extends CrucibleMoltenLead
{
	override void EEInit()
	{
      super.EEInit();
      RegisterNetSyncVariableInt("m_CastRifleTips");
	  RegisterNetSyncVariableInt("m_CastPistolTips");
    };


	void ND_ClayCrucibleMoltenLead()
	{
		if(GetTemperature() >=80)
		{
			StartCooling();
		}
		if(GetTemperature() >=0)
		{
			StopCooling();
		}
		StartCooling();
		
	};
    override bool CanPutIntoHands(EntityAI parent)
    {
		if(GetTemperature() <=80)
		{
			return true;
		}
        if ( parent.FindAttachmentBySlotName( "Gloves" ) && GetTemperature() >= 80)
        {
            return true;
        }
		return false;
    };
};
class ND_ClayCrucibleMoltenBrass extends CrucibleMoltenBrass
{
	override void EEInit()
	{
      super.EEInit();
      RegisterNetSyncVariableInt("m_CastRifleCasing");
	  RegisterNetSyncVariableInt("m_CastPistolCasing");
    };
	override string GetRifleTendancyText()
	{
		if (m_CastRifleCasing == 0)
		{
			if(GetQuantity() >= 28 && GetTemperature() > 300)
			{
				return "Cast 545x39 Casing";
			}
			else if(GetTemperature() < 300 )
			{
				return "Not Hot Enough";
			};
			return "Not Enough Brass";
        }
		if(m_CastRifleCasing == 1)
		{
			if(GetQuantity() >= 30 && GetTemperature() > 300)
			{
				return "Cast 556x45 Casing";
			}
			else if(GetTemperature() < 300 )
			{
				return "Not Hot Enough";
			};
			return "Not Enough Brass";
		}		
		if (m_CastRifleCasing == 2)
		{
			if(GetQuantity() >= 35 && GetTemperature() > 300)
			{
				return "Cast 762x39 Casing";
			}
			else if(GetTemperature() < 300 )
			{
				return "Not Hot Enough";
			};
			return "Not Enough Brass";	
        }
		if (m_CastRifleCasing == 3)
		{
			if(GetQuantity() >= 37 && GetTemperature() > 300)
			{
				return "Cast 308Win Casing";
			}
			else if(GetTemperature() < 300 )
			{
				return "Not Hot Enough";
			};
			return "Not Enough Brass";	
        }
		if (m_CastRifleCasing == 4)
		{
			if(GetQuantity() >= 40 && GetTemperature() > 300)
			{
				return "Cast 762x54 Casing";
			}
			else if(GetTemperature() < 300 )
			{
				return "Not Hot Enough";
			};
			return "Not Enough Brass";
        }
		if (m_CastRifleCasing == 5)
		{
			if(GetQuantity() >= 25 && GetTemperature() > 300 )
			{
				return "Cast 9x39 Casing";
			}
			else if(GetTemperature() < 300 )
			{
				return "Not Hot Enough";
			};
			return "Not Enough Brass";
        }
        return "";

    };
	override string GetPistolTendancyText()
	{
        if (m_CastPistolCasing == 0)
		{
			if(GetQuantity() >= 13 && GetTemperature() > 300)
			{
				return "Cast 22LR Casing";
			}
			else if(GetTemperature() < 300 )
			{
				return "Not Hot Enough";
			};
			return "Not Enough Brass";
        }
		if (m_CastPistolCasing == 1)
		{
			if(GetQuantity() >= 20 && GetTemperature() > 300)
			{
				return "Cast 9x19 Casing";
			}
			else if(GetTemperature() < 300 )
			{
				return "Not Hot Enough";
			};
			return "Not Enough Brass";
        }
        if (m_CastPistolCasing == 2)
		{
			if(GetQuantity() >= 23 && GetTemperature() > 300)
			{
				return "Cast 45ACP Casing";
			}
			else if(GetTemperature() < 300 )
			{
				return "Not Hot Enough";
			};
			return "Not Enough Brass";
        }
		if (m_CastPistolCasing == 3)
		{
			if(GetQuantity() >= 26 && GetTemperature() > 300)
			{
				return "Cast 357 Casing";
			}
			else if(GetTemperature() < 300 )
			{
				return "Not Hot Enough";
			};
			return "Not Enough Brass";
        }
		if (m_CastPistolCasing == 4)
		{
			if(GetQuantity() >= 15 && GetTemperature() > 300)
			{
				return "Cast 380ACP Casing";
			}
			else if(GetTemperature() < 300 )
			{
				return "Not Hot Enough";
			};
			return "Not Enough Brass";
        }
        return "";

    };
	
    override string GetRifleCasingTendancyCreationType()
	{
		if (m_CastRifleCasing == 0)
		{
           return "545x39";
        }
		if(m_CastRifleCasing == 1)
		{
			return "556x45";
		}		
		if (m_CastRifleCasing == 2)
		{
           return "762x39";
        }
		if (m_CastRifleCasing == 3)
		{
           return "308Win";
        }
		if (m_CastRifleCasing == 4)
		{
           return "762x54";
        }
		if (m_CastRifleCasing == 5)
		{
           return "9x39";
        }

        return "";
    };
	
	override int GetRifleCasingReqQuantity()
	{
		if (m_CastRifleCasing == 0)
		{
           return 28;
        }
		else if (m_CastRifleCasing == 1)
		{
           return 30;
        }
		else if (m_CastRifleCasing == 2)
		{
           return 35;
        }
		else if (m_CastRifleCasing == 3)
		{
			return 37;
        }
		else if (m_CastRifleCasing == 4)
		{
			return 40;
        }
		else if (m_CastRifleCasing == 5)
		{
           return 25;
        }
		return 0;
    };
	override int GetPistolCasingReqQuantity()
	{
		if (m_CastPistolCasing == 0)
		{
          return 13;
        }
		else if (m_CastPistolCasing == 1)
		{
          return 20;
        }
        else if (m_CastPistolCasing == 2)
		{
           return 23 ;
        }
		else if (m_CastPistolCasing == 3)
		{
           return 26;
        }
		else if (m_CastPistolCasing == 4)
		{
           return 15;
        }
		return 0;
		SetSynchDirty();
	};
	
	override void MinusQuantityRifle()
	{

		if (m_CastRifleCasing == 0)
		{
           AddQuantity(-28);
        }
		else if (m_CastRifleCasing == 1)
		{
           AddQuantity(-30);
        }
		else if (m_CastRifleCasing == 2)
		{
           AddQuantity(-35);
        }
		else if (m_CastRifleCasing == 3)
		{
			AddQuantity(-37);
        }
		else if (m_CastRifleCasing == 4)
		{
			AddQuantity(-40);
        }
		else if (m_CastRifleCasing == 5)
		{
           AddQuantity(-25);
        }
		Print("m_CastRifleCasing == " + m_CastRifleCasing);
		SetSynchDirty();
	};
	
	override string GetPistolCasingTendancyCreationType()
	{
        if (m_CastPistolCasing == 0)
		{
          return "22LR";
        }
		if (m_CastPistolCasing == 1)
		{
          return "9x19";
        }
        if (m_CastPistolCasing == 2)
		{
           return "45ACP";
        }
		if (m_CastPistolCasing == 3)
		{
           return "357";
        }
		if (m_CastPistolCasing == 4)
		{
           return "380ACP";
        }
        return "";
    };
	
	override void MinusQuantityPistol()
	{
		if (m_CastPistolCasing == 0)
		{
          AddQuantity(-13);
        }
		else if (m_CastPistolCasing == 1)
		{
          AddQuantity(-20);
        }
        else if (m_CastPistolCasing == 2)
		{
           AddQuantity(-23);
        }
		else if (m_CastPistolCasing == 3)
		{
           AddQuantity(-26);
        }
		else if (m_CastPistolCasing == 4)
		{
           AddQuantity(-15);
        }
		SetSynchDirty();
	};
	
	override void StepCasingRifleTendancy()
	{
      m_CastRifleCasing++;
      if (m_CastRifleCasing > 5)
	  {
         m_CastRifleCasing = 0;
      }
	  Print("m_CastRifleCasing" + m_CastRifleCasing)
      SetSynchDirty();
    };
	override void StepCasingPistolTendancy()
	{
      m_CastPistolCasing++;
      if (m_CastPistolCasing > 4)
	  {
         m_CastPistolCasing = 0;
      }
	  Print("m_CastPistolCasing" + m_CastPistolCasing)
      SetSynchDirty();
    };
	
	override int CasingRifleTendancy()
	{
        return m_CastRifleCasing;
    };
	
	override int CasingPistolTendancy()
	{
		return m_CastPistolCasing;
    };
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionAM_BrassChangeCastingAction);
		AddAction(AM_ActionCastingCasingAmmo);
	}

	
	
	void ND_ClayCrucibleMoltenBrass()
	{
		if(GetTemperature() >=80)
		{
			StartCooling();
		}
		if(GetTemperature() >=0)
		{
			StopCooling();
		}
		StartCooling();
		
	};
	override void OnWasDetached(EntityAI parent, int slot_id)
	{
		super.OnWasDetached(parent,slot_id);
		StartCooling();
	};
	
    override bool CanPutIntoHands(EntityAI parent)
    {
		if(GetTemperature() <=80)
		{
			return true;
		}
        if ( parent.FindAttachmentBySlotName( "Gloves" ) && GetTemperature() >= 80)
        {
            return true;
        }
		return false;
    };

};
#endif
class ND_ClayCrucibleMoltenCopper extends ND_ClayMoltenCrucible
{
	void ND_ClayCrucibleMoltenCopper()
	{
		if(GetTemperature() >=80)
		{
			StartCooling();
		}
		if(GetTemperature() >=0)
		{
			StopCooling();
		}
		StartCooling();
		
	};
		override void OnWasAttached(EntityAI parent, int slot_id)
	{
		super.OnWasAttached(parent,slot_id);
		StopCooling();
	};
	override void OnWasDetached(EntityAI parent, int slot_id)
	{
		super.OnWasDetached(parent,slot_id);
		StartCooling();
	};

    override bool CanPutIntoHands(EntityAI parent)
    {
		if(GetTemperature() <=80)
		{
			return true;
		}
        if ( parent.FindAttachmentBySlotName( "Gloves" ) && GetTemperature() >= 80)
        {
            return true;
        }
		return false;
    };
};
class ND_ClayCrucibleMoltenZinc extends ND_ClayMoltenCrucible
{
    void ND_ClayCrucibleMoltenZinc()
	{
		if(GetTemperature() >=80)
		{
			StartCooling();
		}
		if(GetTemperature() >=0)
		{
			StopCooling();
		}
		StartCooling();
		
	};
		override void OnWasAttached(EntityAI parent, int slot_id)
	{
		super.OnWasAttached(parent,slot_id);
		StopCooling();
	};
	override void OnWasDetached(EntityAI parent, int slot_id)
	{
		super.OnWasDetached(parent,slot_id);
		StartCooling();
	};
	

    override bool CanPutIntoHands(EntityAI parent)
    {
		if(GetTemperature() <=80)
		{
			return true;
		}
        if ( parent.FindAttachmentBySlotName( "Gloves" ) && GetTemperature() >= 80)
        {
            return true;
        }
		return false;
    };
};
class ND_ClayCrucibleMoltenIron extends ND_ClayMoltenCrucible
{
	void ND_ClayCrucibleMoltenIron()
	{
		if(GetTemperature() >=80)
		{
			StartCooling();
		}
		if(GetTemperature() >=0)
		{
			StopCooling();
		}
		StartCooling();
		
	};
		override void OnWasAttached(EntityAI parent, int slot_id)
	{
		super.OnWasAttached(parent,slot_id);
		StopCooling();
	};
	override void OnWasDetached(EntityAI parent, int slot_id)
	{
		super.OnWasDetached(parent,slot_id);
		StartCooling();
	};
	

    override bool CanPutIntoHands(EntityAI parent)
    {
		if(GetTemperature() <=80)
		{
			return true;
		}
        if ( parent.FindAttachmentBySlotName( "Gloves" ) && GetTemperature() >= 80)
        {
            return true;
        }
		return false;
    };
	override void SetActions()
	{
		super.SetActions();

		AddAction(ActionFillAnvilMold);
		AddAction(ActionFillIngotMold);
		AddAction(ActionFillBarMold);
		AddAction(ActionFillNuggetMold);
		AddAction(ActionEmptyCrucible);
	};
};
class ND_ClayCrucibleMoltenImpureIron extends ND_ClayMoltenCrucible
{
	void ND_ClayCrucibleMoltenImpureIron()
	{
		if(GetTemperature() >=80)
		{
			StartCooling();
		}
		if(GetTemperature() >=0)
		{
			StopCooling();
		}
		StartCooling();
		
	};
		override void OnWasAttached(EntityAI parent, int slot_id)
	{
		super.OnWasAttached(parent,slot_id);
		StopCooling();
	};
	override void OnWasDetached(EntityAI parent, int slot_id)
	{
		super.OnWasDetached(parent,slot_id);
		StartCooling();
	};
	
    override bool CanPutIntoHands(EntityAI parent)
    {
		if(GetTemperature() <=80)
		{
			return true;
		}
        if ( parent.FindAttachmentBySlotName( "Gloves" ) && GetTemperature() >= 80)
        {
            return true;
        }
		return false;
    };
	override void SetActions()
	{
		super.SetActions();

		AddAction(ActionFillAnvilMold);
		AddAction(ActionFillIngotMold);
		AddAction(ActionFillBarMold);
		AddAction(ActionFillNuggetMold);
		AddAction(ActionEmptyCrucible);
	};
};
class ND_ClayCrucibleMoltenPigIron extends ND_ClayMoltenCrucible
{
		void ND_ClayCrucibleMoltenPigIron()
	{
		if(GetTemperature() >=80)
		{
			StartCooling();
		}
		if(GetTemperature() >=0)
		{
			StopCooling();
		}
		StartCooling();
		
	};
		override void OnWasAttached(EntityAI parent, int slot_id)
	{
		super.OnWasAttached(parent,slot_id);
		StopCooling();
	};
	override void OnWasDetached(EntityAI parent, int slot_id)
	{
		super.OnWasDetached(parent,slot_id);
		StartCooling();
	};
	

    override bool CanPutIntoHands(EntityAI parent)
    {
		if(GetTemperature() <=80)
		{
			return true;
		}
        if ( parent.FindAttachmentBySlotName( "Gloves" ) && GetTemperature() >= 80)
        {
            return true;
        }
		return false;
    };
	override void SetActions()
	{
		super.SetActions();

		AddAction(ActionFillAnvilMold);
		AddAction(ActionFillIngotMold);
		AddAction(ActionFillBarMold);
		AddAction(ActionFillNuggetMold);
		AddAction(ActionEmptyCrucible);
	};
};
