#include "../header/SongCollection.h"
#include "../header/Sort.h"
#include "../header/UserLogin.h"
#include "../header/Diary.h"
#include "../header/UserApplication.h"

int main() 
{
    UserApplication userApplication;
    userApplication.run();

    if (userApplication.getLoginStatus()) 
    {
        SongCollection myCollection;
        myCollection.readSongsFromCSV("NoNumberingDataSet.csv");
        Sort sorter;
        sorter.promptAndSort(myCollection);
    } 
    else 
    {}

    return 0;
}
