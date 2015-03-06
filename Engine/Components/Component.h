//
//  Component.h
//  ZenCoderEngine
//
//  Created by Srinavin Nair on 10/20/13.
//  Copyright (c) 2013 Srinavin Nair. All rights reserved.
//

#ifndef ZenCoderEngine_Component_h
#define ZenCoderEngine_Component_h

#include "Entity.h"

class Entity;

class Component
{
private:
    int _id;
    
protected:
    Entity *_entity;
    
public:
    Component(Entity* entity, int id) {
        _id = id;
        _entity = entity;
    }
    virtual ~Component() {}
    
    virtual void Start()=0;
    virtual void Update()=0;
    virtual void Stop()=0;
    
    inline int GetId() { return _id; }
    inline Entity* GetEntity() { return _entity; }
};

#endif
