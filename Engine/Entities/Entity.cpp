//
//  Entity.cpp
//  ZenCoderEngine
//
//  Created by Srinavin Nair on 10/20/13.
//  Copyright (c) 2013 Srinavin Nair. All rights reserved.
//

#include "Entity.h"
#include "ZenCoderEngine.h"

int Entity::ENTITY_COUNTER = 0;

Entity::Entity()
{
   _id = ENTITY_COUNTER++;
    ZenCoderEngine::GetInstance()->GetEntityManager()->AddEntity(this);
    
    SetPosition(0,0,0);
    SetRotation(0,0,0);
    SetScale(1,1,1);
}

Entity::~Entity()
{
    map<int, Component*>::iterator componentMapItr;
    
    for (componentMapItr = _componentMap.begin(); componentMapItr != _componentMap.end(); ++componentMapItr)
    {
        delete componentMapItr->second;
    }
    
    _componentMap.clear();
}

void Entity::AddComponent(Component* component)
{
    _componentMap.insert(std::pair<int, Component*>(component->GetId(), component));
}

void Entity::RemoveComponent(int componentId)
{
    _componentMap.erase(componentId);
}

void Entity::SetPosition(float x, float y, float z)
{
    position.x = x;
    position.y = y;
    position.z = z;
}

void Entity::SetRotation(float x, float y, float z)
{
    rotation.x = x;
    rotation.y = y;
    rotation.z = z;
}

void Entity::SetScale(float x, float y, float z)
{
    scale.x = x;
    scale.y = y;
    scale.z = z;
}