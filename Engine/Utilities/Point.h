//
//  Point.h
//  ZenCoderEngine
//
//  Created by Srinavin Nair on 10/13/13.
//  Copyright (c) 2013 Srinavin Nair. All rights reserved.
//

#ifndef ZenCoderEngine_Point_h
#define ZenCoderEngine_Point_h

class Point
{
public:
    float x, y;
    
    Point(float xVal=0, float yVal=0)
    {
        Set(xVal, yVal);
    }
    
    ~Point() {}
    
    inline void Set(float xVal, float yVal)
    {
        x = xVal;
        y = yVal;
    }
    
    inline void Add(float xVal, float yVal)
    {
        x += xVal;
        y += yVal;
    }
};

#endif
