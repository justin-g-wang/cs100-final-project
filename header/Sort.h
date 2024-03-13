#include "../header/SongCollection.h"

    class Sort 
    {
    public:
         void sortByArtist(SongCollection& collection);
         void sortByAlbumName(SongCollection& collection);
         void sortBySongName(SongCollection& collection);
         void sortByPopularity(SongCollection& collection);
         void sortByGenre(SongCollection& collection);
         void promptAndSort(SongCollection& collection);
    };