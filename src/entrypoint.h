#ifndef _entrypoint_h
#define _entrypoint_h

#define META_IS_SOURCE2 1

#include <string>
#include "utils.h"

#include <swiftly-ext/core.h>
#include <swiftly-ext/extension.h>
#include <swiftly-ext/hooks/function.h>
#include <swiftly-ext/hooks/vfunction.h>

#include <embedder/src/Embedder.h>
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

    static ClassData* pushRawDotnet(EContext* ctx, CallContext* context, Vector value)
    {
        return (ClassData*)MAKE_CLASS_INSTANCE_CTX(ctx, "Vector", { { "vector_ptr", value } }).getPointer();
    }

    static void pushDotnet(EContext* ctx, CallContext* context, Vector value, bool shouldReturn = false)
    {
        ClassData* val = pushRawDotnet(ctx, context, value);

        if (shouldReturn) {
            context->SetReturnType(typesMap[typeid(void*)]);
            context->SetResult(val);
        }
        else {
            context->SetArgumentType(context->GetArgumentCount(), typesMap[typeid(void*)]);
            context->PushArgument(val);
        }
    }

    static Vector getLua(EContext* ctx, int ref)
    {
        return EValue(ctx, ref, false).cast<ClassData*>()->GetData<Vector>("vector_ptr");
    }

    static Vector getJS(EContext* ctx, JSValue value)
    {
        return EValue(ctx, value).cast<ClassData*>()->GetData<Vector>("vector_ptr");
    }

    static Vector getRawDotnet(EContext* ctx, CallContext* context, void* value)
    {
        return EValue(ctx, value, 18).cast<ClassData*>()->GetData<Vector>("vector_ptr");
    }

    static Vector getDotnet(EContext* ctx, CallContext* context, int index)
    {
        if (index == -1) return getRawDotnet(ctx, context, context->GetResultPtr());
        else return getRawDotnet(ctx, context, context->GetArgumentPtr(index));
    }

    static bool isLuaInstance(EContext* ctx, int ref)
    {
        return EValue(ctx, ref, false).cast<ClassData*>()->HasData("vector_ptr");
    }

    static bool isJSInstance(EContext* ctx, JSValue value)
    {
        return EValue(ctx, value).cast<ClassData*>()->HasData("vector_ptr");
    }

    static bool isDotnetInstance(EContext* ctx, CallContext* context, int index)
    {
        return EValue(ctx, context->GetArgumentPtr(index), 18).cast<ClassData*>()->HasData("vector_ptr");
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

    static ClassData* pushRawDotnet(EContext* ctx, CallContext* context, Vector2D value)
    {
        return (ClassData*)MAKE_CLASS_INSTANCE_CTX(ctx, "Vector2D", { { "Vector2D_ptr", value } }).getPointer();
    }

    static void pushDotnet(EContext* ctx, CallContext* context, Vector2D value, bool shouldReturn = false)
    {
        ClassData* val = pushRawDotnet(ctx, context, value);

        if (shouldReturn) {
            context->SetReturnType(typesMap[typeid(void*)]);
            context->SetResult(val);
        }
        else {
            context->SetArgumentType(context->GetArgumentCount(), typesMap[typeid(void*)]);
            context->PushArgument(val);
        }
    }

    static Vector2D getLua(EContext* ctx, int ref)
    {
        return EValue(ctx, ref, false).cast<ClassData*>()->GetData<Vector2D>("Vector2D_ptr");
    }

    static Vector2D getJS(EContext* ctx, JSValue value)
    {
        return EValue(ctx, value).cast<ClassData*>()->GetData<Vector2D>("Vector2D_ptr");
    }

    static Vector2D getRawDotnet(EContext* ctx, CallContext* context, void* value)
    {
        return EValue(ctx, value, 18).cast<ClassData*>()->GetData<Vector2D>("Vector2D_ptr");
    }

    static Vector2D getDotnet(EContext* ctx, CallContext* context, int index)
    {
        if (index == -1) return getRawDotnet(ctx, context, context->GetResultPtr());
        else return getRawDotnet(ctx, context, context->GetArgumentPtr(index));
    }

    static bool isLuaInstance(EContext* ctx, int ref)
    {
        return EValue(ctx, ref, false).cast<ClassData*>()->HasData("Vector2D_ptr");
    }

    static bool isJSInstance(EContext* ctx, JSValue value)
    {
        return EValue(ctx, value).cast<ClassData*>()->HasData("Vector2D_ptr");
    }

    static bool isDotnetInstance(EContext* ctx, CallContext* context, int index)
    {
        return EValue(ctx, context->GetArgumentPtr(index), 18).cast<ClassData*>()->HasData("Vector2D_ptr");
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

    static ClassData* pushRawDotnet(EContext* ctx, CallContext* context, Vector4D value)
    {
        return (ClassData*)MAKE_CLASS_INSTANCE_CTX(ctx, "Vector4D", { { "Vector4D_ptr", value } }).getPointer();
    }

    static void pushDotnet(EContext* ctx, CallContext* context, Vector4D value, bool shouldReturn = false)
    {
        ClassData* val = pushRawDotnet(ctx, context, value);

        if (shouldReturn) {
            context->SetReturnType(typesMap[typeid(void*)]);
            context->SetResult(val);
        }
        else {
            context->SetArgumentType(context->GetArgumentCount(), typesMap[typeid(void*)]);
            context->PushArgument(val);
        }
    }

    static Vector4D getLua(EContext* ctx, int ref)
    {
        return EValue(ctx, ref, false).cast<ClassData*>()->GetData<Vector4D>("Vector4D_ptr");
    }

    static Vector4D getJS(EContext* ctx, JSValue value)
    {
        return EValue(ctx, value).cast<ClassData*>()->GetData<Vector4D>("Vector4D_ptr");
    }

    static Vector4D getRawDotnet(EContext* ctx, CallContext* context, void* value)
    {
        return EValue(ctx, value, 18).cast<ClassData*>()->GetData<Vector4D>("Vector4D_ptr");
    }

    static Vector4D getDotnet(EContext* ctx, CallContext* context, int index)
    {
        if (index == -1) return getRawDotnet(ctx, context, context->GetResultPtr());
        else return getRawDotnet(ctx, context, context->GetArgumentPtr(index));
    }

    static bool isLuaInstance(EContext* ctx, int ref)
    {
        return EValue(ctx, ref, false).cast<ClassData*>()->HasData("Vector4D_ptr");
    }

    static bool isJSInstance(EContext* ctx, JSValue value)
    {
        return EValue(ctx, value).cast<ClassData*>()->HasData("Vector4D_ptr");
    }

    static bool isDotnetInstance(EContext* ctx, CallContext* context, int index)
    {
        return EValue(ctx, context->GetArgumentPtr(index), 18).cast<ClassData*>()->HasData("Vector4D_ptr");
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

    static ClassData* pushRawDotnet(EContext* ctx, CallContext* context, Color value)
    {
        return (ClassData*)MAKE_CLASS_INSTANCE_CTX(ctx, "Color", { { "Color_ptr", value } }).getPointer();
    }

    static void pushDotnet(EContext* ctx, CallContext* context, Color value, bool shouldReturn = false)
    {
        ClassData* val = pushRawDotnet(ctx, context, value);

        if (shouldReturn) {
            context->SetReturnType(typesMap[typeid(void*)]);
            context->SetResult(val);
        }
        else {
            context->SetArgumentType(context->GetArgumentCount(), typesMap[typeid(void*)]);
            context->PushArgument(val);
        }
    }

    static Color getLua(EContext* ctx, int ref)
    {
        return EValue(ctx, ref, false).cast<ClassData*>()->GetData<Color>("Color_ptr");
    }

    static Color getJS(EContext* ctx, JSValue value)
    {
        return EValue(ctx, value).cast<ClassData*>()->GetData<Color>("Color_ptr");
    }

    static Color getRawDotnet(EContext* ctx, CallContext* context, void* value)
    {
        return EValue(ctx, value, 18).cast<ClassData*>()->GetData<Color>("Color_ptr");
    }

    static Color getDotnet(EContext* ctx, CallContext* context, int index)
    {
        if (index == -1) return getRawDotnet(ctx, context, context->GetResultPtr());
        else return getRawDotnet(ctx, context, context->GetArgumentPtr(index));
    }

    static bool isLuaInstance(EContext* ctx, int ref)
    {
        return EValue(ctx, ref, false).cast<ClassData*>()->HasData("Color_ptr");
    }

    static bool isJSInstance(EContext* ctx, JSValue value)
    {
        return EValue(ctx, value).cast<ClassData*>()->HasData("Color_ptr");
    }

    static bool isDotnetInstance(EContext* ctx, CallContext* context, int index)
    {
        return EValue(ctx, context->GetArgumentPtr(index), 18).cast<ClassData*>()->HasData("Color_ptr");
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

    static ClassData* pushRawDotnet(EContext* ctx, CallContext* context, QAngle value)
    {
        return (ClassData*)MAKE_CLASS_INSTANCE_CTX(ctx, "QAngle", { { "QAngle_ptr", value } }).getPointer();
    }

    static void pushDotnet(EContext* ctx, CallContext* context, QAngle value, bool shouldReturn = false)
    {
        ClassData* val = pushRawDotnet(ctx, context, value);

        if (shouldReturn) {
            context->SetReturnType(typesMap[typeid(void*)]);
            context->SetResult(val);
        }
        else {
            context->SetArgumentType(context->GetArgumentCount(), typesMap[typeid(void*)]);
            context->PushArgument(val);
        }
    }

    static QAngle getLua(EContext* ctx, int ref)
    {
        return EValue(ctx, ref, false).cast<ClassData*>()->GetData<QAngle>("QAngle_ptr");
    }

    static QAngle getJS(EContext* ctx, JSValue value)
    {
        return EValue(ctx, value).cast<ClassData*>()->GetData<QAngle>("QAngle_ptr");
    }

    static QAngle getRawDotnet(EContext* ctx, CallContext* context, void* value)
    {
        return EValue(ctx, value, 18).cast<ClassData*>()->GetData<QAngle>("QAngle_ptr");
    }

    static QAngle getDotnet(EContext* ctx, CallContext* context, int index)
    {
        if (index == -1) return getRawDotnet(ctx, context, context->GetResultPtr());
        else return getRawDotnet(ctx, context, context->GetArgumentPtr(index));
    }

    static bool isLuaInstance(EContext* ctx, int ref)
    {
        return EValue(ctx, ref, false).cast<ClassData*>()->HasData("QAngle_ptr");
    }

    static bool isJSInstance(EContext* ctx, JSValue value)
    {
        return EValue(ctx, value).cast<ClassData*>()->HasData("QAngle_ptr");
    }

    static bool isDotnetInstance(EContext* ctx, CallContext* context, int index)
    {
        return EValue(ctx, context->GetArgumentPtr(index), 18).cast<ClassData*>()->HasData("QAngle_ptr");
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