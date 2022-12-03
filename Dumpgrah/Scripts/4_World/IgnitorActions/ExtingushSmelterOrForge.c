class ActionExtingushSmelterCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime( 20 ); // Dont forget to change back to 30
	}
}

class ActionExtingushForgeFire: ActionContinuousBase
{
	void ActionExtingushForgeFire()
	{
		m_CallbackClass = ActionExtingushSmelterCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_FIREESTINGUISHER;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT;
		//m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH;
		
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_HIGH;
	}
	
	override void CreateConditionComponents()  
	{	
		m_ConditionTarget = new CCTNonRuined( UAMaxDistances.DEFAULT );
		m_ConditionItem = new CCINonRuined;
	}
		
	override string GetText()
	{
		return "Extingush";
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{	
		Object target_object = target.GetObject();
		ND_ForgeBase ForgeBase = ND_ForgeBase.Cast( target_object );
		
		if (ForgeBase && ForgeBase.GetCompEM().IsSwitchedOn() )
		{
			return true;
		}
		
		return false;
	}

	override void OnFinishProgressServer( ActionData action_data )
	{
		ND_ForgewHood Forge = ND_ForgewHood.Cast( action_data.m_Target.GetObject() );
		ND_ForgeBase ForgeBase = ND_ForgeBase.Cast( action_data.m_Target.GetObject() );
		Pot Iron = Pot.Cast(action_data.m_MainItem);
		PlayerBase target = PlayerBase.Cast(action_data.m_Player);
		
		if( ForgeBase.GetCompEM().CanWork() )
		{
			ForgeBase.GetCompEM().SwitchOff();
			MinusQuantity( action_data.m_MainItem, target );
		}
	}
	void MinusQuantity( ItemBase item, PlayerBase player )
	{
		item.AddQuantity(-300,false);// some reason repeats the -# twice no clue.
	}
}
class ActionExtingushSmelterFire: ActionContinuousBase
{
	void ActionExtingushSmelterFire()
	{
		m_CallbackClass = ActionExtingushSmelterCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_FIREESTINGUISHER;
		m_FullBody = true;
		//m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH;
		
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_HIGH;
	}
	
	override void CreateConditionComponents()  
	{	
		m_ConditionTarget = new CCTNonRuined( UAMaxDistances.DEFAULT );
		m_ConditionItem = new CCINonRuined;
	}
		
	override string GetText()
	{
		return "Extingush";
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{	
		//EntityAI target_entity = EntityAI.Cast( target.GetObject() );
		//ND_ImprovedSmelter Smelter = ND_ImprovedSmelter.Cast(target.GetObject() );
		//ND_Smelter BaseSmelter = ND_Smelter.Cast(target.GetObject() );
		//FireExtinguisher Extinguisher = FireExtinguisher.Cast(target.GetObject() );
		Object target_object = target.GetObject();
		SmelterBase BaseSmelter = SmelterBase.Cast( target_object );

		if ( BaseSmelter && BaseSmelter.GetCompEM().IsSwitchedOn() && BaseSmelter.GetAttachmentByType( ND_StackedCoal ) && !BaseSmelter.GetAttachmentByType( ND_MoltenCrucible ) )
		{
			return true;
		};
		
		return false;
	}

	override void OnFinishProgressServer( ActionData action_data )
	{
		SmelterBase BaseSmelter = SmelterBase.Cast( action_data.m_Target.GetObject() );
		PlayerBase target = PlayerBase.Cast(action_data.m_Player);
		
		if( BaseSmelter.GetCompEM().CanWork() )
		{
			BaseSmelter.GetCompEM().SwitchOff();
			MinusQuantity( action_data.m_MainItem, target );
		}
	}
	void MinusQuantity( ItemBase item, PlayerBase player )
	{
		item.AddQuantity(-300,false);// some reason repeats the -# twice no clue.
	}
};