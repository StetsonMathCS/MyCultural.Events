#include <iostream>
#include <fstream>
#include <sstream>
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
	
	for(int i = 1; i < 2; i++){
		vector<Student> stvec = db.searchStudentById(i);
		vector<CCEvent> ccvec = db.searchEventById(13);
		me.setEmailString(stvec, ccvec);
		cout << me.getEmailString() << endl;
	}


	return 0;
}
