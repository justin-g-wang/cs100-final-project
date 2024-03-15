#include "../header/UserApplication.h"
#include "../header/UserMenu.h"
#include <iostream>
#include <limits>
#include <string>

UserApplication::UserApplication() : authentication(storage), isLoggedIn(false) {}

void UserApplication::run() 
{
    while (true)
     {
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
                if (loginUser()) 
                {
                    isLoggedIn = true;
                    std::cout << "Login Successful!\n";
                    return;
                } 
                else 
                {
                    std::cout << "Login Failed. Please Check Your Username And Password" << std::endl;
                }
                break;
            case 3: 
                resetUserPassword();
                break;
            case 4: 
                std::cout << "Exiting Application" << std::endl;
                return;
            default:
                std::cout << "Invalid Option. Please Try Again" << std::endl;
        }
    }
}

void UserApplication::registerUser() 
{
    std::string username, password;
    std::string firstName, lastName, dob; 

    std::cout << "Enter username: ";
    std::cin >> username;
     while (true) 
     {
        std::cout << "Enter password: ";
        std::cin >> password;
        if (isPasswordValid(password)) 
        {
            break; 
        }
    }


    std::cout << "Enter first name: ";
    std::cin >> firstName;
    std::cout << "Enter last name: ";
    std::cin >> lastName;
    
     bool dobValid = false;
    while (!dobValid) 
    {
        std::cout << "Enter date of birth (YYYY-MM-DD): ";
        std::cin >> dob;
        dobValid = isDOBValid(dob);
        if (!dobValid) 
        {
            std::cout << "Invalid date of birth format. Please use YYYY-MM-DD format with numbers only." << std::endl;
        }
    }
    
    UserProfile userProfile(firstName, lastName, dob);
    storage.saveUser(username, password, userProfile);
}

bool UserApplication::loginUser() {
    std::string username, password;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;

    if (authentication.authenticate(username, password)) {
        isLoggedIn = true;
        currentUserUsername = username; 
        return true;
    } else {
        std::cout << "Login Failed. Please Check Your Username And Password" << std::endl;
        return false;
    }
}

bool UserApplication::getLoginStatus() const 
{
    return isLoggedIn;
}

bool UserApplication::isPasswordValid(const std::string& password) 
{
    if (password.length() < 8) {
        std::cout << "Password must be at least 8 characters long." << std::endl;
        return false;
    }

    if (password.find_first_of("0123456789") == std::string::npos) 
    {
        std::cout << "Password must include at least one number." << std::endl;
        return false;
    }

    return true; 
}

bool UserApplication::isDOBValid(const std::string& dob) 
{
    if (dob.length() != 10) 
    {
        return false; // Basic length check
    }

    // Check format is YYYY-MM-DD
    for (int i = 0; i < dob.length(); ++i) 
    {
        if (i == 4 || i == 7) {
            if (dob[i] != '-') return false; // Expecting '-' at positions 5 and 8
        } 
        else 
        {
            if (!isdigit(dob[i])) return false; // Other positions should be digits
        }
    }

    return true;
}

void UserApplication::resetUserPassword() 
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

    try {
        UserProfile user = storage.getUserProfile(username);
        if (user.getFirstName() == firstName && user.getLastName() == lastName && user.getDOB() == dob) 
        {
            bool validPassword = false;
            while (!validPassword) 
            {
                std::cout << "Enter Your New Password: ";
                std::cin >> newPassword;
                validPassword = isPasswordValid(newPassword);
                if (!validPassword)
                {
                    std::cout << "Password does not meet the requirements. It must be at least 8 characters long and include at least one number." << std::endl;
                } 
                else 
                {
                    storage.updateUserPassword(username, newPassword);
                    std::cout << "Password updated successfully.\n";
                }
            }
        } 
        else 
        {
            std::cout << "User Verification Failed. Cannot Reset Password.\n";
        }
    } 
    catch (const std::runtime_error& e) 
    {
        std::cout << "Username Does Not Exist.\n";
    }
}


std::string UserApplication::getCurrentUsername() const {
    return currentUserUsername; 
}

