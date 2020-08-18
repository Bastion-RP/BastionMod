class CfgPatches
{
	class PackStation
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]={"DZ_Data"};
	};
};

class CfgMods
{
	class PackStation
	{
		dir="PackStation";
		picture="";
		action="";
		hideName=1;
		hidePicture=1;
		name="PackStation";
		credits="RoomService";
		author="RoomService";
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
                files[] = {"BastionMod/BastionMisc/PackStation/scripts/4_World"};
			};
		};
    };
};