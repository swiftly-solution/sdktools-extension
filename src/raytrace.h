#ifndef _raytrace_h
#define _raytrace_h

#include "sdk/CGameTrace.h"
#include "sdk/CTraceFilter.h"
#include "sdk/Ray_t.h"

typedef void (*TracePlayerBBox_t)(Vector& start, Vector& end, bbox_t& bounds, CTraceFilter* filter, trace_t& trace);
typedef void (*TraceShape_t)(IVPhysics2* _this, Ray_t& ray, Vector& start, Vector& end, CTraceFilter* filter, trace_t* trace);

#endif