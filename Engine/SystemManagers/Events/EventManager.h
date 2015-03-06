//
//  EventManager.h
//  ZenCoderEngine
//
//  Created by Srinavin Nair on 10/18/13.
//  Copyright (c) 2013 Srinavin Nair. All rights reserved.
//

#ifndef ZenCoderEngine_EventManager_h
#define ZenCoderEngine_EventManager_h

#include <SDL2/SDL.h>
#include <functional>
#include "SystemManager.h"

typedef  std::function<void()> EventCallbackDelegate;
typedef  std::function<void(SDL_Keycode keyCode)> KeyboardEventCallbackDelegate;

class EventManager:public SystemManager
{
private:
    static int ID;
    
    SDL_Event *evt;
    EventCallbackDelegate onSDLQuit;
    KeyboardEventCallbackDelegate onSDLKeyboardPress, onSDLKeyboardRelease;
    
    void OnEvent(SDL_Event *event);
    
public:
    EventManager();
    ~EventManager();
    
    void RegisterSDLQuit(EventCallbackDelegate func);
    void RegisterSDLKeyboardInputs(KeyboardEventCallbackDelegate keyPressFunc, KeyboardEventCallbackDelegate keyReleaseFunc);
    
    void Update();
};


#endif
