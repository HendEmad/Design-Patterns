#include"Behavioral/Command/macros/core/commands/ICommand.h"
#include<chrono>
#include<iostream>
#include<memory>
#include<vector>
#include<ctime>
#include<iomanip>

using namespace std;

class Macro {
    int id;
    vector<shared_ptr<ICommand>> commands;
    chrono::system_clock::time_point createdAt;

public:
    Macro (int id, const vector<shared_ptr<ICommand>>& Commands) :
    id(id), commands(Commands), createdAt(chrono::system_clock::now()){}

    int getId() const {
        return id;
    }

    const vector<shared_ptr<ICommand>>& getCommands() const {
        return commands;
    }

    chrono::system_clock::time_point getCreatedAt() const {
        return createdAt;
    }  

    void printCreatedAt() const {
        time_t createdTime = chrono::system_clock::to_time_t(createdAt);
        cout << "Created at: " << put_time(localtime(&createdTime), "%F %T") << endl;
    }
};