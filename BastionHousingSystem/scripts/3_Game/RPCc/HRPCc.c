enum HRPC
{
	SEND_HOUSE_DATA = -074087,
	SEND_ADMINS_ID,
	SEND_BRP_HOUSES,
	SEND_HOUSES_DATA,
	SEND_RESPONSE,

	REQUEST_HOUSE_DATA,
	REQUEST_ADD_HOUSE_INFO,
	REQUEST_RENT_HOUSE,
	REQUEST_APPROVAL_LEASE,
	REQUEST_EVICT_PLAYER,
	REQUEST_ADD_DOOR_GUEST,
	REQUEST_REMOVE_REQUEST,
	REQUEST_EDIT_DOOR_INFO,
	REQUEST_ADD_GUEST_TO_DOOR,
	REQUEST_CANCEL_LEASE,
	REQUEST_ADD_NEW_GROUP,
	REQUEST_EDIT_GROUP_INFO,
	REQUEST_DELETE_GROUP,
	REQUEST_BRP_HOUSES,
	REQUEST_HOUSES_DATA,
	REQUEST_ALLOW_SUGGEST,
	REQUEST_DENY_SUGGEST,
	REQUEST_PAY_RENT,
	
}

enum HouseResponse
{
	//general
	NECredits = 1, //not enough credits
	Success,
	Unsuccess,

	//specific
	NLBAccount, // not logged in bank acc
}

enum ActionMenu
{
	AdminManageBuildingDirectly = 0,  // directly mean with game action (F)
	ShowRentalConditionsDirectly,
	ShowInfoDirectly, // for owner
	ShowRentInfo,

	RemoteAdminManageBuildingWithTerminal,
	RemoteManageBuildingTerminal,
}
