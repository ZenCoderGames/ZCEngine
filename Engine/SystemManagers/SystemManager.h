//
//  SystemManager.h
//  ZenCoderEngine
//
//  Created by Srinavin Nair on 10/20/13.
//  Copyright (c) 2013 Srinavin Nair. All rights reserved.
//

#ifndef ZenCoderEngine_SystemManager_h
#define ZenCoderEngine_SystemManager_h

class SystemManager
{
private:
    int _id;
    
public:
    SystemManager(int id)
    {
        _id = id;
    }
    
    ~SystemManager() {}
    
    virtual void Update() = 0;
};

#endif
