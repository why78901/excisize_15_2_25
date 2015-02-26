//
//  SceneManager.h
//  HelloWorld1
//
//  Created by zhenfengwang on 15/2/25.
//
//

#ifndef __HelloWorld1__SceneManager__
#define __HelloWorld1__SceneManager__

#include <stdio.h>

typedef enum {
    GAME_SCENE = 0,
    GAME_OVER_SCENE = 1,
}SceneType;

class SceneManager
{
public:
    SceneManager();
    ~SceneManager();
    
    static SceneManager* getInstance();
    
    void showScene(SceneType SceneType);
};
#endif /* defined(__HelloWorld1__SceneManager__) */
