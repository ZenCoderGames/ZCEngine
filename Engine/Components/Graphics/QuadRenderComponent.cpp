//
//  QuadRenderComponent.cpp
//  ZenCoderEngine
//
//  Created by Srinavin Nair on 1/5/14.
//  Copyright (c) 2014 Srinavin Nair. All rights reserved.
//

#include "QuadRenderComponent.h"
#include "ZenCoderEngine.h"

QuadRenderComponent::QuadRenderComponent(Entity* entity, float w, float h):RenderComponent(entity)
{
    _graphicsManager = ZenCoderEngine::GetInstance()->GetGraphicsManager();
    
    _transformRect.w = w;
    _transformRect.h = h;
    
    _color = new Color(1,1,1,1);
    SetColor(1,1,1,1);
}

QuadRenderComponent::~QuadRenderComponent()
{
    delete _color;
    _color = NULL;
    
    if(_texture!=NULL) {
        delete _texture;
        _texture = NULL;
    }
}

void QuadRenderComponent::Update()
{
    glPushMatrix();
    
    glTranslatef(_entity->position.x, _entity->position.y, _entity->position.z);
    glRotatef( _entity->rotation.z, 0, 0, 1 );
    glScalef(_entity->scale.x, _entity->scale.y, _entity->scale.z);
    
    if(_texture!=NULL) {
        glBindTexture( GL_TEXTURE_2D, _texture->getId() );
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    }
    
    glBegin( GL_QUADS );
    glColor4f( _color->r, _color->g, _color->b, _color->a);
    
    if(_texture==NULL)
    {
        glVertex3f( -_transformRect.w, -_transformRect.h, 0 );
        glVertex3f(  _transformRect.w, -_transformRect.h, 0 );
        glVertex3f(  _transformRect.w,  _transformRect.h, 0 );
        glVertex3f( -_transformRect.w,  _transformRect.h, 0 );
    }
    else
    {
        Vector4 spritePos = _texture->GetSpritePos();
        
        glTexCoord2f( spritePos.x, spritePos.y ); glVertex3f( -_transformRect.w, _transformRect.h, 0 );
        glTexCoord2f( spritePos.z, spritePos.y ); glVertex3f(  _transformRect.w, _transformRect.h, 0 );
        glTexCoord2f( spritePos.z, spritePos.w ); glVertex3f(  _transformRect.w, -_transformRect.h, 0 );
        glTexCoord2f( spritePos.x, spritePos.w ); glVertex3f( -_transformRect.w,  -_transformRect.h, 0 );
    }
    
    glEnd();
    
    glDisable(GL_BLEND);
    glBindTexture(GL_TEXTURE_2D, NULL);
    
    glPopMatrix();
}

void QuadRenderComponent::SetColor(float r, float g, float b, float a)
{
    _color->r = r;
    _color->g = g;
    _color->b = b;
    _color->a = a;
}

void QuadRenderComponent::AddTexture(Texture *tex)
{
    _texture = tex;
}