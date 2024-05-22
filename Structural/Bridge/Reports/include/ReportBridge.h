#ifndef REPORT_BRIDGE_H
#define REPORT_BRIDGE_H

#include <string>
class ReportBridge {
public:
    virtual ~ReportBridge() = default;
    virtual std::string showG1Report() const = 0;
    virtual std::string showG2Report() const = 0;
    virtual std::string showG3Report() const = 0;
};

#endif // REPORT_BRIDGE_H