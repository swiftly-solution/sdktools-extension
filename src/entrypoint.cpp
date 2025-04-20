#include "entrypoint.h"
#include "entities.h"
#include "raytrace.h"

#include <embedder/src/embedder.h>

//////////////////////////////////////////////////////////////
/////////////////        Core Variables        //////////////
////////////////////////////////////////////////////////////

SH_DECL_HOOK3_void(INetworkServerService, StartupServer, SH_NOATTRIB, 0, const GameSessionConfiguration_t&, ISource2WorldSession*, const char*);

SDKTools g_Ext;
EntityListener g_entListener;
IVPhysics2* g_Physics = nullptr;
CREATE_GLOBALVARS();

dyno::ReturnAction TraceShapeHook(dyno::CallbackType cbType, dyno::IHook& hook);
FunctionHook TraceShape("TraceShape", dyno::CallbackType::Pre, TraceShapeHook, "pppppppppppp", 'b');

//////////////////////////////////////////////////////////////
/////////////////          Core Class          //////////////
////////////////////////////////////////////////////////////

dyno::ReturnAction TraceShapeHook(dyno::CallbackType cbType, dyno::IHook& hook)
{
    /// IVPhysics2* _this, Ray_t& ray, Vector& start, Vector& end, CTraceFilter* filter, trace_t* trace
    IVPhysics2* _this = hook.GetArgument<IVPhysics2*>(0);
    Ray_t* ray = hook.GetArgument<Ray_t*>(1);
    Vector* start = hook.GetArgument<Vector*>(2);
    Vector* end = hook.GetArgument<Vector*>(3);
    CTraceFilter* filter = hook.GetArgument<CTraceFilter*>(4);
    trace_t* trace = hook.GetArgument<trace_t*>(5);
    
    if(g_Physics == nullptr) {
        g_Physics = _this;
        TTraceShape(_this, ray, start, end, filter, trace);
        TTraceShape.Disable();
    }
}

EXT_EXPOSE(g_Ext);
bool SDKTools::Load(std::string& error, SourceHook::ISourceHook *SHPtr, ISmmAPI* ismm, bool late)
{
    SAVE_GLOBALVARS();
    
    GET_IFACE_ANY(GetEngineFactory, g_pNetworkServerService, INetworkServerService, NETWORKSERVERSERVICE_INTERFACE_VERSION);

    g_entListener.Initialize();
    return true;
}

bool SDKTools::Unload(std::string& error)
{
    UnloadHooks();
    g_entListener.Destroy();
    return true;
}

void SDKTools::AllExtensionsLoaded()
{

}

void SDKTools::AllPluginsLoaded()
{

}

void RayTrace_OnPluginLoad(EContext* ctx, std::string plugin_name);

bool SDKTools::OnPluginLoad(std::string pluginName, void* pluginState, PluginKind_t kind, std::string& error)
{
    EContext* ctx = (EContext*)pluginState;

    RayTrace_OnPluginLoad(ctx, pluginName);

    return true;
}

bool SDKTools::OnPluginUnload(std::string pluginName, void* pluginState, PluginKind_t kind, std::string& error)
{
    return true;
}

const char* SDKTools::GetAuthor()
{
    return "Swiftly Development Team";
}

const char* SDKTools::GetName()
{
    return "SDKTools Extension";
}

const char* SDKTools::GetVersion()
{
#ifndef VERSION
    return "Local";
#else
    return VERSION;
#endif
}

const char* SDKTools::GetWebsite()
{
    return "https://swiftlycs2.net/";
}
