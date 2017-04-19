#ifndef __GAMESCENE_SCENE_H__
#define __GAMESCENE_SCENE_H__

#include "cocos2d.h"
#include "../Globals.h"
#include "../handlers/MapHandler.h"
#include "../objects/Player.h"
#include "../candypunk/World.h"
#include "../objects/FlashLayer.h"

USING_NS_CC;

class GameScene : public World
{
#define MIN_CAMERA_POS 10
#define ON_ROOM_CHANGE_DELAY 0.3f
public:
    static GameScene* getInstance();
    
    static cocos2d::Scene* createScene();
    
    static GameScene* create();
    
    virtual bool init();
    
    void update(float dt);
    void flashColor( cocos2d::Color3B color );
    void createBackground();
    void setGameActive(bool active){ gameActive = active; };
    void createDithering();
    Player* getPlayer();
    
private:
    void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
    void moveCamera(float dt);
    
public:
    MapHandler* mapH;
    Player* playerObj = nullptr;
    FlashLayer* flashLayer;
    cocos2d::Vec2 lastPlayerPos;
    cocos2d::Size visibleSize;
    bool gameActive = false;

private:
    static GameScene* _instance;
    int roomsIndex = 1;
    bool cameraIsMoving = false;
    float cameraYPos = 0.0f;
    
};

#endif // __GAMESCENE_SCENE_H__
