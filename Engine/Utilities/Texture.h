//
//  Texture.h
//  ZenCoderEngine
//
//  Created by Srinavin Nair on 1/12/14.
//  Copyright (c) 2014 Srinavin Nair. All rights reserved.
//

#ifndef ZenCoderEngine_Texture_h
#define ZenCoderEngine_Texture_h

#include <SDL2/SDL_opengl.h>
#include <stdio.h>
#include "Vector4.h"

class Texture
{
private:
    GLuint _Width, _Height, _Id;
    bool _isSpriteSheet;
    float _spriteSize;
    int _numRows, _numCols;
    Vector4 _currentSpritePos;
    
    void freeTexture();
    
public:
    Texture(int w, int h);
    Texture(GLuint* pixels, GLuint width, GLuint height);
    Texture(const char* textureName, GLuint width, GLuint height);
    ~Texture();
    
    GLuint getId();
    GLuint getWidth();
    GLuint getHeight();
    
    void SetAsSpriteSheet(float sizeOfEachSprite, int numRows, int numCols);
    void SetSpritePos(int row, int col);
    Vector4 GetSpritePos();
};

#endif
