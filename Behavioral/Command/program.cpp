#include <iostream>
#include <vector>
#include <numeric>
#include <memory>
#include "core/Product.h"
#include "core/Order.h"
#include "core/commands/commandInvoker.h"
#include "core/commands/addProduct.h"
#include "core/commands/addStock.h"

int main() {
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