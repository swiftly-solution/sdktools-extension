#ifndef _sdk_ctracefilter_h
#define _sdk_ctracefilter_h

#include "../entrypoint.h"
#include "../utils.h"
#include <cstdint>
#include <vector>
#include "gametrace.h"

class CInternalTraceFilter
{
private:
    CTraceFilter* filter;
public:
    CInternalTraceFilter()
    {
        filter = new CTraceFilter();
    }

    ~CInternalTraceFilter()
    {
        delete filter;
    }

    uint64_t m_nInteractsWith;
    uint64_t m_nInteractsExclude;
    uint64_t m_nInteractsAs;

    std::vector<uint32_t> m_nEntityIdsToIgnore;
    std::vector<uint32_t> m_nOwnerIdsToIgnore;
    std::vector<uint16_t> m_nHierarchyIds;
    uint16_t m_nObjectSetMask;
    uint32_t m_nCollisionGroup;

    bool m_bHitSolid;
    bool m_bHitSolidRequiresGenerateContacts;
    bool m_bHitTrigger;
    bool m_bShouldIgnoreDisabledPairs;
    bool m_bIgnoreIfBothInteractWithHitboxes;
    bool m_bForceHitEverything;
    bool m_bUnknown;
    bool m_bIterateEntities;

    void Save()
    {
        filter->m_nInteractsWith = m_nInteractsWith;
        filter->m_nInteractsExclude = m_nInteractsExclude;
        filter->m_nInteractsAs = m_nInteractsAs;
        if (m_nEntityIdsToIgnore.size() > 0) filter->m_nEntityIdsToIgnore[0] = m_nEntityIdsToIgnore[0];
        if (m_nEntityIdsToIgnore.size() > 1) filter->m_nEntityIdsToIgnore[1] = m_nEntityIdsToIgnore[1];
        if (m_nOwnerIdsToIgnore.size() > 0) filter->m_nOwnerIdsToIgnore[0] = m_nOwnerIdsToIgnore[0];
        if (m_nOwnerIdsToIgnore.size() > 1) filter->m_nOwnerIdsToIgnore[1] = m_nOwnerIdsToIgnore[1];
        if (m_nHierarchyIds.size() > 0) filter->m_nHierarchyIds[0] = m_nHierarchyIds[0];
        if (m_nHierarchyIds.size() > 1) filter->m_nHierarchyIds[1] = m_nHierarchyIds[1];
        filter->m_nObjectSetMask = m_nObjectSetMask;
        filter->m_nCollisionGroup = (uint8_t)m_nCollisionGroup;
        filter->m_bHitSolid = m_bHitSolid;
        filter->m_bHitSolidRequiresGenerateContacts = m_bHitSolidRequiresGenerateContacts;
        filter->m_bHitTrigger = m_bHitTrigger;
        filter->m_bShouldIgnoreDisabledPairs = m_bShouldIgnoreDisabledPairs;
        filter->m_bIgnoreIfBothInteractWithHitboxes = m_bIgnoreIfBothInteractWithHitboxes;
        filter->m_bForceHitEverything = m_bForceHitEverything;
        filter->m_bUnknown = m_bUnknown;
        filter->m_bIterateEntities = m_bIterateEntities;
    }

    CTraceFilter* GetRawTraceFilter() { return filter; }
};

#endif