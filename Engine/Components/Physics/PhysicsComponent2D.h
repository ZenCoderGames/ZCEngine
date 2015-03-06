//
//  PhysicsComponent2D.h
//  ZenCoderEngine
//
//  Created by Srinavin Nair on 10/27/13.
//  Copyright (c) 2013 Srinavin Nair. All rights reserved.
//

#ifndef ZenCoderEngine_PhysicsComponent2D_h
#define ZenCoderEngine_PhysicsComponent2D_h

#include "Point.h"
#include "Entity.h"
#include "RenderComponent.h"
#include "Component.h"
#include <Box2D/Box2D.h>
#include <functional>

typedef std::function<void(Entity*)> CollisionCallbackDelegate;

class PhysicsComponent2D:public Component
{
private:
    static int ID;
    b2Vec2 pos, vel;
    CollisionCallbackDelegate _OnEnterCollisionCallback, _OnExitCollisionCallback;

protected:
    static int PIXELS_TO_METERS;
    b2Body* body;
    b2Shape* shape;
    b2FixtureDef* fixture;
    Point* _Offset;
    
public:
    PhysicsComponent2D(Entity* entity, bool isStatic);
    virtual ~PhysicsComponent2D();
    
    inline float GetX() { return body->GetPosition().x * PIXELS_TO_METERS; }
    inline float GetY() { return body->GetPosition().y * PIXELS_TO_METERS; }
    inline b2Body* GetBody() { return body; }
    
    void Start();
    void Update();
    void Stop() {}
    
    void SetTransform(float x, float y, float rot);
    void SetLinearVelocity(float x, float y);
    void Reflect();
    
    void SetCallbacks(CollisionCallbackDelegate EnterCollisionCallback=NULL, CollisionCallbackDelegate ExitCollisionCallback=NULL);
    
    void OnCollisionEnter(PhysicsComponent2D* component);
    void OnCollisionExit(PhysicsComponent2D* component);
    
    void SetOffset(float x, float y)
    {
        _Offset->x = x;
        _Offset->y = y;
    }
    
    inline void SetProperties(float restitution, float density, float friction)
    {
        fixture->restitution = restitution;
        fixture->density = density;
        fixture->friction = friction;
    }
};

#endif
