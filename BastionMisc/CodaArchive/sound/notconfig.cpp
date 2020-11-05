class CfgPatches
{
	class CodaRP_Sounds
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data"
		};
	};
};

class CfgSoundShaders
{
	class base_SoundShaderFlies
	{
		range=20;
		rangeCurve="defaultLFECurve";
		volume=3;
	};

    class coda_alanwalkerfade_SoundShader: base_SoundShaderFlies  // classtag_yourname_Soundshader for naming format, can use coda or scarlett or whatever
    {
        samples[]=
        {
            
            {
                "\coda_gear\Data\coda_gear\sound\alanwalkerfade_1",  // this might need to be _1 on the end of name potentially, its not labled as such because its the first but rather I think its tag for the soundset
                1
            }
    
        };
    };

    class coda_darkmusicfatallullaby_SoundShader: base_SoundShaderFlies  // classtag_yourname_Soundshader for naming format, can use coda or scarlett or whatever
    {
        samples[]=
        {
            
            {
                "\coda_gear\Data\coda_gear\sound\darkmusicfatallullaby_1",  // this might need to be _1 on the end of name potentially, its not labled as such because its the first but rather I think its tag for the soundset
                1
            }
    
        };
    };

    class coda_onlypianoloneliness_SoundShader: base_SoundShaderFlies  // classtag_yourname_Soundshader for naming format, can use coda or scarlett or whatever
    {
        samples[]=
        {
            
            {
                "\coda_gear\Data\coda_gear\sound\onlypianoloneliness_1",  // this might need to be _1 on the end of name potentially, its not labled as such because its the first but rather I think its tag for the soundset
                1
            }
    
        };
    };

    class coda_cartoonwhywelose_SoundShader: base_SoundShaderFlies  // classtag_yourname_Soundshader for naming format, can use coda or scarlett or whatever
    {
        samples[]=
        {
            
            {
                "\coda_gear\Data\coda_gear\sound\cartoonwhywelose_1",  // this might need to be _1 on the end of name potentially, its not labled as such because its the first but rather I think its tag for the soundset
                1
            }
    
        };
    };

};

class CfgSoundSets
{
	class base_SoundSet
	{
		sound3DProcessingType="defaultLFECurve";
		spatial=1;
		doppler=0;
		loop=0;
		volume=30;
	};

	class base_SoundSetLoop
	{
		sound3DProcessingType="defaultLFECurve";
		spatial=1;
		doppler=0;
		loop=1;
	};


    class coda_alanwalkerfade_SoundSet: base_SoundSet //same naming convention as above but SoundSet instead of Soundshader
    {
        soundShaders[]=
        {
            "coda_alanwalkerfade_SoundShader" //name copied from above entry
        };
    };

    class coda_darkmusicfatallullaby_SoundSet: base_SoundSet //same naming convention as above but SoundSet instead of Soundshader
    {
        soundShaders[]=
        {
            "coda_darkmusicfatallullaby_SoundShader" //name copied from above entry
        };
    };

    class coda_onlypianoloneliness_SoundSet: base_SoundSet //same naming convention as above but SoundSet instead of Soundshader
    {
        soundShaders[]=
        {
            "coda_onlypianoloneliness_SoundShader" //name copied from above entry
        };
    };

    class coda_cartoonwhywelose_SoundSet: base_SoundSet //same naming convention as above but SoundSet instead of Soundshader
    {
        soundShaders[]=
        {
            "coda_cartoonwhywelose_SoundShader" //name copied from above entry
        };
    };

};
