class CfgPatches
{
	class SearchTheCorpse_scripts
	{
		requiredAddons[]=
		{
			"DZ_Data"
		};
	};
};
class CfgMods
{
	class SearchTheCorpse
	{
		type="mod";
		author="DeAth[mouse]";
		dependencies[]=
		{
			"Game",
			"World",
			"Mission"
		};
		dir="SearchTheCorpse";
		name="Search The Corpse";
		version="1.0.5";
		authorID="76561198177819635";
		class defs
		{
			class gameScriptModule
			{
				value="";
				files[]=
				{
					"SearchTheCorpse\scripts\3_Game"
				};
			};
			class worldScriptModule
			{
				value="";
				files[]=
				{
					"SearchTheCorpse\scripts\4_World"
				};
			};
			class missionScriptModule
			{
				value="";
				files[]=
				{
					"SearchTheCorpse\scripts\5_Mission"
				};
			};
		};
	};
};
