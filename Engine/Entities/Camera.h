//
//  Camera.h
//  ZenCoderEngine
//
//  Created by Srinavin Nair on 1/11/14.
//  Copyright (c) 2014 Srinavin Nair. All rights reserved.
//

#ifndef ZenCoderEngine_Camera_h
#define ZenCoderEngine_Camera_h

#include "Entity.h"
#include "GraphicsManager.h"

class Camera:public Entity
{
public:
    enum TYPES {ORTHOGRAPHIC, PERSPECTIVE};
    Camera(GraphicsManager *gMgr, TYPES typeVal);
    ~Camera();
    
    void Init();
    void Move(float x, float y, float z);
    void Zoom(float zoomVal);
    void Update();
    
private:
    GraphicsManager *_graphicsManager;
    TYPES _type;
    
    float projectionSize;
};

#endif
