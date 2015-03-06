//
//  Camera.cpp
//  ZenCoderEngine
//
//  Created by Srinavin Nair on 1/11/14.
//  Copyright (c) 2014 Srinavin Nair. All rights reserved.
//

#include "Camera.h"

Camera::Camera(GraphicsManager *gMgr, TYPES typeVal)
{
    _type = typeVal;
    _graphicsManager = gMgr;
    
    projectionSize = 1.0f;
}

Camera::~Camera()
{
        
}

void Camera::Init()
{
    Point* windowSize = _graphicsManager->GetWindowSize();
    
    // Reset The Current Viewport
    ///Set the viewport
    glViewport( 0.f, 0.f, windowSize->x, windowSize->y);
       // glPushMatrix();
    //Initialize Projection Matrix
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    
    if(_type==ORTHOGRAPHIC)
    {
        glOrtho( 0.0, windowSize->x * projectionSize, 0.0f, windowSize->y * projectionSize, 1.0f, -1.0f);
    }
    else
    {
        // to do
    }
    
    // to center the camera at 0,0
    glTranslatef( windowSize->x * projectionSize / 2.f, windowSize->y * projectionSize / 2.f, 0.f );
    
   // glMatrixMode( GL_MODELVIEW );
   // glLoadIdentity();
    
    glTranslatef( position.x, position.y, position.z );
}

void Camera::Move(float x, float y, float z)
{
    SetPosition(x, y, z);
}

void Camera::Zoom(float zoomVal)
{
    projectionSize = zoomVal;
}

void Camera::Update()
{
        
}