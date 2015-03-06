//
//  EventManager.cpp
//  ZenCoderEngine
//
//  Created by Srinavin Nair on 10/18/13.
//  Copyright (c) 2013 Srinavin Nair. All rights reserved.
//

#include "EventManager.h"

int EventManager::ID = 3;

EventManager::EventManager():SystemManager(ID)
{
    evt = new SDL_Event();
}

EventManager::~EventManager()
{
    delete evt;
    evt = NULL;
}

void EventManager::RegisterSDLQuit(EventCallbackDelegate func)
{
    onSDLQuit = func;
}

void EventManager::RegisterSDLKeyboardInputs(KeyboardEventCallbackDelegate keyPressFunc, KeyboardEventCallbackDelegate keyReleaseFunc)
{
    onSDLKeyboardPress = keyPressFunc;
    onSDLKeyboardRelease = keyReleaseFunc;
}

void EventManager::Update()
{
    if(SDL_PollEvent(evt))
    {
        OnEvent(evt);
    }
}

void EventManager::OnEvent(SDL_Event *event)
{
    switch (event->type)
	{
		case SDL_QUIT:
        {
			if(onSDLQuit!=NULL) onSDLQuit();
			break;
		}
		case SDL_KEYDOWN:
		{
			if(onSDLKeyboardPress!=NULL) onSDLKeyboardPress(event->key.keysym.sym);
            break;
		}
        case SDL_KEYUP:
		{
			if(onSDLKeyboardRelease!=NULL) onSDLKeyboardRelease(event->key.keysym.sym);
            break;
		}
	}
}