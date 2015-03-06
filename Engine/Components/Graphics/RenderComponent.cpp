//
//  RenderComponent.cpp
//  ZenCoderEngine
//
//  Created by Srinavin Nair on 10/20/13.
//  Copyright (c) 2013 Srinavin Nair. All rights reserved.
//

#include "RenderComponent.h"
#include "ZenCoderEngine.h"

int RenderComponent::ID = 2;

RenderComponent::RenderComponent(Entity* entity):Component(entity, ID)
{
    _graphicsManager = ZenCoderEngine::GetInstance()->GetGraphicsManager();
    
    _graphicsManager->AddRenderComponent(this);
}

RenderComponent::~RenderComponent()
{
    _graphicsManager->RemoveRenderComponent(this);
}

void RenderComponent::Start()
{
    
}

void RenderComponent::Update()
{
   
}

void RenderComponent::Stop()
{
    
}