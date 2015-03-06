//
//  Texture.cpp
//  ZenCoderEngine
//
//  Created by Srinavin Nair on 1/12/14.
//  Copyright (c) 2014 Srinavin Nair. All rights reserved.
//

#include "Texture.h"
#include "SOIL.h"

Texture::Texture(int w, int h)
{
    int CHECKERBOARD_PIXEL_COUNT = w * h;
    GLuint checkerBoard[ CHECKERBOARD_PIXEL_COUNT ];
    
    //Go through pixels
    for( int i = 0; i < CHECKERBOARD_PIXEL_COUNT; ++i )
    {
        //Get the individual color components
        GLubyte* colors = (GLubyte*)&checkerBoard[ i ];
        
        //Set pixel to red
        colors[ 0 ] = 0xFF;
        colors[ 1 ] = 0xFF;
        colors[ 2 ] = 0xFF;
        colors[ 3 ] = 0xFF;
    }
    
    Texture(checkerBoard, w, h);
}

Texture::Texture(GLuint* pixels, GLuint width, GLuint height )
{
    //Free texture if it exists
    freeTexture();
    
    //Get texture dimensions
    _Width = width;
    _Height = height;
    
    //Generate texture ID
    glGenTextures( 1, &_Id );
    
    //Bind texture ID
    glBindTexture( GL_TEXTURE_2D, _Id );
    
    //Generate texture
    glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels );
    
    //Update texture (3,4,5,6 params are x,y,w,h of segment to be modified)
    //glTexSubImage2D( GL_TEXTURE_2D, 0, 0, 0, mTextureWidth, mTextureHeight, GL_RGBA, GL_UNSIGNED_BYTE, mPixels );
    
    //Set texture parameters
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
    
    //Unbind texture
    glBindTexture( GL_TEXTURE_2D, NULL );
    
    //Check for error
    GLenum error = glGetError();
    if( error != GL_NO_ERROR )
    {
        printf( "Error loading texture from %p pixels!\n", pixels);
    }
    
    _currentSpritePos.x = 0;
    _currentSpritePos.y = 0;
    _currentSpritePos.z = 1;
    _currentSpritePos.w = 1;
}

Texture::Texture(const char* textureName, GLuint width, GLuint height)
{
    //Free texture if it exists
    freeTexture();
    
    //Get texture dimensions
    _Width = width;
    _Height = height;
    
    _Id = SOIL_load_OGL_texture
    (
     textureName,
     SOIL_LOAD_AUTO,
     SOIL_CREATE_NEW_ID,
     SOIL_FLAG_INVERT_Y
     );
    
    //Bind texture ID
    glBindTexture( GL_TEXTURE_2D, _Id );
    
    //Set texture parameters
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
    
    //Unbind texture
    glBindTexture( GL_TEXTURE_2D, NULL );
    
    _currentSpritePos.x = 0;
    _currentSpritePos.y = 0;
    _currentSpritePos.z = 1;
    _currentSpritePos.w = 1;
}

Texture::~Texture()
{
    freeTexture();
}

void Texture::freeTexture()
{
    //Delete texture
    if( _Id != 0 )
    {
        glDeleteTextures( 1, &_Id );
        _Id = 0;
    }
    
    _Width = 0;
    _Width = 0;
}

GLuint Texture::getId()
{
    return _Id;
}

GLuint Texture::getWidth()
{
    return _Width;
}

GLuint Texture::getHeight()
{
    return _Height;
}

void Texture::SetAsSpriteSheet(float sizeOfEachSprite, int numRows, int numCols)
{
    _isSpriteSheet = true;
    _spriteSize = sizeOfEachSprite;
    _numRows = numRows;
    _numCols = numCols;
    
    SetSpritePos(0,0);
}

void Texture::SetSpritePos(int row, int col)
{
    row = _numRows - row - 1;
    
    _currentSpritePos.x = col * _spriteSize / _Width;
    _currentSpritePos.y = row * _spriteSize / _Height;
    _currentSpritePos.z = (col * _spriteSize + _spriteSize)  / _Width;
    _currentSpritePos.w = (row * _spriteSize + _spriteSize) / _Height;
}

Vector4 Texture::GetSpritePos()
{
    return _currentSpritePos;
}
