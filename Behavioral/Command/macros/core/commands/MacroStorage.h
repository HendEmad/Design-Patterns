#ifndef MACROSTORAGE_H
#define MACROSTORAGE_H

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include "Behavioral/Command/macros/core/commands/Macro.h"
#include "Behavioral/Command/macros/core/commands/ICommand.h"
using namespace std;

class MacroStorage {
    vector<Macro> macros;
public:
    MacroStorage() = default;  // private constructor for singleton

    MacroStorage(const MacroStorage&) = delete;  // delete copy constructor
    MacroStorage& operator= (const MacroStorage&) = delete;  // delete assignemnt operator

    static MacroStorage* getInstance() {
        static MacroStorage* instance = new MacroStorage();
        return instance;
    }

    void createMacro(const vector<shared_ptr<ICommand>>& commands) {
        Macro macro(macros.size()+1, commands);
        macros.push_back(macro);

    cout << "\033[33m";
    cout << "Macro #" << macro.getId() << " saved." << endl;
    cout << "\033[0m";
    }
    
    const vector<Macro>& getMacros() const {
        return macros;
    }

    Macro getMacro(int id) const {
        auto it = find_if(macros.begin(), macros.end(), [id](const Macro& macro) {return macro.getId() == id;});
        
        if(it != macros.end())
            return *it;
        else
            throw runtime_error ("Macro not found!");
    }
};

#endif // MACROSTORAGE_H