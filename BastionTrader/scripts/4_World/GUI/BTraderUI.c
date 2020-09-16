class BTraderUI extends UIScriptedMenu
{
	private ScrollWidget		m_ScrollWidgetMainContent;
	private ScrollWidget		m_ScrollRequirement;
	private ScrollWidget		m_ProductScroll;

	private XComboBoxWidget 	m_XComboBoxCategory;

	private EditBoxWidget		m_EditBoxSearch;

	private WrapSpacerWidget	m_WrapMainContent;
	private WrapSpacerWidget	m_WrapRequirements;

	private ProgressBarWidget	m_TraderProgress;
	private Widget				m_Overlay;

	private ItemPreviewWidget	m_ItemPreview;
	private MultilineTextWidget m_ProductDescription;
	private TextWidget			m_EditBoxCount;

	private ButtonWidget		m_DecCountBtn;
	private ButtonWidget		m_IncCountBtn;
	private ButtonWidget		m_TradeBtn;

	//===========================================


	private ref TraderData		traderData;
	private int countMdfr;
	private int cooldown;
	private bool isCooldown;

	private Widget				currentWidget;

	private ref map<Widget, ref BTraderProductData>	ResultsHolder;
	private ref array<EntityAI> localEntities;


	private const int	RESULT_BTN_ID = 302;
	private const float PROGRESS_STEP = 10;

	override Widget Init()
	{
        layoutRoot = GetGame().GetWorkspace().CreateWidgets( "BastionMod/BastionTrader/layouts/bTrader.layout" );

		m_ScrollWidgetMainContent 	= ScrollWidget.Cast(GetWid("ScrollWidgetMainContent"));
		m_ScrollRequirement 		= ScrollWidget.Cast(GetWid("ScrollRequirement"));
		m_ProductScroll 			= ScrollWidget.Cast(GetWid("ProductScroll"));

		m_XComboBoxCategory			= XComboBoxWidget.Cast(GetWid("XComboBoxCategory"));
		m_EditBoxSearch				= EditBoxWidget.Cast(GetWid("EditBoxSearch"));

		m_TraderProgress			= ProgressBarWidget.Cast(GetWid("TraderProgress"));
		m_Overlay					= Widget.Cast(GetWid("Overlay"));

		m_WrapMainContent			= WrapSpacerWidget.Cast(GetWid("WrapMainContent"));
		m_WrapRequirements			= WrapSpacerWidget.Cast(GetWid("WrapRequirements"));

		m_ItemPreview				= ItemPreviewWidget.Cast(GetWid("ItemPreview"));
		m_ProductDescription		= MultilineTextWidget.Cast(GetWid("ProductDescription"));
		m_EditBoxCount				= TextWidget.Cast(GetWid("EditBoxCount"));

		m_DecCountBtn				= ButtonWidget.Cast(GetWid("DecCountBtn"));
		m_IncCountBtn				= ButtonWidget.Cast(GetWid("IncCountBtn"));
		m_TradeBtn					= ButtonWidget.Cast(GetWid("TradeBtn"));

		SetupContent();

		return layoutRoot;
	}

	void BTraderUI(TraderData data)
	{
		GetGame().GetMission().PlayerControlDisable( INPUT_EXCLUDE_ALL );

		traderData = data;
		localEntities = new array<EntityAI>();
		ResultsHolder = new map<Widget, ref BTraderProductData>();
		cooldown = GetBTraderManager().GetConfig().GetCD() * 1000;
		isCooldown = false;
	}

	void ~BTraderUI()
	{
		GetGame().GetMission().PlayerControlEnable( true );
		DestroyLocalEntities();
	}

	Widget GetWid(string val)
	{
		return layoutRoot.FindAnyWidget(val);
	}

	Widget GetCurrentWidget()
	{
		return currentWidget;
	}

	override void Update(float timeslice)
	{
		super.Update(timeslice);

		Input input = GetGame().GetInput();

		if (input.LocalPress("UAUIBack",false))
		{
			Close();
		}
	}

	override void OnShow()
	{
		super.OnShow();
		GetGame().GetMission().GetHud().Show(false);
		PPEffects.SetBlurInventory(0.8);
	}

	override void OnHide()
	{
		super.OnHide();
		GetGame().GetMission().GetHud().Show(true);
		PPEffects.SetBlurInventory(0);
	}

	void FillContent(ref TraderData data = null)
	{
		if (data)
		{traderData = data;}

		if (!traderData) return;

		if (GetBTraderManager().CanTrade(traderData) == false)
		{
			Close();
			g_HM.ShowBastionNotification("You can't trade");
		}

		HideOverlay();

		int count;
		string category;
		BTraderArticleData good;

		ClearAll();

		array<ref BTraderArticleData> allGoods = traderData.GetGoods();

		count = allGoods.Count();

		for (int i = 0; i < count; i++)
		{
			good = allGoods.Get(i);
			category = good.GetCategory();

			m_XComboBoxCategory.AddItem(category);
		}

		m_XComboBoxCategory.SetCurrentItem(0);
		FillResults(0);

	}

	void HideOverlay()
	{
		m_Overlay.Show(false);
	}

	void ShowOverlay()
	{
		m_Overlay.Show(true);
	}

	void FillResults(int idx)
	{
		DestroyAllChildren(m_WrapMainContent);

		int index;
		int count;

		array<ref BTraderProductData> allProducts;
		BTraderArticleData good;
		BTraderProductData product;

		index = idx;

		good = traderData.GetGoods()[index];

		allProducts = good.GetProducts();
		count = allProducts.Count();

		for (int i = 0; i < count; i++)
		{
			product = allProducts.Get(i);

			if (!product) continue;

			CreateProductCard(product);
		}
	}

	void CreateProductCard(ref BTraderProductData product)
	{
		Widget widget;
		ItemPreviewWidget itemPlaceholder;
		MultilineTextWidget	itemName;
		EntityAI localEnt;
		string itemType;
		string itemDisName;

		widget = GetGame().GetWorkspace().CreateWidgets( "BastionMod/BastionTrader/layouts/ProductCard.layout", m_WrapMainContent );

		if (!widget) return;

		itemPlaceholder = ItemPreviewWidget.Cast(widget.FindAnyWidget("ProductItemPreview"));
		itemName 		= MultilineTextWidget.Cast(widget.FindAnyWidget("ProductName"));

		itemType = product.GetResult().GetType();

		localEnt = GetGame().CreateObject(itemType, vector.Zero, true, false);

		if (!localEnt) return;

		itemDisName = localEnt.GetDisplayName();

		itemName.SetText(itemDisName);
		itemPlaceholder.SetItem(localEnt);
		itemPlaceholder.SetModelPosition( Vector( 0, 0, 0.5 ) );
		itemPlaceholder.SetModelOrientation( vector.Zero );
		itemPlaceholder.SetView( localEnt.GetViewIndex() );

		ResultsHolder.Insert(widget, product);
		localEntities.Insert(localEnt);
	}

	void SetupContent()
	{
		FillContent();


	}

	void ClearAll()
	{
		m_XComboBoxCategory.ClearAll();
		ResultsHolder.Clear();
		countMdfr = 1;

		DestroyAllChildren(m_WrapMainContent);
		DestroyAllChildren(m_WrapRequirements);
		DestroyLocalEntities();
	}

	void DestroyAllChildren(Widget w)
	{
		while (w.GetChildren())
		{
			w.RemoveChild(w.GetChildren());
		}
	}

	void DestroyLocalEntities()
	{
		if (!localEntities || !localEntities.Count()) return;

		foreach (auto ent : localEntities)
		{
			if (ent)
			{
				ent.Delete();
			}
		}
		delete localEntities;
	}

	override bool OnClick(Widget w, int x, int y, int button)
	{
		super.OnClick(w,x,y,button);

		switch (w.GetUserID())
		{
			case RESULT_BTN_ID:
				OnResultSelect(w.GetParent());
			break;
		}

		if (w == m_XComboBoxCategory)
		{
			SwithCategory();
		}

		switch (w)
		{
			case m_DecCountBtn:
				ChangeModifier(0);
			break;
			case m_IncCountBtn:
				ChangeModifier(1);
			break;
			case m_TradeBtn:
				ClickOnTrade();
			break;
		}

		return true;
	}

	override bool OnMouseEnter(Widget w, int x, int y)
	{
		super.OnMouseEnter(w,x,y);

		if (w == m_EditBoxSearch)
		{
			ClearPlaceholder();
		}

		return true;
	}

	void ClearPlaceholder()
	{
		string text;

		text = m_EditBoxSearch.GetText();

		if (text == "Search") m_EditBoxSearch.SetText("");
	}

	void ChangeModifier(int type)
	{
		if (type)
		{countMdfr++;}
		else
		{countMdfr--;}
		
		if (countMdfr <= 0)
		countMdfr = 1;

		m_EditBoxCount.SetText(countMdfr.ToString());

		OnResultSelect(currentWidget);
	}

	void SwithCategory()
	{
		int idx;

		idx = m_XComboBoxCategory.GetCurrentItem();

		FillResults(idx);
	}

	void OnResultSelect(Widget w)
	{
		DestroyAllChildren(m_WrapRequirements);// clear requirment conatent
		m_TradeBtn.Enable(true);

		BTraderProductData product;
		array<ref DefaultItemData> requiredProducts;
		DefaultItemData reqProduct;
		int count;

		if (ResultsHolder.Find(w, product))
		{
			currentWidget = w;
			requiredProducts = product.GetReqItems();

			count = requiredProducts.Count();
			
			for (int i = 0; i < count; i++)
			{
				reqProduct = requiredProducts.Get(i);

				if (!reqProduct) continue;

				CreteRequiredCard(reqProduct);
			}
			FillItemInfo(product);
		}
	}

	void FillItemInfo(BTraderProductData product)
	{
		ClearItemInfo();

		string itemType;
		string itemDescrip;
		string itemName;
		EntityAI localEnt;
		ItemBase itemB;

		itemType = product.GetResult().GetType();

		localEnt = GetGame().CreateObject(itemType, vector.Zero, true, false);

		if (!localEnt) return;

		itemName = localEnt.GetDisplayName();

		if (Class.CastTo(itemB,localEnt))
		{
			itemDescrip = itemB.GetTooltip();
			SetDecriptionWidgetSize(itemDescrip.Length());
			m_ProductDescription.SetText(itemDescrip);			
		}

		m_ItemPreview.SetItem(localEnt);
		m_ItemPreview.SetModelPosition( Vector( 0, 0, 0.5 ) );
		m_ItemPreview.SetModelOrientation( vector.Zero );
		m_ItemPreview.SetView( localEnt.GetViewIndex() );

		localEntities.Insert(localEnt);
	}

	void ClearItemInfo()
	{
		m_ItemPreview.SetItem(null);	
		m_ProductDescription.SetText("");
	}

	void SetDecriptionWidgetSize(int len)
	{
		int lines = len / 80;
		float width, height;

		m_ProductDescription.GetSize(width, height);

		height = 0.03;

		height = height + lines * 0.03;

		m_ProductDescription.SetSize(width, height);
	}

	void CreteRequiredCard(DefaultItemData data)
	{
		Widget widget;
		ItemPreviewWidget itemPlaceholder;
		MultilineTextWidget	itemName;
		MultilineTextWidget	itemCount;
		EntityAI localEnt;
		string itemType;
		string itemDisName;
		string quantityLabel;
		float quantity;
		float itemQuantity;

		widget = GetGame().GetWorkspace().CreateWidgets( "BastionMod/BastionTrader/layouts/ReqCard.layout", m_WrapRequirements );

		if (!widget) return;

		itemPlaceholder = ItemPreviewWidget.Cast(widget.FindAnyWidget("ReqItemPreview"));
		itemName 		= MultilineTextWidget.Cast(widget.FindAnyWidget("ReqName"));
		itemCount 		= MultilineTextWidget.Cast(widget.FindAnyWidget("ReqCount"));

		itemType = data.GetType();
		quantity = data.GetQuantity() * countMdfr;
		itemQuantity = GetBTraderManager().GetQuantityByType(itemType);

		quantityLabel = string.Format("%1 / %2", itemQuantity, quantity); // TODO set to current items

		localEnt = GetGame().CreateObject(itemType, vector.Zero, true, false);

		if (!localEnt) return;

		itemDisName = localEnt.GetDisplayName();

		itemName.SetText(itemDisName);
		itemPlaceholder.SetItem(localEnt);
		itemPlaceholder.SetModelPosition( Vector( 0, 0, 0.5 ) );
		itemPlaceholder.SetModelOrientation( vector.Zero );
		itemPlaceholder.SetView( localEnt.GetViewIndex() );

		itemCount.SetText(quantityLabel);
		itemCount.SetColor(COLOR_GREEN);

		if (quantity > itemQuantity)
		{
			itemCount.SetColor(COLOR_RED);
			m_TradeBtn.Enable(false);
		}

		localEntities.Insert(localEnt);
	}

	bool OnChange(Widget w, int x, int y, bool finished)
	{
		super.OnChange(w,x,y,finished);

		if (w == m_EditBoxSearch)
		{
			SearchFilter();
		}
		return true;
	}

	void SearchFilter()
	{
		string pattern;
		string name;
		string resultName;
		int count;
		Widget w;

		pattern = m_EditBoxSearch.GetText();
		count = ResultsHolder.Count();
		pattern.ToLower();

		for (int i = 0; i < count; i++)
		{
			resultName = ResultsHolder.GetElement(i).GetResult().GetType();
			name = GetBTraderManager().GetObjectNameByType( resultName );
			name.ToLower();
			w = ResultsHolder.GetKey(i);
			if (name.Contains(pattern) || name == pattern)
			{
				w.Show(true);
			}
			else
			{
				w.Show(false);
			}
		}
	}

	void ClickOnTrade()
	{
		BTraderProductData data;

		if (!isCooldown)
		{
			isCooldown = true;
			FillTradeProgressBar();
			GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( SetCooldown, cooldown, false, false );
			data = ResultsHolder.Get(currentWidget);

			if (!data)
			{
				return;
			}

			GetBTraderManager().RequestTrade(countMdfr, data);
		}
	}

	void FillTradeProgressBar()
	{
		float step = 100 / (cooldown / PROGRESS_STEP ) * 1.3;
		GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallLater(this.FillPGBar, PROGRESS_STEP, true, step);
	}

	void FillPGBar(float step)
	{
		float progress;

		progress = m_TraderProgress.GetCurrent();
		progress += step;
		m_TraderProgress.SetCurrent(progress);

		if (progress >= 100 || !isCooldown)
		{
			progress = 0;
			m_TraderProgress.SetCurrent(progress);
			GetGame().GetCallQueue(CALL_CATEGORY_GUI).Remove(this.FillPGBar);
		}
	}

	void SetCooldown(bool val)
	{
		isCooldown = val;
	}
}