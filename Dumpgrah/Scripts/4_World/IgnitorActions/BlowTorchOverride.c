modded class Matchbox
{
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionLightItemOnFire);
		AddAction(ActionLightForgeFire);
		AddAction(ActionLightSmelterFire);
	}
}
modded class FireExtinguisher: Inventory_Base
{
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionClapBearTrapWithThisItem);
		AddAction(ActionExtinguishFireplaceByExtinguisher);
		AddAction(ActionExtingushForgeFire);
		AddAction(ActionExtingushSmelterFire);
	}
};