class CfgPatches
{
    class ND_AM_Patch
    {
        units[] =
		{
			""
		};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[]={};

    };
};
class CfgVehicles
{
	class CrucibleBase;
	class CrucibleMoltenBrass : CrucibleBase
	{
	    inventorySlot[]+={"CrucibleOutput"};
	};
	class CrucibleMoltenLead : CrucibleBase
	{
		inventorySlot[]+={"CrucibleOutput"};
	};
};