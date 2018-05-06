#include <iostream>
#include <fstream>
#include "../student.h"
#include "../ccevent.h"
#include "makeemail.h"
#include "../database.h"
#include <sqlite3.h>

using namespace std;
#include <string>
#include <vector>

int main(int argc, const char** argv){
	if(argc != 2){
		cout << "Usage: " << argv[0] << " databasename.db" << endl;
		return -1;
	}

	database db(argv[1]);
	MakeEmail me;	
	//Student st;
	//CCEvent e;
	vector<Student> stvec = db.searchStudentById(1);
	vector<CCEvent> ccvec = db.searchEventById(13);
	
	//st = stvec[0];
	//e = ccvec[0];

	me.setEmailString(stvec, ccvec);

	return 0;
}
