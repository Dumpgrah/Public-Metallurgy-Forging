#ifdef AM_MOD_221
modded class Action_AM_FillTipsCrucible: ActionSingleUseBase
{
	string TendancyText = "";
	
	void Action_AM_FillTipsCrucible()
	{
		m_CommandUID        = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
		m_StanceMask        = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
	};
	

	override string GetText()
	{
		return "Fill Crucible with" + TendancyText;
	};

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Object target_object = target.GetObject();
		EntityAI target_entity = EntityAI.Cast( target.GetObject() );
		AM_TipsBase Tips = AM_TipsBase.Cast(player.GetItemInHands());
		CrucibleFilledTips CrucibleTips = CrucibleFilledTips.Cast( target_object );
		ND_ClayCrucibleFilledTips ClayCrucibleTips = ND_ClayCrucibleFilledTips.Cast( target_object );
		
		if (Tips && CrucibleTips && CrucibleTips.GetQuantity() <= 99 )
		{
			TendancyText = Tips.GetAmmoPartTendancyText();
			
			return true;
		}
		else if (Tips && ClayCrucibleTips && ClayCrucibleTips.GetQuantity() <= 49 )
		{
			TendancyText = Tips.GetAmmoPartTendancyText();
			
			return true;
		};
		return false;
	};

	override void OnExecuteServer( ActionData action_data )
	{
        AM_TipsBase Tips = AM_TipsBase.Cast(action_data.m_MainItem);
		
		 
		CrucibleFilledTips CrucibleTips = CrucibleFilledTips.Cast( action_data.m_Target.GetObject() );
		ND_ClayCrucibleFilledTips ClayCrucibleTips = ND_ClayCrucibleFilledTips.Cast( action_data.m_Target.GetObject() );
		
		float FillAmount = Tips.MathAddtion();
		float ReduceAmount = Tips.ReduceQuantity();
		
        if (CrucibleTips || ClayCrucibleTips)
		{
            if(Tips)
			{
				CrucibleTips.AddQuantity(FillAmount);
				Tips.AddQuantity(-ReduceAmount);
				
				ClayCrucibleTips.AddQuantity(FillAmount);
			};
        };	
	};
	override void OnExecuteClient( ActionData action_data )
	{
        AM_TipsBase Tips = AM_TipsBase.Cast(action_data.m_MainItem);
		
		 
		CrucibleFilledTips CrucibleTips = CrucibleFilledTips.Cast( action_data.m_Target.GetObject() );
		ND_ClayCrucibleFilledTips ClayCrucibleTips = ND_ClayCrucibleFilledTips.Cast( action_data.m_Target.GetObject() );
		
		float FillAmount = Tips.MathAddtion();
		float ReduceAmount = Tips.ReduceQuantity();
		
        if (CrucibleTips || ClayCrucibleTips)
		{
            if(Tips)
			{
				CrucibleTips.AddQuantity(FillAmount);
				Tips.AddQuantity(-ReduceAmount);
				
				ClayCrucibleTips.AddQuantity(FillAmount);
			};
        };	
	};
};
#endif