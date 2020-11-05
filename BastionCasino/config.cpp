class CfgPatches
{
	class BastionCasino
	{
		units[]={};
        weapons[]={};
        requiredVersion=1.0;
        requiredAddons[]={
			"BastionCasino_Data",
            "JM_CF_Scripts"
        };
	};
};


class CfgMods
{
	class BastionCasino
	{
		inputs = "BastionMod\BastionCasino\inputs.xml";
		dir = "BastionCasino";
		name = "Bastion Casino";
		credits = "TheBuster";
		author = "TheBuster";
		authorID = "0";
		version = "0.1";
		extra = 0;
		type = "mod";
		
		dependencies[] = {"Game", "World", "Mission"};

		class defs
		{
            class gameScriptModule
            {
                value="";
                files[]=
                {
                    "BastionMod\BastionCasino\scripts\3_Game"
                };
            };

            class worldScriptModule
            {
                value="";
                files[]=
                {
                    "BastionMod\BastionCasino\scripts\4_World"
                };
            };
			class missionScriptModule
			{
				value = "";
				files[] = {
				    "BastionMod\BastionCasino\scripts\5_Mission"
				};
			};
		};
	};
};
