#include "../header/UserApplication.h"
#include "../header/SongCollection.h"
#include "../header/Sort.h"

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