#include "UserApplication.h"
#include "UserMenu.h"
#include <iostream>
#include <limits>
#include <string>

UserApplication::UserApplication() : authentication(storage), isLoggedIn(false) {}

void UserApplication::run() {
    while (true) {
        int choice = UserMenu::displayMainMenu();

        if (choice == -1) 
        {
            std::cout << "Invalid Option. Please enter a number." << std::endl;
            continue;
        }
        switch (choice) 
        {
            case 1:
                registerUser();
                break;
            case 2:
                if(loginUser()) {
                    isLoggedIn = true;
                    std::cout << "Login Successful!\n";
                    return ;
                } else {
                    std::cout << "Login Failed. Please Check Your Username And Password" << std::endl;
                }
                break;
            case 3:
                std::cout << "Exiting Application" << std::endl;
                return; 
            default:
                std::cout << "Invalid Option. Please Try Again" << std::endl;
        }
    }
}

void UserApplication::registerUser() {
    std::string username, password;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;

    storage.saveUser(username, password);
}

bool UserApplication::loginUser() {
    std::string username, password;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;

    return authentication.authenticate(username, password);
}

bool UserApplication::getLoginStatus() const {
    return isLoggedIn;
}
