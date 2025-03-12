#include "entities.h"
#include <swiftly-ext/event.h>
#include <vector>

std::any tmpret;
CEntityListener g_entityListener;

SH_DECL_MANUALHOOK1_void(StartTouch, 0, 0, 0, CEntityInstance *);
SH_DECL_MANUALHOOK1_void(Touch, 0, 0, 0, CEntityInstance *);
SH_DECL_MANUALHOOK1_void(EndTouch, 0, 0, 0, CEntityInstance *);
SH_DECL_MANUALHOOK1_void(EntityUse, 0, 0, 0, class InputData_t*);
SH_DECL_EXTERN3_void(INetworkServerService, StartupServer, SH_NOATTRIB, 0, const GameSessionConfiguration_t&, ISource2WorldSession*, const char*);

void OnStartTouch(CEntityInstance* ent);
void OnPostStartTouch(CEntityInstance* ent);
void OnTouch(CEntityInstance* ent);
void OnPostTouch(CEntityInstance* ent);
void OnEndTouch(CEntityInstance* ent);
void OnPostEndTouch(CEntityInstance* ent);
void OnUse(class InputData_t* ent);
void OnPostUse(class InputData_t* ent);

void EntityListener::Initialize()
{
    SH_MANUALHOOK_RECONFIGURE(StartTouch, GetOffset("CBaseEntity_StartTouch"), 0, 0);
	SH_MANUALHOOK_RECONFIGURE(Touch, GetOffset("CBaseEntity_Touch"), 0, 0);
	SH_MANUALHOOK_RECONFIGURE(EndTouch, GetOffset("CBaseEntity_EndTouch"), 0, 0);
	SH_MANUALHOOK_RECONFIGURE(EntityUse, GetOffset("CBaseEntity_Use"), 0, 0);

    SH_ADD_HOOK_MEMFUNC(INetworkServerService, StartupServer, g_pNetworkServerService, this, &EntityListener::StartupServer, true);
}

void EntityListener::Destroy()
{
    SH_REMOVE_HOOK_MEMFUNC(INetworkServerService, StartupServer, g_pNetworkServerService, this, &EntityListener::StartupServer, true);

    GameEntitySystem()->RemoveListenerEntity(&g_entityListener);
}

bool bDone = false;
void EntityListener::StartupServer(const GameSessionConfiguration_t& config, ISource2WorldSession*, const char*)
{
    if (bDone) return;
    GameEntitySystem()->AddListenerEntity(&g_entityListener);
    bDone = true;
}

void CEntityListener::OnEntitySpawned(CEntityInstance* pEntity)
{
}

void CEntityListener::OnEntityParentChanged(CEntityInstance* pEntity, CEntityInstance* pNewParent)
{
}

void CEntityListener::OnEntityCreated(CEntityInstance* pEntity)
{
    SH_ADD_MANUALHOOK_STATICFUNC(StartTouch, pEntity, OnStartTouch, false);
    SH_ADD_MANUALHOOK_STATICFUNC(StartTouch, pEntity, OnPostStartTouch, true);
    SH_ADD_MANUALHOOK_STATICFUNC(Touch, pEntity, OnTouch, false);
    SH_ADD_MANUALHOOK_STATICFUNC(Touch, pEntity, OnPostTouch, true);
    SH_ADD_MANUALHOOK_STATICFUNC(EndTouch, pEntity, OnEndTouch, false);
    SH_ADD_MANUALHOOK_STATICFUNC(EndTouch, pEntity, OnPostEndTouch, true);
    SH_ADD_MANUALHOOK_STATICFUNC(EntityUse, pEntity, OnUse, false);
    SH_ADD_MANUALHOOK_STATICFUNC(EntityUse, pEntity, OnPostUse, true);
}

void CEntityListener::OnEntityDeleted(CEntityInstance* pEntity)
{
    SH_REMOVE_MANUALHOOK_STATICFUNC(StartTouch, pEntity, OnStartTouch, false);
    SH_REMOVE_MANUALHOOK_STATICFUNC(StartTouch, pEntity, OnPostStartTouch, true);
    SH_REMOVE_MANUALHOOK_STATICFUNC(Touch, pEntity, OnTouch, false);
    SH_REMOVE_MANUALHOOK_STATICFUNC(Touch, pEntity, OnPostTouch, true);
    SH_REMOVE_MANUALHOOK_STATICFUNC(EndTouch, pEntity, OnEndTouch, false);
    SH_REMOVE_MANUALHOOK_STATICFUNC(EndTouch, pEntity, OnPostEndTouch, true);
    SH_REMOVE_MANUALHOOK_STATICFUNC(EntityUse, pEntity, OnUse, false);
    SH_REMOVE_MANUALHOOK_STATICFUNC(EntityUse, pEntity, OnPostUse, true);
}

void OnStartTouch(CEntityInstance* ent)
{
    if(TriggerEvent("sdktools.ext", "OnEntityStartTouch", { string_format("%p", META_IFACEPTR(CEntityInstance)), "CEntityInstance", string_format("%p", ent), "CEntityInstance" }, tmpret) == EventResult::Stop)
        RETURN_META(MRES_SUPERCEDE);

    RETURN_META(MRES_IGNORED);
}

void OnPostStartTouch(CEntityInstance* ent)
{
    if(TriggerEvent("sdktools.ext", "OnPostEntityStartTouch", { string_format("%p", META_IFACEPTR(CEntityInstance)), "CEntityInstance", string_format("%p", ent), "CEntityInstance" }, tmpret) == EventResult::Stop)
        RETURN_META(MRES_SUPERCEDE);

    RETURN_META(MRES_IGNORED);
}

void OnTouch(CEntityInstance* ent)
{
    if(TriggerEvent("sdktools.ext", "OnEntityTouching", { string_format("%p", META_IFACEPTR(CEntityInstance)), "CEntityInstance", string_format("%p", ent), "CEntityInstance" }, tmpret) == EventResult::Stop)
        RETURN_META(MRES_SUPERCEDE);

    RETURN_META(MRES_IGNORED);
}

void OnPostTouch(CEntityInstance* ent)
{
    if(TriggerEvent("sdktools.ext", "OnPostEntityTouching", { string_format("%p", META_IFACEPTR(CEntityInstance)), "CEntityInstance", string_format("%p", ent), "CEntityInstance" }, tmpret) == EventResult::Stop)
        RETURN_META(MRES_SUPERCEDE);

    RETURN_META(MRES_IGNORED);
}

void OnEndTouch(CEntityInstance* ent)
{
    if(TriggerEvent("sdktools.ext", "OnEntityStopTouch", { string_format("%p", META_IFACEPTR(CEntityInstance)), "CEntityInstance", string_format("%p", ent), "CEntityInstance" }, tmpret) == EventResult::Stop)
        RETURN_META(MRES_SUPERCEDE);

    RETURN_META(MRES_IGNORED);
}

void OnPostEndTouch(CEntityInstance* ent)
{
    if(TriggerEvent("sdktools.ext", "OnPostEntityStopTouch", { string_format("%p", META_IFACEPTR(CEntityInstance)), "CEntityInstance", string_format("%p", ent), "CEntityInstance" }, tmpret) == EventResult::Stop)
        RETURN_META(MRES_SUPERCEDE);

    RETURN_META(MRES_IGNORED);
}

void OnUse(class InputData_t* ent)
{
    if(TriggerEvent("sdktools.ext", "OnEntityUse", { string_format("%p", META_IFACEPTR(CEntityInstance)), "CEntityInstance", string_format("%p", ent->pActivator), "CEntityInstance", string_format("%p", ent->pCaller), "CEntityInstance", ent->nOutputID }, tmpret) == EventResult::Stop)
        RETURN_META(MRES_SUPERCEDE);

    RETURN_META(MRES_IGNORED);
}

void OnPostUse(class InputData_t* ent)
{
    if(TriggerEvent("sdktools.ext", "OnPostEntityUse", { string_format("%p", META_IFACEPTR(CEntityInstance)), "CEntityInstance", string_format("%p", ent->pActivator), "CEntityInstance", string_format("%p", ent->pCaller), "CEntityInstance", ent->nOutputID }, tmpret) == EventResult::Stop)
        RETURN_META(MRES_SUPERCEDE);

    RETURN_META(MRES_IGNORED);
}
