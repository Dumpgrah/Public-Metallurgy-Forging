class ND_ToolWedges extends ItemBase
{
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionAttach);
	}
};
class ND_TreeStump: ItemBase{};

modded class WoodAxe extends ToolBase
{
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionSplitLogRound);
	}
}

modded class Hammer extends Inventory_Base
{
	int m_SmithActionIngot = 0;
	
	int m_SmithActionBar = 0;
	
	int m_SmithActionNugget = 0;
	
	override void EEInit()
	{
      super.EEInit();
      RegisterNetSyncVariableInt("m_SmithActionIngot");
	  RegisterNetSyncVariableInt("m_SmithActionBar");
	  RegisterNetSyncVariableInt("m_SmithActionNugget");
    };
	string GetSmithTendancyText()
	{
        if (m_SmithActionIngot == 0)
		{
          return "Pickaxe Head";
        }
		if (m_SmithActionIngot == 1)
		{
          return "Axe Head";
        }
        if (m_SmithActionIngot == 2)
		{
          return "Hammer Head";
        }
		if (m_SmithActionIngot == 3)
		{
          return "Shovel Head";
        }
        return "";

    };
    string GetSmithTendancyCreationType()
	{
        if (m_SmithActionIngot == 0)
		{
          return "PickaxeHead";
        }
		if (m_SmithActionIngot == 1)
		{
          return "AxeHead";
        }
        if (m_SmithActionIngot == 2)
		{
          return "HammerHead";
        }
		if (m_SmithActionIngot == 3)
		{
          return "ShovelHead";
        }
        return "";
    };
	void StepSmithTendancy()
	{
      m_SmithActionIngot++;
      if (m_SmithActionIngot > 3)
	  {
         m_SmithActionIngot = 0;
      }
      SetSynchDirty();
    };
	
	int SmithTendancy()
	{
      return m_SmithActionIngot;
    };
//Bar
	string GetSmithTendancyBarText()
	{

		if (m_SmithActionBar == 0)
		{
          return "Dagger Parts";
        }
        return "";
    };
	string GetSmithTendancyBarCreationType()
	{
		if (m_SmithActionBar == 0)
		{
          return "IronDaggerBlade";
        }
        return "";
    };
	void StepSmithBarTendancy()
	{
      m_SmithActionBar++;
      if (m_SmithActionBar > 0)
	  {
         m_SmithActionBar = 0;
      }
      SetSynchDirty();
    }
	
	int SmithBarTendancy()
	{
      return m_SmithActionBar;
    }
//Nugget
	string GetSmithTendancyNuggetText()
	{

		if (m_SmithActionNugget == 0)
		{
          return "Iron Nails";
        }
		if (m_SmithActionNugget == 1)
		{
          return "Tool Wedges";
        }
        return "";
    }
	string GetSmithTendancyNuggetCreationType()
	{
		if (m_SmithActionNugget == 0)
		{
          return "IronNails";
        }
		if (m_SmithActionNugget == 1)
		{
          return "ToolWedges";
        }
        return "";
    }
	void StepSmithNuggetTendancy()
	{
      m_SmithActionNugget++;
      if (m_SmithActionNugget > 1)
	  {
         m_SmithActionNugget = 0;
      }
      SetSynchDirty();
    }
	
	int SmithNuggetTendancy()
	{
      return m_SmithActionNugget;
    }
	
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
	}
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionSmashMold);
		
		AddAction(ActionSmithingIngot);
		AddAction(ActionChangeSmithIngotAction);
		
		AddAction(ActionSmithingBar);
		AddAction(ActionChangeSmithBarAction);

		
		AddAction(ActionSmithingNugget);
		AddAction(ActionChangeSmithNuggetAction);

	}
	
}

class ND_CastIronNails extends Nail{};
class ND_ImpureIronNails extends Nail{};
class ND_PureIronNails extends Nail{};

class ND_CastAxe extends WoodAxe{};
class ND_CastHammer extends Hammer{};
class ND_CastPickaxe extends Pickaxe{};
class ND_CastShovel extends Shovel{};
class ND_ImpureShovel extends Shovel{};
class ND_PureShovel extends Shovel{};
class ND_ImpureIronAxe extends WoodAxe{};
class ND_ImpureIronHammer extends Hammer{};
class ND_PureIronHammer extends Hammer{};
class ND_PureIronHatchet extends Hatchet
{
	
	override void Open()
	{
		ReplaceEdibleWithNew("ND_PureIronHatchetHammer");
	}
	
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
	}
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionTurnAroundHatchet);
	}

}
class ND_PureIronHatchetHammer extends Hammer
{
	
	override void Open()
	{
		ReplaceEdibleWithNew("ND_PureIronHatchet");
	}
	
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
	}
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionTurnAroundHatchet);
	}
}
class ND_ImpureIronHatchet extends Hatchet
{
	
	override void Open()
	{
		ReplaceEdibleWithNew("ND_ImpureIronHatchetHammer");
	}
	
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
	}
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionTurnAroundHatchet);
		RemoveAction(ActionBuildPartSwitch);
		AddAction(ActionMineTree);
		AddAction(ActionMineBush);
		RemoveAction(ActionBuildPart);
		AddAction(ActionDismantlePart);
		RemoveAction(ActionDestroyPart);
		//AddAction(ActionSawPlanks);
		AddAction(ActionUnrestrainTarget);
	}
}
class ND_ImpureIronHatchetHammer extends Hammer
{
	
	override void Open()
	{
		ReplaceEdibleWithNew("ND_ImpureIronHatchet");
	}
	
	override void ReplaceEdibleWithNew (string typeName)
	{
		PlayerBase player = PlayerBase.Cast(GetHierarchyRootPlayer());
		if (player)
		{
			ReplaceEdibleWithNewLambda lambda = new ReplaceEdibleWithNewLambda(this, typeName, player);
			player.ServerReplaceItemInHandsWithNew(lambda);
		}
		else
			Error("ReplaceEdibleWithNew - cannot use edible without player");
	}
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionTurnAroundHatchet);
	}
}
class ND_ImpurePickAxe extends Pickaxe
{
};
modded class ActionBuildPartCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		float time = SetBuildingDuration(m_ActionData.m_MainItem);
		m_ActionData.m_ActionComponent = new CAContinuousTime( time );
	}
	
	float SetBuildingDuration( ItemBase item )
	{
		switch( item.Type() )
		{
			case Pickaxe:
			case Shovel:
			case ND_CastShovel:
			case ND_ImpureShovel:
			case ND_PureShovel:
			case FieldShovel:
				return 7.0;
			default:
				return UATimeSpent.DEFAULT_CONSTRUCT;
		}
		return UATimeSpent.DEFAULT_CONSTRUCT;
	}
};
modded class ActionBuildPart: ActionContinuousBase
{

	protected override void SetBuildingAnimation( ItemBase item )
	{
		switch( item.Type() )
		{
			case Pickaxe:
			case Shovel:
			case ND_CastShovel:
			case ND_ImpureShovel:
			case ND_PureShovel:
			case FieldShovel:
				m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DIG;
				break;
			case Pliers:
				m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_INTERACT;
				break;
			case SledgeHammer:
				m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_MINEROCK;
				break;
			default:
				m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_ASSEMBLE;
				break;
		}
	}

}
modded class ActionDismantlePartCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		float time = SetBuildingDuration(m_ActionData.m_MainItem);
		m_ActionData.m_ActionComponent = new CAContinuousTime( time );
	}
	
	float SetBuildingDuration( ItemBase item )
	{
		switch( item.Type() )
		{
			case Pickaxe:
			case Shovel:
			case ND_CastShovel:
			case ND_ImpureShovel:
			case ND_PureShovel:
			case FieldShovel:
				return 7.0;
			default:
				return UATimeSpent.DEFAULT_DECONSTRUCT;
		}
		return UATimeSpent.DEFAULT_DECONSTRUCT;
	}
};

modded class ActionDismantlePart: ActionContinuousBase
{
	protected override void SetBuildingAnimation( ItemBase item )
	{
		switch( item.Type() )
		{
			case Pickaxe:
			case Shovel:
			case ND_CastShovel:
			case ND_ImpureShovel:
			case ND_PureShovel:
			case FieldShovel:
				m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DIG;
				break;
			case Pliers:
				m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_INTERACT;
				break;				
			default:
				m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DISASSEMBLE;
				break;
		}
	}
};
	