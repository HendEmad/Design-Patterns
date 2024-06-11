#include "ICommand.h"
#include "C:\Users\Data-DCS\Design-Patterns\Behavioral\Command\core\Product.h"

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