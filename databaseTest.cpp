#include <iostream>
#include <vector>
#include "student.h"
#include "database.h"
using namespace std;

int main()
{
        database db;
        db.insertStudentData("kyle", "email@email.com", 1, "Fall", 2018, 15, "Music");
       // db.insertEventData("Lunch", "12:00", "the commons", "A nice meal");
        //db.insertEventData("Dinner", "6:00", "the commons", "A bigger meal");
/*	vector<Student> v = db.searchStudentByEmail("email@email.com");
	cout << v[0].getName() + " " + v[0].getEmail() + " ";
	cout << v[0].getId() << endl;
	cout << v[0].getCurrentCC() << endl;
*/
	cout << " search by ID : " << endl;
	vector<Student> v = db.searchStudentById(1);
	cout << v[0].getName() + " " + v[0].getEmail() + " ";
	cout << v[0].getId() << endl;
	cout << v[0].getCurrentCC() << endl;

/*	cout << " search by ID : " << endl;
	vector<CCEvent> v = db.searchEventById(1);
	cout << v[0].getTitle() + " " + v[0].getDateTime() + " ";
	cout << v[0].getId() << endl;
	cout << v[0].getLopcation() + " " + v[0].getDescription << endl;
*/

		
        return 0;
	
}

