#include <string>
#include <sstream>
using namespace std;

#ifndef JOB_APPLICATION_H
#define JOB_APPLICATION_H

class JobApplication {
    public:
    string ApplicantName;
    string JobTitle;
    string JobCode;
    stringstream comments;

    string getComments() const {
        return comments.str();
    }

    void setComments(const string& newComments) { 
        comments.str("");
        comments << newComments;
    }

    string showComments() const {
        return comments.str();
    }
};

#endif // JOB_APPLICATION_H