class ActionPourMoltenLiquidCB : ActionContinuousBaseCB
{
	private const float TIME_TO_REPEAT = 0.25;
	
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousQuantityLiquidTransfer(UAQuantityConsumed.DRAIN_LIQUID, TIME_TO_REPEAT, TransferLiquidActionData.Cast(m_ActionData).m_Tendency);
	}

};

class ActionPourMoltenLiquid: ActionContinuousBase
{
	void ActionPourMoltenLiquid()
	{
		m_CallbackClass = ActionPourMoltenLiquidCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_EMPTY_VESSEL;
		m_CommandUIDProne = DayZPlayerConstants.CMD_ACTIONMOD_EMPTY_VESSEL;
		m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_LOW;
	}
	
	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTNonRuined(UAMaxDistances.DEFAULT);
	}
	
	override bool HasProneException()
	{
		return true;
	}
	
	override string GetText()
	{		
		return "pour molten metal";
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{	
		Object target_object = target.GetObject();
		string selection = target_object.GetActionComponentName( target.GetComponentIndex() );
		ND_CrucibleMoltenCopper Copper = ND_CrucibleMoltenCopper.Cast( target_object );
		//CrucibleMoltenBrass Brass = CrucibleMoltenBrass.Cast( target_object);
		if (Copper)
		{
			return true;
		}
		return false;
		ItemBase target_item = ItemBase.Cast(target.GetObject());
		if ( target_item && item && GetGame().IsServer() && GetGame().IsMultiplayer() )
			return true;
		
		if ( GetGame().IsInventoryOpen() && !player.GetLiquidTendencyDrain() )
		{
			player.SetLiquidTendencyDrain(true);
			return false;
		}
		
		if ( target_item && item && item.GetQuantity() > item.GetQuantityMin() && target_item.GetQuantity() < target_item.GetQuantityMax() && !player.GetLiquidTendencyDrain() && Liquid.CanFillContainer( target_item, item.GetLiquidType() ) && target_item.IsOpen() )
		{
			return true;
		}
		return false;
	}
	override void OnStartServer( ActionData action_data )
	{
		action_data.m_Player.SetLiquidTendencyDrain(false);
	}
	
	override void OnEndServer( ActionData action_data )
	{		
		action_data.m_Player.GetSoftSkillsManager().AddSpecialty( m_SpecialtyWeight );
	}
};