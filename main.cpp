#include "UserApplication.h"
#include "SongCollection.h"
#include "Sort.h"

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
    {
        std::cout << "Failure" << std::endl ;
    }

    return 0;
}