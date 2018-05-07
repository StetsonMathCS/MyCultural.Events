#include <iostream>
#include <fstream>
#include "../student.h"
#include "../ccevent.h"
#include "../database.h"

#include "sqlite3.h"

using namespace std;

/*
 * 1.) get Student from database
 * 2.) determine Student's priority level
 * 	3.) if HIGH, choose cultural credit that is the closest to the current date
 * 	4.) if MED, search through database for CCEvents matching students interests
 * 		5.) create vector of CCEvents object for each of those interests
 * 		6.) determine which event is the closest to the current date
 * 	7.) send CCEvents to Michael to formulate an email template
 * 	8.) get template from Michael
 * 	9.) send to Nick and Isabel
 */

void setStudentNameInEmail(ifstream& in, ofstream& out, Student student){
	string line;
        string wordToReplace = "!!FirstName!!";
        size_t len = wordToReplace.length();
        while (getline(in, line)){
        	while (true){
                	size_t pos = line.find(wordToReplace);
                        if (pos != string::npos){
				if(student.getName() == ""){
					line.replace(pos, len, " No Name");
				}else{
					line.replace(pos, len, " " + student.getName());
				}
			}else{
				out << line << endl;
                                break;
                        }
               	}
				
	}	
}

void setEventDescriptionInEmail(ifstream& in, ofstream& out, CCEvent e){
        string line;
        string wordToReplace = "!!Description!!";
        size_t len = wordToReplace.length();
        while (getline(in, line)){
                while (true){
                        size_t pos = line.find(wordToReplace);
                        if (pos != string::npos){ 
				if(e.getDescription() == ""){
					line.replace(pos, len, " No Description");
				}else{
					line.replace(pos, len, " " + e.getDescription());
				}
                        }else{  
                                out << line << endl;
                                break;
                        }
                }
         
        }
}
	
	
void setEventTimeInEmail(ifstream& in, ofstream& out, CCEvent e){
        string line;
	string wordToReplace = "!!Time!!";
        size_t len = wordToReplace.length();
        while (getline(in, line)){
                while (true){
                        size_t pos = line.find(wordToReplace);
                        if (pos != string::npos){
                                line.replace(pos, len, " " + e.getDateTime());
                        }else{  
                                out << line << endl;
                                break;
                        }
                }
         
        }


}

void setEventLocationInEmail(ifstream& in, ofstream& out, CCEvent e){
        string line;
	string wordToReplace = "!!Location!!";
        size_t len = wordToReplace.length();
        while (getline(in, line)){
                while (true){
                        size_t pos = line.find(wordToReplace);
                        if (pos != string::npos){
                                line.replace(pos, len, " " + e.getLocation());
                        }else{
                                out << line << endl;
                                break;
                        }
                }

        }


}

/*
void setEventPreferencesInEmail(ifstream& in, ofstream& out, CCEvent e){
        wordToReplace = "!!Preferences!!";
        len = wordToReplace.length();
        while (getline(in, line)){
                while (true){
                        size_t pos = line.find(wordToReplace);
                        if (pos != string::npos){
                                line.replace(pos, len, e.getLocation());
                        }else{
                                out << line << endl;
                                break;
                        }
                }

        }


}
*/


int main(int argc, const char** argv){
	if (argc !=2)
	{
		cout << "usage: " << argv[0] << " databasename.db" << endl;
		return -1;
	}
	database db(argv[1]);

	ifstream filein("email2.html"); //email template html
	ofstream fileout("filledStName.html");
	if(!filein || !fileout)
	{
        	cout << "ERROR OPENING FILES: email2.html or filledStName.html does not exist in this directory" << endl;
        	return -1;
    	}


	int numStudentRows = db.rowsInStudentTable();
        cout << numStudentRows << endl;
	Student st;
	CCEvent e;
        for(int i = 0; i < 1; i++){
                vector<Student> stvec = db.searchStudentById(i);
                st = stvec[0];
                st.setPriorityLevel();
                int priorityLevel = st.getPriorityLevel();
                cout << "Student's name is: " << st.getName() << endl;
		cout << "Student's priority level has been set to: " << priorityLevel << endl;
                //if(priorityLevel > 0){
                       // for(int j = 0; j < db.rowsInEventTable(); j++){
				vector<CCEvent> ccvec = db.searchEventById(14);
        	                e = ccvec[0];
                	        cout << "Date/Time for this event is: " << e.getDateTime() << endl;
                        //}
                        
			cout << "Event Title: " << e.getTitle() << endl; 
			cout << "Location: " << e.getLocation() << endl;
			cout << "Date/Time: " << e.getDateTime() << endl;
			cout << "Description: " << e.getDescription() << endl;	
			

			setStudentNameInEmail(filein, fileout, st);
			ifstream filein2("filledStName.html");
			ofstream fileout2("filledEventDesc.html");
			if(!filein2 || !fileout2)
      			{
                		cout << "ERROR OPENING FILES: filledStName.html filledEventDesc.html does not exist in this directory" << endl;
                		return -2;
        		}
			cout << "Event Description has been set in the Email." << endl;
			
			setEventDescriptionInEmail(filein2, fileout2, e);
			ifstream filein3("filledEventDesc.html");
			ofstream fileout3("filledEventTime.html");
			if(!filein3 || !fileout3)
        		{
                		cout << "ERROR OPENING FILES: filledEventDesc.html or filledEventTime.html does not exist in this directory" << endl;
                		return -3;
        		}
			cout << "Event Time has been set in the Email." << endl;
			
			setEventTimeInEmail(filein3, fileout3, e);
			ifstream filein4("filledEventTime.html");			 
			ofstream fileout4("finalEmail.html");
			if(!filein4 || !fileout4)
                        {
                                cout << "ERROR OPENING FILES: fiilledEventTime.html or finalEmail.html does not exist in this directory" << endl;
                                return -4;
                        }
			setEventLocationInEmail(filein4, fileout4, e);
			cout<< "Event Location has been set in the Email.\nEmail template complete.\nOpen 'finalEmail.html' to view the code." << endl;
	
	

	}
	return 0;
}
