class ActionSearchTheCorpseCB : ActionContinuousBaseCB
{
    override void CreateActionComponent()
    {
    	float timer = GetTimer(m_ActionData.m_Player, PlayerBase.Cast(m_ActionData.m_Target.GetObject() ) );
        m_ActionData.m_ActionComponent = new CAContinuousTime(timer);
    }

    float GetTimer(PlayerBase _player, PlayerBase _target)
	{
		int cargoCount = 0;
		int timeForEachItem = 0;

		GetItemCargoCount(cargoCount, _target);

		if(_player.stcConfig)
		{
			if(_player.stcConfig.AddTimeForEachItem)
			{
				timeForEachItem = _player.stcConfig.TimeForEachItem;
			}

			return _player.stcConfig.DefaultTimeToSearchPlayer + (timeForEachItem * cargoCount);
		}

		return 10;
	}

	void GetItemCargoCount(out int cargoCount, PlayerBase _player )
	{
		int attCount = _player.GetHumanInventory().AttachmentCount();
		CargoBase cargo = null;
		//! go thru the each attachment slot and check cargo count
		for(int attIdx = 0; attIdx < attCount; attIdx++)
		{
			EntityAI attachment = _player.GetInventory().GetAttachmentFromIndex(attIdx);
			int attachmentSlot = attachment.GetInventory().GetSlotId(0);
			if( attachment.GetInventory() )
			{
				cargo = attachment.GetInventory().GetCargo();
				if( cargo )
				{
					cargoCount += cargo.GetItemCount();
				}
			}
			
		}
		
		return;
	}
};
class ActionSearchTheCorpseZombieCB : ActionContinuousBaseCB
{
    override void CreateActionComponent()
    {
    	float timer = GetTimer(m_ActionData.m_Player, EntityAI.Cast(m_ActionData.m_Target.GetObject() ) );
        m_ActionData.m_ActionComponent = new CAContinuousTime(timer);
    }

    float GetTimer(PlayerBase _player, EntityAI _target)
	{
		int cargoCount = 0;
		int timeForEachItem = 0;
		
		GetItemCargoCount(cargoCount, _target);

		if(_player.stcConfig)
		{
			if(_player.stcConfig.AddTimeForEachItem)
			{
				timeForEachItem = _player.stcConfig.TimeForEachItem;
			}

			return _player.stcConfig.DefaultTimeToSearchZombie + (timeForEachItem * cargoCount);
		}

		return 10;
	}

	void GetItemCargoCount(out int cargoCount, EntityAI entity )
	{
		CargoBase cargo = null;
		if(entity.GetInventory())
		{
			cargo = entity.GetInventory().GetCargo();

			if (cargo)
			{
				cargoCount = cargo.GetItemCount();
				return;
			}
		}

	}
};

class ActionSearchTheCorpse : ActionContinuousBase
{
	
    
    void ActionSearchTheCorpse()
    {
       	m_CallbackClass = ActionSearchTheCorpseCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_CRAFTING;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
    }
    
    override void CreateConditionComponents()  
    {   
        m_ConditionItem = new CCINone;
		m_ConditionTarget = new DeA_CCTMan(UAMaxDistances.DEFAULT,false);
    }

	override typename GetInputType()
	{
		return ContinuousInteractActionInput;
	}
	
    override string GetText()
    {
        return "#STR_DeA_ActionSearchTheCorpse";
    }

    override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
    {
        EntityAI targetEntity = EntityAI.Cast(target.GetObject());

        if (targetEntity && targetEntity.IsPlayer())
        {
            PlayerBase targetPlayer = PlayerBase.Cast(target.GetObject());

            if (!targetEntity.IsAlive() && !targetPlayer.GetDeAIsSearching(player.GetID()))
            {
                return true;
            }
        }
		
        return false;
    }

    override void OnFinishProgressServer(ActionData action_data)
    {
        PlayerBase targetPlayer = PlayerBase.Cast(action_data.m_Target.GetObject());
		targetPlayer.SetDeAArraySeatchingId(action_data.m_Player.GetID());
		
    }

    override void OnFinishProgressClient(ActionData action_data)
    {
        PlayerBase targetPlayer = PlayerBase.Cast(action_data.m_Target.GetObject());
		targetPlayer.SetDeAArraySeatchingId(action_data.m_Player.GetID());
    }
}

class ActionSearchTheCorpseZombie : ActionContinuousBase
{
    
    void ActionSearchTheCorpseZombie()
    {
       	m_CallbackClass = ActionSearchTheCorpseZombieCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_CRAFTING;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
    }
    
    override void CreateConditionComponents()  
    {   
        m_ConditionItem = new CCINone;
		m_ConditionTarget = new DeA_CCTZombie(UAMaxDistances.DEFAULT);
    }

	override typename GetInputType()
	{
		return ContinuousInteractActionInput;
	}
	
    override string GetText()
    {
        return "#STR_DeA_ActionSearchTheCorpse";
    }

    override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
    {
        EntityAI targetEntity = EntityAI.Cast(target.GetObject());

		if (targetEntity && (targetEntity.IsZombie() || targetEntity.IsZombieMilitary() ) )
        {
			ZombieBase targetZombie = ZombieBase.Cast(target.GetObject());
            
            if (!targetZombie.IsAlive() && !targetZombie.GetDeAIsSearching(player.GetID()))
            {
                return true;
            }
        }
        return false;
    }

    override void OnFinishProgressServer(ActionData action_data)
    {
        ZombieBase targetZombie = ZombieBase.Cast(action_data.m_Target.GetObject());
		targetZombie.SetDeAArraySeatchingId(action_data.m_Player.GetID());
		
    }

    override void OnFinishProgressClient(ActionData action_data)
    {
        ZombieBase targetZombie = ZombieBase.Cast(action_data.m_Target.GetObject());
		targetZombie.SetDeAArraySeatchingId(action_data.m_Player.GetID());
    }
}

class DeA_CCTZombie : CCTBase
{
	protected float m_MaximalActionDistanceSq;
	protected bool m_MustBeAlive;
	
	void DeA_CCTZombie ( float maximal_target_distance )
	{
		m_MaximalActionDistanceSq = maximal_target_distance * maximal_target_distance;	
	}
	
	override bool Can( PlayerBase player, ActionTarget target )
	{	
		if( !target )
			return false;
		
		Object targetObject = target.GetObject();
		if ( !player || !targetObject || targetObject == player || !targetObject.IsMan() )
		{
			EntityAI entityAI = EntityAI.Cast(targetObject);
			if( !entityAI.IsZombie() && !entityAI.IsZombieMilitary())
				return false;
		}
		
		return ( vector.DistanceSq(targetObject.GetPosition(), player.GetPosition()) <= m_MaximalActionDistanceSq );
	}
};

class DeA_CCTMan : CCTBase
{
	protected float m_MaximalActionDistanceSq;
	protected bool m_MustBeAlive;
	
	void DeA_CCTMan ( float maximal_target_distance, bool must_be_alive = true )
	{
		m_MaximalActionDistanceSq = maximal_target_distance * maximal_target_distance;	
		m_MustBeAlive = must_be_alive;
	}
	
	override bool Can( PlayerBase player, ActionTarget target )
	{	
		if( !target )
			return false;
		
		Object targetObject = target.GetObject();
		if ( !player || !targetObject || targetObject == player || !targetObject.IsMan() || ( m_MustBeAlive && targetObject.IsDamageDestroyed() ) )
			return false;
		
		return ( vector.DistanceSq(targetObject.GetPosition(), player.GetPosition()) <= m_MaximalActionDistanceSq );
	}
};