#include <cstdio>
#include <cstdlib>
#include <dlfcn.h>
#include "libs/hook/inlineHook.h"
#include <android/log.h>
#include <cocos2d.h>

using namespace cocos2d;

CCLayer* _ml;

class callbacks {
public:
	void example(CCObject* pSender) {
		_ml->setScale(2);
	}
};

namespace h_menuLayer {
	void* (*o_init)(CCLayer*);
	void* init(CCLayer* self) {
		auto ret = o_init(self);
		_ml = self;
		auto s = CCSprite::createWithSpriteFrameName("GJ_playBtn_001.png");
		auto m = CCMenu::create();
		// menu_selector: exists
		// partur:
		auto b = CCMenuItemSprite::create(s, s, m, (SEL_MenuHandler)(&callbacks::example));
		m->addChild(b, 100);
		m->setPositionX(200);
		m->setPositionY(100);
		self->addChild(m, 100);

		return ret;
	}
}

__attribute__((constructor))
void fdml_init() {
	hook("_ZN9MenuLayer4initEv", h_menuLayer, init, o_init);
	inlineHookAll();
}
