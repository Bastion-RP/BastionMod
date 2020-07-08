class CfgPatches
{
	class ReduceNoShoesBleedChance
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]={"BastionMultiCharacters", "BastionDTAC"};
	};
};

class CfgMods
{
	class ReduceNoShoesBleedChance
	{
		dir="ReduceNoShoesBleedChance";
		picture="";
		action="";
		hideName=1;
		hidePicture=1;
		name="ReduceNoShoesBleedChance";
		credits="Kactet";
		author="Kactet";
		authorID="0";
		version="1.0";
		extra=0;
		type="mod";
        dependencies[] = {"World"};
        
        class defs
        {
			class worldScriptModule
            {
                value = "";
                files[] = {"BastionMod/BastionMisc/ReduceNoShoesBleedChance/scripts/4_World"};
			};
		};
    };
};

