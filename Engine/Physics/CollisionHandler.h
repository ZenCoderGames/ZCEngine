//
//  CollisionHandler.h
//  ZenCoderEngine
//
//  Created by Srinavin Nair on 10/29/13.
//  Copyright (c) 2013 Srinavin Nair. All rights reserved.
//

#ifndef ZenCoderEngine_CollisionHandler_h
#define ZenCoderEngine_CollisionHandler_h

#include "PhysicsManager.h"
#include <Box2D/Box2D.h>

class PhysicsManager;

class CollisionHandler:public b2ContactListener
{
private:
    PhysicsManager *_physicsManager;
    
public:
    CollisionHandler(PhysicsManager *physicsMgr);
    ~CollisionHandler();
    
    void BeginContact(b2Contact* contact);
    void EndContact(b2Contact* contact);
};


#endif
