#ifndef ASKFORUSERLOGIN_H
#define ASKFORUSERLOGIN_H

#include "UserLogin.h"

class askForUserLogin {
private:
    std::string username;
    std::string password;

public:
    bool promptUser();
};

#endif // ASKFORUSERLOGIN_H
