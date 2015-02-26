//
//  OperateLayer.h
//  HelloWorld1
//
//  Created by zhenfengwang on 15/2/25.
//
//

#ifndef __HelloWorld1__OperateLayer__
#define __HelloWorld1__OperateLayer__

#include <stdio.h>
USING_NS_CC;

class Hero;
class OperateLayer : public Layer
{
public:
    OperateLayer();
    ~OperateLayer();
    virtual bool init();
    
    CREATE_FUNC(OperateLayer);
    
    void onTouchesBegan(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event *unused_event);
    void onTouchesMoved(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event *unused_event);
    void onTouchesEnded(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event *unused_event);
    
    CC_SYNTHESIZE(Hero*, m_pHero, Hero);
    
private:
    Sprite *m_pJoystick;
    Sprite *m_pJoystickBg;
    
};
#endif /* defined(__HelloWorld1__OperateLayer__) */
