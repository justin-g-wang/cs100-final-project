#ifndef USERSTORAGE_H
#define USERSTORAGE_H

#include <unordered_map>
#include <string>
#include "UserProfile.h"

class UserStorage 
{
private:

    // Map For String & userprofiles
    std::unordered_map<std::string, std::pair<std::string, UserProfile>> users;
    // File For Storage
    const std::string filePath = "UserLoginStorage.txt";

public:
    // Default Constructor
    UserStorage();
    // Load Users From TxtFile
    void loadUsers();
    // Saves Users To TxtFile , Saves the username , password, and userprofile
    void saveUser(const std::string& username, const std::string& password, const UserProfile& userProfile);
    // checks if username exists
    bool userExists(const std::string& username) const;
    // validate user, checks if username matches password
    bool validateUser(const std::string& username, const std::string& password) const;
    // grabs user profile ( uses username )
    UserProfile getUserProfile(const std::string& username) const; 
    // updates a password for a user
    void updateUserPassword(const std::string& username, const std::string& newPassword); 

};

#endif // USERSTORAGE_H
