class CfgPatches
{
	class BastionMenu
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
	};
};
class CfgMods
{
	class BastionMenu
	{
		dir = "BastionMod/BastionMenu";
		picture = "";
		action = "";
		hideName = 0;
		hidePicture = 0;
		name = "";
		credits = "";
		author = "";
		authorID = "0";
		version = "0.1";
		extra = 0;
		type = "mod";
		dependencies[] = {"Game","World","Mission"};
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = {"BastionMod/BastionMenu/scripts/3_Game"};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"BastionMod/BastionMenu/scripts/4_World"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"BastionMod/BastionMenu/scripts/5_Mission"};
			};
		};
	};
};

class CfgSoundSets
{
	class Main_Music_Menu_SoundSet
	{
		soundShaders[] = {"Main_Music_Menu_SoundShader"};
		volumeFactor = 1;
		frequencyFactor = 1;
		spatial = 0;
	};
};	
class CfgSoundShaders
{
	class Main_Music_Menu_SoundShader
	{
		samples[] = {{"BastionMod\BastionMenu\gui\sound\MainMenu.ogg", 1}};
		volume = 1;
	};
};