class ActionTurnAroundHatchet: ActionSingleUseBase
{
	void ActionTurnAroundHatchet()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_OPENITEM_ONCE;
		m_CommandUIDProne = DayZPlayerConstants.CMD_ACTIONFB_OPENITEM_ONCE;
		//m_Animation = "open";
	}
	
	override void CreateConditionComponents()  
	{	
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTNone;
	}

	override bool HasTarget()
	{
		return false;
	}

	override string GetText()
	{
		return "Turn Around";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{

		return true;

	}
	
	override bool ActionConditionContinue( ActionData action_data )
	{
		return true;
	}
	
	override void OnExecuteClient( ActionData action_data )
	{
		if( !GetGame().IsMultiplayer() )
			#ifdef DAYZ_1_11
                ClearInventoryReservation(action_data);
            #else
                ClearInventoryReservationEx(action_data);
            #endif
		
		action_data.m_MainItem.Open();
	}

	override void OnExecuteServer( ActionData action_data )
	{
		if( !GetGame().IsMultiplayer() )
		    #ifdef DAYZ_1_11
                ClearInventoryReservation(action_data);
            #else
                ClearInventoryReservationEx(action_data);
            #endif
		
		action_data.m_MainItem.Open();
	}
};
class ActionSmashMoldCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime( 5 ); // Dont forget to change back to 30
	}
}
class ActionSmashMold: ActionContinuousBase
{
	void ActionSmashMold()
	{
		m_CallbackClass = ActionSmashMoldCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_ASSEMBLE;
		m_FullBody = true;
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
		return "Smash Mold";
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{	
		EntityAI target_entity = EntityAI.Cast( target.GetObject() );
		ND_MSAMold Mold = ND_MSAMold.Cast(target.GetObject() );
			
		if ( Mold && target_entity.FindAttachmentBySlotName("AnvilCastMetal"))
		{
		  return true;
		}
		return false;
	}

	override void OnFinishProgressServer( ActionData action_data )
	{
		ND_MSAMold Mold = ND_MSAMold.Cast( action_data.m_Target.GetObject() );
		
		Mold.SmashMold();
		
	}
	override void OnFinishProgressClient( ActionData action_data )
	{
		ND_MSAMold Mold = ND_MSAMold.Cast( action_data.m_Target.GetObject() );
		
		Mold.SmashMold();
		
	}

};