#ifndef AUTOMATICEMAIL_H
#define AUTOMATICEMAIL_H

#include <string>
//#include "student.h"
//#include "ccevent.h"

class AutomaticEmail {
private:

    Student student;
    CCEvent event;

public:
    AutomaticEmail();
    
    void setInfo(Student st, CCEvent e);
    
    void sendEmail(); //possible parameters: (Student st, CCEvent event)
    
    ~AutomaticEmail();
};


#endif 
