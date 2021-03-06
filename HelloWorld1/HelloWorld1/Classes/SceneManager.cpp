//
//  SceneManager.cpp
//  HelloWorld1
//
//  Created by zhenfengwang on 15/2/25.
//
//

#include "SceneManager.h"
#include "GameScene.h"
#include "GameOverScene.h"

static SceneManager *s_pSceneManager = NULL;

SceneManager::SceneManager()
{
    
}

SceneManager::~SceneManager()
{
    
}

SceneManager* SceneManager::getInstance()
{
    if (!s_pSceneManager)
    {
        s_pSceneManager = new SceneManager();
    }
    return s_pSceneManager;
}

void SceneManager::showScene(SceneType SceneType)
{
    Scene *pScene = NULL;
    switch (SceneType)
    {
        case GAME_SCENE:
            pScene = GameScene::createScene();
            break;
        case GAME_OVER_SCENE:
            pScene = GameOverScene::createScene();
            break;
    }
    
    if (pScene)
    {
        Director::getInstance()->replaceScene(pScene);
    }
}