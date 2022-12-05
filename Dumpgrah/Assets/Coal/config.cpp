class CfgPatches
{
    class ND_Fireplace
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
			"DZ_Gear_Tools",
			"DZ_Weapons_Melee",
			"DZ_Weapons_Melee_Blade"
		};
    };
};

class CfgSlots
{

    class Slot_ND_Coal
    {
        name="ND_Coal";
        displayName="ND_Coal";
		ghostIcon="set:ForgingIcons image:CoalFuel";
    };
    class Slot_CrucibleInput
    {
        name="CrucibleInput";
        displayName="CrucibleInput";
		ghostIcon="set:ForgingIcons image:OreCrucible";
    };
    class Slot_CrucibleInput1
    {
        name="CrucibleInput1";
        displayName="CrucibleInput1";
		ghostIcon="set:ForgingIcons image:OreCrucible";
    };
    class Slot_CrucibleOutput
    {
        name="CrucibleOutput";
        displayName="CrucibleOutput";
		
    };
	class Slot_CrucibleEmpty
	{
		name="CrucibleEmpty";
        displayName="CrucibleEmpty";
		ghostIcon="set:ForgingIcons image:EmptyCrucible";
    };
	class Slot_ForgeMetal
	{
		name ="ForgeMetal";
		displayName="ForgeMetal";
		ghostIcon="set:ForgingIcons image:Ingot";
	};
	class Slot_ForgeMetalOne
	{
		name ="ForgeMetalOne";
		displayName="ForgeMetal";
		ghostIcon="set:ForgingIcons image:Metal";
	};
	class Slot_ND_Forge_Coal
    {
        name="ND_Forge_Coal";
        displayName="ND_Forge_Coal";
		ghostIcon="set:ForgingIcons image:CoalFuel";
    };
	class Slot_Hardie_Hole
	{
		name="Hardie_Hole";
		displayName="Hardie_Hole";
	};
	class Slot_Pritchel_Hole
	{
		name="Pritchel_Hole";
		displayName="Pritchel_Hole";
	};
	class Slot_Wedges
	{
		name="Wedges";
		displayName="Wedges";
		ghostIcon="set:ForgingIcons image:Wedges";
	};
	class Slot_Anvil_Stand
	{
		name="Anvil_Stand";
		displayName="Anvil_Stand";
		ghostIcon="set:ForgingIcons image:Stump";
	};
	class Slot_Tongs_Parts
	{
		name="TongsPart";
		displayName="TongsPart";
	};
	class Slot_IngotCastMetal
	{
		name="IngotCastMetal";
		displayName="IngotCastMetal";
	};
	class Slot_BarCastMetald
	{
		name="BarCastMetal";
		displayName="BarCastMetal";
	};
	class Slot_NuggetCastMetal
	{
		name="NuggetCastMetal";
		displayName="NuggetCastMetal";
	};
	class Slot_AnvilCastMetall
	{
		name="AnvilCastMetal";
		displayName="AnvilCastMetal";
	};
};
class CfgNonAIVehicles
{
	class ProxyAttachment;
	class ProxyCastIronMakeShiftAnvil : ProxyAttachment
	{
		scope = 2;
		InventorySlot="AnvilCastMetal";
		model="\Dumpgrah\Assets\Furance_colorbase\Forge\CastIronMakeShiftAnvil.p3d";
	};
	class ProxyWedges : ProxyAttachment
	{
		scope = 2;
		InventorySlot="Wedges";
		model="";
	};
	class ProxySplittingWedge : ProxyAttachment
	{
		scope = 2;
		InventorySlot="Hardie_Hole";
		model="\Dumpgrah\Assets\Furance_colorbase\Forge\SplittingWedge.p3d";
	};
	class ProxyManDrill : ProxyAttachment
	{
		scope = 2;
		InventorySlot="Pritchel_Hole";
		model="\Dumpgrah\Assets\Furance_colorbase\Forge\ManDrill.p3d";
	};
	class ProxyIngot : ProxyAttachment
	{
		scope = 2;
		InventorySlot="ForgeMetal";
		model="\Dumpgrah\Assets\Furance_colorbase\Forge\Ingot.p3d";
	};
	class ProxyIngotMoldMetal : ProxyAttachment
	{
		scope = 2;
		InventorySlot="IngotCastMetal";
		model="\Dumpgrah\Assets\Furance_colorbase\Forge\IngotMoldMetal.p3d";
	};
	class ProxyBarMoldMetal : ProxyAttachment
	{
		scope = 2;
		InventorySlot="BarCastMetal";
		model="\Dumpgrah\Assets\Furance_colorbase\Forge\BarMoldMetal.p3d";
	};
	class ProxyNugget : ProxyAttachment
	{
		scope = 2;
		InventorySlot="ForgeMetal";
		model="\Dumpgrah\Assets\Furance_colorbase\Forge\Nugget.p3d";
	};
	class ProxyNuggetMoldMetal : ProxyAttachment
	{
		scope = 2;
		InventorySlot="NuggetCastMetal";
		model="\Dumpgrah\Assets\Furance_colorbase\Forge\NuggetMoldMetal.p3d";
	};
	class ProxyCastIronAxeHead : ProxyAttachment
	{
		scope = 2;
		InventorySlot="ForgeMetalOne";
		model="\Dumpgrah\Assets\Furance_colorbase\Forge\CastIronAxeHead.p3d";
	};
	class Proxycoal : ProxyAttachment 
	{
		scope = 2;
		inventorySlot="ND_Coal";
		model="\Dumpgrah\Assets\Furance_colorbase\coal.p3d";
	};
	class ProxyStackedCoal : ProxyAttachment 
	{
		scope = 2;
		inventorySlot="ND_Coal";
		model="\Dumpgrah\Assets\Furance_colorbase\StackedCoal.p3d";
	};
	class ProxyCrucibleOreCopper : ProxyAttachment 
	{
		scope = 2;
		inventorySlot="CrucibleInput";
		model="\Dumpgrah\Assets\Furance_colorbase\CrucibleOreCopper.p3d";
	};
	class ProxyCrucibleOreZinc : ProxyAttachment 
	{
		scope = 2;
		inventorySlot="CrucibleInput";
		model="\Dumpgrah\Assets\Furance_colorbase\CrucibleOreZinc.p3d";
	};
	class ProxyCrucibleOreIron : ProxyAttachment 
	{
		scope = 2;
		inventorySlot="CrucibleInput";
		model="\Dumpgrah\Assets\Furance_colorbase\CrucibleOreIron.p3d";
	};
	class ProxyCrucibleOreLead : ProxyAttachment 
	{
		scope = 2;
		inventorySlot="CrucibleInput";
		model="\Dumpgrah\Assets\Furance_colorbase\CrucibleOreLead.p3d";
	};
	class ProxyMoltenCopper : ProxyAttachment 
	{
		scope = 2;
		inventorySlot="CrucibleOutput";
		model="\Dumpgrah\Assets\Furance_colorbase\MoltenCopper.p3d";
	};
	class ProxyNDTreeStump: ProxyAttachment
	{
		scope = 2;
		inventorySlot="Anvil_Stand";
		model="\Dumpgrah\Assets\Furance_colorbase\Forge\NDTreeStump.p3d";
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
	class Box_Base;
	class BookBase: Inventory_Base
	{
		scope=0;
		model="\DZ\gear\books\Book_kniga.p3d";
		rotationFlags=1;
		weight=150;
		itemSize[]={2,2};
		inventorySlot[]=
		{
			"OpenBook",
			"Book1",
			"Book2",
			"Book3",
			"Book4",
			"Book5",
			"Book6",
			"Book7",
			"Book8",
			"Book9",
			"Book10",
			"Book11",
			"Book12",
			"Book13",
			"Book14",
			"Book15",
			"Book16",
			"Book17",
			"Book18",
			"Book19",
			"Book20",
			"Book21",
			"Book22",
			"Book23",
			"Book24",
			"Book25",
			"Book26",
			"Book27",
			"Book28",
			"Book29",
			"Book30",
			"Book31",
			"Book32",
			"Book33",
			"Book34",
			"Book35",
			"Book36",
			"Book37",
			"Book38",
			"Book39",
			"Book40",
			"Book41",
			"Book42",
			"Book43",
			"Book44",
			"Book45",
			"Book46",
			"Book47",
			"Book48",
			"Book49",
			"Book50"
		};
		hiddenSelections[]=
		{
			"zbytek"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
				};
			};
		};
	};
	class Metallurgy_ForgingBook: BookBase
	{
		scope=2;
		displayName="Metallurgy Forging Guide";
		descriptionShort="A book that looks like it contains instructions on how to forge and meltdown and cast metal. might be worth look.";
		model="Dumpgrah\Assets\Coal\MetalurgyForgeBook.p3d";
		author="Unknown";
		title="Metallurgy Forging Guide";
		file="Dumpgrah\Bookbase\htmls\MetallurgyForging.html";
		itemSize[]={2,2};
	};
	class ClayPackage: Box_Base
	{
		scope=2;
		displayName="Clay Package";
		descriptionShort="The label says : Firebrick clay, useful for making kilns and hardened structures that can take a lot of heat, maybe I could use this?";
		model="Dumpgrah\Assets\Furance_colorbase\clayPackage\ClayPackage.p3d";
		weight=2540;
		absorbency=0.80000001;
		physLayer = "item_large";
		itemBehaviour = 0;
		heavyItem = 2;
		itemSize[]={2,3};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=80;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\gear\consumables\data\Box_of_Nails.rvmat"
							}
						},
						
						{
							0.6,
							
							{
								"DZ\gear\consumables\data\Box_of_Nails.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\consumables\data\Box_of_Nails_damage.rvmat"
							}
						},
						
						{
							0.3,
							
							{
								"DZ\gear\consumables\data\Box_of_Nails_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\consumables\data\Box_of_Nails_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class Resources
		{
			class ND_ClayLump
			{
				value=35;
				variable="quantity";
			};
		};
	};
	class ND_IronDaggerBlade : Inventory_Base
	{
		scope=2;
		displayName = "Iron Blade,Hilt,Pommel";
		descriptionShort = "A pure iron blade,hilt and pommel, i just now need a handle.";
		model = "\Dumpgrah\Assets\Furance_colorbase\Forge\DaggerBlade.p3d";
		itemSize[] = { 1,4 };
		inventorySlot[]={"ForgeMetalOne"};
	};
	class ND_IronDaggerHilt : Inventory_Base
	{
		scope=2;
		displayName = "Iron Blade,Hilt,Pommel";
		descriptionShort = "A pure iron blade,hilt and pommel, i just now need a handle.";
		model = "\Dumpgrah\Assets\Furance_colorbase\Forge\DaggerHandle.p3d";
		itemSize[] = { 1,2 };
	};
	class ND_MassIronDagger: HuntingKnife
	{
		scope=2;
		displayName="Iron Dagger";
		descriptionShort="A dagger made out of pure iron. 'I once had this blade like you but then i took an arrow to the knee' -Mass";
		model="Dumpgrah\Assets\Furance_colorbase\Forge\Dagger.p3d";
		inventorySlot[]=
		{
			"Knife"
		};
		repairableWithKits[]={4};
		repairCosts[]={20};
		rotationFlags=17;
		RestrainUnlockType=1;
		canSkinBodies=1;
		weight=200;
		itemSize[]={1,4};
		lootTag[]=
		{
			"Hunting",
			"Camping"
		};
		lootCategory="Tools";
		itemInfo[]=
		{
			"Knife"
		};
		openItemSpillRange[]={10,20};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"Dumpgrah\Assets\Furance_colorbase\Forge\Data\Dagger.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\weapons\melee\blade\data\Hunting_knife.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\weapons\melee\blade\data\Hunting_knife_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\weapons\melee\blade\data\Hunting_knife_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\weapons\melee\blade\data\Hunting_knife_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		isMeleeWeapon=1;
		suicideAnim="onehanded";
		class MeleeModes
		{
			class Default
			{
				ammo="MeleeKnife";
				range=1.4;
			};
			class Heavy
			{
				ammo="MeleeKnife_Heavy";
				range=1.6;
			};
			class Sprint
			{
				ammo="MeleeKnife_Heavy";
				range=3.3;
			};
		};
	};
	class Shovel: Inventory_Base
	{
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=200;
				};
			};
		};
	};
	class Hammer: Inventory_Base
	{
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
				};
			};
		};
	};
	class WoodAxe: Inventory_Base
	{
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=250;
				};
			};
		};
	};
	class Hatchet: Inventory_Base
	{
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=150;
				};
			};
		};
	};
	class Tripod;
	class ND_IngotBase : Inventory_Base{};
	class ND_CastIngot : ND_IngotBase
	{
		scope=2;
		displayName = "Cast Iron Ingot";
		descriptionShort = "Cast Iron Ingot this metal is quick brittle and altho looks to be strong it seems it doesnt hold its strength for long while in use. applications for tools shows it will break down quite fast other application might be used instead of tool making. ";
		model = "\Dumpgrah\Assets\Furance_colorbase\Forge\Ingot.p3d";
		varTemperatureMin=0;
		varTemperatureMax=1400;
		itemSize[] = { 2,4 };
		weight=3000;
		inventorySlot[]={"ForgeMetal","IngotCastMetal"};
		simpleHiddenSelections[] = {"IngotCold","IngotHot"};
		hiddenSelections[]=
		{
			"IngotCold",
			"IngotHot"
		};
		hiddenSelectionsTextures[]=
		{
			"\Dumpgrah\Assets\Furance_colorbase\Forge\Data\CastIron.paa"
		};
		hiddenSelectionsMaterials[]=
        {
        	"Dumpgrah\Assets\Furance_colorbase\Forge\Data\stonegroundNoGlowRedoneForMetal.rvmat"
        };
	};
	class ND_CastBar : Inventory_Base
	{
		scope=2;
		displayName = "Cast Iron Bar";
		descriptionShort = "Cast Iron Bar this metal is quick brittle and altho looks to be strong it seems it doesnt hold its strength for long while in use. applications for tools shows it will break down quite fast other application might be used instead of tool making.";
		model = "\Dumpgrah\Assets\Furance_colorbase\Forge\Bar.p3d";
		varTemperatureMin=0;
		varTemperatureMax=1400;
		varQuantityInit=10;
		varQuantityMin=0;
		varQuantityMax=10;
		canBeSplit=1;
		itemSize[] = { 2,3 };
		weight=1000;
		inventorySlot[]={"ForgeMetal","BarCastMetal"};
		simpleHiddenSelections[] = {"BarCold","BarHot"};
		hiddenSelections[]=
		{
			"BarCold",
			"BarHot"
		};
		hiddenSelectionsTextures[]=
		{
			"Dumpgrah\Assets\Furance_colorbase\Forge\Data\CastIron.paa"
		};
		hiddenSelectionsMaterials[]=
        {
        	"Dumpgrah\Assets\Furance_colorbase\Forge\Data\stonegroundNoGlowRedoneForMetal.rvmat"
        };
	};
	class ND_NuggetBase : Inventory_Base{};
	class ND_CastNugget : ND_NuggetBase
	{
		scope=2;
		displayName = "Cast Iron Nugget";
		descriptionShort = "Cast Iron Nugget this metal is quick brittle and altho looks to be strong it seems it doesnt hold its strength for long while in use. applications for tools shows it will break down quite fast other application might be used instead of tool making.";
		model = "\Dumpgrah\Assets\Furance_colorbase\Forge\Nugget.p3d";
		varTemperatureMin=0;
		varTemperatureMax=1400;
		itemSize[] = { 1,1 };
		varQuantityInit=20;
		varQuantityMin=0;
		varQuantityMax=20;
		canBeSplit=1;
		varQuantityDestroyOnMin=1;
		weight=100;
		inventorySlot[]={"ForgeMetal","NuggetCastMetal"};
		simpleHiddenSelections[] = {"NuggetCold","NuggetHot"};
		hiddenSelections[]=
		{
			"NuggetCold",
			"NuggetHot"
		};
		hiddenSelectionsTextures[]=
		{
			"Dumpgrah\Assets\Furance_colorbase\Forge\Data\CastIron.paa"
		};
		hiddenSelectionsMaterials[]=
        {
        	"Dumpgrah\Assets\Furance_colorbase\Forge\Data\stonegroundNoGlowRedoneForMetal.rvmat"
        };
	};
	class ND_ImPureIronIngot: ND_IngotBase
	{
		scope=2;
		displayName = "Impure Iron Ingot";
		descriptionShort = "Impure Iron Ingot. This metal seems to be fair higher in durability and strength when it comes to tool making and other uses. altho its not pure iron some impuritys are still in the metal, it definitly is an upgrade compared to cast iron for tools.";
		model = "\Dumpgrah\Assets\Furance_colorbase\Forge\Ingot.p3d";
		varTemperatureMin=0;
		varTemperatureMax=1650;
		itemSize[] = { 2,4 };
		weight=3000;
		inventorySlot[]={"ForgeMetal","IngotCastMetal"};
		simpleHiddenSelections[] = {"IngotCold","IngotHot"};
		hiddenSelections[]=
		{
			"IngotCold",
			"IngotHot"
		};
		hiddenSelectionsTextures[]=
		{
			"\Dumpgrah\Assets\Furance_colorbase\Forge\Data\Impure Iron.paa"
		};
		hiddenSelectionsMaterials[]=
        {
        	"Dumpgrah\Assets\Furance_colorbase\Forge\Data\stonegroundNoGlowRedoneForMetal.rvmat"
        };
	};
	class ND_ImPureIronBar: Inventory_Base
	{
		scope=2;
		displayName = "Impure Iron Bar";
		descriptionShort = " Impure Iron Bar. This metal seems to be fair higher in durability and strength when it comes to tool making and other uses. altho its not pure iron some impuritys are still in the metal, it definitly is an upgrade compared to cast iron for tools.";
		model = "\Dumpgrah\Assets\Furance_colorbase\Forge\Bar.p3d";
		varTemperatureMin=0;
		varTemperatureMax=1650;
		varQuantityInit=10;
		varQuantityMin=0;
		varQuantityMax=10;
		canBeSplit=1;
		itemSize[] = { 2,3 };
		weight=1000;
		inventorySlot[]={"ForgeMetal","BarCastMetal"};
		simpleHiddenSelections[] = {"BarCold","BarHot"};
		hiddenSelections[]=
		{
			"BarCold",
			"BarHot"
		};
		hiddenSelectionsTextures[]=
		{
			"Dumpgrah\Assets\Furance_colorbase\Forge\Data\Impure Iron.paa"
		};
		hiddenSelectionsMaterials[]=
        {
        	"Dumpgrah\Assets\Furance_colorbase\Forge\Data\stonegroundNoGlowRedoneForMetal.rvmat"
        };
	};
	class ND_ImPureIronNugget: ND_NuggetBase
	{
		scope=2;
		displayName = "Impure Iron Nugget";
		descriptionShort = "Impure Iron Nugget. This metal seems to be fair higher in durability and strength when it comes to tool making and other uses. altho its not pure iron some impuritys are still in the metal, it definitly is an upgrade compared to cast iron for tools.";
		model = "\Dumpgrah\Assets\Furance_colorbase\Forge\Nugget.p3d";
		varTemperatureMin=0;
		varTemperatureMax=1650;
		varQuantityInit=20;
		varQuantityMin=0;
		varQuantityMax=20;
		canBeSplit=1;
		varQuantityDestroyOnMin=1;
		itemSize[] = { 1,1 };
		weight=100;
		inventorySlot[]={"ForgeMetal","NuggetCastMetal"};
		simpleHiddenSelections[] = {"NuggetCold","NuggetHot"};
		hiddenSelections[]=
		{
			"NuggetCold",
			"NuggetHot"
		};
		hiddenSelectionsTextures[]=
		{
			"Dumpgrah\Assets\Furance_colorbase\Forge\Data\Impure Iron.paa"
		};
		hiddenSelectionsMaterials[]=
        {
        	"Dumpgrah\Assets\Furance_colorbase\Forge\Data\stonegroundNoGlowRedoneForMetal.rvmat"
        };
	};
	class ND_IronIngot : ND_IngotBase
	{
		scope=2;
		displayName = "Iron Ingot";
		descriptionShort = " Iron Ingot. This Metal has few flaws and is as pure as i can get it right now, it seems this is the best Iron i can make, maybe better metals can be made?. Its quite a bit stronger then Impure Iron and seems to be quite useful in tool making and holds its edge quite well.";
		model = "\Dumpgrah\Assets\Furance_colorbase\Forge\Ingot.p3d";
		varTemperatureMin=0;
		varTemperatureMax=1650;
		itemSize[] = { 2,4 };
		weight=3000;
		inventorySlot[]={"ForgeMetal","IngotCastMetal","CrucibleOutput"};
		simpleHiddenSelections[] = {"IngotCold","IngotHot"};
		hiddenSelections[]=
		{
			"IngotCold",
			"IngotHot"
		};
		hiddenSelectionsTextures[]=
		{
			"\Dumpgrah\Assets\Furance_colorbase\Forge\Data\PureIron.paa"
		};
		hiddenSelectionsMaterials[]=
        {
        	"Dumpgrah\Assets\Furance_colorbase\Forge\Data\stonegroundNoGlowRedoneForMetal.rvmat"
        };
	};
	class ND_IronBar : Inventory_Base
	{
		scope=2;
		displayName = "Iron Bar";
		descriptionShort = " Iron Bar. This Metal has few flaws and is as pure as i can get it right now, it seems this is the best Iron i can make, maybe better metals can be made. Its quite a bit stronger then Impure Iron and seems to be quite useful in tool making and holds its edge quite well. ";
		model = "\Dumpgrah\Assets\Furance_colorbase\Forge\Bar.p3d";
		varTemperatureMin=0;
		varTemperatureMax=1650;
		itemSize[] = { 2,3 };
		varQuantityInit=10;
		varQuantityMin=0;
		varQuantityMax=10;
		canBeSplit=1;
		varQuantityDestroyOnMin=1;
		weight=1000;
		inventorySlot[]={"ForgeMetal","BarCastMetal"};
		simpleHiddenSelections[] = {"BarCold","BarHot"};
		hiddenSelections[]=
		{
			"BarCold",
			"BarHot"
		};
		hiddenSelectionsTextures[]=
		{
			"Dumpgrah\Assets\Furance_colorbase\Forge\Data\PureIron.paa"
		};
		hiddenSelectionsMaterials[]=
        {
        	"Dumpgrah\Assets\Furance_colorbase\Forge\Data\stonegroundNoGlowRedoneForMetal.rvmat"
        };
	};
	class ND_IronNugget : ND_NuggetBase
	{
		scope=2;
		displayName = "Iron Nugget";
		descriptionShort = " Iron Nugget. This Metal has few flaws and is as pure as i can get it right now, it seems this is the best Iron i can make, maybe better metals can be made. Its quite a bit stronger then Impure Iron and seems to be quite useful in tool making and holds its edge quite well.";
		model = "\Dumpgrah\Assets\Furance_colorbase\Forge\Nugget.p3d";
		varTemperatureMin=0;
		varTemperatureMax=1650;
		canBeSplit=1;
		varQuantityInit=20;
		varQuantityMin=0;
		varQuantityMax=20;
		varQuantityDestroyOnMin=1;
		itemSize[] = { 1,1 };
		weight=100;
		inventorySlot[]={"ForgeMetal","NuggetCastMetal"};
		simpleHiddenSelections[] = {"NuggetCold","NuggetHot"};
		hiddenSelections[]=
		{
			"NuggetCold",
			"NuggetHot"
		};
		hiddenSelectionsTextures[]=
		{
			"Dumpgrah\Assets\Furance_colorbase\Forge\Data\PureIron.paa"
		};
		hiddenSelectionsMaterials[]=
        {
        	"Dumpgrah\Assets\Furance_colorbase\Forge\Data\stonegroundNoGlowRedoneForMetal.rvmat"
        };
	};
	class ND_IncasedIngot : Inventory_Base
	{
		scope=2;
		displayName = "Clay Incased Ingot";
		descriptionShort = "A impure ingot incased in clay.";
		model = "\Dumpgrah\Assets\Furance_colorbase\Forge\ClayIncaseIngot.p3d";
		itemSize[] = { 1,3 };
		inventorySlot[]={"CrucibleInput"};
		hitpoints=100;
	};
	class ND_IngotMold : Inventory_Base
	{
		scope=2;
		displayName = "Ingot Mold";
		descriptionShort = " Ingot Mold ";
		model = "\Dumpgrah\Assets\Furance_colorbase\Forge\IngotMold.p3d";
		itemSize[] = { 2,4 };
		inventorySlot[]={""};
		varTemperatureMin=0;
		varTemperatureMax=500;
		attachments[]=
		{
			"IngotCastMetal"
		};
		class GUIInventoryAttachmentsProps
		{

			class Cavity
			{
				name="Metal";
				description="";
				attachmentSlots[]=
				{
					"IngotCastMetal"
				};
			};
		};
		hitpoints=100;
	};
	class ND_BarMold : Inventory_Base
	{
		scope=2;
		displayName = "Bar Mold";
		descriptionShort = " Bar mold ";
		model = "\Dumpgrah\Assets\Furance_colorbase\Forge\BarMold.p3d";
		itemSize[] = { 2,2 };
		inventorySlot[]={""};
		attachments[]=
		{
			"BarCastMetal"
		};
		class GUIInventoryAttachmentsProps
		{

			class Cavity
			{
				name="Metal";
				description="";
				attachmentSlots[]=
				{
					"BarCastMetal"
				};
			};
		};
		hitpoints=100;
	};
	class ND_NuggetMold : Inventory_Base
	{
		scope=2;
		displayName = "Nugget Mold";
		descriptionShort = " Nugget mold ";
		model = "\Dumpgrah\Assets\Furance_colorbase\Forge\NuggetMold.p3d";
		itemSize[] = { 1,2 };
		inventorySlot[]={""};
		attachments[]=
		{
			"NuggetCastMetal"
		};
		class GUIInventoryAttachmentsProps
		{

			class Cavity
			{
				name="Metal";
				description="";
				attachmentSlots[]=
				{
					"NuggetCastMetal"
				};
			};
		};
		hitpoints=100;
	};	
	class ND_MSAMold : Inventory_Base
	{
		scope=2;
		displayName = "Make Shift Anvil Mold";
		descriptionShort = " Mold for casting Anvils, probly a one time use mold.";
		model = "\Dumpgrah\Assets\Furance_colorbase\Forge\MakeShiftAnvilMold.p3d";
		itemSize[] = { 6,6 };
		varQuantityInit=0;
		varQuantityMin=0;
		varQuantityMax=100;
		varQuantityDestroyOnMin=0;
		inventorySlot[]={""};
		simpleHiddenSelections[] = {"AnvilMoldClay","Broken Mold"};
		attachments[]=
		{
			"AnvilCastMetal"
		};
		class GUIInventoryAttachmentsProps
		{

			class Cavity
			{
				name="Anvil";
				description="";
				attachmentSlots[]=
				{
					"AnvilCastMetal"
				};
			};
		};
		hitpoints=100;
	};
	class ND_CastHeadPick: Inventory_Base
	{
		scope=2;
		displayName="Cast Iron Pick Head";
		descriptionShort="A head for a pickaxe";
		model = "\Dumpgrah\Assets\Furance_colorbase\Forge\CastIronPickaxehead.p3d";
		rotationFlags=12;
		itemSize[]={3,6};
		weight=1300;
		itemBehaviour=2;
		inventorySlot[]={"ForgeMetalOne"};
	};
	class ND_CastPickaxeHead : ND_CastHeadPick{};
	class ND_CastAxeHead: Inventory_Base
	{
		scope=2;
		displayName="Cast Iron Axe Head";
		descriptionShort="A head for a axe";
		model = "\Dumpgrah\Assets\Furance_colorbase\Forge\CastIronAxeHead.p3d";
		rotationFlags=12;
		itemSize[]={3,6};
		weight=1300;
		itemBehaviour=2;
		inventorySlot[]={"ForgeMetalOne"};
	};
	class ND_CastHammerHead: Inventory_Base
	{
		scope=2;
		displayName="Cast Iron Hammer Head";
		descriptionShort="A head for a hammer";
		model = "\Dumpgrah\Assets\Furance_colorbase\Forge\CastIronHammerHead.p3d";
		rotationFlags=12;
		itemSize[]={3,6};
		weight=1300;
		itemBehaviour=2;
		inventorySlot[]={"ForgeMetalOne"};
	};
	class ND_CastShovelHead: Inventory_Base
	{
		scope=2;
		displayName="Cast Iron Shovel Head";
		descriptionShort="A head for a shovel";
		model = "\Dumpgrah\Assets\Furance_colorbase\Forge\CastIronShovelHead.p3d";
		rotationFlags=12;
		itemSize[]={3,6};
		weight=1300;
		itemBehaviour=2;
		inventorySlot[]={"ForgeMetalOne"};
	};
	class ND_CastAxe: WoodAxe
	{
		scope=2;
		displayName="Cast Iron Axe";
		descriptionShort="A axe made out of cast iron, seems very brittle and quite weak";
		model = "\Dumpgrah\Assets\Furance_colorbase\Forge\CastIronAxe.p3d";
		rotationFlags=12;
		repairableWithKits[]={4};
		repairCosts[]={25};
		itemSize[]={2,4};
		weight=750;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=62.5;
					healthLevels[]=
					{
						
						{
							1.0,
							
							{

							}
						},
						
						{
							0.69999999,
							
							{

							}
						},
						
						{
							0.5,
							
							{

							}
						},
						
						{
							0.30000001,
							
							{

							}
						},
						
						{
							0.0,
							
							{

							}
						}
					};
				};
			};
		};

	};
	class ND_CastHammer: Hammer
	{
		scope=2;
		displayName="Cast Iron Hammer";
		descriptionShort="A Hammer made out of cast iron, seems very brittle and quite weak";
		model = "\Dumpgrah\Assets\Furance_colorbase\Forge\CastIronHammer.p3d";
		rotationFlags=12;
		repairableWithKits[]={0,0};
		repairCosts[]={100,100};
		itemSize[]={2,5};
		weight=3000;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=25;
					healthLevels[]=
					{
						
						{
							1.0,
							
							{
								"DZ\gear\tools\data\Hammer.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\tools\data\Hammer.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\tools\data\Hammer_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\tools\data\Hammer_damage.rvmat"
							}
						},
						
						{
							0.0,
							
							{
								"DZ\gear\tools\data\Hammer_destruct.rvmat"
							}
						}
					};
				};
			};
		};

	};
	class ND_CastPickaxe: Pickaxe
	{
		scope=2;
		displayName="Cast Iron Pickaxe";
		descriptionShort="A Pickaxe made out of cast iron, seems very brittle and quite weak";
		model = "\Dumpgrah\Assets\Furance_colorbase\Forge\CastIronPickaxe.p3d";
		rotationFlags=12;
		repairableWithKits[]={4};
		repairCosts[]={25};
		itemSize[]={2,4};
		weight=5000;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=62;
					healthLevels[]=
					{
						
						{
							1.0,
							
							{

							}
						},
						
						{
							0.69999999,
							
							{

							}
						},
						
						{
							0.5,
							
							{

							}
						},
						
						{
							0.30000001,
							
							{

							}
						},
						
						{
							0.0,
							
							{

							}
						}
					};
				};
			};
		};
	};
	class ND_CastShovel: Shovel
	{
		scope=2;
		displayName="Cast Iron Shovel";
		descriptionShort="A Shovel made out of cast iron, seems very brittle and quite weak";
		model = "\Dumpgrah\Assets\Furance_colorbase\Forge\CastIronShovel.p3d";
		rotationFlags=12;
		repairableWithKits[]={0,0};
		repairCosts[]={100,100};
		itemSize[]={2,6};
		weight=8000;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=50;
					healthLevels[]=
					{
						
						{
							1.0,
							
							{

							}
						},
						
						{
							0.69999999,
							
							{

							}
						},
						
						{
							0.5,
							
							{

							}
						},
						
						{
							0.30000001,
							
							{

							}
						},
						
						{
							0.0,
							
							{

							}
						}
					};
				};
			};
		};
	};
	class ND_LongWoodenHandle: Inventory_Base
	{
		scope=2;
		displayName="Long Wooden Handle";
		descriptionShort="A long wooden handle used for attaching tool heads too.";
		model = "\Dumpgrah\Assets\Furance_colorbase\Forge\LongWoodenHandle.p3d";
		rotationFlags=12;
		itemSize[]={1,6};
		weight=1300;
		itemBehaviour=2;
		attachments[]=
		{
			"Wedges"
		};
	};
	class ND_ShortWoodenHandle: Inventory_Base
	{
		scope=2;
		displayName="Short Wooden Handle";
		descriptionShort="A short wooden handle used for attaching tool heads too.";
		model = "\Dumpgrah\Assets\Furance_colorbase\Forge\ShortWoodenHandle.p3d";
		rotationFlags=12;
		itemSize[]={1,3};
		weight=1300;
		itemBehaviour=2;
		attachments[]=
		{
			"Wedges"
		};
	};
	class ND_ImpureAxeHead: Inventory_Base
	{
		scope=2;
		displayName="Impure Iron Axe Head";
		descriptionShort="A impure iron head for a axe";
		model = "\Dumpgrah\Assets\Furance_colorbase\Forge\ImPureIronAxeHead.p3d";
		rotationFlags=12;
		itemSize[]={3,3};
		weight=1300;
		itemBehaviour=2;
		inventorySlot[]={"ForgeMetal","ForgeMetalOne"};
	};
	class ND_ImpureHammerHead: Inventory_Base
	{
		scope=2;
		displayName="Impure Iron Hammer Head";
		descriptionShort="A impure iron head for a axe";
		model = "\Dumpgrah\Assets\Furance_colorbase\Forge\ImpureIronHammerHead.p3d";
		rotationFlags=12;
		itemSize[]={2,2};
		weight=1300;
		itemBehaviour=2;
		inventorySlot[]={"ForgeMetalOne"};
	};
	class ND_ImpureHatchetHead: Inventory_Base
	{
		scope=2;
		displayName="Impure Iron Axe Head";
		descriptionShort="A impure iron head for a axe";
		model = "\Dumpgrah\Assets\Furance_colorbase\Forge\ImpureIronHatchetHead.p3d";
		rotationFlags=12;
		itemSize[]={3,2};
		weight=1300;
		itemBehaviour=2;
		inventorySlot[]={"ForgeMetalOne"};
	};
	class ND_ImpurePickaxeHead: Inventory_Base
	{
		scope=2;
		displayName="Impure Iron PickAxe Head";
		descriptionShort="A impure iron head for a axe";
		model = "\Dumpgrah\Assets\Furance_colorbase\Forge\ImpureIronPickAxeHead.p3d";
		rotationFlags=12;
		itemSize[]={3,3};
		weight=1300;
		itemBehaviour=2;
		inventorySlot[]={"ForgeMetalOne"};
	};
	class ND_ImpureShovelHead: Inventory_Base
	{
		scope=2;
		displayName="Impure Iron shovel";
		descriptionShort="A impure iron head for a shovel";
		model = "\Dumpgrah\Assets\Furance_colorbase\Forge\ImPureIronShovelHead.p3d";
		rotationFlags=12;
		itemSize[]={3,3};
		weight=1300;
		itemBehaviour=2;
		inventorySlot[]={"ForgeMetalOne"};
	};
	class ND_ImpureIronHammer: Hammer
	{
		scope=2;
		displayName="Impure Iron Hammer";
		descriptionShort="A Hammer made out of impure iron, seems quite sturdy but not close to what ive found in the world.";
		model = "\Dumpgrah\Assets\Furance_colorbase\Forge\ImpureIronHammer.p3d";
		rotationFlags=12;
		repairableWithKits[]={0,0};
		repairCosts[]={100,100};
		itemSize[]={2,4};
		weight=3000;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=48;
					healthLevels[]=
					{
						
						{
							1.0,
							
							{

							}
						},
						
						{
							0.69999999,
							
							{

							}
						},
						
						{
							0.5,
							
							{

							}
						},
						
						{
							0.30000001,
							
							{

							}
						},
						
						{
							0.0,
							
							{

							}
						}
					};
				};
			};
		};
	};
	class ND_ImpureIronHatchet: Hatchet
	{
		scope=2;
		displayName="Impure Iron Hatchet";
		descriptionShort="A hatchet made out of impure iron, seems quite sturdy but not close to what ive found in the world.";
		model = "\Dumpgrah\Assets\Furance_colorbase\Forge\ImpureIronHatchet.p3d";
		build_action_type=10;
		dismantle_action_type=10;
		repairableWithKits[]={0,0};
		repairCosts[]={100,100};
		rotationFlags=17;
		weight=1133;
		itemSize[]={2,5};
		openItemSpillRange[]={20,40};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=72;
					healthLevels[]=
					{
						
						{
							1.0,
							
							{
								"DZ\weapons\melee\blade\data\hatchet.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\weapons\melee\blade\data\hatchet.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\weapons\melee\blade\data\hatchet_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\weapons\melee\blade\data\hatchet_damage.rvmat"
							}
						},
						
						{
							0.0,
							
							{
								"DZ\weapons\melee\blade\data\hatchet_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class ND_ImpureIronHatchetHammer: Hammer
	{
		scope=2;
		displayName="Impure Iron Hatchet";
		descriptionShort="A hatchet made out of impure iron, turned around for hammering, seems quite sturdy but not close to what ive found in the world.";
		model = "\Dumpgrah\Assets\Furance_colorbase\Forge\ImpureIronHatchetHammerEnd.p3d";
		rotationFlags=12;
		repairableWithKits[]={0,0};
		repairCosts[]={100,100};
		itemSize[]={2,5};
		weight=3000;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=72;
					healthLevels[]=
					{
						
						{
							1.0,
							
							{

							}
						},
						
						{
							0.69999999,
							
							{

							}
						},
						
						{
							0.5,
							
							{

							}
						},
						
						{
							0.30000001,
							
							{

							}
						},
						
						{
							0.0,
							
							{

							}
						}
					};
				};
			};
		};

	};
	class ND_ImpureIronAxe: WoodAxe
	{
		scope=2;
		displayName="Impure Iron Axe";
		descriptionShort="A axe made out of impure iron, seems quite sturdy but not close to what ive found in the world.";
		model = "\Dumpgrah\Assets\Furance_colorbase\Forge\ImPureIronAxe.p3d";
		rotationFlags=12;
		repairableWithKits[]={4};
		repairCosts[]={25};
		itemSize[]={2,5};
		weight=750;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=120;
					healthLevels[]=
					{
						
						{
							1.0,
							
							{

							}
						},
						
						{
							0.69999999,
							
							{

							}
						},
						
						{
							0.5,
							
							{

							}
						},
						
						{
							0.30000001,
							
							{

							}
						},
						
						{
							0.0,
							
							{

							}
						}
					};
				};
			};
		};
	};
	class ND_ImpurePickAxe : Pickaxe
	{
		scope=2;
		displayName="ImPure Iron Pickaxe";
		descriptionShort="A Pickaxe made out of Impure Iron";
		model = "\Dumpgrah\Assets\Furance_colorbase\Forge\ImpureIronPickAxe.p3d";
		rotationFlags=12;
		repairableWithKits[]={4};
		repairCosts[]={25};
		itemSize[]={3,5};
		weight=5000;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=120;
					healthLevels[]=
					{
						
						{
							1.0,
							
							{

							}
						},
						
						{
							0.69999999,
							
							{

							}
						},
						
						{
							0.5,
							
							{

							}
						},
						
						{
							0.30000001,
							
							{

							}
						},
						
						{
							0.0,
							
							{

							}
						}
					};
				};
			};
		};
	};
	class ND_ImpureShovel: Shovel
	{
		scope=2;
		displayName="Impure Iron Shovel";
		descriptionShort="A impure iron Shovel";
		model = "\Dumpgrah\Assets\Furance_colorbase\Forge\ImPureIronShovel.p3d";
		rotationFlags=12;
		repairableWithKits[]={0,0};
		repairCosts[]={100,100};
		itemSize[]={2,6};
		weight=8000;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=96;
					healthLevels[]=
					{
						
						{
							1.0,
							
							{

							}
						},
						
						{
							0.69999999,
							
							{

							}
						},
						
						{
							0.5,
							
							{

							}
						},
						
						{
							0.30000001,
							
							{

							}
						},
						
						{
							0.0,
							
							{

							}
						}
					};
				};
			};
		};
	};
	class ND_PureAxeHead: Inventory_Base
	{
		scope=2;
		displayName="Pure Iron Axe Head";
		descriptionShort="A Pure iron head for a axe";
		model = "\Dumpgrah\Assets\Furance_colorbase\Forge\PureIronAxeHead.p3d";
		rotationFlags=12;
		itemSize[]={3,3};
		weight=1000;
		itemBehaviour=2;
		inventorySlot[]={"ForgeMetalOne"};
	};
	class ND_PureHammerHead: Inventory_Base
	{
		scope=2;
		displayName="Pure Iron Hammer Head";
		descriptionShort="A Pure iron head for a axe";
		model = "\Dumpgrah\Assets\Furance_colorbase\Forge\pureIronHammerHead.p3d";
		rotationFlags=12;
		itemSize[]={2,2};
		weight=1000;
		itemBehaviour=2;
		inventorySlot[]={"ForgeMetalOne"};
	};
	class ND_PureHatchetHead: Inventory_Base
	{
		scope=2;
		displayName="Pure Iron Hatchet Head";
		descriptionShort="A Pure iron head for a hatchet";
		model = "\Dumpgrah\Assets\Furance_colorbase\Forge\pureIronHatchetHead.p3d";
		rotationFlags=12;
		itemSize[]={2,3};
		weight=1000;
		itemBehaviour=2;
		inventorySlot[]={"ForgeMetalOne"};
	};
	class ND_PurePickaxeHead: Inventory_Base
	{
		scope=2;
		displayName="Pure Iron PickAxe Head";
		descriptionShort="A Pure iron head for a pickaxe";
		model = "\Dumpgrah\Assets\Furance_colorbase\Forge\pureIronPickAxeHead.p3d";
		rotationFlags=12;
		itemSize[]={3,3};
		weight=1000;
		itemBehaviour=2;
		inventorySlot[]={"ForgeMetalOne"};
	};
	class ND_PureShovelHead: Inventory_Base
	{
		scope=2;
		displayName="Pure Iron shovel";
		descriptionShort="A Pure iron head for a shovel";
		model = "\Dumpgrah\Assets\Furance_colorbase\Forge\PureIronShovelHead.p3d";
		rotationFlags=12;
		itemSize[]={3,3};
		weight=1000;
		itemBehaviour=2;
		inventorySlot[]={"ForgeMetalOne"};
	};
	class ND_PureIronHammer: Hammer
	{
		scope=2;
		displayName="Pure Iron Hammer";
		descriptionShort="A Hammer made out of Pure iron, seems quite sturdy but not close to what ive found in the world.";
		model = "\Dumpgrah\Assets\Furance_colorbase\Forge\pureIronHammer.p3d";
		rotationFlags=12;
		repairableWithKits[]={0,0};
		repairCosts[]={100,100};
		itemSize[]={2,4};
		weight=2600;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=72;
					healthLevels[]=
					{
						
						{
							1.0,
							
							{

							}
						},
						
						{
							0.69999999,
							
							{

							}
						},
						
						{
							0.5,
							
							{

							}
						},
						
						{
							0.30000001,
							
							{

							}
						},
						
						{
							0.0,
							
							{

							}
						}
					};
				};
			};
		};
	};
	class ND_PureIronHatchet: Hatchet
	{
		scope=2;
		displayName="Pure Iron Hatchet";
		descriptionShort="A hatchet made out of Pure iron, seems quite sturdy but not close to what ive found in the world.";
		model = "\Dumpgrah\Assets\Furance_colorbase\Forge\pureIronHatchet.p3d";
		build_action_type=10;
		dismantle_action_type=10;
		repairableWithKits[]={0,0};
		repairCosts[]={100,100};
		rotationFlags=17;
		weight=1133;
		itemSize[]={2,5};
		openItemSpillRange[]={20,40};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=108;
					healthLevels[]=
					{
						
						{
							1.0,
							
							{
								"DZ\weapons\melee\blade\data\hatchet.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\weapons\melee\blade\data\hatchet.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\weapons\melee\blade\data\hatchet_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\weapons\melee\blade\data\hatchet_damage.rvmat"
							}
						},
						
						{
							0.0,
							
							{
								"DZ\weapons\melee\blade\data\hatchet_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class ND_PureIronHatchetHammer: Hammer
	{
		scope=2;
		displayName="Pure Iron Hatchet";
		descriptionShort="A hatchet made out of Pure iron, turned around for hammering, seems quite sturdy but not close to what ive found in the world.";
		model = "\Dumpgrah\Assets\Furance_colorbase\Forge\PureIronHatchetHammerEnd.p3d";
		rotationFlags=12;
		repairableWithKits[]={0,0};
		repairCosts[]={100,100};
		itemSize[]={2,5};
		weight=3000;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=108;
					healthLevels[]=
					{
						
						{
							1.0,
							
							{

							}
						},
						
						{
							0.69999999,
							
							{

							}
						},
						
						{
							0.5,
							
							{

							}
						},
						
						{
							0.30000001,
							
							{

							}
						},
						
						{
							0.0,
							
							{

							}
						}
					};
				};
			};
		};

	};
	class ND_PureIronAxe: WoodAxe
	{
		scope=2;
		displayName="Pure Iron Axe";
		descriptionShort="A axe made out of Pure iron, seems quite sturdy but not close to what ive found in the world.";
		model = "\Dumpgrah\Assets\Furance_colorbase\Forge\PureIronAxe.p3d";
		rotationFlags=12;
		repairableWithKits[]={4};
		repairCosts[]={25};
		itemSize[]={2,5};
		weight=750;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=180;
					healthLevels[]=
					{
						
						{
							1.0,
							
							{

							}
						},
						
						{
							0.69999999,
							
							{

							}
						},
						
						{
							0.5,
							
							{

							}
						},
						
						{
							0.30000001,
							
							{

							}
						},
						
						{
							0.0,
							
							{

							}
						}
					};
				};
			};
		};
	};
	class ND_PurePickAxe : Pickaxe
	{
		scope=2;
		displayName="Pure Iron Pickaxe";
		descriptionShort="A Pickaxe made out of Pure Iron";
		model = "\Dumpgrah\Assets\Furance_colorbase\Forge\pureIronPickAxe.p3d";
		rotationFlags=12;
		repairableWithKits[]={4};
		repairCosts[]={25};
		itemSize[]={3,5};
		weight=5000;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=180;
					healthLevels[]=
					{
						
						{
							1.0,
							
							{

							}
						},
						
						{
							0.69999999,
							
							{

							}
						},
						
						{
							0.5,
							
							{

							}
						},
						
						{
							0.30000001,
							
							{

							}
						},
						
						{
							0.0,
							
							{

							}
						}
					};
				};
			};
		};
	};
	class ND_PureShovel: Shovel
	{
		scope=2;
		displayName="Pure Iron Shovel";
		descriptionShort="A Pure iron Shovel";
		model = "\Dumpgrah\Assets\Furance_colorbase\Forge\PureIronShovel.p3d";
		rotationFlags=12;
		repairableWithKits[]={0,0};
		repairCosts[]={100,100};
		itemSize[]={2,6};
		weight=8000;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=144;
					healthLevels[]=
					{
						
						{
							1.0,
							
							{

							}
						},
						
						{
							0.69999999,
							
							{

							}
						},
						
						{
							0.5,
							
							{

							}
						},
						
						{
							0.30000001,
							
							{

							}
						},
						
						{
							0.0,
							
							{

							}
						}
					};
				};
			};
		};
	};
	class ND_CastIronNails : Nail
	{
		scope=2;
		displayName="Cast Iron Forged Nails";
		descriptionShort="Nails made by hand on a forge and anvil, They are made from cast iron and seems quite fragil, might break a few before they go into a board";
		model = "\Dumpgrah\Assets\Furance_colorbase\Forge\CastIronNails.p3d";
		weight=72.279999;
		itemSize[]={1,2};
		canBeSplit=1;
		varQuantityInit=0;
		varQuantityMin=0;
		varQuantityMax=100;
		inventorySlot[]=
		{
			"Material_Nails",
			"Material_L1_Nails",
			"Material_L1W1_Nails",
			"Material_L1W2_Nails",
			"Material_L1W3_Nails",
			"Material_L2_Nails",
			"Material_L2W1_Nails",
			"Material_L2W2_Nails",
			"Material_L2W3_Nails",
			"Material_L3_Nails",
			"Material_L3W1_Nails",
			"Material_L3W2_Nails",
			"Material_L3W3_Nails",
			"Material_FPole_Nails",
			"ForgeMetalOne"
		};
	};
	class ND_ImpureIronNails : Nail
	{
		scope=2;
		displayName="Impure Iron Forged Nails";
		descriptionShort="Nails made by hand on a forge and anvil, They are made form ImPure Iron and while strong bend easly.";
		model = "\Dumpgrah\Assets\Furance_colorbase\Forge\ImPureIronNails.p3d";
		weight=72.279999;
		itemSize[]={1,2};
		canBeSplit=1;
		varQuantityInit=0;
		varQuantityMin=0;
		varQuantityMax=100;
		inventorySlot[]=
		{
			"Material_Nails",
			"Material_L1_Nails",
			"Material_L1W1_Nails",
			"Material_L1W2_Nails",
			"Material_L1W3_Nails",
			"Material_L2_Nails",
			"Material_L2W1_Nails",
			"Material_L2W2_Nails",
			"Material_L2W3_Nails",
			"Material_L3_Nails",
			"Material_L3W1_Nails",
			"Material_L3W2_Nails",
			"Material_L3W3_Nails",
			"Material_FPole_Nails",
			"ForgeMetalOne"
		};
	};
	class ND_PureIronNails : Nail
	{
		scope=2;
		displayName="Hand Forged Iron Nails";
		descriptionShort="Nails made by hand on a forge and anvil, seem super sturdy";
		model = "\Dumpgrah\Assets\Furance_colorbase\Forge\IronNails.p3d";
		weight=72.279999;
		itemSize[]={1,2};
		canBeSplit=1;
		varQuantityInit=0;
		varQuantityMin=0;
		varQuantityMax=120;
		inventorySlot[]=
		{
			"Material_Nails",
			"Material_L1_Nails",
			"Material_L1W1_Nails",
			"Material_L1W2_Nails",
			"Material_L1W3_Nails",
			"Material_L2_Nails",
			"Material_L2W1_Nails",
			"Material_L2W2_Nails",
			"Material_L2W3_Nails",
			"Material_L3_Nails",
			"Material_L3W1_Nails",
			"Material_L3W2_Nails",
			"Material_L3W3_Nails",
			"Material_FPole_Nails",
			"ForgeMetalOne"
		};
	};
	class ND_ManDrill : Inventory_Base
	{
		scope=0;
		displayName="A ManDrill";
		descriptionShort="A ManDrill for an anvil, used to make small circle changes to hot metal, far more delicate of nature then using the anvils horn.";
		model = "\Dumpgrah\Assets\Furance_colorbase\Forge\ManDrill.p3d";
		weight=5000;
		itemSize[]={2,4};
		inventorySlot[]={"Pritchel_Hole"};
	};
	class ND_SplittingWedge : Inventory_Base
	{
		scope=0;
		displayName="Anvil Wedge";
		descriptionShort="A wedge used in a anvil, useful for making hard angles and cutting metal down.";
		model = "\Dumpgrah\Assets\Furance_colorbase\Forge\SplittingWedge.p3d";
		weight=5000;
		itemSize[]={3,2};
		inventorySlot[]={"Hardie_Hole"};
	};
	class ND_ToolWedges : Inventory_Base
	{
		scope=2;
		displayName="Metal Wedges";
		descriptionShort="Used in expanding the top of a wooden handle to keep the tools or items head from falling or flying off.";
		model = "\Dumpgrah\Assets\Furance_colorbase\Forge\ImpureMetalWedges.p3d";
		weight=100;
		itemSize[]={1,1};
		inventorySlot[]={"Wedges","ForgeMetalOne"};
	};
	class ND_MakeShirtAnvilBase : Inventory_Base{};
	
	class ND_SteelAnvil: Inventory_Base
	{
		scope=2;
		displayName = "A High Quality Anvil";
		descriptionShort = "A professionaly cast anvil, tempered and annealed making a strong hard metal surface, it weights 90 kgs. the  stamp on the feed indicate this was made back before WWII making this made out of Hard-Iron which is quite rare to find now days.";
		model = "\Dumpgrah\Assets\Furance_colorbase\Forge\ProfessionalAnvil.p3d";
		canBeDigged=0;
		forceFarBubble="true";
		slopeTolerance=0.30000001;
	    isMeleeWeapon=1; 
		rotationFlags = 17;
		stackedUnit = "w";
		physLayer = "item_large";
		itemBehaviour = 0;
		heavyItem = 1;
		varQuantityDestroyOnMin=1;
		weight = 90000;
		itemSize[] = { 6,6 };
		repairableWithKits[]={0};
		simpleHiddenSelections[] = {"GroundAnvil","StumpAnvil"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=2000;
					healthLevels[]=
					{
						
						{
							1.0,
							
							{
								""
							}
						},
						
						{
							0.69999999,
							
							{
								""
							}
						},
						
						{
							0.5,
							
							{
								""
							}
						},
						
						{
							0.30000001,
							
							{
								""
							}
						},
						
						{
							0.0,
							
							{
								""
							}
						}
					};
				};
			};
		};
		class Cargo
		{
			itemsCargoSize[]={0,0};
			openable=0;
			allowOwnedCargoManipulation=0;
		};
		attachments[]=
		{
			"ForgeMetal",
			"ForgeMetalOne",
			"Anvil_Stand"
			//"Pritchel_Hole"
			//"Hardie_Hole"
		};
		class GUIInventoryAttachmentsProps
		{

			class Face
			{
				name="Face";
				description="";
				attachmentSlots[]=
				{
					"ForgeMetal",
					"ForgeMetalOne"
				};
			};
			class Stand
			{
				name="Anvil Stand";
				description="";
				attachmentSlots[]=
				{
					"Anvil_Stand"
				};
			};
		};
	};
	class ND_BaseAnvilStump : Inventory_Base{};
	class ND_MSPureIronAnvilStump : ND_BaseAnvilStump
	{
		scope=2;
		displayName = "A Hand made Pure Iron Anvil";
		descriptionShort = "A Pure Iron Anvil, Made from Pure Iron the metal is quite sturdy but still weak compared to professionaly made steel.";
		model = "\Dumpgrah\Assets\Furance_colorbase\Forge\PureIronMakeShiftAnvilandStand.p3d";
		canBeDigged=0;
		forceFarBubble="true";
		slopeTolerance=0.30000001;
	    isMeleeWeapon=1; 
		rotationFlags = 17;
		stackedUnit = "w";
		physLayer = "item_large";
		itemBehaviour = 0;
		heavyItem = 1;
		varQuantityDestroyOnMin=1;
		weight = 90000;
		itemSize[] = { 6,6 };
		repairableWithKits[]={0};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=720;
					healthLevels[]=
					{
						
						{
							1.0,
							
							{
								""
							}
						},
						
						{
							0.69999999,
							
							{
								""
							}
						},
						
						{
							0.5,
							
							{
								""
							}
						},
						
						{
							0.30000001,
							
							{
								""
							}
						},
						
						{
							0.0,
							
							{
								""
							}
						}
					};
				};
			};
		};
		class Cargo
		{
			itemsCargoSize[]={0,0};
			openable=0;
			allowOwnedCargoManipulation=0;
		};
		attachments[]=
		{
			"ForgeMetal",
			"ForgeMetalOne"
		};
		class GUIInventoryAttachmentsProps
		{

			class Face
			{
				name="Face";
				description="";
				attachmentSlots[]=
				{
					"ForgeMetal",
					"ForgeMetalOne"
				};
			};
		};
	};
	class ND_MSImpureIronAnvilStump : ND_BaseAnvilStump
	{
		scope=2;
		displayName = "A Hand made Impure Iron Anvil";
		descriptionShort = "A Impure Iron Anvil, Made from Impure Iron the metal is quite sturdy but still weak compared to steel or iron.";
		model = "\Dumpgrah\Assets\Furance_colorbase\Forge\ImpureMakeShiftAnvilandStand.p3d";
		canBeDigged=0;
		forceFarBubble="true";
		slopeTolerance=0.30000001;
	    isMeleeWeapon=1; 
		rotationFlags = 17;
		stackedUnit = "w";
		physLayer = "item_large";
		itemBehaviour = 0;
		heavyItem = 1;
		weight = 90000;
		itemSize[] = { 6,6 };
		repairableWithKits[]={0};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=480;
					healthLevels[]=
					{
						
						{
							1.0,
							
							{
								""
							}
						},
						
						{
							0.69999999,
							
							{
								""
							}
						},
						
						{
							0.5,
							
							{
								""
							}
						},
						
						{
							0.30000001,
							
							{
								""
							}
						},
						
						{
							0.0,
							
							{
								""
							}
						}
					};
				};
			};
		};
		attachments[]=
		{
			"ForgeMetal",
			"ForgeMetalOne"
		};
		class GUIInventoryAttachmentsProps
		{

			class Face
			{
				name="Face";
				description="";
				attachmentSlots[]=
				{
					"ForgeMetal",
					"ForgeMetalOne"
				};
			};
		};
	};
	class ND_MSCastIronAnvilStump : ND_BaseAnvilStump
	{
		scope=2;
		displayName = "A Hand made Cast Iron Anvil";
		descriptionShort = "A Cast Iron Anvil, Made from Cast Iron the metal is quite Brittle.";
		model = "\Dumpgrah\Assets\Furance_colorbase\Forge\CastIronMakeShiftAnvilandStand.p3d";
		canBeDigged=0;
		forceFarBubble="true";
		slopeTolerance=0.30000001;
	    isMeleeWeapon=1; 
		rotationFlags = 17;
		stackedUnit = "w";
		physLayer = "item_large";
		itemBehaviour = 0;
		heavyItem = 1;
		varQuantityDestroyOnMin=1;
		weight = 90000;
		itemSize[] = { 6,6 };
		repairableWithKits[]={0};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=250;
					healthLevels[]=
					{
						
						{
							1.0,
							
							{
								""
							}
						},
						
						{
							0.69999999,
							
							{
								""
							}
						},
						
						{
							0.5,
							
							{
								""
							}
						},
						
						{
							0.30000001,
							
							{
								""
							}
						},
						
						{
							0.0,
							
							{
								""
							}
						}
					};
				};
			};
		};
		class Cargo
		{
			itemsCargoSize[]={0,0};
			openable=0;
			allowOwnedCargoManipulation=0;
		};
		attachments[]=
		{
			"ForgeMetal",
			"ForgeMetalOne"
		};
		class GUIInventoryAttachmentsProps
		{

			class Face
			{
				name="Face";
				description="";
				attachmentSlots[]=
				{
					"ForgeMetal",
					"ForgeMetalOne"
				};
			};
		};
	};
	class ND_MakeShiftPureIronAnvil : ND_MakeShirtAnvilBase
	{
		scope=2;
		displayName = "A Hand made Pure Iron Anvil";
		descriptionShort = "A Pure Iron Anvil, Made from Pure Iron the metal is quite sturdy but still weak compared to professionaly made steel.";
		model = "\Dumpgrah\Assets\Furance_colorbase\Forge\PureIronMakeShiftAnvil.p3d";
		canBeDigged=0;
		forceFarBubble="true";
		slopeTolerance=0.30000001;
	    isMeleeWeapon=1; 
		rotationFlags = 17;
		stackedUnit = "w";
		physLayer = "item_large";
		itemBehaviour = 0;
		heavyItem = 1;
		varQuantityDestroyOnMin=1;
		weight = 90000;
		itemSize[] = { 6,6 };
		repairableWithKits[]={0};
		inventorySlot[]={"AnvilCastMetal"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=720;
					healthLevels[]=
					{
						
						{
							1.0,
							
							{
								""
							}
						},
						
						{
							0.69999999,
							
							{
								""
							}
						},
						
						{
							0.5,
							
							{
								""
							}
						},
						
						{
							0.30000001,
							
							{
								""
							}
						},
						
						{
							0.0,
							
							{
								""
							}
						}
					};
				};
			};
		};
	};
	class ND_MakeShiftImpureIronAnvil : ND_MakeShirtAnvilBase
	{
		scope=2;
		displayName = "A Hand made Impure Iron Anvil";
		descriptionShort = "A Impure Iron Anvil, Made from Impure Iron the metal is quite sturdy but still weak compared to steel or iron.";
		model = "\Dumpgrah\Assets\Furance_colorbase\Forge\ImpureIronMakeShiftAnvil.p3d";
		canBeDigged=0;
		forceFarBubble="true";
		slopeTolerance=0.30000001;
	    isMeleeWeapon=1; 
		rotationFlags = 17;
		stackedUnit = "w";
		physLayer = "item_large";
		itemBehaviour = 0;
		heavyItem = 1;
		varQuantityDestroyOnMin=1;
		weight = 90000;
		itemSize[] = { 6,6 };
		repairableWithKits[]={0};
		inventorySlot[]={"AnvilCastMetal"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=480;
					healthLevels[]=
					{
						
						{
							1.0,
							
							{
								""
							}
						},
						
						{
							0.69999999,
							
							{
								""
							}
						},
						
						{
							0.5,
							
							{
								""
							}
						},
						
						{
							0.30000001,
							
							{
								""
							}
						},
						
						{
							0.0,
							
							{
								""
							}
						}
					};
				};
			};
		};
	};
	class ND_MakeShiftCastIronAnvil : ND_MakeShirtAnvilBase
	{
		scope=2;
		displayName = "A Hand made Cast Iron Anvil";
		descriptionShort = "A Cast Iron Anvil, Made from Cast Iron the metal is quite Brittle.";
		model = "\Dumpgrah\Assets\Furance_colorbase\Forge\CastIronMakeShiftAnvil.p3d";
		canBeDigged=0;
		forceFarBubble="true";
		slopeTolerance=0.30000001;
	    isMeleeWeapon=1; 
		rotationFlags = 17;
		stackedUnit = "w";
		physLayer = "item_large";
		itemBehaviour = 0;
		heavyItem = 1;
		varQuantityDestroyOnMin=1;
		weight = 90000;
		itemSize[] = { 6,6 };
		repairableWithKits[]={0};
		inventorySlot[]={"AnvilCastMetal"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=250;
					healthLevels[]=
					{
						
						{
							1.0,
							
							{
								""
							}
						},
						
						{
							0.69999999,
							
							{
								""
							}
						},
						
						{
							0.5,
							
							{
								""
							}
						},
						
						{
							0.30000001,
							
							{
								""
							}
						},
						
						{
							0.0,
							
							{
								""
							}
						}
					};
				};
			};
		};
	};
	class ND_TreeStump : Inventory_Base
	{
		scope=2;
		displayName = "Tree Stump";
		descriptionShort = "A Cutup tree stump, be good for puting something heavy and secure on it";
		model="Dumpgrah\Assets\Furance_colorbase\Forge\NDTreeStump.p3d";
		canBeDigged=0;
		physLayer = "item_large";
		itemBehaviour = 0;
		heavyItem = 1;
	    isMeleeWeapon=1; 
		rotationFlags = 17;
		weight = 500;
		itemSize[] = { 10,10 };
		repairableWithKits[]={0};
		inventorySlot[]={"Anvil_Stand"};
	};
	class ND_FiredBricks : Inventory_Base
	{
		scope=2;
		displayName = "Fired Clay Bricks";
		descriptionShort = "Hand made and shaped clay bricks, they are fully cured and seem like a good way to make something better.";
		model="\Dumpgrah\Assets\Furance_colorbase\FiredBricks.p3d";
		canBeDigged=0;
	    isMeleeWeapon=1; 
		rotationFlags = 17;
		quantityBar = 0;
		canBeSplit=1;
		varQuantityInit=0;
		varQuantityMin=0;
		varQuantityMax=100;
		stackedUnit = "w";
		varQuantityDestroyOnMin=1;
		inventorySlot[]={"CrucibleOutput"};
		weight = 500;
		itemSize[] = { 2,2 };
		repairableWithKits[]={0};
		
	};
	class ND_UnFiredBricks : Inventory_Base
	{
		scope=2;
		displayName = "UnFired Clay Bricks";
		descriptionShort = "Hand made and shaped clay bricks, they are still are soft and quite easy to deform, i should maybe put these into some heat?";
		model="\Dumpgrah\Assets\Furance_colorbase\UnfiredBricks.p3d";
		canBeDigged=0;
	    isMeleeWeapon=1; 
		rotationFlags = 17;
		quantityBar = 0;
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=10;
		stackedUnit = "w";
		varQuantityDestroyOnMin=1;
		inventorySlot[]={"CrucibleInput"};
		weight = 500;
		itemSize[] = { 2,2 };
		repairableWithKits[]={0};
		
	};
	class ND_ClayLump : Inventory_Base
	{
		scope=2;
		displayName = "Clay Lump";
		descriptionShort = "Its a clay lump, wonder what i can all make with this?";
		model="\Dumpgrah\Assets\Furance_colorbase\Clay Lump.p3d";
		canBeDigged=0;
	    isMeleeWeapon=1; 
		rotationFlags = 17;
		quantityBar = 0;
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=80;
		stackedUnit = "w";
		varQuantityDestroyOnMin=1;
		weight = 25;
		itemSize[] = { 2,2 };
		repairableWithKits[]={0};
		
	};
	class ND_SulfurCharCoalPowder : Inventory_Base
	{
		scope=2;
		displayName = "Sulfur & Charcoal Powder Mixture";
		descriptionShort = "Sulfur & Charcoal powder, I got this by combining sulfur and charcoal. now to add the final ingredient";
		model="\Dumpgrah\Assets\Furance_colorbase\SulfurCharCoalPowderPile.p3d";
		canBeDigged=0;
	    isMeleeWeapon=0; 
		rotationFlags = 17;
		quantityBar = 0;
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=1400;
		stackedUnit = "w";
		varQuantityDestroyOnMin=1;
		weight = 1;
		itemSize[] = { 3,2 };
		repairableWithKits[]={0};
		
	};
	class ND_CharCoalPowder : Inventory_Base
	{
		scope=2;
		displayName = "CharCoal Powder";
		descriptionShort = "CharCoal powder, I got this by crushing charcoal. seems to be an ingredient in making gunpowder";
		model="\Dumpgrah\Assets\Furance_colorbase\CharCoalPowderPile.p3d";
		canBeDigged=0;
	    isMeleeWeapon=0; 
		rotationFlags = 17;
		quantityBar = 0;
		canBeSplit=0;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=1400;
		stackedUnit = "w";
		varQuantityDestroyOnMin=1;
		weight = 1;
		itemSize[] = { 3,2 };
		repairableWithKits[]={0};
		
	};
	class ND_SulfurPowder : Inventory_Base
	{
		scope=2;
		displayName = "Sulfur Powder";
		descriptionShort = "Sulfur powder, I got this by crushing sulfur ore. seems to be an ingredient in making gunpowder";
		model="\Dumpgrah\Assets\Furance_colorbase\SulfurPowderPile.p3d";
		canBeDigged=0;
		weight = 1;
	    isMeleeWeapon=0; 
		rotationFlags = 17;
		quantityBar = 0;
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=1400;
		stackedUnit = "w";
		varQuantityDestroyOnMin=1;
		itemSize[] = { 3,2 };
		repairableWithKits[]={0};
		
	};
	class ND_BonePowder : Inventory_Base
	{
		scope=2;
		displayName = "Crushed Bones";
		descriptionShort = "Crushed Bones, maybe i could make something with this.";
		model="\Dumpgrah\Assets\Furance_colorbase\BonePowderPile.p3d";
		canBeDigged=0;
		weight = 1;
	    isMeleeWeapon=0; 
		rotationFlags = 17;
		quantityBar = 0;
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=100;
		stackedUnit = "w";
		varQuantityDestroyOnMin=1;
		itemSize[] = { 3,2 };
		repairableWithKits[]={0};
		
	};
	class ND_Potassium_Nitrate : Inventory_Base
	{
		scope=2;
		displayName="Potassium Nitrate";
		descriptionShort="Potassium nitrate probably is used as a oxidizer in blackpowder. From the most ancient times until the late 1880s, blackpowder provided the explosive power for all the world's firearms. After that time, small arms and large artillery increasingly began to depend on cordite, a smokeless powder.";
		model="\Dumpgrah\Assets\Furance_colorbase\PotassiumNitrate.p3d";
		animClass="NoFireClass";
		weight=20;
		absorbency=0.30000001;
		itemSize[]={2,2};
		canBeSplit=0;
		varQuantityInit=100;
		varQuantityMin=0;
		varQuantityMax=100;
		varQuantityDestroyOnMin=1;
		stackedUnit = "percentage";
		quantityBar = 1;
		hitpoints=500;

	};
	class ND_SplitWood : Inventory_Base
	{
		scope=2;
		displayName="Pile of split wood";
		descriptionShort="Pile of split wood, seems like you cut this pretty well. made this by chopping up some firewood. maybe it can be used to make something else?";
		model="\Dumpgrah\Assets\Furance_colorbase\FirewoodForCharcoal.p3d";
		animClass="NoFireClass";
		weight=40;
		absorbency=0.30000001;
		itemSize[]={2,3};
		canBeSplit=1;
		varQuantityInit=10;
		varQuantityMin=0;
		varQuantityMax=10;
		stackedUnit = "w";
		quantityBar = 0;
		inventorySlot[]={"CrucibleInput","Firewood"};
		hitpoints=500;

	};
	class ND_Charcoal : Inventory_Base
	{
		scope=2;
		displayName="Pile of Charcoal";
		descriptionShort="Charcoal a refined energy source made from burning firewood and smothering it ";
		model="\Dumpgrah\Assets\Furance_colorbase\Charcoal.p3d";
		animClass="NoFireClass";
		weight=1000;
		absorbency=0.30000001;
		itemSize[]={2,3};
		canBeSplit=1;
		varQuantityInit=2;
		varQuantityMin=0;
		varQuantityMax=2;
		stackedUnit = "w";
		quantityBar = 0;
		inventorySlot[]={"CrucibleOutput","Firewood","ND_Coal"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=500;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								""
							}
						}
					};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class woodenlog_drop
				{
					soundset="woodenlog_drop_SoundSet";
					id=898;
				};
			};
		};
		class EnergyManager
		{
			switchOnAtSpawn=1;
			isPassiveDevice=1;
			energyStorageMax=2400;
			energyUsagePerSecond=0;
			energyAtSpawn=2400;
			powerSocketsCount=1;
			compatiblePlugTypes[]={7};
			convertEnergyToQuantity=1;
		};
	};
	class ND_StackedCoal : Inventory_Base
	{
		scope=2;
		displayName="Pile of Coal";
		descriptionShort="Coal is a combustible black or brownish-black sedimentary rock, formed as rock strata called coal seams. Coal is mostly carbon with variable amounts of other elements; chiefly hydrogen, sulfur, oxygen, and nitrogen - Wiki-ND";
		model="\Dumpgrah\Assets\Furance_colorbase\StackedCoal.p3d";
		animClass="NoFireClass";
		weight=10;
		absorbency=0.30000001;
		canBeSplit =0;
		itemSize[]={3,3};
		varQuantityInit=3600;
		varQuantityMin=0;
		varQuantityMax=3600;
		stackedUnit = "percentage";
		quantityBar = 1;
		inventorySlot[]={"ND_Coal"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=500;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								""
							}
						}
					};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class woodenlog_drop
				{
					soundset="woodenlog_drop_SoundSet";
					id=898;
				};
			};
		};
		class EnergyManager
		{
			switchOnAtSpawn=1;
			isPassiveDevice=1;
			energyStorageMax=3600;
			energyUsagePerSecond=0;
			energyAtSpawn=3600;
			powerSocketsCount=1;
			compatiblePlugTypes[]={7};
			convertEnergyToQuantity=1;
		};
	};
	class ND_ClayRifleCasingMold : Inventory_Base
	{
		scope=2;
		displayName="Clay Rifle Casing Mold";
		descriptionShort="Mold that is Used for making metal casing for ammo, looks like someone just pushed the Rifle casing into the clay to get its shape for casting, looks filmsy and weak, will only last a few times.";
		model="\Dumpgrah\Assets\Furance_colorbase\RifleCasingsClayMold.p3d";
	//	overrideDrawArea="3.0";
		attachments[]={"RifleCasingMold"};
		simpleHiddenSelections[] = {"Casted_Casing"};
		itemSize[]={4,4};
		hitpoints=50;
	    inventorySlot[]={};
		varQuantityInit=0;
		varQuantityMin=0;
		varQuantityMax=100;
		varQuantityDestroyOnMin=1;
		varStackMax=0;
		quantityBar = 1;
		stackedUnit = "percentage";
		rotationFlags=2;
		openable=0;
		heavyItem=1;
		weight=10;
		carveNavmesh=0;
	};
	class ND_ClayRifleTipsMold : Inventory_Base
	{
		scope=2;
		displayName="Clay Rifle Tips Mold";
		descriptionShort="Mold that is Used for making metal Tips for ammo, looks like someone just pushed the Rifle Tips into the clay to get its shape for casting, looks filmsy and weak, will only last a few times.";
		model="\Dumpgrah\Assets\Furance_colorbase\RifleTipsClayMold.p3d";
	//	overrideDrawArea="3.0";
		attachments[]={"RifleTipsMold"};	
		simpleHiddenSelections[] = {"Casted_Tips"};
		itemSize[]={4,4};
		hitpoints=50;
	    inventorySlot[]={};
		varQuantityInit=0;
		varQuantityMin=0;
		varQuantityMax=100;
		varQuantityDestroyOnMin=1;
		varStackMax=0;
		quantityBar = 1;
		stackedUnit = "percentage";
		rotationFlags=2;
		openable=0;
		heavyItem=1;
		weight=10;
		carveNavmesh=0;
	};
	class ND_ClayPistolTipsMold : Inventory_Base
	{
		scope=2;
		displayName="Clay Pistol Tips Mold";
		descriptionShort="Mold that is Used for making metal Tips for ammo, looks like someone just pushed the Pistol Tips into the clay to get its shape for casting, looks filmsy and weak, will only last a few times.";
		model="\Dumpgrah\Assets\Furance_colorbase\Pistoltipsclaymold.p3d";
	//	overrideDrawArea="3.0";
		attachments[]={"RifleTipsMold"};	
		simpleHiddenSelections[] = {"Casted_Tips"};
		itemSize[]={4,4};
		hitpoints=50;
	    inventorySlot[]={};
		varQuantityInit=0;
		varQuantityMin=0;
		varQuantityMax=100;
		varQuantityDestroyOnMin=1;
		varStackMax=0;
		quantityBar = 1;
		stackedUnit = "percentage";
		rotationFlags=2;
		openable=0;
		heavyItem=1;
		weight=10;
		carveNavmesh=0;
	};
	class ND_ClayPistolCasingMold : Inventory_Base
	{
		scope=2;
		displayName="Clay Pistol Casing Mold";
		descriptionShort="Mold that is Used for making metal casing for ammo, looks like someone just pushed the Pistol casing into the clay to get its shape for casting, looks filmsy and weak, will only last a few times.";
		model="\Dumpgrah\Assets\Furance_colorbase\Pistolcasingclaymold.p3d";
	  //overrideDrawArea="3.0";
		attachments[]={"RifleCasingMold"};
		simpleHiddenSelections[] = {"Casted_Casing"};
		itemSize[]={4,4};
		hitpoints=50;
	    inventorySlot[]={};
		varQuantityInit=0;
		varQuantityMin=0;
		varQuantityMax=100;
		varQuantityDestroyOnMin=1;
		varStackMax=0;
		quantityBar = 1;
		stackedUnit = "percentage";
		rotationFlags=2;
		openable=0;
		heavyItem=1;
		weight=10;
		carveNavmesh=0;
	};
	class ND_CrucibleBase : Inventory_Base{};
	class ND_EmptyCrucible : ND_CrucibleBase
	{
		scope=2;
		displayName="Crucible";
		descriptionShort="A empty crucible";
		model="\Dumpgrah\Assets\Furance_colorbase\EmptyCrucible.p3d";
	//	overrideDrawArea="3.0";
		itemSize[]={6,6};
	    inventorySlot[]={"CrucibleEmpty"};
		varQuantityInit=0;
		varQuantityMin=0;
		varQuantityMax=0;
		varQuantityDestroyOnMin=1;
		varTemperatureMin=0;
		varTemperatureMax=100;
		varStackMax=0;
		quantityBar = 0;
		rotationFlags=2;
		openable=0;
		heavyItem=1;
		itemBehaviour = 2;
		weight=225;
		carveNavmesh=0;
	};
	class ND_CruciblePureIron : ND_CrucibleBase
	{
		scope=2;
		displayName="Crucible with Pure Iron Ingots";
		descriptionShort="Crucible Filled with Pure Iron Ingots, i can melt this down and recast into any metal shape i need.";
		model="\Dumpgrah\Assets\Furance_colorbase\Forge\PureIngotFilledCrucible.p3d";
	//	overrideDrawArea="3.0";
	    inventorySlot[]={"CrucibleInput"};
		itemSize[]={6,6};
		quantityBar = 1;
		stackedUnit = "percentage";
		varTemperatureMin=0;
		varTemperatureMax=100;
		varQuantityInit=0;
		varQuantityMin=0;
		varQuantityMax=100;
		varQuantityDestroyOnMin=1;
		varStackMax=0;
		rotationFlags=2;
		openable=0;
		heavyItem=1;
		itemBehaviour = 2;
		weight=45;
		carveNavmesh=0;
	};
	class ND_CrucibleOreCopper : ND_CrucibleBase
	{
		scope=2;
		displayName="Crucible with copper ore";
		descriptionShort="Crucible Filled with Copper Ore";
		model="\Dumpgrah\Assets\Furance_colorbase\CrucibleOreCopper.p3d";
	//	overrideDrawArea="3.0";
	    inventorySlot[]={"CrucibleInput"};
		itemSize[]={6,6};
		quantityBar = 1;
		stackedUnit = "percentage";
		varTemperatureMin=0;
		varTemperatureMax=100;
		varQuantityInit=0;
		varQuantityMin=0;
		varQuantityMax=100;
		varQuantityDestroyOnMin=1;
		varStackMax=0;
		rotationFlags=2;
		openable=0;
		heavyItem=1;
		itemBehaviour = 2;
		weight=45;
		carveNavmesh=0;
	};
	class ND_CrucibleOreZinc : ND_CrucibleBase
	{
		scope=2;
		displayName="Crucible with zinc ore";
		descriptionShort="Crucible Filled with Zinc Ore";
		model="\Dumpgrah\Assets\Furance_colorbase\CrucibleOreZinc.p3d";
	//	overrideDrawArea="3.0";
	    inventorySlot[]={"CrucibleInput", "CrucibleInput1"};
		itemSize[]={6,6};
		quantityBar = 1;
		stackedUnit = "percentage";
		varTemperatureMin=0;
		varTemperatureMax=100;
		varQuantityInit=0;
		varQuantityMin=0;
		varQuantityMax=100;
		varQuantityDestroyOnMin=1;
		varStackMax=0;
		rotationFlags=2;
		openable=0;
		heavyItem=1;
		itemBehaviour = 2;
		weight=450;
		carveNavmesh=0;
	};
	class ND_CrucibleOreIron : ND_CrucibleBase
	{
		scope=2;
		displayName="Crucible with Iron ore";
		descriptionShort="Crucible Filled with Iron Ore";
		model="\Dumpgrah\Assets\Furance_colorbase\CrucibleOreIron.p3d";
	//	overrideDrawArea="3.0";
	    inventorySlot[]={"CrucibleInput"};
		itemSize[]={6,6};
		quantityBar = 1;
		stackedUnit = "percentage";
		varTemperatureMin=0;
		varTemperatureMax=100;
		varQuantityInit=0;
		varQuantityMin=0;
		varQuantityMax=100;
		varQuantityDestroyOnMin=1;
		varStackMax=0;
		rotationFlags=2;
		openable=0;
		heavyItem=1;
		itemBehaviour = 2;
		weight=45;
		carveNavmesh=0;
	};
	class ND_CrucibleOreLead : ND_CrucibleBase
	{
		scope=2;
		displayName="Crucible with Lead ore";
		descriptionShort="Crucible Filled with Lead Ore";
		model="\Dumpgrah\Assets\Furance_colorbase\CrucibleOreLead.p3d";
	//	overrideDrawArea="3.0";
	    inventorySlot[]={"CrucibleInput"};
		itemSize[]={6,6};
		quantityBar = 1;
		stackedUnit = "percentage";
		varTemperatureMin=0;
		varTemperatureMax=100;
		varQuantityInit=0;
		varQuantityMin=0;
		varQuantityMax=100;
		varQuantityDestroyOnMin=1;
		varStackMax=0;
		rotationFlags=2;
		openable=0;
		heavyItem=1;
		itemBehaviour = 2;
		weight=45;
		carveNavmesh=0;
	};
	class ND_CrucibleMoltenCopper : ND_CrucibleBase
	{
		scope=2;
		displayName="Crucible with molten copper";
		descriptionShort="Crucible Filled with Molten Copper";
		model="\Dumpgrah\Assets\Furance_colorbase\MoltenCopper.p3d";
	//	overrideDrawArea="3.0";
	    inventorySlot[]={"CrucibleOutput" , "CrucibleInput"};
		itemSize[]={6,6};
		quantityBar = 1;
		stackedUnit = "percentage";
		varTemperatureMax=1250;
		varLiquidTypeInit=600;
		liquidContainerType="1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256 + 512 + 1024 + 2048 + 4096 + 8192 + 16384 + 32768 + 65536  - (1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256)";
		varQuantityInit=0;
		varQuantityDestroyOnMin=0;
		varQuantityMin=0;
		varQuantityMax=100;
		rotationFlags=2;
		openable=0;
		heavyItem=1;
		itemBehaviour = 2;
		weight=45;
		carveNavmesh=0;
	};
	class ND_CrucibleMoltenZinc : ND_CrucibleBase
	{
		scope=2;
		displayName="Crucible with molten zinc";
		descriptionShort="Crucible Filled with Molten zinc";
		model="\Dumpgrah\Assets\Furance_colorbase\MoltenZinc.p3d";
	//	overrideDrawArea="3.0";
	    inventorySlot[]={"CrucibleOutput" , "CrucibleInput1"};
		itemSize[]={6,6};
		quantityBar = 1;
		stackedUnit = "percentage";
		varTemperatureMin=0;
		varTemperatureMax=900;
		varLiquidTypeInit=600;
		liquidContainerType="1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256 + 512 + 1024 + 2048 + 4096 + 8192 + 16384 + 32768 + 65536  - (1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256)";
		varQuantityInit=100;
		varQuantityMin=0;
		varQuantityMax=100;
		varQuantityDestroyOnMin=0;
		varStackMax=0;
		rotationFlags=2;
		openable=0;
		heavyItem=1;
		itemBehaviour = 2;
		weight=45;
		carveNavmesh=0;
	};
	class ND_CrucibleMoltenIron : ND_CrucibleBase
	{
		scope=2;
		displayName="Crucible with molten Iron";
		descriptionShort="Crucible Filled with Molten Iron";
		model="\Dumpgrah\Assets\Furance_colorbase\MoltenIron.p3d";
	//	overrideDrawArea="3.0";
		itemsCargoSize[]={0,0};
	    inventorySlot[]={"CrucibleOutput"};
		itemSize[]={6,6};
		quantityBar = 1;
		stackedUnit = "percentage";
		varTemperatureMin=0;
		varTemperatureMax=1650;
		varLiquidTypeInit=600;
		liquidContainerType="1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256 + 512 + 1024 + 2048 + 4096 + 8192 + 16384 + 32768 + 65536  - (1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256)";
		varQuantityInit=100;
		varQuantityMin=0;
		varQuantityMax=100;
		varQuantityDestroyOnMin=0;
		varStackMax=0;
		rotationFlags=2;
		openable=0;
		heavyItem=1;
		itemBehaviour = 2;
		weight=45;
		carveNavmesh=0;
	};
	class ND_CrucibleMoltenImpureIron : ND_CrucibleBase
	{
		scope=2;
		displayName="Crucible with molten Impure Iron";
		descriptionShort="Crucible Filled with Molten Iron with quite a few impurties inside of it.";
		model="\Dumpgrah\Assets\Furance_colorbase\MoltenIron.p3d";
			//	overrideDrawArea="3.0";
		itemsCargoSize[]={0,0};
	    inventorySlot[]={"CrucibleOutput"};
		itemSize[]={6,6};
		quantityBar = 1;
		stackedUnit = "percentage";
		varTemperatureMin=0;
		varTemperatureMax=1650;
		varLiquidTypeInit=600;
		liquidContainerType="1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256 + 512 + 1024 + 2048 + 4096 + 8192 + 16384 + 32768 + 65536  - (1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256)";
		varQuantityInit=100;
		varQuantityMin=0;
		varQuantityMax=100;
		varQuantityDestroyOnMin=0;
		varStackMax=0;
		rotationFlags=2;
		openable=0;
		heavyItem=1;
		itemBehaviour = 2;
		weight=45;
		carveNavmesh=0;
	};
	class ND_CrucibleMoltenPigIron : ND_CrucibleBase
	{
		scope=2;
		displayName="Crucible with molten  Pig Iron";
		descriptionShort="Crucible Filled with Molten Iron";
		model="\Dumpgrah\Assets\Furance_colorbase\MoltenIron.p3d";
	//	overrideDrawArea="3.0";
	    inventorySlot[]={"CrucibleOutput"};
		itemSize[]={6,6};
		quantityBar = 1;
		stackedUnit = "percentage";
		varTemperatureMin=0;
		varTemperatureMax=1650;
		varLiquidTypeInit=600;
		liquidContainerType="1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256 + 512 + 1024 + 2048 + 4096 + 8192 + 16384 + 32768 + 65536  - (1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256)";
		varQuantityInit=100;
		varQuantityMin=0;
		varQuantityMax=100;
		varQuantityDestroyOnMin=0;
		varStackMax=0;
		rotationFlags=2;
		openable=0;
		heavyItem=1;
		itemBehaviour = 2;
		weight=45;
		carveNavmesh=0;
	};
	class ND_ClayCrucibleBase : Inventory_Base{};
	class ND_ClayMoltenCrucible :ND_ClayCrucibleBase{};
	class ND_UnfiredClayEmptyCrucible : ND_ClayCrucibleBase 
	{
		scope=2;
		displayName="A Unfired soft Crucible";
		descriptionShort="A Unfired soft crucible";
		model="\Dumpgrah\Assets\Furance_colorbase\EmptyClayCrucible.p3d";
		itemSize[]={4,4};
			//	overrideDrawArea="3.0";
	    inventorySlot[]={"CrucibleInput"};


	};
	class ND_ClayEmptyCrucible : ND_ClayCrucibleBase 
	{
		scope=2;
		displayName="Clay Crucible";
		descriptionShort="A empty crucible";
		model="\Dumpgrah\Assets\Furance_colorbase\EmptyFiredClayCrucible.p3d";
		itemSize[]={4,4};
			//	overrideDrawArea="3.0";
	    inventorySlot[]={"CrucibleOutput"};


	};
	class ND_ClayCrucibleFilledCasing  : ND_ClayCrucibleBase 
	{
		scope=2;
		displayName="Clay Crucible with Casings";
		descriptionShort="Crucible Filled with Casing";
		model="\Dumpgrah\Assets\Furance_colorbase\ClayCrucibleFilledCasing.p3d";
			//	overrideDrawArea="3.0";
	    inventorySlot[]={"CrucibleInput"};
		
		itemSize[]={4,4};
		quantityBar = 1;
		stackedUnit = "percentage";
		varTemperatureMin=0;
		varTemperatureMax=50;
		varQuantityInit=0;
		varQuantityMin=0;
		varQuantityMax=50;
		varQuantityDestroyOnMin=1;
		varStackMax=0;
		rotationFlags=2;
		openable=0;
		heavyItem=1;
		itemBehaviour = 2;
		weight=45;
		carveNavmesh=0;

	};
	class ND_ClayCrucibleFilledTips  : ND_ClayCrucibleBase 
	{
		scope=2;
		displayName="Clay Crucible with Tips";
		descriptionShort="Crucible Filled with Tips";
		model="\Dumpgrah\Assets\Furance_colorbase\ClayCrucibleFilledTips.p3d";
			//	overrideDrawArea="3.0";
	    inventorySlot[]={"CrucibleInput"};
		itemSize[]={4,4};
		quantityBar = 1;
		stackedUnit = "percentage";
		varTemperatureMin=0;
		varTemperatureMax=50;
		varQuantityInit=0;
		varQuantityMin=0;
		varQuantityMax=50;
		varQuantityDestroyOnMin=1;
		varStackMax=0;
		rotationFlags=2;
		openable=0;
		heavyItem=1;
		itemBehaviour = 2;
		weight=45;
		carveNavmesh=0;

	};
	class ND_ClayCrucibleOreCopper  : ND_ClayCrucibleBase
	{
		scope=2;
		displayName="Clay Crucible with copper ore";
		descriptionShort="Crucible Filled with Copper Ore";
		model="\Dumpgrah\Assets\Furance_colorbase\ClayCrucibleOreCopper.p3d";
			//	overrideDrawArea="3.0";
	    inventorySlot[]={"CrucibleInput"};
		itemSize[]={4,4};
		quantityBar = 1;
		stackedUnit = "percentage";
		varTemperatureMin=0;
		varTemperatureMax=50;
		varQuantityInit=0;
		varQuantityMin=0;
		varQuantityMax=50;
		varQuantityDestroyOnMin=1;
		varStackMax=0;
		rotationFlags=2;
		openable=0;
		heavyItem=1;
		itemBehaviour = 2;
		weight=45;
		carveNavmesh=0;

	};
	class ND_ClayCrucibleOreZinc : ND_ClayCrucibleBase 
	{
		scope=2;
		displayName="Clay Crucible with zinc ore";
		descriptionShort="Crucible Filled with Zinc Ore";
		model="\Dumpgrah\Assets\Furance_colorbase\ClayCrucibleOreZinc.p3d";
			//	overrideDrawArea="3.0";
	    inventorySlot[]={"CrucibleInput","CrucibleInput1"};
		itemSize[]={4,4};
		quantityBar = 1;
		stackedUnit = "percentage";
		varTemperatureMin=0;
		varTemperatureMax=50;
		varQuantityInit=0;
		varQuantityMin=0;
		varQuantityMax=50;
		varQuantityDestroyOnMin=1;
		varStackMax=0;
		rotationFlags=2;
		openable=0;
		heavyItem=1;
		itemBehaviour = 2;
		weight=45;
		carveNavmesh=0;

	};
	class ND_ClayCruciblePureIron : ND_ClayCrucibleBase 
	{
		scope=2;
		displayName="Clay Crucible with Pure Iron";
		descriptionShort="Crucible Filled with Pure Iron Ingot.";
		model="\Dumpgrah\Assets\Furance_colorbase\Forge\PureIronFilledClayCrucible.p3d";
			//	overrideDrawArea="3.0";
	    inventorySlot[]={"CrucibleInput"};
		itemSize[]={4,4};
		quantityBar = 1;
		stackedUnit = "percentage";
		varTemperatureMin=0;
		varTemperatureMax=50;
		varQuantityInit=0;
		varQuantityMin=0;
		varQuantityMax=50;
		varQuantityDestroyOnMin=1;
		varStackMax=0;
		rotationFlags=2;
		openable=0;
		heavyItem=1;
		itemBehaviour = 2;
		weight=45;
		carveNavmesh=0;

	};
	class ND_ClayCrucibleOreIron : ND_ClayCrucibleBase 
	{
		scope=2;
		displayName="Clay Crucible with Iron ore";
		descriptionShort="Crucible Filled with Iron Ore";
		model="\Dumpgrah\Assets\Furance_colorbase\ClayCrucibleOreIron.p3d";
			//	overrideDrawArea="3.0";
	    inventorySlot[]={"CrucibleInput"};
		itemSize[]={4,4};
		quantityBar = 1;
		stackedUnit = "percentage";
		varTemperatureMin=0;
		varTemperatureMax=50;
		varQuantityInit=0;
		varQuantityMin=0;
		varQuantityMax=50;
		varQuantityDestroyOnMin=1;
		varStackMax=0;
		rotationFlags=2;
		openable=0;
		heavyItem=1;
		itemBehaviour = 2;
		weight=45;
		carveNavmesh=0;

	};
	class ND_ClayCrucibleOreLead : ND_ClayCrucibleBase 
	{
		scope=2;
		displayName="Clay Crucible with Lead ore";
		descriptionShort="Crucible Filled with Lead Ore";
		model="\Dumpgrah\Assets\Furance_colorbase\ClayCrucibleOreLead.p3d";
			//	overrideDrawArea="3.0";
	    inventorySlot[]={"CrucibleInput"};
		itemSize[]={4,4};
		quantityBar = 1;
		stackedUnit = "percentage";
		varTemperatureMin=0;
		varTemperatureMax=50;
		varQuantityInit=0;
		varQuantityMin=0;
		varQuantityMax=50;
		varQuantityDestroyOnMin=1;
		varStackMax=0;
		rotationFlags=2;
		openable=0;
		heavyItem=1;
		itemBehaviour = 2;
		weight=45;
		carveNavmesh=0;

	};
	class ND_ClayCrucibleMoltenCopper  : ND_ClayMoltenCrucible 
	{
		scope=2;
		displayName="Clay Crucible with molten copper";
		descriptionShort="Crucible Filled with Molten Copper";
		model="\Dumpgrah\Assets\Furance_colorbase\ClayMoltenCopper.p3d";
	//	overrideDrawArea="3.0";
	    inventorySlot[]={"CrucibleOutput"};
		itemSize[]={4,4};
		quantityBar = 1;
		stackedUnit = "percentage";
		varTemperatureMin=0;
		varTemperatureMax=500;
		varLiquidTypeInit=600;
		liquidContainerType="1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256 + 512 + 1024 + 2048 + 4096 + 8192 + 16384 + 32768 + 65536  - (1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256)";
		varQuantityInit=50;
		varQuantityMin=0;
		varQuantityMax=50;
		varQuantityDestroyOnMin=1;
		varStackMax=0;
		rotationFlags=2;
		openable=0;
		heavyItem=1;
		itemBehaviour = 2;
		weight=45;
		carveNavmesh=0;

	};
	class  ND_ClayCrucibleMoltenZinc : ND_ClayMoltenCrucible 
	{
		scope=2;
		displayName="Clay Crucible with molten zinc";
		descriptionShort="Crucible Filled with Molten zinc";
		model="\Dumpgrah\Assets\Furance_colorbase\ClayMoltenZinc.p3d";
	//	overrideDrawArea="3.0";
	    inventorySlot[]={"CrucibleOutput"};
		itemSize[]={4,4};
		quantityBar = 1;
		stackedUnit = "percentage";
		varTemperatureMin=0;
		varTemperatureMax=500;
		varLiquidTypeInit=600;
		liquidContainerType="1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256 + 512 + 1024 + 2048 + 4096 + 8192 + 16384 + 32768 + 65536  - (1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256)";
		varQuantityInit=50;
		varQuantityMin=0;
		varQuantityMax=50;
		varQuantityDestroyOnMin=1;
		varStackMax=0;
		rotationFlags=2;
		openable=0;
		heavyItem=1;
		itemBehaviour = 2;
		weight=45;
		carveNavmesh=0;

	};
	class ND_ClayCrucibleMoltenBrass  : ND_ClayMoltenCrucible 
	{
		scope=2;
		displayName="Clay Crucible with molten brass";
		descriptionShort="Crucible Filled with Molten Brass";
		model="\Dumpgrah\Assets\Furance_colorbase\ClayMoltenBrass.p3d";
	//	overrideDrawArea="3.0";
	    inventorySlot[]={"CrucibleOutput","CrucibleInput"};
		itemSize[]={4,4};
		quantityBar = 1;
		stackedUnit = "percentage";
		varTemperatureMin=0;
		varTemperatureMax=500;
		varLiquidTypeInit=600;
		liquidContainerType="1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256 + 512 + 1024 + 2048 + 4096 + 8192 + 16384 + 32768 + 65536  - (1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256)";
		varQuantityInit=50;
		varQuantityMin=0;
		varQuantityMax=50;
		varQuantityDestroyOnMin=1;
		varStackMax=0;
		rotationFlags=2;
		openable=0;
		heavyItem=1;
		itemBehaviour = 2;
		weight=45;
		carveNavmesh=0;

	};
	class ND_ClayCrucibleMoltenIron  : ND_CrucibleBase
	{
		scope=2;
		displayName="Clay Crucible with molten Iron";
		descriptionShort="Crucible Filled with Molten Iron";
		model="\Dumpgrah\Assets\Furance_colorbase\ClayMoltenIron.p3d";
	//	overrideDrawArea="3.0";
	    inventorySlot[]={"CrucibleOutput"};
		itemSize[]={4,4};
		quantityBar = 1;
		stackedUnit = "percentage";
		varTemperatureMin=0;
		varTemperatureMax=1650;
		varLiquidTypeInit=600;
		liquidContainerType="1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256 + 512 + 1024 + 2048 + 4096 + 8192 + 16384 + 32768 + 65536  - (1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256)";
		varQuantityInit=50;
		varQuantityMin=0;
		varQuantityMax=50;
		varQuantityDestroyOnMin=1;
		varStackMax=0;
		rotationFlags=2;
		openable=0;
		heavyItem=1;
		itemBehaviour = 2;
		weight=45;
		carveNavmesh=0;
	};
	class ND_ClayCrucibleMoltenImpureIron  : ND_CrucibleBase
	{
		scope=2;
		displayName="Clay Crucible with molten Iron";
		descriptionShort="Crucible Filled with Molten Iron";
		model="\Dumpgrah\Assets\Furance_colorbase\ClayMoltenIron.p3d";
	//	overrideDrawArea="3.0";
	    inventorySlot[]={"CrucibleOutput"};
		itemSize[]={4,4};
		quantityBar = 1;
		stackedUnit = "percentage";
		varTemperatureMin=0;
		varTemperatureMax=1650;
		varLiquidTypeInit=600;
		liquidContainerType="1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256 + 512 + 1024 + 2048 + 4096 + 8192 + 16384 + 32768 + 65536  - (1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256)";
		varQuantityInit=50;
		varQuantityMin=0;
		varQuantityMax=50;
		varQuantityDestroyOnMin=1;
		varStackMax=0;
		rotationFlags=2;
		openable=0;
		heavyItem=1;
		itemBehaviour = 2;
		weight=45;
		carveNavmesh=0;
	};
	class ND_ClayCrucibleMoltenPigIron : ND_CrucibleBase 
	{
		scope=2;
		displayName="Clay Crucible with molten  Pig Iron";
		descriptionShort="Crucible Filled with Molten Iron";
		model="\Dumpgrah\Assets\Furance_colorbase\ClayMoltenIron.p3d";
	//	overrideDrawArea="3.0";
	    inventorySlot[]={"CrucibleOutput"};
		itemSize[]={4,4};
		quantityBar = 1;
		stackedUnit = "percentage";
		varTemperatureMin=0;
		varTemperatureMax=1650;
		varLiquidTypeInit=600;
		liquidContainerType="1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256 + 512 + 1024 + 2048 + 4096 + 8192 + 16384 + 32768 + 65536  - (1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256)";
		varQuantityInit=50;
		varQuantityMin=0;
		varQuantityMax=50;
		varQuantityDestroyOnMin=1;
		varStackMax=0;
		rotationFlags=2;
		openable=0;
		heavyItem=1;
		itemBehaviour = 2;
		weight=45;
		carveNavmesh=0;

	};
	class ND_ClayCrucibleMoltenLead  : ND_ClayMoltenCrucible 
	{
		scope=2;
		displayName="Clay Crucible with molten Lead";
		descriptionShort="Crucible Filled with Molten Lead";
		model="\Dumpgrah\Assets\Furance_colorbase\ClayMoltenLead.p3d";
	//	overrideDrawArea="3.0";
	    inventorySlot[]={"CrucibleOutput","CrucibleInput"};
		itemSize[]={4,4};
		quantityBar = 1;
		stackedUnit = "percentage";
		varTemperatureMin=0;
		varTemperatureMax=500;
		varLiquidTypeInit=600;
		liquidContainerType="1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256 + 512 + 1024 + 2048 + 4096 + 8192 + 16384 + 32768 + 65536  - (1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256)";
		varQuantityInit=50;
		varQuantityMin=0;
		varQuantityMax=50;
		varQuantityDestroyOnMin=1;
		varStackMax=0;
		rotationFlags=2;
		openable=0;
		heavyItem=1;
		itemBehaviour = 2;
		weight=45;
		carveNavmesh=0;

	};
	class SmelterBase : Inventory_Base{};
	class ND_ForgeBase : SmelterBase
	{
		scope=2;
		displayName="Forge";
		descriptionShort="A Forge with no roof or hood, will heat metal well but not very quickly";
		model="\Dumpgrah\Assets\Furance_colorbase\Forge\Forge.p3d";
	//	overrideDrawArea="3.0";
		hitpoints=1000;
		forceFarBubble="true";
		slopeTolerance=0.30000001;
		rotationFlags=2;
		varTemperatureMin=0;
		varTemperatureMax=1000;
		absorbency=0.30000001;
		openable=0;
		heavyItem=1;
		carveNavmesh=0;
		stackedUnit="";
		randomQuantity=0;
		varLiquidTypeInit=0;
		liquidContainerType="";
		varQuantityInit=0;
		varQuantityMin=0;
		varQuantityMax=0;
		allowOwnedCargoManipulation=0;
		simpleHiddenSelections[] = {"Base","HotCoals","HotCoalsBurning"};
		lootTag[]=
		{
			"Camping"
		};
		lootCategory="Tools";
		weight=27500;
		itemSize[]={11,13};
		physLayer = "item_large";
		itemBehaviour = 2;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=64;
					healthLevels[]=
					{
						
						{
							1.0,
							
							{
								""
							}
						},
						
						{
							0.69999999,
							
							{
								""
							}
						},
						
						{
							0.5,
							
							{
								""
							}
						},
						
						{
							0.30000001,
							
							{
								""
							}
						},
						
						{
							0.0,
							
							{
								""
							}
						}
					};
				};
			};
		};
		class Cargo
		{
			itemsCargoSize[]={0,0};
			openable=0;
			allowOwnedCargoManipulation=0;
		};
		attachments[]=
		{

			"ND_Coal",
			"ND_Forge_Coal",
			"ForgeMetal"
		};
		class GUIInventoryAttachmentsProps
		{
			class Fuel
			{
				name="Coal";
				description="";
				attachmentSlots[]=
				{
					"ND_Coal"
				};
				ghostIcon="set:ForgingIcons image:CoalFuel";
			};
			class CrucibleInput
			{
				name="Hearth";
				description="";
				attachmentSlots[]=
				{
					"ForgeMetal"
				};
			};
		};
		hiddenSelections[]=
		{
			"TopCoals"
		};
		hiddenSelectionsTextures[]=
		{
			"DZ\gear\cooking\data\log01burned_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"DZ\gear\cooking\data\log02burnednoemit.rvmat"
		};
		class AnimationSources
		{
			class TopCoals
			{
				source="user";
				initPhase=1;
				animPeriod=0.0099999998;
			};
		};
		class EnergyManager
		{
			switchOnAtSpawn=0;
			autoSwitchOff=1;
			autoSwitchOffWhenInCargo=1;
			energyStorageMax=0;
			energyUsagePerSecond=0.90;
			energyAtSpawn=0;
			powerSocketsCount=0;
			plugType=7;
			attachmentAction=1;
		};
	};
	class ND_ForgewHood : SmelterBase
	{
		scope=2;
		displayName="Forge with hood";
		descriptionShort="A Forge with a brick hood on it, keeps the Heat in making metal heat faster";
		model="\Dumpgrah\Assets\Furance_colorbase\Forge\ForgeComplete.p3d";
	//	overrideDrawArea="3.0";
		hitpoints=1000;
		forceFarBubble="true";
		slopeTolerance=0.30000001;
		rotationFlags=2;
		varTemperatureMin=0;
		varTemperatureMax=1400;
		absorbency=0.0;
		openable=0;
		heavyItem=1;
		carveNavmesh=0;
		stackedUnit="";
		randomQuantity=0;
		varLiquidTypeInit=0;
		liquidContainerType="";
		varQuantityInit=0;
		varQuantityMin=0;
		varQuantityMax=0;
		allowOwnedCargoManipulation=0;
		simpleHiddenSelections[] = {"Base","HotCoals","HotCoalsBurning"};
		lootTag[]=
		{
			"Camping"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=64;
					healthLevels[]=
					{
						
						{
							1.0,
							
							{
								""
							}
						},
						
						{
							0.69999999,
							
							{
								""
							}
						},
						
						{
							0.5,
							
							{
								""
							}
						},
						
						{
							0.30000001,
							
							{
								""
							}
						},
						
						{
							0.0,
							
							{
								""
							}
						}
					};
				};
			};
		};
		lootCategory="Tools";
		weight=27500;
		itemSize[]={12,13};
		physLayer = "item_large";
		itemBehaviour = 2;
		class Cargo
		{
			itemsCargoSize[]={0,0};
			openable=0;
			allowOwnedCargoManipulation=0;
		};
		attachments[]=
		{

			"ND_Coal",
			"ND_Forge_Coal",
			"ForgeMetal"
		};
		class GUIInventoryAttachmentsProps
		{
			class Fuel
			{
				name="Coal";
				description="";
				attachmentSlots[]=
				{
					"ND_Coal"
				};
				ghostIcon="set:ForgingIcons image:CoalFuel";
			};
			class CrucibleInput
			{
				name="Hearth";
				description="";
				attachmentSlots[]=
				{
					"ForgeMetal"
				};
			};
		};
		hiddenSelections[]=
		{
			"TopCoals"
		};
		hiddenSelectionsTextures[]=
		{
			"DZ\gear\cooking\data\log01burned_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"DZ\gear\cooking\data\log02burnednoemit.rvmat"
		};
		class AnimationSources
		{
			class TopCoals
			{
				source="user";
				initPhase=1;
				animPeriod=0.0099999998;
			};
		};
		class EnergyManager
		{
			switchOnAtSpawn=0;
			autoSwitchOff=1;
			autoSwitchOffWhenInCargo=1;
			energyStorageMax=0;
			energyUsagePerSecond=0.75;
			energyAtSpawn=0;
			powerSocketsCount=0;
			plugType=7;
			attachmentAction=1;
		};
	};
	class ND_Smelter : SmelterBase
	{
		scope=2;
		displayName="Simple Smelter";
		descriptionShort="Simple smelter used for melting down metals from ores to basic objects, seems i can control the heat just enough to maybe make some a basic alloy";
		model="\Dumpgrah\Assets\Furance_colorbase\smelter.p3d";
	//	overrideDrawArea="3.0";
		hitpoints=1000;
		forceFarBubble="true";
		slopeTolerance=0.30000001;
		rotationFlags=2;
		varTemperatureMin=0;
		varTemperatureMax=1650;
		absorbency=0.30000001;
		openable=0;
		heavyItem=1;
		carveNavmesh=0;
		stackedUnit="";
		randomQuantity=0;
		varLiquidTypeInit=0;
		liquidContainerType="";
		varQuantityInit=0;
		varQuantityMin=0;
		varQuantityMax=0;
		allowOwnedCargoManipulation=0;
		lootTag[]=
		{
			"Camping"
		};
		lootCategory="Tools";
		weight=27500;
		itemSize[]={10,13};
		physLayer = "item_large";
		itemBehaviour = 2;
		class Cargo
		{
			itemsCargoSize[]={0,0};
			openable=0;
			allowOwnedCargoManipulation=0;
		};
		attachments[]=
		{

			"ND_Coal",
			"CrucibleInput",
			"CrucibleInput1",
			"CrucibleOutput",
			"CrucibleEmpty"
		};
		class GUIInventoryAttachmentsProps
		{
			class Fuel
			{
				name="Coal";
				description="";
				attachmentSlots[]=
				{
					"ND_Coal"
				};
				ghostIcon="set:ForgingIcons image:CoalFuel";
			};
			class CrucibleInput
			{
				name="Smelter Chamber";
				description="";
				attachmentSlots[]=
				{
					"CrucibleInput",
					"CrucibleInput1"
				};
			};
			class CrucibleOutput
			{
				name="Smelter Output";
				description="";
				attachmentSlots[]=
				{
					"CrucibleOutput",
					"CrucibleEmpty"
				};
			};
		};
		class EnergyManager
		{
			switchOnAtSpawn=0;
			autoSwitchOff=1;
			autoSwitchOffWhenInCargo=1;
			energyStorageMax=0;
			energyUsagePerSecond=0.80;
			energyAtSpawn=0;
			powerSocketsCount=0;
			plugType=7;
			attachmentAction=1;
		};
	};
	class ND_SimpleSmelterDestroyed : Inventory_Base
	{
		scope=2;
		displayName="Destroyed Smelter";
		descriptionShort=" A destroyed smelter, someone smashed this really good";
		model="\Dumpgrah\Assets\Furance_colorbase\SimpleSmelterDestroyed.p3d";
	    //overrideDrawArea="3.0";
		forceFarBubble="true";
		slopeTolerance=0.30000001;
		rotationFlags=2;
		varTemperatureMin=1;
		varTemperatureMax=1650;
		absorbency=0.0;
		openable=0;
		heavyItem=1;
		carveNavmesh=0;
		stackedUnit="";
		randomQuantity=0;
		varLiquidTypeInit=0;
		liquidContainerType="";
		varQuantityInit=0;
		varQuantityMin=0;
		varQuantityMax=0;
		physLayer = "item_large";
		itemBehaviour = 2;
		class Cargo
		{
			itemsCargoSize[]={0,0};
			openable=0;
			allowOwnedCargoManipulation=0;
		};
	};
	class ND_ImprovedSmelterDestroyed : Inventory_Base
	{
		scope=2;
		displayName="Destroyed Smelter";
		descriptionShort=" A destroyed smelter, someone smashed this really good";
		model="\Dumpgrah\Assets\Furance_colorbase\ImprovedFurnaceDestroyed.p3d";
	    //overrideDrawArea="3.0";
		forceFarBubble="true";
		slopeTolerance=0.30000001;
		rotationFlags=2;
		varTemperatureMin=0;
		varTemperatureMax=1650;
		absorbency=0.30000001;
		openable=0;
		heavyItem=1;
		carveNavmesh=0;
		stackedUnit="";
		randomQuantity=0;
		varLiquidTypeInit=0;
		liquidContainerType="";
		varQuantityInit=0;
		varQuantityMin=0;
		varQuantityMax=0;
		physLayer = "item_large";
		itemBehaviour = 2;
		class Cargo
		{
			itemsCargoSize[]={0,0};
			openable=0;
			allowOwnedCargoManipulation=0;
		};
	};
	class ND_ImprovedSmelter : SmelterBase
	{
		scope=2;
		displayName="Smelter";
		descriptionShort="Smelter used for melting down metals from ores to basic objects, seems i can control the heat just enough to maybe make some a basic alloy";
		model="\Dumpgrah\Assets\Furance_colorbase\ImprovedFurnace.p3d";
	//	overrideDrawArea="3.0";
		hitpoints=1000;
		forceFarBubble="true";
		slopeTolerance=0.30000001;
		rotationFlags=2;
	//	varTemperatureMin=0;
		varTemperatureMax=1800;
		absorbency=0.0;
		openable=0;
		heavyItem=1;
		carveNavmesh=0;
		weight=250000‬;
		itemSize[]={10,13};
		physLayer = "item_large";
		itemBehaviour = 2;
		class Cargo
		{
			itemsCargoSize[]={0,0};
			openable=0;
			allowOwnedCargoManipulation=0;
		};
		attachments[]=
		{
	
			"ND_Coal",
			"CrucibleInput",
			"CrucibleInput1",
			"CrucibleOutput",
			"CrucibleEmpty"
		};
		class GUIInventoryAttachmentsProps
		{
			class Fuel
			{
				name="Coal";
				description="";
				attachmentSlots[]=
				{
					"ND_Coal"
				};
				ghostIcon="set:ForgingIcons image:CoalFuel";
			};
			class CrucibleInput
			{
				name="Smelter Chamber";
				description="";
				attachmentSlots[]=
				{
					"CrucibleInput",
					"CrucibleInput1"
				};
			};
			class CrucibleOutput
			{
				name="Smelter Output";
				description="";
				attachmentSlots[]=
				{
					"CrucibleOutput",
					"EmptyCrucible"
				};
			};
		};
		class EnergyManager
		{
			switchOnAtSpawn=0;
			autoSwitchOff=1;
			autoSwitchOffWhenInCargo=1;
			energyStorageMax=0;
			energyUsagePerSecond=0.65;
			energyAtSpawn=0;
			powerSocketsCount=0;
			plugType=7;
			attachmentAction=1;
		};
	};
};

