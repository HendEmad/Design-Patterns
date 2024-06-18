#ifndef ADDSTOCK_H
#define ADDSTOCK_H

#include"Behavioral/Command/macros/core/commands/ICommand.h"
#include"Behavioral/Command/macros/core/commands/addProduct.h"

class addStock : public ICommand{
    Product& _product;
    double _quantity;

public:
    addStock(Product& product, double quantity):
    _product(product), _quantity(quantity) {}

    void Execute() {
        _product.addStock(_quantity);
    }

};

#endif // ADDSTOCK_H