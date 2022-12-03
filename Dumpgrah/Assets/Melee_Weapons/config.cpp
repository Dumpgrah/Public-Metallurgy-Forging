class CfgPatches
{
    class MF_MeleeWeapons
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
class CfgVehicles
{	
	class Inventory_Base;

	class MF_Halbread: Inventory_Base
	{
		scope=2;
		displayName="Testing";
		descriptionShort="Testing";
		model="Dumpgrah\Assets\Melee_Weapons\Halbert\Halbred.p3d";
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
};