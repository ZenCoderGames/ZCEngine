//
//  ZCEngine.h
//  ZenCoderEngine
//
//  Created by Srinavin Nair on 10/13/13.
//  Copyright (c) 2013 Srinavin Nair. All rights reserved.
//

#ifndef ZenCoderEngine_ZCEngine_h
#define ZenCoderEngine_ZCEngine_h

#include "EventManager.h"
#include "PhysicsManager.h"
#include "InputManager.h"
#include "EntityManager.h"
#include "GraphicsManager.h"
#include <assert.h>
#include <list>

class ZenCoderEngine
{
private:
    static ZenCoderEngine *_instance;
    
    PhysicsManager *_physicsManager;
    EventManager *_eventManager;
    InputManager *_inputManager;
    EntityManager *_entityManager;
    GraphicsManager *_graphicsManager;
    list<SystemManager*> _systemManagerList;
    list<SystemManager*>::const_iterator _systemManagerListItr;
    bool _isRunning;
    
    ZenCoderEngine();
    ~ZenCoderEngine();
    ZenCoderEngine(ZenCoderEngine const&); // don't implement
    void operator = (ZenCoderEngine const&); //don't implement
    
    void OnQuit();
public:
    static ZenCoderEngine* GetInstance();
    
    void Init(int windowSizeX, int windowSizeY);
    void Update();
    void CreateBlockingDelay(int numMilliSecs);
    inline void DeInit() { OnQuit(); }
    
    inline bool IsRunning() { return _isRunning; }

    inline PhysicsManager* GetPhysicsManager() { return _physicsManager; }
    inline EventManager* GetEventManager() { return _eventManager; }
    inline InputManager* GetInputManager() { return _inputManager; }
    inline EntityManager* GetEntityManager() { return _entityManager; }
    inline GraphicsManager* GetGraphicsManager() { return _graphicsManager; }
    
    inline static void DestroyInstance() {
        delete _instance;
        _instance = NULL;
    }
};

#endif
