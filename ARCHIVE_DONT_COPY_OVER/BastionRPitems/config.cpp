class CfgPatches
{
	class BastionRPitems
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
	class BastionRPitems
	{
		dir="BastionRPitems";
		picture="";
		action="";
		hideName=0;
		hidePicture=1;
		name="BastionRPitems";
		credits="Bastion, Swade_93";
		author="Swade_93";
		authorID="76561198281669756";
		version="1";
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
				files[]=
				{
					"BastionRPitems/Scripts/4_World"
				};
			};
		};
	};
};
