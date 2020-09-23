class CfgPatches
{
	class GrenadeLog
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data", "BastionRemoteIED"};
	};
};
class CfgMods
{
	class GrenadeLog
	{
		dir = "GrenadeLog";
		picture = "";
		action = "";
		hideName = 0;
		hidePicture = 0;
		name = "";
		authorID = "0";
		version = "0.1";
		extra = 0;
		type = "mod";
		dependencies[] = {"World"};
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = {"BastionMod/BastionMisc/GrenadeLog/scripts/4_world"};
			};
		};
	};
};
