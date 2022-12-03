class CfgPatches
{
	class Dumpgrah
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Scripts"
		};
	};
};
class CfgMods
{
	class Dumpgrah
	{
		dir="Dumpgrah";
		picture="";
		action="";
		hideName=0;
		hidePicture=1;
		name="Dumpgrah";
		credits="Dumpgrah";
		author="Dumpgrah";
		authorID="0";
		version="1.25";
		extra=0;
		type="mod";
		dependencies[]=
		{
			"gui",
			"Game",
			"World",
			"Mission"
		};
		class defs
		{
			class imageSets
            {
                files[]=
                {"Dumpgrah\GUI\imagesets\ForgingIcons.imageset"};
            };
			class gameScriptModule
			{
				value="";
				files[] = 
				{ 
					"Dumpgrah/Scripts/3_Game","0_AM_Define\scripts\Common" 
				};
			};
			class worldScriptModule
			{
				value="";
				files[]=
				{
					"Dumpgrah/scripts/4_World","0_AM_Define\scripts\Common"
				};
			};
			class missionScriptModule
			{
				value="";
				files[]=
				{
					"Dumpgrah/scripts/5_Mission","0_AM_Define\scripts\Common"
				};
			};
		};
	};
};
