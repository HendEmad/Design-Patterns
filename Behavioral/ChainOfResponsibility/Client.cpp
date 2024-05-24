#include <iostream>
#include <memory>
#include "C:\Users\Data-DCS\Design-Patterns\Behavioral\ChainOfResponsibility\BaseHandler.h"
#include "C:\Users\Data-DCS\Design-Patterns\Behavioral\ChainOfResponsibility\HRHandler.h"
#include "C:\Users\Data-DCS\Design-Patterns\Behavioral\ChainOfResponsibility\JobApplication.h"
#include "C:\Users\Data-DCS\Design-Patterns\Behavioral\ChainOfResponsibility\TechHandler.h"
using namespace std;

int main() {
    shared_ptr<JobApplication> jobApp = make_shared<JobApplication>();
    jobApp -> ApplicantName = "Hend";
    jobApp -> JobTitle = "SDE";
    jobApp -> JobCode = "#122524";

    shared_ptr<HRHandler> hr = make_shared<HRHandler>();
    shared_ptr<TechHandler> tech = make_shared<TechHandler>();

    hr -> setNext(tech);  // create the chain

    hr -> HandleRequest(jobApp);  // start the chain
    

    cout << jobApp -> showComments();

}