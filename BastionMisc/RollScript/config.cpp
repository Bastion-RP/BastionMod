class CfgPatches
{
	class RollScript
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]={"DZ_Data", "BastionMultiCharacters"};
	};
};

class CfgMods
{
	class RollScript
	{
		dir="RollScript";
		picture="";
		action="";
		hideName=1;
		hidePicture=1;
		name="RollScript";
		credits="";
		author="Kactet";
		authorID="0";
		version="1.0";
		extra=0;
		type="mod";
		inputs="BastionMod/BastionMisc/RollScript/inputs/modded_Inputs.xml";
        dependencies[] = {"World", "Mission"};
        
        class defs
        {
			class worldScriptModule
            {
                value = "";
                files[] = {"BastionMod/BastionMisc/RollScript/scripts/4_World"};
			};

			class missionScriptModule
            {
                value = "";
                files[] = {"BastionMod/BastionMisc/RollScript/scripts/5_Mission"};
			};
		};
    };
};

