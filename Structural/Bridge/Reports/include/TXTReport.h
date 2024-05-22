#ifndef TXT_REPORT_H
#define TXT_REPORT_H

#include "C:\Users\Data-DCS\Design-Patterns\Structural\Bridge\Reports\include\ReportBridge.h"

class TXTReport : public ReportBridge {
public:
    std::string showG1Report() const override;
    std::string showG2Report() const override;
    std::string showG3Report() const override;
};

#endif // TXT_REPORT_H