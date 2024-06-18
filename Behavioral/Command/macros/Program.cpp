#include"core/Product.h"
#include"core/Order.h"
#include"Behavioral/Command/macros/core/commands/commandInvoker.h"
#include"Behavioral/Command/macros/core/commands/addStock.h"
#include "Behavioral/Command/macros/core/commands/addProduct.h"
#include"Behavioral/Command/macros/core/commands/MacroStorage.h"
#include <iostream>
#include <numeric>
#include <vector>
#include <memory>
MacroStorage* macro_ = new MacroStorage(); 

int main() {
    void replayMacro();
    Product laptop(1, "laptop", 20000, 10);
    Product keyboard(2, "keyboard", 300, 50);
    Product mouse(3, "mouse", 150, 70);

    while(true) {
        Order order;
        commandInvoker invoker;     
        while(true) {
            cout << "Select one of the below commands: " << endl;
            cout << "\t1. add laptop" << endl;
            cout << "\t2. add keyboard" << endl;
            cout << "\t3. add mouse" << endl;
            cout << "\t4. save macro" << endl;
            cout << "\t5. replay macro" << endl;
            cout << "\t0. process and exit" << endl;

            int commandId;
            cin >> commandId;

            if(commandId == 1){
                invoker.AddCommand(make_shared<addProduct>(order, laptop, 1));
                invoker.AddCommand(make_shared<addStock>(laptop, -1));
            }
            else if (commandId == 2){
                invoker.AddCommand(make_shared<addProduct>(order, keyboard, 1));
                invoker.AddCommand(make_shared<addStock>(keyboard, -1));
            }
            else if(commandId == 3){
                invoker.AddCommand(make_shared<addProduct>(order, mouse, 1));
                invoker.AddCommand(make_shared<addStock>(mouse, -1));
            }
            else if(commandId == 4) {
                macro_ ->createMacro(invoker.getCommands());
                invoker.clearCommands();
            }

            else if(commandId == 5) {
                replayMacro();
            }

            else if(commandId == 0) {
                invoker.ExecuteCommands();
                double totalQuantity = accumulate(order.getLines().begin(), order.getLines().end(), 0.0, 
                [](double sum, const OrderLine& line) {
                    return sum + line.Quantity;
                });

                double totalPrice = accumulate(order.getLines().begin(), order.getLines().end(), 0.0,
                [](double sum, const OrderLine& line){
                    return sum + (line.Quantity * line.UnitPrice);
                });
                cout << "\033[33m";
                cout << "order # " << order.getId() << " created: Quantity = " << totalQuantity << ", total price = " << totalPrice << endl;
                cout << "\033[0m";
                break;
            }
        }
        cout << "=================================================================" << endl;
    }
    return 0;
}

void replayMacro() {
    cout << "Enter macro ID: " << endl;
    for(const auto& macro : macro_->getMacros()) {
        // convert the time_point to a readable string format
        time_t createdAtTimeT = chrono::system_clock::to_time_t(macro.getCreatedAt());
        cout << macro.getId() << "(commands count: " << macro.getCommands().size() << ", created at " << ctime(&createdAtTimeT) << '\n';
    }
    int macroId;
    cin >> macroId;
    try{
        const Macro& selectedMacro = macro_->getMacro(macroId);
        Order order;
        commandInvoker invoker;
        for(auto& command : selectedMacro.getCommands()){
            if(auto addProd = dynamic_cast<addProduct*>(command.get())){
                addProd -> order = order;
            }
            invoker.AddCommand(command);
        }
        invoker.ExecuteCommands();
    }
    catch(const runtime_error& e){
        cout << e.what() << endl;  // handle error if macro is not found
    }
}
