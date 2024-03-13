#include <iostream>
#include <limits>

class UserMenu {
public:
    static int displayMainMenu() {
        int choice;
        std::cout << "Select An Option" << std::endl;
        std::cout << "1. Register" << std::endl;
        std::cout << "2. Login" << std::endl;
        std::cout << "3. Forget Password" << std::endl; 
        std::cout << "4. Exit" << std::endl; 
        std::cin >> choice;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return -1; 
        }
        return choice;
    }
};