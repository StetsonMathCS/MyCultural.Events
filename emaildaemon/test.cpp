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

/*
void find_and_replace(string& file_contents,const string& f, const string& r) {
	string pos = file_contents.find(f);
	while (pos != string::npos) {
		file_contents.replace(pos, f.length(), r);
		pos = file_contents.find(f, pos);
	}

}

string getfile(ifstream& is) {
  string contents;
  for (char ch; is.get(ch); contents.push_back(ch)) {}
  return contents;
}
*/

void setStudentNameInEmail(ifstream& in, ofstream& out, Student student){
	string line;
        string wordToReplace = "!!FirstName!!";
        size_t len = wordToReplace.length();
                        while (getline(in, line)){
                                while (true){
                                        size_t pos = line.find(wordToReplace);
                                        if (pos != string::npos){
                                                line.replace(pos, len, "Heyley");
						//break;
                                        	out << line << endl;
					}else{
						out << line << endl;
                                                break;
                                        }

                                        //out << line << endl;
                        	}
				
				//out << line << endl;
			}	
			//out << line << endl;
}


int main(int argc, const char** argv){
	if (argc !=2)
	{
		cout << "usage: " << argv[0] << " databasename.db" << endl;
		return -1;
	}
	database db(argv[1]);
	//db.insertStudentData("Heyley", "hgatewood@stetson.edu", 2020, "Fall", 10, "art");
	//db.insertStudentData("John", "johndoe@stetson.edu", 2019, "Fall", 8, "music, film");

	ifstream filein("textfile.txt");
	ofstream fileout("temp.txt");
	if(!filein || !fileout) //if both files are not available
	{
        	cout << "Error opening files!" << endl;
        	return 1;
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
                        for(int j = 0; j < db.rowsInEventTable(); j++){
				vector<CCEvent> ccvec = db.searchEventById(1);
        	                e = ccvec[0];
                	        cout << "Date/Time for this event is: " << e.getDateTime() << endl;
			//Chooses Cultural Credit for that student
                        }
			//Setting the Student's First name in the email template
			setStudentNameInEmail(filein, fileout, st);
/*			string line;
    			string wordToReplace = "!!FirstName!!";
    			size_t len = wordToReplace.length();
    			while (getline(filein, line)){
        			while (true){
            				size_t pos = line.find(wordToReplace);
            				if (pos != string::npos)
                				line.replace(pos, len, "GOODBYE");
            				else 
                				break;
        				}	

        				fileout << line << '\n';
    			}*/
			
		//}
		//}
	}
	
	//Settin the Event's Time in the email template



	//find_and_replace(contents, "HELLO", "GOODBYE");
	//string contents = getfile(file);
	//find_and_replace(contents, "HELLO", "GOODBYE");
	//fileout << contents;

/*
	vector<CCEvent> v = db.searchEventById(1);
	CCEvent e = v[0];


	//CCEvent e;
	cout << "Title: " << e.getTitle() << endl;
	cout << "Location: " << e.getLocation() << endl;
	cout << "Date/Time: " << e.getDateTime() << endl;
	cout << "Description: " << e.getDescription() << endl;
<<<<<<< HEAD
*/
/*
	//database db;
	for(int i = 0; i < 20; i++){
	
		cout << "CCEvent: " << db.getName(i) << endl;
	}
*/	
/*	if(argc != 2) {
                cout << "Usage: " << argv[0] << " databasename.db" << endl;
                return -1;
        }
	database db(argv[1]);
	vector<Student> v;
	v = db.searchStudentByName("kyle");
	cout << v[0].getName() << endl;*/
	return 0;
}
