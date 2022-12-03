modded class ActionMineTree : ActionMineBase
{
	void ActionMineTree()
	{
		m_CallbackClass = ActionMineTreeCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_HACKTREE;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT;
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_HIGH;
	}
	
	override void CreateConditionComponents()
	{	
		m_ConditionTarget = new CCTCursor(UAMaxDistances.SMALL);
		m_ConditionItem = new CCINonRuined;
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		
		//Action not allowed if player has broken legs
		if (player.GetBrokenLegs() == eBrokenLegs.BROKEN_LEGS)
			return false;
		
		Object targetObject = target.GetObject();
		//GetMaterialAndQuantityMap
		
		return targetObject.IsTree() && targetObject.IsCuttable();
	}
	
	override void OnFinishProgressServer( ActionData action_data )
	{
		action_data.m_Player.GetSoftSkillsManager().AddSpecialty( m_SpecialtyWeight );
		TreeHard TreeHardMod = TreeHard.Cast( action_data.m_Target.GetObject() );
		super.OnFinishProgressServer(action_data);	
		if(TreeHardMod && TreeHardMod.GetHealth("","") < 5)
		{
			ItemBase Rock = ItemBase.Cast( GetGame().CreateObjectEx( "ND_TreeStump",action_data.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE ) );
		};			
		
		// "hiding" of map item
		//action_data.m_Target.GetObject().SetOrigin("0 0 0");
	}
};