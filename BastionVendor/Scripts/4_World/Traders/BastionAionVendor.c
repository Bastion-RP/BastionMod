class BRP_VendingMachine_Base extends House
{
	protected ref TInputActionMap m_InputActionMap;

    bool m_ActionsInitialize;

    void BRP_VendingMachine_Base()
    {
        if ( GetGame().IsServer() )
		{
			//SetAllowDamage( false );

			GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( OnInitServer, 250 );
		}

		if ( GetGame().IsClient() || !GetGame().IsMultiplayer() )
		{
			GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( OnInitClient, 1000 );
		}
    }

    void ~BRP_VendingMachine_Base()
    {

    }

	void OnInitServer()
	{

	}

	void OnInitClient()
	{
		
	}

	void SetActions()
	{
		AddAction( ActionTrade );
	}

	void InitializeActions()
	{
		m_InputActionMap = new TInputActionMap;

		SetActions();
	}

	override void GetActions(typename action_input_type, out array<ActionBase_Basic> actions)
	{
		if ( !m_ActionsInitialize )
		{
			m_ActionsInitialize = true;

			InitializeActions();
		}

		actions = m_InputActionMap.Get(action_input_type);
	}

	void AddAction(typename actionName)
	{
		ActionBase action = ActionManagerBase.GetAction(actionName);

		typename ai = action.GetInputType();
		if(!ai)
		{
			m_ActionsInitialize = false;
			return;
		}

		ref array<ActionBase_Basic> action_array = m_InputActionMap.Get( ai );

		if(!action_array)
		{
			action_array = new array<ActionBase_Basic>;
			m_InputActionMap.Insert(ai, action_array);
		}
		action_array.Insert(action); 
	}

	void RemoveAction(typename actionName)
	{
		ActionBase action = ActionManagerBase.GetAction(actionName);
		typename ai = action.GetInputType();
		ref array<ActionBase_Basic> action_array = m_InputActionMap.Get( ai );

		if(action_array)
		{
			for(int i = 0; i < action_array.Count(); i++)
			{
				if(action == action_array.Get(i))
				{
					action_array.Remove(i);
				}
			}
			action_array = new array<ActionBase_Basic>;
			m_InputActionMap.Insert(ai, action_array);
		}
		action_array.Insert(action); 
	}

	override bool IsInventoryVisible()
	{
		return false;
	}

	override bool CanDisplayCargo()
	{
		return false;
	}
}