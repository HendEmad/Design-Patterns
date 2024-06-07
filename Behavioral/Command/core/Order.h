#include <iostream>
#include <random>
#include <vector>
#include <memory>
#include <algorithm>
#include"Product.h"
#include "orderLine.cpp"
using namespace std;

class Order{
private:
    int Id;
    vector<orderLine> lines;

    static int generateRandomId() {
        static random_device rd;  // number generator used to seed the random number engine
        static mt19937 gen(rd());  // standard random number engine in c++, seeded from the value from random_device
        static uniform_int_distribution<> dis(1, 1000);  // ensure that the numbers generated are uniformaly distributed across the specified range
        return dis(gen);
    }

public:
    Order() : Id(generateRandomId()) {}

    int gerId() const {return Id;}
    const vector<orderLine>& getLines() const {return lines;}

    void addProduct(const Product& product, int quantity){
        lines.push_back(orderLine{product.getId(), product.getUnitPrice(), quantity});
        cout << "\033[33m";
        cout << "Prodcut `" << product.getName() << "` added, order now contains " << lines.size() << endl;
        cout << "\033[0m";
    }
};