class ActionEmptyCrucibleCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
	  m_ActionData.m_ActionComponent = new CAContinuousTime(10);
	}
};

class ActionEmptyCrucible101: ActionContinuousBase
{
	void ActionEmptyCrucible101()
	{
		m_CallbackClass = ActionEmptyCrucibleCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_EMPTY_VESSEL;
		m_CommandUIDProne = DayZPlayerConstants.CMD_ACTIONMOD_EMPTY_VESSEL;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT;
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_MEDIUM;
	}
	
	override void CreateConditionComponents()  
	{	
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTSurface(UAMaxDistances.DEFAULT);
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		// Check if player is standing on terrain
		vector plr_pos = player.GetPosition();
		float height = GetGame().SurfaceY(plr_pos[0], plr_pos[2]);
		height = plr_pos[1] - height;
		
		if ( height > 0.4 )
			return false; // Player is not standing on ground
		
		if ( !GetGame().IsMultiplayer() || GetGame().IsClient() )
		{
			if ( !player.IsPlacingLocal() && player.IsCurrentCameraAimedAtGround() )
			{
				if ( target )
				{
					string surface_type;
					vector position;
					position = target.GetCursorHitPos();
					
					GetGame().SurfaceGetType( position[0], position[2], surface_type );
					

					return true;
					
				}
			}
		
			return false;
		}
		else
		{
			return true;
		}
	}


	override bool HasTarget()
	{
		return true;
	}

	override string GetText()
	{
		return "Empty Crucible";
	}

	override void OnFinishProgressServer( ActionData action_data )
	{	
		if( !GetGame().IsMultiplayer() )
       ClearInventoryReservationEx(action_data);
		
		action_data.m_MainItem.Open();
	}
		
	override void OnExecuteClient( ActionData action_data )
	{
		if( !GetGame().IsMultiplayer() )
       ClearInventoryReservationEx(action_data);
		
		action_data.m_MainItem.Open();
	}

	override void OnExecuteServer( ActionData action_data )
	{
		if( !GetGame().IsMultiplayer() )
       ClearInventoryReservationEx(action_data);
		
		action_data.m_MainItem.Open();
	}
};