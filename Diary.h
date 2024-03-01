#ifndef DIARY_H
#define DIARY_H
#include <string>


class Diary {
    private: 
        int numSongs;
        int numArtists;
        int numAlbums;
        std::string songRecs; //might be vector?
        std::string albumRecs; //might be vector?
        std::string artistRecs; //might be vector?

    public:
        int getNumSongs();
        int getNumArtists();
        int getNumAlbums();
        void showSongRecs();
        void showAlbumRecs();
        void showArtistsRecs();
        void addSong();
        void removeSong();
}



#endif //DIARY_H