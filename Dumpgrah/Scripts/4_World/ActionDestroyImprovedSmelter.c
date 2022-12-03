class ActionDestroyImprovedSmelterCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.DEFAULT_DESTROY_SMELTER);
	}
};

class ActionSmashImprovedSmelter: ActionContinuousBase
{	
	void ActionSmashImprovedSmelter()
	{
		m_CallbackClass = ActionDestroyImprovedSmelterCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DISASSEMBLE;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT;
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_MEDIUM;
	}
	 
	override void CreateConditionComponents()  
	{	
		m_ConditionTarget = new CCTNonRuined(UAMaxDistances.DEFAULT);
		m_ConditionItem = new CCINonRuined;
	}
/*
	override int GetType()
	{
		return 2324243;
	}
*/
	override string GetText()
	{
		return "Smash Smelter";
	}
/*	override typename GetInputType()
	{
		return ContinuousInteractActionInput;
	}*/
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Object target_object = target.GetObject();
		string selection = target_object.GetActionComponentName( target.GetComponentIndex() );
		ND_ImprovedSmelter Smelter = ND_ImprovedSmelter.Cast( target_object );
		
		if ( Smelter && Smelter.IsNDLocked()/* && selection == "wall_interact"*/ )
		{
			return true;
		}
		if ( Smelter)
		{
			return true;
		}		
		return false;
	}

	override void OnFinishProgressServer( ActionData action_data )
	{
		vector pos = action_data.m_Player.GetPosition();
		ND_ImprovedSmelter Smelter = ND_ImprovedSmelter.Cast( action_data.m_Target.GetObject() );
		if ( Smelter )
		{
			Smelter.Delete();
			Smelter = ND_ImprovedSmelter.Cast( GetGame().CreateObject("ND_ImprovedSmelterDestroyed", pos) );
			action_data.m_MainItem.DecreaseHealth( UADamageApplied.CrackSmelter, false );
			
			Smelter.SetPosition(pos);
		}
		
		//soft skills
		action_data.m_Player.GetSoftSkillsManager().AddSpecialty( m_SpecialtyWeight );
	}

};

