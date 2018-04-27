#include <iostream>
#include <string>
#include <sstream>
#include "sqlite3.h"

using namespace std;

sqlite3 *db;

// This is the callback function to display the selected data in the table
static int callback(void *NotUsed, int argc, char **argv, char **szColName)
{
	for (int i = 0; i < argc; i++)
	{
		cout << szColName[i] << ": " << argv[i] << endl;
	}

	cout << "\n";

	return 0;
}

// return is the table has values and how many
int rowsIntable()
{
	int count=0;
	sqlite3_stmt * stmt;
	sqlite3_prepare( db, "SELECT * from myStudent;", -1, &stmt, NULL );//preparing the statement
	sqlite3_step( stmt );//executing the statement

	while( sqlite3_column_text( stmt, 0 ) )
	{
		count++;
		sqlite3_step( stmt );
	}
	return count;

}

bool checkEmptyTable()
{
	int c=rowsIntable();
	if(c==0)
		return true;

	return false;
}

//search by name
void searchByName(string word)
{
	char *szErrMsg = 0;
	string s="select * from myStudent where name='"+word+"'";
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

//search by email
void searchByEmail(string word)
{
	char *szErrMsg = 0;
	string s="select * from myStudent where email='"+word+"'";
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
void searchByPreference(string word)
{
	char *szErrMsg = 0;
	string s="select * from myStudent where preference='"+word+"'";
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


//search by currentCC
void searchByCurrentcc(string word)
{
	char *szErrMsg = 0;
	string s="select * from myStudent where currentCC="+word+"";
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

//search by graduation semester
void searchByGradsemester(string word)
{
	char *szErrMsg = 0;
	string s="select * from myStudent where gradSemester='"+word+"'";
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

//search by graduation year
void searchByGradyear(int word)
{

    cout<<"Searching by grad year:"<<word<<endl;
	char *szErrMsg = 0;

	std::ostringstream ss;
	ss << word;

	string s="select * from myStudent where gradYear="+ss.str()+"";
	/* Execute SQL statement */
	cout<<s<<endl;
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


//insert data according to student paramaters
void insertData(string name,string email,int currentcc,string gradsemester,int gradyear,string pref)
{

	std::ostringstream ss;
	ss << currentcc;
	string query="INSERT INTO myStudent(name,email,currentCC,gradSemester,gradYear,preference) VALUES (";

	query.append("'"+name+"','");
	query.append(email+"',");
	query.append(ss.str()+",'");
	query.append(gradsemester+"',");

	ss.clear();
	std::ostringstream ss2;
	ss2 << gradyear;

	query.append(ss2.str()+",'");
	query.append(pref+"')");

	cout<<query<<endl;
	char *szErrMsg = 0;
	int rc = sqlite3_exec(db,query.c_str() , NULL, NULL, &szErrMsg);
	if (rc != SQLITE_OK)
	{
		cout << "SQL Error: " << szErrMsg << std::endl;
		sqlite3_free(szErrMsg);

	}
	else
        cout<<"Insert Successfully"<<endl;



}

int main()
{

	char *szErrMsg = 0;
	int retval;

	// open database
	int rc = sqlite3_open("StetsonData.db", &db);

	if (rc)
		cout << "Can't open or create database\n";
	else
		cout << "Open database successfully\n";



	const char *szSQL = "CREATE TABLE myStudent (" \
	"ind INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE," \
	"name	TEXT NOT NULL," \
	"email	TEXT NOT NULL," \
	"currentCC	INTEGER NOT NULL," \
	"gradSemester	TEXT NOT NULL," \
	"gradYear	INTEGER NOT NULL," \
	"preference	TEXT NOT NULL);";

	string s="select * from myStudent";
	/* Execute SQL statement */
	rc = sqlite3_exec(db, s.c_str(), callback, NULL, &szErrMsg);

	///if error that means no table by that name so create this table
	if( rc != SQLITE_OK )
    {
		sqlite3_free(szErrMsg);
        rc = sqlite3_exec(db,szSQL , NULL, NULL, &szErrMsg);
        if (rc != SQLITE_OK)
        {
            cout << "SQL Error Table:" << szErrMsg << std::endl;
            sqlite3_free(szErrMsg);

        }
	}


//	cout<<"Total rows in table:"<<rowsIntable()<<endl;
	// name , email , currentcc, gradSemester, gradYear
	//	insertData("test","test",10,"test",2020,"test");
	
	//	insertData("abdullah","gmail.com",3,"test",2020,"music");

//cout<<"Searching with semester "<<endl;
//	searchByGradyear(2020);
	//	cout << "Sreaching with preference" << endl;
	//	searchByPreference("music");

	// Close database
	if (db)
	{
		sqlite3_close(db);
	}

	return 0;
}

