//#define _GLIBCXX_USE_CXX11_ABI 0/1
#include "database.h"
#include "sqlite3.h"
#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;

database::database()
{
	int retval = 0;
	retval = sqlite3_open("MyCultural.db", &db);
	if (retval != SQLITE_OK)
	{
		cout << "Cannot open MyCultural.db: " << sqlite3_errcode(db) << endl;
	}
	
	retval = createTables();
	
	

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

int database::createTables()
{
	int retval = sqlite3_exec(db,"CREATE TABLE IF NOT EXISTS StudentsTable (" \
			     "'index' INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE," \
			     "name TEXT," \
			     "email TEXT," \
			     "currentCC INTEGER," \
			     "gradSemester TEXT," \
			     "gradYear INTEGER," \
			     "preferences TEXT);", NULL, NULL, &errmsg);
	if(retval != SQLITE_OK)
	{
		cout << "Error in creating students: " << errmsg << endl;
		sqlite3_free(errmsg);
	}
	
	retval = sqlite3_exec(db,"CREATE TABLE IF NOT EXISTS EventsTable (" \
			     "id	INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE," \
			     "name	TEXT NOT NULL," \
			     "date_and_time	TEXT NOT NULL," \
			     "location	TEXT NOT NULL," \
			     "description	TEXT );", NULL, NULL, &errmsg);
	if(retval != SQLITE_OK)
        {
                cout << "Error in creating events: " << errmsg << endl;
                sqlite3_free(errmsg);
        }
	return retval;
}

int database::callback(void *NotUsed, int argc, char **argv, char **szColName)
{
	for (int i = 0; i < argc; i++)
	{
		cout << szColName[i] << ": " << argv[i] << endl;
	}

	cout << "\n";

	return 0;
}


void database::insertStudentData(int index, string name, string email, int currentCC, string gradSemester, int gradYear, string preferences)
{
	
	std::ostringstream ss;
	string query="INSERT INTO StudentsTable(name, email, currentCC, gradSemester, gradYear, preferences) VALUES (";
	query.append("'"+name+"','");
        query.append(email+"',");
	ss << currentCC;
	query.append(ss.str()+ ",'");
        query.append(gradSemester+"',");
	ss.str("");
	ss << gradYear;
	query.append(ss.str() + ",");
	query.append("'" + preferences + "')");

        cout<<query<<endl;
        char *szErrMsg = 0;
        int rc = sqlite3_exec(db,query.c_str() , NULL, NULL, &szErrMsg);
        if (rc != SQLITE_OK)
        {
                cout << "SQL Error chk: " << szErrMsg << endl;
                sqlite3_free(szErrMsg);

        }
}

void database::insertEventData(string name,string time,string loc,string desc)
{
	std::ostringstream ss;
//	ss << id;
	string query="INSERT INTO EventsTable(name, date_and_time, location, description) VALUES (";
//	query.append(ss.str());
	query.append("'"+name+"','");
	query.append(time+"','");
	query.append(loc+"','");
	query.append(desc+"')");


	cout<<query<<endl;
	char *szErrMsg = 0;
	int rc = sqlite3_exec(db,query.c_str() , NULL, NULL, &szErrMsg);
	if (rc != SQLITE_OK)
	{
		cout << "SQL Error chk: " << szErrMsg << endl;
		sqlite3_free(szErrMsg);

	}

}
void database::searchStudentByName(string word )
{
    sqlite3_stmt *stmt;
    const char *pzTest;
    
    string s = "select * from StudentsTable where name=?";
    
    int rc = sqlite3_prepare(db, s.c_str(), -1, &stmt, &pzTest);
    
    if (sqlite3_bind_text(stmt, 1, word.c_str(), -1, NULL) != SQLITE_OK) {
        return;
    }
    
    //Read each row
    while ( (rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        cout << "Ind = " << sqlite3_column_int(stmt, 0) << endl;
        cout << "name = " << sqlite3_column_text(stmt, 1) << endl;
        cout << "email = " << sqlite3_column_text(stmt, 2) << endl;
        cout << "currentCC = " << sqlite3_column_int(stmt, 3) << endl;
        cout << "gradSemester = " << sqlite3_column_text(stmt, 4) << endl;
        cout << "gradYear = " << sqlite3_column_int(stmt, 5) << endl;
        cout << "preferences = " << sqlite3_column_text(stmt, 6) << endl;
        
        cout << endl;
    }
    
    sqlite3_finalize(stmt);
}

	
}

void database::searchStudentByEmail(string word )
{
  sqlite3_stmt *stmt;
    const char *pzTest;
    
    string s = "select * from StudentsTable where email=?";
    
    int rc = sqlite3_prepare(db, s.c_str(), -1, &stmt, &pzTest);
    
    if (sqlite3_bind_text(stmt, 1, word.c_str(), -1, NULL) != SQLITE_OK) {
        return;
    }
    
    //Read each row
    while ( (rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        cout << "Ind = " << sqlite3_column_int(stmt, 0) << endl;
        cout << "name = " << sqlite3_column_text(stmt, 1) << endl;
        cout << "email = " << sqlite3_column_text(stmt, 2) << endl;
        cout << "currentCC = " << sqlite3_column_int(stmt, 3) << endl;
        cout << "gradSemester = " << sqlite3_column_text(stmt, 4) << endl;
        cout << "gradYear = " << sqlite3_column_int(stmt, 5) << endl;
        cout << "preferences = " << sqlite3_column_text(stmt, 6) << endl;
        
        cout << endl;
    }
    
    sqlite3_finalize(stmt);


}

void database::searchStudentByPreferences(string word )
{
  sqlite3_stmt *stmt;
    const char *pzTest;
    
    string s = "select * from StudentsTable where preferences=?";
    
    int rc = sqlite3_prepare(db, s.c_str(), -1, &stmt, &pzTest);
    
    if (sqlite3_bind_text(stmt, 1, word.c_str(), -1, NULL) != SQLITE_OK) {
        return;
    }
    
    //Read each row
    while ( (rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        cout << "Ind = " << sqlite3_column_int(stmt, 0) << endl;
        cout << "name = " << sqlite3_column_text(stmt, 1) << endl;
        cout << "email = " << sqlite3_column_text(stmt, 2) << endl;
        cout << "currentCC = " << sqlite3_column_int(stmt, 3) << endl;
        cout << "gradSemester = " << sqlite3_column_text(stmt, 4) << endl;
        cout << "gradYear = " << sqlite3_column_int(stmt, 5) << endl;
        cout << "preferences = " << sqlite3_column_text(stmt, 6) << endl;
        
        cout << endl;
    }
    
    sqlite3_finalize(stmt);


}
void database::searchStudentByCurrentcc(int word )
{
sqlite3_stmt *stmt;
    const char *pzTest;
    
    string s = "select * from myStudent where currentCC=?";
    
    int rc = sqlite3_prepare(db, s.c_str(), -1, &stmt, &pzTest);
    
    if (sqlite3_bind_int(stmt, 1, cc) != SQLITE_OK) {
        return;
    }
    
    //Read each row
    while ( (rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        cout << "Ind = " << sqlite3_column_int(stmt, 0) << endl;
        cout << "name = " << sqlite3_column_text(stmt, 1) << endl;
        cout << "email = " << sqlite3_column_text(stmt, 2) << endl;
        cout << "currentCC = " << sqlite3_column_int(stmt, 3) << endl;
        cout << "gradSemester = " << sqlite3_column_text(stmt, 4) << endl;
        cout << "gradYear = " << sqlite3_column_int(stmt, 5) << endl;
        cout << "preference = " << sqlite3_column_text(stmt, 6) << endl;
        
        cout << endl;
    }
    
    sqlite3_finalize(stmt);

}

void database::searchStudentByGradsemester(string word )
{
    sqlite3_stmt *stmt;
    const char *pzTest;
    
    string s = "select * from StudentsTable where gradSemester=?";
    
    int rc = sqlite3_prepare(db, s.c_str(), -1, &stmt, &pzTest);
    
    if (sqlite3_bind_text(stmt, 1, word.c_str(), -1, NULL) != SQLITE_OK) {
        return;
    }
    
    //Read each row
    while ( (rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        cout << "Ind = " << sqlite3_column_int(stmt, 0) << endl;
        cout << "name = " << sqlite3_column_text(stmt, 1) << endl;
        cout << "email = " << sqlite3_column_text(stmt, 2) << endl;
        cout << "currentCC = " << sqlite3_column_int(stmt, 3) << endl;
        cout << "gradSemester = " << sqlite3_column_text(stmt, 4) << endl;
        cout << "gradYear = " << sqlite3_column_int(stmt, 5) << endl;
        cout << "preferences = " << sqlite3_column_text(stmt, 6) << endl;
        
        cout << endl;
    }
    
    sqlite3_finalize(stmt);



}

void database::searchStudentByGradyear(int word )
{
sqlite3_stmt *stmt;
    const char *pzTest;
    
    string s = "select * from myStudent where gradYear=?";
    
    int rc = sqlite3_prepare(db, s.c_str(), -1, &stmt, &pzTest);
    
    if (sqlite3_bind_int(stmt, 1, year) != SQLITE_OK) {
        return;
    }
    
    //Read each row
    while ( (rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        cout << "Ind = " << sqlite3_column_int(stmt, 0) << endl;
        cout << "name = " << sqlite3_column_text(stmt, 1) << endl;
        cout << "email = " << sqlite3_column_text(stmt, 2) << endl;
        cout << "currentCC = " << sqlite3_column_int(stmt, 3) << endl;
        cout << "gradSemester = " << sqlite3_column_text(stmt, 4) << endl;
        cout << "gradYear = " << sqlite3_column_int(stmt, 5) << endl;
        cout << "preference = " << sqlite3_column_text(stmt, 6) << endl;
        
        cout << endl;
    }
    
    sqlite3_finalize(stmt);

}



void database::searchByLoc(string word)
{
	char *szErrMsg = 0;
	string s="select * from EventsTable where location='"+word+"'";
//	sqlite3_stmt *stmt;
	/* Execute SQL statement */
	int rc = sqlite3_exec(db, s.c_str(), callback, NULL, &szErrMsg);

	if( rc != SQLITE_OK ) {
		cout<< "SQL error:"<<szErrMsg;
		sqlite3_free(szErrMsg);
	}
	else
	{

	}

}

void database::searchByDesc(string word)
{
	char *szErrMsg = 0;
	string s="select * from EventsTable where description='"+word+"'";
	/* Execute SQL statement */
	int rc = sqlite3_exec(db, s.c_str(), callback, NULL, &szErrMsg);

	if( rc != SQLITE_OK ) {
		cout<< "SQL error:"<<szErrMsg;
		sqlite3_free(szErrMsg);
	}
	else
	{
		//cout<< "Operation done successfully\n";
	}

}

void database::searchById(int i)
{
	char *szErrMsg = 0;
        string s="select * from EventsTable where id=";
	std::ostringstream ss;
	ss << i;
	
        /* Execute SQL statement */
        int rc = sqlite3_exec(db, s.c_str(), callback, NULL, &szErrMsg);

        if( rc != SQLITE_OK ) {
                cout<< "SQL error:"<<szErrMsg;
                sqlite3_free(szErrMsg);
        }
        else
        {
                //cout<< "Operation done successfully\n";
        }

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


