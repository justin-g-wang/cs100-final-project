#include "UserAuthentication.h"

UserAuthentication::UserAuthentication(UserStorage& storage) : storage(storage) {}

bool UserAuthentication::authenticate(const std::string& username, const std::string& password) 
{
    return storage.validateUser(username, password);
}
