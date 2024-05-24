#include "C:\Users\Data-DCS\Design-Patterns\Behavioral\ChainOfResponsibility\BaseHandler.h"
#include "C:\Users\Data-DCS\Design-Patterns\Behavioral\ChainOfResponsibility\JobApplication.h"
#include <memory>

#ifndef HR_HANDLER_H
#define HR_HANDLER_H

class HRHandler : public BaseHandler {
    public:
    void toNext_Scenario3(shared_ptr <JobApplication> request) {
        if(nextHandler != nullptr) {
            nextHandler -> HandleRequest(request);
        }
        else {
            request -> comments << "End by HR...\n";
        }
    }

    void HandleRequest(shared_ptr<JobApplication> request) override{

        #pragma region Scenario 1
        // request -> comments << "HR evaluation comment.\n";

        // if(nextHandler != nullptr) {
        //     nextHandler -> HandleRequest(request);
        // }
        // else {
        //     request -> comments << "End by HR Handler\n";
        // }
        #pragma endregion

        #pragma region Scenario 2
        // check if the handler is able to process the request or not
        // if (request -> JobCode == "#1546") {
        //     request -> comments << "HR Comment...\n";
        // }
        // else{  // send request to the next handler
        //     if (nextHandler != nullptr) {
        //     nextHandler -> HandleRequest(request);
        //     }
        //     else {
        //         request -> comments << "End by HR Handler...\n";
        //     }
        // }
        #pragma endregion
        
        if (request -> JobCode == "#1546") {
            request -> comments << "HR Comment...\n";
            toNext_Scenario3(request);
        }
        else {
            toNext_Scenario3(request);
        }
    }
    
};

#endif // HR_HANDLER_H