#include <iostream>

#include "../ccevent.h"
#include "../database.h"


using namespace std;

int main(){

	CCEvent e;
	cout << "Title: " << e.getTitle() << endl;
	cout << "Location: " << e.getLocation() << endl;
	cout << "Date/Time: " << e.getDateTime() << endl;
	cout << "Description: " << e.getDescription() << endl;

	database db;

	return 0;
}
