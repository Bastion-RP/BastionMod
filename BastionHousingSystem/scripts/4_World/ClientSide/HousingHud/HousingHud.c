class HousingHud extends UIScriptedMenu
{
	private EditBoxWidget				m_BName;
	private TextWidget					m_BPos;
	private EditBoxWidget				m_BPrice;
	private EditBoxWidget				m_BTime;

	private MultilineEditBoxWidget		m_Description;

	private CheckBoxWidget				m_CLA;
	private CheckBoxWidget				m_CLB;
	private CheckBoxWidget				m_CLC;
	private CheckBoxWidget				m_CLD;
	private CheckBoxWidget				m_CLS;

	private CheckBoxWidget				m_Approval;

	private MapWidget					m_MapHousePos;

	private WrapSpacerWidget			m_WrapDoor;

	private ButtonWidget				m_Btn_Save;
	private ButtonWidget				m_Btn_Cancel;
	private ButtonWidget				m_BtnSwitchTo3D;
	private ButtonWidget				m_BtnSwitchToMap;

	private Widget						m_PanelCreateHouse;

	private ItemPreviewWidget			m_HousePreview;

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

//=========================== door panel =================================

	private Widget						m_PanelDoorInfo;

	private TextWidget					m_DIDoorName;
	private TextWidget					m_DIPrice;
	private TextWidget					m_DITime;

	private MultilineTextWidget			m_DIDescription;

	private ButtonWidget				m_DIBtnRequest;

//=========================== other =======================================
	private ref array<CheckBoxWidget>	m_DoorsIdxWidgets;

	private ref array<Widget>			m_ForDoorsIds;
	private ref array<Widget>			m_ForGuestStorage;

	private int							m_Type;
	private int							m_CurrentDoorId;
	private int							m_CurrentGuestId;

	private int							m_StartDoorIdx;

	private int							COLOR_ORNG = -32760;
	private int							COLOR_TRANSPARENT = 16744456;

	void HousingHud(int type, int idx)
    {
        GetGame().GetMission().PlayerControlDisable(INPUT_EXCLUDE_ALL);
		m_Type = type;
		m_DoorsIdxWidgets 	= new array<CheckBoxWidget>();
		m_ForGuestStorage 	= new array<Widget>();
		m_ForDoorsIds 		= new array<Widget>();
		m_CurrentDoorId		= -1;
		m_CurrentGuestId	= -1;
		m_StartDoorIdx		= idx;
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

		m_CLA						=	CheckBoxWidget.Cast(GetWid("CLA"));
		m_CLB						=	CheckBoxWidget.Cast(GetWid("CLB"));
		m_CLC						=	CheckBoxWidget.Cast(GetWid("CLC"));
		m_CLD						=	CheckBoxWidget.Cast(GetWid("CLD"));
		m_CLS						=	CheckBoxWidget.Cast(GetWid("CLS"));

		m_Approval					=	CheckBoxWidget.Cast(GetWid("Approval"));

		m_WrapDoor					=	WrapSpacerWidget.Cast(GetWid("WrapDoor"));

		m_MapHousePos				=	MapWidget.Cast(GetWid("MapHousePos"));

		m_Btn_Save					=	ButtonWidget.Cast(GetWid("Btn_Save"));
		m_Btn_Cancel				=	ButtonWidget.Cast(GetWid("Btn_Cancel"));
		m_BtnSwitchTo3D				=	ButtonWidget.Cast(GetWid("BtnSwitchTo3D"));
		m_BtnSwitchToMap			=	ButtonWidget.Cast(GetWid("BtnSwitchToMap"));

		m_PanelCreateHouse			=	Widget.Cast(GetWid("PanelCreateHouse"));

		m_HousePreview				=	ItemPreviewWidget.Cast(GetWid("HousePreview"));

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

		//=========================== door panel =================================

		m_PanelDoorInfo				=	Widget.Cast(GetWid("PanelDoorInfo"));

		m_DIDoorName				=	TextWidget.Cast(GetWid("DIDoorName"));
		m_DIPrice					=	TextWidget.Cast(GetWid("DIPrice"));
		m_DITime					=	TextWidget.Cast(GetWid("DITime"));

		m_DIDescription				=	MultilineTextWidget.Cast(GetWid("DIDescription"));

		m_DIBtnRequest				=	ButtonWidget.Cast(GetWid("DIBtnRequest"));

		// other		===================================================================


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
		return layoutRoot;
	}

    Widget GetWid(string val)
	{
		return layoutRoot.FindAnyWidget(val);
	}

	override bool OnClick(Widget w, int x, int y, int button)
	{
		// super.OnClick(w, x, y, button);
		Print("Click on "+w+" userID "+w.GetUserID());
		if (w.GetUserID() == 20)
		{
			EditBoxWidget.Cast(w.GetParent()).SetText("");
			w.Unlink();
			return true;
		}
		if (w.GetUserID() == 33)
		{
			CancelDoorInfo();
			BlockButton(w);
			FillDoorGuest(w.GetParent().GetUserID());
			FillDoorRequest(w.GetParent().GetUserID());
			return true;
		}
		if (w.GetUserID() == 67)
		{
			FillDoorGuestInfo(w.GetParent().GetUserID());
			FillDoorRequestInfo(w.GetParent().GetUserID());
			return true;
		}
		if (!ButtonWidget.Cast(w)) return false;
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
					g_HM.TryRentBuilding();
				break;
				case m_InfoBtnApproval:
					g_HM.SendHouseRentRequest();
				break;
				case m_BtnSwitchToMap:
					AddPointToMap(m_MapHousePos);
					m_HousePreview.Show(false);
					m_BtnSwitchToMap.Show(false);
					m_MapHousePos.Show(true);
					m_BtnSwitchTo3D.Show(true);
				break;
				case m_BtnSwitchTo3D:
					m_MapHousePos.ClearUserMarks();
					m_MapHousePos.Show(false);
					m_BtnSwitchTo3D.Show(false);
					m_BtnSwitchToMap.Show(true);
					m_HousePreview.Show(true);
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
					m_MHBtnInfo.Enable(false);
					m_MHBtnDoorsControl.Enable(true);
					m_MHBtnRequests.Enable(true);
					ChangePanel("info");
				break;
				case m_MHBtnDoorsControl:
					m_MHBtnInfo.Enable(true);
					m_MHBtnDoorsControl.Enable(false);
					m_MHBtnRequests.Enable(true);
					ChangePanel("dControl");
				break;
				case m_MHBtnRequests:
					m_MHBtnInfo.Enable(true);
					m_MHBtnDoorsControl.Enable(true);
					m_MHBtnRequests.Enable(false);
					ChangePanel("request");
				break;
				case m_MHBtnEvict:
					g_HM.RequestEvictPlayer(m_CurrentDoorId, m_CurrentGuestId);
					g_HM.m_House.m_HouseData.DoorsData.Get(m_CurrentDoorId).Renters.Remove(m_CurrentGuestId);
					ReloadGuests();
				break;
				case m_MHBtnAccept:
					g_HM.RequestAddGuestToDoor(m_CurrentDoorId, m_CurrentGuestId);
					g_HM.LocalAddGuest(m_CurrentDoorId, m_CurrentGuestId);
					ReloadRequests();
				break;
				case m_MHBtnDeny:
					g_HM.RequestRemoveRequest(m_CurrentDoorId, m_CurrentGuestId);
					ReloadRequests();
				break;
				case m_MHBtnPayRent:
					// pay rent
				break;
				case m_MHBtnCancelLease:
					// cancel lease
				break;
				case m_MHBtnEditDoorInfo:
					EditDoorInfo();
				break;
				case m_MHBtnEditDoorSave:
					SaveDoorInfo();
				case m_MHBtnEditDoorCancel:
					CancelDoorInfo();
				break;
				case m_DIBtnRequest:
					g_HM.SendRequestDoor(m_StartDoorIdx);
				break;
			}
		}	
		return false;
		//return super.OnClick(w, x, y, button);
	}

	void SetupCreateHouseSetting()
	{
		m_BPos.SetText(g_HM.m_House.GetPosition().ToString());
		m_HousePreview.SetItem( g_HM.m_House );
		m_HousePreview.SetView( g_HM.m_House.GetViewIndex() );
		m_HousePreview.SetModelOrientation( Vector( 0,0,0 ) );
		for (int i = 0; i < g_HM.m_House.GetDoorsCount(); i++)
		{
			CheckBoxWidget temp = CheckBoxWidget.Cast(GetGame().GetWorkspace().CreateWidgets("BastionMod/BastionHousingSystem/layouts/DoorIndex.layout", m_WrapDoor));
			temp.SetUserID(i);
			string txt = "ID ["+i+"]";
			temp.SetText(txt);
			m_DoorsIdxWidgets.Insert(temp);
		}
	}

	void SetupShowInfo()
	{
		string temp;
		HouseData hd = g_HM.m_House.m_HouseData;
		
		m_InfoHousePreview.SetItem( g_HM.m_House );
		m_InfoHousePreview.SetView( g_HM.m_House.GetViewIndex() );
		m_InfoHousePreview.SetModelOrientation( Vector( 0,0,0 ) );

		m_InfoHouseName.SetText(hd.BuldingName);
		m_InfoDescription.SetText(hd.BuldingDescription);
		//HouseManager.CalcRightHeight(m_InfoDescription, hd.BuldingDescription.Length());
		m_InfoPriceTxt.SetText(hd.RentPrice.ToString());
		m_InfoTimeTxt.SetText(hd.LeaseTime.ToString());
		SetupAllowClasses(hd);
		SetupAllowDoors(hd);

		if (hd.NeedApproval)
		{
			m_InfoBtnRent.Show(false);
			m_InfoBtnApproval.Show(true);
		}
		else
		{
			//if (multicharacterclass) multicharacterclass
			//m_InfoBtnRent.Enable(false);
		}
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

		for (int i = 0; i < m_DoorsIdxWidgets.Count(); i++)
		{
			CheckBoxWidget cb = m_DoorsIdxWidgets.Get(i);
			if (cb.IsChecked())
			{
				ref HouseDoorData hdd = new HouseDoorData();
				hdd.Index = cb.GetUserID();
				hd.DoorsData.Insert(hdd);
			}
		}

		if (m_Approval.IsChecked()) hd.NeedApproval = true;

		if (m_CLA.IsChecked()) hd.AllowCitizenClasses.Insert(m_CLA.GetUserID());
		if (m_CLB.IsChecked()) hd.AllowCitizenClasses.Insert(m_CLB.GetUserID());
		if (m_CLC.IsChecked()) hd.AllowCitizenClasses.Insert(m_CLC.GetUserID());
		if (m_CLD.IsChecked()) hd.AllowCitizenClasses.Insert(m_CLD.GetUserID());
		if (m_CLS.IsChecked()) hd.AllowCitizenClasses.Insert(m_CLS.GetUserID());
		Print("SaveBuildingInfo packet applied");
		g_HM.m_House.RPCSingleParam(HRPC.REQUEST_ADD_HOUSE_INFO, new Param1<ref HouseData>(hd), true, null);
		g_HM.CloseMenu();
	}

	void AddPointToMap(MapWidget w)
	{
		w.AddUserMark(g_HM.m_House.GetPosition(), "House" , ARGB(255, 255, 128, 8), "\\BastionMod\\BastionHousingSystem\\layouts\\dot.paa");
	}

	bool ValidateInfo()
	{
		bool oneSelected = false;
		string temp;
		m_Description.GetText(temp);
		if (!m_BName.GetText() || !m_BPrice.GetText() || !m_BTime.GetText() || !temp)
		{
			HouseManager.SelfChatMessage("Error! All fields must be filled.");
			return false;
		}
		if (!m_CLA.IsChecked() && !m_CLB.IsChecked() && !m_CLC.IsChecked() && !m_CLD.IsChecked() && !m_CLS.IsChecked())
		{
			HouseManager.SelfChatMessage("Error! Select at least 1 class.");
			return false;
		}
		for (int i = 0; i < m_DoorsIdxWidgets.Count(); i++)
		{
			CheckBoxWidget cb = m_DoorsIdxWidgets.Get(i);
			if (cb.IsChecked()) oneSelected = true;
		}

		if (!oneSelected)
		{
			HouseManager.SelfChatMessage("Error! Select at least 1 door.");
			return false;
		}

		return true;
	}

	void SetupAllowClasses(HouseData hd)
	{
		string temp = "";
		for (int i = 0; i < hd.AllowCitizenClasses.Count(); i++)
		{
			if (i != 0)
			{
				temp += ", ";
			}
			switch(hd.AllowCitizenClasses.Get(i))
			{
				case 1:
					temp += "A";
				break;
				case 2:
					temp += "B";
				break;
				case 3:
					temp += "C";
				break;
				case 4:
					temp += "D";
				break;
				case 5:
					temp += "S";
				break;
			}
		}
		m_InfoClassTxt.SetText(temp);
	}

	void SetupAllowDoors(HouseData hd)
	{
		string temp = "";
		for (int i = 0; i < hd.DoorsData.Count(); i++)
		{
			int idx = hd.DoorsData.Get(i).Index;
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
		m_MHPanelInfo.Show(false);
		m_MHPanelRequests.Show(false);
		m_MHPanelDoorsControl.Show(false);

		switch(val)
		{
			case "info":
				SetupMHPanelInfo();
				m_MHPanelInfo.Show(true);
			break;
			case "dControl":
				SetupDoorControlInfo();
				m_MHPanelDoorsControl.Show(true);
			break;
			case "request":
				SetupDoorRequests();
				m_MHPanelRequests.Show(true);
			break;
		}
	}

	void SetupMHPanelInfo()
	{
		HouseData hd = g_HM.m_House.m_HouseData;
		m_MHTextHouseName.SetText(hd.BuldingName);
		m_MHDescription.SetText(hd.BuldingDescription);
		//HouseManager.CalcRightHeight(m_MHDescription, hd.BuldingDescription.Length());
		m_MHTextRentDate.SetText(hd.MainOwner.Date);
		int val = hd.MainOwner.RentTimeLeft / 60;
		m_MHTextRentTime.SetText(val.ToString());
		m_MHTextRentPrice.SetText(hd.RentPrice.ToString());
		val = 0;
		for (int i = 0; i < hd.DoorsData.Count(); i++)
		{
			val += hd.DoorsData.Get(i).Renters.Count();
		}
		m_MHTextGuestNum.SetText(val.ToString());
		val = hd.DoorsData.Count();
		m_MHTextDoorCount.SetText(val.ToString());
	}

	void SetupDoorControlInfo()
	{
		ClearAllChildren(m_MHWrapDoorsId);
		HouseData hd = g_HM.m_House.m_HouseData;
		FillDoorsId(hd, m_MHWrapDoorsId);
	}

	void FillDoorsId(HouseData hd, Widget container)
	{
		m_ForDoorsIds.Clear();
		for (int i = 0; i < hd.DoorsData.Count(); i++)
		{
			HouseDoorData hdd = hd.DoorsData.Get(i);
			Widget dId = GetGame().GetWorkspace().CreateWidgets("BastionMod/BastionHousingSystem/layouts/MHDoorId.layout", container);
			TextWidget tId = TextWidget.Cast(dId.FindAnyWidget("MHDoorIdText"));
			string str = "";
			str = "[ID:"+hdd.Index.ToString()+"]";
			tId.SetText(str);
			dId.SetUserID(hdd.Index);
			Print(dId.GetColor());
			m_ForDoorsIds.Insert(dId);
		}
		m_ForDoorsIds.Debug();
	}

	void FillDoorGuest(int dIndex)
	{
		ClearAllChildren(m_MHWrapGuestsNames);
		m_MHPanelGuestInfo.Show(false);
		HouseData hd = g_HM.m_House.m_HouseData;
		for (int i = 0; i < hd.DoorsData.Count(); i++)
		{
			HouseDoorData hdd = hd.DoorsData.Get(i);
			if (hdd.Index == dIndex)
			{
				for (int j = 0; j < hdd.Renters.Count(); j++)
				{
					HousePersonData hpd = hdd.Renters.Get(j);
					Widget gId = GetGame().GetWorkspace().CreateWidgets("BastionMod/BastionHousingSystem/layouts/MHGuestInfo.layout", m_MHWrapGuestsNames);
					TextWidget tId = TextWidget.Cast(gId.FindAnyWidget("MHGuestInfoName"));
					tId.SetText(hpd.Name);
					gId.SetUserID(j);
				}
				m_CurrentDoorId = i;
			}
		}
	}

	void ClearAllChildren(Widget w)
	{
		while (w.GetChildren())
		{
			w.RemoveChild(w.GetChildren());
		}
	}

	void FillDoorGuestInfo(int dIndex)
	{
		if (m_CurrentDoorId != -1)
		{
			HousePersonData hpd = g_HM.m_House.m_HouseData.DoorsData.Get(m_CurrentDoorId).Renters.Get(dIndex);
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
		if (m_CurrentDoorId != -1)
		{
			RentSuggestion rs = g_HM.m_House.m_HouseData.DoorsData.Get(m_CurrentDoorId).RentSuggestions.Get(dIndex);
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
		FillDoorGuest(m_CurrentDoorId);
	}

	void SetupDoorRequests()
	{
		HouseData hd = g_HM.m_House.m_HouseData;
		ClearAllChildren(m_MHWrapReqDoors);
		FillDoorsId(hd, m_MHWrapReqDoors);
	}

	void FillDoorRequest(int dIndex)
	{
		ClearAllChildren(m_MHWrapGuestsRequests);
		m_MHPanelGuestInfoRequest.Show(false);
		HouseData hd = g_HM.m_House.m_HouseData;
		for (int i = 0; i < hd.DoorsData.Count(); i++)
		{
			HouseDoorData hdd = hd.DoorsData.Get(i);
			if (hdd.Index == dIndex)
			{
				for (int j = 0; j < hdd.RentSuggestions.Count(); j++)
				{
					RentSuggestion rs = hdd.RentSuggestions.Get(j);
					Widget gId = GetGame().GetWorkspace().CreateWidgets("BastionMod/BastionHousingSystem/layouts/MHGuestInfo.layout", m_MHWrapGuestsRequests);
					TextWidget tId = TextWidget.Cast(gId.FindAnyWidget("MHGuestInfoName"));
					tId.SetText(rs.Name);
					gId.SetUserID(j);
				}
				m_CurrentDoorId = i;
			}
		}
	}

	void BlockButton(Widget w)
	{
		for (int i = 0; i < m_ForDoorsIds.Count(); i++)
		{
			if (m_ForDoorsIds.Get(i).FindAnyWidget("ButtonWidget0"))
			{
				m_ForDoorsIds.Get(i).FindAnyWidget("ButtonWidget0").Enable(true);
				m_ForDoorsIds.Get(i).SetColor(COLOR_TRANSPARENT);
			}
		}
		w.GetParent().FindAnyWidget("ButtonWidget0").Enable(false);
		w.GetParent().SetColor(COLOR_ORNG);
		m_MHBtnEditDoorInfo.Show(true);
	}

	void ReloadRequests()
	{
		FillDoorRequest(m_CurrentGuestId);
	}

	void EditDoorInfo()
	{
		ref HouseDoorData hdd = g_HM.m_House.m_HouseData.DoorsData.Get(m_CurrentDoorId);
		if (hdd)
		{
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
		ref HouseDoorData hdd = new HouseDoorData();
		string name = m_MHDoorName.GetText();
		string descip;
		m_MHDescriptionDoor.GetText(descip);
		string price = m_MHDoorRentPrice.GetText();
		string time = m_MHDoorRentTime.GetText();


		hdd.Name = name;
		hdd.Description = descip;
		hdd.RentPrice = price.ToInt();
		hdd.LeaseTime = time.ToInt();
		g_HM.SaveDoorInfo(hdd, m_CurrentDoorId);
	}

	void SetupDoorInfo()
	{
		HouseData hd = g_HM.m_House.m_HouseData;
		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
		for (int i = 0; i < hd.DoorsData.Count(); i++)
		{
			ref HouseDoorData hdd = hd.DoorsData.Get(i);
			if (hdd.Index == m_StartDoorIdx)
			{
				m_DIDoorName.SetText(hdd.Name);
				m_DIPrice.SetText(hdd.RentPrice.ToString());
				m_DITime.SetText(hdd.LeaseTime.ToString());
				m_DIDescription.SetText(hdd.Description);
				for (int j = 0; j < hdd.RentSuggestions.Count(); j++)
				{
					RentSuggestion rs = hdd.RentSuggestions.Get(j);
					if ( (rs.HashID == player.GetIdentity().GetId()) || IsDoorOwner(hdd,player.GetIdentity().GetId()))
					{
						m_DIBtnRequest.Enable(false);
					}
				}
			}
		}
	}

	bool IsDoorOwner(ref HouseDoorData hdd, string uid)
	{
		for (int i = 0; i < hdd.Renters.Count(); i++)
		{
			if (uid == hdd.Renters.Get(i).HashID)
			return true;
		}
		return false;
	}
}
// Проверка класса перед арендой.