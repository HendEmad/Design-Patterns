#ifndef GRADE_1_REPORT_H
#define GRADE_1_REPORT_H

#include "Bridge/Grades/GradeReport.h"
#include <string>
#include <memory>
using namespace std;

class grade1Report : public GradeReport {
    public:
    grade1Report(shared_ptr<ReportBridge> report): GradeReport(report) {}
    string showReport() const override {
        return report -> showG1Report();
    }
};

#endif // GRADE_1_REPORT_H