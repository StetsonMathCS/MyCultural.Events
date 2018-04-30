#ifndef DATABASE_H
#define DATABASE_H
#include "sqlite3.h"
#include <string>

class database 
{
	public:
		database();
		~database();
		//database(const char*);
		int createTables();	
		int getID(std::string);
		std::string getName(int);
<<<<<<< HEAD
		void toString();
		void searchEventById(int);
		void searchEventByName(std::string);
		void searchEventByLoc(std::string);	
		void searchEventByDesc(std::string);
=======
		void searchByName(std::string);
		void searchByDesc(std::string);
>>>>>>> 90f39056a7ac4855d0d8dd6b6179d09ff81128a8
		void searchStudentByName(std::string);
		void searchStudentByEmail(std::string);
		void searchStudentByPreferences(std::string);
		void searchStudentByCurrentcc(int);
		void searchStudentByGradsemester(std::string);
		void searchStudentByGradyear(int);
<<<<<<< HEAD
=======
		void searchByLoc(std::string);
		void searchById(int);
>>>>>>> 90f39056a7ac4855d0d8dd6b6179d09ff81128a8
		static int callback(void*, int, char**, char**);
		int getCredits(int);
		std::string getEmail(int);
		std::string getPreferences(int);
		void insertStudentData(int, std::string, std::string, int, std::string, int, std::string);
		void insertEventData(std::string, std::string, std::string, std::string);
<<<<<<< HEAD
		int rowsInEventTable();
=======
>>>>>>> 90f39056a7ac4855d0d8dd6b6179d09ff81128a8
		int rowsInStudentTable();
		bool checkEmptyStudentTable();

	private:
		sqlite3* db;
		char* errmsg;


};

#endif
