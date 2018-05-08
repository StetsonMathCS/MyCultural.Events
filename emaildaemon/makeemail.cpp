#include <iostream>
#include <fstream>
#include <sstream>
#include "../student.h"
#include "../ccevent.h"
#include "makeemail.h"
#include <curl/curl.h>

using namespace std;
#include <string>
#include <vector>

MakeEmail::MakeEmail()
{
	emailStr = "no email";
}

void MakeEmail::storeEmailString(string str){
        emailStr = str;
}


string MakeEmail::getEmailString(){
        return emailStr;
}

void MakeEmail::setStudentNameInEmail(Student student){
        ifstream in("email2.html");
	ofstream out("filledStName.html");

	string line;
        string wordToReplace = "!!FirstName!!";
        size_t len = wordToReplace.length();
        while (getline(in, line)){
                while (true){
                        size_t pos = line.find(wordToReplace);
                        if (pos != string::npos){
                                if(student.getName() == ""){
                                        line.replace(pos, len, " No Name");
                                }else{
                                        line.replace(pos, len, " " + student.getName());
                                }
                        }else{
                                out << line << endl;
                                break;
                        }
                }

        }
}

                                                                                                                      
void MakeEmail::setEventTitleInEmail(ifstream& in, ofstream& out, CCEvent event){
        string line;
        string wordToReplace = "!!Title!!";
        size_t len = wordToReplace.length();
        while (getline(in, line)){
                while (true){
                        size_t pos = line.find(wordToReplace);
                        if (pos != string::npos){
                                if(event.getTitle() == " "){
                                        line.replace(pos, len, " ");
                                }else{
                                        line.replace(pos, len, " " + event.getTitle());
                                }
                        }else{
                                out << line << endl;
                                break;
                        }
                }
        }
}

void MakeEmail::setEventDescriptionInEmail(ifstream& in, ofstream& out, CCEvent event){
        string line;
        string wordToReplace = "!!Description!!";
        size_t len = wordToReplace.length();
        while (getline(in, line)){
                while (true){
                        size_t pos = line.find(wordToReplace);
                        if (pos != string::npos){
                                if(event.getDescription() == ""){
                                        line.replace(pos, len, " No Description");
                                }else{
                                        line.replace(pos, len, " " + event.getDescription());
                                }
                        }else{
                                out << line << endl;
                                break;
                        }
                }

        }
}

void MakeEmail::setEventTimeInEmail(ifstream& in, ofstream& out, CCEvent event){
        string line;
        string wordToReplace = "!!Time!!";
        size_t len = wordToReplace.length();
        while (getline(in, line)){
                while (true){
                        size_t pos = line.find(wordToReplace);
                        if (pos != string::npos){
                                line.replace(pos, len, " " + event.getDateTime());
                        }else{
                                out << line << endl;
                                break;
                        }
                }

        }


}

void MakeEmail::setEventLocationInEmail(ifstream& in, ofstream& out, CCEvent event){
        string line;
        string wordToReplace = "!!Location!!";
        size_t len = wordToReplace.length();
        while (getline(in, line)){
                while (true){
                        size_t pos = line.find(wordToReplace);
                        if (pos != string::npos){
                                line.replace(pos, len, " " + event.getLocation());
                        }else{
                                out << line << endl;
                                break;
                        }
                }

        }


}

int MakeEmail::setEmailString(vector<Student> stvec, vector<CCEvent> ccvec){
	Student student;
	CCEvent event;
//	for(int i = 1; i < 2; i++){
                //vector<Student> stvec = db.searchStudentById(i);
                student = stvec[0];
               
                setStudentNameInEmail(student);
                student.setPriorityLevel();
                int priorityLevel = student.getPriorityLevel();
                cout << "Student's name is: " << student.getName() << endl;
                cout << "Student's priority level has been set to: " << priorityLevel << endl;
                if(priorityLevel > 0){ //priorityLevel og 1 means HIGH PRIORITY, email sent about the nearest cultural credit available regardless of the student's interests/preferences(
			//vector<CCEvent> ccvec = db.searchEventById(14); //used Event 14 for testing purposes
                        event = ccvec[0];
                        cout << "Date/Time for this event is: " << event.getDateTime() << endl;
			
			
                        ifstream filein2("filledStName.html");
                        ofstream fileout2("filledEventTitle.html");
                        if(!filein2 || !fileout2){
                                 cout << "ERROR OPENING FILES: filledStName.html filledEventTitle.html does not exist in this directory." << endl;
                                return -2;
                        }
                        setEventTitleInEmail(filein2, fileout2, event);
                        cout << "Event Title has been set in the Email." << endl;

                        ifstream filein3("filledEventTitle.html");
                        ofstream fileout3("filledEventDesc.html");
                        if(!filein3 || !fileout3){
                                 cout << "ERROR OPENING FILES: filledEventTitle.html filledEventDesc.html does not exist in this directory." << endl;
                                return -3;
                        }
                        setEventDescriptionInEmail(filein3, fileout3, event);
                        cout << "Event Description has been set in the Email." << endl;

                        ifstream filein4("filledEventDesc.html");
                        ofstream fileout4("filledEventTime.html");
                        if(!filein4 || !fileout4)
                        {
                                cout << "ERROR OPENING FILES: filledEventDesc.html or filledEventTime.html does not exist in this directory" << endl;
                                return -4;
                        }
                        setEventTimeInEmail(filein4, fileout4, event);
                        cout << "Event Time has been set in the Email." << endl;
			
			ifstream filein5("filledEventTime.html");
			ofstream fileout5("finalEmail.html");
                        if(!filein5 || !fileout5)
                        {
                                cout << "ERROR OPENING FILES: fiilledEventTime.html or finalEmail.html does not exist in this directory" << endl;
                                return -5;
                        }
                        setEventLocationInEmail(filein5, fileout5, event);
                        cout<< "Event Location has been set in the Email.\nEmail template complete.\nOpen 'finalEmail.html' to view the code." << endl;
		}
		if(priorityLevel == 0){ //priorityLevel of 0 means MEDIUM PRIORITY, email sent based on student's interests/preferences

			//vector<CCEvent> ccvec = db.searchEventByDesc(st.getInterests());
                        /*if(ccvec.size() > 0){ //If there are actually CC events matching the student's interests
				event = ccvec[0];
                                cout << "Num Events in student's interests: " << ccvec.size() << endl;
                                cout << "Date/Time for this event is: " << event.getDateTime() << endl;
                        }else{//if there are no current CC events matchin ght esudent's interests
				 //vector<CCEvent> ccvec2 = db.searchEventById(14); //used 13 for testing purposes
				 event = ccvec[0];
                                 cout << "There are no cultural events matching this student's interests." << endl;
			}*/

			event = ccvec[0];

			cout << "Event Title: " << event.getTitle() << endl;
                        cout << "Location: " << event.getLocation() << endl;
                        cout << "Date/Time: " << event.getDateTime() << endl;
                        cout << "Description: " << event.getDescription() << endl;

                        ifstream filein2("filledStName.html");
                        ofstream fileout2("filledEventTitle.html");
                        if(!filein2 || !fileout2){
                                 cout << "ERROR OPENING FILES: filledStName.html filledEventTitle.html does not exist in this directory." << endl;
                                return -2;
                        }
                        setEventTitleInEmail(filein2, fileout2, event);
                        cout << "Event Title has been set in the Email." << endl;

                        ifstream filein3("filledEventTitle.html");
                        ofstream fileout3("filledEventDesc.html");
                        if(!filein3 || !fileout3){
                                 cout << "ERROR OPENING FILES: filledEventTitle.html filledEventDesc.html does not exist in this directory." << endl;
                                return -3;
                        }
                        setEventDescriptionInEmail(filein3, fileout3, event);
         		cout << "Event Description has been set in the Email." << endl;

                        ifstream filein4("filledEventDesc.html");
                        ofstream fileout4("filledEventTime.html");
                        if(!filein4 || !fileout4)
                        {
                                cout << "ERROR OPENING FILES: filledEventDesc.html or filledEventTime.html does not exist in this directory" << endl;

                                return -4;
                        }
                        setEventTimeInEmail(filein4, fileout4, event);
                        cout << "Event Time has been set in the Email." << endl;

                        ifstream filein5("filledEventTime.html");
                        ofstream fileout5("finalEmail.html");
                        if(!filein5 || !fileout5)
                        {
                                cout << "ERROR OPENING FILES: fiilledEventTime.html or finalEmail.html does not exist in this directory" << endl;
                                return -5;
                        }
                        setEventLocationInEmail(filein5, fileout5, event);
                        cout<< "Event Location has been set in the Email.\nEmail template complete.\nOpen 'finalEmail.html' to view the code." << endl;

                }
                if(priorityLevel < 0){ //priorityLevel of -1 is LOW priority, no email is sent
			cout << "Student is LOW PRIORITY." << endl;
                }
		stringstream buffer;
		ifstream finalEmail("finalEmail.html");	
    		buffer << finalEmail.rdbuf();
    		storeEmailString(buffer.str());
//		cout << getEmailString() << endl;
//	}
	return 0;
}

string MakeEmail::escape(string const &s)
{
	std::size_t n = s.length();
	std::string escaped;
	escaped.reserve(n * 2);

	for (std::size_t i = 0; i < n; ++i)
	{
		if (s[i] == '\\' || s[i] == '\"')
		escaped += '\\';
		escaped += s[i];
	}
	return escaped;
}

void MakeEmail::emails(string toemail, string subject, string body)
{
	CURL *curl;
	CURLcode res;
	curl_global_init(CURL_GLOBAL_ALL);

	//get a curl handle
	curl = curl_easy_init();
	curl_easy_setopt(curl, CURLOPT_VERBOSE, 1);

	//set the URL to receive the POST DATA
	struct curl_slist *chunk = NULL;
	std::string key= "Authorization: Bearer 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";
	std::string content= "Content-Type: application/json";
	std::cout << content << std::endl;
	std::cout << key << std::endl;
	chunk = curl_slist_append(chunk, key.c_str());
        chunk = curl_slist_append(chunk, content.c_str());
	res = curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);
	curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST"); 
	curl_easy_setopt(curl, CURLOPT_URL, "https://api.sendgrid.com/v3/mail/send");
	curl_easy_setopt(curl, CURLOPT_POST, 1);
	
	//especify the POST DATA
	std::string postbody = "{\"personalizations\": [{\"to\": [{\"email\": \"" + escape(toemail) + "\"}]}],\"from\": {\"email\": \"myculturalevents@stetson.edu\"},\"subject\": \"" + escape(subject) + "\",\"content\": [{\"type\": \"text/plain\", \"value\": \"" + escape(body) +"\"}]}";
	std::cout << postbody << std::endl;
	curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postbody.c_str());


	//perform the request, and resquest will get the return code
	curl_easy_perform(curl);
	//clean up
	curl_easy_cleanup(curl);
}
/*
int main() {

	for(int i = 1; i < 2; i++){
                vector<Student> stvec = db.searchStudentById(i);
                //vector<CCEvent> ccvec = db.searchEventById(13);
                setEmailString(stvec, ccvec);
                cout << me.getEmailString() << endl;
        

	//setEmailString(vector<Student> stvec, vector<CCEvent> ccvec)	
	MakeEmail me;
	me.emails("hgatewood@stetson.edu", "Hello", "stuff");
	

	return 0;
}*/
