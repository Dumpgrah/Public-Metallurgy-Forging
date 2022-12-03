class ND_IngotBase : ItemBase
{
	protected ref Timer m_HeatingTimer;
	protected ref Timer m_CoolingTimer;
	float HeatingRate = GetSmelterSettings().CrudeSmelterHeatingRate;
	
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
	
	protected void StartCooling()
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
		float Temp = GetForgingSettings().SmithMetalTemp;
		float temperature = GetTemperature();
		temperature = temperature - 6;

		SetTemperature(temperature);
		
		if ( GetTemperature() == 1)
		{
			m_CoolingTimer.Stop();
			m_CoolingTimer = NULL;
			//Print("zxd");
		}
		if (GetTemperature() <= Temp)
		{
			ShowSimpleSelection("IngotCold", 1);
			ShowSimpleSelection("IngotHot", 0);
			
		};
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
		float Temp = GetForgingSettings().SmithMetalTemp;
		float temperature = GetTemperature();
		temperature = temperature + 10;
		SetTemperature( temperature );
		if (GetTemperature() >= Temp)
		{
			ShowSimpleSelection("IngotCold", 0);
			ShowSimpleSelection("IngotHot", 1);
		}
	};
	void ShowSimpleSelection(string selectionName, bool hide = false)
    {
        TStringArray selectionNames = new TStringArray;
        ConfigGetTextArray("simpleHiddenSelections",selectionNames);
        int selectionId = selectionNames.Find(selectionName);
        SetSimpleHiddenSelectionState(selectionId, hide);
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
	override bool CanPutInCargo( EntityAI parent )
    {
		if (GetTemperature() >= 50)
		{
			return false;
		}
		return true;
    }
	
}
class ND_NuggetBase : ItemBase
{
	protected ref Timer m_HeatingTimer;
	protected ref Timer m_CoolingTimer;
	float HeatingRate = GetSmelterSettings().CrudeSmelterHeatingRate;
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
	
	protected void StartCooling()
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
		if (GetTemperature() <= 700)
		{
			ShowSimpleSelection("NuggetCold", 1);
			ShowSimpleSelection("NuggetHot", 0);
			
		};
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
		float Temp = GetForgingSettings().SmithMetalTemp;
		float temperature = GetTemperature();
		temperature = temperature + HeatingRate + 20;
		SetTemperature( temperature );
		if (GetTemperature() >= Temp)
		{
			ShowSimpleSelection("NuggetCold", 0);
			ShowSimpleSelection("NuggetHot", 1);
		};
	};
	override void OnWasAttached(EntityAI parent, int slot_id)
	{
		super.OnWasAttached(parent, slot_id);
		if (parent.IsKindOf("ND_ForgeBase") && parent.GetCompEM().IsWorking() )
		{
			StartHeating();
			StopCooling();
		}
		if (parent.IsKindOf("ND_ForgewHood")&& parent.GetCompEM().IsWorking() )
		{
			StartHeating();
			StopCooling();
		}
	};
	
	override void OnWasDetached(EntityAI parent, int slot_id)
	{
		super.OnWasDetached(parent,slot_id);
		StopHeating();
		StartCooling();

    };
	void ShowSimpleSelection(string selectionName, bool hide = false)
    {
        TStringArray selectionNames = new TStringArray;
        ConfigGetTextArray("simpleHiddenSelections",selectionNames);
        int selectionId = selectionNames.Find(selectionName);
        SetSimpleHiddenSelectionState(selectionId, hide);
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
	override bool CanPutInCargo( EntityAI parent )
    {
		if (GetTemperature() >= 50)
		{
			return false;
		}
		return true;
    };
}
class ND_ImPureIronIngot extends ND_IngotBase
{
	void ND_ImPureIronIngot()
	{

	};
	
	override void OnWasAttached(EntityAI parent, int slot_id)
	{
		super.OnWasAttached(parent, slot_id);
		float Temp = GetForgingSettings().SmithMetalTemp;
		if (GetTemperature() >= Temp)
		{
			ShowSimpleSelection("IngotCold", 0);
			ShowSimpleSelection("IngotHot", 1);
		}
		if (GetTemperature() <= Temp)
		{
			ShowSimpleSelection("IngotCold", 1);
			ShowSimpleSelection("IngotHot", 0);
			
		}
		if (parent.IsKindOf("ND_ForgeBase")&& parent.GetCompEM().IsWorking() )
		{
			StartHeating();
			StopCooling();
		}
		if (parent.IsKindOf("ND_ForgewHood")&& parent.GetCompEM().IsWorking() )
		{
			StartHeating();
			StopCooling();
		}
		
	};
	
	override void OnWasDetached(EntityAI parent, int slot_id)
	{
		super.OnWasDetached(parent,slot_id);
		float Temp = GetForgingSettings().SmithMetalTemp;
		if (GetTemperature() >= Temp)
		{
			ShowSimpleSelection("IngotCold", 0);
			ShowSimpleSelection("IngotHot", 1);
			Update();
            SetSynchDirty();
		}
		if (GetTemperature() <= Temp)
		{
			ShowSimpleSelection("IngotCold", 1);
			ShowSimpleSelection("IngotHot", 0);
		}
		StopHeating();
		StartCooling();

    };
	override bool CanPutInCargo( EntityAI parent )
    {
		if (GetTemperature() >= 50)
		{
			return false;
		}
		return true;
    };
    


	
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionDetach);
		AddAction(ActionAttach);
		AddAction(ActionAttachOnProxy);
	};
};
class ND_ImPureIronBar extends ItemBase
{
	
	float HeatingRate = GetSmelterSettings().CrudeSmelterHeatingRate;
	void ND_ImPureIronBar()
	{
		ShowSimpleSelection("BarCold", 1);
		ShowSimpleSelection("BarHot", 0);
	};
	
	override void OnWasAttached(EntityAI parent, int slot_id)
	{
		super.OnWasAttached(parent, slot_id);
		float Temp = GetForgingSettings().SmithMetalTemp;
		
		if (GetTemperature() >= Temp)
		{
			ShowSimpleSelection("BarCold", 0);
			ShowSimpleSelection("BarHot", 1);
		};
		if (GetTemperature() <= Temp)
		{
			ShowSimpleSelection("BarCold", 1);
			ShowSimpleSelection("BarHot", 0);
			
		};
		if (parent.IsKindOf("ND_ForgeBase")&& parent.GetCompEM().IsWorking() )
		{
			StartHeating();
			StopCooling();
		}
		if (parent.IsKindOf("ND_ForgewHood")&& parent.GetCompEM().IsWorking() )
		{
			StartHeating();
			StopCooling();
		}
	};
	
	override void OnWasDetached(EntityAI parent, int slot_id)
	{
		super.OnWasDetached(parent,slot_id);
		float Temp = GetForgingSettings().SmithMetalTemp;
		
		if (GetTemperature() >= Temp)
		{
			ShowSimpleSelection("BarCold", 0);
			ShowSimpleSelection("BarHot", 1);
		};
		if (GetTemperature() <= Temp)
		{
			ShowSimpleSelection("BarCold", 1);
			ShowSimpleSelection("BarHot", 0);
			
		};
		StopHeating();
		StartCooling();

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
	void ShowSimpleSelection(string selectionName, bool hide = false)
    {
        TStringArray selectionNames = new TStringArray;
        ConfigGetTextArray("simpleHiddenSelections",selectionNames);
        int selectionId = selectionNames.Find(selectionName);
        SetSimpleHiddenSelectionState(selectionId, hide);
    };
	protected ref Timer m_HeatingTimer;
	protected ref Timer m_CoolingTimer;
	
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
	
	protected void StartCooling()
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
		float Temp = GetForgingSettings().SmithMetalTemp;
		float temperature = GetTemperature();
		temperature = temperature - 12;

		SetTemperature(temperature);
		
		if ( GetTemperature() == 1)
		{
			m_CoolingTimer.Stop();
			m_CoolingTimer = NULL;
			//Print("zxd");
		}
		if (GetTemperature() <= Temp)
		{
			ShowSimpleSelection("BarCold", 1);
			ShowSimpleSelection("BarHot", 0);
			
		};
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
		float Temp = GetForgingSettings().SmithMetalTemp;
		float temperature = GetTemperature();
		temperature = temperature + HeatingRate + 10;
		SetTemperature( temperature );
		if (GetTemperature() >= Temp)
		{
			ShowSimpleSelection("BarCold", 0);
			ShowSimpleSelection("BarHot", 1);
		};
	};
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionDetach);
		AddAction(ActionAttach);
		AddAction(ActionAttachOnProxy);
	}
};
class ND_ImPureIronNugget extends ND_NuggetBase
{
	void ND_ImPureIronNugget()
	{
		ShowSimpleSelection("NuggetCold", 1);
		ShowSimpleSelection("NuggetHot", 0);
	};
	
	override void OnWasAttached(EntityAI parent, int slot_id)
	{
		super.OnWasAttached(parent, slot_id);
		float Temp = GetForgingSettings().SmithMetalTemp;
		
		if (GetTemperature() >= Temp)
		{
			ShowSimpleSelection("NuggetCold", 0);
			ShowSimpleSelection("NuggetHot", 1);
		};
		if (GetTemperature() <= Temp)
		{
			ShowSimpleSelection("NuggetCold", 1);
			ShowSimpleSelection("NuggetHot", 0);
			
		};
		if (parent.IsKindOf("ND_ForgeBase")&& parent.GetCompEM().IsWorking() )
		{
			StartHeating();
			StopCooling();
		}
		if (parent.IsKindOf("ND_ForgewHood")&& parent.GetCompEM().IsWorking() )
		{
			StartHeating();
			StopCooling();
		}
	};
	
	override void OnWasDetached(EntityAI parent, int slot_id)
	{
		super.OnWasDetached(parent,slot_id);
		float Temp = GetForgingSettings().SmithMetalTemp;
		
		if (GetTemperature() >= Temp)
		{
			ShowSimpleSelection("NuggetCold", 0);
			ShowSimpleSelection("NuggetHot", 1);
		};
		if (GetTemperature() <= Temp)
		{
			ShowSimpleSelection("NuggetCold", 1);
			ShowSimpleSelection("NuggetHot", 0);
			
		};
		StopHeating();
		StartCooling();

    };
	

    

	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionDetach);
		AddAction(ActionAttach);
		AddAction(ActionAttachOnProxy);
	}
};
class ND_CastIngot extends ND_IngotBase
{
	void ND_CastIngot()
	{
		ShowSimpleSelection("IngotCold", 1);
		ShowSimpleSelection("IngotHot", 0);
	};
	
	override void OnWasAttached(EntityAI parent, int slot_id)
	{
		super.OnWasAttached(parent, slot_id);
		float Temp = GetForgingSettings().SmithMetalTemp;
		if (GetTemperature() >= Temp)
		{
			ShowSimpleSelection("IngotCold", 0);
			ShowSimpleSelection("IngotHot", 1);
		}
		if (GetTemperature() <= Temp)
		{
			ShowSimpleSelection("IngotCold", 1);
			ShowSimpleSelection("IngotHot", 0);
			
		}
		if (parent.IsKindOf("ND_ForgeBase")&& parent.GetCompEM().IsWorking() )
		{
			StartHeating();
			StopCooling();
		}
		if (parent.IsKindOf("ND_ForgewHood")&& parent.GetCompEM().IsWorking() )
		{
			StartHeating();
			StopCooling();
		}
		
	};
	override void OnWasDetached(EntityAI parent, int slot_id)
	{
		super.OnWasDetached(parent,slot_id);
		float Temp = GetForgingSettings().SmithMetalTemp;
		if (GetTemperature() >= Temp)
		{
			ShowSimpleSelection("IngotCold", 0);
			ShowSimpleSelection("IngotHot", 1);
			Update();
            SetSynchDirty();
		}
		if (GetTemperature() <= Temp)
		{
			ShowSimpleSelection("IngotCold", 1);
			ShowSimpleSelection("IngotHot", 0);
		}
		StopHeating();
		StartCooling();

    };
	override bool CanPutInCargo( EntityAI parent )
    {
		if (GetTemperature() >= 50)
		{
			return false;
		}
		return true;
    };
    

	
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionDetach);
		AddAction(ActionAttach);
		AddAction(ActionAttachOnProxy);
	};
};
class ND_CastBar:ND_ImPureIronBar{};
class ND_CastNugget:ND_NuggetBase
{
	void ND_CastNugget()
	{
		ShowSimpleSelection("NuggetCold", 1);
		ShowSimpleSelection("NuggetHot", 0);
	};
	
	override void OnWasAttached(EntityAI parent, int slot_id)
	{
		super.OnWasAttached(parent, slot_id);
		float Temp = GetForgingSettings().SmithMetalTemp;
		
		if (GetTemperature() >= Temp)
		{
			ShowSimpleSelection("NuggetCold", 0);
			ShowSimpleSelection("NuggetHot", 1);
		};
		if (GetTemperature() <= Temp)
		{
			ShowSimpleSelection("NuggetCold", 1);
			ShowSimpleSelection("NuggetHot", 0);
			
		};
		if (parent.IsKindOf("ND_ForgeBase")&& parent.GetCompEM().IsWorking() )
		{
			StartHeating();
			StopCooling();
		}
		if (parent.IsKindOf("ND_ForgewHood")&& parent.GetCompEM().IsWorking() )
		{
			StartHeating();
			StopCooling();
		}
	};

	
	override bool CanPutInCargo( EntityAI parent )
    {
		if (GetTemperature() >= 50)
		{
			return false;
		}
		return true;
    }
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionDetach);
		AddAction(ActionAttach);
		AddAction(ActionAttachOnProxy);
	}
};
class ND_IronIngot extends ND_IngotBase
{
	void ND_IronIngot()
	{
		ShowSimpleSelection("IngotCold", 1);
		ShowSimpleSelection("IngotHot", 0);
	};
	
	override void OnWasAttached(EntityAI parent, int slot_id)
	{
		super.OnWasAttached(parent, slot_id);
		float Temp = GetForgingSettings().SmithMetalTemp;
		
		if (GetTemperature() >= Temp)
		{
			ShowSimpleSelection("IngotCold", 0);
			ShowSimpleSelection("IngotHot", 1);
		}
		if (GetTemperature() <= Temp)
		{
			ShowSimpleSelection("IngotCold", 1);
			ShowSimpleSelection("IngotHot", 0);
			
		}
		if (parent.IsKindOf("ND_ForgeBase")&& parent.GetCompEM().IsWorking() )
		{
			StartHeating();
			StopCooling();
		}
		if (parent.IsKindOf("ND_ForgewHood")&& parent.GetCompEM().IsWorking() )
		{
			StartHeating();
			StopCooling();
		}
		
	};
	
	override void OnWasDetached(EntityAI parent, int slot_id)
	{
		super.OnWasDetached(parent,slot_id);
		float Temp = GetForgingSettings().SmithMetalTemp;
		
		if (GetTemperature() >= Temp)
		{
			ShowSimpleSelection("IngotCold", 0);
			ShowSimpleSelection("IngotHot", 1);
			Update();
            SetSynchDirty();
		}
		if (GetTemperature() <= Temp)
		{
			ShowSimpleSelection("IngotCold", 1);
			ShowSimpleSelection("IngotHot", 0);

			
		}
		StopHeating();
		StartCooling();

    };
	override bool CanPutInCargo( EntityAI parent )
    {
		if (GetTemperature() >= 50)
		{
			return false;
		}
		return true;
    };
    
	
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionDetach);
		AddAction(ActionAttach);
		AddAction(ActionAttachOnProxy);
	};
};
class ND_IronBar:ND_ImPureIronBar{};
class ND_IronNugget:ND_NuggetBase
{
	void ND_IronNugget()
	{
		ShowSimpleSelection("NuggetCold", 1);
		ShowSimpleSelection("NuggetHot", 0);
	};
	
	override void OnWasAttached(EntityAI parent, int slot_id)
	{
		super.OnWasAttached(parent, slot_id);
		float Temp = GetForgingSettings().SmithMetalTemp;
		
		if (GetTemperature() >= Temp)
		{
			ShowSimpleSelection("NuggetCold", 0);
			ShowSimpleSelection("NuggetHot", 1);
		};
		if (GetTemperature() <= Temp)
		{
			ShowSimpleSelection("NuggetCold", 1);
			ShowSimpleSelection("NuggetHot", 0);
			
		};
		if (parent.IsKindOf("ND_ForgeBase") && parent.GetCompEM().IsWorking() )
		{
			StartHeating();
			StopCooling();
		}
		if (parent.IsKindOf("ND_ForgewHood")&& parent.GetCompEM().IsWorking() )
		{
			StartHeating();
			StopCooling();
		}
	};
	
	override void OnWasDetached(EntityAI parent, int slot_id)
	{
		super.OnWasDetached(parent,slot_id);
		float Temp = GetForgingSettings().SmithMetalTemp;
		
		if (GetTemperature() >= Temp)
		{
			ShowSimpleSelection("NuggetCold", 0);
			ShowSimpleSelection("NuggetHot", 1);
		};
		if (GetTemperature() <= Temp)
		{
			ShowSimpleSelection("NuggetCold", 1);
			ShowSimpleSelection("NuggetHot", 0);
			
		};
		StopHeating();
		StartCooling();

    };
	protected void StopHeating()
	{
		m_HeatingTimer.Stop();
		m_HeatingTimer = NULL;
	}
	
	override bool CanPutInCargo( EntityAI parent )
    {
		if (GetTemperature() >= 50)
		{
			return false;
		}
		return true;
    }
    

	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionDetach);
		AddAction(ActionAttach);
		AddAction(ActionAttachOnProxy);
	}
};