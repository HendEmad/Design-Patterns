#ifndef ORDERLINE_H
#define ORDERLINE_H

class OrderLine {
public:
    OrderLine(int productId, double quantity, double unitPrice):
    productId(productId), Quantity(quantity), UnitPrice(unitPrice) {}

    int productId;
    double Quantity;
    double UnitPrice;
};

#endif //ORDERLINE_H