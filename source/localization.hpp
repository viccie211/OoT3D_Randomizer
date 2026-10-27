#include <string>
#include <unordered_map>
#include "localization_dictionaries.hpp"
#include "debug.hpp"

typedef enum Languages {
  English,
  French,
  Spanish,
  Italian,
  German
} Languages;

class LocalizationManager {
private:
    Languages currentLanguage;
    std::unordered_map<Languages, std::unordered_map<std::string, std::string>*> dictionaries;
    std::unordered_map<std::string, std::string>* currentDictionary;

public:
    LocalizationManager() {
        // Initialization inside the constructor works because it's inside a function!
        
        dictionaries[English] = &localizationDictionaries->dictEnUS;
        dictionaries[French] = &localizationDictionaries->dictFrFR;

        // Set a default active dictionary
        currentLanguage=English;
        currentDictionary = dictionaries[currentLanguage];

    }

    ~LocalizationManager() {}

  void SetLanguage(Languages newLanguage){
      currentDictionary = dictionaries[newLanguage];
      currentLanguage = newLanguage;
  }
  void CycleLanguage(){
    if(currentLanguage==English)
        SetLanguage(French);
    else
        SetLanguage(English);
  }

  const char* GetString(std::string key){
    CitraPrint("Translation Key requested: " +key);
    auto translation = (*currentDictionary).find(key);
    CitraPrint("Translation found: "+(*currentDictionary)[key]);
    if(translation==(*currentDictionary).end()){
        return key.c_str();
    }
    return translation->second.c_str();
  }
};


static LocalizationManager* localizationManager = new LocalizationManager();