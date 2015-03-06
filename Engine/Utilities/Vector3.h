//
//  Vector3.h
//  ZenCoderEngine
//
//  Created by Srinavin Nair on 1/12/14.
//  Copyright (c) 2014 Srinavin Nair. All rights reserved.
//

#ifndef ZenCoderEngine_Vector3_h
#define ZenCoderEngine_Vector3_h

#include <iostream>

class Vector3
{
public:
    float x, y, z;
    
    Vector3(float xVal=0, float yVal=0, float zVal=0)
    {
        Set(xVal, yVal, zVal);
    }
    
    ~Vector3() {}
    
    inline void Set(float xVal, float yVal, float zVal)
    {
        x = xVal;
        y = yVal;
        z = zVal;
    }
    
    inline void Add(float xVal, float yVal, float zVal)
    {
        x += xVal;
        y += yVal;
        z += zVal;
    }
    
    inline void Print()
    {
        std::cout<<x<<","<<y<<","<<z<<std::endl;
    }
};

#endif
