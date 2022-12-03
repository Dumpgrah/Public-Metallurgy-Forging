modded class Pickaxe extends ItemBase
{

	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionMineOre);
	}
};
modded class Shovel extends ItemBase
{
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionDigClay);
	}
};
class ClayPit extends ItemBase 
{
	void MineClay(PlayerBase player)
    {    
		vector pos = player.GetPosition();
        vector ori = GetOrientation(); // im not getting used ;_;
    
		ItemBase Rock = ItemBase.Cast( GetGame().CreateObjectEx( "ND_ClayLump", pos, ECE_PLACE_ON_SURFACE ) );
		ItemBase Rock1 = ItemBase.Cast( GetGame().CreateObjectEx( "ND_ClayLump", pos, ECE_PLACE_ON_SURFACE ) );
		ItemBase Rock2 = ItemBase.Cast( GetGame().CreateObjectEx( "ND_ClayLump", pos, ECE_PLACE_ON_SURFACE ) );
        
		
		Rock2.SetPosition(pos);
		Rock1.SetPosition(pos);
		Rock.SetPosition(pos);
        AddQuantity(-50);
    }
	override bool CanPutIntoHands( EntityAI parent )
    {
        super.CanPutIntoHands( parent );
		
        return false;
    };
	override bool CanPutInCargo( EntityAI parent )
    {
		super.CanPutInCargo(parent);
		
        return false;
    };
};
class BoulderisBoulder extends ItemBase 
{
	void MineOre(PlayerBase player)
    {    
		vector pos = player.GetPosition();
        vector ori = GetOrientation(); // im not getting used ;_;
    
		ItemBase Rock = ItemBase.Cast( GetGame().CreateObjectEx( "Stone", pos, ECE_PLACE_ON_SURFACE ) );
		ItemBase Rock1 = ItemBase.Cast( GetGame().CreateObjectEx( "SmallStone", pos, ECE_PLACE_ON_SURFACE ) );
		ItemBase Rock2 = ItemBase.Cast( GetGame().CreateObjectEx( "SmallStone", pos, ECE_PLACE_ON_SURFACE ) );
        
		
		Rock2.SetPosition(pos);
		Rock1.SetPosition(pos);
		Rock.SetPosition(pos);
        AddQuantity(-10);
    }
	override bool CanPutIntoHands( EntityAI parent )
    {
        super.CanPutIntoHands( parent );
		
        return false;
    };
	override bool CanPutInCargo( EntityAI parent )
    {
		super.CanPutInCargo(parent);
		
        return false;
    };
};

class CoalOreBoulder extends BoulderisBoulder 
{
    void MineOre(PlayerBase player)
    {    
        vector pos = player.GetPosition();
        vector ori = GetOrientation(); // im not getting used ;_;
    
        ItemBase item = ItemBase.Cast( GetGame().CreateObjectEx( "ND_OreCoal", pos, ECE_PLACE_ON_SURFACE ) );
		ItemBase Rock = ItemBase.Cast( GetGame().CreateObjectEx( "Stone", pos, ECE_PLACE_ON_SURFACE ) );
		ItemBase Rock1 = ItemBase.Cast( GetGame().CreateObjectEx( "SmallStone", pos, ECE_PLACE_ON_SURFACE ) );
		ItemBase Rock2 = ItemBase.Cast( GetGame().CreateObjectEx( "SmallStone", pos, ECE_PLACE_ON_SURFACE ) );
        
		
		Rock2.SetPosition(pos);
		Rock1.SetPosition(pos);
            
        item.SetPosition(pos);
		Rock.SetPosition(pos);
        AddQuantity(-10);
    }
	override bool CanPutIntoHands( EntityAI parent )
    {
        super.CanPutIntoHands( parent );
		
        return false;


    };
	override bool CanPutInCargo( EntityAI parent )
    {
		super.CanPutInCargo(parent);
		
        return false;
    };
};
class CopperOreBoulder extends BoulderisBoulder 
{
    void MineOre(PlayerBase player)
    {    
        vector pos = player.GetPosition();
        vector ori = GetOrientation(); // im not getting used ;_;
    
        ItemBase item = ItemBase.Cast( GetGame().CreateObjectEx( "ND_OreCopper", pos, ECE_PLACE_ON_SURFACE ) );
		ItemBase Rock = ItemBase.Cast( GetGame().CreateObjectEx( "Stone", pos, ECE_PLACE_ON_SURFACE ) );
		ItemBase Rock1 = ItemBase.Cast( GetGame().CreateObjectEx( "SmallStone", pos, ECE_PLACE_ON_SURFACE ) );
		ItemBase Rock2 = ItemBase.Cast( GetGame().CreateObjectEx( "SmallStone", pos, ECE_PLACE_ON_SURFACE ) );
        
		
		Rock2.SetPosition(pos);
		Rock1.SetPosition(pos);
            
        item.SetPosition(pos);
		Rock.SetPosition(pos);
        AddQuantity(-34);
    }
	override bool CanPutIntoHands( EntityAI parent )
    {
        super.CanPutIntoHands( parent );
		
        return false;


    };
	override bool CanPutInCargo( EntityAI parent )
    {
		super.CanPutInCargo(parent);
		
        return false;
    };
};
class IronOreBoulder extends BoulderisBoulder 
{
    void MineOre(PlayerBase player)
    {    
        vector pos = player.GetPosition();
        vector ori = GetOrientation(); // im not getting used ;_;
    
        ItemBase item = ItemBase.Cast( GetGame().CreateObjectEx( "ND_OreIron", pos, ECE_PLACE_ON_SURFACE ) );
		ItemBase Rock = ItemBase.Cast( GetGame().CreateObjectEx( "Stone", pos, ECE_PLACE_ON_SURFACE ) );
		ItemBase Rock1 = ItemBase.Cast( GetGame().CreateObjectEx( "SmallStone", pos, ECE_PLACE_ON_SURFACE ) );
		ItemBase Rock2 = ItemBase.Cast( GetGame().CreateObjectEx( "SmallStone", pos, ECE_PLACE_ON_SURFACE ) );
        
		
		Rock2.SetPosition(pos);
		Rock1.SetPosition(pos);
            
        item.SetPosition(pos);
		Rock.SetPosition(pos);
        AddQuantity(-25);
    }
	override bool CanPutIntoHands( EntityAI parent )
    {
        super.CanPutIntoHands( parent );
		
        return false;


    };
	override bool CanPutInCargo( EntityAI parent )
    {
		super.CanPutInCargo(parent);
		
        return false;
    };
};
class KimberliteOreBoulder extends BoulderisBoulder 
{
    void MineOre(PlayerBase player)
    {    
        vector pos = player.GetPosition();
        vector ori = GetOrientation(); // im not getting used ;_;
    
        ItemBase item = ItemBase.Cast( GetGame().CreateObjectEx( "ND_OreKimberlite", pos, ECE_PLACE_ON_SURFACE ) );
		ItemBase Rock = ItemBase.Cast( GetGame().CreateObjectEx( "Stone", pos, ECE_PLACE_ON_SURFACE ) );
		ItemBase Rock1 = ItemBase.Cast( GetGame().CreateObjectEx( "SmallStone", pos, ECE_PLACE_ON_SURFACE ) );
		ItemBase Rock2 = ItemBase.Cast( GetGame().CreateObjectEx( "SmallStone", pos, ECE_PLACE_ON_SURFACE ) );
        
		
		Rock2.SetPosition(pos);
		Rock1.SetPosition(pos);
            
        item.SetPosition(pos);
		Rock.SetPosition(pos);
        AddQuantity(-55);
    }
	override bool CanPutIntoHands( EntityAI parent )
    {
        super.CanPutIntoHands( parent );
		
        return false;


    };
	override bool CanPutInCargo( EntityAI parent )
    {
		super.CanPutInCargo(parent);
		
        return false;
    };
};
class LeadOreBoulder extends BoulderisBoulder 
{
    void MineOre(PlayerBase player)
    {    
        vector pos = player.GetPosition();
        vector ori = GetOrientation(); // im not getting used ;_;
    
        ItemBase item = ItemBase.Cast( GetGame().CreateObjectEx( "ND_OreLead", pos, ECE_PLACE_ON_SURFACE ) );
		ItemBase item2 = ItemBase.Cast( GetGame().CreateObjectEx( "ND_OreZinc", pos, ECE_PLACE_ON_SURFACE ) );
		ItemBase Rock = ItemBase.Cast( GetGame().CreateObjectEx( "Stone", pos, ECE_PLACE_ON_SURFACE ) );
		ItemBase Rock1 = ItemBase.Cast( GetGame().CreateObjectEx( "SmallStone", pos, ECE_PLACE_ON_SURFACE ) );
		ItemBase Rock2 = ItemBase.Cast( GetGame().CreateObjectEx( "SmallStone", pos, ECE_PLACE_ON_SURFACE ) );
        
		
		Rock2.SetPosition(pos);
		Rock1.SetPosition(pos);
            
        item.SetPosition(pos);
		item2.SetPosition(pos);
		Rock.SetPosition(pos);
        AddQuantity(-35);
    }
	override bool CanPutIntoHands( EntityAI parent )
    {
        super.CanPutIntoHands( parent );
		
        return false;


    };
	override bool CanPutInCargo( EntityAI parent )
    {
		super.CanPutInCargo(parent);
		
        return false;
    };
};
class QuartzOreBoulder extends BoulderisBoulder 
{
    void MineOre(PlayerBase player)
    {    
        vector pos = player.GetPosition();
        vector ori = GetOrientation(); // im not getting used ;_;
    
        ItemBase item = ItemBase.Cast( GetGame().CreateObjectEx( "ND_OreQuartz", pos, ECE_PLACE_ON_SURFACE ) );
		ItemBase Rock = ItemBase.Cast( GetGame().CreateObjectEx( "Stone", pos, ECE_PLACE_ON_SURFACE ) );
		ItemBase Rock1 = ItemBase.Cast( GetGame().CreateObjectEx( "SmallStone", pos, ECE_PLACE_ON_SURFACE ) );
		ItemBase Rock2 = ItemBase.Cast( GetGame().CreateObjectEx( "SmallStone", pos, ECE_PLACE_ON_SURFACE ) );
        
		
		Rock2.SetPosition(pos);
		Rock1.SetPosition(pos);
            
        item.SetPosition(pos);
		Rock.SetPosition(pos);
        AddQuantity(-55);
    }
	override bool CanPutIntoHands( EntityAI parent )
    {
        super.CanPutIntoHands( parent );
		
        return false;


    };
	override bool CanPutInCargo( EntityAI parent )
    {
		super.CanPutInCargo(parent);
		
        return false;
    };
};
class SulfurOreBoulder extends BoulderisBoulder 
{
    void MineOre(PlayerBase player)
    {    
        vector pos = player.GetPosition();
        vector ori = GetOrientation(); // im not getting used ;_;
    
        ItemBase item = ItemBase.Cast( GetGame().CreateObjectEx( "ND_OreSulfur", pos, ECE_PLACE_ON_SURFACE ) );
		ItemBase Rock = ItemBase.Cast( GetGame().CreateObjectEx( "Stone", pos, ECE_PLACE_ON_SURFACE ) );
		ItemBase Rock1 = ItemBase.Cast( GetGame().CreateObjectEx( "SmallStone", pos, ECE_PLACE_ON_SURFACE ) );
		ItemBase Rock2 = ItemBase.Cast( GetGame().CreateObjectEx( "SmallStone", pos, ECE_PLACE_ON_SURFACE ) );
        
		
		Rock2.SetPosition(pos);
		Rock1.SetPosition(pos);
            
        item.SetPosition(pos);
		Rock.SetPosition(pos);
        AddQuantity(-35);
    }
	override bool CanPutIntoHands( EntityAI parent )
    {
        super.CanPutIntoHands( parent );
		
        return false;


    };
	override bool CanPutInCargo( EntityAI parent )
    {
		super.CanPutInCargo(parent);
		
        return false;
    };
};
class ActionDigClay: ActionContinuousBase
{
	static int CYCLES = 4;
	void ActionDigClay()
	{
		m_CallbackClass = ActionMineOreCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DIGMANIPULATE;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT;		
		
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_HIGH;
	}
	
	override void CreateConditionComponents()  
	{	
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTNonRuined( UAMaxDistances.BASEBUILDING );
	}
		
	override string GetText()
	{

		return "Dig Clay";

	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Object target_object = target.GetObject();
		string selection = target_object.GetActionComponentName( target.GetComponentIndex() );
		ClayPit Pit = ClayPit.Cast( target_object );
		
		if (Pit)
		{
			return true;
		}	
		return false;
	}
	
	override void OnFinishProgressServer( ActionData action_data )
    {    
        ClayPit Pit = ClayPit.Cast( action_data.m_Target.GetObject() );
        Pit.MineClay(action_data.m_Player)
		action_data.m_MainItem.DecreaseHealth( 15, false );
    }
	
	override string GetAdminLogMessage(ActionData action_data)
	{
		return " Mined Ore " + action_data.m_Target.GetObject().GetDisplayName() + " with " + action_data.m_MainItem.GetDisplayName();
	}
};
class ActionMineOre: ActionContinuousBase
{
	static int CYCLES = 4;
	void ActionMineOre()
	{
		m_CallbackClass = ActionMineOreCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_MINEROCK;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT;		
		
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_HIGH;
	}
	
	override void CreateConditionComponents()  
	{	
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTNonRuined( UAMaxDistances.BASEBUILDING );
	}
		
	override string GetText()
	{

		return "Mine Boulder";

	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Object target_object = target.GetObject();
		string selection = target_object.GetActionComponentName( target.GetComponentIndex() );
		BoulderisBoulder Boulder = BoulderisBoulder.Cast( target_object );
		
		if (Boulder)
		{
			return true;
		}	
		return false;
	}
	
	override void OnFinishProgressServer( ActionData action_data )
    {    
        BoulderisBoulder Boulder = BoulderisBoulder.Cast( action_data.m_Target.GetObject() );
        Boulder.MineOre(action_data.m_Player)
		action_data.m_MainItem.DecreaseHealth( 15, false );
    }
	
	override string GetAdminLogMessage(ActionData action_data)
	{
		return " Mined Ore " + action_data.m_Target.GetObject().GetDisplayName() + " with " + action_data.m_MainItem.GetDisplayName();
	}
};
class ActionMineOreCB : ActionContinuousBaseCB
{	
	override void CreateActionComponent()
	{
		//m_ActionData.m_ActionComponent = new CAContinuousTime( 30 ); // Dont forget to change back to 30
		m_ActionData.m_ActionComponent = new CAContinuousRepeat( UATimeSpent.MineOre/ActionMineOre.Cast(m_ActionData.m_Action).CYCLES );
	}
};
modded class UATimeSpent
{
	const float MineOre = 30;
}