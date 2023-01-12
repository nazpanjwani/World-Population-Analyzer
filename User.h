#ifndef USER_H
#define USER_H

#include "Data.h"
#include "Data.cpp"

class User{
	private:
	string username;
	char password[11];
	
	public:	
	User(Data s1);
	void verifyDetails(Data s1);
    void adminMenu(Data &obj);
    void guestMenu(Data &obj);	
};


#endif
