modded class UATimeSpent
{
	const float DEFAULT_DESTROY_SMELTER = 600; //600
};
modded class UADamageApplied
{
	const float CrackSmelter = 50;
	const float SplitWood = 25;
};
class ActionSplitStumpCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime( 25 ); // Dont forget to change back to 30
	}
}
class ActionDestroySmelterCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.DEFAULT_DESTROY_SMELTER);
	}
};

class ActionSmashSmelter: ActionContinuousBase
{	
	void ActionSmashSmelter()
	{
		m_CallbackClass = ActionDestroySmelterCB;
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
		ND_Smelter Smelter = ND_Smelter.Cast( target_object );
		
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
		ND_Smelter Smelter = ND_Smelter.Cast( action_data.m_Target.GetObject() );
		if ( Smelter )
		{
			Smelter.Delete();
			Smelter = ND_Smelter.Cast( GetGame().CreateObject("ND_SimpleSmelterDestroyed", pos) );
			action_data.m_MainItem.DecreaseHealth( UADamageApplied.CrackSmelter, false );
			
			Smelter.SetPosition(pos);
		}
		
		//soft skills
		action_data.m_Player.GetSoftSkillsManager().AddSpecialty( m_SpecialtyWeight );
	}

};
class ActionSplitLogRound: ActionContinuousBase
{	
	void ActionSplitLogRound()
	{
		m_CallbackClass = ActionSplitStumpCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_MINEROCK;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT;
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_HIGH;
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
		return "Split Log Round";
	}
/*	override typename GetInputType()
	{
		return ContinuousInteractActionInput;
	}*/
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Object target_object = target.GetObject();
		string selection = target_object.GetActionComponentName( target.GetComponentIndex() );
		ND_TreeStump Stump = ND_TreeStump.Cast( target_object );
		
		if ( Stump)
		{
			return true;
		}		
		return false;
	}

	override void OnFinishProgressServer( ActionData action_data )
	{
		vector pos = action_data.m_Player.GetPosition();
		ND_TreeStump Stump = ND_TreeStump.Cast( action_data.m_Target.GetObject() );
		if ( Stump )
		{
			Stump.Delete();
			Stump = ND_TreeStump.Cast( GetGame().CreateObject("ND_SplitWood", pos) );
			action_data.m_MainItem.DecreaseHealth( UADamageApplied.SplitWood, false );
			
			Stump.SetPosition(pos);
		}
		
		//soft skills
		action_data.m_Player.GetSoftSkillsManager().AddSpecialty( m_SpecialtyWeight );
	}

};
modded class SledgeHammer
{
	void SetActions()
	{
		super.SetActions();
		AddAction(ActionClapBearTrapWithThisItem);
		AddAction(ActionMineRock);
		AddAction(ActionBuildPartSwitch);
		AddAction(ActionDismantlePart);
		AddAction(ActionBuildPart);
		AddAction(ActionSmashSmelter);
		AddAction(ActionSmashImprovedSmelter);
	}
}

