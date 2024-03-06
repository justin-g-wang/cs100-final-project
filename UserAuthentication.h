#ifndef USERAUTHENTICATION_H
#define USERAUTHENTICATION_H

#include "UserStorage.h"
#include <string>

class UserAuthentication {
private:
    UserStorage& storage;

public:
    UserAuthentication(UserStorage& storage);
    bool authenticate(const std::string& username, const std::string& password);
};

#endif // USERAUTHENTICATION_H
