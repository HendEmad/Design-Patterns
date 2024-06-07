#include "C:\Users\Data-DCS\Design-Patterns\Behavioral\Command\core\Product.h"
#include "C:\Users\Data-DCS\Design-Patterns\Behavioral\Command\core\Order.h"

Product laptop(1, "laptop", 20000, 10);
Product keyboard(2, "keyboard", 300, 50);
Product mouse(3, "mouse", 600, 70);

while(true) {
    Order order;
    while(true) {
        cout << "Select one of the below commands: " << endl;
        cout << "\t1. Add lapop" << endl;
        cout << "\t2. Add keyboard" << endl;
        cout << "\t3. Add mouse" << endl;
        cout << "\t4. Process and exit" << endl;

        Product selectProduct = NULL;
        int commandId;
        cin >> commandId;
        
        if(commandId == 1)
            selectProduct = laptop;
        else if (commandId == 2)
            selectProduct = keyboard;
        else if (commandId == 3)
            selectProduct = mouse;
        else if (commandId == 0) {
            double totalQuantity = accumulate(order.getLines().begin(), order.getLines().end(), 0.0,
            [](double sum, const orderLine& line){
                return sum + line.quantity;
            });
            double totlPrice = accumulate(order.gerLines().begin(), order.getLines().end(), 0.0,
            [](double sum, const orderLine& line){
                return sum + (line.quantity * line.unitPrice);
            }
            )
        }
    }
}