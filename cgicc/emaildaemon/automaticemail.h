#ifndef AUTOMATICEMAIL_H
#define AUTOMATICEMAIL_H

#include <string>

class AutomaticEmail {
private:

public:
    AutomaticEmail();
    
    void setStudentInfo();
    
    void sendEmail(); //possible parameters: (Student st, CCEvent event)
    
    ~AutomaticEmail();
};


#endif 
