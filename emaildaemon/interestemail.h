#ifndef INTERESTEMAIL_H
#define INTERESTEMAIL_H

#include <string>
#include <set>


class InterestEmail {
private:
    
public:
    InterestEmail();
    void setStudentInfo();
    std::set<std::string> findInterestCC();
    void sendEmail(); //possible parameters: (Student st, CCEvent event)
    ~InterestEmail();
};


#endif
