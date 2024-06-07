#include <string>
#include <iostream>
using namespace std;

class Product {
    int id, stockBalance;
    string name;
    double unitPrice;

public:
    Product(int id, const string& name, double unitPrice, int stockBalance) {
        this -> id = id;
        this -> name = name;
        this -> unitPrice = unitPrice;
        this -> stockBalance = stockBalance;
    }

    int getId() const {return id;}
    string getName() const {return name;}
    double getUnitPrice() const {return unitPrice;}
    int getStockBalance() const {return stockBalance;}

    void addStock(double quantity) {
        stockBalance += quantity;
        cout << "\033[36m0";  // set console text color to Cyan
        cout << "Product `" << name << "` stock changes to " << stockBalance << endl;
        cout << "\033[0m";  // reset console text color to default;
    }
};