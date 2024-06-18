#ifndef HTML_REPORT_H
#define HTML_REPORT_H


#include "Bridge/Reports/include/ReportBridge.h"
#include <string>

class HTMLReport : public ReportBridge {
public:
    std::string showG1Report() const override;
    std::string showG2Report() const override;
    std::string showG3Report() const override;
};

# endif // HTML_REPORT_H