class CfgPatches
{
	class ForceFeeding
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]={"DZ_Data"};
	};
};

class CfgMods
{
	class ForceFeeding
	{
		dir="ForceFeeding";
		picture="";
		action="";
		hideName=1;
		hidePicture=1;
		name="ForceFeeding";
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
                files[] = {"BastionMod/BastionMisc/ForceFeeding/scripts/4_World"};
			};
		};
    };
};