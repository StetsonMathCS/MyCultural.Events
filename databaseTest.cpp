#include <iostream>
#include "database.h"
using namespace std;

int main()
{
        database db;
        db.insertStudentData(1, "kyle", "email@email.com", 15, "Fall", 2018,"Music");
        db.insertEventData("Lunch", "12:00", "the commons", "A nice meal");
        db.insertEventData("Dinner", "6:00", "the commons", "A bigger meal");
        cout << "Searching for lunch: " << endl;
        db.searchByName("Lunch");
        cout << "Searching for Dinner: " << endl;
        db.searchByName("Dinner");
        cout << "Searching for the commons: " << endl;
        db.searchByLoc("the commons");
	db.searchStudentByName("kyle");
	db.searchStudentByGradyear(2018);
        return 0;
}

