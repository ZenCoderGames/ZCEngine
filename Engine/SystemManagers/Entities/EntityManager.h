//
//  EntityManager.h
//  ZenCoderEngine
//
//  Created by Srinavin Nair on 10/20/13.
//  Copyright (c) 2013 Srinavin Nair. All rights reserved.
//

#ifndef ZenCoderEngine_EntityManager_h
#define ZenCoderEngine_EntityManager_h

#include "Entity.h"
#include <list>
#include "SystemManager.h"

class EntityManager:public SystemManager
{
private:
    static int ID;
    
    list<Entity*> _listOfEntities;
    list<Entity*>::const_iterator _listOfEntitiesItr;
    
public:
    EntityManager();
    ~EntityManager();
    
    void AddEntity(Entity*);
    void RemoveEntity(Entity*);
    void Update();
};

#endif
