class CfgPatches
{
	class HackingScript
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
	};
};

class CfgMods
{
	class HackingScript
	{
		dir = "HackingScript";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "HackingScript";
		credits = "Kactet";
		author = "Kactet";
		authorID = "0";
		version = "1.0";
		extra = 0;
		type = "mod";
		dependencies[] = {"Game","World","Mission"};
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = {"BastionMod/BastionMisc/HackingScript/scripts/4_World"};
			};
		};
	};
};

#include "sounds\CfgSounds.hpp"