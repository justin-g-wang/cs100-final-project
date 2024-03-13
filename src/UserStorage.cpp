#include "../header/UserStorage.h"
#include <fstream>
#include <iostream>


UserStorage::UserStorage() 
{
    loadUsers();
}

void UserStorage::loadUsers() 
{
    std::ifstream inFile(filePath);
    if (!inFile.is_open()) {
        std::cerr << "Failed To Open File To Load Users " << filePath << std::endl;
        return;
    }

    std::string username, password, firstName, lastName, dob;
    while (inFile >> username >> password >> firstName >> lastName >> dob) {
        UserProfile userProfile(firstName, lastName, dob);
        users[username] = std::make_pair(password, userProfile);
    }
}

void UserStorage::saveUser(const std::string& username, const std::string& password, const UserProfile& userProfile) 
{
    if (userExists(username)) 
    {
        std::cout << "User Already Exists." << std::endl;
        return;
    }

    users[username] = std::make_pair(password, userProfile);
    std::ofstream outFile(filePath, std::ios::app);
    if (!outFile.is_open()) 
    {
        std::cerr << "Failed To Open File For Saving User " << filePath << std::endl;
        return;
    }

    outFile << username << " " << password << " "
            << userProfile.getFirstName() << " "
            << userProfile.getLastName() << " "
            << userProfile.getDOB() << std::endl;
    std::cout << "User Registered Successfully." << std::endl;
}

bool UserStorage::userExists(const std::string& username) const 
{
    return users.find(username) != users.end();
}

bool UserStorage::validateUser(const std::string& username, const std::string& password) const 
{
    auto it = users.find(username);
    if (it != users.end()) {
        return it->second.first == password;
    }
    return false;
}

UserProfile UserStorage::getUserProfile(const std::string& username) const 
{
    if (users.find(username) != users.end()) 
    {
        return users.at(username).second; 
    }
    throw std::runtime_error("User Not Found"); 
}

void UserStorage::updateUserPassword(const std::string& username, const std::string& newPassword)
 {
    auto it = users.find(username);
    if (it != users.end()) 
    {
        it->second.first = newPassword;

        std::ofstream outFile(filePath, std::ios::trunc);
        if (!outFile.is_open()) 
        {
            std::cerr << "Failed to open file for updating user " << filePath << std::endl;
            return;
        }

        for (const auto& user : users) 
        {
            outFile << user.first << " " 
                    << user.second.first << " " 
                    << user.second.second.getFirstName() << " "
                    << user.second.second.getLastName() << " "
                    << user.second.second.getDOB() << std::endl;
        }
    } 
    else 
    {
        throw std::runtime_error("User not found");
    }
}

