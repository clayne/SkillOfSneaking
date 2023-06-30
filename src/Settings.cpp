#include "Settings.h"
#include "SimpleIni.h"

Settings* Settings::GetSingleton() {
    static Settings singleton;
    return std::addressof(singleton);
}

void Settings::LoadSettings() {
    logger::info("Loading settings");
    CSimpleIniA ini;
    ini.SetUnicode();
    ini.LoadFile(R"(.\Data\SKSE\Plugins\SkillOfSneaking.ini)");

    sneak_xp_gain = std::atof(ini.GetValue("General", "fSneakXPGain"));

    logger::info("Loaded settings");
}