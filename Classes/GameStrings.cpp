#include "GameStrings.h"
#include "cocos2d.h"

GameStrings s_gameStrings;

void GSMainMenuInit(GameLanguage language)
{
    static bool lazyInitCh = true;
    static bool lazyInitEn = true;
    static MainMenuStrings s_chMainMenuStrings;
    static MainMenuStrings s_enMainMenuStrings;

    bool parseString = false;
    std::string  mainMenuPath;

    auto fileUtils = cocos2d::FileUtils::getInstance();

    switch (language)
    {
    case GameLanguage::Chinese:
        if (lazyInitCh)
        {
            mainMenuPath = fileUtils->fullPathForFilename("stringsCh.xml");
            parseString = true;
            lazyInitCh = false;
        }
        s_gameStrings.mainMenu = &s_chMainMenuStrings;
        break;
    case GameLanguage::English:
        if (lazyInitEn)
        {
            mainMenuPath = fileUtils->fullPathForFilename("stringsEn.xml");
            parseString = true;
            lazyInitEn = false;
        }
        s_gameStrings.mainMenu = &s_enMainMenuStrings;
        break;
    default:
        break;
    }

    if (parseString)
    {
        auto dict = fileUtils->getValueMapFromFile(mainMenuPath);

        s_gameStrings.mainMenu->play = dict["mainMenuStart"].asString();
        s_gameStrings.mainMenu->help = dict["mainMenuHelp"].asString();
        s_gameStrings.mainMenu->settings = dict["mainMenuSettings"].asString();
        s_gameStrings.mainMenu->about = dict["mainMenuAbout"].asString();

        s_gameStrings.mainMenu->settingMusic = dict["settingMusic"].asString();
        s_gameStrings.mainMenu->settingSFX = dict["settingSFX"].asString();
        s_gameStrings.mainMenu->settingSelLanguage = dict["settingSelLanguage"].asString();
        s_gameStrings.mainMenu->settingLanguage = dict["settingLanguage"].asString();
        s_gameStrings.mainMenu->settingReset = dict["settingReset"].asString();
        s_gameStrings.mainMenu->settingRedeemCode = dict["settingRedeemCode"].asString();
        s_gameStrings.mainMenu->settingRedeem = dict["settingRedeem"].asString();
        s_gameStrings.mainMenu->settingRedeemHintText = dict["settingRedeemHintText"].asString();

        s_gameStrings.mainMenu->settingResetTipTitle = dict["settingResetTipTitle"].asString();
        s_gameStrings.mainMenu->settingResetTipContent = dict["settingResetTipContent"].asString();
        s_gameStrings.mainMenu->settingResetConfirm = dict["settingResetConfirm"].asString();
        s_gameStrings.mainMenu->settingResetCancel = dict["settingResetCancel"].asString();
        s_gameStrings.mainMenu->settingResetNotification = dict["settingResetNotification"].asString();

        s_gameStrings.mainMenu->settingResume = dict["settingResume"].asString();
        s_gameStrings.mainMenu->settingRetry = dict["settingRetry"].asString();
        s_gameStrings.mainMenu->settingBackToBase = dict["settingBackToBase"].asString();

        s_gameStrings.mainMenu->helpTitle = dict["helpTitle"].asString();
        
        s_gameStrings.mainMenu->aboutVersions = dict["aboutVersions"].asString();
        s_gameStrings.mainMenu->aboutMicroblog = dict["aboutMicroblog"].asString();
        s_gameStrings.mainMenu->aboutEmail = dict["aboutEmail"].asString();
        s_gameStrings.mainMenu->aboutRate = dict["aboutRate"].asString();
        s_gameStrings.mainMenu->aboutRateAppreciation = dict["aboutRateAppreciation"].asString();
    }
}

void GSHelpInfoInit(GameLanguage language)
{
    static bool lazyInitCh = true;
    static bool lazyInitEn = true;
    static HelpInfoStrings s_chHelpInfo;
    static HelpInfoStrings s_enHelpInfo;

    bool parseString = false;
    std::string  helpInfoPath;

    auto fileUtils = cocos2d::FileUtils::getInstance();

    switch (language)
    {
    case GameLanguage::Chinese:
        if (lazyInitCh)
        {
            helpInfoPath = fileUtils->fullPathForFilename("helpInfoCh.xml");
            parseString = true;
            lazyInitCh = false;
        }
        s_gameStrings.helpInfo = &s_chHelpInfo;
        break;
    case GameLanguage::English:
        if (lazyInitEn)
        {
            helpInfoPath = fileUtils->fullPathForFilename("helpInfoEn.xml");
            parseString = true;
            lazyInitEn = false;
        }
        s_gameStrings.helpInfo = &s_enHelpInfo;
        break;
    default:
        break;
    }

    if (parseString)
    {
        auto dict = fileUtils->getValueMapFromFile(helpInfoPath);

        s_gameStrings.helpInfo->sparInfo = dict["sparInfo"].asString();
        s_gameStrings.helpInfo->gemInfo = dict["gemInfo"].asString();

        s_gameStrings.helpInfo->fighter[0] = dict["fighter1"].asString();
        s_gameStrings.helpInfo->fighter[1] = dict["fighter2"].asString();
        s_gameStrings.helpInfo->fighter[2] = dict["fighter3"].asString();
        s_gameStrings.helpInfo->fighter[3] = dict["fighter4"].asString();
        s_gameStrings.helpInfo->fighter[4] = dict["fighter5"].asString();
        s_gameStrings.helpInfo->fighter[5] = dict["fighter6"].asString();
        s_gameStrings.helpInfo->fighterLocked = dict["fighterLocked"].asString();

        s_gameStrings.helpInfo->weapon[0] = dict["weapon1"].asString();
        s_gameStrings.helpInfo->weapon[1] = dict["weapon2"].asString();
        s_gameStrings.helpInfo->weapon[2] = dict["weapon3"].asString();
        s_gameStrings.helpInfo->weaponLocked = dict["weaponLocked"].asString();
    }
}

void GSBaseInit(GameLanguage language)
{
    static bool lazyInitCh = true;
    static bool lazyInitEn = true;
    static BaseStrings s_chBaseStrings;
    static BaseStrings s_enBaseStrings;

    bool parseString = false;
    std::string  baseStringsFilePath;

    auto fileUtils = cocos2d::FileUtils::getInstance();

    switch (language)
    {
    case GameLanguage::Chinese:
        if (lazyInitCh)
        {
            baseStringsFilePath = fileUtils->fullPathForFilename("baseStringsCh.xml");
            parseString = true;
            lazyInitCh = false;
        }
        s_gameStrings.base = &s_chBaseStrings;
        break;
    case GameLanguage::English:
        if (lazyInitEn)
        {
            baseStringsFilePath = fileUtils->fullPathForFilename("baseStringsEn.xml");
            parseString = true;
            lazyInitEn = false;
        }
        s_gameStrings.base = &s_enBaseStrings;
        break;
    default:
        break;
    }

    if (parseString)
    {
        auto dict = fileUtils->getValueMapFromFile(baseStringsFilePath);

        s_gameStrings.base->topBarMedal = dict["topBarMedal"].asString();
        s_gameStrings.base->topBarBattle = dict["topBarBattle"].asString();
        s_gameStrings.base->topBarMainMenu = dict["topBarMainMenu"].asString();

        s_gameStrings.base->upgrade = dict["upgrade"].asString();
        s_gameStrings.base->upgradeLevel = dict["upgradeLevel"].asString();
        s_gameStrings.base->upgradeAtt = dict["upgradeAtt"].asString();
        s_gameStrings.base->upgradeDef = dict["upgradeDef"].asString();
        s_gameStrings.base->upgradeLife = dict["upgradeLife"].asString();
        s_gameStrings.base->upgradeSpd = dict["upgradeSpd"].asString();
        s_gameStrings.base->upgradeRange = dict["upgradeRange"].asString();

        s_gameStrings.base->weaponQuantity = dict["weaponQuantity"].asString();
        
        s_gameStrings.base->sparCapacity = dict["sparCapacity"].asString();
        s_gameStrings.base->sparRecoverRate = dict["sparRecoverRate"].asString();
        s_gameStrings.base->second = dict["second"].asString();
        
    }
}