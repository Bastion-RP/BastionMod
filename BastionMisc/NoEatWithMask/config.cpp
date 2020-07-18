class CfgPatches
{
	class NoEatWithMask
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]={"DZ_Data"};
	};
};

class CfgMods
{
	class NoEatWithMask
	{
		dir="NoEatWithMask";
		picture="";
		action="";
		hideName=1;
		hidePicture=1;
		name="NoEatWithMask";
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
                files[] = {"BastionMod/BastionMisc/NoEatWithMask/scripts/4_World"};
			};
		};
    };
};

