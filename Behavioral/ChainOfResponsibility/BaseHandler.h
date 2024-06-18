#include <memory>
#include "Behavioral/ChainOfResponsibility/JobApplication.h"
using namespace std;

#ifndef BASE_HANDLER_H
#define BASE_HANDLER_H

class BaseHandler {
    protected:
    shared_ptr<BaseHandler> nextHandler;

    public:
    void setNext(shared_ptr<BaseHandler> handler) {
        nextHandler = handler;
    }

    virtual void HandleRequest(shared_ptr<JobApplication> request) = 0;

    virtual ~BaseHandler() = default;
};

#endif // BASE_HANDLER_H