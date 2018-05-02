#include <iostream>
#include <vector>
#include "student.h"
#include "ccevent.h"
#include "database.h"
using namespace std;

int main(int argc, const char **argv)
{
<<<<<<< HEAD
        database db;
       db.insertStudentData("kyle", "email@email.com", 15, "Fall", 2018, "Music");
=======
	if(argc != 2) {
		cout << "Usage: " << argv[0] << " databasename.db" << endl;
		return -1;
	}
        database db(argv[1]);
        db.insertStudentData("kyle", "email@email.com", 15, "Fall", 2018, "Music");
>>>>>>> 38d7140ea6eda2a0ce3fe5e44ef9223dd5080768
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

