class ActionDetachToTongs: ActionInteractBase
{
	string m_ItemName = "";

	void ActionDetachToTongs()
	{
		m_CommandUID        = DayZPlayerConstants.CMD_ACTIONMOD_PICKUP_HANDS;
		m_CommandUIDProne	= DayZPlayerConstants.CMD_ACTIONFB_PICKUP_HANDS;
		m_HUDCursorIcon     = CursorIcons.LootCorpse;
	}

	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTNone;
	}	
	
	override bool HasProneException()
	{
		return true;
	}

	override string GetText()
	{
		return "#take_to_hands";
	}
	
	override typename GetInputType()
	{
		return ContinuousInteractActionInput;
	}
	
	override bool HasProgress()
	{
		return false;
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		ItemBase tgt_item = ItemBase.Cast( target.GetObject() );
		EntityAI tgt_parent = EntityAI.Cast( target.GetParent() );
		EntityAI tgt_entity = EntityAI.Cast( target.GetObject() );

		if ( !tgt_item || !tgt_entity || !tgt_parent )
			return false;

		if ( !tgt_parent || !tgt_item.IsItemBase() || !tgt_item.IsTakeable() || tgt_item.IsBeingPlaced() )
			return false;

		if ( player.GetCommand_Vehicle() )
			return false;

		if ( player.GetInventory().CanAddEntityIntoInventory(tgt_entity) )
		{
			if ( tgt_entity.GetHierarchyRootPlayer() != player )
			{
				if ( tgt_entity.CanDetachAttachment( tgt_parent ) && tgt_parent.CanReleaseAttachment( tgt_entity ) )
					return true;
			}		
		}

		return false;
	}

	override void OnExecuteServer( ActionData action_data )
	{
		if ( GetGame().IsMultiplayer() )
			return;

		ActionManagerClient am = ActionManagerClient.Cast(action_data.m_Player.GetActionManager());
		am.UnlockInventory(action_data);

		EntityAI ntarget = EntityAI.Cast(action_data.m_Target.GetObject());
		action_data.m_Player.PredictiveTakeEntityToHands(ntarget);

	}
	
	override void OnExecuteClient( ActionData action_data )
	{
		ActionManagerClient am = ActionManagerClient.Cast(action_data.m_Player.GetActionManager());
		am.UnlockInventory(action_data);

		EntityAI ntarget = EntityAI.Cast(action_data.m_Target.GetObject());
		action_data.m_Player.PredictiveTakeEntityToHands(ntarget);
	}
	
	override void CreateAndSetupActionCallback( ActionData action_data )
	{
		EntityAI target = EntityAI.Cast(action_data.m_Target.GetObject());
		ActionBaseCB callback;
		if (!target)
			return;
		
		if (target.IsHeavyBehaviour())
		{
			Class.CastTo(callback, action_data.m_Player.StartCommand_Action(DayZPlayerConstants.CMD_ACTIONFB_PICKUP_HEAVY,GetCallbackClassTypename(),DayZPlayerConstants.STANCEMASK_ERECT));
		}
		else
		{
			if( action_data.m_Player.IsPlayerInStance(DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT) )
			{
				Class.CastTo(callback, action_data.m_Player.AddCommandModifier_Action(DayZPlayerConstants.CMD_ACTIONMOD_PICKUP_HANDS,GetCallbackClassTypename()));
			}
			else
			{
				Class.CastTo(callback, action_data.m_Player.StartCommand_Action(DayZPlayerConstants.CMD_ACTIONFB_PICKUP_HANDS,GetCallbackClassTypename(),DayZPlayerConstants.STANCEMASK_PRONE));
			}
		}
		callback.SetActionData(action_data); 
		callback.InitActionComponent();
		action_data.m_Callback = callback;
	}
};
class ActionAttachToTongs: ActionSingleUseBase
{
	void ActionAttachToTongs()
	{
	}

	override void CreateConditionComponents() 
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTNonRuined( UAMaxDistances.DEFAULT );
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_ATTACHITEM;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
	}
		
	override string GetText()
	{
		return "#attach";
	}
	
	override ActionData CreateActionData()
	{
		AttachActionData action_data = new AttachActionData;
		return action_data;
	}
	
	override bool SetupAction(PlayerBase player, ActionTarget target, ItemBase item, out ActionData action_data, Param extra_data = NULL)
	{
		ref InventoryLocation il = new InventoryLocation;
		if (!GetGame().IsMultiplayer() || GetGame().IsClient())
		{
			EntityAI target_entity;
			
			if ( target.IsProxy() )
			{
				target_entity = EntityAI.Cast( target.GetParent() );
			}
			else
			{
				target_entity = EntityAI.Cast( target.GetObject() );
			}
			
			if(!target_entity.GetInventory().FindFreeLocationFor( item, FindInventoryLocationType.ATTACHMENT, il ))
				return false;
		}
			
		if ( super.SetupAction( player, target, item, action_data, extra_data))
		{
			if (!GetGame().IsMultiplayer() || GetGame().IsClient())
			{
				AttachActionData action_data_a = AttachActionData.Cast(action_data);
				action_data_a.m_AttSlot = il.GetSlot();
			}
			return true;
		}
		return false;
	}
	
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		EntityAI target_entity = EntityAI.Cast( target.GetObject() );
		
		if ( target_entity && item )
		{
			if ( target_entity.GetInventory() && target_entity.GetInventory().CanAddAttachment( item ) )
			{
				return true;
			}
		}	
		return false;
	}

	override void OnExecuteServer( ActionData action_data )
	{
		if (GetGame().IsMultiplayer())
			return;
		
		AttachActionData action_data_a = AttachActionData.Cast(action_data);
		EntityAI target_EAI;
			
		if ( action_data.m_Target.IsProxy() )
		{
			target_EAI = EntityAI.Cast( action_data_a.m_Target.GetParent() ); // cast to ItemBase
		}
		else
		{
			target_EAI = EntityAI.Cast( action_data_a.m_Target.GetObject() ); // cast to ItemBase
		}
		
		if (target_EAI && action_data_a.m_MainItem)
		{
			action_data_a.m_Player.PredictiveTakeEntityToTargetAttachmentEx(target_EAI, action_data_a.m_MainItem,action_data_a.m_AttSlot);
		}
	}
	
	override void OnExecuteClient( ActionData action_data )
	{
		AttachActionData action_data_a = AttachActionData.Cast(action_data);
		
		EntityAI target_EAI;
			
		if ( action_data.m_Target.IsProxy() )
		{
			target_EAI = EntityAI.Cast( action_data_a.m_Target.GetParent() ); // cast to ItemBase
		}
		else
		{
			target_EAI = EntityAI.Cast( action_data_a.m_Target.GetObject() ); // cast to ItemBase
		}
		
		if (target_EAI && action_data_a.m_MainItem)
		{
			action_data_a.m_Player.PredictiveTakeEntityToTargetAttachmentEx(target_EAI, action_data_a.m_MainItem, action_data_a.m_AttSlot);
		}
	}
};