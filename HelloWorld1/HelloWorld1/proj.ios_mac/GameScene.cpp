//
//  GameScene.cpp
//  HelloWorld1
//
//  Created by zhenfengwang on 15/2/25.
//
//

#include "GameScene.h"
#include "GameLayer.h"
#include "OperateLayer.h"

Scene* GameScene::createScene()
{
    auto scene = Scene::create();
    
    auto gameLayer = GameLayer::create();
    scene->addChild(gameLayer,0);
    
    auto operateLayer = OperateLayer::create();
    scene->addChild(operateLayer,1);
    operateLayer->setHero(gameLayer->getHero());
    
    return scene;
}