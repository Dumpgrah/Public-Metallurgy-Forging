class CfgPatches
{
    class ND_Still
    {
        units[] =
		{
			""
		};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] = 
		{
			"DZ_Data",
			"DZ_Gear_Camping",
			"DZ_Gear_Tools"
		};
    };
};
class CfgVehicles
{	
	class Inventory_Base;
	class Nail;
	class Firewood;
	class Pickaxe;
	class HuntingKnife;
	class Pot;
	class ND_Still : Inventory_Base
	{
		scope=2;
		displayName = "Still";
		descriptionShort = "Testing";
		model = "\Dumpgrah\Assets\Stills\Still.p3d";
		itemSize[] = { 1,4 };
		physLayer = "item_large";
		itemBehaviour = 2;
		heavyItem=1;
		carveNavmesh=0;
	};
};

