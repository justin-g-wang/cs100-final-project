#ifndef USERSTORAGE_H
#define USERSTORAGE_H

#include <unordered_map>
#include <string>
#include "UserProfile.h"

class UserStorage {
private:
    std::unordered_map<std::string, std::string> users;
    const std::string filePath = "UserLoginStorage.txt";

public:
    UserStorage();
    void loadUsers();
    void saveUser(const std::string& username, const std::string& password, const UserProfile& userProfile);
    bool userExists(const std::string& username) const;
    bool validateUser(const std::string& username, const std::string& password) const;
};

#endif // USERSTORAGE_H
