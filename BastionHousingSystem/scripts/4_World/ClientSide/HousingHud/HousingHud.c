class HousingHud extends UIScriptedMenu
{
	private EditBoxWidget				m_BName;
	private TextWidget					m_BPos;
	private EditBoxWidget				m_BPrice;
	private EditBoxWidget				m_BTime;

	private MultilineEditBoxWidget		m_Description;

	private ScrollWidget				m_ScrollDoors;
	private ScrollWidget				m_ScrollRequests;

	private CheckBoxWidget				m_CLA;
	private CheckBoxWidget				m_CLB;
	private CheckBoxWidget				m_CLC;
	private CheckBoxWidget				m_CLD;
	private CheckBoxWidget				m_CLS;

	private CheckBoxWidget				m_SEC0;
	private CheckBoxWidget				m_SEC1;
	private CheckBoxWidget				m_SEC2;
	private CheckBoxWidget				m_SEC3;
	private CheckBoxWidget				m_SEC4;
	private CheckBoxWidget				m_SEC5;

	private CheckBoxWidget				m_Approval;

	private MapWidget					m_MapHousePos;

	private WrapSpacerWidget			m_WrapDoor;
	private WrapSpacerWidget			m_WrapHouseRequests;

	private ButtonWidget				m_Btn_Save;
	private ButtonWidget				m_Btn_Cancel;
	private ButtonWidget				m_BtnSwitchTo3D;
	private ButtonWidget				m_BtnSwitchToMap;
	private ButtonWidget				m_BBtnSelectAll;

	private ButtonWidget				m_PlaceHolder1;
	private ButtonWidget				m_PlaceHolder2;
	private ButtonWidget				m_PlaceHolder3;

	private ButtonWidget				m_PCHBtnAllow;
	private ButtonWidget				m_PCHBtnDeny;

	private Widget						m_PanelCreateHouse;
	private Widget						m_PanelCreateHousWrap;
	private Widget						m_PanelCHRequests;

	private ItemPreviewWidget			m_HousePreview;

	private TextWidget					m_RequesterName;
	private TextWidget					m_RequesterId;
	private TextWidget					m_RequesterClass;

//========================== info panel =================================

	private Widget						m_PanelInfoForMainTenant;

	private ItemPreviewWidget			m_InfoHousePreview;
	private MultilineTextWidget			m_InfoDescription;
	private MapWidget					m_InfoMapHousePos;

	private ButtonWidget				m_InfoBtnSwitchToMap;
	private ButtonWidget				m_InfoBtnSwitchTo3D;
	private ButtonWidget				m_InfoBtnRent;
	private ButtonWidget				m_InfoBtnApproval;

	private TextWidget					m_InfoHouseName;
	private TextWidget					m_InfoPriceTxt;
	private TextWidget					m_InfoTimeTxt;
	private TextWidget					m_InfoClassTxt;

	private WrapSpacerWidget			m_InfoWrapDoors;

	private int m_characterRotationX;
	private int m_characterRotationY;
	private int m_characterScaleDelta;
	private vector m_characterOrientation;

//=========================== manage house panel ==========================

	private Widget						m_PanelManageHouse;

	private ButtonWidget				m_MHBtnInfo;			// for tabs
	private ButtonWidget				m_MHBtnDoorsControl;	// for tabs
	private ButtonWidget				m_MHBtnRequests;		// for tabs

	private Widget						m_MHPanelInfo;			// for tabs
	private Widget						m_MHPanelRequests;		// for tabs
	private Widget						m_MHPanelDoorsControl;	// for tabs

	// House info tab
	private TextWidget					m_MHTextRentDate;
	private TextWidget					m_MHTextRentTime;
	private TextWidget					m_MHTextRentPrice;
	private TextWidget					m_MHTextGuestNum;
	private TextWidget					m_MHTextDoorCount;
	private TextWidget					m_MHTextDoorRealCount;
	private TextWidget					m_MHTextHouseName;

	private MultilineTextWidget			m_MHDescription;

	private ButtonWidget				m_MHBtnPayRent;
	private ButtonWidget				m_MHBtnCancelLease;
	// ./House info tab

	// Door control tab
	private WrapSpacerWidget			m_MHWrapDoorsId;
	private WrapSpacerWidget			m_MHWrapGuestsNames;

	private Widget						m_MHPanelGuestInfo;
	private Widget						m_MHPanelEditDoorInfo;

	private TextWidget					m_MHGuestName;
	private TextWidget					m_MHGuestId;
	private TextWidget					m_MHGuestSince;
	private TextWidget					m_MHGuestClass;

	private ButtonWidget				m_MHBtnEvict;
	private ButtonWidget				m_MHBtnEditDoorInfo;

	private ButtonWidget				m_MHBtnEditDoorSave;
	private ButtonWidget				m_MHBtnEditDoorCancel;

	private EditBoxWidget				m_MHDoorName;
	private EditBoxWidget				m_MHDoorRentPrice;
	private EditBoxWidget				m_MHDoorRentTime;

	private MultilineEditBoxWidget		m_MHDescriptionDoor;
	// ./Door control tab

	// Door requst tab
	private WrapSpacerWidget			m_MHWrapReqDoors;
	private WrapSpacerWidget			m_MHWrapGuestsRequests;

	private TextWidget					m_MHReqId;
	private TextWidget					m_MHReqClass;
	private TextWidget					m_MHReqNam;

	private ButtonWidget				m_MHBtnAccept;
	private ButtonWidget				m_MHBtnDeny;

	private Widget						m_MHPanelGuestInfoRequest;
	// ./Door request tab

	// Door groups tab
	private Widget						m_MHPanelDoorGroups;

	private ButtonWidget				m_MHBtnDoorGroups;
	private ButtonWidget				m_MHBtnDoorGroupsCreate;
	private ButtonWidget				m_MHBtnDoorGroupsEdit;
	private ButtonWidget				m_MHDGBtnSave;
	private ButtonWidget				m_MHDGBtnCancel;
	private ButtonWidget				m_MHDGEditBtnSaveGroup;
	private ButtonWidget				m_MHDGEditBtnCancel;
	private ButtonWidget				m_MHDGEditBtnDeleteGroup;

	private Widget						m_MHPanelDGCreate;
	private Widget						m_MHPanelDGEdit;
	private Widget						m_MHDGPanelEdit;
	private Widget						m_MHDGPanelShowInfo;


	private EditBoxWidget				m_MHDGGroupName;
	private EditBoxWidget				m_MHDGGroupPrice;
	private EditBoxWidget				m_MHDGGroupLeaseTime;
	private EditBoxWidget				m_MHDGEditName;
	private EditBoxWidget				m_MHDGEditPrice;
	private EditBoxWidget				m_MHDGEditTime;
	private MultilineEditBoxWidget		m_MHDGDoorDescrip;
	private MultilineEditBoxWidget		m_MHDGEditDescription;

	private TextWidget					m_MHDGTxtName;
	private TextWidget					m_MHDGTxtPrice;
	private TextWidget					m_MHDGTxtTime;

	private MultilineTextWidget			m_MHDGTxtDescrip;

	private WrapSpacerWidget			m_MHDGGroupAllowDoors;
	private WrapSpacerWidget			m_MHDGListGroups;
	private WrapSpacerWidget			m_MHDGEditListDoors;
	private WrapSpacerWidget			m_MHDGTxtListDoors;
	// ./Door groups tab

//=========================== door panel =================================

	private Widget						m_PanelDoorInfo;

	private TextWidget					m_DIDoorName;
	private TextWidget					m_DIPrice;
	private TextWidget					m_DITime;
	private TextWidget					m_DIClasses;

	private WrapSpacerWidget			m_DIDoorsList;

	private MultilineTextWidget			m_DIDescription;

	private ButtonWidget				m_DIBtnRequest;

//=========================== search terminal =============================

	private Widget						m_PanelTerminalWrap;
	private EditBoxWidget				m_SearchBox;
	private ButtonWidget				m_SearchRefreshBtn;
	private WrapSpacerWidget			m_SearchHouseContainer;
	private ScrollWidget				m_SearchScroll;

	private CheckBoxWidget				m_SchCheckBoxA;
	private CheckBoxWidget				m_SchCheckBoxB;
	private CheckBoxWidget				m_SchCheckBoxC;
	private CheckBoxWidget				m_SchCheckBoxD;
	private CheckBoxWidget				m_SchCheckBoxS;

	private CheckBoxWidget				m_SchChBSec0;
	private CheckBoxWidget				m_SchChBSec1;
	private CheckBoxWidget				m_SchChBSec2;
	private CheckBoxWidget				m_SchChBSec3;
	private CheckBoxWidget				m_SchChBSec4;
	private CheckBoxWidget				m_SchChBSec5;

	private CheckBoxWidget				m_SchCheckBoxRentable;
	private CheckBoxWidget				m_SchCheckBoxOwnHouses;
	private CheckBoxWidget				m_SchCheckBoxAdminRequests;

//============================ tooltip ====================================

	private Widget						m_PanelTipHouseOwner;
	private TextWidget					m_Owner;

//============================ ./tooltip ==================================

//=========================== other =======================================

	private ref array<CheckBoxWidget>	m_DoorsIdxWidgets;
	private ref array<CheckBoxWidget>	m_SearchClasses;
	private ref array<CheckBoxWidget>	m_SearchSectors;
	private ref array<CheckBoxWidget>	m_ClassesWidget;
	private ref array<Widget>			m_ForGroupsIds;
	private ref array<Widget>			m_ForGuestStorage;

	private ref array<Widget>			m_Placeholders;

	private ref array<CheckBoxWidget>	m_SectorsWidget;

	private ref BstModal				m_BstModal;

	private int							m_Type;
	private int							m_CurrentGuestId;
	private int							m_CurrentGroupId;
	private int							m_StartGroupIdx;
	private int							m_CurrentSuggestionIdx;
	private int							COLOR_ORNG = -32760;
	private int							COLOR_TRANSPARENT = 16744456;

	private bool						IsAdmin;

	private string 						m_SearchPattern;

	PlayerBase							m_Player;

	void HousingHud(int type, int idx)
    {
        GetGame().GetMission().PlayerControlDisable(INPUT_EXCLUDE_ALL);
		m_Type = type;
		m_DoorsIdxWidgets 	= new array<CheckBoxWidget>();
		m_SectorsWidget 	= new array<CheckBoxWidget>();
		m_SearchClasses 	= new array<CheckBoxWidget>();
		m_SearchSectors 	= new array<CheckBoxWidget>();
		m_ClassesWidget 	= new array<CheckBoxWidget>();
		m_ForGuestStorage 	= new array<Widget>();
		m_ForGroupsIds 		= new array<Widget>();
		m_Placeholders 		= new array<Widget>();
		m_CurrentGuestId	= -1;
		m_CurrentGroupId	= -1;
		m_CurrentSuggestionIdx	= -1;
		IsAdmin				= false;
		m_StartGroupIdx		= g_HM.GetGroupIdxByDoorIndex(idx);
		m_Player			= PlayerBase.Cast(GetGame().GetPlayer());

		g_HM.RequestMainData();
    }

    void ~HousingHud()
    {
        GetGame().GetMission().PlayerControlEnable(true);
		g_HM.SetBuilding(NULL);
    }

	override Widget Init()
	{
		layoutRoot 				    = 	GetGame().GetWorkspace().CreateWidgets("BastionMod/BastionHousingSystem/layouts/HousingHud.layout");
        m_BName						=	EditBoxWidget.Cast(GetWid("BName"));
        m_BPos						=	TextWidget.Cast(GetWid("BPos"));
        m_BPrice					=	EditBoxWidget.Cast(GetWid("BPrice"));
        m_BTime						=	EditBoxWidget.Cast(GetWid("BTime"));

		m_Description				=	MultilineEditBoxWidget.Cast(GetWid("Description"));

		m_ScrollDoors				=	ScrollWidget.Cast(GetWid("ScrollDoors"));
		m_ScrollRequests			=	ScrollWidget.Cast(GetWid("ScrollRequests"));

		m_CLA						=	CheckBoxWidget.Cast(GetWid("CLA"));
		m_CLB						=	CheckBoxWidget.Cast(GetWid("CLB"));
		m_CLC						=	CheckBoxWidget.Cast(GetWid("CLC"));
		m_CLD						=	CheckBoxWidget.Cast(GetWid("CLD"));
		m_CLS						=	CheckBoxWidget.Cast(GetWid("CLS"));

		m_SEC0						=	CheckBoxWidget.Cast(GetWid("SEC0"));
		m_SEC1						=	CheckBoxWidget.Cast(GetWid("SEC1"));
		m_SEC2						=	CheckBoxWidget.Cast(GetWid("SEC2"));
		m_SEC3						=	CheckBoxWidget.Cast(GetWid("SEC3"));
		m_SEC4						=	CheckBoxWidget.Cast(GetWid("SEC4"));
		m_SEC5						=	CheckBoxWidget.Cast(GetWid("SEC5"));

		m_Approval					=	CheckBoxWidget.Cast(GetWid("Approval"));

		m_WrapDoor					=	WrapSpacerWidget.Cast(GetWid("WrapDoor"));
		m_WrapHouseRequests			=	WrapSpacerWidget.Cast(GetWid("WrapHouseRequests"));

		m_MapHousePos				=	MapWidget.Cast(GetWid("MapHousePos"));

		m_Btn_Save					=	ButtonWidget.Cast(GetWid("Btn_Save"));
		m_Btn_Cancel				=	ButtonWidget.Cast(GetWid("Btn_Cancel"));
		m_BtnSwitchTo3D				=	ButtonWidget.Cast(GetWid("BtnSwitchTo3D"));
		m_BtnSwitchToMap			=	ButtonWidget.Cast(GetWid("BtnSwitchToMap"));
		m_BBtnSelectAll				=	ButtonWidget.Cast(GetWid("BBtnSelectAll"));

		m_PlaceHolder1				=	ButtonWidget.Cast(GetWid("PlaceHolder1"));
		m_PlaceHolder2				=	ButtonWidget.Cast(GetWid("PlaceHolder2"));
		m_PlaceHolder3				=	ButtonWidget.Cast(GetWid("PlaceHolder3"));

		m_PCHBtnAllow				=	ButtonWidget.Cast(GetWid("PCHBtnAllow"));
		m_PCHBtnDeny				=	ButtonWidget.Cast(GetWid("PCHBtnDeny"));

		m_PanelCreateHouse			=	Widget.Cast(GetWid("PanelCreateHouse"));
		m_PanelCreateHousWrap		=	Widget.Cast(GetWid("PanelCreateHousWrap"));
		m_PanelCHRequests			=	Widget.Cast(GetWid("PanelCHRequests"));

		m_HousePreview				=	ItemPreviewWidget.Cast(GetWid("HousePreview"));

		m_RequesterName				=	TextWidget.Cast(GetWid("RequesterName"));
		m_RequesterId				=	TextWidget.Cast(GetWid("RequesterId"));
		m_RequesterClass			=	TextWidget.Cast(GetWid("RequesterClass"));

		// info panel	===================================================================

		m_PanelInfoForMainTenant	=	Widget.Cast(GetWid("PanelInfoForMainTenant"));

		m_InfoHousePreview			=	ItemPreviewWidget.Cast(GetWid("InfoHousePreview"));

		m_InfoDescription			=	MultilineTextWidget.Cast(GetWid("InfoDescription"));

		m_InfoMapHousePos 			=	MapWidget.Cast(GetWid("InfoMapHousePos"));

		m_InfoBtnSwitchToMap		=	ButtonWidget.Cast(GetWid("InfoBtnSwitchToMap"));
		m_InfoBtnSwitchTo3D			=	ButtonWidget.Cast(GetWid("InfoBtnSwitchTo3D"));
		m_InfoBtnRent				=	ButtonWidget.Cast(GetWid("InfoBtnRent"));
		m_InfoBtnApproval			=	ButtonWidget.Cast(GetWid("InfoBtnApproval"));

		m_InfoPriceTxt				=	TextWidget.Cast(GetWid("InfoPriceTxt"));
		m_InfoTimeTxt				=	TextWidget.Cast(GetWid("InfoTimeTxt"));
		m_InfoClassTxt				=	TextWidget.Cast(GetWid("InfoClassTxt"));
		m_InfoHouseName				=	TextWidget.Cast(GetWid("InfoHouseName"));

		m_InfoWrapDoors				=	WrapSpacerWidget.Cast(GetWid("InfoWrapDoors"));

		// house manage	===================================================================

		m_PanelManageHouse			=	Widget.Cast(GetWid("PanelManageHouse"));

		m_MHBtnInfo					=	ButtonWidget.Cast(GetWid("MHBtnInfo"));
		m_MHBtnDoorsControl			=	ButtonWidget.Cast(GetWid("MHBtnDoorsControl"));
		m_MHBtnRequests				=	ButtonWidget.Cast(GetWid("MHBtnRequests"));

		m_MHPanelInfo				=	Widget.Cast(GetWid("MHPanelInfo"));
		m_MHPanelRequests			=	Widget.Cast(GetWid("MHPanelRequests"));
		m_MHPanelDoorsControl		=	Widget.Cast(GetWid("MHPanelDoorsControl"));

		m_MHTextRentDate			=	TextWidget.Cast(GetWid("MHTextRentDate"));
		m_MHTextRentTime			=	TextWidget.Cast(GetWid("MHTextRentTime"));
		m_MHTextRentPrice			=	TextWidget.Cast(GetWid("MHTextRentPrice"));
		m_MHTextGuestNum			=	TextWidget.Cast(GetWid("MHTextGuestNum"));
		m_MHTextDoorCount			=	TextWidget.Cast(GetWid("MHTextDoorCount"));
		m_MHTextDoorRealCount		= 	TextWidget.Cast(GetWid("MHTextDoorRealCount"));
		m_MHTextHouseName			=	TextWidget.Cast(GetWid("MHTextHouseName"));

		m_MHDescription				=	MultilineTextWidget.Cast(GetWid("MHDescription"));

		m_MHBtnPayRent				=	ButtonWidget.Cast(GetWid("MHBtnPayRent"));
		m_MHBtnCancelLease			=	ButtonWidget.Cast(GetWid("MHBtnCancelLease"));

		m_MHWrapDoorsId				=	WrapSpacerWidget.Cast(GetWid("MHWrapDoorsId"));
		m_MHWrapGuestsNames			=	WrapSpacerWidget.Cast(GetWid("MHWrapGuestsNames"));
		m_MHPanelGuestInfo			=	Widget.Cast(GetWid("MHPanelGuestInfo"));
		m_MHPanelEditDoorInfo		=	Widget.Cast(GetWid("MHPanelEditDoorInfo"));
		m_MHGuestName				=	TextWidget.Cast(GetWid("MHGuestName"));
		m_MHGuestId					=	TextWidget.Cast(GetWid("MHGuestId"));
		m_MHGuestSince				=	TextWidget.Cast(GetWid("MHGuestSince"));
		m_MHGuestClass				=	TextWidget.Cast(GetWid("MHGuestClass"));
		m_MHBtnEvict				=	ButtonWidget.Cast(GetWid("MHBtnEvict"));
		m_MHBtnEditDoorInfo			=	ButtonWidget.Cast(GetWid("MHBtnEditDoorInfo"));


		m_MHWrapReqDoors			=	WrapSpacerWidget.Cast(GetWid("MHWrapReqDoors"));
		m_MHWrapGuestsRequests		=	WrapSpacerWidget.Cast(GetWid("MHWrapGuestsRequests"));

		m_MHReqId					=	TextWidget.Cast(GetWid("MHReqId"));
		m_MHReqClass				=	TextWidget.Cast(GetWid("MHReqClass"));
		m_MHReqNam					=	TextWidget.Cast(GetWid("MHReqNam"));

		m_MHBtnAccept				=	ButtonWidget.Cast(GetWid("MHBtnAccept"));
		m_MHBtnDeny					=	ButtonWidget.Cast(GetWid("MHBtnDeny"));

		m_MHPanelGuestInfoRequest	=	Widget.Cast(GetWid("MHPanelGuestInfoRequest"));

		m_MHBtnEditDoorSave			=	ButtonWidget.Cast(GetWid("MHBtnEditDoorSave"));
		m_MHBtnEditDoorCancel		=	ButtonWidget.Cast(GetWid("MHBtnEditDoorCancel"));

		m_MHDoorName				=	EditBoxWidget.Cast(GetWid("MHDoorName"));
		m_MHDoorRentPrice			=	EditBoxWidget.Cast(GetWid("MHDoorRentPrice"));
		m_MHDoorRentTime			=	EditBoxWidget.Cast(GetWid("MHDoorRentTime"));

		m_MHDescriptionDoor			=	MultilineEditBoxWidget.Cast(GetWid("MHDescriptionDoor"));

		// Door groups tab =======================================================

		m_MHPanelDoorGroups			=	Widget.Cast(GetWid("MHPanelDoorGroups"));
		m_MHPanelDGCreate			=	Widget.Cast(GetWid("MHPanelDGCreate"));
		m_MHPanelDGEdit				=	Widget.Cast(GetWid("MHPanelDGEdit"));
		m_MHDGPanelEdit				=	Widget.Cast(GetWid("MHDGPanelEdit"));
		m_MHDGPanelShowInfo			=	Widget.Cast(GetWid("MHDGPanelShowInfo"));

		m_MHBtnDoorGroups			=	ButtonWidget.Cast(GetWid("MHBtnDoorGroups"));
		m_MHBtnDoorGroupsCreate		=	ButtonWidget.Cast(GetWid("MHBtnDoorGroupsCreate"));
		m_MHBtnDoorGroupsEdit		=	ButtonWidget.Cast(GetWid("MHBtnDoorGroupsEdit"));
		m_MHDGBtnSave				=	ButtonWidget.Cast(GetWid("MHDGBtnSave"));
		m_MHDGBtnCancel				=	ButtonWidget.Cast(GetWid("MHDGBtnCancel"));
		m_MHDGEditBtnSaveGroup		=	ButtonWidget.Cast(GetWid("MHDGEditBtnSaveGroup"));
		m_MHDGEditBtnCancel			=	ButtonWidget.Cast(GetWid("MHDGEditBtnCancel"));
		m_MHDGEditBtnDeleteGroup	=	ButtonWidget.Cast(GetWid("MHDGEditBtnDeleteGroup"));

		m_MHDGGroupName				=	EditBoxWidget.Cast(GetWid("MHDGGroupName"));
		m_MHDGGroupPrice			=	EditBoxWidget.Cast(GetWid("MHDGGroupPrice"));
		m_MHDGGroupLeaseTime		=	EditBoxWidget.Cast(GetWid("MHDGGroupLeaseTime"));
		m_MHDGEditName				=	EditBoxWidget.Cast(GetWid("MHDGEditName"));
		m_MHDGEditPrice				=	EditBoxWidget.Cast(GetWid("MHDGEditPrice"));
		m_MHDGEditTime				=	EditBoxWidget.Cast(GetWid("MHDGEditTime"));

		m_MHDGDoorDescrip			=	MultilineEditBoxWidget.Cast(GetWid("MHDGDoorDescrip"));
		m_MHDGEditDescription		=	MultilineEditBoxWidget.Cast(GetWid("MHDGEditDescription"));

		m_MHDGTxtDescrip			=	MultilineTextWidget.Cast(GetWid("MHDGTxtDescrip"));

		m_MHDGTxtName				=	TextWidget.Cast(GetWid("MHDGTxtName"));
		m_MHDGTxtPrice				=	TextWidget.Cast(GetWid("MHDGTxtPrice"));
		m_MHDGTxtTime				=	TextWidget.Cast(GetWid("MHDGTxtTime"));

		m_MHDGGroupAllowDoors		=	WrapSpacerWidget.Cast(GetWid("MHDGGroupAllowDoors"));
		m_MHDGListGroups			=	WrapSpacerWidget.Cast(GetWid("MHDGListGroups"));
		m_MHDGEditListDoors			=	WrapSpacerWidget.Cast(GetWid("MHDGEditListDoors"));
		m_MHDGTxtListDoors			=	WrapSpacerWidget.Cast(GetWid("MHDGTxtListDoors"));
		//=========================== door panel =================================

		m_PanelDoorInfo				=	Widget.Cast(GetWid("PanelDoorInfo"));

		m_DIDoorName				=	TextWidget.Cast(GetWid("DIDoorName"));
		m_DIPrice					=	TextWidget.Cast(GetWid("DIPrice"));
		m_DITime					=	TextWidget.Cast(GetWid("DITime"));
		m_DIClasses					=	TextWidget.Cast(GetWid("DIClasses"));

		m_DIDoorsList				=	WrapSpacerWidget.Cast(GetWid("DIDoorsList"));

		m_DIDescription				=	MultilineTextWidget.Cast(GetWid("DIDescription"));

		m_DIBtnRequest				=	ButtonWidget.Cast(GetWid("DIBtnRequest"));

		//=========================== search terminal =============================

		m_PanelTerminalWrap			=	Widget.Cast(GetWid("PanelTerminalWrap"));
		m_SearchBox					=	EditBoxWidget.Cast(GetWid("SearchBox"));
		m_SearchRefreshBtn			=	ButtonWidget.Cast(GetWid("SearchRefreshBtn"));
		m_SearchHouseContainer		=	WrapSpacerWidget.Cast(GetWid("SearchHouseContainer"));
		m_SearchScroll				=	ScrollWidget.Cast(GetWid("SearchScroll"));

		m_SchCheckBoxA				=	CheckBoxWidget.Cast(GetWid("SchCheckBoxA"));
		m_SchCheckBoxB				=	CheckBoxWidget.Cast(GetWid("SchCheckBoxB"));
		m_SchCheckBoxC				=	CheckBoxWidget.Cast(GetWid("SchCheckBoxC"));
		m_SchCheckBoxD				=	CheckBoxWidget.Cast(GetWid("SchCheckBoxD"));
		m_SchCheckBoxS				=	CheckBoxWidget.Cast(GetWid("SchCheckBoxS"));

		m_SchChBSec0				=	CheckBoxWidget.Cast(GetWid("SchChBSec0"));	
		m_SchChBSec1				=	CheckBoxWidget.Cast(GetWid("SchChBSec1"));	
		m_SchChBSec2				=	CheckBoxWidget.Cast(GetWid("SchChBSec2"));	
		m_SchChBSec3				=	CheckBoxWidget.Cast(GetWid("SchChBSec3"));	
		m_SchChBSec4				=	CheckBoxWidget.Cast(GetWid("SchChBSec4"));
		m_SchChBSec5				=	CheckBoxWidget.Cast(GetWid("SchChBSec5"));

		m_SchCheckBoxRentable		=	CheckBoxWidget.Cast(GetWid("SchCheckBoxRentable"));
		m_SchCheckBoxOwnHouses		=	CheckBoxWidget.Cast(GetWid("SchCheckBoxOwnHouses"));
		m_SchCheckBoxAdminRequests	=	CheckBoxWidget.Cast(GetWid("SchCheckBoxAdminRequests"));

		m_PanelTipHouseOwner		=	Widget.Cast(GetWid("PanelTipHouseOwner"));

		m_Owner						=	TextWidget.Cast(GetWid("Owner"));

		// other		===================================================================

		m_BstModal					=	new BstModal(layoutRoot);

		FillPlaceholdersArr();
		FillSectorsArr();
		FillSearchArr();
		FillClassesWidgets();

		if (m_Type == 0)
		{
			SetupCreateHouseSetting();
			m_PanelCreateHouse.Show(true);
		}
		else if (m_Type == 1)
		{
			SetupShowInfo();
			m_PanelInfoForMainTenant.Show(true);
		}
		else if (m_Type == 2)
		{
			SetupMHPanelInfo();
			m_PanelManageHouse.Show(true);
		}
		else if (m_Type == 3)
		{
			SetupDoorInfo();
			m_PanelDoorInfo.Show(true);
			//need door panel
		}
		else if (m_Type == 5) // admin use terminal
		{
			m_PanelTerminalWrap.Show(true);
			m_PanelCreateHouse.Show(true);
			m_SchCheckBoxOwnHouses.Show(false);
			IsAdmin = true;
		}
		else if (m_Type == 6) // m_Player use terminal
		{
			m_PanelTerminalWrap.Show(true);
			m_SchCheckBoxRentable.SetChecked(true);
			m_SchCheckBoxRentable.Show(false);
			m_SchCheckBoxAdminRequests.Show(false);
			if(g_HM.m_House)
			SetupShowInfo();

			m_PanelInfoForMainTenant.Show(true);
		}

		SearchHouses();

		return layoutRoot;
	}

    Widget GetWid(string val)
	{
		return layoutRoot.FindAnyWidget(val);
	}

	override bool OnClick(Widget w, int x, int y, int button)
	{
		if (!ButtonWidget.Cast(w)) return false;
		if (w.GetUserID() == 20 ) // placeholder for editboxs
		{
			EditBoxWidget.Cast(w.GetParent()).SetText("");
			w.Show(false);
			return true;
		}
		if (w.GetUserID() == 33) // door id btn
		{
			BlockButton(w);
			FillGroupGuest(w.GetParent().GetUserID());
			FillDoorRequest(w.GetParent().GetUserID());
			return true;
		}
		if (w.GetUserID() == 67) // guest id btn
		{
			FillGroupGuestInfo(w.GetParent().GetUserID());
			FillDoorRequestInfo(w.GetParent().GetUserID());
			return true;
		}
		if (w.GetUserID() == 68) //
		{
			ShowGroupInfo(w.GetParent().GetUserID());
			return true;
		}
		if (w.GetUserID() == 777) // click on house elem in search area
		{
			ShowHouseInfo(w.GetParent().GetUserID());
			return true;
		}
		if (w.GetName() == "ModalBtnYes")
		{
			m_BstModal.OnClick(true);
		}
		if (w.GetName() == "ModalBtnNo")
		{
			m_BstModal.OnClick(false);
		}
		if (w.GetUserID() == 757) // click on request (admin)
		{
			ShowRequesterInfo(w.GetParent().GetUserID());
		}
		// if (!ButtonWidget.Cast(w)) return false;
		{
			switch (w)
			{
				case m_Btn_Save:
					SaveBuildingInfo();
				break;
				case m_Btn_Cancel:
					g_HM.CloseMenu();
				break;
				case m_InfoBtnRent:
					m_BstModal.RequestConfirm("TryRentBuilding");
				break;
				case m_InfoBtnApproval:
					g_HM.SendHouseRentRequest();
					m_InfoBtnApproval.Enable(false);
					g_HM.ShowBastionNotification("Request to rent a building has been sent");
				break;
				case m_BtnSwitchToMap:
					AddPointToMap(m_MapHousePos);
					m_HousePreview.Show(false);
					m_BtnSwitchToMap.Show(false);
					m_MapHousePos.Show(true);
					m_BtnSwitchTo3D.Show(true);
					g_HM.ShowBastionNotification("Switched to map");
				break;
				case m_BtnSwitchTo3D:
					m_MapHousePos.ClearUserMarks();
					m_MapHousePos.Show(false);
					m_BtnSwitchTo3D.Show(false);
					m_BtnSwitchToMap.Show(true);
					m_HousePreview.Show(true);
					g_HM.ShowBastionNotification("Switched to 3D");
				break;
				case m_InfoBtnSwitchToMap:
					AddPointToMap(m_InfoMapHousePos);
					m_InfoHousePreview.Show(false);
					m_InfoBtnSwitchToMap.Show(false);
					m_InfoMapHousePos.Show(true);
					m_InfoBtnSwitchTo3D.Show(true);
				break;
				case m_InfoBtnSwitchTo3D:
					m_InfoMapHousePos.ClearUserMarks();
					m_InfoMapHousePos.Show(false);
					m_InfoBtnSwitchTo3D.Show(false);
					m_InfoBtnSwitchToMap.Show(true);
					m_InfoHousePreview.Show(true);
				break;
				case m_MHBtnInfo:
					ChangePanel("info");
				break;
				case m_MHBtnDoorsControl:
					ChangePanel("dControl");
				break;
				case m_MHBtnRequests:
					ChangePanel("request");
				break;
				case m_MHBtnDoorGroups:
					ChangePanel("dGroups");
				break;
				case m_MHBtnEvict:
					g_HM.RequestEvictPlayer(m_CurrentGroupId, m_CurrentGuestId);
					g_HM.m_House.m_HouseData.GroupsData.Get(m_CurrentGroupId).Renters.Remove(m_CurrentGuestId);
					ReloadGuests();
					g_HM.ShowBastionNotification("The tenant was evicted.");
				break;
				case m_MHBtnAccept:
					g_HM.RequestAddGuestToDoor(m_CurrentGroupId, m_CurrentGuestId);
					g_HM.LocalAddGuest(m_CurrentGroupId, m_CurrentGuestId);
					ReloadRequests();
				break;
				case m_MHBtnDeny:
					g_HM.RequestRemoveRequest(m_CurrentGroupId, m_CurrentGuestId);
					ReloadRequests();
				break;
				case m_MHBtnPayRent:
					// pay rent TODO: pay rent
					g_HM.RequestPayRent();
				break;
				case m_MHBtnCancelLease:
					m_BstModal.RequestConfirm("CancelLease");
				break;
				case m_MHBtnEditDoorInfo:
					EditDoorInfo();
				break;
				case m_MHBtnEditDoorSave:
					SaveDoorInfo();
					g_HM.ShowBastionNotification("Information saved");
				case m_MHBtnEditDoorCancel:
					CancelDoorInfo();
				break;
				case m_DIBtnRequest:
					m_BstModal.RequestConfirm("ReqGroup", this);
				break;
				case m_MHBtnDoorGroupsCreate:
					CreateNewGroup();
				break;
				case m_MHDGBtnSave:
					SaveNewGroup();
				break;
				case m_MHDGBtnCancel:
					CancelCreationGroup();
				break;
				case m_MHBtnDoorGroupsEdit:
					EditGroupInfo();
				break;
				case m_MHDGEditBtnSaveGroup:
					SaveGroupEditInfo();
				break;
				case m_MHDGEditBtnCancel:
					CancelEditingGroup();
				break;
				case m_MHDGEditBtnDeleteGroup:
					DeleteGroup();
				break;
				case m_SearchRefreshBtn:
					g_HM.RequestMainData();
					m_SearchRefreshBtn.Enable(false);
					GetGame().GetCallQueue( CALL_CATEGORY_GUI ).CallLater( m_SearchRefreshBtn.Enable, 1000, false, true);
				break;
				case m_BBtnSelectAll:
					CreateSelectAllDoors();
				break;
				case m_PCHBtnAllow:
					g_HM.RequestAllowSuggestion(m_CurrentSuggestionIdx);
					LocalAllowSuggestion(m_CurrentSuggestionIdx);
				break;
				case m_PCHBtnDeny:
					g_HM.RequestDenySuggestion(m_CurrentSuggestionIdx);
					LocalDenySuggestion(m_CurrentSuggestionIdx);
				break;
			}
		}	
		return false;
	}

	void SetupCreateHouseSetting()
	{
		HouseData hd = g_HM.m_House.m_HouseData;
		m_DoorsIdxWidgets.Clear();
		ClearAllChildren(m_WrapDoor);
		m_MapHousePos.ClearUserMarks();
		ClearCheckboxes();
		AddPointToMap(m_MapHousePos);
		m_ScrollDoors.VScrollToPos01(0);
		m_HousePreview.SetItem( g_HM.m_House );
		m_HousePreview.SetView( g_HM.m_House.GetViewIndex() );
		m_HousePreview.SetModelOrientation( Vector( 0,0,0 ) );

		if (hd.BuldingName)
		m_BName.SetText(hd.BuldingName);
		else
		m_BName.SetText("Name");

		if (hd.RentPrice)
		m_BPrice.SetText(hd.RentPrice.ToString());
		else
		m_BPrice.SetText("Rent price");

		if (hd.LeaseTime)
		m_BTime.SetText(hd.LeaseTime.ToString());
		else
		m_BTime.SetText("Lease Time(in hours)");

		if (hd.BuildingSector != -1)
		CheckBoxWidget.Cast(m_SectorsWidget.Get(hd.BuildingSector)).SetChecked(true);

		if (hd.BuldingDescription)
			m_Description.SetText(hd.BuldingDescription);
		else
			m_Description.SetText("");
	
		for (int k = 0; k < hd.AllowCitizenClasses.Count(); k++)
		{
			m_ClassesWidget.Get((hd.AllowCitizenClasses.Get(k) - 1)).SetChecked(true);
		}

		for (int i = 0; i < hd.TotalDoors; i++)
		{
			CheckBoxWidget temp = CheckBoxWidget.Cast(GetGame().GetWorkspace().CreateWidgets("BastionMod/BastionHousingSystem/layouts/DoorIndex.layout", m_WrapDoor));
			temp.SetUserID(i);
			string txt = "ID ["+i+"]";
			temp.SetText(txt);
			m_DoorsIdxWidgets.Insert(temp);
			if ((hd.AllowDoors.Find(i) + 1))
			{temp.SetChecked(true);}
		}
		for (int j = 0; j < 3; j++)
		{
			m_Placeholders.Get(j).Show(true);
		}

		if (hd.NeedApproval)
		{
			m_Approval.SetChecked(true);
		}
	}

	void SetupShowInfo()
	{
		HouseData hd = g_HM.m_House.m_HouseData;
		string temp;
		m_InfoMapHousePos.ClearUserMarks();
		AddPointToMap(m_InfoMapHousePos);
		if (!hd) return;
		m_InfoHousePreview.SetItem( g_HM.m_House );
		m_InfoHousePreview.SetView( g_HM.m_House.GetViewIndex() );
		m_InfoHousePreview.SetModelOrientation( Vector( 0,0,0 ) );

		m_InfoHouseName.SetText(hd.BuldingName);
		m_InfoDescription.SetText(hd.BuldingDescription);
		m_InfoPriceTxt.SetText(hd.RentPrice.ToString());
		m_InfoTimeTxt.SetText(hd.LeaseTime.ToString());
		m_InfoClassTxt.SetText(GetAllowClassesToString(hd));
		SetupAllowDoors(hd);

		m_InfoBtnRent.Enable(false);
		m_InfoBtnApproval.Enable(true);
		if (hd.NeedApproval && !AllowApproval(hd))
		{
			m_InfoBtnRent.Show(false);
			m_InfoBtnApproval.Show(true);
			if (g_HM.HasDuplicateSuggestion(m_Player.GetMultiCharactersPlayerId().ToString(), hd.RentSuggestions))
			{
				m_InfoBtnApproval.Enable(false);
			}
		}
		else
		{
			m_InfoBtnRent.Show(true);
			m_InfoBtnApproval.Show(false);
			if ( (hd.AllowCitizenClasses.Find(m_Player.GetMultiCharactersPlayerClass()) + 1) )
			{
				m_InfoBtnRent.Enable(true);
			}
		}
		if (!g_HM.m_House)
		{
			m_InfoBtnRent.Enable(false);
		}
	}

	bool AllowApproval(HouseData hd)
	{
		for (int i = 0; i < hd.RentSuggestions.Count(); i++)
		{
			if (hd.RentSuggestions.Get(i).MilticharacterID == m_Player.GetMultiCharactersPlayerId().ToString())
			{
				if (hd.RentSuggestions.Get(i).Approved)
				return true;
				else
				return false;
			}
		}
		return false;
	}

	void SaveBuildingInfo()
	{
		if (!ValidateInfo()) return;
		ref HouseData hd = new HouseData();
		int low, high;
		string temp;
		m_Description.GetText(temp);
		g_HM.m_House.GetNetworkID(low, high);
		hd.Low = low;
		hd.High = high;
		hd.BuldingName = m_BName.GetText();
		hd.BuldingDescription = temp;
		hd.BuildingPos = g_HM.m_House.GetPosition().ToString();
		hd.LeaseTime = m_BTime.GetText().ToInt();
		hd.RentPrice = m_BPrice.GetText().ToInt();
		hd.BuildingSector = -1;
		hd.TotalDoors = g_HM.m_House.GetDoorsCount();
		for (int i = 0; i < m_DoorsIdxWidgets.Count(); i++)
		{
			CheckBoxWidget cb = m_DoorsIdxWidgets.Get(i);
			if (cb.IsChecked())
			{
				hd.AllowDoors.Insert(cb.GetUserID());
			}
		}

		for (int j = 0; j < m_SectorsWidget.Count(); j++)
		{
			if (m_SectorsWidget.Get(j).IsChecked())
			{
				hd.BuildingSector = m_SectorsWidget.Get(j).GetUserID();
				break;
			}
		}

		if (m_Approval.IsChecked()) hd.NeedApproval = true;

		for (int k = 0; k < 5; k++)
		{
			if (m_ClassesWidget.Get(k).IsChecked())
			{hd.AllowCitizenClasses.Insert(m_ClassesWidget.Get(k).GetUserID());}
		}

		g_HM.m_House.RPCSingleParam(HRPC.REQUEST_ADD_HOUSE_INFO, new Param1<ref HouseData>(hd), true, null);
		g_HM.ShowBastionNotification("The information is saved and the building is added for rent");
		g_HM.CloseMenu();
	}

	void AddPointToMap(MapWidget w)
	{
		w.AddUserMark(g_HM.m_House.GetPosition(), "House" , ARGB(255, 255, 128, 8), "\\BastionMod\\BastionHousingSystem\\layouts\\dot.paa");
	}

	bool ValidateInfo()
	{
		bool oneSelected = false;
		int SectorsCount = 0;
		string temp;
		m_Description.GetText(temp);
		if (!m_BName.GetText() || !m_BPrice.GetText() || !m_BTime.GetText() || !temp)
		{
			g_HM.ShowBastionNotification("Error! All fields must be filled.");
			return false;
		}
		if (!m_CLA.IsChecked() && !m_CLB.IsChecked() && !m_CLC.IsChecked() && !m_CLD.IsChecked() && !m_CLS.IsChecked())
		{
			g_HM.ShowBastionNotification("Error! Select at least 1 class.");
			return false;
		}
		for (int i = 0; i < m_DoorsIdxWidgets.Count(); i++)
		{
			CheckBoxWidget cb = m_DoorsIdxWidgets.Get(i);
			if (cb.IsChecked()) oneSelected = true;
		}

		if (!oneSelected)
		{
			g_HM.ShowBastionNotification("Error! Select at least 1 door.");
			return false;
		}

		foreach (CheckBoxWidget cbs : m_SectorsWidget)
		{
			if (cbs.IsChecked())
			{SectorsCount++;}
		}

		if (SectorsCount > 1)
		{
			g_HM.ShowBastionNotification("Error! You cannot select more than 1 sector.");
			return false;
		}


		return true;
	}

	string GetAllowClassesToString(HouseData hd)
	{
		string temp = "";
		for (int i = 0; i < hd.AllowCitizenClasses.Count(); i++)
		{
			if (i != 0)
			{
				temp += ", ";
			}
			temp += IntClassToChar(hd.AllowCitizenClasses.Get(i));
		}
		return temp;
	}

	string IntClassToChar(int classId)
	{
		string char;
		switch(classId)
		{
			case 1:
				char = "A";
			break;
			case 2:
				char = "B";
			break;
			case 3:
				char = "C";
			break;
			case 4:
				char = "D";
			break;
			case 5:
				char = "S";
			break;
		}
		return char;
	}

	void SetupAllowDoors(HouseData hd)
	{
		ClearAllChildren(m_InfoWrapDoors);
		string temp = "";
		for (int i = 0; i < hd.AllowDoors.Count(); i++)
		{
			int idx = hd.AllowDoors.Get(i);
			TextWidget txtw = TextWidget.Cast(GetGame().GetWorkspace().CreateWidgets("BastionMod/BastionHousingSystem/layouts/InfoDoorElem.layout", m_InfoWrapDoors));
			temp = "[ID:"+idx+"]";
			txtw.SetText(temp);
		}
	}

	//--------------------------------------------------------------------------
	override bool OnMouseButtonDown(Widget w, int x, int y, int button)
	{
		super.OnMouseButtonDown(w, x, y, button);
		
		if (w == m_HousePreview)
		{
			GetGame().GetDragQueue().Call(this, "UpdateRotation");
			g_Game.GetMousePos(m_characterRotationX, m_characterRotationY);
			return true;
		}
		if (w == m_InfoHousePreview)
		{
			GetGame().GetDragQueue().Call(this, "UpdateRotation");
			g_Game.GetMousePos(m_characterRotationX, m_characterRotationY);
			return true;
		}
		return false;
	}
	
	//--------------------------------------------------------------------------
	void UpdateRotation(int mouse_x, int mouse_y, bool is_dragging)
	{
		vector o = m_characterOrientation;
		o[0] = o[0] + (m_characterRotationY - mouse_y);
		o[1] = o[1] - (m_characterRotationX - mouse_x);
		
		m_HousePreview.SetModelOrientation( o );
		m_InfoHousePreview.SetModelOrientation( o );
		if (!is_dragging)
		{
			m_characterOrientation = o;
		}
	}
	
	void ChangePanel(string val)
	{
		if (!g_HM.m_House) return;
		m_MHPanelInfo.Show(false);
		m_MHPanelRequests.Show(false);
		m_MHPanelDoorsControl.Show(false);
		m_MHPanelDoorGroups.Show(false);

		m_MHBtnInfo.Enable(true);
		m_MHBtnDoorsControl.Enable(true);
		m_MHBtnRequests.Enable(true);
		m_MHBtnDoorGroups.Enable(true);

		switch(val)
		{
			case "info":
				SetupMHPanelInfo();
				m_MHPanelInfo.Show(true);
				m_MHBtnInfo.Enable(false);
			break;
			case "dControl":
				m_CurrentGroupId = -1;
				m_CurrentGuestId = -1;
				SetupGroupControlInfo();
				m_MHPanelDoorsControl.Show(true);
				m_MHBtnDoorsControl.Enable(false);
			break;
			case "request":
				m_CurrentGroupId = -1;
				m_CurrentGuestId = -1;
				SetupDoorRequests();
				m_MHPanelRequests.Show(true);
				m_MHBtnRequests.Enable(false);
			break;
			case "dGroups":
				SetupDoorGroups();
				m_MHPanelDoorGroups.Show(true);
				m_MHBtnDoorGroups.Enable(false);
			break;
		}
	}

	void SetupMHPanelInfo()
	{
		HouseData hd = g_HM.m_House.m_HouseData;
		if (!hd)
		{
			return;
		}
		m_MHTextHouseName.SetText(hd.BuldingName);
		m_MHDescription.SetText(hd.BuldingDescription);
		//HouseManager.CalcRightHeight(m_MHDescription, hd.BuldingDescription.Length());
		m_MHTextRentDate.SetText(hd.MainOwner.Date);
		int val = hd.MainOwner.RentTimeLeft / 60;
		if (!val)
		m_MHTextRentTime.SetText("<1");
		else
		m_MHTextRentTime.SetText(val.ToString());
		m_MHTextRentPrice.SetText(hd.RentPrice.ToString());
		val = 0;
		for (int i = 0; i < hd.GroupsData.Count(); i++)
		{
			val += hd.GroupsData.Get(i).Renters.Count();
		}
		m_MHTextGuestNum.SetText(val.ToString());
		val = hd.GroupsData.Count();
		m_MHTextDoorCount.SetText(val.ToString());
		m_MHTextDoorRealCount.SetText(hd.AllowDoors.Count().ToString());

		m_MHBtnPayRent.Enable(true);
		m_MHBtnCancelLease.Enable(true);

		if (!g_HM.m_House)
		{
			m_MHBtnPayRent.Enable(false);
			m_MHBtnCancelLease.Enable(false);
		}
	}

	void SetupGroupControlInfo()
	{
		ClearAllChildren(m_MHWrapDoorsId);
		HouseData hd = g_HM.m_House.m_HouseData;
		FiilGroupsId(hd, m_MHWrapDoorsId);
	}

	void FiilGroupsId(HouseData hd, Widget container)
	{
		m_ForGroupsIds.Clear();
		for (int i = 0; i < hd.GroupsData.Count(); i++)
		{
			HouseGroupData hdd = hd.GroupsData.Get(i);
			Widget dId = GetGame().GetWorkspace().CreateWidgets("BastionMod/BastionHousingSystem/layouts/MHGroupElem.layout", container);
			TextWidget tId = TextWidget.Cast(dId.FindAnyWidget("MHGroupText"));
			tId.SetText(hdd.Name);
			dId.SetUserID(i);
			m_ForGroupsIds.Insert(dId);
		}
	}

	void FillGroupGuest(int dIndex)
	{
		ClearAllChildren(m_MHWrapGuestsNames);
		m_MHPanelGuestInfo.Show(false);
		HouseGroupData hgd = g_HM.m_House.m_HouseData.GroupsData.Get(dIndex);
		if (!hgd)
		{
			g_HM.ShowBastionNotification("Error, group guest data is corrupted");
			return;
		}
		for (int i = 0; i < hgd.Renters.Count(); i++)
		{
			HousePersonData hpd = hgd.Renters.Get(i);
			Widget gId = GetGame().GetWorkspace().CreateWidgets("BastionMod/BastionHousingSystem/layouts/MHGuestInfo.layout", m_MHWrapGuestsNames);
			TextWidget tId = TextWidget.Cast(gId.FindAnyWidget("MHGuestInfoName"));
			tId.SetText(hpd.Name);
			gId.SetUserID(i);
		}
		m_CurrentGroupId = dIndex;
	}

	void ClearAllChildren(Widget w)
	{
		while (w.GetChildren())
		{
			w.RemoveChild(w.GetChildren());
		}
	}

	void FillGroupGuestInfo(int dIndex)
	{
		if (m_CurrentGroupId != -1)
		{
			HousePersonData hpd = g_HM.m_House.m_HouseData.GroupsData.Get(m_CurrentGroupId).Renters.Get(dIndex);
			if (!hpd) return;
			m_CurrentGuestId = dIndex;
			m_MHPanelGuestInfo.Show(true);
			m_MHGuestName.SetText(hpd.Name);
			m_MHGuestId.SetText(hpd.MilticharacterID);
			m_MHGuestSince.SetText(hpd.Date);
			m_MHGuestClass.SetText(hpd.BastionClass)
		}
	}

	void FillDoorRequestInfo(int dIndex)
	{
		if (m_CurrentGroupId != -1)
		{
			RentSuggestion rs = g_HM.m_House.m_HouseData.GroupsData.Get(m_CurrentGroupId).RentSuggestions.Get(dIndex);
			if (!rs) return;
			m_MHPanelGuestInfoRequest.Show(true);
			m_CurrentGuestId = dIndex;
			m_MHReqNam.SetText(rs.Name);
			m_MHReqId.SetText(rs.MilticharacterID);
			m_MHReqClass.SetText(rs.BastionClass);
		}
	}

	void ReloadGuests()
	{
		FillGroupGuest(m_CurrentGroupId);
	}

	void SetupDoorRequests()
	{
		HouseData hd = g_HM.m_House.m_HouseData;
		ClearAllChildren(m_MHWrapReqDoors);
		FiilGroupsId(hd, m_MHWrapReqDoors);
	}

	void FillDoorRequest(int dIndex)
	{
		ClearAllChildren(m_MHWrapGuestsRequests);
		m_MHPanelGuestInfoRequest.Show(false);
		HouseGroupData hgd = g_HM.m_House.m_HouseData.GroupsData.Get(m_CurrentGroupId);
		if (!hgd)
		{
			g_HM.ShowBastionNotification("Error, group request data is corrupted");
			return;
		}
		for (int i = 0; i < hgd.RentSuggestions.Count(); i++)
		{
			RentSuggestion rs = hgd.RentSuggestions.Get(i);
			Widget gId = GetGame().GetWorkspace().CreateWidgets("BastionMod/BastionHousingSystem/layouts/MHGuestInfo.layout", m_MHWrapGuestsRequests);
			TextWidget tId = TextWidget.Cast(gId.FindAnyWidget("MHGuestInfoName"));
			tId.SetText(rs.Name);
			gId.SetUserID(i);
		}
	}

	void BlockButton(Widget w)
	{
		for (int i = 0; i < m_ForGroupsIds.Count(); i++)
		{
			if (m_ForGroupsIds.Get(i).FindAnyWidget("ButtonWidget0"))
			{
				m_ForGroupsIds.Get(i).FindAnyWidget("ButtonWidget0").Enable(true);
				m_ForGroupsIds.Get(i).SetColor(COLOR_TRANSPARENT);
			}
		}
		w.GetParent().FindAnyWidget("ButtonWidget0").Enable(false);
		w.GetParent().SetColor(COLOR_ORNG);
	}

	void ReloadRequests()
	{
		FillDoorRequest(m_CurrentGuestId);
	}

	void EditDoorInfo()
	{
		ref HouseGroupData hdd = g_HM.m_House.m_HouseData.GroupsData.Get(m_CurrentGroupId);
		if (hdd)
		{
			m_MHDoorName.SetText("Door name");
			m_MHDoorRentPrice.SetText("Rent price");
			m_MHDoorRentTime.SetText("Lease Time (int hour)");
			m_MHDescriptionDoor.SetText("Description");
			//==== default
			if (hdd.Name)
			m_MHDoorName.SetText(hdd.Name);
			if (hdd.RentPrice)
			m_MHDoorRentPrice.SetText(hdd.RentPrice.ToString());
			if (hdd.LeaseTime)
			m_MHDoorRentTime.SetText(hdd.LeaseTime.ToString());
			if (hdd.Description)
			m_MHDescriptionDoor.SetText(hdd.Description);
			//HouseManager.CalcRightHeight(m_MHDescriptionDoor, hdd.Description.Length());
		}
		m_MHPanelEditDoorInfo.Show(true);
	}

	void CancelDoorInfo()
	{
		m_MHPanelEditDoorInfo.Show(false);
	}

	void SaveDoorInfo()
	{
		ref HouseGroupData hdd = new HouseGroupData();
		string name = m_MHDoorName.GetText();
		string descip;
		m_MHDescriptionDoor.GetText(descip);
		string price = m_MHDoorRentPrice.GetText();
		string time = m_MHDoorRentTime.GetText();


		hdd.Name = name;
		hdd.Description = descip;
		hdd.RentPrice = price.ToInt();
		hdd.LeaseTime = time.ToInt();
		g_HM.SaveDoorInfo(hdd, m_CurrentGroupId);
	}

	void SetupDoorInfo()
	{
		ClearAllChildren(m_DIDoorsList);
		HouseData hd = g_HM.m_House.m_HouseData;
		string uid = m_Player.GetMultiCharactersPlayerId().ToString();
		ref HouseGroupData hdd = hd.GroupsData.Get(m_StartGroupIdx);
		if ( hdd )
		{
			m_DIDoorName.SetText(hd.BuldingName);
			m_DIPrice.SetText(hdd.RentPrice.ToString());
			m_DITime.SetText(hdd.LeaseTime.ToString());
			m_DIClasses.SetText(GetAllowClassesToString(hd));
			m_DIDescription.SetText(hdd.Description);

			for (int k = 0; k < hdd.Indexes.Count(); k++)
			{
				CheckBoxWidget dId = GetGame().GetWorkspace().CreateWidgets("BastionMod/BastionHousingSystem/layouts/DoorIndex.layout", m_DIDoorsList);
				string str = "";
				str = "[ID:"+hdd.Indexes.Get(k).ToString()+"]";
				dId.SetText(str);
				dId.SetChecked(true);
				dId.Enable(false);
			}

			for (int j = 0; j < hdd.RentSuggestions.Count(); j++)
			{
				RentSuggestion rs = hdd.RentSuggestions.Get(j);
				if ( (rs.MilticharacterID == uid) || IsDoorOwner(hdd,uid) )
				{
					m_DIBtnRequest.Enable(false);
				}
			}
		}
	}

	bool IsDoorOwner(ref HouseGroupData hdd, string uid)
	{
		for (int i = 0; i < hdd.Renters.Count(); i++)
		{
			if (uid == hdd.Renters.Get(i).MilticharacterID)//TODO change to multicharID
			return true;
		}
		return false;
	}

	void SetupDoorGroups()
	{
		ClearAllChildren(m_MHDGListGroups);
		HouseData hd = g_HM.m_House.m_HouseData;

		for (int j = 0; j < hd.GroupsData.Count(); j++)
		{
			Widget groupWid = GetGame().GetWorkspace().CreateWidgets("BastionMod/BastionHousingSystem/layouts/MHDoorGroup.layout", m_MHDGListGroups);
			TextWidget tw 	= TextWidget.Cast(groupWid.FindAnyWidget("MHDoorGroupName"));
			tw.SetText( hd.GroupsData.Get(j).Name );
			groupWid.SetUserID(j);
		}
	}

	void ShowGroupInfo(int idx)
	{
		ClearAllChildren(m_MHDGTxtListDoors);
		m_MHBtnDoorGroupsEdit.Enable(false);
		if (idx != -1)
		{
			m_CurrentGroupId = idx;
			HouseGroupData hgd = g_HM.m_House.m_HouseData.GroupsData.Get(idx);
			m_MHDGTxtName.SetText(hgd.Name);
			m_MHDGTxtPrice.SetText(hgd.RentPrice.ToString());
			m_MHDGTxtTime.SetText(hgd.LeaseTime.ToString());
			m_MHDGTxtDescrip.SetText(hgd.Description);
			m_MHBtnDoorGroupsEdit.Enable(true);
			for (int i = 0; i < hgd.Indexes.Count(); i++)
			{
				CheckBoxWidget dId = GetGame().GetWorkspace().CreateWidgets("BastionMod/BastionHousingSystem/layouts/DoorIndex.layout", m_MHDGTxtListDoors);
				string str = "";
				str = "[ID:"+hgd.Indexes.Get(i).ToString()+"]";
				dId.SetText(str);
				dId.SetChecked(true);
				dId.Enable(false);
			}

			m_MHDGPanelShowInfo.Show(true);
		}
	}

	void EditGroupInfo()
	{
		ClearAllChildren(m_MHDGEditListDoors);
		CheckBoxWidget dId;
		string str;
		HouseGroupData hgd = g_HM.m_House.m_HouseData.GroupsData.Get(m_CurrentGroupId);
		m_DoorsIdxWidgets.Clear();
		m_MHDGEditName.SetText(hgd.Name);
		m_MHDGEditPrice.SetText(hgd.RentPrice.ToString());
		m_MHDGEditTime.SetText(hgd.LeaseTime.ToString());
		m_MHDGEditDescription.SetText(hgd.Description);

		for (int i = 0; i < hgd.Indexes.Count(); i++)
		{
			dId = GetGame().GetWorkspace().CreateWidgets("BastionMod/BastionHousingSystem/layouts/DoorIndex.layout", m_MHDGEditListDoors);
			str = "";
			str = "[ID:"+hgd.Indexes.Get(i).ToString()+"]";
			dId.SetText(str);
			dId.SetChecked(true);
			dId.SetUserID(hgd.Indexes.Get(i));
			m_DoorsIdxWidgets.Insert(dId);
		}
		array<int> tempFreeDoors = g_HM.GetFreeDoors(g_HM.m_House.m_HouseData);
		for (int j = 0; j < tempFreeDoors.Count(); j++)
		{
			dId = GetGame().GetWorkspace().CreateWidgets("BastionMod/BastionHousingSystem/layouts/DoorIndex.layout", m_MHDGEditListDoors);
			str = "";
			str = "[ID:"+tempFreeDoors.Get(j).ToString()+"]";
			dId.SetText(str);
			dId.SetUserID(tempFreeDoors.Get(j));
			m_DoorsIdxWidgets.Insert(dId);
		}

		m_MHDGPanelShowInfo.Show(false);
		m_MHDGPanelEdit.Show(true);
	}

	void CreateNewGroup()
	{
		if (!g_HM.GetFreeDoors(g_HM.m_House.m_HouseData).Count())
		{
			g_HM.ShowBastionNotification("There are no available doors");
			return;
		}
		m_MHDGGroupName.SetText("");
		m_MHDGDoorDescrip.SetText("");
		m_MHDGGroupPrice.SetText("");
		m_MHDGGroupLeaseTime.SetText("");
		FillFreeDoorsCG(); // create group fiil free doors
		m_MHPanelDGEdit.Show(false);
		m_MHPanelDGCreate.Show(true);
	}

	void CancelCreationGroup()
	{
		m_MHPanelDGEdit.Show(true);
		m_MHPanelDGCreate.Show(false);
	}

	void FillFreeDoorsCG()
	{
		ClearAllChildren(m_MHDGGroupAllowDoors);
		m_DoorsIdxWidgets.Clear(); // maybe cause problem
		HouseData hd = g_HM.m_House.m_HouseData;
		array<int> PosDoors = hd.AllowDoors;
		int idx = -1;
		for (int i = 0; i < hd.GroupsData.Count(); i++)
		{
			HouseGroupData hdd = hd.GroupsData.Get(i);
			for (int j = 0; j < hdd.Indexes.Count(); j++)
			{
				idx = PosDoors.Find(hdd.Indexes.Get(j));
				if (idx >= 0)
				{
					PosDoors.Remove(idx);
				}
			}
		}
		for (int k = 0; k < PosDoors.Count(); k++)
		{
			CheckBoxWidget dId = GetGame().GetWorkspace().CreateWidgets("BastionMod/BastionHousingSystem/layouts/DoorIndex.layout", m_MHDGGroupAllowDoors);
			string str = "";
			str = "[ID:"+PosDoors.Get(k).ToString()+"]";
			dId.SetText(str);
			dId.SetUserID(PosDoors.Get(k));
			m_DoorsIdxWidgets.Insert(dId);
		}
	}

	void SaveNewGroup()
	{
		ref HouseData hd = g_HM.m_House.m_HouseData;
		bool oneDoorSelect = false;
		string name, descrip, price, ltime;
		name = m_MHDGGroupName.GetText();
		m_MHDGDoorDescrip.GetText(descrip);
		price = m_MHDGGroupPrice.GetText();
		ltime = m_MHDGGroupLeaseTime.GetText();
		for (int i = 0; i < hd.GroupsData.Count(); i++)
		{
			if (name == hd.GroupsData.Get(i).Name)
			{
				g_HM.ShowBastionNotification("Error, a group with this name already exists");
				return;
			}
		}

		if (!name || !descrip || !price || !ltime)
		{
			g_HM.ShowBastionNotification("Error, all fields must be filled");
			return;
		}

		for (int k = 0; k < m_DoorsIdxWidgets.Count(); k++)
		{
			if ( m_DoorsIdxWidgets.Get(k).IsChecked() ) 
			{
				oneDoorSelect = true;
				break;
			}
		}

		if (!oneDoorSelect)
		{
			g_HM.ShowBastionNotification("Error, select at least 1 door");
			return;
		}

		ref HouseGroupData data = new HouseGroupData;
		data.Name = name;
		data.Description = descrip;
		data.RentPrice = price.ToInt();
		data.LeaseTime = ltime.ToInt();
		ref array<int> idxs = new array<int>();
		for (int m = 0; m < m_DoorsIdxWidgets.Count(); m++)
		{
			if(m_DoorsIdxWidgets.Get(m).IsChecked())
			idxs.Insert(m_DoorsIdxWidgets.Get(m).GetUserID());
		}
		data.Indexes = idxs;
		hd.GroupsData.Insert(data);
		SetupDoorGroups();
		m_MHDGPanelShowInfo.Show(false);
		g_HM.RequestAddNewGroup(data, idxs);
		ShowGroupInfo(m_CurrentGroupId);
		g_HM.ShowBastionNotification("A new group was created");
		CancelCreationGroup();
	}

	void CancelEditingGroup()
	{
		m_MHDGPanelEdit.Show(false);
		m_MHDGPanelShowInfo.Show(false);
	}

	void SaveGroupEditInfo()
	{
		ref HouseGroupData hgd = new HouseGroupData;
		string descrip;
		bool oneDoorSelect = false;
		m_MHDGEditDescription.GetText(descrip);
		if (!m_MHDGEditName.GetText() || !m_MHDGEditPrice.GetText() || !m_MHDGEditTime.GetText() || !descrip)
		{
			g_HM.ShowBastionNotification("Error, all fields must be filled");
			return;
		}

		if (m_CurrentGroupId == -1)
		{
			g_HM.ShowBastionNotification("Error, group data is corrupted");
			return;
		}

		for (int k = 0; k < m_DoorsIdxWidgets.Count(); k++)
		{
			if ( m_DoorsIdxWidgets.Get(k).IsChecked() ) 
			{
				oneDoorSelect = true;
				break;
			}
		}
		if (!oneDoorSelect)
		{
			g_HM.ShowBastionNotification("Error, select at least 1 door");
			return;
		}

		hgd.Name = m_MHDGEditName.GetText();
		hgd.RentPrice = m_MHDGEditPrice.GetText().ToInt();
		hgd.LeaseTime = m_MHDGEditTime.GetText().ToInt();
		hgd.Description = descrip;
		
		for (int i = 0; i < m_DoorsIdxWidgets.Count(); i++)
		{
			if (m_DoorsIdxWidgets.Get(i).IsChecked())
			{
				hgd.Indexes.Insert(m_DoorsIdxWidgets.Get(i).GetUserID());
			}
		}

		g_HM.m_House.m_HouseData.GroupsData.Get(m_CurrentGroupId) = hgd; // client insta update info

		g_HM.RequestEditGroupInfo(hgd, m_CurrentGroupId);

		g_HM.ShowBastionNotification("New information has been saved");
		SetupDoorGroups();
		CancelEditingGroup();
	}

	void DeleteGroup()
	{
		if (m_CurrentGroupId == -1)
		{
			g_HM.ShowBastionNotification("Error, group data is corrupted");
			return;
		}
		m_MHDGPanelEdit.Show(false);
		m_MHDGPanelShowInfo.Show(false);
		g_HM.m_House.m_HouseData.GroupsData.Remove(m_CurrentGroupId);
		g_HM.ShowBastionNotification("Group has been deleted");
		g_HM.RequestRemoveGroup(m_CurrentGroupId);
		SetupDoorGroups();
	}

	void FillSectorsArr()
	{
		m_SectorsWidget.Clear()
		m_SectorsWidget.Insert(m_SEC0);
		m_SectorsWidget.Insert(m_SEC1);
		m_SectorsWidget.Insert(m_SEC2);
		m_SectorsWidget.Insert(m_SEC3);
		m_SectorsWidget.Insert(m_SEC4);
		m_SectorsWidget.Insert(m_SEC5);
	}

	void ReqGroup()
	{
		g_HM.SendRequestGroup(m_StartGroupIdx);
		m_DIBtnRequest.Enable(false);
		g_HM.ShowBastionNotification("A request to rent this door group has been sent");
	}

	override bool OnChange(Widget w, int x, int y, bool finished)
	{
		if ((w == m_SearchBox) || (CheckBoxWidget.Cast(w) && w.GetParent().GetName().Contains("Search")))
		{
			SearchHouses();
		}
		if (w == m_SchCheckBoxOwnHouses)
		{
			g_HM.SetBuilding(NULL);
			CleanHouseTable();
			if (CheckBoxWidget.Cast(w).IsChecked())
			{
				m_PanelInfoForMainTenant.Show(false);
				m_PanelManageHouse.Show(true);
			}
			else
			{
				m_PanelManageHouse.Show(false);
				m_PanelInfoForMainTenant.Show(true);
			}
		}
		if (w == m_SchCheckBoxAdminRequests)
		{
			g_HM.SetBuilding(NULL);
			if (CheckBoxWidget.Cast(w).IsChecked())
			{
				m_PanelCreateHousWrap.Show(false);
				m_PanelCHRequests.Show(true);
				CleanRequestPanel();
			}
			else
			{
				m_PanelCreateHousWrap.Show(true);
				m_PanelCHRequests.Show(false);
			}
		}
		return false;
	}

	void SearchHouses()
	{
		m_SearchPattern = m_SearchBox.GetText();
		FillHouses();
	}

	void FillHouses()
	{
		ClearAllChildren(m_SearchHouseContainer);
		m_SearchScroll.VScrollToPos01( 0 );
		for (int i = 0; i < g_HM.AllHouseData.Count(); i++)
		{
			HouseData hd = g_HM.AllHouseData.Get(i);
			if(AllowFilters(hd))
			{
				Widget houseElem = GetGame().GetWorkspace().CreateWidgets("BastionMod/BastionHousingSystem/layouts/HouseElem.layout", m_SearchHouseContainer);
				TextWidget.Cast(houseElem.FindAnyWidget("HouseName")).SetText(hd.BuldingName);
				houseElem.SetUserID(i);
			}
		}
	}

	bool AllowFilters(HouseData hd)
	{
		string name = hd.BuldingName;
		string pattern = m_SearchPattern;
		name.ToLower();
		pattern.ToLower();
		if (!name.Contains(pattern))
		{return false;}

		for (int j = 0; j < 6; j++)
		{
			if (m_SearchSectors.Get(j).IsChecked() && hd.BuildingSector != j)
			{return false;}
		}

		for (int i = 1; i < 6; i++)
		{
			if (m_SearchClasses.Get(i).IsChecked() && !(hd.AllowCitizenClasses.Find(i) + 1))
			{return false;}
		}
		

		if (m_SchCheckBoxRentable.IsChecked() && !hd.LeaseTime /*&& !m_SchCheckBoxOwnHouses.IsChecked()*/)
		{return false;}

		if (!IsAdmin && !m_SchCheckBoxOwnHouses.IsChecked())
		{
			if (hd.MainOwner.Name)
			{return false;}
		}

		if (m_SchCheckBoxOwnHouses.IsChecked())
		{
			if (hd.MainOwner.MilticharacterID != m_Player.GetMultiCharactersPlayerId().ToString())
			{
				return false;
			}
		}

		if (m_SchCheckBoxAdminRequests.IsChecked())
		{
			if (!hd.RentSuggestions.Count())
			{return false;}
		}

		return true;
	}

	void ShowHouseInfo(int idx)
	{
		m_PanelTipHouseOwner.Show(false);
		HouseData hd = g_HM.AllHouseData.Get(idx);
		if (!hd) return;
		BRP_House house = BRP_House.Cast(GetGame().GetObjectByNetworkId(hd.Low, hd.High));
		if (house)
		{
			house.m_HouseData = hd;
			g_HM.SetBuilding(house);
			m_MHBtnDoorGroupsEdit.Enable(false);
			m_MHDGPanelShowInfo.Show(false);
			m_MHDGPanelEdit.Show(false);
			SetupCreateHouseSetting();
			SetupShowInfo();
			SetupMHPanelInfo();
			ChangePanel("info");
			if (IsAdmin && (m_Type == 5) && hd.MainOwner.Name)
			{
				m_PanelTipHouseOwner.Show(true);
				m_Owner.SetText(hd.MainOwner.Name);
			}
			if (IsAdmin && (m_Type == 5) && m_SchCheckBoxAdminRequests.IsChecked())
			{
				FillHouseRequests(hd);
				m_PCHBtnAllow.Enable(true);
				m_PCHBtnDeny.Enable(true);
			}
		}
		else
		{
			g_HM.ShowBastionNotification("House NOT found");
		}
	}

	void FillPlaceholdersArr()
	{
		m_Placeholders.Insert(m_PlaceHolder1);
		m_Placeholders.Insert(m_PlaceHolder2);
		m_Placeholders.Insert(m_PlaceHolder3);
	}

	void FillSearchArr()
	{
		m_SearchSectors.Insert(m_SchChBSec0);
		m_SearchSectors.Insert(m_SchChBSec1);
		m_SearchSectors.Insert(m_SchChBSec2);
		m_SearchSectors.Insert(m_SchChBSec3);
		m_SearchSectors.Insert(m_SchChBSec4);
		m_SearchSectors.Insert(m_SchChBSec5);

		m_SearchClasses.Insert(m_SchCheckBoxA);// fix
		m_SearchClasses.Insert(m_SchCheckBoxA);
		m_SearchClasses.Insert(m_SchCheckBoxB);
		m_SearchClasses.Insert(m_SchCheckBoxC);
		m_SearchClasses.Insert(m_SchCheckBoxD);
		m_SearchClasses.Insert(m_SchCheckBoxS);
	}

	void FillClassesWidgets()
	{
		m_ClassesWidget.Insert(m_CLA);
		m_ClassesWidget.Insert(m_CLB);
		m_ClassesWidget.Insert(m_CLC);
		m_ClassesWidget.Insert(m_CLD);
		m_ClassesWidget.Insert(m_CLS);
	}

	void ClearCheckboxes()
	{
		foreach (CheckBoxWidget cwid : m_ClassesWidget)
		{
			cwid.SetChecked(false);
		}
		foreach (CheckBoxWidget swid : m_SectorsWidget)
		{
			swid.SetChecked(false);
		}
		m_Approval.SetChecked(false);
	}

	void CreateSelectAllDoors()
	{
		for (int i = 0; i < m_DoorsIdxWidgets.Count(); i++)
		{
			CheckBoxWidget.Cast(m_DoorsIdxWidgets.Get(i)).SetChecked(true);
		}
	}

	void CleanHouseTable()
	{
		m_InfoPriceTxt.SetText("");
		m_InfoTimeTxt.SetText("");
		m_InfoClassTxt.SetText("");
		m_InfoHouseName.SetText("");
		m_InfoDescription.SetText("");
		m_InfoHouseName.SetText("");

		m_MHTextRentDate.SetText("");
		m_MHTextRentTime.SetText("");
		m_MHTextRentPrice.SetText("");
		m_MHTextGuestNum.SetText("");
		m_MHTextDoorCount.SetText("");
		m_MHTextDoorRealCount.SetText("");
		m_MHDescription.SetText("");
		m_MHTextHouseName.SetText("");

		m_InfoBtnRent.Enable(false);
		m_MHBtnPayRent.Enable(false);
		m_MHBtnCancelLease.Enable(false);
		ClearAllChildren(m_InfoWrapDoors);
	}

	void FillHouseRequests(HouseData hd)
	{
		ClearAllChildren(m_WrapHouseRequests);
		for (int i = 0; i < hd.RentSuggestions.Count(); i++)
		{
			RentSuggestion rs = hd.RentSuggestions.Get(i);
			if (rs.Approved) continue;
			Widget panRequester = GetGame().GetWorkspace().CreateWidgets("BastionMod/BastionHousingSystem/layouts/Requester.layout", m_WrapHouseRequests);
			TextWidget.Cast(panRequester.FindAnyWidget("RequesterName")).SetText(rs.Name);
			panRequester.SetUserID(i);
		}
	}

	void ShowRequesterInfo(int idx)
	{
		if (idx != -1)
		{
			m_CurrentSuggestionIdx = idx;
			RentSuggestion rs = g_HM.m_House.m_HouseData.RentSuggestions.Get(idx);
			if (rs)
			{
				m_RequesterName.SetText(rs.Name);
				m_RequesterId.SetText(rs.MilticharacterID);
				m_RequesterClass.SetText(IntClassToChar(rs.BastionClass.ToInt()));
			}
		}
	}

	void CleanRequestPanel()
	{
		ClearAllChildren(m_WrapHouseRequests);
		m_RequesterName.SetText("");
		m_RequesterId.SetText("");
		m_RequesterClass.SetText("");
	}

	void LocalDenySuggestion(int idx)
	{
		HouseData hd = g_HM.m_House.m_HouseData;
		if (hd)
		{
			if (hd.RentSuggestions.Get(idx))
			{
				hd.RentSuggestions.Remove(idx);
				FillHouseRequests(hd);
			}
		}
	}

	void LocalAllowSuggestion(int idx)
	{
		HouseData hd = g_HM.m_House.m_HouseData;
		if (hd)
		{
			if (hd.RentSuggestions.Get(idx))
			{
				hd.RentSuggestions.Get(idx).Approved = 1;
				FillHouseRequests(hd);
			}
		}
	}
}

