#include "entrypoint.h"
#include "entities.h"

//////////////////////////////////////////////////////////////
/////////////////        Core Variables        //////////////
////////////////////////////////////////////////////////////

SH_DECL_HOOK3_void(INetworkServerService, StartupServer, SH_NOATTRIB, 0, const GameSessionConfiguration_t&, ISource2WorldSession*, const char*);

SDKTools g_Ext;
EntityListener g_entListener;
CUtlVector<FuncHookBase *> g_vecHooks;
CREATE_GLOBALVARS();

//////////////////////////////////////////////////////////////
/////////////////          Core Class          //////////////
////////////////////////////////////////////////////////////

EXT_EXPOSE(g_Ext);
bool SDKTools::Load(std::string& error, SourceHook::ISourceHook *SHPtr, ISmmAPI* ismm, bool late)
{
    SAVE_GLOBALVARS();
    
    GET_IFACE_ANY(GetEngineFactory, g_pNetworkServerService, INetworkServerService, NETWORKSERVERSERVICE_INTERFACE_VERSION);

    if(!InitializeHooks()) {
        error = "Failed to initialize hooks.";
        return false;
    }

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

bool SDKTools::OnPluginLoad(std::string pluginName, void* pluginState, PluginKind_t kind, std::string& error)
{
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
