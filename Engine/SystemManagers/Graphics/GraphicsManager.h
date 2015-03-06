//
//  Graphics.h
//  ZenCoderEngine
//
//  Created by Srinavin Nair on 10/13/13.
//  Copyright (c) 2013 Srinavin Nair. All rights reserved.
//

#ifndef ZenCoderEngine_Graphics_h
#define ZenCoderEngine_Graphics_h

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <string>
#include <list>
#include "RenderComponent.h"
#include "Point.h"
#include "SystemManager.h"
#include <vector>
#include <iostream>
#include <fstream>
#include "Camera.h"


// glm
#include "glm.hpp"
//#include "matrix_projection.hpp"
#include "matrix_transform.hpp"

using namespace std;

class Camera;

class GraphicsManager:public SystemManager
{
private:
    static int ID;
    
    SDL_Window* _window;
    //SDL_Renderer* _renderer;
    SDL_GLContext _context;
    list<RenderComponent*> _listOfRender2DComponents;
    list<RenderComponent*>::const_iterator _listOfRender2DComponentsItr;
    
    Point* _windowSize;
    
    Camera *_camera;
    
public:
    GraphicsManager(int windowSizeX, int windowSizeY);
    ~GraphicsManager();
    
    void ClearScreen();
    Point* GetWindowSize();
    void initGL();
    GLuint LoadShaders(string vertex_file_path, string fragment_file_path);
    
    //inline SDL_Renderer* GetRenderer() { return _renderer; }
    
    void AddRenderComponent(RenderComponent* newRenderComponent);
    void RemoveRenderComponent(RenderComponent* renderComponent);
    
    void Update();
    
    GLuint loadShaderFromFile( std::string path, GLenum shaderType );
    const char* filetobuf(const char *file);
    
    // glm
    glm::mat4 projectionMatrix; // Store the projection matrix
    glm::mat4 viewMatrix; // Store the view matrix
    glm::mat4 modelMatrix; // Store the model matrix
    
    static bool SHOW_BOX_2D;
    static bool SHOW_RENDERERS;
    
    inline Camera* GetCamera()
    {
        return _camera;
    }
};

#endif
