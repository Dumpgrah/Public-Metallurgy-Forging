class ActionReadBookForge extends ActionSingleUseBase
{
	void ActionReadBook()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_DROPITEM_HANDS;
		m_FullBody = false;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_PRONE;
		//m_Animation = "break";
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
		return "#read";
	}

	override void OnExecuteClient( ActionData action_data )
	{
		action_data.m_Player.ToggleBookReading();
	}

	override void OnExecuteServer( ActionData action_data )
	{
		if (!GetGame().IsMultiplayer())
			action_data.m_Player.ToggleBookReading();
	}
};
