//
//  PhysicsManager.cpp
//  ZenCoderEngine
//
//  Created by Srinavin Nair on 10/23/13.
//  Copyright (c) 2013 Srinavin Nair. All rights reserved.
//

#include "PhysicsManager.h"

int PhysicsManager::ID = 1;

PhysicsManager::PhysicsManager(float gravityX, float gravityY):SystemManager(ID)
{
    b2Vec2 gravity(gravityX, gravityY);
    world = new b2World(gravity);
    timeStep = 1.0f / 60.0f;
	velocityIterations = 6;
	positionIterations = 2;
    
    _collisionHandler = new CollisionHandler(this);
    world->SetContactListener(_collisionHandler);
    
    _debugDraw = new Box2DDebugDraw();
    world->SetDebugDraw(_debugDraw);
    
    _debugDraw->SetFlags( b2Draw::e_shapeBit );
}

PhysicsManager::~PhysicsManager()
{
    delete world;
}

b2Body* PhysicsManager::CreateBody(b2BodyDef* bodyDef)
{
    return world->CreateBody(bodyDef);
}

void PhysicsManager::DestroyBody(b2Body* body)
{
    _listOfBodiesToDestroy.push_back(body);
}

void PhysicsManager::Update()
{
    // Destroy pending bodies
    if(_listOfBodiesToDestroy.size()>0)
    {
        for(_listOfBodiesToDestroyItr = _listOfBodiesToDestroy.begin(), _listOfBodiesToDestroyItrEnd = _listOfBodiesToDestroy.end(); _listOfBodiesToDestroyItr != _listOfBodiesToDestroyItrEnd; ++_listOfBodiesToDestroyItr)
        {
            _mapOfBodyToComponent[*_listOfBodiesToDestroyItr] = NULL;
            world->DestroyBody(*_listOfBodiesToDestroyItr);
        }
        
        _listOfBodiesToDestroy.clear();
    }
    
    // Start new
    if(_listOfNew2DComponents.size()>0)
    {
        for (_listOf2DComponentsItr = _listOfNew2DComponents.begin(); _listOf2DComponentsItr != _listOfNew2DComponents.end(); ++_listOf2DComponentsItr)
        {
            (*_listOf2DComponentsItr)->Start();
        }
        _listOfNew2DComponents.clear();
    }
    
    world->Step(timeStep, velocityIterations, positionIterations);

    // Update 2D
    for (_listOf2DComponentsItr = _listOf2DComponents.begin(); _listOf2DComponentsItr != _listOf2DComponents.end(); ++_listOf2DComponentsItr)
    {
        (*_listOf2DComponentsItr)->Update();
    }
}

void PhysicsManager::Add2DComponent(PhysicsComponent2D* component)
{
    _listOf2DComponents.push_back(component);
    _listOfNew2DComponents.push_back(component);
    _mapOfBodyToComponent[component->GetBody()] = component;
}

void PhysicsManager::Remove2DComponent(PhysicsComponent2D* component)
{
    component->Stop();
    
    b2Body* body = component->GetBody();
    
    DestroyBody(body);
    
    _listOf2DComponents.remove(component);
    
    _listOf2DComponentsItr = find (_listOfNew2DComponents.begin(), _listOfNew2DComponents.end(), component);
    if (_listOf2DComponentsItr != _listOfNew2DComponents.end())
        _listOfNew2DComponents.remove(*_listOf2DComponentsItr);
}

void PhysicsManager::HandleEnterCollision(b2Body* body1, b2Body* body2)
{
    if(_mapOfBodyToComponent[body1]!=NULL && _mapOfBodyToComponent[body2]!=NULL)
        _mapOfBodyToComponent[body1]->OnCollisionEnter(_mapOfBodyToComponent[body2]);
    if(_mapOfBodyToComponent[body1]!=NULL && _mapOfBodyToComponent[body2]!=NULL)
        _mapOfBodyToComponent[body2]->OnCollisionEnter(_mapOfBodyToComponent[body1]);
}

void PhysicsManager::HandleExitCollision(b2Body* body1, b2Body* body2)
{
    if(_mapOfBodyToComponent[body1]!=NULL && _mapOfBodyToComponent[body2]!=NULL)
        _mapOfBodyToComponent[body1]->OnCollisionExit(_mapOfBodyToComponent[body2]);
    if(_mapOfBodyToComponent[body1]!=NULL && _mapOfBodyToComponent[body2]!=NULL)
        _mapOfBodyToComponent[body2]->OnCollisionExit(_mapOfBodyToComponent[body1]);
}

void PhysicsManager::DrawDebugData()
{    
    world->DrawDebugData();
}
