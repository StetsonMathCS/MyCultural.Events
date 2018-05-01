#include <iostream>
#include <vector>
#include "student.h"
#include "database.h"
using namespace std;

int main()
{
        database db;
        db.insertStudentData("kyle", "email@email.com", 1, "Fall", 2018, 15, "Music");
        //db.insertEventData("Lunch", "12:00", "the commons", "A nice meal");
        //db.insertEventData("Dinner", "6:00", "the commons", "A bigger meal");
	vector<Student> v = db.searchStudentByEmail("email@email.com");
	cout << v[0].getName() + " " + v[0].getEmail() + " ";
	cout << v[0].getId() << endl;
	cout << v[0].getCurrentCC() << endl;
        return 0;
}

