modded class PluginRecipesManager 
{

 	override void RegisterRecipies()
	{
		super.RegisterRecipies();
		RegisterRecipe(new CraftCoalPick);
		RegisterRecipe(new CraftCoalHammer);
    }
};

