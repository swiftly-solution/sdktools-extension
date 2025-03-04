#ifndef _raytrace_h
#define _raytrace_h

#include "sdk/CGameTrace.h"
#include "sdk/CTraceFilter.h"
#include "sdk/Ray_t.h"

typedef void (*TracePlayerBBox_t)(Vector& start, Vector& end, bbox_t& bounds, CTraceFilter* filter, trace_t& trace);
typedef void (*TraceShape_t)(IVPhysics2* _this, Ray_t& ray, Vector& start, Vector& end, CTraceFilter* filter, trace_t* trace);

class RayTrace
{
private:
    std::string m_plugin_name;
public:
    RayTrace(std::string plugin_name);
    ~RayTrace() = default;

    void TracePlayerBBox(Vector *start, Vector *end, bbox_t *bounds, CInternalTraceFilter *filter, CGameTraceInternal* trace);
    void TraceShape(Vector* start, Vector* end, InternalRay_t* ray, CInternalTraceFilter *filter, CGameTraceInternal* trace);
};

#endif