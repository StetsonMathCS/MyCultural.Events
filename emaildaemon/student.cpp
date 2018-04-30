#include <iostream>
#include "automaticemail.h"
#include "interestemail.h"
#include "student.h"
#include <ctime>

#include <list>
#include <set>
using namespace std;

Student::Student() : interests()
{
    name = "noname";
    email = "student@stetson.edu";
    identity = -1;
    gradSem = "Fall";
    gradYear = -1;
    currentCC = -1;
    
    sendAutomaticEmail = false;
    sendInterestEmail = false;
    
}


Student::Student(string _name, string _email, int _id, string _gradSem, int _gradYear, int _cc, string_interests)
{
    name = _name;
    email = _email;
    identity = _id;
    gradSem = _gradSem;
    gradYear = _gradYear;
    currentCC = _cc;
    interests = _interests;
    
    sendAutomaticEmail = false;
    sendInterestEmail = false;
}


void Student::setName(string nm)
{
    name = nm;
}

void Student::setEmail(string e)
{
    email = e;
}

void Student::setId(int id)
{
    identity = id;
}

void Student::setGradSem(string m)
{
    /*
    if(m.compare("Spring") == 0){
        gradSem = 2;
    }else if(m.compare("Fall") == 0){ //graduating in the Fall (0)
        gradSem = 1;
    }*/
    gradSem = m;
}

void Student::setGradYear(int y)
{
    gradYear = y;
}

void Student::setCurrentCC(int cc)
{
    currentCC = cc;
}

string Student::getName()
{
    return name;
}

string Student::getEmail()
{
    return email;
}

int Student::getId()
{
    return identity;
}

string Student::getGradSem()
{
    return gradSem;
}
int Student::getGradYear()
{
    return gradYear;
}
int Student::getCurrentCC()
{
    return currentCC;
}
set<string> Student::getInterests()
{
    return interests;
}

int Student::getPriorityLevel()
{
    return priorityLevel;
}

int Student::getStudentYrStatus()
{
    int gradSemNum;
    if(gradSem.compare("Spring") == 0){
	gradSemNum = 2; 
    }else if(gradSem.compare("Fall") == 0){ //graduating in the Fall (0
	gradSemNum = 1;    
    }

    time_t now = time(0); // current date/time based on current system
    tm *ltm = localtime(&now);
    int currentYear = 1900 + ltm->tm_year;
    int currentMonth = 1 + ltm->tm_mon;

    int currentSem;
    if(currentMonth >= 1 && currentMonth <= 5){
	currentSem = 2;
    }else if(currentMonth >= 8 && currentMonth <= 12){
	currentSem = 1;
    }

    int yearsLeft = gradYear - currentYear;
    int semLeft = yearsLeft * 2;

    if(gradSemNum != currentSem){
        if((currentSem - gradSemNum) > 0){ //currentSem is Spring(2) and gradSem is Fall(1)
            semLeft--;
        }else if ((currentSem - gradSemNum) < 0){ //currentSem is Fall(1) and gradSem is Spring(2)
            semLeft++;
        }
    }
    
    int status = 0;
    if(semLeft == 7 || semLeft == 8){ //Freshman status
        status = 1;
        
    }else if(semLeft == 5 || semLeft == 6){ //Sophomore Satus
        status = 2;
        
    }else if(semLeft == 3 || semLeft == 4){ //Junior Status
        status = 3;
        
    }else if(semLeft <= 2){ //Senior Status
        status = 4;
    }

    return status;
}

void Student::setPriorityLevel(){
    int yr = getStudentYrStatus();
    bool isHighPriority = false;
    bool isMedPriority = false;
    bool isLowPriority = false;
    if(yr == 1){
        if(currentCC < 1){
            isHighPriority = true;
        }else if(currentCC >= 1 && currentCC <= 3){
            isMedPriority = true;
        }else {
            isLowPriority = true;
        }
    }
    else if(yr == 2){
        if(currentCC < 7){
            isHighPriority = true;
        }else if(currentCC >= 7 && currentCC <= 9){
            isMedPriority = true;
        }else if (currentCC > 9){
            isLowPriority = true;
        }
    }
    else if(yr == 3){
        if(currentCC < 13){
            isHighPriority = true;
        }else if(currentCC >= 13 && currentCC <= 15){
            isMedPriority = true;
        }else if (currentCC > 15){
            isLowPriority = true;
        }
    }
    else if(yr == 4){
        if(currentCC < 24){
            isHighPriority = true;
        }
    }
    if(isHighPriority){
        priorityLevel = 1;
        sendAutomaticEmail = true;
        sendInterestEmail = false;
    } else if(isMedPriority){
        priorityLevel = 0;
        sendInterestEmail = true;
        sendAutomaticEmail = false;
    } else if(isLowPriority){
        priorityLevel = -1;
	sendInterestEmail = false;
        sendAutomaticEmail = false;
    }
}

void Student::sendEmail(){
    if(sendAutomaticEmail){
        //new AutomaticEmail(); //Send email about all CC events regardless of interests
        
    }
    if(sendInterestEmail){
        //new InterestEmail(); //Send email about CC Events tailored to student's interests
        
    }
}



