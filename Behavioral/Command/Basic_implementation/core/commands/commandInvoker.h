#include <iostream>
#include <vector>
#include "ICommand.h"
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
    }
};