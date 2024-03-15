#ifndef RECC_H
#define RECC_H
#include "../header/SongCollection.h"
#include "../header/Diary.h"

    class Recc {
    private:
        std::vector<Song> recc;
    public:
        std::vector<Song>& getRecc();
        void addSong(const Song userSong);
        void viewRecc(SongCollection& collection);
        void ReccByArtist(SongCollection& collection);
        void ReccByAlbum(SongCollection& collection);
        void ReccBySong(SongCollection& collection, Diary& userDiary);
        void ReccByPopularity(SongCollection& collection);
        void ReccByGenre(SongCollection& collection);
        void promptForRecc(SongCollection& collection, Diary& userDiary, std::vector<Song>& recc);
        void saveToFile() const;
        void loadFromFile();
    };

#endif
