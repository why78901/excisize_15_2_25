//
//  GameOverScene.h
//  HelloWorld1
//
//  Created by zhenfengwang on 15/2/25.
//
//

#ifndef __HelloWorld1__GameOverScene__
#define __HelloWorld1__GameOverScene__

#include <stdio.h>
USING_NS_CC;

class GameOverLayer : public LayerColor
{
public:
    GameOverLayer();
    virtual ~GameOverLayer();
    
    CREATE_FUNC(GameOverLayer);
    
    void restartGame();
    bool init();
    
    CC_SYNTHESIZE_READONLY(cocos2d::Label*, m_pLabel, GameOverLabel);
};

class GameOverScene
{
public:
    static Scene* createScene();
};
#endif /* defined(__HelloWorld1__GameOverScene__) */
