//
//  Color.h
//  ZenCoderEngine
//
//  Created by Srinavin Nair on 1/12/14.
//  Copyright (c) 2014 Srinavin Nair. All rights reserved.
//

#ifndef ZenCoderEngine_Color_h
#define ZenCoderEngine_Color_h

class Color
{
public:
    float r, g, b, a;
    
    Color(float rVal, float gVal, float bVal, float aVal)
    {
        Set(rVal, gVal, bVal, aVal);
    }
    
    ~Color() {}
    
    inline void Set(float rVal, float gVal, float bVal, float aVal)
    {
        r = rVal;
        g = gVal;
        b = bVal;
        a = aVal;
    }
    
    inline void Add(float rVal, float gVal, float bVal, float aVal)
    {
        r += rVal;
        g += gVal;
        b += bVal;
        a += aVal;
    }
};

#endif
