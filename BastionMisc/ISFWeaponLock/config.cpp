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
class CfgSoundShaders
{
	class Custom_SoundShader_Base
	{
		range = 30;
	};
	
	class ISFW_UnauthorizedAccess_SoundShader: Custom_SoundShader_Base
	{
		samples[] = {{"BastionMod\BastionMisc\ISFWeaponLock\sounds\unauthorizedaccess.ogg",1}};
		volume = 1;
	};
};
class CfgSoundSets
{
	class Custom_SoundSet_Base
	{
		sound3DProcessingType = "character3DProcessingType";
		volumeCurve = "characterAttenuationCurve";
		spatial = 1;
		doppler = 0;
		loop = 0;
	};
	class ISFW_UnauthorizedAccess_SoundSet: Custom_SoundSet_Base
	{
		soundShaders[] = {"ISFW_UnauthorizedAccess_SoundShader"};
		frequencyRandomizer = 0;
		volumeRandomizer = 0;
		volume = 1;
	};
};

