#ifndef USERLOGIN_H
#define USERLOGIN_H

#include <iostream>
#include <unordered_map>
#include <string>

class UserLogin {
private:
    std::unordered_map<std::string, std::string> users;

public:
    void registerUsers(const std::string& username, const std::string& password);
    bool loginUser(const std::string& username, const std::string& password);
    void saveUsersToFile() const;
    void loadUsersFromFile();
};

#endif // USERLOGIN_H
