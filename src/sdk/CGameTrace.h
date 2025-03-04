#ifndef _sdk_cgametrace_h
#define _sdk_cgametrace_h

#include "../entrypoint.h"
#include "../utils.h"
#include <cstdint>
#include "gametrace.h"

class CGameTraceInternal
{
private:
    CGameTrace* trace;
public:
    CGameTraceInternal()
    {
        trace = new CGameTrace();
    }

    ~CGameTraceInternal()
    {
        delete trace;
    }

    CPhysSurfaceProperties* m_pSurfaceProperties;
    CHitBox *m_pHitbox;
    uint64 m_nContents;
    RnCollisionAttr_t m_ShapeAttributes;
    Vector m_vStartPos;
    Vector m_vEndPos;
    Vector m_vHitNormal;
    Vector m_vHitPoint;
    float m_flHitOffset;
    float m_flFraction;
    int32_t m_nTriangle;
    int16_t m_nHitboxBoneIndex;
    uint8_t m_eRayType;
    bool m_bStartInSolid;
    bool m_bExactHitPoint;

    std::string GetEntity() { return string_format("%p", trace->m_pEnt); }

    void SyncToTrace() {
        trace->m_pSurfaceProperties = m_pSurfaceProperties;
        trace->m_pHitbox = m_pHitbox;
        trace->m_nContents = m_nContents;
        trace->m_ShapeAttributes = m_ShapeAttributes;
        trace->m_vStartPos = m_vStartPos;
        trace->m_vEndPos = m_vEndPos;
        trace->m_vHitNormal = m_vHitNormal;
        trace->m_vHitPoint = m_vHitPoint;
        trace->m_flHitOffset = m_flHitOffset;
        trace->m_flFraction = m_flFraction;
        trace->m_nTriangle = m_nTriangle;
        trace->m_nHitboxBoneIndex = m_nHitboxBoneIndex;
        trace->m_eRayType = (RayType_t)m_eRayType;
        trace->m_bStartInSolid = m_bStartInSolid;
        trace->m_bExactHitPoint = m_bExactHitPoint;
    }

    void SyncFromTrace() {
        m_pSurfaceProperties = (CPhysSurfaceProperties*)trace->m_pSurfaceProperties;
        m_pHitbox = (CHitBox*)trace->m_pHitbox;
        m_nContents = trace->m_nContents;
        m_ShapeAttributes = trace->m_ShapeAttributes;
        m_vStartPos = trace->m_vStartPos;
        m_vEndPos = trace->m_vEndPos;
        m_vHitNormal = trace->m_vHitNormal;
        m_vHitPoint = trace->m_vHitPoint;
        m_flHitOffset = trace->m_flHitOffset;
        m_flFraction = trace->m_flFraction;
        m_nTriangle = trace->m_nTriangle;
        m_nHitboxBoneIndex = trace->m_nHitboxBoneIndex;
        m_eRayType = (uint8_t)trace->m_eRayType;
        m_bStartInSolid = trace->m_bStartInSolid;
        m_bExactHitPoint = trace->m_bExactHitPoint;
    }

    CGameTrace* GetRawTrace() { return trace; }
    std::string GetRawTracePtr() { return string_format("%p", trace); }
};

#endif