#include <iostream>
#include <vector>
#include "student.h"
#include "ccevent.h"
#include "database.h"
using namespace std;

int main()
{
        database db;
       db.insertStudentData("kyle", "email@email.com", 15, "Fall", 2018, "Music");
        db.insertEventData("Lunch", "12:00", "the commons", "A nice meal");
        db.insertEventData("Dinner", "6:00", "the commons", "A bigger meal");
	cout << db.rowsInStudentTable() << endl;
	//vector<Student> v = db.searchStudentById(1);
	//cout << v[0].getName() + " " + v[0].getEmail() + " ";
	vector<CCEvent> v = db.searchEventByDesc("A bigger meal");
	cout << v[0].getId() << endl;
	cout << v[0].getTitle() + " " + v[0].getDateTime() + " ";
	cout << v[0].getLocation() + " " + v[0].getDescription() << endl;
    
    return 0;
}

