#include "automaticemail.h"

#include <set>
#include <string>
#include <CkEmail.h>


using namespace std;

AutomaticEmail::AutomaticEmail()
{ 
}

void AutomaticEmail::setStudentInfo(Student st, CCEvent e)
{
    //CkEmail email;
    string email_Subject = "Cultural Credit Event Alert!!!";
    email.put_Body("Hello, " + st.getName() + "!\n" + e.getTitle() +" is a cultural-credit event coming up that you don't want to miss!\n" 
	+"Date/Time : " + e.getDateTime() + "\n" 
	+"Location : " + e.getLocation() + "\n"
	+ "Description : " + e.getDescription() + "\n"
	+"See you there! --Heyley:)");
    email.put_From("Chilkat Support <hgatewood@stetson.edu>");
    email.AddTo(st.getName(), st.getEmail());		
  
}

void AutomaticEmail::sendEmail()//possible parameters: (Student st, CCEvent event)
{
    //Email template
}


AutomaticEmail::~AutomaticEmail()
{ }

