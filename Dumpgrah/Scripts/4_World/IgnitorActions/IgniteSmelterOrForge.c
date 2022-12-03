class ActionLightSmelterCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime( 5 ); // Dont forget to change back to 30
	}
}

class ActionLightForgeFire: ActionContinuousBase
{
	void ActionLightForgeFire()
	{
		m_CallbackClass = ActionLightSmelterCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_STARTFIRE;
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
		return "#ignite";
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{	
		EntityAI target_entity = EntityAI.Cast( target.GetObject() );
		ND_ForgewHood Forge = ND_ForgewHood.Cast(target.GetObject() );
		ND_ForgeBase ForgeBase = ND_ForgeBase.Cast(target.GetObject() );
		Matchbox lighter = Matchbox.Cast(target.GetObject() );
		
		if ( Forge && Forge.GetAttachmentByType( ND_StackedCoal ) && !target_entity.GetCompEM().IsSwitchedOn()  || ForgeBase && ForgeBase.GetAttachmentByType( ND_StackedCoal )  && !target_entity.GetCompEM().IsSwitchedOn()  )
		{
			return true;
		}
		if ( Forge && Forge.GetAttachmentByType( ND_Charcoal ) && !target_entity.GetCompEM().IsSwitchedOn()  || ForgeBase && ForgeBase.GetAttachmentByType( ND_Charcoal )  && !target_entity.GetCompEM().IsSwitchedOn()  )
		{
			return true;
		}
		
		return false;
	}

	override void OnFinishProgressServer( ActionData action_data )
	{
		ND_ForgewHood Forge = ND_ForgewHood.Cast( action_data.m_Target.GetObject() );
		ND_ForgeBase ForgeBase = ND_ForgeBase.Cast( action_data.m_Target.GetObject() );
		PlayerBase target = PlayerBase.Cast(action_data.m_Player);
		
		if( ForgeBase.GetCompEM().CanWork() )
		{
			ForgeBase.GetCompEM().SwitchOn();
			MinusQuantity( action_data.m_MainItem, target );
		}
	}
	void MinusQuantity( ItemBase item, PlayerBase player )
	{
		item.AddQuantity(-3,false);// some reason repeats the -# twice no clue.
	}
}
class ActionLightSmelterFire: ActionContinuousBase
{
	void ActionLightSmelterFire()
	{
		m_CallbackClass = ActionLightSmelterCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_STARTFIRE;
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
		return "#ignite";
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{	
		EntityAI target_entity = EntityAI.Cast( target.GetObject() );
		ND_ImprovedSmelter Smelter = ND_ImprovedSmelter.Cast(target.GetObject() );
		ND_Smelter BaseSmelter = ND_Smelter.Cast(target.GetObject() );
		Matchbox lighter = Matchbox.Cast(target.GetObject() );
		
		if ( Smelter && Smelter.GetAttachmentByType( ND_StackedCoal ) && !target_entity.GetCompEM().IsSwitchedOn() || BaseSmelter && BaseSmelter.GetAttachmentByType( ND_StackedCoal ) && !target_entity.GetCompEM().IsSwitchedOn())
		{
			return true;
		}
		///lighter.IsIgnited()
		return false;
	}

	override void OnFinishProgressServer( ActionData action_data )
	{
		ND_ImprovedSmelter Smelter = ND_ImprovedSmelter.Cast( action_data.m_Target.GetObject() );
		ND_Smelter BaseSmelter = ND_Smelter.Cast( action_data.m_Target.GetObject() );
		PlayerBase target = PlayerBase.Cast(action_data.m_Player);
		
		if ( Smelter.GetCompEM().CanWork() )
		{
			Smelter.GetCompEM().SwitchOn();
			MinusQuantity( action_data.m_MainItem, target );
		}
		if( BaseSmelter.GetCompEM().CanWork() )
		{
			BaseSmelter.GetCompEM().SwitchOn();
			MinusQuantity( action_data.m_MainItem, target );
		}
	}
	void MinusQuantity( ItemBase item, PlayerBase player )
	{
		item.AddQuantity(-3,false);// some reason repeats the -# twice no clue.
	}
}