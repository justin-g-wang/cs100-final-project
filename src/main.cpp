#include "../header/SongCollection.h"
#include "../header/Sort.h"
#include "../header/UserLogin.h"
#include "../header/Diary.h"
#include "../header/UserApplication.h"
#include "../header/ratings.h"

int main() {
    UserApplication userApplication;
    userApplication.run();

    if (userApplication.getLoginStatus()) {
        std::string username = userApplication.getCurrentUsername();
        if (!username.empty()) {
            Diary userDiary;
            Ratings ratings;
            userDiary.loadFromFile(username); 
            SongCollection myCollection;
            myCollection.readSongsFromCSV("NoNumberingDataSet.csv");

    bool running = true;
    int choice;

    while (running) {
        std::cout << "1. Add A Song To The Diary & A Rating\n";
        std::cout << "2. View Recommendations\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
            Sort sorter;
            sorter.promptAndSort(myCollection, username);
                break;
            case 2:
                //viewRecommendations();
                break;
            case 3:
                std::cout << "Exiting program...\n";
                running = false;
                break;
            default:
                std::cout << "Invalid choice, please try again.\n";
        }
    }



            
        }
    } else {
       
    }

    return 0;
}
