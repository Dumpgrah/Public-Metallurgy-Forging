modded class UADamageApplied
{
	float IngotDmg = GetForgingSettings().SmithIngotDmg;
	float BarDmg = GetForgingSettings().SmithBarDmg;
	float NuggetDmg = GetForgingSettings().SmithNuggetDmg;
	
	const float SmithingHeavy	= IngotDmg;
	const float SmithingMed	= BarDmg;
	const float SmithingLight	= NuggetDmg;
};
class ActionSmithingIngotCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		float SmithIngot = GetForgingSettings().SmithIngotTime;
		
		m_ActionData.m_ActionComponent = new CAContinuousTime( SmithIngot );//120
	};
}
class ActionSmithingBarCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		float SmithBar = GetForgingSettings().SmithBarTime;
		
		m_ActionData.m_ActionComponent = new CAContinuousTime( SmithBar );//30
	};
};
class ActionSmithingNuggetCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		float SmithNugget = GetForgingSettings().SmithNuggetTime;
		
		m_ActionData.m_ActionComponent = new CAContinuousTime( SmithNugget );//5
	};
};
class ActionSmithingNailsCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		float SmithNugget = GetForgingSettings().SmithNuggetTime;
		
		m_ActionData.m_ActionComponent = new CAContinuousTime( SmithNugget );//45
	};
};
class ActionChangeSmithIngotAction: ActionSingleUseBase
{
    void ActionChangeSmithIngotAction()
	{
        m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_OPENDOORFW;
        m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
        //m_HUDCursorIcon = CursorIcons.OpenDoors;
    };

    override void CreateConditionComponents()
	{
        m_ConditionItem = new CCINone;
        m_ConditionTarget = new CCTCursor;
    };

    override string GetText()
	{
        return "Change Action";
    };

    override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
        EntityAI target_entity = EntityAI.Cast( target.GetObject() );
        Object target_object = target.GetObject();
		Anvil_Base AnvilBase = Anvil_Base.Cast( target_object );
		ND_IngotBase CheckIngot = ND_IngotBase.Cast( target_entity.GetAttachmentByType(ND_IngotBase) );
        
        if (AnvilBase && CheckIngot && !AnvilBase.GetOutPutOccupied())
		{
            return true;
        }
        return false;
    };
    
	override void OnStartServer( ActionData action_data )
    {
        Hammer Ham = Hammer.Cast(action_data.m_MainItem);
        if (Ham)
		{
            Ham.StepSmithTendancy();
        }
    };
};
class ActionChangeSmithBarAction: ActionSingleUseBase
{
    void ActionChangeSmithBarAction()
	{
        m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_OPENDOORFW;
        m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
        //m_HUDCursorIcon = CursorIcons.OpenDoors;
    };

    override void CreateConditionComponents()
	{
        m_ConditionItem = new CCINone;
        m_ConditionTarget = new CCTCursor;
    };

    override string GetText()
	{
        return "Change Action";
    };

    override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
        EntityAI target_entity = EntityAI.Cast( target.GetObject() );
        Object target_object = target.GetObject();
		Anvil_Base AnvilBase = Anvil_Base.Cast( target_object );
		ND_ImPureIronBar CheckBar = ND_ImPureIronBar.Cast( target_entity.GetAttachmentByType(ND_ImPureIronBar) );
        
        if (AnvilBase && CheckBar && !AnvilBase.GetOutPutOccupied())
		{
            return true;
        }
        return false;
    };
    
	override void OnStartServer( ActionData action_data )
    {
        Hammer Ham = Hammer.Cast(action_data.m_MainItem);
        if (Ham)
		{
            Ham.StepSmithBarTendancy();
        }
    };
};
class ActionChangeSmithNuggetAction: ActionSingleUseBase
{
    void ActionChangeSmithNuggetAction()
	{
        m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_OPENDOORFW;
        m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
        //m_HUDCursorIcon = CursorIcons.OpenDoors;
    };

    override void CreateConditionComponents()
	{
        m_ConditionItem = new CCINone;
        m_ConditionTarget = new CCTCursor;
    };

    override string GetText()
	{
        return "Change Action";
    };

    override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
        EntityAI target_entity = EntityAI.Cast( target.GetObject() );
        Object target_object = target.GetObject();
		Anvil_Base AnvilBase = Anvil_Base.Cast( target_object );
		ND_NuggetBase CheckNugget = ND_NuggetBase.Cast( target_entity.GetAttachmentByType(ND_NuggetBase) );
        
        if (AnvilBase && CheckNugget && !AnvilBase.GetOutPutOccupied())
		{
            return true;
        }
        return false;
    };
    
	override void OnStartServer( ActionData action_data )
    {
        Hammer Ham = Hammer.Cast(action_data.m_MainItem);
        if (Ham)
		{
            Ham.StepSmithNuggetTendancy();
        }
    };
};
class ActionSmithingIngot: ActionContinuousBase
{	
	void ActionSmithingIngot()
	{
		m_CallbackClass = ActionSmithingIngotCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_ASSEMBLE;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT;
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_HIGH;
	};
	int SpamCounter = 0;
    string TendancyText = "";
    override string GetText()
	{
		
        return "Smith " + TendancyText;
    };

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		//Hammer Ham = player.GetItemInHands();
		
		Hammer Ham = item;
		
		int currenttime = GetGame().GetTime();
		
		EntityAI target_entity = EntityAI.Cast( target.GetObject() );
        Object target_object = target.GetObject();
		Anvil_Base AnvilBase = Anvil_Base.Cast( target.GetObject() );
		ND_SteelAnvil SteelAnvil = ND_SteelAnvil.Cast( target.GetObject() );
		ND_IngotBase CheckIngot = ND_IngotBase.Cast( target_entity.GetAttachmentByType(ND_IngotBase) );
		
		if (AnvilBase && AnvilBase.GetForgingMetalCount() > 0 && AnvilBase.IsTemperatureValid() && Ham && CheckIngot && !AnvilBase.GetOutPutOccupied())
		{
			TendancyText = Ham.GetSmithTendancyText();
			if(AnvilBase.GetForgingMetal() == "Ingot")
			{
				m_CallbackClass = ActionSmithingIngotCB;
			}
			else
			{
				m_CallbackClass = ActionSmithingIngotCB;
			}
			return true;
		}
		return false;
	};

	override void OnFinishProgressServer( ActionData action_data )
	{
		Hammer Ham = Hammer.Cast(action_data.m_MainItem);
		
		Anvil_Base AnvilTest = Anvil_Base.Cast( action_data.m_Target.GetObject() );
		ND_SteelAnvil SteelAnvil = ND_SteelAnvil.Cast( action_data.m_Target.GetObject() );
		
		AnvilTest.DestroyIngotAndCreateItem(Ham.GetSmithTendancyCreationType());
		//AnvilTest.DestroyNuggetAndItem(Ham.GetSmithTendancyCreationType())
		
		
		action_data.m_MainItem.DecreaseHealth( UADamageApplied.SmithingHeavy, false );
	};
};
class ActionSmithingBar: ActionContinuousBase
{	
	void ActionSmithingBar()
	{
		m_CallbackClass = ActionSmithingBarCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_ASSEMBLE;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT;
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_HIGH;
	};
	int SpamCounter = 0;
    string TendancyText = "";
    override string GetText()
	{
		
        return "Smith " + TendancyText;
    };

    override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		//Hammer Ham = player.GetItemInHands();
		
		Hammer Ham = item;
		
		int currenttime = GetGame().GetTime();
		
		EntityAI target_entity = EntityAI.Cast( target.GetObject() );
        Object target_object = target.GetObject();
		Anvil_Base AnvilBase = Anvil_Base.Cast( target.GetObject() );
		ND_SteelAnvil SteelAnvil = ND_SteelAnvil.Cast( target.GetObject() );
		ND_IronBar CheckBar = ND_IronBar.Cast( target_entity.GetAttachmentByType(ND_IronBar) );
		ND_CastBar CheckBar1 = ND_CastBar.Cast( target_entity.GetAttachmentByType(ND_CastBar) );
		ND_ImPureIronBar CheckBar2 = ND_ImPureIronBar.Cast( target_entity.GetAttachmentByType(ND_ImPureIronBar) );
		
		if (AnvilBase && AnvilBase.GetForgingBarCount() && AnvilBase.IsTemperatureValid() && Ham && CheckBar && !AnvilBase.GetOutPutOccupied())
		{
			TendancyText = Ham.GetSmithTendancyBarText();
			if(AnvilBase.GetForgingMetal() == "Bar")
			{
				m_CallbackClass = ActionSmithingBarCB;
			}
			return true;
		}
		else if (CheckBar1 || CheckBar2);
		{
			return false;
		}
		return false;
	};

	override void OnFinishProgressServer( ActionData action_data )
	{
		Hammer Ham = Hammer.Cast(action_data.m_MainItem);
		
		Anvil_Base AnvilTest = Anvil_Base.Cast( action_data.m_Target.GetObject() );
		ND_SteelAnvil SteelAnvil = ND_SteelAnvil.Cast( action_data.m_Target.GetObject() );
		
		AnvilTest.DestroyBarAndItem(Ham.GetSmithTendancyBarCreationType());
		//AnvilTest.DestroyNuggetAndItem(Ham.GetSmithTendancyCreationType())
		
		action_data.m_MainItem.DecreaseHealth( UADamageApplied.SmithingHeavy, false );
	};
};
class ActionSmithingNugget: ActionContinuousBase
{	
	void ActionSmithingNugget()
	{
		m_CallbackClass = ActionSmithingIngotCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_ASSEMBLE;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT;
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_HIGH;
	};
	int SpamCounter = 0;
    string TendancyText = "";
    override string GetText()
	{
		
        return "Smith " + TendancyText;
    };

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
    {
		//Hammer Ham = player.GetItemInHands();
		
		
		Hammer Ham = item;
		
		int currenttime = GetGame().GetTime();
		
		EntityAI target_entity = EntityAI.Cast( target.GetObject() );
        Object target_object = target.GetObject();
		Anvil_Base AnvilBase = Anvil_Base.Cast( target.GetObject() );
		ND_SteelAnvil SteelAnvil = ND_SteelAnvil.Cast( target.GetObject() );
		ND_NuggetBase CheckNugget = ND_NuggetBase.Cast( target_entity.GetAttachmentByType(ND_NuggetBase) );
		
		if (AnvilBase && AnvilBase.GetForgingNuggetCount() >= 19 && AnvilBase.IsTemperatureValid() && Ham && CheckNugget && !AnvilBase.GetOutPutOccupied() && AnvilBase.NuggetNailCheck() )
		{
			TendancyText = Ham.GetSmithTendancyNuggetText();
			if(AnvilBase.GetForgingMetal() == "Nugget")
			{
				m_CallbackClass = ActionSmithingNailsCB;
			}
			else
			{
				m_CallbackClass = ActionSmithingIngotCB;
			}
			return true;
		}
		return false;
	};

	override void OnFinishProgressServer( ActionData action_data )
	{
		Hammer Ham = Hammer.Cast(action_data.m_MainItem);
		
		Anvil_Base AnvilTest = Anvil_Base.Cast( action_data.m_Target.GetObject() );
		ND_SteelAnvil SteelAnvil = ND_SteelAnvil.Cast( action_data.m_Target.GetObject() );
		if(Ham.m_SmithActionNugget == 1)
		{
			AnvilTest.DestoryNuggetAndCreateWedges(Ham.GetSmithTendancyNuggetCreationType());
		}
		else 
			AnvilTest.DestroyNuggetAndItem(Ham.GetSmithTendancyNuggetCreationType());
		
		
		action_data.m_MainItem.DecreaseHealth( UADamageApplied.SmithingHeavy, false );
	};
	
};