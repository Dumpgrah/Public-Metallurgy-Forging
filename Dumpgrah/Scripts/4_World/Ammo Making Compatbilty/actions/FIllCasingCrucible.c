#ifdef AM_MOD_221
modded class Action_AM_FillCasingCrucible: ActionSingleUseBase
{
	string TendancyText = "";
	
	void Action_AM_FillCasingCrucible()
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
		AM_CasingBase Casing = AM_CasingBase.Cast(player.GetItemInHands());
		CrucibleFilledCasing CrucibleCasing = CrucibleFilledCasing.Cast( target_object );
		ND_ClayCrucibleFilledCasing ClayCrucibleCasing = ND_ClayCrucibleFilledCasing.Cast( target_object );
		
		if (Casing && CrucibleCasing && CrucibleCasing.GetQuantity() <= 99 )
		{
			TendancyText = Casing.GetAmmoPartTendancyText();
			
			return true;
		}
		else if (Casing && ClayCrucibleCasing && ClayCrucibleCasing.GetQuantity() <= 49 )
		{
			TendancyText = Casing.GetAmmoPartTendancyText();
			
			return true;
		};
		return false;
	};

	override void OnExecuteServer( ActionData action_data )
	{
        AM_CasingBase Casing = AM_CasingBase.Cast(action_data.m_MainItem);
		 
		CrucibleFilledCasing CrucibleCasing = CrucibleFilledCasing.Cast( action_data.m_Target.GetObject() );
		ND_ClayCrucibleFilledCasing ClayCrucibleCasing = ND_ClayCrucibleFilledCasing.Cast( action_data.m_Target.GetObject() );
		
		float FillAmount = Casing.MathAddtion();
		float ReduceAmount = Casing.ReduceQuantity();
		
        if (CrucibleCasing || ClayCrucibleCasing)
		{
            if(Casing)
			{
				CrucibleCasing.AddQuantity(FillAmount);
				Casing.AddQuantity(-ReduceAmount);
				
				ClayCrucibleCasing.AddQuantity(FillAmount);
			};
        };	
	};
	override void OnExecuteClient( ActionData action_data )
	{
        AM_CasingBase Casing = AM_CasingBase.Cast(action_data.m_MainItem);
		 
		CrucibleFilledCasing CrucibleCasing = CrucibleFilledCasing.Cast( action_data.m_Target.GetObject() );
		ND_ClayCrucibleFilledCasing ClayCrucibleCasing = ND_ClayCrucibleFilledCasing.Cast( action_data.m_Target.GetObject() );
		
		float FillAmount = Casing.MathAddtion();
		float ReduceAmount = Casing.ReduceQuantity();
		
        if (CrucibleCasing || ClayCrucibleCasing)
		{
            if(Casing)
			{
				CrucibleCasing.AddQuantity(FillAmount);
				Casing.AddQuantity(-ReduceAmount);
				
				ClayCrucibleCasing.AddQuantity(FillAmount);
			};
        };
	};
};
#endif