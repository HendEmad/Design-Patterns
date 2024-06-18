#include "ICommand.h"
#include "Behavioral/Command/core/Product.h"

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