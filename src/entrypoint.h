#ifndef _entrypoint_h
#define _entrypoint_h

#define META_IS_SOURCE2 1

#include <swiftly-ext/core.h>
#include <swiftly-ext/extension.h>
#include <swiftly-ext/hooks/NativeHooks.h>

#include <string>
#include "iserver.h"
#include "utils.h"

class GameSessionConfiguration_t
{
};

class IVPhysics2;

class SDKTools : public SwiftlyExt
{
public:
    bool Load(std::string& error, SourceHook::ISourceHook *SHPtr, ISmmAPI* ismm, bool late);
    bool Unload(std::string& error);
    
    void AllExtensionsLoaded();
    void AllPluginsLoaded();

    bool OnPluginLoad(std::string pluginName, void* pluginState, PluginKind_t kind, std::string& error);
    bool OnPluginUnload(std::string pluginName, void* pluginState, PluginKind_t kind, std::string& error);

public:
    const char* GetAuthor();
    const char* GetName();
    const char* GetVersion();
    const char* GetWebsite();
};

extern SDKTools g_Ext;
extern IVPhysics2* g_Physics;
DECLARE_GLOBALVARS();

#endif