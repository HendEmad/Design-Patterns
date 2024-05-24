#include "C:\Users\Data-DCS\Design-Patterns\Behavioral\ChainOfResponsibility\BaseHandler.h"
#include "C:\Users\Data-DCS\Design-Patterns\Behavioral\ChainOfResponsibility\JobApplication.h"
#include <sstream>


#ifndef TECH_HANDLER_H
#define TECH_HANDLER_H

class TechHandler : public BaseHandler {
    public:
    void toNext_Scenario3(shared_ptr <JobApplication> request) {
        if (nextHandler != nullptr) {
            nextHandler -> HandleRequest(request);
        }
        else {
            request -> comments << "End by tech...\n";
        }
    }

    void HandleRequest(shared_ptr<JobApplication> request) override{

        #pragma region Scenario 1
        // request -> comments << "Tech evaluation comment.\n";

        // if(nextHandler != nullptr) {
        //     nextHandler -> HandleRequest(request);
        // }
        // else{
        //     request -> comments << "End by technical handler\n";
        // }
        #pragma endregion

        #pragma region Scenario 2
        // if (request -> JobCode == "#122524") {
        //     request -> comments << "Tech Comment...\n";
        // }
        // else{
        //     if(nextHandler != nullptr) {
        //         nextHandler -> HandleRequest(request);
        //     }
        //     else {
        //         request -> comments << "End by tech handler...\n";
        //     }
        // }
        #pragma endregion
    
        if(request -> JobCode == "#122524") {
            request -> comments << "Tech comment...\n";
            toNext_Scenario3(request);
        }
        else {
            toNext_Scenario3(request);
        }
    }
};

#endif // TECH_HANDLER_H