//
//  InputManager.cpp
//  ZenCoderEngine
//
//  Created by Srinavin Nair on 10/18/13.
//  Copyright (c) 2013 Srinavin Nair. All rights reserved.
//

#include "InputManager.h"

int InputManager::ID = 5;

InputManager::InputManager(EventManager* evtManager):SystemManager(ID)
{
    using namespace std::placeholders;
    evtManager->RegisterSDLKeyboardInputs(std::bind(&InputManager::OnKeyboardInputPress, this, _1),
                                  std::bind(&InputManager::OnKeyboardInputRelease, this, _1));
}

InputManager::~InputManager()
{
    
}

void InputManager::RegisterKeyboard(KeyboardEventCallbackDelegate onPressFunc, KeyboardEventCallbackDelegate onReleaseFunc)
{
    OnKeyboardPress = onPressFunc;
    OnKeyboardRelease = onReleaseFunc;
}

void InputManager::OnKeyboardInputPress(SDL_Keycode keyCode)
{
    if(OnKeyboardPress!=NULL) OnKeyboardPress(keyCode);
}

void InputManager::OnKeyboardInputRelease(SDL_Keycode keyCode)
{
    if(OnKeyboardRelease!=NULL) OnKeyboardRelease(keyCode);
}