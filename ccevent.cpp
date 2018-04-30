#include <iostream>       
#include "ccevent.h"

using namespace std;


CCEvent::CCEvent() {
	title = "notitle";
	location = "nolocation";
	dateTime = "nodatetime";
	description = "nodescription";
}

CCEvent::CCEvent(string _title, string _location, string _dateTime, string _description){
	title = _title;
	location = _location;
	dateTime = _dateTime;
	description = _description;
}

void CCEvent::setTitle(string t){
	title = t;
}

void CCEvent::setLocation(string loc){
	location = loc;
}

void CCEvent::setDateTime(string dt){
	dateTime = dt;
}

void CCEvent::setDescription(string d){
	description = d;
}

string CCEvent::getTitle(){
	return title;
}

string CCEvent::getLocation(){
	return location;
}

string CCEvent::getDateTime(){
	return dateTime;
}

string CCEvent::getDescription(){
	return description;
}
