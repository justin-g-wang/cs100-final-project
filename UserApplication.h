#ifndef USERAPPLICATION_H
#define USERAPPLICATION_H

#include "UserStorage.h"
#include "UserAuthentication.h"

class UserApplication {
private:
    UserStorage storage;
    UserAuthentication authentication;
    bool isLoggedIn;

public:
    UserApplication();
    void run();
    void registerUser();
    bool loginUser();
    bool getLoginStatus() const;
};

#endif // USERAPPLICATION_H
