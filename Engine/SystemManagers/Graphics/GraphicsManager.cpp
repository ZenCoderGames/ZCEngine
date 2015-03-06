//
//  GraphicsManager.cpp
//  ZenCoderEngine
//
//  Created by Srinavin Nair on 10/13/13.
//  Copyright (c) 2013 Srinavin Nair. All rights reserved.
//

#include "GraphicsManager.h"
#include <assert.h>
#include "ZenCoderEngine.h"
#include "PhysicsManager.h"

int GraphicsManager::ID = 4;

bool GraphicsManager::SHOW_BOX_2D = false;
bool GraphicsManager::SHOW_RENDERERS = true;

static const string SHADER_PATH = "/Users/srinavinnair/Documents/Development/XCodeDev/ZenCoderEngineBase/Engine/Graphics/Shaders/";

GraphicsManager::GraphicsManager(int windowSizeX, int windowSizeY):SystemManager(ID)
{
    _windowSize = new Point(windowSizeX, windowSizeY);
    
    // Create the window where we will draw.
    _window = SDL_CreateWindow("ZenCoderEngine",
                              SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              windowSizeX, windowSizeY, SDL_WINDOW_OPENGL);

    initGL();
}

GraphicsManager::~GraphicsManager()
{
    delete _windowSize;
    _windowSize = NULL;
    SDL_GL_DeleteContext(_context);
    _context = NULL;
    SDL_DestroyWindow(_window);
    _window = NULL;
}

Point* GraphicsManager::GetWindowSize()
{
    return _windowSize;
}

void GraphicsManager::ClearScreen()
{
    //SDL_RenderClear(_renderer);
    glClear( GL_COLOR_BUFFER_BIT );
}

void GraphicsManager::initGL()
{
    /* Turn on double buffering with a 24bit Z buffer.
     * You may need to change this to 16 or 32 for your system */
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
    
    _context = SDL_GL_CreateContext(_window);
    
    /* This makes our buffer swap syncronized with the monitor's vertical refresh */
    SDL_GL_SetSwapInterval(1);

    _camera = new Camera(this, Camera::ORTHOGRAPHIC);

    //_camera->Zoom(5.5f);
    
    
	glEnable(GL_TEXTURE_2D);							// Enable Texture Mapping ( NEW ) - only for fixed pipeline
	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations
    
    
    //Check for error
    GLenum error = glGetError();
    if( error != GL_NO_ERROR )
    {
        assert( "Error initializing OpenGL! %s\n");
    }
}

void GraphicsManager::Update()
{
    //Clear color buffer and depth buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear The Screen And The Depth Buffer
	
    
    //Initialize clear color
    glClearColor( 0.f, 0.f, 0.f, 1.f );
    
    _camera->Init();
    
    if(SHOW_BOX_2D)
    {
        glPushMatrix();
        glScalef(50,50,50);
        PhysicsManager *physicsMgr = ZenCoderEngine::GetInstance()->GetPhysicsManager();
        physicsMgr->DrawDebugData();
        glPopMatrix();
    }
   
    // Draw 2D
    if(SHOW_RENDERERS)
    {
        for (_listOfRender2DComponentsItr = _listOfRender2DComponents.begin(); _listOfRender2DComponentsItr != _listOfRender2DComponents.end(); ++_listOfRender2DComponentsItr)
        {
            (*_listOfRender2DComponentsItr)->Update();
        }
    }
    
    SDL_GL_SwapWindow(_window);
}

void GraphicsManager::AddRenderComponent(RenderComponent* newRenderComponent)
{
    _listOfRender2DComponents.push_back(newRenderComponent);
}

void GraphicsManager::RemoveRenderComponent(RenderComponent* renderComponent)
{
    renderComponent->Stop();
    _listOfRender2DComponents.remove(renderComponent);
    
}

const char* GraphicsManager::filetobuf(const char *file)
{
    FILE *fptr;
    long length;
    char *buf;
    
    fptr = fopen(file, "rb"); /* Open file for reading */
    if (!fptr) /* Return NULL on failure */
        return NULL;
    fseek(fptr, 0, SEEK_END); /* Seek to the end of the file */
    length = ftell(fptr); /* Find out how many bytes into the file we are */
    buf = (char*)malloc(length+1); /* Allocate a buffer for the entire length of the file and a null terminator */
    fseek(fptr, 0, SEEK_SET); /* Go back to the beginning of the file */
    fread(buf, length, 1, fptr); /* Read the contents of the file in to the buffer */
    fclose(fptr); /* Close the file */
    buf[length] = 0; /* Null terminator */
    
    return buf; /* Return the buffer */
}

GLuint GraphicsManager::LoadShaders(string vertex_file_path, string fragment_file_path){
    
    // Create the shaders
    GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
    GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
    
    // Read the Vertex Shader code from the file
   /* string VertexShaderCode;
    ifstream VertexShaderStream(SHADER_PATH + vertex_file_path, std::ios::in);
    if(VertexShaderStream.is_open())
    {
        std::string Line = "";
        while(getline(VertexShaderStream, Line))
            VertexShaderCode += "\n" + Line;
        VertexShaderStream.close();
    }*/
    const char* VertexShaderCode = filetobuf((SHADER_PATH + vertex_file_path).c_str());
    
    // Read the Fragment Shader code from the file
    /*string FragmentShaderCode;
    ifstream FragmentShaderStream(SHADER_PATH + fragment_file_path, std::ios::in);
    if(FragmentShaderStream.is_open()){
        std::string Line = "";
        while(getline(FragmentShaderStream, Line))
            FragmentShaderCode += "\n" + Line;
        FragmentShaderStream.close();
    }*/
    
    const char* FragmentShaderCode = filetobuf((SHADER_PATH + fragment_file_path).c_str());
    
    GLint Result = GL_FALSE;
    int InfoLogLength;
    
    // Compile Vertex Shader
    //printf("Compiling shader : %s\n", vertex_file_path);
    //char const * VertexSourcePointer = VertexShaderCode.c_str();
    char const * VertexSourcePointer = VertexShaderCode;
    glShaderSource(VertexShaderID, 1, &VertexSourcePointer , NULL);
    glCompileShader(VertexShaderID);
    
    // Check Vertex Shader
    glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &Result);
    glGetShaderiv(VertexShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    std::vector<char> VertexShaderErrorMessage(InfoLogLength);
    glGetShaderInfoLog(VertexShaderID, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
    fprintf(stdout, "%s\n", &VertexShaderErrorMessage[0]);
    
    // Compile Fragment Shader
    //printf("Compiling shader : %s\n", fragment_file_path);
    //char const * FragmentSourcePointer = FragmentShaderCode.c_str();
    char const * FragmentSourcePointer = FragmentShaderCode;
    glShaderSource(FragmentShaderID, 1, &FragmentSourcePointer , NULL);
    glCompileShader(FragmentShaderID);
    
    // Check Fragment Shader
    glGetShaderiv(FragmentShaderID, GL_COMPILE_STATUS, &Result);
    glGetShaderiv(FragmentShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    std::vector<char> FragmentShaderErrorMessage(InfoLogLength);
    glGetShaderInfoLog(FragmentShaderID, InfoLogLength, NULL, &FragmentShaderErrorMessage[0]);
    fprintf(stdout, "%s\n", &FragmentShaderErrorMessage[0]);
    
    // Link the program
    fprintf(stdout, "Linking program\n");
    GLuint ProgramID = glCreateProgram();
    glAttachShader(ProgramID, VertexShaderID);
    glAttachShader(ProgramID, FragmentShaderID);
    glLinkProgram(ProgramID);
    
    // Check the program
    glGetProgramiv(ProgramID, GL_LINK_STATUS, &Result);
    glGetProgramiv(ProgramID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    std::vector<char> ProgramErrorMessage( max(InfoLogLength, int(1)) );
    glGetProgramInfoLog(ProgramID, InfoLogLength, NULL, &ProgramErrorMessage[0]);
    fprintf(stdout, "%s\n", &ProgramErrorMessage[0]);
    
    glDeleteShader(VertexShaderID);
    glDeleteShader(FragmentShaderID);
    
    return ProgramID;
}

GLuint GraphicsManager::loadShaderFromFile( std::string path, GLenum shaderType )
{
    //Open file
    GLuint shaderID = 0;
    std::string shaderString;
    std::ifstream sourceFile( path.c_str() );
    
    //Source file loaded
    if( sourceFile )
    {
        //Get shader source
        shaderString.assign( ( std::istreambuf_iterator< char >( sourceFile ) ), std::istreambuf_iterator< char >() );
        
        //Create shader ID
        shaderID = glCreateShader( shaderType );
        
        //Set shader source
        const GLchar* shaderSource = shaderString.c_str();
        glShaderSource( shaderID, 1, (const GLchar**)&shaderSource, NULL );
        
        //Compile shader source
        glCompileShader( shaderID );
        
        //Check shader for errors
        GLint shaderCompiled = GL_FALSE;
        glGetShaderiv( shaderID, GL_COMPILE_STATUS, &shaderCompiled );
        if( shaderCompiled != GL_TRUE )
        {
            printf( "Unable to compile shader %d!\n\nSource:\n%s\n", shaderID, shaderSource );
            glDeleteShader( shaderID );
            shaderID = 0;
        }
    }
    else
    {
        printf( "Unable to open file %s\n", path.c_str() );
    }
    
    return shaderID;
}