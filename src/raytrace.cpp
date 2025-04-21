#include "raytrace.h"
#include "entrypoint.h"
#include <swiftly-ext/memory.h>
#include <embedder/src/Embedder.h>

void RayTrace_OnPluginLoad(EContext* ctx, std::string plugin_name)
{
    ADD_CLASS("BBox");

    ADD_CLASS_FUNCTION("BBox", "BBox", [](FunctionContext* context, ClassData* data) -> void {
        data->SetData("bbox_ptr", new bbox_t());
        });

    ADD_CLASS_FUNCTION("BBox", "~BBox", [](FunctionContext* context, ClassData* data) -> void {
        if (data->HasData("bbox_ptr")) {
            delete data->GetData<bbox_t*>("bbox_ptr");
        }
        });

    ADD_CLASS_MEMBER("BBox", "mins", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<bbox_t*>("bbox_ptr")->mins);
        },
        [](FunctionContext* context, ClassData* data) -> void {
            Vector value = context->GetArgumentOr<Vector>(0, Vector(0.0, 0.0, 0.0));
            data->GetData<bbox_t*>("bbox_ptr")->mins = value;
        });

    ADD_CLASS_MEMBER("BBox", "maxs", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<bbox_t*>("bbox_ptr")->maxs);
        },
        [](FunctionContext* context, ClassData* data) -> void {
            Vector value = context->GetArgumentOr<Vector>(0, Vector(0.0, 0.0, 0.0));
            data->GetData<bbox_t*>("bbox_ptr")->maxs = value;
        });

    ADD_CLASS("CTraceFilter");

    ADD_CLASS_FUNCTION("CTraceFilter", "CTraceFilter", [](FunctionContext* context, ClassData* data) -> void {
        data->SetData("ctracefilter_ptr", new CInternalTraceFilter());
        });

    ADD_CLASS_FUNCTION("CTraceFilter", "~CTraceFilter", [](FunctionContext* context, ClassData* data) -> void {
        if (data->HasData("ctracefilter_ptr")) {
            delete data->GetData<CInternalTraceFilter*>("ctracefilter_ptr");
        }
        });

    ADD_CLASS_MEMBER("CTraceFilter", "InteractsWith", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<CInternalTraceFilter*>("ctracefilter_ptr")->m_nInteractsWith);
        },
        [](FunctionContext* context, ClassData* data) -> void {
            uint64_t value = context->GetArgumentOr<uint64_t>(0, 0);
            data->GetData<CInternalTraceFilter*>("ctracefilter_ptr")->m_nInteractsWith = value;
        });

    ADD_CLASS_MEMBER("CTraceFilter", "InteractsExclude", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<CInternalTraceFilter*>("ctracefilter_ptr")->m_nInteractsExclude);
        },
        [](FunctionContext* context, ClassData* data) -> void {
            uint64_t value = context->GetArgumentOr<uint64_t>(0, 0);
            data->GetData<CInternalTraceFilter*>("ctracefilter_ptr")->m_nInteractsExclude = value;
        });

    ADD_CLASS_MEMBER("CTraceFilter", "InteractsAs", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<CInternalTraceFilter*>("ctracefilter_ptr")->m_nInteractsAs);
        },
        [](FunctionContext* context, ClassData* data) -> void {
            uint64_t value = context->GetArgumentOr<uint64_t>(0, 0);
            data->GetData<CInternalTraceFilter*>("ctracefilter_ptr")->m_nInteractsAs = value;
        });

    ADD_CLASS_MEMBER("CTraceFilter", "EntityIdsToIgnore", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<CInternalTraceFilter*>("ctracefilter_ptr")->m_nEntityIdsToIgnore);
        },
        [](FunctionContext* context, ClassData* data) -> void {
            std::vector<uint32_t> value = context->GetArgumentOr<std::vector<uint32_t>>(0, std::vector<uint32_t>{});
            data->GetData<CInternalTraceFilter*>("ctracefilter_ptr")->m_nEntityIdsToIgnore = value;
        });

    ADD_CLASS_MEMBER("CTraceFilter", "OwnerIdsToIgnore", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<CInternalTraceFilter*>("ctracefilter_ptr")->m_nOwnerIdsToIgnore);
        },
        [](FunctionContext* context, ClassData* data) -> void {
            std::vector<uint32_t> value = context->GetArgumentOr<std::vector<uint32_t>>(0, std::vector<uint32_t>{});
            data->GetData<CInternalTraceFilter*>("ctracefilter_ptr")->m_nOwnerIdsToIgnore = value;
        });

    ADD_CLASS_MEMBER("CTraceFilter", "HierarchyIds", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<CInternalTraceFilter*>("ctracefilter_ptr")->m_nHierarchyIds);
        },
        [](FunctionContext* context, ClassData* data) -> void {
            std::vector<uint16_t> value = context->GetArgumentOr<std::vector<uint16_t>>(0, std::vector<uint16_t>{});
            data->GetData<CInternalTraceFilter*>("ctracefilter_ptr")->m_nHierarchyIds = value;
        });

    ADD_CLASS_MEMBER("CTraceFilter", "ObjectSetMask", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<CInternalTraceFilter*>("ctracefilter_ptr")->m_nObjectSetMask);
        },
        [](FunctionContext* context, ClassData* data) -> void {
            uint16_t value = context->GetArgumentOr<uint16_t>(0, 0);
            data->GetData<CInternalTraceFilter*>("ctracefilter_ptr")->m_nObjectSetMask = value;
        });

    ADD_CLASS_MEMBER("CTraceFilter", "CollisionGroup", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<CInternalTraceFilter*>("ctracefilter_ptr")->m_nCollisionGroup);
        },
        [](FunctionContext* context, ClassData* data) -> void {
            uint32_t value = context->GetArgumentOr<uint32_t>(0, 0);
            data->GetData<CInternalTraceFilter*>("ctracefilter_ptr")->m_nCollisionGroup = value;
        });

    ADD_CLASS_MEMBER("CTraceFilter", "HitSolid", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<CInternalTraceFilter*>("ctracefilter_ptr")->m_bHitSolid);
        },
        [](FunctionContext* context, ClassData* data) -> void {
            bool value = context->GetArgumentOr<bool>(0, false);
            data->GetData<CInternalTraceFilter*>("ctracefilter_ptr")->m_bHitSolid = value;
        });

    ADD_CLASS_MEMBER("CTraceFilter", "HitSolidRequiresGenerateContacts", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<CInternalTraceFilter*>("ctracefilter_ptr")->m_bHitSolidRequiresGenerateContacts);
        },
        [](FunctionContext* context, ClassData* data) -> void {
            bool value = context->GetArgumentOr<bool>(0, false);
            data->GetData<CInternalTraceFilter*>("ctracefilter_ptr")->m_bHitSolidRequiresGenerateContacts = value;
        });

    ADD_CLASS_MEMBER("CTraceFilter", "HitTrigger", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<CInternalTraceFilter*>("ctracefilter_ptr")->m_nCollisionGroup);
        },
        [](FunctionContext* context, ClassData* data) -> void {
            bool value = context->GetArgumentOr<bool>(0, false);
            data->GetData<CInternalTraceFilter*>("ctracefilter_ptr")->m_bHitTrigger = value;
        });

    ADD_CLASS_MEMBER("CTraceFilter", "ShouldIgnoreDisabledPairs", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<CInternalTraceFilter*>("ctracefilter_ptr")->m_bShouldIgnoreDisabledPairs);
        },
        [](FunctionContext* context, ClassData* data) -> void {
            bool value = context->GetArgumentOr<bool>(0, false);
            data->GetData<CInternalTraceFilter*>("ctracefilter_ptr")->m_bShouldIgnoreDisabledPairs = value;
        });

    ADD_CLASS_MEMBER("CTraceFilter", "IgnoreIfBothInteractWithHitboxes", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<CInternalTraceFilter*>("ctracefilter_ptr")->m_bIgnoreIfBothInteractWithHitboxes);
        },
        [](FunctionContext* context, ClassData* data) -> void {
            bool value = context->GetArgumentOr<bool>(0, false);
            data->GetData<CInternalTraceFilter*>("ctracefilter_ptr")->m_bIgnoreIfBothInteractWithHitboxes = value;
        });

    ADD_CLASS_MEMBER("CTraceFilter", "ForceHitEverything", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<CInternalTraceFilter*>("ctracefilter_ptr")->m_bForceHitEverything);
        },
        [](FunctionContext* context, ClassData* data) -> void {
            bool value = context->GetArgumentOr<bool>(0, false);
            data->GetData<CInternalTraceFilter*>("ctracefilter_ptr")->m_bForceHitEverything = value;
        });

    ADD_CLASS_MEMBER("CTraceFilter", "Unknown", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<CInternalTraceFilter*>("ctracefilter_ptr")->m_bUnknown);
        },
        [](FunctionContext* context, ClassData* data) -> void {
            bool value = context->GetArgumentOr<bool>(0, false);
            data->GetData<CInternalTraceFilter*>("ctracefilter_ptr")->m_bUnknown = value;
        });

    ADD_CLASS_MEMBER("CTraceFilter", "IterateEntities", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<CInternalTraceFilter*>("ctracefilter_ptr")->m_bIterateEntities);
        },
        [](FunctionContext* context, ClassData* data) -> void {
            bool value = context->GetArgumentOr<bool>(0, false);
            data->GetData<CInternalTraceFilter*>("ctracefilter_ptr")->m_bIterateEntities = value;
        });

    ADD_CLASS_FUNCTION("CTraceFilter", "Save", [](FunctionContext* context, ClassData* data) -> void {
        data->GetData<CInternalTraceFilter*>("ctracefilter_ptr")->Save();
        });

    ADD_CLASS("CPhysSurfacePropertiesPhysics");

    ADD_CLASS_FUNCTION("CPhysSurfacePropertiesPhysics", "CPhysSurfacePropertiesPhysics", [](FunctionContext* context, ClassData* data) -> void {
        data->SetData("cphyssurfacepropertiesphysics_ptr", new CPhysSurfacePropertiesPhysics());
        });

    ADD_CLASS_FUNCTION("CPhysSurfacePropertiesPhysics", "~CPhysSurfacePropertiesPhysics", [](FunctionContext* context, ClassData* data) -> void {
        if (data->HasData("cphyssurfacepropertiesphysics_ptr")) {
            delete data->GetData<CPhysSurfacePropertiesPhysics*>("cphyssurfacepropertiesphysics_ptr");
        }
        });

    ADD_CLASS_MEMBER("CPhysSurfacePropertiesPhysics", "friction", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<CPhysSurfacePropertiesPhysics*>("cphyssurfacepropertiesphysics_ptr")->m_friction);
        },
        [](FunctionContext* context, ClassData* data) -> void {
            float value = context->GetArgumentOr<float>(0, 0);
            data->GetData<CPhysSurfacePropertiesPhysics*>("cphyssurfacepropertiesphysics_ptr")->m_friction = value;
        });

    ADD_CLASS_MEMBER("CPhysSurfacePropertiesPhysics", "elasticity", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<CPhysSurfacePropertiesPhysics*>("cphyssurfacepropertiesphysics_ptr")->m_elasticity);
        },
        [](FunctionContext* context, ClassData* data) -> void {
            float value = context->GetArgumentOr<float>(0, 0);
            data->GetData<CPhysSurfacePropertiesPhysics*>("cphyssurfacepropertiesphysics_ptr")->m_elasticity = value;
        });

    ADD_CLASS_MEMBER("CPhysSurfacePropertiesPhysics", "density", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<CPhysSurfacePropertiesPhysics*>("cphyssurfacepropertiesphysics_ptr")->m_density);
        },
        [](FunctionContext* context, ClassData* data) -> void {
            float value = context->GetArgumentOr<float>(0, 0);
            data->GetData<CPhysSurfacePropertiesPhysics*>("cphyssurfacepropertiesphysics_ptr")->m_density = value;
        });

    ADD_CLASS_MEMBER("CPhysSurfacePropertiesPhysics", "thickness", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<CPhysSurfacePropertiesPhysics*>("cphyssurfacepropertiesphysics_ptr")->m_thickness);
        },
        [](FunctionContext* context, ClassData* data) -> void {
            float value = context->GetArgumentOr<float>(0, 0);
            data->GetData<CPhysSurfacePropertiesPhysics*>("cphyssurfacepropertiesphysics_ptr")->m_thickness = value;
        });

    ADD_CLASS_MEMBER("CPhysSurfacePropertiesPhysics", "softContactFrequency", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<CPhysSurfacePropertiesPhysics*>("cphyssurfacepropertiesphysics_ptr")->m_softContactFrequency);
        },
        [](FunctionContext* context, ClassData* data) -> void {
            float value = context->GetArgumentOr<float>(0, 0);
            data->GetData<CPhysSurfacePropertiesPhysics*>("cphyssurfacepropertiesphysics_ptr")->m_softContactFrequency = value;
        });

    ADD_CLASS_MEMBER("CPhysSurfacePropertiesPhysics", "softContactDampingRatio", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<CPhysSurfacePropertiesPhysics*>("cphyssurfacepropertiesphysics_ptr")->m_softContactDampingRatio);
        },
        [](FunctionContext* context, ClassData* data) -> void {
            float value = context->GetArgumentOr<float>(0, 0);
            data->GetData<CPhysSurfacePropertiesPhysics*>("cphyssurfacepropertiesphysics_ptr")->m_softContactDampingRatio = value;
        });

    ADD_CLASS_MEMBER("CPhysSurfacePropertiesPhysics", "wheelDrag", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<CPhysSurfacePropertiesPhysics*>("cphyssurfacepropertiesphysics_ptr")->m_wheelDrag);
        },
        [](FunctionContext* context, ClassData* data) -> void {
            float value = context->GetArgumentOr<float>(0, 0);
            data->GetData<CPhysSurfacePropertiesPhysics*>("cphyssurfacepropertiesphysics_ptr")->m_wheelDrag = value;
        });

    ADD_CLASS("CPhysSurfacePropertiesAudio");

    ADD_CLASS_FUNCTION("CPhysSurfacePropertiesAudio", "CPhysSurfacePropertiesAudio", [](FunctionContext* context, ClassData* data) -> void {
        data->SetData("cphyssurfacepropertiesaudio_ptr", new CPhysSurfacePropertiesAudio());
        });

    ADD_CLASS_FUNCTION("CPhysSurfacePropertiesAudio", "~CPhysSurfacePropertiesAudio", [](FunctionContext* context, ClassData* data) -> void {
        if (data->HasData("cphyssurfacepropertiesaudio_ptr")) {
            delete data->GetData<CPhysSurfacePropertiesAudio*>("cphyssurfacepropertiesaudio_ptr");
        }
        });

    ADD_CLASS_MEMBER("CPhysSurfacePropertiesAudio", "reflectivity", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<CPhysSurfacePropertiesAudio*>("cphyssurfacepropertiesaudio_ptr")->m_reflectivity);
        },
        [](FunctionContext* context, ClassData* data) -> void {
            float value = context->GetArgumentOr<float>(0, 0);
            data->GetData<CPhysSurfacePropertiesAudio*>("cphyssurfacepropertiesaudio_ptr")->m_reflectivity = value;
        });

    ADD_CLASS_MEMBER("CPhysSurfacePropertiesAudio", "hardnessFactor", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<CPhysSurfacePropertiesAudio*>("cphyssurfacepropertiesaudio_ptr")->m_hardnessFactor);
        },
        [](FunctionContext* context, ClassData* data) -> void {
            float value = context->GetArgumentOr<float>(0, 0);
            data->GetData<CPhysSurfacePropertiesAudio*>("cphyssurfacepropertiesaudio_ptr")->m_hardnessFactor = value;
        });

    ADD_CLASS_MEMBER("CPhysSurfacePropertiesAudio", "roughnessFactor", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<CPhysSurfacePropertiesAudio*>("cphyssurfacepropertiesaudio_ptr")->m_roughnessFactor);
        },
        [](FunctionContext* context, ClassData* data) -> void {
            float value = context->GetArgumentOr<float>(0, 0);
            data->GetData<CPhysSurfacePropertiesAudio*>("cphyssurfacepropertiesaudio_ptr")->m_roughnessFactor = value;
        });

    ADD_CLASS_MEMBER("CPhysSurfacePropertiesAudio", "roughThreshold", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<CPhysSurfacePropertiesAudio*>("cphyssurfacepropertiesaudio_ptr")->m_roughThreshold);
        },
        [](FunctionContext* context, ClassData* data) -> void {
            float value = context->GetArgumentOr<float>(0, 0);
            data->GetData<CPhysSurfacePropertiesAudio*>("cphyssurfacepropertiesaudio_ptr")->m_roughThreshold = value;
        });

    ADD_CLASS_MEMBER("CPhysSurfacePropertiesAudio", "hardThreshold", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<CPhysSurfacePropertiesAudio*>("cphyssurfacepropertiesaudio_ptr")->m_hardThreshold);
        },
        [](FunctionContext* context, ClassData* data) -> void {
            float value = context->GetArgumentOr<float>(0, 0);
            data->GetData<CPhysSurfacePropertiesAudio*>("cphyssurfacepropertiesaudio_ptr")->m_hardThreshold = value;
        });

    ADD_CLASS_MEMBER("CPhysSurfacePropertiesAudio", "hardVelocityThreshold", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<CPhysSurfacePropertiesAudio*>("cphyssurfacepropertiesaudio_ptr")->m_hardVelocityThreshold);
        },
        [](FunctionContext* context, ClassData* data) -> void {
            float value = context->GetArgumentOr<float>(0, 0);
            data->GetData<CPhysSurfacePropertiesAudio*>("cphyssurfacepropertiesaudio_ptr")->m_hardVelocityThreshold = value;
        });

    ADD_CLASS_MEMBER("CPhysSurfacePropertiesAudio", "StaticImpactVolume", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<CPhysSurfacePropertiesAudio*>("cphyssurfacepropertiesaudio_ptr")->m_flStaticImpactVolume);
        },
        [](FunctionContext* context, ClassData* data) -> void {
            float value = context->GetArgumentOr<float>(0, 0);
            data->GetData<CPhysSurfacePropertiesAudio*>("cphyssurfacepropertiesaudio_ptr")->m_flStaticImpactVolume = value;
        });

    ADD_CLASS_MEMBER("CPhysSurfacePropertiesAudio", "OcclusionFactor", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<CPhysSurfacePropertiesAudio*>("cphyssurfacepropertiesaudio_ptr")->m_flOcclusionFactor);
        },
        [](FunctionContext* context, ClassData* data) -> void {
            float value = context->GetArgumentOr<float>(0, 0);
            data->GetData<CPhysSurfacePropertiesAudio*>("cphyssurfacepropertiesaudio_ptr")->m_flOcclusionFactor = value;
        });

    ADD_CLASS("CPhysSurfacePropertiesSoundNames");

    ADD_CLASS_FUNCTION("CPhysSurfacePropertiesSoundNames", "CPhysSurfacePropertiesSoundNames", [](FunctionContext* context, ClassData* data) -> void {
        data->SetData("cphyssurfacepropertiessoundnames_ptr", new CPhysSurfacePropertiesSoundNames());
        });

    ADD_CLASS_FUNCTION("CPhysSurfacePropertiesSoundNames", "~CPhysSurfacePropertiesSoundNames", [](FunctionContext* context, ClassData* data) -> void {
        if (data->HasData("cphyssurfacepropertiessoundnames_ptr")) {
            delete data->GetData<CPhysSurfacePropertiesSoundNames*>("cphyssurfacepropertiessoundnames_ptr");
        }
        });

    ADD_CLASS_MEMBER("CPhysSurfacePropertiesSoundNames", "impactSoft", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<CPhysSurfacePropertiesSoundNames*>("cphyssurfacepropertiesaudio_ptr")->m_impactSoft.String());
        },
        [](FunctionContext* context, ClassData* data) -> void {
            std::string value = context->GetArgumentOr<std::string>(0, "");
            data->GetData<CPhysSurfacePropertiesSoundNames*>("cphyssurfacepropertiesaudio_ptr")->m_impactSoft.Set(value.c_str());
        });

    ADD_CLASS_MEMBER("CPhysSurfacePropertiesSoundNames", "impactHard", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<CPhysSurfacePropertiesSoundNames*>("cphyssurfacepropertiesaudio_ptr")->m_impactHard.String());
        },
        [](FunctionContext* context, ClassData* data) -> void {
            std::string value = context->GetArgumentOr<std::string>(0, "");
            data->GetData<CPhysSurfacePropertiesSoundNames*>("cphyssurfacepropertiesaudio_ptr")->m_impactHard.Set(value.c_str());
        });

    ADD_CLASS_MEMBER("CPhysSurfacePropertiesSoundNames", "scrapeSmooth", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<CPhysSurfacePropertiesSoundNames*>("cphyssurfacepropertiesaudio_ptr")->m_scrapeSmooth.String());
        },
        [](FunctionContext* context, ClassData* data) -> void {
            std::string value = context->GetArgumentOr<std::string>(0, "");
            data->GetData<CPhysSurfacePropertiesSoundNames*>("cphyssurfacepropertiesaudio_ptr")->m_scrapeSmooth.Set(value.c_str());
        });

    ADD_CLASS_MEMBER("CPhysSurfacePropertiesSoundNames", "scrapeRough", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<CPhysSurfacePropertiesSoundNames*>("cphyssurfacepropertiesaudio_ptr")->m_scrapeRough.String());
        },
        [](FunctionContext* context, ClassData* data) -> void {
            std::string value = context->GetArgumentOr<std::string>(0, "");
            data->GetData<CPhysSurfacePropertiesSoundNames*>("cphyssurfacepropertiesaudio_ptr")->m_scrapeRough.Set(value.c_str());
        });

    ADD_CLASS_MEMBER("CPhysSurfacePropertiesSoundNames", "bulletImpact", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<CPhysSurfacePropertiesSoundNames*>("cphyssurfacepropertiesaudio_ptr")->m_bulletImpact.String());
        },
        [](FunctionContext* context, ClassData* data) -> void {
            std::string value = context->GetArgumentOr<std::string>(0, "");
            data->GetData<CPhysSurfacePropertiesSoundNames*>("cphyssurfacepropertiesaudio_ptr")->m_bulletImpact.Set(value.c_str());
        });

    ADD_CLASS_MEMBER("CPhysSurfacePropertiesSoundNames", "rolling", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<CPhysSurfacePropertiesSoundNames*>("cphyssurfacepropertiesaudio_ptr")->m_rolling.String());
        },
        [](FunctionContext* context, ClassData* data) -> void {
            std::string value = context->GetArgumentOr<std::string>(0, "");
            data->GetData<CPhysSurfacePropertiesSoundNames*>("cphyssurfacepropertiesaudio_ptr")->m_rolling.Set(value.c_str());
        });

    ADD_CLASS_MEMBER("CPhysSurfacePropertiesSoundNames", "break", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<CPhysSurfacePropertiesSoundNames*>("cphyssurfacepropertiesaudio_ptr")->m_break.String());
        },
        [](FunctionContext* context, ClassData* data) -> void {
            std::string value = context->GetArgumentOr<std::string>(0, "");
            data->GetData<CPhysSurfacePropertiesSoundNames*>("cphyssurfacepropertiesaudio_ptr")->m_break.Set(value.c_str());
        });

    ADD_CLASS_MEMBER("CPhysSurfacePropertiesSoundNames", "strain", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<CPhysSurfacePropertiesSoundNames*>("cphyssurfacepropertiesaudio_ptr")->m_strain.String());
        },
        [](FunctionContext* context, ClassData* data) -> void {
            std::string value = context->GetArgumentOr<std::string>(0, "");
            data->GetData<CPhysSurfacePropertiesSoundNames*>("cphyssurfacepropertiesaudio_ptr")->m_strain.Set(value.c_str());
        });

    ADD_CLASS_MEMBER("CPhysSurfacePropertiesSoundNames", "meleeImpact", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<CPhysSurfacePropertiesSoundNames*>("cphyssurfacepropertiesaudio_ptr")->m_meleeImpact.String());
        },
        [](FunctionContext* context, ClassData* data) -> void {
            std::string value = context->GetArgumentOr<std::string>(0, "");
            data->GetData<CPhysSurfacePropertiesSoundNames*>("cphyssurfacepropertiesaudio_ptr")->m_meleeImpact.Set(value.c_str());
        });

    ADD_CLASS_MEMBER("CPhysSurfacePropertiesSoundNames", "pushOff", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<CPhysSurfacePropertiesSoundNames*>("cphyssurfacepropertiesaudio_ptr")->m_pushOff.String());
        },
        [](FunctionContext* context, ClassData* data) -> void {
            std::string value = context->GetArgumentOr<std::string>(0, "");
            data->GetData<CPhysSurfacePropertiesSoundNames*>("cphyssurfacepropertiesaudio_ptr")->m_pushOff.Set(value.c_str());
        });

    ADD_CLASS_MEMBER("CPhysSurfacePropertiesSoundNames", "skidStop", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<CPhysSurfacePropertiesSoundNames*>("cphyssurfacepropertiesaudio_ptr")->m_skidStop.String());
        },
        [](FunctionContext* context, ClassData* data) -> void {
            std::string value = context->GetArgumentOr<std::string>(0, "");
            data->GetData<CPhysSurfacePropertiesSoundNames*>("cphyssurfacepropertiesaudio_ptr")->m_skidStop.Set(value.c_str());
        });

    ADD_CLASS("CPhysSurfaceProperties");

    ADD_CLASS_FUNCTION("CPhysSurfaceProperties", "CPhysSurfaceProperties", [](FunctionContext* context, ClassData* data) -> void {
        data->SetData("cphyssurfaceproperties_ptr", new CPhysSurfaceProperties());
        });

    ADD_CLASS_FUNCTION("CPhysSurfaceProperties", "~CPhysSurfaceProperties", [](FunctionContext* context, ClassData* data) -> void {
        if (data->HasData("cphyssurfaceproperties_ptr")) {
            delete data->GetData<CPhysSurfaceProperties*>("cphyssurfaceproperties_ptr");
        }
        });

    ADD_CLASS_MEMBER("CPhysSurfaceProperties", "name", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<CPhysSurfaceProperties*>("cphyssurfaceproperties_ptr")->m_name.String());
        },
        [](FunctionContext* context, ClassData* data) -> void {
            std::string value = context->GetArgumentOr<std::string>(0, "");
            data->GetData<CPhysSurfaceProperties*>("cphyssurfaceproperties_ptr")->m_name.Set(value.c_str());
        });

    ADD_CLASS_MEMBER("CPhysSurfaceProperties", "nameHash", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<CPhysSurfaceProperties*>("cphyssurfaceproperties_ptr")->m_nameHash);
        },
        [](FunctionContext* context, ClassData* data) -> void {
            uint32 value = context->GetArgumentOr<uint32>(0, 0);
            data->GetData<CPhysSurfaceProperties*>("cphyssurfaceproperties_ptr")->m_nameHash = value;
        });

    ADD_CLASS_MEMBER("CPhysSurfaceProperties", "baseNameHash", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<CPhysSurfaceProperties*>("cphyssurfaceproperties_ptr")->m_baseNameHash);
        },
        [](FunctionContext* context, ClassData* data) -> void {
            uint32 value = context->GetArgumentOr<uint32>(0, 0);
            data->GetData<CPhysSurfaceProperties*>("cphyssurfaceproperties_ptr")->m_baseNameHash = value;
        });

    ADD_CLASS_MEMBER("CPhysSurfaceProperties", "ListIndex", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<CPhysSurfaceProperties*>("cphyssurfaceproperties_ptr")->m_nListIndex);
        },
        [](FunctionContext* context, ClassData* data) -> void {
            int32 value = context->GetArgumentOr<int32>(0, 0);
            data->GetData<CPhysSurfaceProperties*>("cphyssurfaceproperties_ptr")->m_nListIndex = value;
        });

    ADD_CLASS_MEMBER("CPhysSurfaceProperties", "BaseListIndex", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<CPhysSurfaceProperties*>("cphyssurfaceproperties_ptr")->m_nBaseListIndex);
        },
        [](FunctionContext* context, ClassData* data) -> void {
            int32 value = context->GetArgumentOr<int32>(0, 0);
            data->GetData<CPhysSurfaceProperties*>("cphyssurfaceproperties_ptr")->m_nBaseListIndex = value;
        });

    ADD_CLASS_MEMBER("CPhysSurfaceProperties", "Hidden", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<CPhysSurfaceProperties*>("cphyssurfaceproperties_ptr")->m_bHidden);
        },
        [](FunctionContext* context, ClassData* data) -> void {
            bool value = context->GetArgumentOr<bool>(0, 0);
            data->GetData<CPhysSurfaceProperties*>("cphyssurfaceproperties_ptr")->m_bHidden = value;
        });

    ADD_CLASS_MEMBER("CPhysSurfaceProperties", "description", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<CPhysSurfaceProperties*>("cphyssurfaceproperties_ptr")->m_description.String());
        },
        [](FunctionContext* context, ClassData* data) -> void {
            std::string value = context->GetArgumentOr<std::string>(0, "");
            data->GetData<CPhysSurfaceProperties*>("cphyssurfaceproperties_ptr")->m_description.Set(value.c_str());
        });

    ADD_CLASS_MEMBER_READONLY("CPhysSurfaceProperties", "physics", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(MAKE_CLASS_INSTANCE("CPhysSurfacePropertiesPhysics", { { "cphyssurfacepropertiesphysics_ptr", data->GetData<CPhysSurfaceProperties*>("cphyssurfaceproperties_ptr")->m_physics } }));
        });

    ADD_CLASS_MEMBER_READONLY("CPhysSurfaceProperties", "audioSounds", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(MAKE_CLASS_INSTANCE("CPhysSurfacePropertiesSoundNames", { { "cphyssurfacepropertiessoundnames_ptr", data->GetData<CPhysSurfaceProperties*>("cphyssurfaceproperties_ptr")->m_audioSounds } }));
        });

    ADD_CLASS_MEMBER_READONLY("CPhysSurfaceProperties", "audioParams", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(MAKE_CLASS_INSTANCE("CPhysSurfacePropertiesAudio", { { "cphyssurfacepropertiesaudio_ptr", data->GetData<CPhysSurfaceProperties*>("cphyssurfaceproperties_ptr")->m_audioParams } }));
        });

    ADD_CLASS("CHitBox");

    ADD_CLASS_FUNCTION("CHitBox", "CHitBox", [](FunctionContext* context, ClassData* data) -> void {
        data->SetData("chitbox_ptr", new CHitBox());
        });

    ADD_CLASS_FUNCTION("CHitBox", "~CHitBox", [](FunctionContext* context, ClassData* data) -> void {
        if (data->HasData("chitbox_ptr")) {
            delete data->GetData<CHitBox*>("chitbox_ptr");
        }
        });

    ADD_CLASS_MEMBER("CHitBox", "name", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<CHitBox*>("chitbox_ptr")->m_name.String());
        },
        [](FunctionContext* context, ClassData* data) -> void {
            std::string value = context->GetArgumentOr<std::string>(0, "");
            data->GetData<CHitBox*>("chitbox_ptr")->m_name.Set(value.c_str());
        });


    ADD_CLASS_MEMBER("CHitBox", "SurfaceProperty", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<CHitBox*>("chitbox_ptr")->m_sSurfaceProperty.String());
        },
        [](FunctionContext* context, ClassData* data) -> void {
            std::string value = context->GetArgumentOr<std::string>(0, "");
            data->GetData<CHitBox*>("chitbox_ptr")->m_sSurfaceProperty.Set(value.c_str());
        });


    ADD_CLASS_MEMBER("CHitBox", "BoneName", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<CHitBox*>("chitbox_ptr")->m_sBoneName.String());
        },
        [](FunctionContext* context, ClassData* data) -> void {
            std::string value = context->GetArgumentOr<std::string>(0, "");
            data->GetData<CHitBox*>("chitbox_ptr")->m_sBoneName.Set(value.c_str());
        });

    ADD_CLASS_MEMBER("CHitBox", "MinBounds", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<CHitBox*>("chitbox_ptr")->m_vMinBounds);
        },
        [](FunctionContext* context, ClassData* data) -> void {
            Vector value = context->GetArgumentOr<Vector>(0, Vector(0.0, 0.0, 0.0));
            data->GetData<CHitBox*>("chitbox_ptr")->m_vMinBounds = value;
        });


    ADD_CLASS_MEMBER("CHitBox", "MaxBounds", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<CHitBox*>("chitbox_ptr")->m_vMaxBounds);
        },
        [](FunctionContext* context, ClassData* data) -> void {
            Vector value = context->GetArgumentOr<Vector>(0, Vector(0.0, 0.0, 0.0));
            data->GetData<CHitBox*>("chitbox_ptr")->m_vMaxBounds = value;
        });


    ADD_CLASS_MEMBER("CHitBox", "ShapeRadius", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<CHitBox*>("chitbox_ptr")->m_flShapeRadius);
        },
        [](FunctionContext* context, ClassData* data) -> void {
            float value = context->GetArgumentOr<float>(0, 0);
            data->GetData<CHitBox*>("chitbox_ptr")->m_flShapeRadius = value;
        });


    ADD_CLASS_MEMBER("CHitBox", "BoneNameHash", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<CHitBox*>("chitbox_ptr")->m_nBoneNameHash.GetHashCode());
        },
        [](FunctionContext* context, ClassData* data) -> void {
            uint32 value = context->GetArgumentOr<uint32>(0, 0);
            data->GetData<CHitBox*>("chitbox_ptr")->m_nBoneNameHash.SetHashCode(value);
        });

    ADD_CLASS_MEMBER("CHitBox", "GroupId", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<CHitBox*>("chitbox_ptr")->m_nGroupId);
        },
        [](FunctionContext* context, ClassData* data) -> void {
            int32 value = context->GetArgumentOr<int32>(0, 0);
            data->GetData<CHitBox*>("chitbox_ptr")->m_nGroupId = value;
        });


    ADD_CLASS_MEMBER("CHitBox", "ShapeType", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<CHitBox*>("chitbox_ptr")->m_nShapeType);
        },
        [](FunctionContext* context, ClassData* data) -> void {
            uint8 value = context->GetArgumentOr<uint8>(0, 0);
            data->GetData<CHitBox*>("chitbox_ptr")->m_nShapeType = value;
        });


    ADD_CLASS_MEMBER("CHitBox", "TranslationOnly", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<CHitBox*>("chitbox_ptr")->m_bTranslationOnly);
        },
        [](FunctionContext* context, ClassData* data) -> void {
            bool value = context->GetArgumentOr<bool>(0, false);
            data->GetData<CHitBox*>("chitbox_ptr")->m_bTranslationOnly = value;
        });


    ADD_CLASS_MEMBER("CHitBox", "CRC", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<CHitBox*>("chitbox_ptr")->m_CRC);
        },
        [](FunctionContext* context, ClassData* data) -> void {
            uint32 value = context->GetArgumentOr<uint32>(0, 0);
            data->GetData<CHitBox*>("chitbox_ptr")->m_CRC = value;
        });


    ADD_CLASS_MEMBER("CHitBox", "RenderColor", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<CHitBox*>("chitbox_ptr")->m_cRenderColor);
        },
        [](FunctionContext* context, ClassData* data) -> void {
            Color value = context->GetArgumentOr<Color>(0, Color(255, 255, 255, 255));
            data->GetData<CHitBox*>("chitbox_ptr")->m_cRenderColor = value;
        });

    ADD_CLASS_MEMBER("CHitBox", "HitBoxIndex", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<CHitBox*>("chitbox_ptr")->m_nHitBoxIndex);
        },
        [](FunctionContext* context, ClassData* data) -> void {
            uint16 value = context->GetArgumentOr<uint16>(0, 0);
            data->GetData<CHitBox*>("chitbox_ptr")->m_nHitBoxIndex = value;
        });


    ADD_CLASS_MEMBER("CHitBox", "ShouldForceTransform", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<CHitBox*>("chitbox_ptr")->m_bForcedTransform);
        },
        [](FunctionContext* context, ClassData* data) -> void {
            bool value = context->GetArgumentOr<bool>(0, false);
            data->GetData<CHitBox*>("chitbox_ptr")->m_bForcedTransform = value;
        });

    ADD_CLASS("RnCollisionAttr_t");

    ADD_CLASS_FUNCTION("RnCollisionAttr_t", "RnCollisionAttr_t", [](FunctionContext* context, ClassData* data) -> void {
        data->SetData("rncollisionattr_t_ptr", new RnCollisionAttr_t());
        });

    ADD_CLASS_FUNCTION("RnCollisionAttr_t", "~RnCollisionAttr_t", [](FunctionContext* context, ClassData* data) -> void {
        if (data->HasData("rncollisionattr_t_ptr")) {
            delete data->GetData<RnCollisionAttr_t*>("rncollisionattr_t_ptr");
        }
        });

    ADD_CLASS_MEMBER("RnCollisionAttr_t", "InteractsAs", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<RnCollisionAttr_t*>("rncollisionattr_t_ptr")->m_nInteractsAs);
        },
        [](FunctionContext* context, ClassData* data) -> void {
            uint64 value = context->GetArgumentOr<uint64>(0, 0);
            data->GetData<RnCollisionAttr_t*>("rncollisionattr_t_ptr")->m_nInteractsAs = value;
        });

    ADD_CLASS_MEMBER("RnCollisionAttr_t", "InteractsWith", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<RnCollisionAttr_t*>("rncollisionattr_t_ptr")->m_nInteractsWith);
        },
        [](FunctionContext* context, ClassData* data) -> void {
            uint64 value = context->GetArgumentOr<uint64>(0, 0);
            data->GetData<RnCollisionAttr_t*>("rncollisionattr_t_ptr")->m_nInteractsWith = value;
        });

    ADD_CLASS_MEMBER("RnCollisionAttr_t", "InteractsExclude", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<RnCollisionAttr_t*>("rncollisionattr_t_ptr")->m_nInteractsExclude);
        },
        [](FunctionContext* context, ClassData* data) -> void {
            uint64 value = context->GetArgumentOr<uint64>(0, 0);
            data->GetData<RnCollisionAttr_t*>("rncollisionattr_t_ptr")->m_nInteractsExclude = value;
        });

    ADD_CLASS_MEMBER("RnCollisionAttr_t", "EntityId", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<RnCollisionAttr_t*>("rncollisionattr_t_ptr")->m_nEntityId);
        },
        [](FunctionContext* context, ClassData* data) -> void {
            uint32 value = context->GetArgumentOr<uint32>(0, 0);
            data->GetData<RnCollisionAttr_t*>("rncollisionattr_t_ptr")->m_nEntityId = value;
        });

    ADD_CLASS_MEMBER("RnCollisionAttr_t", "OwnerId", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<RnCollisionAttr_t*>("rncollisionattr_t_ptr")->m_nOwnerId);
        },
        [](FunctionContext* context, ClassData* data) -> void {
            uint32 value = context->GetArgumentOr<uint32>(0, 0);
            data->GetData<RnCollisionAttr_t*>("rncollisionattr_t_ptr")->m_nOwnerId = value;
        });

    ADD_CLASS_MEMBER("RnCollisionAttr_t", "HierarchyId", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<RnCollisionAttr_t*>("rncollisionattr_t_ptr")->m_nHierarchyId);
        },
        [](FunctionContext* context, ClassData* data) -> void {
            uint16 value = context->GetArgumentOr<uint16>(0, 0);
            data->GetData<RnCollisionAttr_t*>("rncollisionattr_t_ptr")->m_nHierarchyId = value;
        });

    ADD_CLASS_MEMBER("RnCollisionAttr_t", "CollisionGroup", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<RnCollisionAttr_t*>("rncollisionattr_t_ptr")->m_nCollisionGroup);
        },
        [](FunctionContext* context, ClassData* data) -> void {
            uint8 value = context->GetArgumentOr<uint8>(0, 0);
            data->GetData<RnCollisionAttr_t*>("rncollisionattr_t_ptr")->m_nCollisionGroup = value;
        });

    ADD_CLASS_MEMBER("RnCollisionAttr_t", "CollisionFunctionMask", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<RnCollisionAttr_t*>("rncollisionattr_t_ptr")->m_nCollisionFunctionMask);
        },
        [](FunctionContext* context, ClassData* data) -> void {
            uint8 value = context->GetArgumentOr<uint8>(0, 0);
            data->GetData<RnCollisionAttr_t*>("rncollisionattr_t_ptr")->m_nCollisionFunctionMask = value;
        });

    ADD_CLASS("trace_t");

    ADD_CLASS_FUNCTION("trace_t", "trace_t", [](FunctionContext* context, ClassData* data) -> void {
        data->SetData("cgametraceinternal_ptr", new CGameTraceInternal());
        });

    ADD_CLASS_FUNCTION("trace_t", "~trace_t", [](FunctionContext* context, ClassData* data) -> void {
        if (data->HasData("cgametraceinternal_ptr")) {
            delete data->GetData<CGameTraceInternal*>("cgametraceinternal_ptr");
        }
        });

    ADD_CLASS_MEMBER_READONLY("trace_t", "SurfaceProperties", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(MAKE_CLASS_INSTANCE("CPhysSurfaceProperties", { { "cphyssurfaceproperties_ptr", data->GetData<CGameTraceInternal*>("cgametraceinternal_ptr")->m_pSurfaceProperties } }));
        });

    ADD_CLASS_MEMBER_READONLY("trace_t", "Hitbox", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(MAKE_CLASS_INSTANCE("CHitBox", { { "chitbox_ptr", data->GetData<CGameTraceInternal*>("cgametraceinternal_ptr")->m_pHitbox } }));
        });

    ADD_CLASS_MEMBER("trace_t", "Contents", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<CGameTraceInternal*>("cgametraceinternal_ptr")->m_nContents);
        },
        [](FunctionContext* context, ClassData* data) -> void {
            uint64 value = context->GetArgumentOr<uint64>(0, 0);
            data->GetData<CGameTraceInternal*>("cgametraceinternal_ptr")->m_nContents = value;
        });

    ADD_CLASS_MEMBER_READONLY("trace_t", "ShapeAttributes", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(MAKE_CLASS_INSTANCE("RnCollisionAttr_t", { { "rncollisionattr_t_ptr", data->GetData<CGameTraceInternal*>("cgametraceinternal_ptr")->m_ShapeAttributes } }));
        });

    ADD_CLASS_MEMBER("trace_t", "StartPos", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<CGameTraceInternal*>("cgametraceinternal_ptr")->m_vStartPos);
        },
        [](FunctionContext* context, ClassData* data) -> void {
            Vector value = context->GetArgumentOr<Vector>(0, Vector(0.0, 0.0, 0.0));
            data->GetData<CGameTraceInternal*>("cgametraceinternal_ptr")->m_vStartPos = value;
        });

    ADD_CLASS_MEMBER("trace_t", "EndPos", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<CGameTraceInternal*>("cgametraceinternal_ptr")->m_vEndPos);
        },
        [](FunctionContext* context, ClassData* data) -> void {
            Vector value = context->GetArgumentOr<Vector>(0, Vector(0.0, 0.0, 0.0));
            data->GetData<CGameTraceInternal*>("cgametraceinternal_ptr")->m_vEndPos = value;
        });

    ADD_CLASS_MEMBER("trace_t", "HitNormal", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<CGameTraceInternal*>("cgametraceinternal_ptr")->m_vHitNormal);
        },
        [](FunctionContext* context, ClassData* data) -> void {
            Vector value = context->GetArgumentOr<Vector>(0, Vector(0.0, 0.0, 0.0));
            data->GetData<CGameTraceInternal*>("cgametraceinternal_ptr")->m_vHitNormal = value;
        });

    ADD_CLASS_MEMBER("trace_t", "HitPoint", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<CGameTraceInternal*>("cgametraceinternal_ptr")->m_vHitPoint);
        },
        [](FunctionContext* context, ClassData* data) -> void {
            Vector value = context->GetArgumentOr<Vector>(0, Vector(0.0, 0.0, 0.0));
            data->GetData<CGameTraceInternal*>("cgametraceinternal_ptr")->m_vHitPoint = value;
        });

    ADD_CLASS_MEMBER("trace_t", "HitOffset", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<CGameTraceInternal*>("cgametraceinternal_ptr")->m_flHitOffset);
        },
        [](FunctionContext* context, ClassData* data) -> void {
            float value = context->GetArgumentOr<float>(0, 0);
            data->GetData<CGameTraceInternal*>("cgametraceinternal_ptr")->m_flHitOffset = value;
        });

    ADD_CLASS_MEMBER("trace_t", "Fraction", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<CGameTraceInternal*>("cgametraceinternal_ptr")->m_flFraction);
        },
        [](FunctionContext* context, ClassData* data) -> void {
            float value = context->GetArgumentOr<float>(0, 0);
            data->GetData<CGameTraceInternal*>("cgametraceinternal_ptr")->m_flFraction = value;
        });

    ADD_CLASS_MEMBER("trace_t", "Triangle", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<CGameTraceInternal*>("cgametraceinternal_ptr")->m_nTriangle);
        },
        [](FunctionContext* context, ClassData* data) -> void {
            int32_t value = context->GetArgumentOr<int32_t>(0, 0);
            data->GetData<CGameTraceInternal*>("cgametraceinternal_ptr")->m_nTriangle = value;
        });

    ADD_CLASS_MEMBER("trace_t", "HitboxBoneIndex", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<CGameTraceInternal*>("cgametraceinternal_ptr")->m_nHitboxBoneIndex);
        },
        [](FunctionContext* context, ClassData* data) -> void {
            int16_t value = context->GetArgumentOr<int16_t>(0, 0);
            data->GetData<CGameTraceInternal*>("cgametraceinternal_ptr")->m_nHitboxBoneIndex = value;
        });

    ADD_CLASS_MEMBER("trace_t", "RayType", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<CGameTraceInternal*>("cgametraceinternal_ptr")->m_eRayType);
        },
        [](FunctionContext* context, ClassData* data) -> void {
            uint8_t value = context->GetArgumentOr<uint8_t>(0, 0);
            data->GetData<CGameTraceInternal*>("cgametraceinternal_ptr")->m_eRayType = value;
        });

    ADD_CLASS_MEMBER("trace_t", "StartInSolid", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<CGameTraceInternal*>("cgametraceinternal_ptr")->m_bStartInSolid);
        },
        [](FunctionContext* context, ClassData* data) -> void {
            bool value = context->GetArgumentOr<bool>(0, false);
            data->GetData<CGameTraceInternal*>("cgametraceinternal_ptr")->m_bStartInSolid = value;
        });

    ADD_CLASS_MEMBER("trace_t", "ExactHitPoint", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<CGameTraceInternal*>("cgametraceinternal_ptr")->m_bExactHitPoint);
        },
        [](FunctionContext* context, ClassData* data) -> void {
            bool value = context->GetArgumentOr<bool>(0, false);
            data->GetData<CGameTraceInternal*>("cgametraceinternal_ptr")->m_bExactHitPoint = value;
        });

    ADD_CLASS_FUNCTION("trace_t", "GetEntity", [](FunctionContext* context, ClassData* data) -> void {
        data->GetData<CGameTraceInternal*>("trace_t")->GetEntity();
        });

    ADD_CLASS_FUNCTION("trace_t", "SyncToTrace", [](FunctionContext* context, ClassData* data) -> void {
        data->GetData<CGameTraceInternal*>("trace_t")->SyncToTrace();
        });

    ADD_CLASS_FUNCTION("trace_t", "SyncFromTrace", [](FunctionContext* context, ClassData* data) -> void {
        data->GetData<CGameTraceInternal*>("trace_t")->SyncFromTrace();
        });

    ADD_CLASS_FUNCTION("trace_t", "GetRawTrace", [](FunctionContext* context, ClassData* data) -> void {
        data->GetData<CGameTraceInternal*>("trace_t")->GetRawTrace();
        });

    ADD_CLASS("Ray_t");

    ADD_CLASS_FUNCTION("Ray_t", "Ray_t", [](FunctionContext* context, ClassData* data) -> void {
        data->SetData("internalray_t", new InternalRay_t());
        });

    ADD_CLASS_FUNCTION("Ray_t", "~Ray_t", [](FunctionContext* context, ClassData* data) -> void {
        if (data->HasData("internalray_t")) {
            delete data->GetData<InternalRay_t*>("internalray_t");
        }
        });

    ADD_CLASS_FUNCTION("Ray_t", "InitLine", [](FunctionContext* context, ClassData* data) -> void {
        Vector vec = context->GetArgumentOr<Vector>(0, Vector(0.0, 0.0, 0.0));
        data->GetData<InternalRay_t*>("Ray_t")->InitLine(vec);
        });

    ADD_CLASS_FUNCTION("Ray_t", "InitSphere", [](FunctionContext* context, ClassData* data) -> void {
        Vector vec = context->GetArgumentOr<Vector>(0, Vector(0.0, 0.0, 0.0));
        float radius = context->GetArgumentOr<float>(0, 0.0f);
        data->GetData<InternalRay_t*>("Ray_t")->InitSphere(vec, radius);
        });

    ADD_CLASS_FUNCTION("Ray_t", "InitHull", [](FunctionContext* context, ClassData* data) -> void {
        Vector vmin = context->GetArgumentOr<Vector>(0, Vector(0.0, 0.0, 0.0));
        Vector vmax = context->GetArgumentOr<Vector>(1, Vector(0.0, 0.0, 0.0));
        data->GetData<InternalRay_t*>("Ray_t")->InitHull(vmin, vmax);
        });

    ADD_CLASS_FUNCTION("Ray_t", "InitCapsule", [](FunctionContext* context, ClassData* data) -> void {
        Vector vmin = context->GetArgumentOr<Vector>(0, Vector(0.0, 0.0, 0.0));
        Vector vmax = context->GetArgumentOr<Vector>(1, Vector(0.0, 0.0, 0.0));
        float radius = context->GetArgumentOr<float>(2, 0.0f);
        data->GetData<InternalRay_t*>("Ray_t")->InitCapsule(vmin, vmax, radius);
        });

    ADD_CLASS_FUNCTION("Ray_t", "InitMesh", [](FunctionContext* context, ClassData* data) -> void {
        Vector vmin = context->GetArgumentOr<Vector>(0, Vector(0.0, 0.0, 0.0));
        Vector vmax = context->GetArgumentOr<Vector>(1, Vector(0.0, 0.0, 0.0));
        std::vector<Vector> vertices = context->GetArgumentOr<std::vector<Vector>>(0, std::vector<Vector>{});
        data->GetData<InternalRay_t*>("Ray_t")->InitMesh(vmin, vmax, vertices);
        });

    ADD_CLASS_FUNCTION("Ray_t", "GetRayPtr", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<InternalRay_t*>("Ray_t")->GetRayPtr());
        });

    ADD_CLASS_FUNCTION("Ray_t", "GetType", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<InternalRay_t*>("Ray_t")->GetType());
        });

    ADD_CLASS("RayTrace");

    ADD_CLASS_FUNCTION("RayTrace", "TracePlayerBBox", [](FunctionContext* context, ClassData* data) -> void {
        Vector start = context->GetArgumentOr<Vector>(0, Vector(0.0, 0.0, 0.0));
        Vector end = context->GetArgumentOr<Vector>(1, Vector(0.0, 0.0, 0.0));
        ClassData* bounds = context->GetArgumentOr<ClassData*>(2, nullptr);
        ClassData* filter = context->GetArgumentOr<ClassData*>(3, nullptr);
        ClassData* trace = context->GetArgumentOr<ClassData*>(4, nullptr);

        if (!bounds || !bounds->HasData("bbox_ptr")) return;
        if (!filter || !filter->HasData("ctracefilter_ptr")) return;
        if (!trace || !trace->HasData("cgametraceinternal_ptr")) return;

        void* sig = GetSignature("TracePlayerBBox");
        if (sig == nullptr) return;

        CInternalTraceFilter* ftr = filter->GetData<CInternalTraceFilter*>("ctracefilter_ptr");
        CGameTraceInternal* trc = trace->GetData<CGameTraceInternal*>("cgametraceinternal_ptr");
        ftr->Save();
        reinterpret_cast<TracePlayerBBox_t>(sig)(start, end, *bounds->GetData<bbox_t*>("bbox_ptr"), ftr->GetRawTraceFilter(), *trc->GetRawTrace());
        trc->SyncFromTrace();
        });

    ADD_CLASS_FUNCTION("RayTrace", "TraceShape", [](FunctionContext* context, ClassData* data) -> void {
        Vector start = context->GetArgumentOr<Vector>(0, Vector(0.0, 0.0, 0.0));
        Vector end = context->GetArgumentOr<Vector>(1, Vector(0.0, 0.0, 0.0));
        ClassData* ray = context->GetArgumentOr<ClassData*>(2, nullptr);
        ClassData* filter = context->GetArgumentOr<ClassData*>(3, nullptr);
        ClassData* trace = context->GetArgumentOr<ClassData*>(4, nullptr);

        if (!ray || !ray->HasData("internalray_t")) return;
        if (!filter || !filter->HasData("ctracefilter_ptr")) return;
        if (!trace || !trace->HasData("cgametraceinternal_ptr")) return;

        void* sig = GetSignature("TracePlayerBBox");
        if (sig == nullptr) return;

        InternalRay_t* rawray = ray->GetData<InternalRay_t*>("internalray_t");
        CInternalTraceFilter* ftr = filter->GetData<CInternalTraceFilter*>("ctracefilter_ptr");
        CGameTraceInternal* trc = trace->GetData<CGameTraceInternal*>("cgametraceinternal_ptr");
        ftr->Save();
        reinterpret_cast<TraceShape_t>(sig)(g_Physics, *(rawray->GetRawRay()), start, end, ftr->GetRawTraceFilter(), trc->GetRawTrace());
        trc->SyncFromTrace();
        });

    ADD_VARIABLES("RayType", {
    { "RAY_TYPE_LINE", ENGINE_VALUE((uint64_t)RayType_t::RAY_TYPE_LINE) },
    { "RAY_TYPE_SPHERE", ENGINE_VALUE((uint64_t)RayType_t::RAY_TYPE_SPHERE) },
    { "RAY_TYPE_HULL", ENGINE_VALUE((uint64_t)RayType_t::RAY_TYPE_HULL) },
    { "RAY_TYPE_CAPSULE", ENGINE_VALUE((uint64_t)RayType_t::RAY_TYPE_CAPSULE) },
    { "RAY_TYPE_MESH", ENGINE_VALUE((uint64_t)RayType_t::RAY_TYPE_MESH) }
        });

    ADD_VARIABLES("CollisionFunctionMask", {
    { "FCOLLISION_FUNC_ENABLE_SOLID_CONTACT", ENGINE_VALUE((uint64_t)CollisionFunctionMask_t::FCOLLISION_FUNC_ENABLE_SOLID_CONTACT) },
    { "FCOLLISION_FUNC_ENABLE_TRACE_QUERY", ENGINE_VALUE((uint64_t)CollisionFunctionMask_t::FCOLLISION_FUNC_ENABLE_TRACE_QUERY) },
    { "FCOLLISION_FUNC_ENABLE_TOUCH_EVENT", ENGINE_VALUE((uint64_t)CollisionFunctionMask_t::FCOLLISION_FUNC_ENABLE_TOUCH_EVENT) },
    { "FCOLLISION_FUNC_ENABLE_SELF_COLLISIONS", ENGINE_VALUE((uint64_t)CollisionFunctionMask_t::FCOLLISION_FUNC_ENABLE_SELF_COLLISIONS) },
    { "FCOLLISION_FUNC_IGNORE_FOR_HITBOX_TEST", ENGINE_VALUE((uint64_t)CollisionFunctionMask_t::FCOLLISION_FUNC_IGNORE_FOR_HITBOX_TEST) },
    { "FCOLLISION_FUNC_ENABLE_TOUCH_PERSISTS", ENGINE_VALUE((uint64_t)CollisionFunctionMask_t::FCOLLISION_FUNC_ENABLE_TOUCH_PERSISTS) }
        });

    ADD_VARIABLES("RnQueryObjectSet", {
    { "RNQUERY_OBJECTS_STATIC", ENGINE_VALUE((uint64_t)RnQueryObjectSet::RNQUERY_OBJECTS_STATIC) },
    { "RNQUERY_OBJECTS_DYNAMIC", ENGINE_VALUE((uint64_t)RnQueryObjectSet::RNQUERY_OBJECTS_DYNAMIC) },
    { "RNQUERY_OBJECTS_NON_COLLIDEABLE", ENGINE_VALUE((uint64_t)RnQueryObjectSet::RNQUERY_OBJECTS_NON_COLLIDEABLE) },
    { "RNQUERY_OBJECTS_KEYFRAMED_ONLY", ENGINE_VALUE((uint64_t)RnQueryObjectSet::RNQUERY_OBJECTS_KEYFRAMED_ONLY) },
    { "RNQUERY_OBJECTS_DYNAMIC_ONLY", ENGINE_VALUE((uint64_t)RnQueryObjectSet::RNQUERY_OBJECTS_DYNAMIC_ONLY) },
    { "RNQUERY_OBJECTS_ALL_GAME_ENTITIES", ENGINE_VALUE((uint64_t)RnQueryObjectSet::RNQUERY_OBJECTS_ALL_GAME_ENTITIES) },
    { "RNQUERY_OBJECTS_ALL", ENGINE_VALUE((uint64_t)RnQueryObjectSet::RNQUERY_OBJECTS_ALL) }
        });

    ADD_VARIABLES("HitboxShapeType", {
    { "HITBOX_SHAPE_HULL", ENGINE_VALUE((uint64_t)HitboxShapeType_t::HITBOX_SHAPE_HULL) },
    { "HITBOX_SHAPE_SPHERE", ENGINE_VALUE((uint64_t)HitboxShapeType_t::HITBOX_SHAPE_SPHERE) },
    { "HITBOX_SHAPE_CAPSULE", ENGINE_VALUE((uint64_t)HitboxShapeType_t::HITBOX_SHAPE_CAPSULE) }
        });

    ADD_VARIABLES("TraceMask", {
    { "MASK_ALL", ENGINE_VALUE((uint64_t)MASK_ALL) },
    { "MASK_SOLID", ENGINE_VALUE((uint64_t)MASK_SOLID) },
    { "MASK_PLAYERSOLID", ENGINE_VALUE((uint64_t)MASK_PLAYERSOLID) },
    { "MASK_NPCSOLID", ENGINE_VALUE((uint64_t)MASK_NPCSOLID) },
    { "MASK_NPCFLUID", ENGINE_VALUE((uint64_t)MASK_NPCFLUID) },
    { "MASK_WATER", ENGINE_VALUE((uint64_t)MASK_WATER) },
    { "MASK_SHOT", ENGINE_VALUE((uint64_t)MASK_SHOT) },
    { "MASK_SHOT_BRUSHONLY", ENGINE_VALUE((uint64_t)MASK_SHOT_BRUSHONLY) },
    { "MASK_SHOT_HULL", ENGINE_VALUE((uint64_t)MASK_SHOT_HULL) },
    { "MASK_SHOT_PORTAL", ENGINE_VALUE((uint64_t)MASK_SHOT_PORTAL) },
    { "MASK_SOLID_BRUSHONLY", ENGINE_VALUE((uint64_t)MASK_SOLID_BRUSHONLY) },
    { "MASK_PLAYERSOLID_BRUSHONLY", ENGINE_VALUE((uint64_t)MASK_PLAYERSOLID_BRUSHONLY) },
    { "MASK_NPCSOLID_BRUSHONLY", ENGINE_VALUE((uint64_t)MASK_NPCSOLID_BRUSHONLY) }
        });

    ADD_VARIABLES("MaskContents", {
    { "CONTENTS_EMPTY", ENGINE_VALUE((uint64_t)CONTENTS_EMPTY) },
    { "CONTENTS_SOLID", ENGINE_VALUE((uint64_t)CONTENTS_SOLID) },
    { "CONTENTS_HITBOX", ENGINE_VALUE((uint64_t)CONTENTS_HITBOX) },
    { "CONTENTS_TRIGGER", ENGINE_VALUE((uint64_t)CONTENTS_TRIGGER) },
    { "CONTENTS_SKY", ENGINE_VALUE((uint64_t)CONTENTS_SKY) },
    { "CONTENTS_PLAYER_CLIP", ENGINE_VALUE((uint64_t)CONTENTS_PLAYER_CLIP) },
    { "CONTENTS_NPC_CLIP", ENGINE_VALUE((uint64_t)CONTENTS_NPC_CLIP) },
    { "CONTENTS_BLOCK_LOS", ENGINE_VALUE((uint64_t)CONTENTS_BLOCK_LOS) },
    { "CONTENTS_BLOCK_LIGHT", ENGINE_VALUE((uint64_t)CONTENTS_BLOCK_LIGHT) },
    { "CONTENTS_LADDER", ENGINE_VALUE((uint64_t)CONTENTS_LADDER) },
    { "CONTENTS_PICKUP", ENGINE_VALUE((uint64_t)CONTENTS_PICKUP) },
    { "CONTENTS_BLOCK_SOUND", ENGINE_VALUE((uint64_t)CONTENTS_BLOCK_SOUND) },
    { "CONTENTS_NODRAW", ENGINE_VALUE((uint64_t)CONTENTS_NODRAW) },
    { "CONTENTS_WINDOW", ENGINE_VALUE((uint64_t)CONTENTS_WINDOW) },
    { "CONTENTS_PASS_BULLETS", ENGINE_VALUE((uint64_t)CONTENTS_PASS_BULLETS) },
    { "CONTENTS_WORLD_GEOMETRY", ENGINE_VALUE((uint64_t)CONTENTS_WORLD_GEOMETRY) },
    { "CONTENTS_WATER", ENGINE_VALUE((uint64_t)CONTENTS_WATER) },
    { "CONTENTS_SLIME", ENGINE_VALUE((uint64_t)CONTENTS_SLIME) },
    { "CONTENTS_TOUCH_ALL", ENGINE_VALUE((uint64_t)CONTENTS_TOUCH_ALL) },
    { "CONTENTS_PLAYER", ENGINE_VALUE((uint64_t)CONTENTS_PLAYER) },
    { "CONTENTS_NPC", ENGINE_VALUE((uint64_t)CONTENTS_NPC) },
    { "CONTENTS_DEBRIS", ENGINE_VALUE((uint64_t)CONTENTS_DEBRIS) },
    { "CONTENTS_PHYSICS_PROP", ENGINE_VALUE((uint64_t)CONTENTS_PHYSICS_PROP) },
    { "CONTENTS_NAV_IGNORE", ENGINE_VALUE((uint64_t)CONTENTS_NAV_IGNORE) },
    { "CONTENTS_NAV_LOCAL_IGNORE", ENGINE_VALUE((uint64_t)CONTENTS_NAV_LOCAL_IGNORE) },
    { "CONTENTS_POST_PROCESSING_VOLUME", ENGINE_VALUE((uint64_t)CONTENTS_POST_PROCESSING_VOLUME) },
    { "CONTENTS_UNUSED_LAYER3", ENGINE_VALUE((uint64_t)CONTENTS_UNUSED_LAYER3) },
    { "CONTENTS_CARRIED_OBJECT", ENGINE_VALUE((uint64_t)CONTENTS_CARRIED_OBJECT) },
    { "CONTENTS_PUSHAWAY", ENGINE_VALUE((uint64_t)CONTENTS_PUSHAWAY) },
    { "CONTENTS_SERVER_ENTITY_ON_CLIENT", ENGINE_VALUE((uint64_t)CONTENTS_SERVER_ENTITY_ON_CLIENT) },
    { "CONTENTS_CARRIED_WEAPON", ENGINE_VALUE((uint64_t)CONTENTS_CARRIED_WEAPON) },
    { "CONTENTS_STATIC_LEVEL", ENGINE_VALUE((uint64_t)CONTENTS_STATIC_LEVEL) },
    { "CONTENTS_CSGO_TEAM1", ENGINE_VALUE((uint64_t)CONTENTS_CSGO_TEAM1) },
    { "CONTENTS_CSGO_TEAM2", ENGINE_VALUE((uint64_t)CONTENTS_CSGO_TEAM2) },
    { "CONTENTS_CSGO_GRENADE_CLIP", ENGINE_VALUE((uint64_t)CONTENTS_CSGO_GRENADE_CLIP) },
    { "CONTENTS_CSGO_DRONE_CLIP", ENGINE_VALUE((uint64_t)CONTENTS_CSGO_DRONE_CLIP) },
    { "CONTENTS_CSGO_MOVEABLE", ENGINE_VALUE((uint64_t)CONTENTS_CSGO_MOVEABLE) },
    { "CONTENTS_CSGO_OPAQUE", ENGINE_VALUE((uint64_t)CONTENTS_CSGO_OPAQUE) },
    { "CONTENTS_CSGO_MONSTER", ENGINE_VALUE((uint64_t)CONTENTS_CSGO_MONSTER) },
    { "CONTENTS_CSGO_UNUSED_LAYER", ENGINE_VALUE((uint64_t)CONTENTS_CSGO_UNUSED_LAYER) },
    { "CONTENTS_CSGO_THROWN_GRENADE", ENGINE_VALUE((uint64_t)CONTENTS_CSGO_THROWN_GRENADE) }
        });

    // GetGlobalNamespace(ctx).addConstant("raytrace", RayTrace(plugin_name));
    ADD_VARIABLE("_G", "raytrace", MAKE_CLASS_INSTANCE_CTX(ctx, "RayTrace", {}));
}