//
//  Enemy.h
//  HelloWorld1
//
//  Created by zhenfengwang on 15/2/26.
//
//

#ifndef __HelloWorld1__Enemy__
#define __HelloWorld1__Enemy__

#include <stdio.h>
#include "BaseSprite.h"
USING_NS_CC;

typedef enum {
    AI_IDLE = 0,
    AI_PATROL,
    AI_ATTACK,
    AI_PURSUIT
}AiState;

class Enemy : public BaseSprite
{
public:
    Enemy();
    ~Enemy();
    
    bool init();
    
    CREATE_FUNC(Enemy);
    
    CC_SYNTHESIZE(cocos2d::Point, m_moveDirection, MoveDirection);
    CC_SYNTHESIZE(float, m_eyeArea, EyeArea);
    CC_SYNTHESIZE(float, m_attackArea, AttackArea)
    CC_SYNTHESIZE(AiState, m_aiState, AiState);
    
    void execute(const cocos2d::Point& target, float targetBodyWidth);
    
private:
    void decide(const cocos2d::Point& target, float targetBodyWidth);
    
    unsigned int m_nextDecisionTime;
};
#endif /* defined(__HelloWorld1__Enemy__) */
