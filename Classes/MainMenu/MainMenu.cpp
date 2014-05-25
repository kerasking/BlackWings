#include "MainMenu.h"
#include "VisibleRect.h"
#include "MenuItemImageLabel.h"
#include "LoadResourceLayer.h"
#include "Configuration.h"
#include "GameStrings.h"
#include "MenuSettings.h"
#include "HelpLayer.h"
#include "AboutLayer.h"
#include "Base.h"

USING_NS_CC;

bool MainMenu::init()
{
    if (Scene::init())
    {
        auto loadLayer = LoadResourceLayer::create(CC_CALLBACK_1(MainMenu::createBg, this));
        loadLayer->addImage("allBt.png");
        loadLayer->addImage("icons.png");
        loadLayer->addImage("plains.png");
        loadLayer->addImage("bombs.png");
        this->addChild(loadLayer);
        loadLayer->startLoad();

        return true;
    }

    return false;
}

void MainMenu::createBg(Ref *sender)
{
    this->removeChild((LoadResourceLayer*)sender,true);

    auto frameCache = SpriteFrameCache::getInstance();
    frameCache->addSpriteFramesWithFile("allBt.plist");
    frameCache->addSpriteFramesWithFile("icons.plist");
    frameCache->addSpriteFramesWithFile("plains.plist");
    frameCache->addSpriteFramesWithFile("bombs.plist");

    if (fabs(s_visibleRect.visibleHeight - 1136) < FLT_EPSILON)
    {
        auto mainMenuBg = Sprite::create("mainBackground_bg.png");
        mainMenuBg->setPosition(s_visibleRect.center);
        addChild(mainMenuBg);
    }
    auto mainMenuBg = Sprite::create("mainBackground.png"); 
    mainMenuBg->setPosition(s_visibleRect.center);
    addChild(mainMenuBg);

    auto logo = Sprite::create("logo.png");
    logo->setAnchorPoint(Point::ANCHOR_MIDDLE_TOP);
    logo->setPosition(s_visibleRect.center.x,s_visibleRect.top.y - 50);
    addChild(logo);

    auto action = RepeatForever::create( Sequence::create( MoveBy::create(3.0f,Point(0,20)),
        MoveBy::create(3.0f,Point(0,-20)),nullptr) );
    logo->runAction(action);

    createMenu();
}

void MainMenu::createMenu()
{
    auto itemStart = MenuItemImageLabel::createWithFrameName("bt_main_0.png","bt_main_1.png",
        CC_CALLBACK_1(MainMenu::menuCallbackPlay,this),s_gameStrings.mainMenu->play);

    auto itemHelp = MenuItemImageLabel::createWithFrameName("bt_main_0.png","bt_main_1.png",
        CC_CALLBACK_1(MainMenu::menuCallbackHelp,this),s_gameStrings.mainMenu->help);

    auto itemSettings = MenuItemImageLabel::createWithFrameName("bt_main_0.png","bt_main_1.png",
        CC_CALLBACK_1(MainMenu::menuCallbackSettings,this),s_gameStrings.mainMenu->settings);

    auto itemAbout = MenuItemImageLabel::createWithFrameName("bt_main_0.png","bt_main_1.png",
        CC_CALLBACK_1(MainMenu::menuCallbackAbout,this),s_gameStrings.mainMenu->about);

    Point itemPos(s_visibleRect.center.x, s_visibleRect.center.y - 50);
    itemStart->setPosition(itemPos); 
    itemPos.y -= 100;
    itemHelp->setPosition(itemPos);
    itemPos.y -= 100;
    itemSettings->setPosition(itemPos);
    itemPos.y -= 100;
    itemAbout->setPosition(itemPos);

    auto menu = Menu::create( itemStart, itemHelp, itemSettings, itemAbout, nullptr);
    menu->setPosition(Point::ZERO);
    addChild(menu);

    itemStart->setScale(1.0f,0.0f);
    itemHelp->setScale(1.0f,0.0f);
    itemSettings->setScale(1.0f,0.0f);
    itemAbout->setScale(1.0f,0.0f);

    auto scaleAction = ScaleTo::create(0.17f,1.0f,1.0f);
    itemStart->runAction(scaleAction);
    itemHelp->runAction(Sequence::create(DelayTime::create(0.17f),scaleAction->clone(),nullptr));
    itemSettings->runAction(Sequence::create(DelayTime::create(0.34f),scaleAction->clone(),nullptr));
    itemAbout->runAction(Sequence::create(DelayTime::create(0.51f),scaleAction->clone(),nullptr));

    auto listener = EventListenerCustom::create(GameConfig::eventLanguageChange, [=](EventCustom* event){
        itemStart->setText(s_gameStrings.mainMenu->play);
        itemHelp->setText(s_gameStrings.mainMenu->help);
        itemSettings->setText(s_gameStrings.mainMenu->settings);
        itemAbout->setText(s_gameStrings.mainMenu->about);
    });

    _eventDispatcher->addEventListenerWithFixedPriority(listener, 1);
}

void MainMenu::menuCallbackPlay(Ref *sender)
{
    _eventDispatcher->removeCustomEventListeners(GameConfig::eventLanguageChange);

    auto base = Base::create();
    Director::getInstance()->replaceScene(base);
}

void MainMenu::menuCallbackHelp(Ref *sender)
{
    auto helpLayer = HelpLayer::create();
    addChild(helpLayer);
}

void MainMenu::menuCallbackSettings(Ref *sender)
{
    auto settingLayer = MenuSettings::create();
    addChild(settingLayer);
}

void MainMenu::menuCallbackAbout(Ref *sender)
{
    auto aboutLayer = AboutLayer::create();
    addChild(aboutLayer);
}
