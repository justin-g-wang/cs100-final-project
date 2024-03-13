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
        diary.clear();
        numSongs = 0;
        numArtists = 0;
        numAlbums = 0;
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
        std::string songTitle;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, songName); 
        
        auto& songs = collection.getSongs();
        bool found = false;
        for (const auto& song : songs) 
        {
            if (song.songName == songTitle) 
            {
                found = true;
                numSongs++;
                diary.push_back(Song(songName));   
                std::cout << "Artist: " << song.artist
                        << ", Album: " << song.albumName
                        << ", Song: " << song.songName
            }   
        }
         
        if (!found) {
            std::cout << "No songs found for : " << songName << std::endl;
        }
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