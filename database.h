#ifndef DATABASE_H
#define DATABASE_H
#include "sqlite3.h"
#include <vector>
#include <string>

class Student;
class ccevent;
class database 
{
	public:
		database();
		~database();
		//database(const char*);
		int createTables();	
		int getID(std::string);
		std::string getName(int);
		
		void toString();
//		void searchEventById(int);
		void searchByEventName(std::string);
		void searchByEventLoc(std::string);	
		void searchByEventDesc(std::string);
		
//		void searchByName(std::string);
//		void searchByDesc(std::string);
		
		void searchStudentByName(std::string);
		std::vector<Student> searchStudentByEmail(std::string);
		void searchStudentByPreferences(std::string);
		void searchStudentByCurrentcc(int);
		void searchStudentByGradsemester(std::string);
		void searchStudentByGradyear(int);
		
//		void searchByLoc(std::string);
//		void searchById(int);
		
		static int callback(void*, int, char**, char**);
		int getCredits(int);
		std::string getEmail(int);
		std::string getPreferences(int);
		void insertStudentData(std::string, std::string, int, std::string, int, int, std::string);
		void insertEventData(std::string, std::string, std::string, std::string);
		
		int rowsInEventTable();
		
		int rowsInStudentTable();
		bool checkEmptyStudentTable();

		bool checkEmptyEventTable();

	private:
		sqlite3* db;
		char* errmsg;


};

#endif
