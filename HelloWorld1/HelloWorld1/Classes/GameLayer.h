//
//  GameLayer.h
//  HelloWorld1
//
//  Created by zhenfengwang on 15/2/25.
//
//

#ifndef __HelloWorld1__GameLayer__
#define __HelloWorld1__GameLayer__

#include <stdio.h>

USING_NS_CC;
#define MIN_ENEMY_COUNT 5
#define PATH_BG_MUSIC "background-music-aac.wav"
#define PATH_HERO_HIT_EFFECT "pd_hit0.wav"
#define PATH_ENEMY_HIT_EFFECT "pd_hit1.wav"
#define PATH_HERO_DEAD_EFFECT "pd_herodeath.mp3"
#define PATH_ENEMY_DEAD_EFFECT "pd_botdeath.wav"
#define PATH_HERO_TALK_EFFECT "hero_talk.mp3"

class BaseSprite;
class Hero;
class GameLayer : public Layer
{
public:
    GameLayer();
    ~GameLayer();
    
    virtual bool init();
    
    void onHeroWalk(cocos2d::Point direction, float distance);
    void onHeroAttack();
    void onHeroStop();
    void onHeroDead(BaseSprite *pTarget);
    
    void onEnemyAttack(BaseSprite *pSprite);
    void onEnemyDead(BaseSprite *pTarget);
    void addEnemy();
    
    void exitApp(Ref* pSender);
    
    CC_SYNTHESIZE_READONLY(Hero*, m_pHero, Hero);
    CREATE_FUNC(GameLayer);
private:
    TMXTiledMap *m_pTiledMap;
    float m_fTileWidth;
    float m_fTileHeight;
    
    float m_fScreenWidth;
    float m_fScreenHeight;
    cocos2d::Point m_origin;
    
    cocos2d::__Array *m_pEnemies;
    cocos2d::SpriteBatchNode *m_pSpriteNodes;
    
    cocos2d::ProgressTimer *m_pBlood;
    cocos2d::ProgressTimer *m_pBloodBg;
    cocos2d::MenuItemImage *m_pCloseItem;
};
#endif /* defined(__HelloWorld1__GameLayer__) */
