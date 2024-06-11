#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <iostream>
using namespace std;

class Product {
private:
    int Id;
    string Name;
    double UnitPrice;
    double StockBalance;

public:
    Product(int id, const string& name, double unitPrice, double stockBalance) :
    Id(id), Name(name), UnitPrice(unitPrice), StockBalance(stockBalance) {}

    int getId() const {return Id;}
    const string& getName() const {return Name;}
    double getUnitPrice() const {return UnitPrice;}
    double getStockBalance() const {return StockBalance;}

    void addStock(double quantity) {
        StockBalance += quantity;
        cout << "\033[36m";
        cout << "product `" << Name << "` stock changed to " << StockBalance << endl;
        cout << "\033[0m";        
    }
};

#endif //PRODUCT_H