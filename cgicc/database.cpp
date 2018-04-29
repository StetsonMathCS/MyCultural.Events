#include "database.h"
#include "sqlite3.h"
#include <iostream>
#include <cstring>
using namespace std;

database::database()
{
	int retval = 0;
	retval = sqlite3_open("students.db", &db);
	if (retval != SQLITE_OK)
	{
		cout << "Cannot open students.db: " << sqlite3_errcode(db) << endl;
	}

	retval = createTable();
	retval = insertStudent(1, "Kyle", "Fakeemail@gmail.com", 15, "Food");

}

/*database::database(const char* dbName)
{
	int retval = 0;
	retval = sqlite3_open(dbName + ".db", &db);
	if (retval != SQLITE_OK)
	{
		cout << "Cannot open " << dbName << ".db: " << sqlite3_errcode(db) << endl;
	}
	retval = createTable();

}
*/
database::~database()
{
	sqlite3_close(db);
}

int database::createTable()
{
	int retval = sqlite3_exec(db, "CREATE TABLE mytable (id int, name text, email text, credits int, prefs text);", NULL, NULL, &errmsg);
	if(retval != SQLITE_OK)
	{
		cout << "Error in previous command: " << errmsg << endl;
		sqlite3_free(errmsg);
	}
	return retval;
}

int database::insertStudent(int ID, string name, string email, int credits, string prefs)
{
	int retval = sqlite3_exec(db, "INSERT INTO mytable VALUES (1 , \"name\", \"Fakeemail@gmail.com\", 16, \"Food\");", NULL, NULL, &errmsg);
        if(retval != SQLITE_OK)
        {
                cout << "Error in previous command: " << errmsg << endl;
                sqlite3_free(errmsg);
        }
        return retval;
	
}

void database::toString()
{
	sqlite3_stmt *s;
	const char *sql = "SELECT * FROM mytable ORDER BY id";
	int retval = sqlite3_prepare(db, sql, strlen(sql), &s, NULL);
	if(retval != SQLITE_OK)
	{
		cout << "Error in preparing statement." << endl;
	}
	while(sqlite3_step(s) == SQLITE_ROW)
	{
		int id = sqlite3_column_int(s, 0);
		const unsigned char *name = sqlite3_column_text(s, 1);
		const unsigned char *email = sqlite3_column_text(s, 2);
		int creds = sqlite3_column_double(s, 3);
		const unsigned char *prefs = sqlite3_column_text(s, 4);
		cout << "ID = " << id << ", name = " << name << ", email = " << email << ", credits = " << creds << ", prefs = " << prefs << endl;
	}

}
int database::getID(string email)
{
	int ID = 0;
	return ID;
}

int database::getCredits(int ID)
{
	return 0;
}

string database::getName(int ID)
{
	return "";
}

string database::getEmail(int ID)
{
	return "";
}

string database::getPreferences(int ID)
{
	return "";
}


