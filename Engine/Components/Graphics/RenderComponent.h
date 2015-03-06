//
//  RenderComponent.h
//  ZenCoderEngine
//
//  Created by Srinavin Nair on 10/20/13.
//  Copyright (c) 2013 Srinavin Nair. All rights reserved.
//

#ifndef ZenCoderEngine__RenderComponent_h
#define ZenCoderEngine__RenderComponent_h

#include "Component.h"
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <string>
#include <OpenGL/gl.h>
#include "SOIL.h"

using namespace std;

class GraphicsManager;

class RenderComponent:public Component
{
private:
    GraphicsManager *_graphicsManager;
    
protected:
    static int ID;

    SDL_Rect _transformRect;
    
public:
    RenderComponent(Entity* entity);
    ~RenderComponent();
   
    virtual void Start();
    virtual void Update();
    virtual void Stop();
    
    inline float GetWidth() { return _transformRect.w; }
    inline float GetHeight() { return _transformRect.h; }
};

#endif
