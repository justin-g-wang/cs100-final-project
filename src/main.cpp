#include "../header/SongCollection.h"
#include "../header/Sort.h"
#include "../header/UserLogin.h"
#include "../header/askForUserLogin.h"
#include "../header/Diary.h"
int main() {

    askForUserLogin userLoginPrompt;
    bool loginWasSuccessful = userLoginPrompt.promptUser();
    
    if (loginWasSuccessful) 
    {
        SongCollection myCollection;
        myCollection.readSongsFromCSV("NoNumberingDataSet.csv");
        Sort sorter;
        sorter.promptAndSort(myCollection);
    } 
    else 
    {
        std::cout << "Access Denied." << std::endl;
    }

    return 0;
}
