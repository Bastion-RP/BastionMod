class GeneralHousesData
{
	ref array<string> 				Admins = new array<string>();	// contains steamid64, they have access to all buildings
	float							MaxHoursNonPayment;
	ref array<ref HouseData>		HousesData = new array<ref HouseData>();
}

class HouseData
{
	int								Low;
	int 							High;
	string							BuldingName;
	string							BuldingDescription;
	string							BuildingPos;
	ref HousePersonData				MainOwner = new HousePersonData();
	int								LeaseTime;
	int								RentPrice;
	bool							NeedApproval;
	ref array<ref HouseDoorData>	DoorsData = new array<ref HouseDoorData>();
	ref array<int>					AllowCitizenClasses = new array<int>();
	ref array<ref RentSuggestion>	RentSuggestions = new array<ref RentSuggestion>();
}

class DefaultSorage
{
	string							Classname;
	int								Count;
}

class HousePersonData
{
	string							Name;
	string							MilticharacterID;
	string							SteamID;
	string							HashID;
	string							Date;
	string							BastionClass;
	int								BankAccountId;
	int								RentTimeLeft;

}

class HouseDoorData
{
	int								Index;
	int								RentPrice;
	ref array<ref HousePersonData>	Renters = new array<ref HousePersonData>();
	int								LeaseTime;
	string							Name;
	string							Description;
	ref array<ref RentSuggestion>	RentSuggestions = new array<ref RentSuggestion>();
}

class RentSuggestion
{
	string							Name;
	string							MilticharacterID;
	string							SteamID;
	string							HashID;
	string							Date;
	string							BastionClass;
	bool							Approved;
	bool							Checked;
}