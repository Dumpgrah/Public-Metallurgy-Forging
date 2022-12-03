class CfgPatches
{
    class SurivalResources
    {
        units[] =
		{
			""
		};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] = 
		{
			"DZ_Data"
		};
    };
};
class CfgMods
{
	class ND_SurivalResources
	{
		dir="SurivalResources";
		name="Resources";
		credits="Dumpgrah";
		author="Dumpgrah";
		authorID="0";
		version="1.0";
		extra=0;
		type="mod";
		dependencies[]=
		{
			"World"
		};
		class defs
		{
			class worldScriptModule
			{
				value="";
				files[]=
				{
					"SurvivalResources\Scripts\4_World"
					
				};
			};
		};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class ClayPit: Inventory_Base
	{
		scope=2;
		model="\SurvivalResources\SurivalResources_ColorBase\ClayPit.p3d";
		physLayer = "item_large";
		forceFarBubble="true";
		slopeTolerance=0.30000001;
		varQuantityDestroyOnMin=1;
		varQuantityInit=100;
		varQuantityMin=0;
		varQuantityMax=100;
		stackedUnit = "percentage";
		quantityBar = 1;
		useEntityHierarchy = "true";
	};
	class BoulderisBoulder: Inventory_Base
	{
		scope=2;
		model="\SurvivalResources\SurivalResources_ColorBase\BoulderWhole.p3d";
		physLayer = "item_large";
		forceFarBubble="true";
		slopeTolerance=0.30000001;
		varQuantityDestroyOnMin=1;
		varQuantityInit=100;
		varQuantityMin=0;
		varQuantityMax=100;
		stackedUnit = "percentage";
		quantityBar = 1;
		useEntityHierarchy = "true";
		hiddenSelections[]=
		{
			"OreTextures"
		};
		hiddenSelectionsTextures[]=
		{
			"SurvivalResources\SurivalResources_ColorBase\Data\BoulderPlain.paa"
		};

	};
	class CoalOreBoulder : BoulderisBoulder
	{
		scope=2;
		model="\SurvivalResources\SurivalResources_ColorBase\BoulderWhole.p3d";
		physLayer = "item_large";
		forceFarBubble="true";
		slopeTolerance=0.30000001;
		varQuantityDestroyOnMin=1;
		varQuantityInit=100;
		varQuantityMin=0;
		varQuantityMax=100;
		stackedUnit = "percentage";
		quantityBar = 1;
		hiddenSelections[]=
		{
			"OreTextures"
		};
		hiddenSelectionsTextures[]=
		{
			"SurvivalResources\SurivalResources_ColorBase\Data\BoulderCoal.paa"
		};
	};
	class CopperOreBoulder : BoulderisBoulder
	{
		scope=2;
		model="\SurvivalResources\SurivalResources_ColorBase\BoulderWhole.p3d";
		physLayer = "item_large";
		forceFarBubble="true";
		slopeTolerance=0.30000001;
		varQuantityDestroyOnMin=1;
		varQuantityInit=100;
		varQuantityMin=0;
		varQuantityMax=100;
		stackedUnit = "percentage";
		quantityBar = 1;
		hiddenSelections[]=
		{
			"OreTextures"
		};
		hiddenSelectionsTextures[]=
		{
			"SurvivalResources\SurivalResources_ColorBase\Data\Bouldercopper.paa"
		};
	};
	class IronOreBoulder : BoulderisBoulder
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"SurvivalResources\SurivalResources_ColorBase\Data\BoulderIron.paa"
		};
	};
	class KimberliteOreBoulder : BoulderisBoulder
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"SurvivalResources\SurivalResources_ColorBase\Data\BoulderKimberlite.paa"
		};
	};
	class LeadOreBoulder : BoulderisBoulder
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"SurvivalResources\SurivalResources_ColorBase\Data\BoulderLead.paa"
		};
	};
	class QuartzOreBoulder : BoulderisBoulder
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"SurvivalResources\SurivalResources_ColorBase\Data\BoulderQuarts.paa"
		};
	};
	class SulfurOreBoulder : BoulderisBoulder
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"SurvivalResources\SurivalResources_ColorBase\Data\BoulderSulfur.paa"
		};
	};
	class Firewood;
	class ND_Coal: Inventory_Base
	{
		scope=2;
		displayName="Coal";
		descriptionShort="Coal is a combustible black or brownish-black sedimentary rock, formed as rock strata called coal seams. Coal is mostly carbon with variable amounts of other elements; chiefly hydrogen, sulfur, oxygen, and nitrogen. Maybe i can make a stack of this and use it for a fuel source.";
		model="\SurvivalResources\SurivalResources_ColorBase\coal.p3d";
		animClass="NoFireClass";
		weight=2000;
		absorbency=0.30000001;
		itemSize[]={2,2};
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=10;
		varQuantityDestroyOnMin=1;
		varStackMax=10;
		inventorySlot[]={"Firewood"};
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
							1.0,
							
							{
								"SurvivalResources\SurivalResources_ColorBase\Data\Coal.rvmat"
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
	};
	class BaseballBat;
	class ND_GoldNugget : Inventory_Base
	{
		scope=2;
		displayName="Gold Nugget";
		descriptionShort="A gold nugget is a naturally occurring piece of native gold. Watercourses often concentrate nuggets and finer gold in placers. Nuggets are recovered by placer mining, but they are also found in residual deposits where the gold-bearing veins or lodes are weathered. Nuggets are also found in the tailings piles of previous mining operations, especially those left by gold mining dredges.. - Wiki-ND";
		model="\SurvivalResources\SurivalResources_ColorBase\GoldNugget.p3d";
		rotationFlags=17;
		hitpoints=50;
		itemBehaviour=2;
		weight=6500;
		itemSize[]={1,2};
		varQuantityInit=0;
		varQuantityMin=0;
		varQuantityMax=10;
		canBeSplit=1;
		varQuantityDestroyOnMin=1;
		absorbency=0.69999999;
		varTemperatureMax=100;
	};
	class ND_OreGold : Inventory_Base
	{
		scope=2;
		displayName="Quarts with shiny flakes";
		descriptionShort="Citrine is a variety of quartz whose color ranges from a pale yellow to brown due to ferric impurities. The name is derived from the Latin word citrina which means yellow. Seems this one has some Bright yellow metatlic Spots . - Wiki-ND";
		model="\SurvivalResources\SurivalResources_ColorBase\GoldOre.p3d";
		rotationFlags=17;
		hitpoints=50;
		itemBehaviour=2;
		weight=6500;
		itemSize[]={2,3};
		varQuantityInit=0;
		varQuantityMin=0;
		varQuantityMax=0;
		absorbency=0.69999999;
		varTemperatureMax=100;
	};
	class ND_OreCoal : Inventory_Base
	{
		scope=2;
		displayName="Coal Ore";
		descriptionShort="Coal ore produces Coal which is valued for its energy content and since the 1880s, has been widely used to generate electricity. Steel and cement industries use coal as a fuel for extraction of iron from iron ore and for cement production. In the United Kingdom and South Africa, a coal mine and its structures are a colliery, a coal mine – a pit, and the above-ground structures – a pit head. In Australia, colliery generally refers to an underground coal mine. In the United States, colliery has been used[when?] to describe a coal mine operation, but the word's usage is less common today. - Wiki-ND";
		model="\SurvivalResources\SurivalResources_ColorBase\CoalOre.p3d";
		rotationFlags=17;
		hitpoints=50;
		itemBehaviour=2;
		weight=6500;
		itemSize[]={2,3};
		varQuantityInit=0;
		varQuantityMin=0;
		varQuantityMax=0;
		absorbency=0.69999999;
		varTemperatureMax=100;
	};
	class ND_OreCopper : Inventory_Base
	{
		scope=2;
		displayName="Copper Ore";
		descriptionShort="Copper ore produces a copper carbonate hydroxide mineral, with the formula Cu2CO3 (OH)2. This opaque, green-banded mineral crystallizes in the monoclinic crystal system, and most often forms botryoidal, fibrous, or stalagmitic masses, in fractures and deep, underground spaces, where the water table and hydrothermal fluids provide the means for chemical precipitation. Individual crystals are rare, but occur as slender to acicular prisms. Pseudomorphs after more tabular or blocky azurite crystals also occur. - Wiki-ND";
		model="\SurvivalResources\SurivalResources_ColorBase\CopperOre.p3d";
		rotationFlags=17;
		hitpoints=50;
		itemBehaviour=1;
		weight=6000;
		itemSize[]={2,2};
		varQuantityInit=0;
		varQuantityMin=0;
		varQuantityMax=0;
		absorbency=0.69999999;
		varTemperatureMax=100;
	};
	class ND_OreIron : Inventory_Base
	{
		scope=2;
		displayName="Iron Ore";
		descriptionShort="Iron ore are usually rich in iron oxides and vary in color from dark grey, bright yellow, or deep purple to rusty red. The iron is usually found in the form of magnetite. - Wiki-ND";
		model="\SurvivalResources\SurivalResources_ColorBase\IronOre.p3d";
		rotationFlags=17;
		hitpoints=50;
		itemBehaviour=2;
		weight=7000;
		itemSize[]={2,3};
		varQuantityInit=0;
		varQuantityMin=0;
		varQuantityMax=0;
		absorbency=0.69999999;
		varTemperatureMax=100;
	};
	class ND_OreKimberlite : Inventory_Base
	{
		scope=2;
		displayName="Kimberlite Ore";
		descriptionShort="Kimberlite which is an igneous rock, which sometimes contains *redacted*. It is named after the town of Kimberley in South Africa, Previously, the term kimberlite has been applied to olivine lamproites as Kimberlite II, however this has been in error. - Wiki-ND";
		model="\SurvivalResources\SurivalResources_ColorBase\KimberliteOre.p3d";
		rotationFlags=17;
		hitpoints=50;
		itemBehaviour=2;
		weight=8000;
		itemSize[]={3,4};
		varQuantityInit=0;
		varQuantityMin=0;
		varQuantityMax=0;
		absorbency=0.69999999;
		varTemperatureMax=100;
	};
	class ND_OreLead : Inventory_Base
	{
		scope=2;
		displayName="Lead Ore";
		descriptionShort="Lead ore produces Lead which is a chemical element with the symbol Pb (from the Latin plumbum) and atomic number 82. It is a heavy metal that is denser than most common materials. Lead is soft and malleable, and also has a relatively low melting point. When freshly cut, lead is silvery with a hint of blue; it tarnishes to a dull gray color when exposed to air. Lead has the highest atomic number of any stable element and three of its isotopes are endpoints of major nuclear decay chains of heavier elements. - Wiki-ND";
		model="\SurvivalResources\SurivalResources_ColorBase\LeadOre.p3d";
		rotationFlags=17;
		hitpoints=50;
		itemBehaviour=1;
		weight=7000;
		itemSize[]={2,3};
		varQuantityInit=0;
		varQuantityMin=0;
		varQuantityMax=0;
		absorbency=0.69999999;
		varTemperatureMax=100;
	};
	class ND_OreQuartz : Inventory_Base
	{
		scope=2;
		displayName="Quartz Ore";
		descriptionShort="Quartz ore produces Quartz which is a hard, crystalline mineral composed of silicon and oxygen atoms. The atoms are linked in a continuous framework of SiO4 silicon–oxygen tetrahedra, with each oxygen being shared between two tetrahedra, giving an overall chemical formula of SiO2. Quartz is the second most abundant mineral in Earth's continental crust, behind feldspar. - Wiki-ND";
		model="\SurvivalResources\SurivalResources_ColorBase\QuartzOre.p3d";
		rotationFlags=17;
		hitpoints=50;
		itemBehaviour=2;
		weight=7500;
		itemSize[]={2,3};
		varQuantityInit=0;
		varQuantityMin=0;
		varQuantityMax=0;
		absorbency=0.69999999;
		varTemperatureMax=100;
	};
	class ND_OreSulfur : Inventory_Base
	{
		scope=2;
		displayName="Sulfur Ore";
		descriptionShort="Sulfur ore produces Sulfur which is a chemical element with the symbol S and atomic number 16. It is abundant, multivalent, and nonmetallic. Under normal conditions, sulfur atoms form cyclic octatomic molecules with a chemical formula S8. Elemental sulfur is a bright yellow, crystalline solid at room temperature. - Wiki-ND ";
		model="\SurvivalResources\SurivalResources_ColorBase\SulfurOre.p3d";
		rotationFlags=17;
		hitpoints=50;
		itemBehaviour=1;
		weight=4500;
		itemSize[]={2,2};
		varQuantityInit=0;
		varQuantityMin=0;
		varQuantityMax=0;
		absorbency=0.69999999;
		varTemperatureMax=100;
	};
	class ND_OreZinc : Inventory_Base
	{
		scope=2;
		displayName="Zinc Ore";
		descriptionShort="Zinc ore produces Zinc which is a chemical element with the symbol Zn and atomic number 30. Zinc is a slightly brittle metal at room temperature and has a blue-silvery appearance when oxidation is removed. It is the first element in group 12 of the periodic table. In some respects, zinc is chemically similar to magnesium: both elements exhibit only one normal oxidation state (+2), and the Zn2+ and Mg2+ ions are of similar size. Zinc is the 24th most abundant element in Earth's crust and has five stable isotopes. The most common zinc ore is sphalerite (zinc blende), a zinc sulfide mineral. The largest workable lodes are in Australia, Asia, and the United States. Zinc is refined by froth flotation of the ore, roasting, and final extraction using electricity (electrowinning). - Wiki-ND";
		model="\SurvivalResources\SurivalResources_ColorBase\ZincOre.p3d";
		rotationFlags=17;
		hitpoints=50;
		itemBehaviour=1;
		weight=5000;
		itemSize[]={1,1};
		varQuantityInit=0;
		varQuantityMin=0;
		varQuantityMax=0;
		absorbency=0.69999999;
		varTemperatureMax=100;
	};

};