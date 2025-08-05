using SwiftlyS2.Internal_API;
using static SwiftlyS2.API.SDK.CoreClasses;

namespace SwiftlyS2.API.Extensions.SDKTools
{
    public class RayTraceSDK
    {
        public class BBox : ClassData
        {
            public BBox() : base(Internal_API.Invoker.CallNative<IntPtr>("BBox", "BBox", Internal_API.CallKind.ClassFunction))
            {
            }
            public Vector mins
            {
                get { return Invoker.CallNative<Vector>("BBox", "mins", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("BBox", "mins", CallKind.ClassMember, m_classData, value); }
            }
            public Vector maxs
            {
                get { return Invoker.CallNative<Vector>("BBox", "maxs", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("BBox", "maxs", CallKind.ClassMember, m_classData, value); }
            }
        }
        public class CHitBox : ClassData
        {
            public CHitBox() : base(Internal_API.Invoker.CallNative<IntPtr>("CHitBox", "CHitBox", Internal_API.CallKind.ClassFunction))
            {
            }
            public string name
            {
                get { return Invoker.CallNative<string>("CHitBox", "name", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("CHitBox", "name", CallKind.ClassMember, m_classData, value); }
            }
            public string SurfaceProperty
            {
                get { return Invoker.CallNative<string>("CHitBox", "SurfaceProperty", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("CHitBox", "SurfaceProperty", CallKind.ClassMember, m_classData, value); }
            }
            public string BoneName
            {
                get { return Invoker.CallNative<string>("CHitBox", "BoneName", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("CHitBox", "BoneName", CallKind.ClassMember, m_classData, value); }
            }
            public Vector MinBounds
            {
                get { return Invoker.CallNative<Vector>("CHitBox", "MinBounds", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("CHitBox", "MinBounds", CallKind.ClassMember, m_classData, value); }
            }
            public Vector MaxBounds
            {
                get { return Invoker.CallNative<Vector>("CHitBox", "MaxBounds", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("CHitBox", "MaxBounds", CallKind.ClassMember, m_classData, value); }
            }
            public float ShapeRadius
            {
                get { return Invoker.CallNative<float>("CHitBox", "ShapeRadius", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("CHitBox", "ShapeRadius", CallKind.ClassMember, m_classData, value); }
            }
            public uint BoneNameHash
            {
                get { return Invoker.CallNative<uint>("CHitBox", "BoneNameHash", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("CHitBox", "BoneNameHash", CallKind.ClassMember, m_classData, value); }
            }
            public int GroupId
            {
                get { return Invoker.CallNative<int>("CHitBox", "GroupId", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("CHitBox", "GroupId", CallKind.ClassMember, m_classData, value); }
            }
            public byte ShapeType
            {
                get { return Invoker.CallNative<byte>("CHitBox", "ShapeType", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("CHitBox", "ShapeType", CallKind.ClassMember, m_classData, value); }
            }
            public bool TranslationOnly
            {
                get { return Invoker.CallNative<bool>("CHitBox", "TranslationOnly", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("CHitBox", "TranslationOnly", CallKind.ClassMember, m_classData, value); }
            }
            public uint CRC
            {
                get { return Invoker.CallNative<uint>("CHitBox", "CRC", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("CHitBox", "CRC", CallKind.ClassMember, m_classData, value); }
            }
            public Color RenderColor
            {
                get { return Invoker.CallNative<Color>("CHitBox", "RenderColor", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("CHitBox", "RenderColor", CallKind.ClassMember, m_classData, value); }
            }
            public ushort HitBoxIndex
            {
                get { return Invoker.CallNative<ushort>("CHitBox", "HitBoxIndex", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("CHitBox", "HitBoxIndex", CallKind.ClassMember, m_classData, value); }
            }
            public bool ShouldForceTransform
            {
                get { return Invoker.CallNative<bool>("CHitBox", "ShouldForceTransform", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("CHitBox", "ShouldForceTransform", CallKind.ClassMember, m_classData, value); }
            }
        }
        public class CPhysSurfaceProperties : ClassData
        {
            public CPhysSurfaceProperties() : base(Internal_API.Invoker.CallNative<IntPtr>("CPhysSurfaceProperties", "CPhysSurfaceProperties", Internal_API.CallKind.ClassFunction))
            {
            }
            public string name
            {
                get { return Invoker.CallNative<string>("CPhysSurfaceProperties", "name", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("CPhysSurfaceProperties", "name", CallKind.ClassMember, m_classData, value); }
            }
            public uint nameHash
            {
                get { return Invoker.CallNative<uint>("CPhysSurfaceProperties", "nameHash", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("CPhysSurfaceProperties", "nameHash", CallKind.ClassMember, m_classData, value); }
            }
            public uint baseNameHash
            {
                get { return Invoker.CallNative<uint>("CPhysSurfaceProperties", "baseNameHash", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("CPhysSurfaceProperties", "baseNameHash", CallKind.ClassMember, m_classData, value); }
            }
            public int ListIndex
            {
                get { return Invoker.CallNative<int>("CPhysSurfaceProperties", "ListIndex", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("CPhysSurfaceProperties", "ListIndex", CallKind.ClassMember, m_classData, value); }
            }
            public int BaseListIndex
            {
                get { return Invoker.CallNative<int>("CPhysSurfaceProperties", "BaseListIndex", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("CPhysSurfaceProperties", "BaseListIndex", CallKind.ClassMember, m_classData, value); }
            }
            public bool Hidden
            {
                get { return Invoker.CallNative<bool>("CPhysSurfaceProperties", "Hidden", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("CPhysSurfaceProperties", "Hidden", CallKind.ClassMember, m_classData, value); }
            }
            public string description
            {
                get { return Invoker.CallNative<string>("CPhysSurfaceProperties", "description", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("CPhysSurfaceProperties", "description", CallKind.ClassMember, m_classData, value); }
            }
            public CPhysSurfacePropertiesPhysics physics
            {
                get { return Invoker.CallNative<CPhysSurfacePropertiesPhysics>("CPhysSurfaceProperties", "physics", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("CPhysSurfaceProperties", "physics", CallKind.ClassMember, m_classData, value); }
            }
            public CPhysSurfacePropertiesSoundNames audioSounds
            {
                get { return Invoker.CallNative<CPhysSurfacePropertiesSoundNames>("CPhysSurfaceProperties", "audioSounds", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("CPhysSurfaceProperties", "audioSounds", CallKind.ClassMember, m_classData, value); }
            }
            public CPhysSurfacePropertiesAudio audioParams
            {
                get { return Invoker.CallNative<CPhysSurfacePropertiesAudio>("CPhysSurfaceProperties", "audioParams", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("CPhysSurfaceProperties", "audioParams", CallKind.ClassMember, m_classData, value); }
            }
        }
        public class CPhysSurfacePropertiesAudio : ClassData
        {
            public CPhysSurfacePropertiesAudio() : base(Internal_API.Invoker.CallNative<IntPtr>("CPhysSurfacePropertiesAudio", "CPhysSurfacePropertiesAudio", Internal_API.CallKind.ClassFunction))
            {
            }
            public float reflectivity
            {
                get { return Invoker.CallNative<float>("CPhysSurfacePropertiesAudio", "reflectivity", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("CPhysSurfacePropertiesAudio", "reflectivity", CallKind.ClassMember, m_classData, value); }
            }
            public float hardnessFactor
            {
                get { return Invoker.CallNative<float>("CPhysSurfacePropertiesAudio", "hardnessFactor", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("CPhysSurfacePropertiesAudio", "hardnessFactor", CallKind.ClassMember, m_classData, value); }
            }
            public float roughnessFactor
            {
                get { return Invoker.CallNative<float>("CPhysSurfacePropertiesAudio", "roughnessFactor", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("CPhysSurfacePropertiesAudio", "roughnessFactor", CallKind.ClassMember, m_classData, value); }
            }
            public float roughThreshold
            {
                get { return Invoker.CallNative<float>("CPhysSurfacePropertiesAudio", "roughThreshold", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("CPhysSurfacePropertiesAudio", "roughThreshold", CallKind.ClassMember, m_classData, value); }
            }
            public float hardThreshold
            {
                get { return Invoker.CallNative<float>("CPhysSurfacePropertiesAudio", "hardThreshold", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("CPhysSurfacePropertiesAudio", "hardThreshold", CallKind.ClassMember, m_classData, value); }
            }
            public float hardVelocityThreshold
            {
                get { return Invoker.CallNative<float>("CPhysSurfacePropertiesAudio", "hardVelocityThreshold", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("CPhysSurfacePropertiesAudio", "hardVelocityThreshold", CallKind.ClassMember, m_classData, value); }
            }
            public float StaticImpactVolume
            {
                get { return Invoker.CallNative<float>("CPhysSurfacePropertiesAudio", "StaticImpactVolume", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("CPhysSurfacePropertiesAudio", "StaticImpactVolume", CallKind.ClassMember, m_classData, value); }
            }
            public float OcclusionFactor
            {
                get { return Invoker.CallNative<float>("CPhysSurfacePropertiesAudio", "OcclusionFactor", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("CPhysSurfacePropertiesAudio", "OcclusionFactor", CallKind.ClassMember, m_classData, value); }
            }
        }
        public class CPhysSurfacePropertiesPhysics : ClassData
        {
            public CPhysSurfacePropertiesPhysics() : base(Internal_API.Invoker.CallNative<IntPtr>("CPhysSurfacePropertiesPhysics", "CPhysSurfacePropertiesPhysics", Internal_API.CallKind.ClassFunction))
            {
            }
            public float friction
            {
                get { return Invoker.CallNative<float>("CPhysSurfacePropertiesPhysics", "friction", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("CPhysSurfacePropertiesPhysics", "friction", CallKind.ClassMember, m_classData, value); }
            }
            public float elasticity
            {
                get { return Invoker.CallNative<float>("CPhysSurfacePropertiesPhysics", "elasticity", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("CPhysSurfacePropertiesPhysics", "elasticity", CallKind.ClassMember, m_classData, value); }
            }
            public float density
            {
                get { return Invoker.CallNative<float>("CPhysSurfacePropertiesPhysics", "density", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("CPhysSurfacePropertiesPhysics", "density", CallKind.ClassMember, m_classData, value); }
            }
            public float thickness
            {
                get { return Invoker.CallNative<float>("CPhysSurfacePropertiesPhysics", "thickness", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("CPhysSurfacePropertiesPhysics", "thickness", CallKind.ClassMember, m_classData, value); }
            }
            public float softContactFrequency
            {
                get { return Invoker.CallNative<float>("CPhysSurfacePropertiesPhysics", "softContactFrequency", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("CPhysSurfacePropertiesPhysics", "softContactFrequency", CallKind.ClassMember, m_classData, value); }
            }
            public float softContactDampingRatio
            {
                get { return Invoker.CallNative<float>("CPhysSurfacePropertiesPhysics", "softContactDampingRatio", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("CPhysSurfacePropertiesPhysics", "softContactDampingRatio", CallKind.ClassMember, m_classData, value); }
            }
        }
        public class CPhysSurfacePropertiesSoundNames : ClassData
        {
            public CPhysSurfacePropertiesSoundNames() : base(Internal_API.Invoker.CallNative<IntPtr>("CPhysSurfacePropertiesSoundNames", "CPhysSurfacePropertiesSoundNames", Internal_API.CallKind.ClassFunction))
            {
            }
            public string impactSoft
            {
                get { return Invoker.CallNative<string>("CPhysSurfacePropertiesSoundNames", "impactSoft", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("CPhysSurfacePropertiesSoundNames", "impactSoft", CallKind.ClassMember, m_classData, value); }
            }
            public string impactHard
            {
                get { return Invoker.CallNative<string>("CPhysSurfacePropertiesSoundNames", "impactHard", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("CPhysSurfacePropertiesSoundNames", "impactHard", CallKind.ClassMember, m_classData, value); }
            }
            public string scrapeSmooth
            {
                get { return Invoker.CallNative<string>("CPhysSurfacePropertiesSoundNames", "scrapeSmooth", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("CPhysSurfacePropertiesSoundNames", "scrapeSmooth", CallKind.ClassMember, m_classData, value); }
            }
            public string scrapeRough
            {
                get { return Invoker.CallNative<string>("CPhysSurfacePropertiesSoundNames", "scrapeRough", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("CPhysSurfacePropertiesSoundNames", "scrapeRough", CallKind.ClassMember, m_classData, value); }
            }
            public string bulletImpact
            {
                get { return Invoker.CallNative<string>("CPhysSurfacePropertiesSoundNames", "bulletImpact", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("CPhysSurfacePropertiesSoundNames", "bulletImpact", CallKind.ClassMember, m_classData, value); }
            }
            public string rolling
            {
                get { return Invoker.CallNative<string>("CPhysSurfacePropertiesSoundNames", "rolling", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("CPhysSurfacePropertiesSoundNames", "rolling", CallKind.ClassMember, m_classData, value); }
            }
            public string strain
            {
                get { return Invoker.CallNative<string>("CPhysSurfacePropertiesSoundNames", "strain", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("CPhysSurfacePropertiesSoundNames", "strain", CallKind.ClassMember, m_classData, value); }
            }
            public string meleeImpact
            {
                get { return Invoker.CallNative<string>("CPhysSurfacePropertiesSoundNames", "meleeImpact", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("CPhysSurfacePropertiesSoundNames", "meleeImpact", CallKind.ClassMember, m_classData, value); }
            }
            public string pushOff
            {
                get { return Invoker.CallNative<string>("CPhysSurfacePropertiesSoundNames", "pushOff", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("CPhysSurfacePropertiesSoundNames", "pushOff", CallKind.ClassMember, m_classData, value); }
            }
            public string skidStop
            {
                get { return Invoker.CallNative<string>("CPhysSurfacePropertiesSoundNames", "skidStop", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("CPhysSurfacePropertiesSoundNames", "skidStop", CallKind.ClassMember, m_classData, value); }
            }
        }
        public class CTraceFilter : ClassData
        {
            public CTraceFilter() : base(Internal_API.Invoker.CallNative<IntPtr>("CTraceFilter", "CTraceFilter", Internal_API.CallKind.ClassFunction))
            {
            }
            public void Save()
            {
                Internal_API.Invoker.CallNative("CTraceFilter", "Save", Internal_API.CallKind.ClassFunction, m_classData);
            }
            public ulong InteractsWith
            {
                get { return Invoker.CallNative<ulong>("CTraceFilter", "InteractsWith", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("CTraceFilter", "InteractsWith", CallKind.ClassMember, m_classData, value); }
            }
            public ulong InteractsExclude
            {
                get { return Invoker.CallNative<ulong>("CTraceFilter", "InteractsExclude", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("CTraceFilter", "InteractsExclude", CallKind.ClassMember, m_classData, value); }
            }
            public ulong InteractsAs
            {
                get { return Invoker.CallNative<ulong>("CTraceFilter", "InteractsAs", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("CTraceFilter", "InteractsAs", CallKind.ClassMember, m_classData, value); }
            }
            public uint[] EntityIdsToIgnore
            {
                get { return Invoker.CallNative<uint[]>("CTraceFilter", "EntityIdsToIgnore", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("CTraceFilter", "EntityIdsToIgnore", CallKind.ClassMember, m_classData, value); }
            }
            public uint[] OwnerIdsToIgnore
            {
                get { return Invoker.CallNative<uint[]>("CTraceFilter", "OwnerIdsToIgnore", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("CTraceFilter", "OwnerIdsToIgnore", CallKind.ClassMember, m_classData, value); }
            }
            public ushort[] HierarchyIds
            {
                get { return Invoker.CallNative<ushort[]>("CTraceFilter", "HierarchyIds", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("CTraceFilter", "HierarchyIds", CallKind.ClassMember, m_classData, value); }
            }
            public ushort ObjectSetMask
            {
                get { return Invoker.CallNative<ushort>("CTraceFilter", "ObjectSetMask", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("CTraceFilter", "ObjectSetMask", CallKind.ClassMember, m_classData, value); }
            }
            public uint CollisionGroup
            {
                get { return Invoker.CallNative<uint>("CTraceFilter", "CollisionGroup", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("CTraceFilter", "CollisionGroup", CallKind.ClassMember, m_classData, value); }
            }
            public bool HitSolid
            {
                get { return Invoker.CallNative<bool>("CTraceFilter", "HitSolid", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("CTraceFilter", "HitSolid", CallKind.ClassMember, m_classData, value); }
            }
            public bool HitSolidRequiresGenerateContacts
            {
                get { return Invoker.CallNative<bool>("CTraceFilter", "HitSolidRequiresGenerateContacts", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("CTraceFilter", "HitSolidRequiresGenerateContacts", CallKind.ClassMember, m_classData, value); }
            }
            public bool HitTrigger
            {
                get { return Invoker.CallNative<bool>("CTraceFilter", "HitTrigger", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("CTraceFilter", "HitTrigger", CallKind.ClassMember, m_classData, value); }
            }
            public bool ShouldIgnoreDisabledPairs
            {
                get { return Invoker.CallNative<bool>("CTraceFilter", "ShouldIgnoreDisabledPairs", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("CTraceFilter", "ShouldIgnoreDisabledPairs", CallKind.ClassMember, m_classData, value); }
            }
            public bool IgnoreIfBothInteractWithHitboxes
            {
                get { return Invoker.CallNative<bool>("CTraceFilter", "IgnoreIfBothInteractWithHitboxes", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("CTraceFilter", "IgnoreIfBothInteractWithHitboxes", CallKind.ClassMember, m_classData, value); }
            }
            public bool ForceHitEverything
            {
                get { return Invoker.CallNative<bool>("CTraceFilter", "ForceHitEverything", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("CTraceFilter", "ForceHitEverything", CallKind.ClassMember, m_classData, value); }
            }
            public bool Unknown
            {
                get { return Invoker.CallNative<bool>("CTraceFilter", "Unknown", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("CTraceFilter", "Unknown", CallKind.ClassMember, m_classData, value); }
            }
            public bool IterateEntities
            {
                get { return Invoker.CallNative<bool>("CTraceFilter", "IterateEntities", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("CTraceFilter", "IterateEntities", CallKind.ClassMember, m_classData, value); }
            }
        }
        public class Ray_t : ClassData
        {
            public Ray_t() : base(Internal_API.Invoker.CallNative<IntPtr>("Ray_t", "Ray_t", Internal_API.CallKind.ClassFunction))
            {
            }
            public void InitLine(Vector startOffset)
            {
                Internal_API.Invoker.CallNative("Ray_t", "InitLine", Internal_API.CallKind.ClassFunction, m_classData, startOffset);
            }
            public void InitSphere(Vector center, float radius)
            {
                Internal_API.Invoker.CallNative("Ray_t", "InitSphere", Internal_API.CallKind.ClassFunction, m_classData, center, radius);
            }
            public void InitHull(Vector min, Vector max)
            {
                Internal_API.Invoker.CallNative("Ray_t", "InitHull", Internal_API.CallKind.ClassFunction, m_classData, min, max);
            }
            public void InitCapsule(Vector centerA, Vector centerB, float radius)
            {
                Internal_API.Invoker.CallNative("Ray_t", "InitCapsule", Internal_API.CallKind.ClassFunction, m_classData, centerA, centerB, radius);
            }
            public void InitMesh(Vector min, Vector max, Vector[] vertices)
            {
                Internal_API.Invoker.CallNative("Ray_t", "InitMesh", Internal_API.CallKind.ClassFunction, m_classData, min, max, (object)vertices);
            }
            public string GetRayPtr()
            {
                return Internal_API.Invoker.CallNative<string>("Ray_t", "GetRayPtr", Internal_API.CallKind.ClassFunction, m_classData);
            }
            public RayType_t GetType()
            {
                return Internal_API.Invoker.CallNative<RayType_t>("Ray_t", "GetType", Internal_API.CallKind.ClassFunction, m_classData);
            }
        }
        public class RnCollisionAttr_t : ClassData
        {
            public RnCollisionAttr_t() : base(Internal_API.Invoker.CallNative<IntPtr>("RnCollisionAttr_t", "RnCollisionAttr_t", Internal_API.CallKind.ClassFunction))
            {
            }
            public ulong InteractsAs
            {
                get { return Invoker.CallNative<ulong>("RnCollisionAttr_t", "InteractsAs", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("RnCollisionAttr_t", "InteractsAs", CallKind.ClassMember, m_classData, value); }
            }
            public ulong InteractsWith
            {
                get { return Invoker.CallNative<ulong>("RnCollisionAttr_t", "InteractsWith", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("RnCollisionAttr_t", "InteractsWith", CallKind.ClassMember, m_classData, value); }
            }
            public ulong InteractsExclude
            {
                get { return Invoker.CallNative<ulong>("RnCollisionAttr_t", "InteractsExclude", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("RnCollisionAttr_t", "InteractsExclude", CallKind.ClassMember, m_classData, value); }
            }
            public uint EntityId
            {
                get { return Invoker.CallNative<uint>("RnCollisionAttr_t", "EntityId", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("RnCollisionAttr_t", "EntityId", CallKind.ClassMember, m_classData, value); }
            }
            public uint OwnerId
            {
                get { return Invoker.CallNative<uint>("RnCollisionAttr_t", "OwnerId", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("RnCollisionAttr_t", "OwnerId", CallKind.ClassMember, m_classData, value); }
            }
            public ushort HierarchyId
            {
                get { return Invoker.CallNative<ushort>("RnCollisionAttr_t", "HierarchyId", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("RnCollisionAttr_t", "HierarchyId", CallKind.ClassMember, m_classData, value); }
            }
            public byte CollisionGroup
            {
                get { return Invoker.CallNative<byte>("RnCollisionAttr_t", "CollisionGroup", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("RnCollisionAttr_t", "CollisionGroup", CallKind.ClassMember, m_classData, value); }
            }
            public byte CollisionFunctionMask
            {
                get { return Invoker.CallNative<byte>("RnCollisionAttr_t", "CollisionFunctionMask", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("RnCollisionAttr_t", "CollisionFunctionMask", CallKind.ClassMember, m_classData, value); }
            }
        }
        public class trace_t : ClassData
        {
            public trace_t() : base(Internal_API.Invoker.CallNative<IntPtr>("trace_t", "trace_t", Internal_API.CallKind.ClassFunction))
            {
            }
            public string GetEntity()
            {
                return Internal_API.Invoker.CallNative<string>("trace_t", "GetEntity", Internal_API.CallKind.ClassFunction, m_classData);
            }
            public void SyncToTrace()
            {
                Internal_API.Invoker.CallNative("trace_t", "SyncToTrace", Internal_API.CallKind.ClassFunction, m_classData);
            }
            public void SyncFromTrace()
            {
                Internal_API.Invoker.CallNative("trace_t", "SyncFromTrace", Internal_API.CallKind.ClassFunction, m_classData);
            }
            public string GetRawTrace()
            {
                return Internal_API.Invoker.CallNative<string>("trace_t", "GetRawTrace", Internal_API.CallKind.ClassFunction, m_classData);
            }
            public CPhysSurfaceProperties SurfaceProperties
            {
                get { return Invoker.CallNative<CPhysSurfaceProperties>("trace_t", "SurfaceProperties", CallKind.ClassMember, m_classData); }
            }
            public CHitBox Hitbox
            {
                get { return Invoker.CallNative<CHitBox>("trace_t", "Hitbox", CallKind.ClassMember, m_classData); }
            }
            public ulong Contents
            {
                get { return Invoker.CallNative<ulong>("trace_t", "Contents", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("trace_t", "Contents", CallKind.ClassMember, m_classData, value); }
            }
            public RnCollisionAttr_t ShapeAttributes
            {
                get { return Invoker.CallNative<RnCollisionAttr_t>("trace_t", "ShapeAttributes", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("trace_t", "ShapeAttributes", CallKind.ClassMember, m_classData, value); }
            }
            public Vector StartPos
            {
                get { return Invoker.CallNative<Vector>("trace_t", "StartPos", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("trace_t", "StartPos", CallKind.ClassMember, m_classData, value); }
            }
            public Vector EndPos
            {
                get { return Invoker.CallNative<Vector>("trace_t", "EndPos", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("trace_t", "EndPos", CallKind.ClassMember, m_classData, value); }
            }
            public Vector HitNormal
            {
                get { return Invoker.CallNative<Vector>("trace_t", "HitNormal", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("trace_t", "HitNormal", CallKind.ClassMember, m_classData, value); }
            }
            public Vector HitPoint
            {
                get { return Invoker.CallNative<Vector>("trace_t", "HitPoint", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("trace_t", "HitPoint", CallKind.ClassMember, m_classData, value); }
            }
            public float HitOffset
            {
                get { return Invoker.CallNative<float>("trace_t", "HitOffset", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("trace_t", "HitOffset", CallKind.ClassMember, m_classData, value); }
            }
            public float Fraction
            {
                get { return Invoker.CallNative<float>("trace_t", "Fraction", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("trace_t", "Fraction", CallKind.ClassMember, m_classData, value); }
            }
            public int Triangle
            {
                get { return Invoker.CallNative<int>("trace_t", "Triangle", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("trace_t", "Triangle", CallKind.ClassMember, m_classData, value); }
            }
            public short HitboxBoneIndex
            {
                get { return Invoker.CallNative<short>("trace_t", "HitboxBoneIndex", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("trace_t", "HitboxBoneIndex", CallKind.ClassMember, m_classData, value); }
            }
            public RayType_t RayType
            {
                get { return Invoker.CallNative<RayType_t>("trace_t", "RayType", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("trace_t", "RayType", CallKind.ClassMember, m_classData, value); }
            }
            public bool StartInSolid
            {
                get { return Invoker.CallNative<bool>("trace_t", "StartInSolid", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("trace_t", "StartInSolid", CallKind.ClassMember, m_classData, value); }
            }
            public bool ExactHitPoint
            {
                get { return Invoker.CallNative<bool>("trace_t", "ExactHitPoint", CallKind.ClassMember, m_classData); }
                set { Invoker.CallNative("trace_t", "ExactHitPoint", CallKind.ClassMember, m_classData, value); }
            }
        }
        public enum CollisionFunctionMask_t : long
        {
            FCOLLISION_FUNC_ENABLE_SOLID_CONTACT = (1 << 0),
            FCOLLISION_FUNC_ENABLE_TRACE_QUERY = (1 << 1),
            FCOLLISION_FUNC_ENABLE_TOUCH_EVENT = (1 << 2),
            FCOLLISION_FUNC_ENABLE_SELF_COLLISIONS = (1 << 3),
            FCOLLISION_FUNC_IGNORE_FOR_HITBOX_TEST = (1 << 4),
            FCOLLISION_FUNC_ENABLE_TOUCH_PERSISTS = (1 << 5)
        }
        public enum HitboxShapeType_t : long
        {
            HITBOX_SHAPE_HULL = 0,
            HITBOX_SHAPE_SPHERE = 1,
            HITBOX_SHAPE_CAPSULE = 2
        }
        public enum MaskContents : long
        {
            CONTENTS_EMPTY = 0,
            CONTENTS_SOLID = 1,
            CONTENTS_HITBOX = 2,
            CONTENTS_TRIGGER = 4,
            CONTENTS_SKY = 8,
            CONTENTS_PLAYER_CLIP = 16,
            CONTENTS_NPC_CLIP = 32,
            CONTENTS_BLOCK_LOS = 64,
            CONTENTS_BLOCK_LIGHT = 128,
            CONTENTS_LADDER = 256,
            CONTENTS_PICKUP = 512,
            CONTENTS_BLOCK_SOUND = 1024,
            CONTENTS_NODRAW = 2048,
            CONTENTS_WINDOW = 4096,
            CONTENTS_PASS_BULLETS = 8192,
            CONTENTS_WORLD_GEOMETRY = 16384,
            CONTENTS_WATER = 32768,
            CONTENTS_SLIME = 65536,
            CONTENTS_TOUCH_ALL = 131072,
            CONTENTS_PLAYER = 262144,
            CONTENTS_NPC = 524288,
            CONTENTS_DEBRIS = 1048576,
            CONTENTS_PHYSICS_PROP = 2097152,
            CONTENTS_NAV_IGNORE = 4194304,
            CONTENTS_NAV_LOCAL_IGNORE = 8388608,
            CONTENTS_POST_PROCESSING_VOLUME = 16777216,
            CONTENTS_UNUSED_LAYER3 = 33554432,
            CONTENTS_CARRIED_OBJECT = 67108864,
            CONTENTS_PUSHAWAY = 134217728,
            CONTENTS_SERVER_ENTITY_ON_CLIENT = 268435456,
            CONTENTS_CARRIED_WEAPON = 536870912,
            CONTENTS_STATIC_LEVEL = 1073741824,
            CONTENTS_CSGO_TEAM1 = 2147483648,
            CONTENTS_CSGO_TEAM2 = 4294967296,
            CONTENTS_CSGO_GRENADE_CLIP = 8589934592,
            CONTENTS_CSGO_DRONE_CLIP = 17179869184,
            CONTENTS_CSGO_MOVEABLE = 34359738368,
            CONTENTS_CSGO_OPAQUE = 68719476736,
            CONTENTS_CSGO_MONSTER = 137438953472,
            CONTENTS_CSGO_UNUSED_LAYER = 274877906944,
            CONTENTS_CSGO_THROWN_GRENADE = 549755813888
        }
        public enum RayType_t : long
        {
            RAY_TYPE_LINE = 0,
            RAY_TYPE_SPHERE = 1,
            RAY_TYPE_HULL = 2,
            RAY_TYPE_CAPSULE = 3,
            RAY_TYPE_MESH = 4
        }
        public enum RnQueryObjectSet : long
        {
            RNQUERY_OBJECTS_STATIC = (1 << 0),
            RNQUERY_OBJECTS_KEYFRAMED = (1 << 1),
            RNQUERY_OBJECTS_DYNAMIC = (1 << 2),
            RNQUERY_OBJECTS_LOCATABLE = (1 << 3),
            RNQUERY_OBJECTS_ALL_GAME_ENTITIES = RNQUERY_OBJECTS_KEYFRAMED | RNQUERY_OBJECTS_DYNAMIC | RNQUERY_OBJECTS_LOCATABLE,
            RNQUERY_OBJECTS_ALL = RNQUERY_OBJECTS_STATIC | RNQUERY_OBJECTS_ALL_GAME_ENTITIES
        }
        public enum TraceMask : ulong
        {
            MASK_ALL = 18446744073709551615,
            MASK_SOLID = 798721,
            MASK_PLAYERSOLID = 798737,
            MASK_NPCSOLID = 798753,
            MASK_NPCFLUID = 790561,
            MASK_WATER = 98304,
            MASK_SHOT = 1839107,
            MASK_SHOT_BRUSHONLY = 1052673,
            MASK_SHOT_HULL = 1847297,
            MASK_SHOT_PORTAL = 790529,
            MASK_SOLID_BRUSHONLY = 12289,
            MASK_PLAYERSOLID_BRUSHONLY = 12305,
            MASK_NPCSOLID_BRUSHONLY = 12321
        }
    }
}