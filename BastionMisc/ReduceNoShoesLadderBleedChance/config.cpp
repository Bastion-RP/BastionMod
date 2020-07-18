class CfgPatches
{
	class ReduceNoShoesLadderBleedChance
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]={"DZ_Data"};
	};
};

class CfgMods
{
	class ReduceNoShoesLadderBleedChance
	{
		dir="ReduceNoShoesLadderBleedChance";
		picture="";
		action="";
		hideName=1;
		hidePicture=1;
		name="ReduceNoShoesLadderBleedChance";
		credits="Kactet";
		author="Kactet";
		authorID="0";
		version="1.0";
		extra=0;
		type="mod";
        dependencies[] = {"World", "Game"};
        
        class defs
        {
			class gameScriptModule
			{
				value="";
				files[] = {"BastionMod/BastionMisc/ReduceNoShoesLadderBleedChance/scripts/3_Game"};
			};
			class worldScriptModule
            {
                value = "";
                files[] = {"BastionMod/BastionMisc/ReduceNoShoesLadderBleedChance/scripts/4_World"};
			};
		};
    };
};

