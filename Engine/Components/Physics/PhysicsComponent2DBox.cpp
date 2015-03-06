//
//  PhysicsComponent2DBox.cpp
//  ZenCoderEngine
//
//  Created by Srinavin Nair on 10/27/13.
//  Copyright (c) 2013 Srinavin Nair. All rights reserved.
//

#include "PhysicsComponent2DBox.h"
#include "ZenCoderEngine.h"

PhysicsComponent2DBox::PhysicsComponent2DBox(Entity* entity, float width, float height, bool isStatic):PhysicsComponent2D(entity, isStatic)
{
     PhysicsManager *physicsMgr = ZenCoderEngine::GetInstance()->GetPhysicsManager();
    
    b2PolygonShape* polyShape = new b2PolygonShape();
    // Create shape
    shape = polyShape;
    // Create fixture
    fixture = new b2FixtureDef();
    fixture->shape = shape;
    if(!isStatic)
    {
        fixture->restitution = 0;
        fixture->density = 1.0f;
        fixture->friction = 0.0f;
    }
    
     polyShape->SetAsBox(width/PhysicsComponent2D::PIXELS_TO_METERS, height/PhysicsComponent2D::PIXELS_TO_METERS);

     physicsMgr->Add2DComponent(this);
    
    _Offset = new Point(0, 0);
}

PhysicsComponent2DBox::~PhysicsComponent2DBox()
{
    
}