#ifndef _entrypoint_h
#define _entrypoint_h

#define META_IS_SOURCE2 1

#include <string>
#include "utils.h"

#include <swiftly-ext/core.h>
#include <swiftly-ext/extension.h>
#include <swiftly-ext/hooks/function.h>
#include <swiftly-ext/hooks/vfunction.h>

#pragma once
#include <embedder/src/embedder.h>
template<class T>
struct Stack;
template<>
struct Stack<Vector>
{
    static void pushLua(EContext* ctx, Vector value)
    {
        MAKE_CLASS_INSTANCE_CTX(ctx, "Vector", { { "vector_ptr", value } }).pushLua();
    }

    static JSValue pushJS(EContext* ctx, Vector value)
    {
        return JS_DupValue(ctx->GetJSState(), MAKE_CLASS_INSTANCE_CTX(ctx, "Vector", { { "vector_ptr", value } }).pushJS());
    }

    static Vector getLua(EContext* ctx, int ref)
    {
        return EValue(ctx, ref, false).cast<ClassData*>()->GetData<Vector>("vector_ptr");
    }

    static Vector getJS(EContext* ctx, JSValue value)
    {
        return EValue(ctx, value).cast<ClassData*>()->GetData<Vector>("vector_ptr");
    }

    static bool isLuaInstance(EContext* ctx, int ref)
    {
        return EValue(ctx, ref, false).cast<ClassData*>()->HasData("vector_ptr");
    }

    static bool isJSInstance(EContext* ctx, JSValue value)
    {
        return EValue(ctx, value).cast<ClassData*>()->HasData("vector_ptr");
    }
};

template<>
struct Stack<Vector2D>
{
    static void pushLua(EContext* ctx, Vector2D value)
    {
        MAKE_CLASS_INSTANCE_CTX(ctx, "Vector2D", { { "Vector2D_ptr", value } }).pushLua();
    }

    static JSValue pushJS(EContext* ctx, Vector2D value)
    {
        return JS_DupValue(ctx->GetJSState(), MAKE_CLASS_INSTANCE_CTX(ctx, "Vector2D", { { "Vector2D_ptr", value } }).pushJS());
    }

    static Vector2D getLua(EContext* ctx, int ref)
    {
        return EValue(ctx, ref, false).cast<ClassData*>()->GetData<Vector2D>("Vector2D_ptr");
    }

    static Vector2D getJS(EContext* ctx, JSValue value)
    {
        return EValue(ctx, value).cast<ClassData*>()->GetData<Vector2D>("Vector2D_ptr");
    }

    static bool isLuaInstance(EContext* ctx, int ref)
    {
        return EValue(ctx, ref, false).cast<ClassData*>()->HasData("Vector2D_ptr");
    }

    static bool isJSInstance(EContext* ctx, JSValue value)
    {
        return EValue(ctx, value).cast<ClassData*>()->HasData("Vector2D_ptr");
    }
};

template<>
struct Stack<Vector4D>
{
    static void pushLua(EContext* ctx, Vector4D value)
    {
        MAKE_CLASS_INSTANCE_CTX(ctx, "Vector4D", { { "Vector4D_ptr", value } }).pushLua();
    }

    static JSValue pushJS(EContext* ctx, Vector4D value)
    {
        return JS_DupValue(ctx->GetJSState(), MAKE_CLASS_INSTANCE_CTX(ctx, "Vector4D", { { "Vector4D_ptr", value } }).pushJS());
    }

    static Vector4D getLua(EContext* ctx, int ref)
    {
        return EValue(ctx, ref, false).cast<ClassData*>()->GetData<Vector4D>("Vector4D_ptr");
    }

    static Vector4D getJS(EContext* ctx, JSValue value)
    {
        return EValue(ctx, value).cast<ClassData*>()->GetData<Vector4D>("Vector4D_ptr");
    }

    static bool isLuaInstance(EContext* ctx, int ref)
    {
        return EValue(ctx, ref, false).cast<ClassData*>()->HasData("Vector4D_ptr");
    }

    static bool isJSInstance(EContext* ctx, JSValue value)
    {
        return EValue(ctx, value).cast<ClassData*>()->HasData("Vector4D_ptr");
    }
};

template<>
struct Stack<Color>
{
    static void pushLua(EContext* ctx, Color value)
    {
        MAKE_CLASS_INSTANCE_CTX(ctx, "Color", { { "Color_ptr", value } }).pushLua();
    }

    static JSValue pushJS(EContext* ctx, Color value)
    {
        return JS_DupValue(ctx->GetJSState(), MAKE_CLASS_INSTANCE_CTX(ctx, "Color", { { "Color_ptr", value } }).pushJS());
    }

    static Color getLua(EContext* ctx, int ref)
    {
        return EValue(ctx, ref, false).cast<ClassData*>()->GetData<Color>("Color_ptr");
    }

    static Color getJS(EContext* ctx, JSValue value)
    {
        return EValue(ctx, value).cast<ClassData*>()->GetData<Color>("Color_ptr");
    }

    static bool isLuaInstance(EContext* ctx, int ref)
    {
        return EValue(ctx, ref, false).cast<ClassData*>()->HasData("Color_ptr");
    }

    static bool isJSInstance(EContext* ctx, JSValue value)
    {
        return EValue(ctx, value).cast<ClassData*>()->HasData("Color_ptr");
    }
};

template<>
struct Stack<QAngle>
{
    static void pushLua(EContext* ctx, QAngle value)
    {
        MAKE_CLASS_INSTANCE_CTX(ctx, "QAngle", { { "QAngle_ptr", value } }).pushLua();
    }

    static JSValue pushJS(EContext* ctx, QAngle value)
    {
        return JS_DupValue(ctx->GetJSState(), MAKE_CLASS_INSTANCE_CTX(ctx, "QAngle", { { "QAngle_ptr", value } }).pushJS());
    }

    static QAngle getLua(EContext* ctx, int ref)
    {
        return EValue(ctx, ref, false).cast<ClassData*>()->GetData<QAngle>("QAngle_ptr");
    }

    static QAngle getJS(EContext* ctx, JSValue value)
    {
        return EValue(ctx, value).cast<ClassData*>()->GetData<QAngle>("QAngle_ptr");
    }

    static bool isLuaInstance(EContext* ctx, int ref)
    {
        return EValue(ctx, ref, false).cast<ClassData*>()->HasData("QAngle_ptr");
    }

    static bool isJSInstance(EContext* ctx, JSValue value)
    {
        return EValue(ctx, value).cast<ClassData*>()->HasData("QAngle_ptr");
    }
};

#include "iserver.h"

class GameSessionConfiguration_t
{
};

class IVPhysics2;

class SDKTools : public SwiftlyExt
{
public:
    bool Load(std::string& error, SourceHook::ISourceHook* SHPtr, ISmmAPI* ismm, bool late);
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