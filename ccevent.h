#ifndef ccevent_h
#define ccevent_h

#include <string>

class CCEvent {
private:
	std::string title;
	std::string location;
	std::string dateTime;
	std::string description;

public:
	CCEvent();
	CCEvent(std::string _title, std::string _location, std::string _dateTime, std::string _description);
	void setTitle(std::string t);
	void setLocation(std::string loc);
	void setDateTime(std::string dt);
	void setDescription(std::string d);

	std::string getTitle();
	std::string getLocation();
	std::string getDateTime();
	std::string getDescription();
};

#endif	
