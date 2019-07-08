﻿/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "AudioEngine.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// シーンの初期化(一度だけ実行される)
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();



	DelayTime* delay = DelayTime::create(3.0f);
	// 関数呼び出しアクション
	//CallFunc* callFunc = CallFunc::create(
	//	CC_CALLBACK_0(HelloWorld::myFunction, this));
	CallFunc* callFunc = CallFunc::create(
		CC_CALLBACK_0(HelloWorld::myFunction2, this, "HelloWorld.png"));
	CallFunc* callFunc2 = CallFunc::create(
		CC_CALLBACK_0(HelloWorld::myFunction2, this, "panda.jpg"));
	Sequence* seq = Sequence::create(delay, callFunc, delay, callFunc2, nullptr);

	this->runAction(seq);
	//this->myFunction();

	// サウンド再生								  ループ 音量
	audioID = experimental::AudioEngine::play2d("testbgm.mp3", false, 0.8f);

	// update関数を有効にする
	this->scheduleUpdate();

    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}

void HelloWorld::update(float delta)
{
}

void HelloWorld::myFunction()
{
	Sprite* spr = Sprite::create("HelloWorld.png");
	this->addChild(spr);
	spr->setPosition(Vec2(500, 500));
}

void HelloWorld::myFunction2(std::string filename)
{
	Sprite* spr = Sprite::create(filename);
	this->addChild(spr);
	spr->setPosition(Vec2(500, 500));
}