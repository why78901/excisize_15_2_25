//
//  Hero.h
//  HelloWorld1
//
//  Created by zhenfengwang on 15/2/25.
//
//

#ifndef __HelloWorld1__Hero__
#define __HelloWorld1__Hero__

#include <stdio.h>
#include "BaseSprite.h"
USING_NS_CC;

class Hero : public BaseSprite
{
public:
    Hero();
    ~Hero();
    
    bool init();
    
    CREATE_FUNC(Hero);
    
    std::function<void(cocos2d::Point, float)> walk;
    std::function<void(void)> stop;
};
#endif /* defined(__HelloWorld1__Hero__) */
