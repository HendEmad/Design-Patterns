#include <iostream>
#include <string>

class ConfigurationManager {
private:
    static ConfigurationManager* instance;
    ConfigurationManager() {
        std::cout << "Loading configuration from file...\n";
    }
public:
    static ConfigurationManager* getInstance() {
        if(instance == nullptr)
            instance = new ConfigurationManager();
        return instance;
    }
    std::string getConfigValue(const std::string& key) {
        return "Value for " + key;
    }
};

ConfigurationManager* ConfigurationManager::instance = nullptr;
int main() {
    ConfigurationManager* config1 = ConfigurationManager::getInstance();
    ConfigurationManager* config2 = ConfigurationManager::getInstance();

    std::cout << config1->getConfigValue("Setting 1") << std::endl;
    std::cout << config2->getConfigValue("Setting 2") << std::endl; 
}
