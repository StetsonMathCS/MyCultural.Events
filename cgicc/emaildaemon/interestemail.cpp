#include "interestemail.h"

#include <set>
#include <string>

using namespace std;

InterestEmail::InterestEmail()
{ }

void InterestEmail::setStudentInfo()
{
    
}

set<string> InterestEmail::findInterestCC()
{
    /*
     Go through the system and find all the CC events that
     contain keywords that match the student's interests.
     
     Add those CC event to a list called selectedCCEvents
     */
    
    set<string> selectedCCEvents;
    return selectedCCEvents;
}

void InterestEmail::sendEmail()//possible parameters: (Student st, CCEvent event)
{
    //Email template
}

InterestEmail::~InterestEmail()
{ }

