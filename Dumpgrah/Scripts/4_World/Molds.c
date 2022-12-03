//class ND_ClayCrucibleMoltenIron: Bottle_Base{};
class ND_IncasedIngot : ItemBase{};
class ND_IngotMold: ItemBase
{
	
	void ND_IngotMold()
	{
	};
	
	ND_ClayCrucibleMoltenPigIron GetCastIronIngot()
	{
		return ND_ClayCrucibleMoltenPigIron.Cast( GetAttachmentByType( ND_ClayCrucibleMoltenPigIron ) );
	}
	
	ND_ImPureIronIngot GetImPureIronIngot()
	{
		return ND_ImPureIronIngot.Cast( GetAttachmentByType( ND_ImPureIronIngot ) );
	}
	
	ND_CrucibleMoltenIron GetIronIngot()
	{
		return ND_CrucibleMoltenIron.Cast( GetAttachmentByType( ND_CrucibleMoltenIron ) );
	}

	
	void CreateCastIngot()
	{
		Object targetObject;
		
		GetInventory().CreateAttachment("ND_CastIngot"); //Produces Item in the output slot
		AddHealth("","Health",-33);
		//GetIronIngot().SetTemperature(60)

	};
	void CreateImpureIngot()
	{
		Object targetObject;
		
		GetInventory().CreateAttachment("ND_ImPureIronIngot"); //Produces Item in the output slot
		AddHealth("","Health",-33);

	};
	void CreatePureIngot()
	{
		Object targetObject;
		
		GetInventory().CreateAttachment("ND_IronIngot"); //Produces Item in the output slot
		AddHealth("","Health",-33);

	};
};

class ND_BarMold : ItemBase
{
	void ND_BarMold()
	{
	};
	
	float CreateCast = GetForgingSettings().CastBarMade;
	float CreateImpure = GetForgingSettings().ImpureBarMade;
	float CreatePure = GetForgingSettings().PureBarMade;
	
	void CreateCastBar()
	{
		Object targetObject;
		ND_CastBar Bar = ND_CastBar.Cast(GetInventory().CreateAttachment("ND_CastBar"));
		Bar.SetQuantity(CreateCast);
		AddHealth("","Health",-15);

	};
	void CreateImpureBar()
	{
		Object targetObject;
		ND_ImPureIronBar Bar = ND_ImPureIronBar.Cast(GetInventory().CreateAttachment("ND_ImPureIronBar"));
		Bar.SetQuantity(CreateImpure);
		AddHealth("","Health",-15);

	};
	void CreatePureBar()
	{
		Object targetObject;
		ND_IronBar Bar = ND_IronBar.Cast(GetInventory().CreateAttachment("ND_IronBar"));
		Bar.SetQuantity(CreatePure);
		AddHealth("","Health",-15);

	};
	
};

class ND_NuggetMold : ItemBase
{
	void ND_NuggetMold()
	{
	};
	
	ND_ClayCrucibleMoltenPigIron GetCastIronNugget()
	{
		return ND_ClayCrucibleMoltenPigIron.Cast( GetAttachmentByType( ND_ClayCrucibleMoltenPigIron ) );
	}
	
	ND_ImPureIronIngot GetImPureIronNugget()
	{
		return ND_ImPureIronIngot.Cast( GetAttachmentByType( ND_ImPureIronIngot ) );
	}
	
	ND_CrucibleMoltenIron GetIronNugget()
	{
		return ND_CrucibleMoltenIron.Cast( GetAttachmentByType( ND_CrucibleMoltenIron ) );
	}

	float CreateCast = GetForgingSettings().CastNuggetsMade;
	float CreateImpure = GetForgingSettings().ImpureNuggetsMade;
	float CreatePure = GetForgingSettings().PureNuggetMade;
	
	void CreateCastNugget()
	{
		Object targetObject;
		ND_CastNugget Nugget = ND_CastNugget.Cast(GetInventory().CreateAttachment("ND_CastNugget"));
		Nugget.SetQuantity(CreateCast);
		AddHealth("","Health",-2);

	};
	void CreateImpureNugget()
	{
		Object targetObject;
		
		ND_ImPureIronNugget Nugget = ND_ImPureIronNugget.Cast(GetInventory().CreateAttachment("ND_ImPureIronNugget"));
		Nugget.SetQuantity(CreateImpure);
		AddHealth("","Health",-10);

	};
	void CreatePureNugget()
	{
		Object targetObject;
		
		ND_IronNugget Nugget = ND_IronNugget.Cast(GetInventory().CreateAttachment("ND_IronNugget"));
		Nugget.SetQuantity(CreatePure);
		AddHealth("","Health",-10);

	};
	
};
class ND_MSAMold : ItemBase
{
	private bool m_IsLocked = false;
	
	float QuantityAdded = GetForgingSettings().PourAnvilMetal;
	float QuantityRequired = GetForgingSettings().RequiredQuantityToCastAnvil;
	
	void ND_MSAMold()
	{
	};
	override void EEInit()
	{
		ShowSimpleSelection("AnvilMoldClay", 1);
		ShowSimpleSelection("Broken Mold", 0);
		
	}
	void CreateCastAnvil()
	{
		Object targetObject;
		PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
		ND_MSAMold Mold = ND_MSAMold.Cast( targetObject );
		if( GetQuantity() > QuantityRequired/2)
		{
			GetInventory().CreateAttachment("ND_MakeShiftCastIronAnvil"); //Produces Item in the output slot
			AddQuantity(QuantityAdded);
			LockAnvil(true);
			LockAnvilOne(true);
			LockAnvilTwo(true);
		}
		AddQuantity(QuantityAdded);
		AddHealth("","Health",-5);

	};
	void CreateImpureAnvil()
	{
		Object targetObject;
		PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
		ND_MSAMold Mold = ND_MSAMold.Cast( targetObject );
		if( GetQuantity() > QuantityRequired/2)
		{
			GetInventory().CreateAttachment("ND_MakeShiftImpureIronAnvil"); //Produces Item in the output slot
			AddQuantity(QuantityAdded);
			LockAnvil(true);
			LockAnvilOne(true);
			LockAnvilTwo(true);
		}
		AddQuantity(QuantityAdded);
		AddHealth("","Health",-5);

	};
	void CreatePureAnvil()
	{
		Object targetObject;
		PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
		ND_MSAMold Mold = ND_MSAMold.Cast( targetObject );
		if( GetQuantity() > QuantityRequired/2)
		{
			GetInventory().CreateAttachment("ND_MakeShiftPureIronAnvil"); //Produces Item in the output slot
			AddQuantity(QuantityAdded);
			LockAnvil(true);
			LockAnvilOne(true);
			LockAnvilTwo(true);
		}
		AddQuantity(QuantityAdded);
		AddHealth("","Health",-5);

	};
	void SmashMold()
	{
		ShowSimpleSelection("AnvilMoldClay", 0);
		ShowSimpleSelection("Broken Mold", 1);
		AddQuantity(-100);
		AddHealth("","Health",-100);
		LockAnvil(false);
		LockAnvilOne(false);
		LockAnvilTwo(false);
	};
	void SmashSmashMold()
	{
		ShowSimpleSelection("AnvilMoldClay", 0);
		ShowSimpleSelection("Broken Mold", 1);
	};
	
	private void ShowSimpleSelection(string selectionName, bool hide = false)
    {
        TStringArray selectionNames = new TStringArray;
        ConfigGetTextArray("simpleHiddenSelections",selectionNames);
        int selectionId = selectionNames.Find(selectionName);
        SetSimpleHiddenSelectionState(selectionId, hide);
    };
	void LockAnvil(bool do_lock)
	{
		ItemBase AnvilCastBase = GetCastAnvil();
		if (AnvilCastBase)
		{
			if (do_lock)
			{
				AnvilCastBase.LockToParent();
			}
			else
			{
				AnvilCastBase.UnlockFromParent();
			}
		}
	};
	void LockAnvilOne(bool do_lock)
	{
		ItemBase AnvilImpureBase = GetImpurePureAnvil();
		
		if (AnvilImpureBase)
		{
			if (do_lock)
			{
				AnvilImpureBase.LockToParent();
			}
			else
			{
				AnvilImpureBase.UnlockFromParent();
			}
		}
	}
	void LockAnvilTwo(bool do_lock)
	{
		ItemBase AnvilPureBase = GetPureAnvil();
		if (AnvilPureBase)
		{
			if (do_lock)
			{
				AnvilPureBase.LockToParent();
			}
			else
			{
				AnvilPureBase.UnlockFromParent();
			}
		}
	};
	ND_MakeShiftCastIronAnvil GetCastAnvil()
	{
		return ND_MakeShiftCastIronAnvil.Cast( GetAttachmentByType(ND_MakeShiftCastIronAnvil) );
	}
	ND_MakeShiftImpureIronAnvil GetImpurePureAnvil()
	{
		return ND_MakeShiftImpureIronAnvil.Cast( GetAttachmentByType(ND_MakeShiftImpureIronAnvil) );
	}
	ND_MakeShiftPureIronAnvil GetPureAnvil()
	{
		return ND_MakeShiftPureIronAnvil.Cast( GetAttachmentByType(ND_MakeShiftPureIronAnvil) );
	}
	override bool CanPutIntoHands( EntityAI parent )
    {
        super.CanPutIntoHands( parent );    
        if ( GetHealthLevel() == GameConstants.STATE_RUINED )
        {
            return false;
        }
		if ( GetInventory().AttachmentCount() == 1)
        {
            return false;
        }
        return true;

    };
	override bool CanPutInCargo( EntityAI parent )
    {
		super.CanPutInCargo(parent);
        if ( GetHealthLevel() == GameConstants.STATE_RUINED )
        {
            return false;
        }
		if ( GetInventory().AttachmentCount() == 1)
        {
            return false;
        }
        return true;
    };
	
};
#ifdef AM_MOD_221

class ND_ClayRifleCasingMold: StrongRifleCasingMold
{
	void ND_ClayRifleCasingMold()
	{
		ShowSimpleSelection("Casted_Casing", 0);
	};
	override void EEItemAttached(EntityAI item, string slot_name)
	{
		super.EEItemAttached(item,slot_name);
		if(slot_name == "RifleCasingMold")
		{
			ShowSimpleSelection("Casted_Casing", 1);
		};
	};
	
	override void EEItemDetached(EntityAI item, string slot_name)
	{
		super.EEItemDetached(item, slot_name);
		
		if(slot_name == "RifleCasingMold")
		{
			ShowSimpleSelection("Casted_Casing", 0);

		};
	};
	
	override void CreateCasing(string CreationType)
	{
		AM_CasingBase Casing = AM_CasingBase.Cast(GetInventory().CreateAttachment("Casing" + CreationType) );
		Casing.AddQuantity(10);
		AddQuantity(-2.5);
	};
};
class ND_ClayRifleTipsMold: StrongRifleTipsMold
{
	void ND_ClayRifleTipsMold()
	{
		ShowSimpleSelection("Casted_Tips", 0);
	};
	override void EEItemAttached(EntityAI item, string slot_name)
	{
		super.EEItemAttached(item,slot_name);
		if(slot_name == "RifleTipsMold")
		{
			ShowSimpleSelection("Casted_Tips", 1);
		};
	};
	
	override void EEItemDetached(EntityAI item, string slot_name)
	{
		super.EEItemDetached(item, slot_name);
		
		if(slot_name == "RifleTipsMold")
		{
			ShowSimpleSelection("Casted_Tips", 0);

		};
	};
	override void CreateTips(string CreationType)
	{
		AM_TipsBase Tips = AM_TipsBase.Cast(GetInventory().CreateAttachment("Tips" + CreationType) );
		Tips.AddQuantity(10);
		AddQuantity(-2.5);
	};
};
class ND_ClayPistolCasingMold: StrongPistolCasingMold
{
	void ND_ClayPistolCasingMold()
	{
		ShowSimpleSelection("Casted_Casing", 0);
	};
	override void EEItemAttached(EntityAI item, string slot_name)
	{
		super.EEItemAttached(item,slot_name);
		if(slot_name == "RifleCasingMold")
		{
			ShowSimpleSelection("Casted_Casing", 1);
		};
	};
	
	override void EEItemDetached(EntityAI item, string slot_name)
	{
		super.EEItemDetached(item, slot_name);
		
		if(slot_name == "RifleCasingMold")
		{
			ShowSimpleSelection("Casted_Casing", 0);
	
		};
	};
	
	override void CreateCasing(string CreationType)
	{
		AM_CasingBase Casing = AM_CasingBase.Cast(GetInventory().CreateAttachment("Casing" + CreationType) );
		Casing.AddQuantity(10);
		AddQuantity(-2.5);
	};
};
class ND_ClayPistolTipsMold: StrongPistolTipsMold
{
	void ND_ClayPistolTipsMold()
	{
		ShowSimpleSelection("Casted_Tips", 0);
	};
	override void EEItemAttached(EntityAI item, string slot_name)
	{
		super.EEItemAttached(item,slot_name);
		if(slot_name == "RifleTipsMold")
		{
			ShowSimpleSelection("Casted_Tips", 1);
		};
	};
	
	override void EEItemDetached(EntityAI item, string slot_name)
	{
		super.EEItemDetached(item, slot_name);
		
		if(slot_name == "RifleTipsMold")
		{
			ShowSimpleSelection("Casted_Tips", 0);

		};
	};
	override void CreateTips(string CreationType)
	{
		AM_TipsBase Tips = AM_TipsBase.Cast(GetInventory().CreateAttachment("Tips" + CreationType) );
		Tips.AddQuantity(10);
		AddQuantity(-2.5);
	};
};
#endif