//
//  CDItem.cpp
//  BlackWings
//
//  Created by Jacky on 14-6-1.
//
//

#include "CDItem.h"
#include "Configuration.h"

USING_NS_CC;

CDItem* CDItem::create(int index, const CDEndCallback& callback)
{
    auto ret = new CDItem;
    if (ret && ret->init(index, callback))
    {
        ret->autorelease();
        return ret;
    }
    
    delete ret;
    return nullptr;
}

bool CDItem::init(int index, const CDEndCallback& callback)
{
    bool ret =false;
    
    _onFinish = callback;
    _index = index;
    _cdtime = s_plainConfigs[_index][s_playerConfig.fighterslevel[_index]].cd*60;
    _curcdtime = 0;
    _isMove = true;
    
    auto item_bk = Sprite::createWithSpriteFrameName("item_1.png");
    item_bk->setAnchorPoint(Point::ANCHOR_MIDDLE);
    this->addChild(item_bk);
    
    _cdBar = ui::LoadingBar::create("plain_progress.png");
    _cdBar->setPosition(Point(item_bk->getContentSize().width/2,30));
    _cdBar->setAnchorPoint(Point::ANCHOR_MIDDLE);
    item_bk->addChild(_cdBar);

    char fileName[30];
    int type = _index;
    int level = s_playerConfig.fighterslevel[type];

    sprintf(fileName,"plain_%d_lv_%d.png",type + 1,level + 1);
    auto plain = Sprite::createWithSpriteFrameName(fileName);
    plain->setAnchorPoint(Point::ANCHOR_MIDDLE);
    plain->setPosition(Point(item_bk->getContentSize().width/2,item_bk->getContentSize().height-55));
    item_bk->addChild(plain);
    
    this->scheduleUpdate();
    
    ret =true;
    return ret;
    
}

void CDItem::update(float dt)
{
    _curcdtime++;
    if (_curcdtime < _cdtime) {
        _cdBar->setPercent(float(_cdtime-_curcdtime)*100/_cdtime);
    }
    else
    {
        _cdBar->setPercent(0);
        _onFinish(this);
        removeFromParent();
        _eventDispatcher->dispatchCustomEvent(GameConfig::eventResortCDItems,this);
    }
}