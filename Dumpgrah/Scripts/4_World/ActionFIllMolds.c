class ActionEmptyCrucibleeCB1 : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime( 5 ); // Dont forget to change back to 30
	}
};
class ActionEmptyCrucibleeCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime( 15 ); // Dont forget to change back to 30
	}
};
class ActionFillMoldCB : ActionContinuousBaseCB
{
	float TimeToCast = GetForgingSettings().CastMetalTime;
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime( TimeToCast ); // Dont forget to change back to 30
	}
}
class ActionEmptyCrucibleinhands: ActionContinuousBase
{
	void ActionEmptyCrucibleinhands()
	{
		m_CallbackClass = ActionEmptyCrucibleeCB1;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_EMPTY_VESSEL;
		m_CommandUIDProne = DayZPlayerConstants.CMD_ACTIONFB_EMPTY_VESSEL;
		m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_LOW;
	}
	
	override void CreateConditionComponents()  
	{	
		m_ConditionTarget = new CCTNonRuined( UAMaxDistances.DEFAULT );
		m_ConditionItem = new CCINonRuined;
	}
		
	override string GetText()
	{
		
		
		return "Dump Metal";
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{	
		//ND_CrucibleBase Crucible = ND_CrucibleBase.Cast(player.GetItemInHands());
		//ND_Smelter Smelter = ND_Smelter.Cast(target.GetObject() );
		vector 	pos_cursor = target.GetCursorHitPos();
		vector 	pos_head;
		MiscGameplayFunctions.GetHeadBonePos( player, pos_head );
		float distance = vector.Distance(pos_cursor, pos_head);
			
		if ( GetGame().IsServer() && GetGame().IsMultiplayer() )
			return true;
		
		if (player.IsCurrentCameraAimedAtGround())
		{
			return true;
		}
		return false;
	}

	override void OnFinishProgressServer( ActionData action_data )
	{
		ND_CrucibleBase Crucible = ND_CrucibleBase.Cast( action_data.m_Target.GetObject() );
		PlayerBase target = PlayerBase.Cast(action_data.m_Player);
		ND_Smelter NDSmelter = ND_Smelter.Cast( action_data.m_Target.GetObject() );
		action_data.m_MainItem.Open();

	}
};
class ActionEmptyCrucible: ActionContinuousBase
{
	void ActionEmptyCrucible()
	{
		m_CallbackClass = ActionEmptyCrucibleeCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_EMPTY_VESSEL;
		m_CommandUIDProne = DayZPlayerConstants.CMD_ACTIONFB_EMPTY_VESSEL;
		m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_LOW;
	}
	
	override void CreateConditionComponents()  
	{	
		m_ConditionTarget = new CCTNonRuined( UAMaxDistances.DEFAULT );
		m_ConditionItem = new CCINonRuined;
	}
		
	override string GetText()
	{
		
		
		return "Dump Metal";
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{	
		ND_CrucibleBase Crucible = ND_CrucibleBase.Cast(player.GetItemInHands());
		ND_Smelter Smelter = ND_Smelter.Cast(target.GetObject() );
		vector 	pos_cursor = target.GetCursorHitPos();
		vector 	pos_head;
		MiscGameplayFunctions.GetHeadBonePos( player, pos_head );
		float distance = vector.Distance(pos_cursor, pos_head);
			
		
		if ( Crucible && Smelter)
		{
			return true;
		}
		return false;
	}

	override void OnFinishProgressServer( ActionData action_data )
	{
		ND_CrucibleBase Crucible = ND_CrucibleBase.Cast( action_data.m_Target.GetObject() );
		PlayerBase target = PlayerBase.Cast(action_data.m_Player);
		ND_Smelter NDSmelter = ND_Smelter.Cast( action_data.m_Target.GetObject() );
		if(NDSmelter)
		{
			action_data.m_MainItem.Open();
			
		}
	}
}
class ActionFillIngotMold: ActionContinuousBase
{
	float MoltenMetalConsumed = GetForgingSettings().PourIronIngot;
	
	void ActionFillIngotMold()
	{
		m_CallbackClass = ActionFillMoldCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_EMPTY_VESSEL;
		m_CommandUIDProne = DayZPlayerConstants.CMD_ACTIONFB_EMPTY_VESSEL;
		m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_LOW;
	}
	
	override void CreateConditionComponents()  
	{	
		m_ConditionTarget = new CCTNonRuined( UAMaxDistances.DEFAULT );
		m_ConditionItem = new CCINonRuined;
	}
		
	override string GetText()
	{
		return "Cast Metal Ingot";
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{	
		float MoltenMetalTemp = GetForgingSettings().TempToPourMetal;
		ND_CrucibleBase Crucible = ND_CrucibleBase.Cast(player.GetItemInHands());
		EntityAI target_entity = EntityAI.Cast( target.GetObject() );
		ND_IngotMold Mold = ND_IngotMold.Cast(target.GetObject() );
		
		if ( Mold && !target_entity.FindAttachmentBySlotName("IngotCastMetal") &&  Crucible.GetTemperature() >= MoltenMetalTemp && Crucible.GetQuantity() >= MoltenMetalConsumed  )
		{
			return true;
		}
		
		return false;
	}

	override void OnFinishProgressServer( ActionData action_data )
	{
		ND_IngotMold IngotMold = ND_IngotMold.Cast( action_data.m_Target.GetObject() );
		//ND_CrucibleMoltenPigIron Crucible = ND_CrucibleMoltenPigIron.Cast( action_data.m_Target.GetObject() );
		ND_CrucibleMoltenPigIron CastIron = ND_CrucibleMoltenPigIron.Cast(action_data.m_MainItem);
		ND_CrucibleMoltenImpureIron ImpureIron = ND_CrucibleMoltenImpureIron.Cast(action_data.m_MainItem);
		ND_CrucibleMoltenIron Iron = ND_CrucibleMoltenIron.Cast(action_data.m_MainItem);
		PlayerBase target = PlayerBase.Cast(action_data.m_Player);
		
		if(IngotMold && action_data.m_MainItem.IsKindOf("ND_CrucibleMoltenPigIron")    || action_data.m_MainItem.IsKindOf("ND_ClayCrucibleMoltenPigIron") )
		{
			IngotMold.CreateCastIngot();
			MinusQuantity( action_data.m_MainItem, target );
		}
		if(IngotMold && action_data.m_MainItem.IsKindOf("ND_CrucibleMoltenImpureIron") || action_data.m_MainItem.IsKindOf("ND_ClayCrucibleMoltenImpureIron")  )
		{
			IngotMold.CreateImpureIngot();
			MinusQuantity( action_data.m_MainItem, target );
		}
		if(IngotMold && action_data.m_MainItem.IsKindOf("ND_CrucibleMoltenIron")       || action_data.m_MainItem.IsKindOf("ND_ClayCrucibleMoltenIron")  )
		{
			IngotMold.CreatePureIngot();
			MinusQuantity( action_data.m_MainItem, target );
		}
	}
	void MinusQuantity( ItemBase item, PlayerBase player )
	{
		item.AddQuantity(-MoltenMetalConsumed,false);// some reason repeats the -# twice no clue.
	}
}
class ActionFillNuggetMold: ActionContinuousBase
{
	float MoltenMetalConsumed = GetForgingSettings().PourIronNugget;
	
	
	void ActionFillNuggetMold()
	{
		m_CallbackClass = ActionFillMoldCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_EMPTY_VESSEL;
		m_CommandUIDProne = DayZPlayerConstants.CMD_ACTIONFB_EMPTY_VESSEL;
		m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_LOW;
	}
	
	override void CreateConditionComponents()  
	{	
		m_ConditionTarget = new CCTNonRuined( UAMaxDistances.DEFAULT );
		m_ConditionItem = new CCINonRuined;
	}
		
	override string GetText()
	{
		return "Cast Metal Nugget";
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{	
		float MoltenMetalTemp = GetForgingSettings().TempToPourMetal;
		ND_CrucibleBase Crucible = ND_CrucibleBase.Cast(player.GetItemInHands());
		EntityAI target_entity = EntityAI.Cast( target.GetObject() );
		ND_NuggetMold Mold = ND_NuggetMold.Cast(target.GetObject() );
		
		if ( Mold && !target_entity.FindAttachmentBySlotName("NuggetCastMetal") &&  Crucible.GetTemperature() >= MoltenMetalTemp && Crucible.GetQuantity() >= MoltenMetalConsumed )
		{
			return true;
		}
		
		return false;
	}

	override void OnFinishProgressServer( ActionData action_data )
	{
		ND_NuggetMold NuggetMold = ND_NuggetMold.Cast( action_data.m_Target.GetObject() );
		//ND_CrucibleMoltenPigIron Crucible = ND_CrucibleMoltenPigIron.Cast( action_data.m_Target.GetObject() );
		ND_CrucibleMoltenPigIron CastIron = ND_CrucibleMoltenPigIron.Cast(action_data.m_MainItem);
		ND_CrucibleMoltenImpureIron ImpureIron = action_data.m_MainItem;
		ND_CrucibleMoltenIron Iron = ND_CrucibleMoltenIron.Cast(action_data.m_MainItem);
		PlayerBase target = PlayerBase.Cast(action_data.m_Player);
		
		if(NuggetMold && action_data.m_MainItem.IsKindOf("ND_CrucibleMoltenPigIron") || action_data.m_MainItem.IsKindOf("ND_ClayCrucibleMoltenPigIron") )
		{
			NuggetMold.CreateCastNugget();
			MinusQuantity( action_data.m_MainItem, target );
		}
		if(NuggetMold && action_data.m_MainItem.IsKindOf("ND_CrucibleMoltenImpureIron") || action_data.m_MainItem.IsKindOf("ND_ClayCrucibleMoltenImpureIron") )
		{
			NuggetMold.CreateImpureNugget();
			MinusQuantity( action_data.m_MainItem, target );
		}
		if(NuggetMold && action_data.m_MainItem.IsKindOf("ND_CrucibleMoltenIron") || action_data.m_MainItem.IsKindOf("ND_ClayCrucibleMoltenIron") )
		{
			NuggetMold.CreatePureNugget();
			MinusQuantity( action_data.m_MainItem, target );
		}
	}
	void MinusQuantity( ItemBase item, PlayerBase player )
	{
		item.AddQuantity(-MoltenMetalConsumed,false);// some reason repeats the -# twice no clue.
		//item.Open()
	}
};
class ActionFillBarMold: ActionContinuousBase
{
	float MoltenMetalConsumed = GetForgingSettings().PourIronBars;
	
	void ActionFillBarMold()
	{
		m_CallbackClass = ActionFillMoldCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_EMPTY_VESSEL;
		m_CommandUIDProne = DayZPlayerConstants.CMD_ACTIONFB_EMPTY_VESSEL;
		m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_LOW;
	}
	
	override void CreateConditionComponents()  
	{	
		m_ConditionTarget = new CCTNonRuined( UAMaxDistances.DEFAULT );
		m_ConditionItem = new CCINonRuined;
	}
		
	override string GetText()
	{
		return "Cast Metal Bar";
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{	
		float MoltenMetalTemp = GetForgingSettings().TempToPourMetal;
		ND_CrucibleBase Crucible = ND_CrucibleBase.Cast(player.GetItemInHands());
		EntityAI target_entity = EntityAI.Cast( target.GetObject() );
		ND_BarMold Mold = ND_BarMold.Cast(target.GetObject() );
		
		if ( Mold && !target_entity.FindAttachmentBySlotName("BarCastMetal") &&  Crucible.GetTemperature() >= MoltenMetalTemp && Crucible.GetQuantity() >= MoltenMetalConsumed)
		{
			return true;
		}
		
		return false;
	}

	override void OnFinishProgressServer( ActionData action_data )
	{
		ND_BarMold BarMold = ND_BarMold.Cast( action_data.m_Target.GetObject() );
		//ND_CrucibleMoltenPigIron Crucible = ND_CrucibleMoltenPigIron.Cast( action_data.m_Target.GetObject() );
		ND_CrucibleMoltenPigIron CastIron = ND_CrucibleMoltenPigIron.Cast(action_data.m_MainItem);
		ND_CrucibleMoltenImpureIron ImpureIron = action_data.m_MainItem;
		ND_CrucibleMoltenIron Iron = ND_CrucibleMoltenIron.Cast(action_data.m_MainItem);
		PlayerBase target = PlayerBase.Cast(action_data.m_Player);
		
		if(BarMold && action_data.m_MainItem.IsKindOf("ND_CrucibleMoltenPigIron") || action_data.m_MainItem.IsKindOf("ND_ClayCrucibleMoltenPigIron")  )
		{
			BarMold.CreateCastBar();
			MinusQuantity( action_data.m_MainItem, target );
		}
		if(BarMold && action_data.m_MainItem.IsKindOf("ND_CrucibleMoltenImpureIron") || action_data.m_MainItem.IsKindOf("ND_ClayCrucibleMoltenImpureIron") )
		{
			BarMold.CreateImpureBar();
			MinusQuantity( action_data.m_MainItem, target );
		}
		if(BarMold && action_data.m_MainItem.IsKindOf("ND_CrucibleMoltenIron") || action_data.m_MainItem.IsKindOf("ND_ClayCrucibleMoltenIron") )
		{
			BarMold.CreatePureBar();
			MinusQuantity( action_data.m_MainItem, target );
		}
	}
	void MinusQuantity( ItemBase item, PlayerBase player )
	{
		item.AddQuantity(-MoltenMetalConsumed,false);// some reason repeats the -# twice no clue.
		//item.Open()
	}
}
class ActionFillAnvilMold: ActionContinuousBase
{
	float MoltenMetalConsumed = GetForgingSettings().PourAnvilMetal;
	
	void ActionFillAnvilMold()
	{
		m_CallbackClass = ActionFillMoldCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_EMPTY_VESSEL;
		m_CommandUIDProne = DayZPlayerConstants.CMD_ACTIONFB_EMPTY_VESSEL;
		m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_LOW;
	}
	
	override void CreateConditionComponents()  
	{	
		m_ConditionTarget = new CCTNonRuined( UAMaxDistances.DEFAULT );
		m_ConditionItem = new CCINonRuined;
	}
		
	override string GetText()
	{
		return "Cast Anvil";
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		float MoltenMetalTemp = GetForgingSettings().TempToPourMetal;
		
		ND_CrucibleBase Crucible = ND_CrucibleBase.Cast(player.GetItemInHands());
		EntityAI target_entity = EntityAI.Cast( target.GetObject() );
		ND_MSAMold Mold = ND_MSAMold.Cast(target.GetObject() );
		
		if ( Mold && !target_entity.FindAttachmentBySlotName("CastMetal") &&  Crucible.GetTemperature() >= MoltenMetalTemp && Crucible.GetQuantity() >= MoltenMetalConsumed )
		{
			return true;
		}
		
		return false;
	}

	override void OnFinishProgressServer( ActionData action_data )
	{
		
		ND_MSAMold AnvilMold = ND_MSAMold.Cast( action_data.m_Target.GetObject() );
		//ND_CrucibleMoltenPigIron Crucible = ND_CrucibleMoltenPigIron.Cast( action_data.m_Target.GetObject() );
		ND_CrucibleMoltenPigIron CastIron = ND_CrucibleMoltenPigIron.Cast(action_data.m_MainItem);
		ND_CrucibleMoltenImpureIron ImpureIron = action_data.m_MainItem;
		ND_CrucibleMoltenIron Iron = ND_CrucibleMoltenIron.Cast(action_data.m_MainItem);
		PlayerBase target = PlayerBase.Cast(action_data.m_Player);
		
		if(AnvilMold && action_data.m_MainItem.IsKindOf("ND_CrucibleMoltenPigIron") || action_data.m_MainItem.IsKindOf("ND_ClayCrucibleMoltenPigIron")  )
		{
			AnvilMold.CreateCastAnvil();
			MinusQuantity( action_data.m_MainItem, target );
		}
		if(AnvilMold && action_data.m_MainItem.IsKindOf("ND_CrucibleMoltenImpureIron") || action_data.m_MainItem.IsKindOf("ND_ClayCrucibleMoltenImpureIron") )
		{
			AnvilMold.CreateImpureAnvil();
			MinusQuantity( action_data.m_MainItem, target );
		}
		if(AnvilMold && action_data.m_MainItem.IsKindOf("ND_CrucibleMoltenIron") || action_data.m_MainItem.IsKindOf("ND_ClayCrucibleMoltenIron") )
		{
			AnvilMold.CreatePureAnvil();
			MinusQuantity( action_data.m_MainItem, target );
		}
	}
	void MinusQuantity( ItemBase item, PlayerBase player )
	{
		item.AddQuantity(-MoltenMetalConsumed,false);// some reason repeats the -# twice no clue.
		//item.Open()
	}
}