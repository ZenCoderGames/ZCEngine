//
//  PhysicsComponent2D.cpp
//  ZenCoderEngine
//
//  Created by Srinavin Nair on 10/27/13.
//  Copyright (c) 2013 Srinavin Nair. All rights reserved.
//

#include "PhysicsComponent2D.h"
#include "ZenCoderEngine.h"

int PhysicsComponent2D::ID = 1;
int PhysicsComponent2D::PIXELS_TO_METERS = 50;

PhysicsComponent2D::PhysicsComponent2D(Entity* entity, bool isStatic):Component(entity, ID)
{
    PhysicsManager *physicsMgr = ZenCoderEngine::GetInstance()->GetPhysicsManager();
    // Create body definition
    b2BodyDef boxBodyDef;
    boxBodyDef.type = isStatic?b2_staticBody:b2_dynamicBody;
    // Create body from definition
    body = physicsMgr->CreateBody(&boxBodyDef);
}

PhysicsComponent2D::~PhysicsComponent2D()
{
    ZenCoderEngine::GetInstance()->GetPhysicsManager()->Remove2DComponent(this);
}

void PhysicsComponent2D::SetTransform(float x, float y, float rot=0)
{
    pos.x = (x + _Offset->x) / PIXELS_TO_METERS;
    pos.y = (y + _Offset->y) / PIXELS_TO_METERS;
    rot = rot * 3.14f / 180;
    body->SetTransform(pos, rot);
}

void PhysicsComponent2D::SetLinearVelocity(float x, float y)
{
    vel.x = x / PIXELS_TO_METERS;
    vel.y = y / PIXELS_TO_METERS;
    body->SetLinearVelocity(vel);
}

void PhysicsComponent2D::Reflect()
{
    vel = body->GetLinearVelocity();
    vel.x *= -1;
    vel.y *= -1;
    body->SetLinearVelocity(vel);
}

void PhysicsComponent2D::SetCallbacks(CollisionCallbackDelegate EnterCollisionCallback, CollisionCallbackDelegate ExitCollisionCallback)
{
    _OnEnterCollisionCallback = EnterCollisionCallback;
    _OnExitCollisionCallback = ExitCollisionCallback;
}

void PhysicsComponent2D::Start()
{
    body->CreateFixture(fixture);
    
    SetTransform(_entity->position.x, _entity->position.y, _entity->rotation.y);
}

void PhysicsComponent2D::Update()
{
    _entity->SetPosition(body->GetPosition().x * PIXELS_TO_METERS - _Offset->x, body->GetPosition().y * PIXELS_TO_METERS - _Offset->y, _entity->position.z);
}

void PhysicsComponent2D::OnCollisionEnter(PhysicsComponent2D* component)
{
    if(_OnEnterCollisionCallback!=NULL)
        _OnEnterCollisionCallback(component->GetEntity());
}

void PhysicsComponent2D::OnCollisionExit(PhysicsComponent2D* component)
{
    if(_OnExitCollisionCallback!=NULL)
        _OnExitCollisionCallback(component->GetEntity());
}