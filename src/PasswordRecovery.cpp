#include "../header/PasswordRecovery.h"
#include <iostream>

PasswordRecovery::PasswordRecovery(UserStorage& storage) : storage(storage) {}

void PasswordRecovery::resetPassword() 
{
    std::string username, firstName, lastName, dob, newPassword;
    std::cout << "Enter your username: ";
    std::cin >> username;
    std::cout << "Enter your first name: ";
    std::cin >> firstName;
    std::cout << "Enter your last name: ";
    std::cin >> lastName;
    std::cout << "Enter your date of birth (YYYY-MM-DD): ";
    std::cin >> dob;


    if (storage.userExists(username)) 
    {
        UserProfile user = storage.getUserProfile(username); // Implement this method in UserStorage
        if (user.getFirstName() == firstName && user.getLastName() == lastName && user.getDOB() == dob) {
            std::cout << "Enter your new password: ";
            std::cin >> newPassword;
            storage.updateUserPassword(username, newPassword);
            std::cout << "Password updated successfully.\n";
        } 
        else
        {
            std::cout << "User verification failed. Cannot reset password.\n";
        }
    } 
    else 
    {
        std::cout << "Username does not exist.\n";
    }
}
