//
//  EntityManager.cpp
//  ZenCoderEngine
//
//  Created by Srinavin Nair on 10/20/13.
//  Copyright (c) 2013 Srinavin Nair. All rights reserved.
//

#include "EntityManager.h"

int EntityManager::ID = 2;

EntityManager::EntityManager():SystemManager(ID)
{
    
}

EntityManager::~EntityManager()
{
    std::cout<<"Entities cleared: "<<_listOfEntities.size();
    for (_listOfEntitiesItr = _listOfEntities.begin(); _listOfEntitiesItr != _listOfEntities.end(); ++_listOfEntitiesItr)
    {
        delete *_listOfEntitiesItr;
    }
    
    _listOfEntities.clear();
}

void EntityManager::AddEntity(Entity* entity)
{
    _listOfEntities.push_back(entity);
}

void EntityManager::RemoveEntity(Entity* entity)
{
    _listOfEntities.remove(entity);
    delete entity;
}

void EntityManager::Update()
{
    for (_listOfEntitiesItr = _listOfEntities.begin(); _listOfEntitiesItr != _listOfEntities.end(); ++_listOfEntitiesItr)
    {
        (*_listOfEntitiesItr)->Update();
    }
}