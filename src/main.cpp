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
            userDiary.loadFromFile(username); 
            SongCollection myCollection;
            myCollection.readSongsFromCSV("NoNumberingDataSet.csv");
            Sort sorter;
            sorter.promptAndSort(myCollection, username);
        }
    } else {
       
    }

    return 0;
}
