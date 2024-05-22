#ifndef GRADE_2_REPORT_H
#define GRADE_2_REPORT_H

#include "C:\Users\Data-DCS\Design-Patterns\Structural\Bridge\Grades\GradeReport.h"
#include <string>
#include <memory>
using namespace std;

class grade2Report : public GradeReport {
    public:
    grade2Report(shared_ptr<ReportBridge> report): GradeReport(report) {}
    string showReport() const override {
        return report -> showG2Report();
    }
};

#endif // GRADE_2_REPORT_H