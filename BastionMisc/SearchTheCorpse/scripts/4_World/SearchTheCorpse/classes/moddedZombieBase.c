modded class ZombieBase extends DayZInfected
{
	bool							m_ActionsInitialize;
	ref TInputActionMap				m_InputActionMap;
	ref protected ActionManagerBase	m_ActionManager;
	
	ref array<string> dea_arraySearchingUID = new array<string>;
	
	void SetActions()
    {
        AddAction(ActionSearchTheCorpseZombie);
    }
	
	ref array<int> dea_arraySearchingId = new array<int>;
	
	void SetDeAArraySeatchingId(int id)
	{
		if(dea_arraySearchingId == null)
			dea_arraySearchingId = new array<int>;
		
		int idx = dea_arraySearchingId.Find(id);
		if(idx == -1)
		{
			dea_arraySearchingId.Insert(id);
		}
	}
	
	bool GetDeAIsSearching(int id)
	{
		int idx = dea_arraySearchingId.Find(id);
		return idx != -1;
	}
	
	void InitializeActions()
	{
		
		m_InputActionMap = new TInputActionMap;
		SetActions();
		
	}
	
	override void GetActions(typename action_input_type, out array<ActionBase_Basic> actions)
	{
		if(!m_ActionsInitialize)
		{
			m_ActionsInitialize = true;
			InitializeActions();
		}
		
		actions = m_InputActionMap.Get(action_input_type);
	}
	void AddAction(typename actionName)
	{
		ActionBase action = GetActionManager().GetAction(actionName);

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
		ActionBase action = GetActionManager().GetAction(actionName);
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
	
	ActionManagerBase GetActionManager()
	{
		return m_ActionManager;
	}
	
}