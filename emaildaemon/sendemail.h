#ifndef SENDEMAIL_H
#define SENDEMAIL_H

#include <string>
#include <vector>

class SendEmail{ 
private:


public:
	int getID() const;
	int getYear() const;
	int getCulturalCreditCount(int id) const;
	std::vector<std::string> getInterests();
	
	bool sendEmail();

};


#endif
