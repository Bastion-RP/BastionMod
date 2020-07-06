class CfgPatches
{
	class IncreasedStamina
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]={"BastionMultiCharacters", "BastionDTAC"};
	};
};

class CfgMods
{
	class IncreasedStamina
	{
		dir="IncreasedStamina";
		picture="";
		action="";
		hideName=1;
		hidePicture=1;
		name="IncreasedStamina";
		credits="Kactet";
		author="Kactet";
		authorID="0";
		version="1.0";
		extra=0;
		type="mod";
        dependencies[] = {"Game"};
        
        class defs
        {
			class gameScriptModule
            {
                value = "";
                files[] = {"BastionMod/BastionMisc/IncreasedStamina/scripts/3_Game"};
			};
		};
    };
};

