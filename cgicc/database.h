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
		int createTable();	
		int getID(std::string);
		std::string getName(int);
		void toString();
		int getCredits(int);
		std::string getEmail(int);
		std::string getPreferences(int);
		int insertStudent(int, std::string, std::string, int, std::string);
	private:
		sqlite3* db;
		char* errmsg;


};

#endif
