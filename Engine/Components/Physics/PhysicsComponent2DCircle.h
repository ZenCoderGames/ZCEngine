//
//  PhysicsComponent2DCircle.h
//  ZenCoderEngine
//
//  Created by Srinavin Nair on 1/19/14.
//  Copyright (c) 2014 Srinavin Nair. All rights reserved.
//

#ifndef ZenCoderEngine_PhysicsComponent2DCircle_h
#define ZenCoderEngine_PhysicsComponent2DCircle_h

#include "PhysicsComponent2D.h"

class PhysicsComponent2DCircle:public PhysicsComponent2D
{
private:
    
    
public:
    PhysicsComponent2DCircle(Entity* entity, float radius, bool isStatic);
    ~PhysicsComponent2DCircle();
};


#endif
