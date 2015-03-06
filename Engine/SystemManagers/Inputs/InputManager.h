//
//  InputManager.h
//  ZenCoderEngine
//
//  Created by Srinavin Nair on 10/18/13.
//  Copyright (c) 2013 Srinavin Nair. All rights reserved.
//

#ifndef ZenCoderEngine_InputManager_h
#define ZenCoderEngine_InputManager_h

#include "EventManager.h"

typedef  std::function<void(SDL_Keycode keyCode)> KeyboardEventCallbackDelegate;

class InputManager:public SystemManager
{
private:
    static int ID;
    
    void OnKeyboardInputPress(SDL_Keycode keyCode);
    void OnKeyboardInputRelease(SDL_Keycode keyCode);
    KeyboardEventCallbackDelegate OnKeyboardPress, OnKeyboardRelease;
    
public:
    InputManager(EventManager *evtManager);
    ~InputManager();
    
    void RegisterKeyboard(KeyboardEventCallbackDelegate onPressFunc, KeyboardEventCallbackDelegate onReleaseFunc);
    void Update() {}
};

#endif
