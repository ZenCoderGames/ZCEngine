//
//  Vector4.h
//  ZenCoderEngine
//
//  Created by Srinavin Nair on 1/13/14.
//  Copyright (c) 2014 Srinavin Nair. All rights reserved.
//

#ifndef ZenCoderEngine_Vector4_h
#define ZenCoderEngine_Vector4_h

class Vector4
{
public:
    float x, y, z, w;
    
    Vector4(float rVal=0, float gVal=0, float bVal=0, float aVal=0)
    {
        Set(rVal, gVal, bVal, aVal);
    }
    
    ~Vector4() {}
    
    inline void Set(float rVal, float gVal, float bVal, float aVal)
    {
        x = rVal;
        y = gVal;
        z = bVal;
        w = aVal;
    }
    
    inline void Add(float rVal, float gVal, float bVal, float aVal)
    {
        x += rVal;
        y += gVal;
        z += bVal;
        w += aVal;
    }
};

#endif
