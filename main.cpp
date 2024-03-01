#include "SongCollection.h"
#include "Sort.h"
#include "UserLogin.h"
#include "askForUserLogin.h"

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
