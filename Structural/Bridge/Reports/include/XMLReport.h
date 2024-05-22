#ifndef XML_REPORT_H
#define XML_REPORT_H

#include "C:\Users\Data-DCS\Design-Patterns\Structural\Bridge\Reports\include\ReportBridge.h"

class XMLReport : public ReportBridge {
public:
    std::string showG1Report() const override;
    std::string showG2Report() const override;
    std::string showG3Report() const override;
};

#endif // XML_REPORT_H