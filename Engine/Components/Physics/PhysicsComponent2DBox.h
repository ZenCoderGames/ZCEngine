//
//  PhysicsComponent2DBox.h
//  ZenCoderEngine
//
//  Created by Srinavin Nair on 10/27/13.
//  Copyright (c) 2013 Srinavin Nair. All rights reserved.
//

#ifndef ZenCoderEngine_PhysicsComponent2DBox_h
#define ZenCoderEngine_PhysicsComponent2DBox_h

#include "PhysicsComponent2D.h"

class PhysicsComponent2DBox:public PhysicsComponent2D
{
private:

    
public:
    PhysicsComponent2DBox(Entity* entity, float width, float height, bool isStatic);
    ~PhysicsComponent2DBox();
};


#endif
