//
//  PhysicsManager.h
//  ZenCoderEngine
//
//  Created by Srinavin Nair on 10/23/13.
//  Copyright (c) 2013 Srinavin Nair. All rights reserved.
//

#ifndef ZenCoderEngine_PhysicsManager_h
#define ZenCoderEngine_PhysicsManager_h

#include "SystemManager.h"
#include <Box2D/Box2D.h>
#include "PhysicsComponent2D.h"
#include <list>
#include "CollisionHandler.h"
#include <map>
#include "Box2DDebugDraw.h"

class CollisionHandler;

class PhysicsManager:public SystemManager
{
private:
    static int ID;
    
    b2World *world;
    float32 timeStep;
	int32 velocityIterations;
	int32 positionIterations;
    
    list<PhysicsComponent2D*> _listOfNew2DComponents;
    list<PhysicsComponent2D*> _listOf2DComponents;
    list<PhysicsComponent2D*>::const_iterator _listOf2DComponentsItr;
    
    CollisionHandler* _collisionHandler;
    map<b2Body*, PhysicsComponent2D*> _mapOfBodyToComponent;
    
    Box2DDebugDraw* _debugDraw;
    
    list<b2Body*> _listOfBodiesToDestroy;
    list<b2Body*>::const_iterator _listOfBodiesToDestroyItr, _listOfBodiesToDestroyItrEnd;
    
public:
    PhysicsManager(float gravityX, float gravityY);
    ~PhysicsManager();

    b2Body* CreateBody(b2BodyDef* bodyDef);
    void DestroyBody(b2Body* body);
    void Update();
    inline b2World* GetWorld() { return world; }
    
    void Add2DComponent(PhysicsComponent2D* component);
    void Remove2DComponent(PhysicsComponent2D* component);
    
    void HandleEnterCollision(b2Body* body1, b2Body* body2);
    void HandleExitCollision(b2Body* body1, b2Body* body2);
    
    void DrawDebugData();
    
    inline void SetGravity(float gravityX, float gravityY)
    {
        b2Vec2 gravity(gravityX, gravityY);
        world->SetGravity(gravity);
    }
};

#endif
