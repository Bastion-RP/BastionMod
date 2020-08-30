class CfgPatches
{
	class HardCoreBackPack_scripts
	{
		requiredAddons[]={};
	};
};
class CfgMods
{
	class HardCoreBackPack
	{
		type="mod";
		author="DeAth[mouse]";
		dir="HardCoreBackPack";
		name="Hardcore BackPack";
		credits="DeAth[mouse]";
		version="1.0.3";
		authorID="76561198177819635";
		dependencies[]=
		{
			"World"
		};
		class defs
		{
			class gameScriptModule
			{
				value="";
				files[]=
				{
					"HardCoreBackPack/scripts/3_Game"
				};
			};
			class worldScriptModule
			{
				value="";
				files[]=
				{
					"HardCoreBackPack/scripts/4_World"
				};
			};
			class missionScriptModule
			{
				value="";
				files[]=
				{
					"HardCoreBackPack/scripts/5_Mission"
				};
			};
		};
	};
};
