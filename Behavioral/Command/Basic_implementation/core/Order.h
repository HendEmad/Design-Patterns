#ifndef ORDER_H
#define ORDER_H

#include <vector>
#include <iostream>
#include <random>
#include "OrderLine.h"
#include "Product.h"
using namespace std;

class Order {
private:
    static int generateRandomId() {
        static random_device rd;
        static mt19937 gen(rd());
        static uniform_int_distribution<> dis(1, 1000);
        return dis(gen);
    }

    int Id;
    vector<OrderLine> lines;

public:
    Order() : Id(generateRandomId()) {}
    int getId() const {return Id;}
    const vector <OrderLine>& getLines() const {return lines;}

    void addProduct(const Product& product, double quantity) {
        lines.emplace_back(product.getId(), quantity, product.getUnitPrice());
        cout << "\033[33m";
        cout << "product `" << product.getName() << "` added, order now contains " << lines.size() << " products" << endl;
        cout << "\033[0m";
    }

};

#endif // ORDER_H