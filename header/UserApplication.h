#ifndef USERAPPLICATION_H
#define USERAPPLICATION_H

#include "../header/UserStorage.h"
#include "../header/UserAuthentication.h"
#include "../header/UserProfile.h"

class UserApplication 
{
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
    bool isPasswordValid(const std::string& password);
    bool isDOBValid(const std::string& dob);
    void resetUserPassword();
};

#endif // USERAPPLICATION_H
