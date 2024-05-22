#include "C:\Users\Data-DCS\Design-Patterns\Structural\Bridge\Grades\grade1Report.h"
#include "C:\Users\Data-DCS\Design-Patterns\Structural\Bridge\Reports\include\HTMLReport.h"
// #include "C:\Users\Data-DCS\Design-Patterns\Structural\Bridge\Reports\include\TXTReport.h"
// #include "C:\Users\Data-DCS\Design-Patterns\Structural\Bridge\Reports\include\XMLReport.h"
#include <iostream>
#include <memory>
using namespace std;

int main() {
    auto htmlReport = make_shared<HTMLReport>(); //HTMLReport object
    auto reportTool = make_shared<grade1Report>(htmlReport); //grade1Report object composed with htmlReport object 

    cout << reportTool -> showReport() << endl; 
}