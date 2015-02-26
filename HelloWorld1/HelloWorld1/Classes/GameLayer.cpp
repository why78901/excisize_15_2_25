//
//  GameLayer.cpp
//  HelloWorld1
//
//  Created by zhenfengwang on 15/2/25.
//
//

#include "GameLayer.h"
#include "Hero.h"

bool collisionDetection(const BoundingBox &hitBox, const BoundingBox &bodyBox)
{
    Rect hitRect = hitBox.actual;
    Rect bodyRect = bodyBox.actual;
    if(hitRect.intersectsRect(bodyRect))
    {
        return true;
    }
    
    return false;
}

GameLayer::GameLayer()
    :m_pTiledMap(NULL),
    m_pSpriteNodes(NULL),
    m_pHero(NULL),
    m_pEnemies(NULL),
    m_pBlood(NULL),
    m_pBloodBg(NULL)
{
    
}

GameLayer::~GameLayer()
{
    this->unscheduleUpdate();
    CC_SAFE_RELEASE(m_pEnemies);
}

bool GameLayer::init()
{
    bool ret = false;
    do {
        CC_BREAK_IF(!Layer::init());
        
        auto visibleSize = Director::getInstance()->getVisibleSize();
        this->m_origin = Director::getInstance()->getVisibleOrigin();
        this->m_fScreenWidth = visibleSize.width;
        this->m_fScreenHeight = visibleSize.height;
        
        m_pCloseItem = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_1(GameLayer::exitApp, this));
        m_pCloseItem->setPosition(this->m_origin + Point(visibleSize) -Point(m_pCloseItem->getContentSize()/2));
        auto menu = Menu::create(m_pCloseItem,NULL);
        menu->setPosition(Point::ZERO);
        this->addChild(menu,1);
        
        m_pTiledMap = TMXTiledMap::create("pd_tilemap.tmx");
        this->addChild(m_pTiledMap);
        Size tileSize = m_pTiledMap->getTileSize();
        m_fTileWidth = tileSize.width;
        m_fTileHeight = tileSize.height;
        
        SpriteFrameCache::getInstance()->addSpriteFramesWithFile("pd_sprites.plist");
        m_pSpriteNodes = SpriteBatchNode::create("pd_sprites.pvr.ccz");
        this->addChild(m_pSpriteNodes);
        
        m_pHero = Hero::create();
        m_pHero->setPosition(m_origin = Point(100,100));
        m_pHero->runIdleAction();
        m_pHero->setZOrder(m_fScreenHeight - m_pHero->getPositionY());
        m_pHero->setAttack(5);
        m_pHero->setHP(100);
//        m_pHero->onDeadCallback = CC_CALLBACK_0(GameLayer::on, <#__target__, ...#>)
    } while (0);
    return ret;
}

void GameLayer::exitApp(Ref* pSender)
{
    Director::getInstance()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void GameLayer::onHeroDead(BaseSprite *pTarget)
{
    if (m_pHero->getCurrActionState() == ACTION_STATE_DEAD)
    {
        pTarget->removeSprite();
        
    }
}