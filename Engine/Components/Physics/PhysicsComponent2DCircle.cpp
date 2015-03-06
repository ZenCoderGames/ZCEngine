//
//  PhysicsComponent2DCircle.cpp
//  ZenCoderEngine
//
//  Created by Srinavin Nair on 10/27/13.
//  Copyright (c) 2013 Srinavin Nair. All rights reserved.
//

#include "PhysicsComponent2DCircle.h"
#include "ZenCoderEngine.h"

PhysicsComponent2DCircle::PhysicsComponent2DCircle(Entity* entity, float radius, bool isStatic):PhysicsComponent2D(entity, isStatic)
{
    PhysicsManager *physicsMgr = ZenCoderEngine::GetInstance()->GetPhysicsManager();
    b2CircleShape* circleShape = new b2CircleShape();
    // Create shape
    shape = circleShape;
    // Create fixture
    fixture = new b2FixtureDef();
    fixture->shape = shape;
    if(!isStatic)
    {
        fixture->restitution = 0;
        fixture->density = 1.0f;
        fixture->friction = 0.0f;
    }

    // shape->SetAsBox(width, height);
    
    physicsMgr->Add2DComponent(this);
    
    _Offset = new Point(0, 0);
    
    circleShape->m_radius = radius/PIXELS_TO_METERS;
}

PhysicsComponent2DCircle::~PhysicsComponent2DCircle()
{
    
}