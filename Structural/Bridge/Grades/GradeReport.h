#ifndef GRADE_REPORT_H
#define GRADE_REPORT_H

#include "Bridge/Reports/include/ReportBridge.h"
#include <iostream>
#include <memory>
using namespace std;

class GradeReport {
protected:
    shared_ptr<ReportBridge> report;
public:
    GradeReport(shared_ptr<ReportBridge> report) : report(report) {}

    void setReport(const shared_ptr<ReportBridge>& report) {
        this -> report = report;
    }

    shared_ptr<ReportBridge> getReport() const {
        return report;
    }

    virtual string showReport() const = 0;

    virtual ~GradeReport() = default; 
};


#endif // GRADE_REPORT_H