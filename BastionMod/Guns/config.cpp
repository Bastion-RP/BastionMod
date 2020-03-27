class CfgPatches
{
	class BastionRP_Guns
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
		};
	};
};
class CfgMods
{
	class BastionRP_Guns
	{
		dir="";
		picture="";
		action="";
		hideName=1;
		hidePicture=1;
		name="BastionRP_Guns";
		credits="Hop";
		author="Hop";
		authorID="0";
		version="1.0";
		extra=0;
		type="mod";
		dependencies[]=
		{
			"World"
		};
		class defs
		{
			class worldScriptModule
			{
				value="";
				files[]=
				{
					"BastionMod\Guns\scripts\4_world"
				};
			};
		};
	};
};
