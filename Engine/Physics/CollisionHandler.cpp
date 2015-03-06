//
//  CollisionHandler.cpp
//  ZenCoderEngine
//
//  Created by Srinavin Nair on 10/29/13.
//  Copyright (c) 2013 Srinavin Nair. All rights reserved.
//

#include "CollisionHandler.h"

CollisionHandler::CollisionHandler(PhysicsManager *physicsMgr)
{
    _physicsManager = physicsMgr;
}

CollisionHandler::~CollisionHandler()
{
    _physicsManager = NULL;
}

void CollisionHandler::BeginContact(b2Contact* contact)
{
    b2Body* bodyAUserData = contact->GetFixtureA()->GetBody();
    b2Body* bodyBUserData = contact->GetFixtureB()->GetBody();
    _physicsManager->HandleEnterCollision(bodyAUserData, bodyBUserData);
}

void CollisionHandler::EndContact(b2Contact* contact)
{
    b2Body* bodyAUserData = contact->GetFixtureA()->GetBody();
    b2Body* bodyBUserData = contact->GetFixtureB()->GetBody();
    _physicsManager->HandleExitCollision(bodyAUserData, bodyBUserData);
}