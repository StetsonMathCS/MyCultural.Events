#include <iostream>
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


int main(){
	database db;
	
	//db.insertStudentData("Heyley", "hgatewood@stetson.edu", 2020, "Fall", 10, "art");
	//db.insertStudentData("John", "johndoe@stetson.edu", 2019, "Fall", 8, "music, film");

	int numStudentRows = db.rowsInStudentTable();
	cout << numStudentRows << endl;

	

	for(int i = 0; i < 2; i++){
		vector<Student> stvec = db.searchStudentById(i);	
		Student st = stvec[0];
		st.setPriorityLevel();
		int priorityLevel = st.getPriorityLevel();
		cout << "Student's priority level has been set to: " << priorityLevel << endl;
		if(priorityLevel > 0){ //HIGH PRIORITY
			//for(int j = 0; j < db.rowsInEventTable(); j++){
			vector<CCEvent> ccvec = db.searchEventById(1);
			CCEvent e = ccvec[0];
			cout << "Date/Time for this event is: " << e.getDateTime() << endl;				
			
			//}
		}

	}
/*
	vector<CCEvent> v = db.searchEventById(1);
	CCEvent e = v[0];


	//CCEvent e;
	cout << "Title: " << e.getTitle() << endl;
	cout << "Location: " << e.getLocation() << endl;
	cout << "Date/Time: " << e.getDateTime() << endl;
	cout << "Description: " << e.getDescription() << endl;
*/
/*
	//database db;
	for(int i = 0; i < 20; i++){
	
		cout << "CCEvent: " << db.getName(i) << endl;
	}
*/	
	return 0;
}
