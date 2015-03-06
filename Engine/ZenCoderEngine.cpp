//
//  ZenCoderEngine.cpp
//  ZenCoderEngine
//
//  Created by Srinavin Nair on 10/13/13.
//  Copyright (c) 2013 Srinavin Nair. All rights reserved.
//

#include "ZenCoderEngine.h"

ZenCoderEngine *ZenCoderEngine::_instance = NULL;

ZenCoderEngine* ZenCoderEngine::GetInstance()
{
    if(_instance==NULL)
    {
        _instance = new ZenCoderEngine();
    }
    
    return _instance;
}

ZenCoderEngine::ZenCoderEngine()
{
    _isRunning = false;
}

ZenCoderEngine::~ZenCoderEngine()
{
    delete _entityManager;
    delete _physicsManager;
    delete _eventManager;
    delete _inputManager;
    delete _graphicsManager;
    
    _systemManagerList.clear();
    
    SDL_Quit();
}

void ZenCoderEngine::OnQuit()
{
    _isRunning = false;
}

void ZenCoderEngine::Init(int windowSizeX, int windowSizeY)
{
    if (SDL_Init(SDL_INIT_VIDEO) >= 0)
    {
        _physicsManager = new PhysicsManager(0.0f, 10.0f);
        _eventManager = new EventManager();
        _eventManager->RegisterSDLQuit(std::bind(&ZenCoderEngine::OnQuit, this));
        _inputManager = new InputManager(_eventManager);
        _entityManager = new EntityManager();
        _graphicsManager = new GraphicsManager(windowSizeX, windowSizeY);
        
        _systemManagerList.push_back(_physicsManager);
        _systemManagerList.push_back(_eventManager);
        _systemManagerList.push_back(_entityManager);
        _systemManagerList.push_back(_graphicsManager);
        
        _isRunning = true;
        return;
    }
    
    assert("SDL not initialized");
}

void ZenCoderEngine::Update()
{
    for (_systemManagerListItr = _systemManagerList.begin(); _systemManagerListItr != _systemManagerList.end(); ++_systemManagerListItr)
    {
        (*_systemManagerListItr)->Update();
    }
}

void ZenCoderEngine::CreateBlockingDelay(int numMilliSecs)
{
    SDL_Delay(numMilliSecs);
}