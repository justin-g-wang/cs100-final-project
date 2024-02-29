#include "SongCollection.h"
#include "Sort.h"

int main() {
    SongCollection myCollection;
    myCollection.readSongsFromCSV("NoNumberingDataSet.csv");

    Sort sorter; // Create an instance of Sort
    sorter.promptAndSort(myCollection); // Call the member function on the instance

    return 0;
}
