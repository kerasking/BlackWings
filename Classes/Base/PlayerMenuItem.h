#pragma once

#include "cocos2d.h"
#include "TextSprite.h"

USING_NS_CC;

class PlayerMenuItem : public MenuItemImage
{
public:
    enum class Type
    {
        Fighter,
        Weapon
    };
   static PlayerMenuItem* create(Type playerType,int index);

   bool init(Type playerType,int index);

   virtual void activate();

private:
    PlayerMenuItem();
    
    void activeCD_callback(EventCustom* event);
    
    void unselectedall(EventCustom* event);
    
    void updateFlightData(EventCustom* event);
    void updateWeaponData(EventCustom* event);

    TextSprite * _label;
    int typeIndex;
    
    Type _type;
    int _index;
    
    TextSprite* stoneformake_text;
    Label* countNum;
    Label* stoneTatalNum;
};
