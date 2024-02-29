#include "askForUserLogin.h"
#include <iostream>

bool askForUserLogin::promptUser() 
{
    int userInput;
    UserLogin loginSystem;
    bool loginSuccess = false; 

    std::cout << "If You Are A New User Click 1" << std::endl;
    std::cout << "If You Already Have An Account Click 2" << std::endl;
    std::cin >> userInput;

    loginSystem.loadUsersFromFile();

    if (userInput == 1) {
        std::cout << "Enter A Username: " << std::endl;
        std::cin >> username;
        std::cout << "Enter A Password: " << std::endl;
        std::cin >> password;

        loginSystem.registerUsers(username, password);
        loginSuccess = loginSystem.loginUser(username, password);

    } else if (userInput == 2) 
    {
        std::cout << "Enter Your Username: " << std::endl;
        std::cin >> username;
        std::cout << "Enter Your Password: " << std::endl;
        std::cin >> password;

        loginSuccess = loginSystem.loginUser(username, password);
    } else {
        std::cout << "Invalid Option Selected" << std::endl;
    }

    return loginSuccess;
}
