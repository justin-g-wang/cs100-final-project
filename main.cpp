#include "SongCollection.h"

int main() {
    SongCollection mySongCollection;
    mySongCollection.readSongsFromCSV("NoNumberingDataSet.csv");
    mySongCollection.printSongs();

    return 0; 
}