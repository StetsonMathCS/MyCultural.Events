#ifndef MAKEEMAIL_H
#define MAKEEMAIL_H

//#include "makeemail.h"
#include "../student.h"
#include "../ccevent.h"
#include <string>
#include <fstream>
#include <vector>


class MakeEmail {
	private:
		std::string email;
	public:
		MakeEmail();
		void setStudentNameInEmail(Student);
		void setEventTitleInEmail(std::ifstream&, std::ofstream&, CCEvent);
		void setEventDescriptionInEmail(std::ifstream&, std::ofstream&, CCEvent);
		void setEventTimeInEmail(std::ifstream&, std::ofstream&, CCEvent);
		void setEventLocationInEmail(std::ifstream&, std::ofstream&, CCEvent);
		int setEmailString(std::vector<Student>, std::vector<CCEvent>);		

};
#endif
