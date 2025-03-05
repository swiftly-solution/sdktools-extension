#include "raytrace.h"
#include "entrypoint.h"
#include <Embedder.h>

void RayTrace_OnPluginLoad(EContext* ctx, std::string plugin_name)
{
    BeginClass<bbox_t>("BBox", ctx)
        .addConstructor<>()
        .addProperty("mins", &bbox_t::mins)
        .addProperty("maxs", &bbox_t::maxs)
    .endClass();

    BeginClass<CInternalTraceFilter>("CTraceFilter", ctx)
        .addConstructor<>()
        .addProperty("InteractsWith", &CInternalTraceFilter::m_nInteractsWith)
        .addProperty("InteractsExclude", &CInternalTraceFilter::m_nInteractsExclude)
        .addProperty("InteractsAs", &CInternalTraceFilter::m_nInteractsAs)
        .addProperty("EntityIdsToIgnore", &CInternalTraceFilter::m_nEntityIdsToIgnore)
        .addProperty("OwnerIdsToIgnore", &CInternalTraceFilter::m_nOwnerIdsToIgnore)
        .addProperty("HierarchyIds", &CInternalTraceFilter::m_nHierarchyIds)
        .addProperty("ObjectSetMask", &CInternalTraceFilter::m_nObjectSetMask)
        .addProperty("CollisionGroup", &CInternalTraceFilter::m_nCollisionGroup)
        .addProperty("HitSolid", &CInternalTraceFilter::m_bHitSolid)
        .addProperty("HitSolidRequiresGenerateContacts", &CInternalTraceFilter::m_bHitSolidRequiresGenerateContacts)
        .addProperty("HitTrigger", &CInternalTraceFilter::m_bHitTrigger)
        .addProperty("ShouldIgnoreDisabledPairs", &CInternalTraceFilter::m_bShouldIgnoreDisabledPairs)
        .addProperty("IgnoreIfBothInteractWithHitboxes", &CInternalTraceFilter::m_bIgnoreIfBothInteractWithHitboxes)
        .addProperty("ForceHitEverything", &CInternalTraceFilter::m_bForceHitEverything)
        .addProperty("Unknown", &CInternalTraceFilter::m_bUnknown)
        .addProperty("IterateEntities", &CInternalTraceFilter::m_bIterateEntities)
        .addFunction("Save", &CInternalTraceFilter::Save)
    .endClass();

    BeginClass<CPhysSurfacePropertiesPhysics>("CPhysSurfacePropertiesPhysics", ctx)
        .addConstructor<>()
        .addProperty("friction", &CPhysSurfacePropertiesPhysics::m_friction)
        .addProperty("elasticity", &CPhysSurfacePropertiesPhysics::m_elasticity)
        .addProperty("density", &CPhysSurfacePropertiesPhysics::m_density)
        .addProperty("thickness", &CPhysSurfacePropertiesPhysics::m_thickness)
        .addProperty("softContactFrequency", &CPhysSurfacePropertiesPhysics::m_softContactFrequency)
        .addProperty("softContactDampingRatio", &CPhysSurfacePropertiesPhysics::m_softContactDampingRatio)
        .addProperty("wheelDrag", &CPhysSurfacePropertiesPhysics::m_wheelDrag)
    .endClass();

    BeginClass<CPhysSurfacePropertiesAudio>("CPhysSurfacePropertiesAudio", ctx)
        .addConstructor<>()
        .addProperty("reflectivity", &CPhysSurfacePropertiesAudio::m_reflectivity)
        .addProperty("hardnessFactor", &CPhysSurfacePropertiesAudio::m_hardnessFactor)
        .addProperty("roughnessFactor", &CPhysSurfacePropertiesAudio::m_roughnessFactor)
        .addProperty("roughThreshold", &CPhysSurfacePropertiesAudio::m_roughThreshold)
        .addProperty("hardThreshold", &CPhysSurfacePropertiesAudio::m_hardThreshold)
        .addProperty("hardVelocityThreshold", &CPhysSurfacePropertiesAudio::m_hardVelocityThreshold)
        .addProperty("StaticImpactVolume", &CPhysSurfacePropertiesAudio::m_flStaticImpactVolume)
        .addProperty("OcclusionFactor", &CPhysSurfacePropertiesAudio::m_flOcclusionFactor)
    .endClass();

    BeginClass<CPhysSurfacePropertiesSoundNames>("CPhysSurfacePropertiesSoundNames", ctx)
        .addConstructor<>()
        .addProperty("impactSoft", &CPhysSurfacePropertiesSoundNames::m_impactSoft)
        .addProperty("impactHard", &CPhysSurfacePropertiesSoundNames::m_impactHard)
        .addProperty("scrapeSmooth", &CPhysSurfacePropertiesSoundNames::m_scrapeSmooth)
        .addProperty("scrapeRough", &CPhysSurfacePropertiesSoundNames::m_scrapeRough)
        .addProperty("bulletImpact", &CPhysSurfacePropertiesSoundNames::m_bulletImpact)
        .addProperty("rolling", &CPhysSurfacePropertiesSoundNames::m_rolling)
        .addProperty("break", &CPhysSurfacePropertiesSoundNames::m_break)
        .addProperty("strain", &CPhysSurfacePropertiesSoundNames::m_strain)
        .addProperty("meleeImpact", &CPhysSurfacePropertiesSoundNames::m_meleeImpact)
        .addProperty("pushOff", &CPhysSurfacePropertiesSoundNames::m_pushOff)
        .addProperty("skidStop", &CPhysSurfacePropertiesSoundNames::m_skidStop)
    .endClass();

    BeginClass<CPhysSurfaceProperties>("CPhysSurfaceProperties", ctx)
        .addConstructor<>()
        .addProperty("name", &CPhysSurfaceProperties::m_name)
        .addProperty("nameHash", &CPhysSurfaceProperties::m_nameHash)
        .addProperty("baseNameHash", &CPhysSurfaceProperties::m_baseNameHash)
        .addProperty("ListIndex", &CPhysSurfaceProperties::m_nListIndex)
        .addProperty("BaseListIndex", &CPhysSurfaceProperties::m_nBaseListIndex)
        .addProperty("Hidden", &CPhysSurfaceProperties::m_bHidden)
        .addProperty("description", &CPhysSurfaceProperties::m_description)
        .addProperty("physics", &CPhysSurfaceProperties::m_physics)
        .addProperty("audioSounds", &CPhysSurfaceProperties::m_audioSounds)
        .addProperty("audioParams", &CPhysSurfaceProperties::m_audioParams)
    .endClass();

    BeginClass<CHitBox>("CHitBox", ctx)
        .addConstructor<>()
        .addProperty("name", &CHitBox::m_name)
        .addProperty("SurfaceProperty", &CHitBox::m_sSurfaceProperty)
        .addProperty("BoneName", &CHitBox::m_sBoneName)
        .addProperty("MinBounds", &CHitBox::m_vMinBounds)
        .addProperty("MaxBounds", &CHitBox::m_vMaxBounds)
        .addProperty("ShapeRadius", &CHitBox::m_flShapeRadius)
        .addProperty("BoneNameHash", &CHitBox::m_nBoneNameHash)
        .addProperty("GroupId", &CHitBox::m_nGroupId)
        .addProperty("ShapeType", &CHitBox::m_nShapeType)
        .addProperty("TranslationOnly", &CHitBox::m_bTranslationOnly)
        .addProperty("CRC", &CHitBox::m_CRC)
        .addProperty("RenderColor", &CHitBox::m_cRenderColor)
        .addProperty("HitBoxIndex", &CHitBox::m_nHitBoxIndex)
        .addProperty("ShouldForceTransform", &CHitBox::m_bForcedTransform)
    .endClass();

    BeginClass<RnCollisionAttr_t>("RnCollisionAttr_t", ctx)
        .addConstructor<>()
        .addProperty("InteractsAs", &RnCollisionAttr_t::m_nInteractsAs)
        .addProperty("InteractsWith", &RnCollisionAttr_t::m_nInteractsWith)
        .addProperty("InteractsExclude", &RnCollisionAttr_t::m_nInteractsExclude)
        .addProperty("EntityId", &RnCollisionAttr_t::m_nEntityId)
        .addProperty("OwnerId", &RnCollisionAttr_t::m_nOwnerId)
        .addProperty("HierarchyId", &RnCollisionAttr_t::m_nHierarchyId)
        .addProperty("CollisionGroup", &RnCollisionAttr_t::m_nCollisionGroup)
        .addProperty("CollisionFunctionMask", &RnCollisionAttr_t::m_nCollisionFunctionMask)
    .endClass();

    BeginClass<CGameTraceInternal>("trace_t", ctx)
        .addConstructor<>()
        .addProperty("SurfaceProperties", &CGameTraceInternal::m_pSurfaceProperties)
        .addProperty("Hitbox", &CGameTraceInternal::m_pHitbox)
        .addProperty("Contents", &CGameTraceInternal::m_nContents)
        .addProperty("ShapeAttributes", &CGameTraceInternal::m_ShapeAttributes)
        .addProperty("StartPos", &CGameTraceInternal::m_vStartPos)
        .addProperty("EndPos", &CGameTraceInternal::m_vEndPos)
        .addProperty("HitNormal", &CGameTraceInternal::m_vHitNormal)
        .addProperty("HitPoint", &CGameTraceInternal::m_vHitPoint)
        .addProperty("HitOffset", &CGameTraceInternal::m_flHitOffset)
        .addProperty("Fraction", &CGameTraceInternal::m_flFraction)
        .addProperty("Triangle", &CGameTraceInternal::m_nTriangle)
        .addProperty("HitboxBoneIndex", &CGameTraceInternal::m_nHitboxBoneIndex)
        .addProperty("RayType", &CGameTraceInternal::m_eRayType)
        .addProperty("StartInSolid", &CGameTraceInternal::m_bStartInSolid)
        .addProperty("ExactHitPoint", &CGameTraceInternal::m_bExactHitPoint)
        .addFunction("GetEntity", &CGameTraceInternal::GetEntity)
        .addFunction("SyncToTrace", &CGameTraceInternal::SyncToTrace)
        .addFunction("SyncFromTrace", &CGameTraceInternal::SyncFromTrace)
        .addFunction("GetRawTrace", &CGameTraceInternal::GetRawTracePtr)
    .endClass();

    BeginClass<InternalRay_t>("Ray_t", ctx)
        .addConstructor<>()
        .addFunction("InitLine", &InternalRay_t::InitLine)
        .addFunction("InitSphere", &InternalRay_t::InitSphere)
        .addFunction("InitHull", &InternalRay_t::InitHull)
        .addFunction("InitCapsule", &InternalRay_t::InitCapsule)
        .addFunction("InitMesh", &InternalRay_t::InitMesh)
        .addFunction("GetRayPtr", &InternalRay_t::GetRayPtr)
        .addFunction("GetType", &InternalRay_t::GetType)
    .endClass();

    BeginClass<RayTrace>("RayTrace", ctx)
        .addConstructor<std::string>()
        .addFunction("TracePlayerBBox", &RayTrace::TracePlayerBBox)
        .addFunction("TraceShape", &RayTrace::TraceShape)
    .endClass();

    GetGlobalNamespace(ctx)
        .beginNamespace("RayType_t")
            .addConstant("RAY_TYPE_LINE", (uint64_t)RayType_t::RAY_TYPE_LINE)
            .addConstant("RAY_TYPE_SPHERE", (uint64_t)RayType_t::RAY_TYPE_SPHERE)
            .addConstant("RAY_TYPE_HULL", (uint64_t)RayType_t::RAY_TYPE_HULL)
            .addConstant("RAY_TYPE_CAPSULE", (uint64_t)RayType_t::RAY_TYPE_CAPSULE)
            .addConstant("RAY_TYPE_MESH", (uint64_t)RayType_t::RAY_TYPE_MESH)
        .endNamespace()
        .beginNamespace("CollisionFunctionMask_t")
            .addConstant("FCOLLISION_FUNC_ENABLE_SOLID_CONTACT", (uint64_t)CollisionFunctionMask_t::FCOLLISION_FUNC_ENABLE_SOLID_CONTACT)
            .addConstant("FCOLLISION_FUNC_ENABLE_TRACE_QUERY", (uint64_t)CollisionFunctionMask_t::FCOLLISION_FUNC_ENABLE_TRACE_QUERY)
            .addConstant("FCOLLISION_FUNC_ENABLE_TOUCH_EVENT", (uint64_t)CollisionFunctionMask_t::FCOLLISION_FUNC_ENABLE_TOUCH_EVENT)
            .addConstant("FCOLLISION_FUNC_ENABLE_SELF_COLLISIONS", (uint64_t)CollisionFunctionMask_t::FCOLLISION_FUNC_ENABLE_SELF_COLLISIONS)
            .addConstant("FCOLLISION_FUNC_IGNORE_FOR_HITBOX_TEST", (uint64_t)CollisionFunctionMask_t::FCOLLISION_FUNC_IGNORE_FOR_HITBOX_TEST)
            .addConstant("FCOLLISION_FUNC_ENABLE_TOUCH_PERSISTS", (uint64_t)CollisionFunctionMask_t::FCOLLISION_FUNC_ENABLE_TOUCH_PERSISTS)
        .endNamespace()
        .beginNamespace("RnQueryObjectSet")
            .addConstant("RNQUERY_OBJECTS_STATIC", (uint64_t)RnQueryObjectSet::RNQUERY_OBJECTS_STATIC)
            .addConstant("RNQUERY_OBJECTS_DYNAMIC", (uint64_t)RnQueryObjectSet::RNQUERY_OBJECTS_DYNAMIC)
            .addConstant("RNQUERY_OBJECTS_NON_COLLIDEABLE", (uint64_t)RnQueryObjectSet::RNQUERY_OBJECTS_NON_COLLIDEABLE)
            .addConstant("RNQUERY_OBJECTS_KEYFRAMED_ONLY", (uint64_t)RnQueryObjectSet::RNQUERY_OBJECTS_KEYFRAMED_ONLY)
            .addConstant("RNQUERY_OBJECTS_DYNAMIC_ONLY", (uint64_t)RnQueryObjectSet::RNQUERY_OBJECTS_DYNAMIC_ONLY)
            .addConstant("RNQUERY_OBJECTS_ALL_GAME_ENTITIES", (uint64_t)RnQueryObjectSet::RNQUERY_OBJECTS_ALL_GAME_ENTITIES)
            .addConstant("RNQUERY_OBJECTS_ALL", (uint64_t)RnQueryObjectSet::RNQUERY_OBJECTS_ALL)
        .endNamespace()
        .beginNamespace("HitboxShapeType_t")
            .addConstant("HITBOX_SHAPE_HULL", (uint64_t)HitboxShapeType_t::HITBOX_SHAPE_HULL)
            .addConstant("HITBOX_SHAPE_SPHERE", (uint64_t)HitboxShapeType_t::HITBOX_SHAPE_SPHERE)
            .addConstant("HITBOX_SHAPE_CAPSULE", (uint64_t)HitboxShapeType_t::HITBOX_SHAPE_CAPSULE)
        .endNamespace();

    GetGlobalNamespace(ctx).addConstant("raytrace", RayTrace(plugin_name));
}

RayTrace::RayTrace(std::string plugin_name)
{
    m_plugin_name = plugin_name;
}

void RayTrace::TracePlayerBBox(Vector *start, Vector *end, bbox_t *bounds, CInternalTraceFilter *filter, CGameTraceInternal* trace)
{
    void* sig = GetSignature("TracePlayerBBox");
    if(sig == nullptr) return;

    reinterpret_cast<TracePlayerBBox_t>(sig)(*start, *end, *bounds, filter->GetRawTraceFilter(), *trace->GetRawTrace());
}

void RayTrace::TraceShape(Vector* start, Vector* end, InternalRay_t* ray, CInternalTraceFilter *filter, CGameTraceInternal* trace)
{
    void* sig = GetSignature("TraceShape");
    if(sig == nullptr) return;

    reinterpret_cast<TraceShape_t>(sig)(g_Physics, *(ray->GetRawRay()), *start, *end, filter->GetRawTraceFilter(), trace->GetRawTrace());
}