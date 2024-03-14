#include "../header/askForUserLogin.h"
#include <iostream>


// void askForUserLogin::setUsername(const std::string& name) {
//     username = name;
// }

// std::string askForUserLogin::getUsername() {
//     return username;
// }

bool askForUserLogin::promptUser() 
{
    int userInput;
    UserLogin loginSystem;
    bool loginSuccess = false; 

    std::cout << "Click One If You Would Like To Create An Account" << std::endl;
    std::cout << "Click Two If You Already Have An Account" << std::endl;
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
    } 
    else 
    {
        std::cout << "Invalid Option Selected" << std::endl;
    }

    return loginSuccess;
}
