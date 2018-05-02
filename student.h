#ifndef student_h
#define student_h

#include <string>
#include <set>

#include "database.h"
//#include "emaildaemon/automaticemail.h"
//#include "emaildaemon/interestemail.h"

class Student {
private:
    std::string name;
    std::string email;
    int identity;
    std::string gradSem;
    int gradYear;
    int currentCC;
    std::string interests;
    int priorityLevel;
    
protected:
    bool sendAutomaticEmail;
    bool sendInterestEmail;

public:
    Student();
    Student(std::string nm, std::string email, int id, std::string sem, int year, int cc, std::string interests);
    
    void setName(std::string nm);
    void setEmail(std::string email);
    void setId(int id);
    void setGradSem(std::string m);
    void setGradYear(int y);
    void setCurrentCC(int cc);
    void setPriorityLevel();

    //void setUpEmail(Student st, CCevent e);
    
    std::string getName();
    std::string getEmail();
    int getId();
    std::string getGradSem();
    int getGradYear();
    int getCurrentCC();
    std::string getInterests();
    int getPriorityLevel();
 
    int getStudentYrStatus();
    
    void sendEmail();
    
};


#endif 
