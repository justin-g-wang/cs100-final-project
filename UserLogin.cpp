#include "UserLogin.h"
#include <fstream>

void UserLogin::registerUsers(const std::string& username, const std::string& password) {

    if (users.find(username) != users.end()) 
    {
        std::cout << "User Already Exists" << std::endl;
        return;
    }
    users[username] = password;
    std::cout << "User Registered Successfully" << std::endl;
    saveUsersToFile(); 
}

bool UserLogin::loginUser(const std::string& username, const std::string& password) {
    auto it = users.find(username);

    if (it != users.end() && it->second == password) 
    {
        std::cout << "Login Successful" << std::endl;
        return true;
    }
    std::cout << "Login Failed" << std::endl;
    return false;
}

void UserLogin::saveUsersToFile() const {
    std::ofstream outFile("userLoginInfo.txt");
    if (!outFile.is_open()) {
        std::cerr << "Failed To Open File" << std::endl;
        return;
    }
    for (const auto& pair : users) {
        outFile << pair.first << " " << pair.second << std::endl;
    }
}

void UserLogin::loadUsersFromFile() {
    std::ifstream inFile("userLoginInfo.txt");
    if (!inFile.is_open()) {
        std::cerr << "Failed To Open File" << std::endl;
        return;
    }
    std::string username, password;
    while (inFile >> username >> password) {
        users[username] = password;
    }
}
