#include "UserStorage.h"
#include <fstream>
#include <iostream>


UserStorage::UserStorage() {
    loadUsers();
}

void UserStorage::loadUsers() {
    std::ifstream inFile(filePath);
    if (!inFile.is_open()) {
        std::cerr << "Failed To Open File To Load Users " << filePath << std::endl;
        return;
    }

    std::string username, password;
    while (inFile >> username >> password) {
        users[username] = password;
    }
}

void UserStorage::saveUser(const std::string& username, const std::string& password, const UserProfile& userProfile) {
    
     if (userExists(username)) {
        std::cout << "User Already Exists." << std::endl;
        return;
    }

    users[username] = password;
    std::ofstream outFile(filePath, std::ios::app);
    if (!outFile.is_open()) {
        std::cerr << "Failed To Open File For Saving User " << filePath << std::endl;
        return;
    }

    outFile << username << " " << password << " " 
            << userProfile.getFirstName() << " " 
            << userProfile.getLastName() << " " 
            << userProfile.getDOB() << std::endl;
    std::cout << "User Registered Successfully." << std::endl;
}

bool UserStorage::userExists(const std::string& username) const {
    return users.find(username) != users.end();
}

bool UserStorage::validateUser(const std::string& username, const std::string& password) const {
    auto it = users.find(username);
    if (it != users.end()) {
        return it->second == password;
    }
    return false;
}
