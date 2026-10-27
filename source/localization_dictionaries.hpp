#include <unordered_map>
#include <string>

class LocalizationDictionaries {

public:
  std::unordered_map<std::string, std::string> dictEnUS;
  std::unordered_map<std::string, std::string> dictFrFR;

  LocalizationDictionaries(){
    dictEnUS = {
      {"navigate","\x1b[4;10HA/B/D-pad: Navigate Menu\n"},
      {"selectExit","            Select: Exit to Homebrew Menu\n"},
      {"newRandomSeed", "                 Y: New Random Seed\n"},
      {"inputCustomSeed", "                 X: Input Custom Seed\n"},
      {"currentSeed", "\x1b[11;7HCurrent Seed: %s\n"},
    };

    dictFrFR= {
      {"navigate","\x1b[4;10HA/B/D-pad: Parcourir le menu\n"},
      {"selectExit","            Select: Quitter vers le menu Homebrew\n"},
      {"newRandomSeed", "        Y: Nouvelle graine aléatoire\n"},
      {"inputCustomSeed", "      X: Saisir une graine personnalisée\n"},
      {"currentSeed", "\x1b[11;7HGraine actuelle: %s\n"},
    };
  }

};

static LocalizationDictionaries* localizationDictionaries = new LocalizationDictionaries();