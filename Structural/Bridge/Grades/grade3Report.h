#ifndef GRADE_3_REPORT_H
#define GRADE_3_REPORT_H

#include "C:\Users\Data-DCS\Design-Patterns\Structural\Bridge\Grades\GradeReport.h"
#include <string>
#include <memory>
using namespace std;

class grade3Report : public GradeReport {
    public:
    grade3Report(shared_ptr<ReportBridge> report): GradeReport(report) {}
    string showReport() const override {
        return report -> showG3Report();
    }
};

#endif // GRADE_3_REPORT_H