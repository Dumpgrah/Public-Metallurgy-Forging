modded class PluginRecipesManager 
{

 	override void RegisterRecipies()
	{
		super.RegisterRecipies();
		//RegisterRecipe(new ExtinguishForgeOrSmelter);
		//Weapons
		RegisterRecipe(new MakeDagger);
		//Pure Iron Tools
		RegisterRecipe(new MakePureIronShovel);
		RegisterRecipe(new MakePureIronPickaxe);
		RegisterRecipe(new MakePureIronHatchet);
		RegisterRecipe(new MakePureIronHammer);
		RegisterRecipe(new MakePureIronAxe);
		//Impure Iron tools
		RegisterRecipe(new MakeImpureIronShovel);
		RegisterRecipe(new MakeImpureIronPickaxe);
		RegisterRecipe(new MakeImpureIronHatchet);
		RegisterRecipe(new MakeImpureIronHammer);
		RegisterRecipe(new MakeImpureIronAxe);
		//Cast iron tools
		RegisterRecipe(new MakeCastIronShovel);
		RegisterRecipe(new MakeCastIronPickaxe);
		RegisterRecipe(new MakeCastIronHammer);
		RegisterRecipe(new MakeCastIronAxe);
		// Daggers,Hilts,Molds,Crucibles
		RegisterRecipe(new MakeIncasedIngot);
		RegisterRecipe(new MakeCarveDaggerHilt);
		RegisterRecipe(new MakeCarveShortHandle);
		RegisterRecipe(new MakeCarveLongHandle);
		RegisterRecipe(new MakeAnvilMold);
		RegisterRecipe(new MakeNuggetMold);
		RegisterRecipe(new MakeBarMold);
		RegisterRecipe(new MakeIngotMold);
		//Forge & Smleter
		RegisterRecipe(new MakeForge);
		RegisterRecipe(new MakeForgeImproved);
		RegisterRecipe(new MakeSmelter);
		RegisterRecipe(new MakeSimpleSmelter);
		//Anvils
		RegisterRecipe(new MakeCastAnvil);
		RegisterRecipe(new MakeImpureAnvil);
		RegisterRecipe(new MakePureAnvil);
		//Make bricks and fill crucibles
		RegisterRecipe(new MakeIronCrucibleFill);
		RegisterRecipe(new MakeUnfiredBricks);
	    RegisterRecipe(new MakeIronCrucible);
		RegisterRecipe(new MakeClayIronCrucible);
		
	    RegisterRecipe(new MakePureIronCrucible);
		RegisterRecipe(new MakeAddPureIronCrucible);
		RegisterRecipe(new MakeClayPureIronCrucible);
	
		RegisterRecipe(new MakePTMClay);
		RegisterRecipe(new MakePCMClay);
		RegisterRecipe(new MakeRTMClay);
		RegisterRecipe(new MakeRCMClay);
		RegisterRecipe(new MakeUnfiredClayCrucible);
		
		// crafting recipes
		RegisterRecipe(new MakeStackedCoal);
		RegisterRecipe(new AddCoaltoStackedCoal);
		RegisterRecipe(new CrushCharcoal2);
		RegisterRecipe(new CrushCharcoal);
		RegisterRecipe(new CrushSulur);
		RegisterRecipe(new CrushSulur2);
		RegisterRecipe(new CrushBones);
		RegisterRecipe(new CrushBones2);
		RegisterRecipe(new MixCharcoalSulur);
		RegisterRecipe(new CreateGunpowderbyhand);
		RegisterRecipe(new MakeSplitWood);
		
		
		// Ammo Making Comptablity
		#ifdef AM_MOD_221
		RegisterRecipe(new MakeCopperCrucible);
		RegisterRecipe(new MakeClayCopperCrucible);
		RegisterRecipe(new FillCopperCrucible);
		RegisterRecipe(new FillClayCopperCrucible);
		
		RegisterRecipe(new MakeLeadCrucible);
		RegisterRecipe(new FillLeadCrucible);
		RegisterRecipe(new MakeClayLeadCrucible);
		RegisterRecipe(new FillClayLeadCrucible);
		
		RegisterRecipe(new MakeZincCrucible);
		RegisterRecipe(new FillZincCrucible);
		RegisterRecipe(new MakeClayZincCrucible);
		RegisterRecipe(new FillClayZincCrucible);
		
		RegisterRecipe(new MakeClayPistolTipsMold);
		RegisterRecipe(new MakeClayPistolCasingsMold);
		
		RegisterRecipe(new MakeClayRifleTipsMold);
		RegisterRecipe(new MakeClayRifleCasingsMold);
		
		RegisterRecipe(new MakeTipsClayCrucibleSmart);
		RegisterRecipe(new MakeCasingClayCrucibleSmart);
		
		#endif
    }
};

