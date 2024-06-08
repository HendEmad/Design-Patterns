#include "ICommand.h"
#include "C:\Users\Data-DCS\Design-Patterns\Behavioral\Command\core\Order.h"
#include "C:\Users\Data-DCS\Design-Patterns\Behavioral\Command\core\Product.h"

class addProduct : public ICommand{
    Order& _order;
    Product& _product;
    double _quantity;
public:
    addProduct(Order& order,Product& product, double quantity) :
    _order(order), _product(product), _quantity(quantity) {}


    void Execute() override{
        _order.addProduct(_product, _quantity);
    }
};