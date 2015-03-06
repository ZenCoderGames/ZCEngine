//
//  Box2DDebugDraw.h
//  ZenCoderEngine
//
//  Created by Srinavin Nair on 1/17/14.
//  Copyright (c) 2014 Srinavin Nair. All rights reserved.
//

#ifndef ZenCoderEngine_Box2DDebugDraw_h
#define ZenCoderEngine_Box2DDebugDraw_h

#include "Box2D.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

class Box2DDebugDraw : public b2Draw
{
private:
    
    
public:
    Box2DDebugDraw();
    ~Box2DDebugDraw();
    
    void DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color);
    
	void DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color);
    
	void DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color);
    
	void DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color);
    
	void DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color);
    
	void DrawTransform(const b2Transform& xf);
    
    void DrawPoint(const b2Vec2& p, float32 size, const b2Color& color);
    
    void DrawString(int x, int y, const char* string, ...);
    
    void DrawAABB(b2AABB* aabb, const b2Color& color);
};

#endif
