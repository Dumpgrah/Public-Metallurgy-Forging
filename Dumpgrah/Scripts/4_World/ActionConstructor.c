modded class ActionConstructor 
{
    override void RegisterActions(TTypenameArray actions)
    {	
		super.RegisterActions(actions);
		actions.Insert(ActionEmptyCrucible101);
		
		actions.Insert(ActionReadBookForge);
		
		actions.Insert(ActionSplitLogRound);
		
		actions.Insert(ActionSmashMold);
		
		actions.Insert(ActionEmptyCrucible);
		
		actions.Insert(ActionEmptyCrucibleinhands);
		
		actions.Insert(ActionFillAnvilMold);
		
		actions.Insert(ActionFillIngotMold);
		
		actions.Insert(ActionFillBarMold);
		
		actions.Insert(ActionFillNuggetMold);
		
		actions.Insert(ActionLightSmelterFire);
		
		actions.Insert(ActionLightForgeFire);
		
		actions.Insert(ActionExtingushSmelterFire);
		
		actions.Insert(ActionExtingushForgeFire);
		
		actions.Insert(ActionSmashSmelter);  
		
		actions.Insert(ActionSmashImprovedSmelter);
		
		actions.Insert(ActionPourMoltenLiquid);
		
		actions.Insert(ActionTurnAroundHatchet);

		actions.Insert(ActionDetachToTongs);
		
		actions.Insert(ActionAttachToTongs);
		
		//actions.Insert(ActionExtingushSmelterFireWithWater);
		
		actions.Insert(ActionSmithingIngot);
		actions.Insert(ActionChangeSmithIngotAction);
		
		actions.Insert(ActionSmithingBar);
		actions.Insert(ActionChangeSmithBarAction);
		
		actions.Insert(ActionSmithingNugget);
		actions.Insert(ActionChangeSmithNuggetAction);
		
    };
};