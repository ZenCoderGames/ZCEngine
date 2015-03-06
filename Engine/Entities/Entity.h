//
//  Entity.h
//  ZenCoderEngine
//
//  Created by Srinavin Nair on 10/20/13.
//  Copyright (c) 2013 Srinavin Nair. All rights reserved.
//

#ifndef ZenCoderEngine_Entity_h
#define ZenCoderEngine_Entity_h

#include "Vector3.h"
#include <map>
using namespace std;

class Component;

class Entity
{
private:
    static int ENTITY_COUNTER;
    int _id;
    map<int, Component*> _componentMap;
    
public:
    Vector3 position;
    Vector3 rotation;
    Vector3 scale;
    
    Entity();
    virtual ~Entity();
    
    void AddComponent(Component* component);
    void RemoveComponent(int componentId);
    
    virtual void Update()=0;
    
    inline int GetId() { return _id; }
    
    void SetPosition(float x, float y, float z);
    void SetRotation(float x, float y, float z);
    void SetScale(float x, float y, float z);
};

#endif
