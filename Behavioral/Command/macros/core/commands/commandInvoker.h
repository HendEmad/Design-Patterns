#ifndef COMMAND_INVOKER_H
#define COMMAND_INVOKER_H

#include <iostream>
#include <vector>
#include <memory>
#include "C:\Users\Data-DCS\Design-Patterns\Behavioral\Command\macros\core\commands\ICommand.h"
using namespace std;

class commandInvoker{
    vector<shared_ptr<ICommand>> _commands;
public:
    void AddCommand(const shared_ptr<ICommand>& command) {
        _commands.push_back(command);
    }

    void ExecuteCommands() {
        for(const auto& command: _commands) {
            command -> Execute();
        }
        clearCommands();
    }

    void clearCommands() {
        _commands.clear();
    }

    vector <shared_ptr<ICommand>> getCommands() {
        return _commands;
    }
};

#endif //COMMAND_INVOKER_H