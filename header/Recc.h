#ifndef RECC_H
#define RECC_H
#include "../header/SongCollection.h"
#include "../header/Diary.h"

    class Recc {
    private:
        std::vector<Song> recc;
    public:
        std::vector<Song>& getRecc();
        void viewRecc(SongCollection& collection, std::vector<Song>& diary);
        void ReccByArtist(SongCollection& collection);
        void ReccByAlbum(SongCollection& collection);
        void ReccBySong(SongCollection& collection, Diary& userDiary, std::vector<Song>& recc);
        void ReccByPopularity(SongCollection& collection);
        void ReccByGenre(SongCollection& collection);
        void promptForRecc(SongCollection& collection, Diary& userDiary, std::vector<Song>& recc);
    };

#endif
