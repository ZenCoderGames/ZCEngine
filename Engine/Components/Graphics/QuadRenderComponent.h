//
//  QuadRenderComponent.h
//  ZenCoderEngine
//
//  Created by Srinavin Nair on 1/5/14.
//  Copyright (c) 2014 Srinavin Nair. All rights reserved.
//

#ifndef ZenCoderEngine_QuadRenderComponent_h
#define ZenCoderEngine_QuadRenderComponent_h

#include "RenderComponent.h"
#include "Color.h"
#include "Texture.h"

class GraphicsManager;

class QuadRenderComponent:public RenderComponent
{
private:
    GraphicsManager *_graphicsManager;
    Color *_color;
    Texture *_texture;
    
public:
    QuadRenderComponent(Entity* entity, float w=1, float h=1);
    ~QuadRenderComponent();
    
    void Update();
    void SetColor(float r, float g, float b, float a);
    void AddTexture(Texture *tex);
    
    inline Texture* GetTexture() { return _texture; }
};

#endif
