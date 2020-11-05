class CfgPatches
{
	class KickedPlayer_scripts
	{
		requiredAddons[]=
		{
			"DZ_Data"
		};
	};
};
class CfgMods
{
	class KickedPlayer
	{
		type="mod";
		author="DeAth[mouse]";
		dependencies[]=
		{
			"Game",
			"World",
			"Mission"
		};
		dir="KickedPlayer";
		name="KickedPlayer";
		version="1.0.5";
		authorID="76561198177819635";
		class defs
		{
			class gameScriptModule
			{
				value="";
				files[]=
				{
					"BastionMod\BastionMisc\KickedPlayer\scripts\3_Game"
				};
			};
			class worldScriptModule
			{
				value="";
				files[]=
				{
					"BastionMod\BastionMisc\KickedPlayer\scripts\4_World"
				};
			};
			class missionScriptModule
			{
				value="";
				files[]=
				{
					"BastionMod\BastionMisc\KickedPlayer\scripts\5_Mission"
				};
			};
		};
	};
};
