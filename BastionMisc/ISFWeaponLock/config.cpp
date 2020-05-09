class CfgPatches
{
	class ISFWeaponLock
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]={"BastionMultiCharacters", "BastionDTAC"};
	};
};

class CfgMods
{
	class ISFWeaponLock
	{
		dir="ISFWeaponLock";
		picture="";
		action="";
		hideName=1;
		hidePicture=1;
		name="ISFWeaponLock";
		credits="";
		author="Cleetus";
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
                files[] = {"BastionMod/BastionMisc/ISFWeaponLock/scripts/4_World"};
			};
		};
    };
};

