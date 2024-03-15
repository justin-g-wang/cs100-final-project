#ifndef DIARY_H
#define DIARY_H
#include <string>
#include <vector>
#include <iostream>
#include "Song.h"
#include "SongCollection.h"
// #include "Sort.h"

class Diary {
    private: 
        int numSongs;
        int numArtists;
        int numAlbums;
        std::string songRecs; //might be vector?
        std::string albumRecs; //might be vector?
        std::string artistRecs; //might be vector?
        std::vector<Song> diary;

    public:
        Diary() : numSongs(0), numArtists(0), numAlbums(0) {}

        void createDiary();
        int getNumSongs();
        int getNumArtists();
        int getNumAlbums();
        std::vector<Song>& getDiary();
        void addSong(SongCollection& collection);
        void viewDiary(SongCollection& collection);
        void saveToFile(const std::string& username) const;
        void loadFromFile(const std::string& username);
        void addAlbum(SongCollection& collection);
        void addArtist(SongCollection& collection);
        void removeSong(SongCollection& collection);
        void removeAlbum(SongCollection& collection);
        void removeArtist(SongCollection& collection);

};

#endif
