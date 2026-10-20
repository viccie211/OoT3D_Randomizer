#include <string>
#include <unordered_map>

typedef enum Languages {
  English,
  French,
  Spanish,
  Italian,
  German
} Languages;

class LocalizationManager {
private:
    std::unordered_map<Languages, std::unordered_map<std::string, std::string>*> dictionaries;
    std::unordered_map<std::string, std::string>* currentDictionary;

public:
    LocalizationManager() {
        // Initialization inside the constructor works because it's inside a function!
        
        auto englishDict = new std::unordered_map<std::string, std::string>();
        (*englishDict)["hello"] = "Hello";
        (*englishDict)["bye"] = "Goodbye";
        dictionaries[English] = englishDict;

        auto frenchDict = new std::unordered_map<std::string, std::string>();
        (*frenchDict)["hello"] = "Bonjour";
        (*frenchDict)["bye"] = "Au revoir";
        dictionaries[French] = frenchDict;

        // Set a default active dictionary
        currentDictionary = dictionaries[French];
    }

    // Clean up memory in the destructor
    ~LocalizationManager() {
        for (auto& [lang, dictPtr] : dictionaries) {
            delete dictPtr;
        }
    }

  void SetLanguage(Languages newLanguage){
      currentDictionary = dictionaries[newLanguage];
  }

  std::string GetString(std::string key){
    return (*currentDictionary)[key];
  }
};


static LocalizationManager* localizationManager = new LocalizationManager();