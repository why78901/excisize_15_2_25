//
//  OperateLayer.cpp
//  HelloWorld1
//
//  Created by zhenfengwang on 15/2/25.
//
//

#include "OperateLayer.h"
#include "Hero.h"
USING_NS_CC;

OperateLayer::OperateLayer():
    m_pJoystick(NULL),
    m_pJoystickBg(NULL)
{
    
}

OperateLayer::~OperateLayer()
{
    
}

bool OperateLayer::init()
{
    bool ret = false;
    do {
        CC_BREAK_IF(!Layer::init());
        
        m_pJoystick = Sprite::create("joystick.png");
        m_pJoystickBg = Sprite::create("joystick_bg.png");
        this->addChild(m_pJoystickBg,0);
        this->addChild(m_pJoystick,1);
        
        this->hideJoystick();
        
        auto listener = EventListenerTouchAllAtOnce::create();
        listener->onTouchesBegan = CC_CALLBACK_2(OperateLayer::onTouchesBegan, this);
        listener->onTouchesMoved = CC_CALLBACK_2(OperateLayer::onTouchesMoved, this);
        listener->onTouchesEnded = CC_CALLBACK_2(OperateLayer::onTouchesEnded, this);
        _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
        
        ret = true;
        
    } while (false);
    
    return ret;
}

void OperateLayer::showJoystick(Point pos)
{
    m_pJoystick->setPosition(pos);
    m_pJoystickBg->setPosition(pos);
    
    m_pJoystick->setVisible(true);
    m_pJoystickBg->setVisible(true);
}

void OperateLayer::hideJoystick()
{
    m_pJoystick->setPosition(m_pJoystickBg->getPosition());
    m_pJoystick->setVisible(false);
    m_pJoystickBg->setVisible(false);
}

void OperateLayer::updateJoystick(cocos2d::Point direction, float distance)
{
    Point start = m_pJoystickBg->getPosition();
    
    if (distance < 33)
    {
        m_pJoystick->setPosition(start + (direction * distance));
    }
    else if (distance > 78)
    {
        m_pJoystick->setPosition(start + (direction * 45));
    }
    else
    {
        m_pJoystick->setPosition(start + (direction * 33));
    }
}

void OperateLayer::onTouchesBegan(const std::vector<cocos2d::Touch *> &touches, cocos2d::Event *unused_event)
{
    Size winSize = Director::getInstance()->getWinSize();
    Vector<Touch*>::const_iterator touchIter = touches.begin();
    while (touchIter != touches.end())
    {
        Touch *pTouch = (Touch*)(*touchIter);
        Point p = pTouch->getLocation();
        if (p.x <= winSize.width / 2)
        {
            this->showJoystick(p);
        }
        else
        {
            m_pHero->attack();
        }
        
        ++touchIter;
    }
}

void OperateLayer::onTouchesMoved(const std::vector<cocos2d::Touch *> &touches, cocos2d::Event *unused_event)
{
    Size winSize = Director::getInstance()->getWinSize();
    Vector<Touch*>::const_iterator touchIter = touches.begin();
    Touch *pTouch = (Touch*)(*touchIter);
    Point start = pTouch->getStartLocation();
    if (start.x > winSize.width /2)
    {
        return;
    }
    Point dest = pTouch->getLocation();
    float dicstance = start.getDistance(dest);
    Point value = dest - start;
    value.normalize();
    Point direction = value;
    this->updateJoystick(direction, dicstance);
    
    m_pHero->walk(direction,dicstance);
}

void OperateLayer::onTouchesEnded(const std::vector<cocos2d::Touch *> &touches, cocos2d::Event *unused_event)
{
    this->hideJoystick();
    m_pHero->stop();
}