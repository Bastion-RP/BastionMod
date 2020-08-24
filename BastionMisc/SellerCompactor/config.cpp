class CfgPatches
{
	class SellerCompactor
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]={};
	};
};

class CfgMods
{
	class SellerCompactor
	{
		dir="SellerCompactor";
		picture="";
		action="";
		hideName=1;
		hidePicture=1;
		name="SellerCompactor";
		credits="Kactet";
		author="Kactet";
		authorID="0";
		version="1.0";
		extra=0;
		type="mod";
        dependencies[] = {"Game", "World"};
        
        class defs
        {
			class gameScriptModule
            {
                value = "";
                files[] = {"BastionMod/BastionMisc/SellerCompactor/scripts/3_Game"};
			};

			class worldScriptModule
            {
                value = "";
                files[] = {"BastionMod/BastionMisc/SellerCompactor/scripts/4_World"};
			};
		};
    };
};

