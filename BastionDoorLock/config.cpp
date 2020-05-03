class CfgPatches
{
	class BastionDoorLock
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
	};
};
class CfgMods
{
	class BastionDoorLock
	{
		dir = "BastionDoorLock";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "BastionDoorLock";
		credits = "RoomService";
		author = "RoomService";
		authorID = "0";
		version = "1.0";
		extra = 0;
		type = "mod";
		dependencies[] = {"Game","World","Mission"};
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = {"BastionMod/BastionDoorLock/scripts/3_Game"};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"BastionMod/BastionDoorLock/scripts/4_World"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"BastionMod/BastionDoorLock/scripts/5_Mission"};
			};
		};
	};
};

class CfgVehicles
{
	class Lockpick;
	class BRP_LockPick : Lockpick
	{
		scope=2;
		displayName="NCC Lockpick";
		descriptionShort="Tool to add/remove codelocks to building doors.";
		model="\dz\gear\tools\Lockpick.p3d";
		animClass="Knife";
		RestrainUnlockType=0;
		rotationFlags=17;
		isLockpick=1;
		itemSize[]={1,1};
		weight=190;
		fragility=0.0099999998;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\gear\tools\data\Lockpick.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\tools\data\Lockpick.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\tools\data\Lockpick_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\tools\data\Lockpick_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\tools\data\Lockpick_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class MeleeModes
		{
			class Default
			{
				ammo="MeleeLightBlunt";
				range=1;
			};
			class Heavy
			{
				ammo="MeleeLightBlunt_Heavy";
				range=1;
			};
			class Sprint
			{
				ammo="MeleeLightBlunt_Heavy";
				range=2.8;
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class lockpicker_move_in
				{
					soundSet="lockpicker_move_in_SoundSet";
					id=110202;
				};
				class lockpicker_move_out
				{
					soundSet="lockpicker_move_out_SoundSet";
					id=110203;
				};
				class lockpicker_loop
				{
					soundSet="lockpicker_loop_SoundSet";
					id=203;
				};
				class lockpicker_end
				{
					soundSet="lockpicker_end_SoundSet";
					id=110204;
				};
			};
		};
	};
};
