#ifndef ASKFORUSERLOGIN_H
#define ASKFORUSERLOGIN_H

#include "UserLogin.h"

class askForUserLogin {
private:
    std::string username;
    std::string password;

public:
    void setUsername(const std::string& name); 
    std::string getUsername(); 
    bool promptUser();
};

#endif // ASKFORUSERLOGIN_H
