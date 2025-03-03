#ifndef _entities_h
#define _entities_h

#include <swiftly-ext/memory.h>
#include "entrypoint.h"

class EntityListener
{
public:
    void Initialize();
    void Destroy();

    void StartupServer(const GameSessionConfiguration_t& config, ISource2WorldSession*, const char*);
};

class CEntityListener : public IEntityListener
{
    void OnEntityCreated(CEntityInstance* pEntity) override;
    void OnEntitySpawned(CEntityInstance* pEntity) override;
    void OnEntityDeleted(CEntityInstance* pEntity) override;
    void OnEntityParentChanged(CEntityInstance* pEntity, CEntityInstance* pNewParent) override;
};

class InputData_t
{
public:
	CEntityInstance* pActivator;
	CEntityInstance* pCaller;
	variant_t value;
	int nOutputID;
};

extern EntityListener g_entListener;

#endif