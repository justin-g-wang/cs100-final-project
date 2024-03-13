#include "ratings.h"
#include "Diary.h"
#include "Song.h"
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <limits>

     void createDiary() {
        // Initialize or reset the diary
        Diary.clear();
        numSongs = 0;
        numArtists = 0;
        numAlbums = 0;
        std::vector<Song>& diary
    }


    int getNumSongs() const {
        return numSongs;
    }
    int getNumArtists() const {
        return numArtists;
    }
    int getNumAlbums() const {
        return numAlbums;
    }

    void Diary::addSong(std::vector<Song>& diary){
        std::cout << "Enter the title of the song: ";
        std::string addedSong;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, addedSong); 
        numSongs++;
        diary.push_back(Song(songName));

    std::cout << songName << " added to the diary!" << std::endl;
}
    
    void Diary::addAlbum(){

    }
    void Diary::addArtist(){

    }
    void Diary::removeSong(){

    }
    void Diary::removeAlbum(){

    }
    void Diary::removeArtist(){
        
    }