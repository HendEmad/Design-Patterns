#ifndef ADDPRODUCT_H
#define ADDPRODUCT_H

#include "ICommand.h"
#include "Behavioral/Command/macros/core/Order.h"
#include "Behavioral/Command/macros/core/Product.h"

class addProduct : public ICommand{
    Product& _product;
    double _quantity;
public:
    Order& order;
    Order& getOrder() {
        return order;
    }
    addProduct(Order& order,Product& product, double quantity) :
    order(order), _product(product), _quantity(quantity) {}


    void Execute() override{
        order.addProduct(_product, _quantity);
    }
};

#endif // ADDPRODUCT_H