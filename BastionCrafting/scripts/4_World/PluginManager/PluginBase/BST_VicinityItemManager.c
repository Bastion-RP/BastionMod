// Credits to class VicinityItemManager.
// This was adapted to be used to grab containers in the vicinity of a crafting bench

class BST_VicinityItemManager : PluginBase {
    private const float CONE_HEIGHT_MIN = -0.5;
    private const float CONE_HEIGHT_MAX = 3.0;

    private bool IsObstructed(Object object, PlayerBase player) {
        bool isObstructed = false;
        vector objectCenterPos;
        vector objectContactPos;
        vector objectContactDir;
        vector raycastStart;
        int contactComponent;
        array<ref RaycastRVResult> arrayHitProxyObjects = new array<ref RaycastRVResult>();
        set<Object> setHitObjects = new set<Object>();
        EntityAI entity;

        Class.CastTo(entity, object);

        if (object.MemoryPointExists("ce_center")) {
            vector modelPos = object.GetMemoryPointPos("ce_center");
            objectCenterPos = object.ModelToWorld(modelPos);
        } else if (entity.IsMan()) {
            if (PlayerBase.Cast(entity)) {
                objectCenterPos = PlayerBase.Cast(entity).GetBonePositionWS(PlayerBase.Cast(entity).GetBoneIndexByName("Pelvis"));
            }
        } else if (entity.IsZombie() || entity.IsZombieMilitary()) {
            if (ZombieBase.Cast(entity)) {
                objectCenterPos = ZombieBase.Cast(entity).ModelToWorld(ZombieBase.Cast(entity).GetSelectionPositionOld("Pelvis"));
            }
        } else {
            objectCenterPos = object.GetPosition();
            objectCenterPos[1] = objectCenterPos[1] + 0.2;
        }

        MiscGameplayFunctions.GetHeadBonePos(player, raycastStart);

        if (object.HasProxyParts() || object.CanUseConstruction()) {
            RaycastRVParams rayInput = new RaycastRVParams(raycastStart, objectCenterPos, player);

            DayZPhysics.RaycastRVProxy(rayInput, arrayHitProxyObjects);

            if (arrayHitProxyObjects) {
                if (arrayHitProxyObjects.Count() > 0) {
                    if (arrayHitProxyObjects[0].hierLevel > 0) {
                        if (arrayHitProxyObjects[0].parent) {
                            if (!arrayHitProxyObjects[0].parent.IsMan()) {
                                EntityAI parent = EntityAI.Cast(arrayHitProxyObjects[0].parent);

                                if (parent.GetInventory().GetCargo()) {
                                    isObstructed = true;
                                } else {
                                    isObstructed = false;
                                }
                            }
                        }
                    }
                }
            }
        } else {
            if (setHitObjects) {
                setHitObjects.Clear();
                DayZPhysics.RaycastRV(raycastStart, objectCenterPos, objectContactPos, objectContactDir, contactComponent, setHitObjects, null, player, false, false, ObjIntersectFire, 0.0, CollisionFlags.ALLOBJECTS);
            }
        }
        foreach (Object hitObject : setHitObjects) {
            if (hitObject.IsBuilding()) {
                isObstructed = true;
                break;
            }
            if (hitObject.IsPlainObject()) {
                isObstructed = true;
                break;
            }
        }
        return isObstructed;
    }

    array<EntityAI> RefreshVicinityItems(PlayerBase player) {
        array<EntityAI> arrayVicinityItems = new array<EntityAI>();
        array<Object> arrayVicinityObjects = new array<Object>();
        array<CargoBase> proxyCargos = new array<CargoBase>();
        float vicinityDistance = GetBSTCraftingManager().GetConfig().GetVicinityDistance();

        if (arrayVicinityItems) {
            arrayVicinityItems.Clear();
        }
        GetGame().GetObjectsAtPosition3D(player.GetPosition(), vicinityDistance, arrayVicinityObjects, proxyCargos);

        foreach (Object object : arrayVicinityObjects) {
            EntityAI entity = EntityAI.Cast(object);

            if (entity && entity.GetInventory().GetCargo() && vector.DistanceSq(player.GetPosition(), entity.GetPosition()) < vicinityDistance * vicinityDistance && !IsObstructed(entity, player)) {
                arrayVicinityItems.Insert(entity);
            }
        }
        return arrayVicinityItems;
    }
}

BST_VicinityItemManager GetBSTVicinityItemManager() {
    return BST_VicinityItemManager.Cast(GetPlugin(BST_VicinityItemManager));
}