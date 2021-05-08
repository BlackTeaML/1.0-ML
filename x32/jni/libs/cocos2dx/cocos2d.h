#ifndef COCOS2D_H
#define COCOS2D_H

// smaller than original cocos headers :ok_cool:
// note: tested only CCSprite::createWithSpriteFrameName, CCMenuItemSprite::create, node->setPositionX, node->setPositionY, node->addChild, node->setScale and CCMenu::create

namespace cocos2d {
  class CCPoint {
  public:
    float x;
    float y;
    CCPoint();
    CCPoint(float, float);
  };
  class CCSize {
  public:
    float width;
    float height;
    CCSize();
    CCSize(float, float);
  };
  class CCObject {
  public:
    CCObject(void);
  };
  typedef void (CCObject::*SEL_MenuHandler)(CCObject*);
  #define menu_selector(_SELECTOR) (SEL_MenuHandler)(&_SELECTOR)
	class CCNode : public CCObject {
	public:
    CCNode();
		void setScale(float);
		void setScaleX(float);
		void setScaleY(float);
		void getScale(float);
		void setPositionX(float);
		void setPositionY(float);
    void setPosition(cocos2d::CCPoint const&);
    cocos2d::CCPoint getPosition();
    float getPositionY();
    float getPositionX();
    bool isVisible();
    void setVisible();
    void getTag();
    void setTag(int);
    void addChild(cocos2d::CCNode*);
    void addChild(cocos2d::CCNode*, int);
    void removeChild(cocos2d::CCNode*, bool);
    void addChild(cocos2d::CCNode*, int, int);
    void setContentSize(cocos2d::CCSize const&);
    cocos2d::CCSize getContentSize();
    static CCNode* create();
	};
	class CCLayer : public cocos2d::CCNode {
  public:
    CCLayer();
    static CCLayer* create();
    void init();
  };
	class CCScene : public cocos2d::CCNode {
  public:
    CCScene();
    static CCScene* create();
    void init();
  };
  class CCSprite : public cocos2d::CCNode {
  public:
    CCSprite();
    static CCSprite* create(const char*);
    void init();
    static CCSprite* createWithSpriteFrameName(const char*);
  };
  class CCMenuItemSprite : public CCSprite {
  public:
    CCMenuItemSprite();
    static CCMenuItemSprite* create(cocos2d::CCNode*, cocos2d::CCNode*, cocos2d::CCObject*, SEL_MenuHandler);
  };
  class CCDirector {
  public:
    CCDirector();
    static CCDirector* sharedDirector();
    void pushScene(CCScene*);
    void popScene();
  };
  class CCMenu : public cocos2d::CCNode {
  public:
    CCMenu();
    static CCMenu* create();
  };
}

#endif
