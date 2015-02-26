//
//  Enemy.cpp
//  HelloWorld1
//
//  Created by zhenfengwang on 15/2/26.
//
//

#include "Enemy.h"

Enemy::Enemy():
    m_nextDecisionTime(0)
{
    
}

Enemy::~Enemy()
{
    
}

bool Enemy::init()
{
    bool ret = false;
    do {
        this->initWithSpriteFrameName("robot_idle_00.png");
        
        Animation *pIdleAnim = this->createAnimation("robot_idle_%02d.png", 5, 12);
        this->setIdleAction(RepeatForever::create(Animate::create(pIdleAnim)));
        
        Animation *pWalkAnim = this->createAnimation("robot_walk_%02d.png", 6, 12);
        this->setWalkAction(RepeatForever::create(Animate::create(pWalkAnim)));
        
        Animation *pAttackAnim = this->createAnimation("robot_attack_%02d.png", 5, 20);
        this->setAttackAction(Sequence::create(Animate::create(pAttackAnim), BaseSprite::createIdleCallbackFunc(), NULL));
        
        Animation *pHurtAnim = this->createAnimation("robot_hurt_%02d.png", 3, 20);
        this->setHurtAction(Sequence::create(Animate::create(pHurtAnim), BaseSprite::createIdleCallbackFunc(), NULL));
        
        Animation *pDeadAnim = this->createAnimation("robot_knockout_%02d.png", 5, 12);
        this->setDeadAction(Sequence::create(Animate::create(pDeadAnim), Blink::create(3, 9), BaseSprite::createDeadCallbackFunc(), NULL));
        
        Size enemyShowSize = this->getDisplayFrame()->getRect().size;
        this->m_bodyBox = this->createBoundingBox(Point(-enemyShowSize.width / 2, -enemyShowSize.height / 2), enemyShowSize);
        this->m_hitBox = this->createBoundingBox(Point(enemyShowSize.width / 2, -5), Size(25, 20));
        
        ret = true;
    } while(0);
    
    return ret;
}

