#ifndef _sdk_rayt_h
#define _sdk_rayt_h

#include "../entrypoint.h"
#include "../utils.h"
#include <cstdint>
#include "gametrace.h"

class InternalRay_t
{
private:
    Ray_t* ray;
    std::vector<Vector> m_vertices;
public:
    InternalRay_t()
    {
        ray = new Ray_t();
    }

    ~InternalRay_t()
    {
        delete ray;
        m_vertices.clear();
    }

    void InitLine(Vector startOffset)
    {
        ray->Init(startOffset);
    }

    void InitSphere(Vector center, float radius)
    {
        ray->Init(center, radius);
    }

    void InitHull(Vector min, Vector max)
    {
        ray->Init(min, max);
    }

    void InitCapsule(Vector centerA, Vector centerB, float radius)
    {
        ray->Init(centerA, centerB, radius);
    }

    void InitMesh(Vector min, Vector max, std::vector<Vector> vertices)
    {
        m_vertices = vertices;
        ray->Init(min, max, m_vertices.data(), m_vertices.size());
    }

    Ray_t* GetRawRay() { return ray; }
    std::string GetRayPtr() { return string_format("%p", ray); }
    uint8_t GetType() { return ray->m_eType; }
};

#endif