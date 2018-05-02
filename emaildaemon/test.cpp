#include <iostream>
#include "../student.h"
#include "../ccevent.h"
#include "../database.h"


using namespace std;

int main(int argc, const char **argv)
{

	CCEvent e;
	cout << "Title: " << e.getTitle() << endl;
	cout << "Location: " << e.getLocation() << endl;
	cout << "Date/Time: " << e.getDateTime() << endl;
	cout << "Description: " << e.getDescription() << endl;
	if(argc != 2) {
                cout << "Usage: " << argv[0] << " databasename.db" << endl;
                return -1;
        }
	database db(argv[1]);
	vector<Student> v;
	v = db.searchStudentByName("kyle");
	cout << v[0].getName() << endl;
	return 0;
}
