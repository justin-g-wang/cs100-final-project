#include "ratings.h"
#include "Diary.h"
#include "Song.h"
#include "Sort.h"
#include "SongCollection.h"
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <limits>
#include <fstream>
#include <sstream>
#include <vector>

     void createDiary(int numSongs, int numArtists, int numAlbums, std::vector<Song>& diary) {
        // Initialize or reset the diary
        numSongs = 0;
        numArtists = 0;
        numAlbums = 0;
        diary.clear();
    }


    int Diary::getNumSongs() {
        return diary.size();
    }

    int Diary::getNumArtists() {
        return numArtists;
    }
    
    int Diary::getNumAlbums() {
        return numAlbums;
    }

    void Diary::viewDiary(SongCollection& collection) {
        std::cout << "===== DIARY =====" << std::endl;
        for (auto &song : diary) {
            std::cout << "Title: " << song.songName << ", Artist: " << song.artist << ", Album: " << song.albumName << std::endl;
        }
        std::cout << std::endl;
    }

    void Diary::addSong(SongCollection& collection){
        std::string songTitle;
        std::cout << "Enter the title of the song: ";
        // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, songTitle);

        auto& songs = collection.getSongs();
        bool found = false;
        for (const auto& song : songs) 
        {
            if (song.songName == songTitle) 
            {
                found = true;
                numSongs++;
                auto hello = Song(song.artist, song.albumName, song.songName, "PLACEHOLDER", "PLACEHOLDER"); // <---- Edit whatever here
                diary.push_back(hello);   
                std::cout << "Song: " << song.songName
                        << ", Album: " << song.albumName
                        << ", Artist: " << song.artist << std::endl;
                        
                std::cout << songTitle << " added to the diary!" << std::endl;
                break;
            }   
        }
         
        if (!found) {
            std::cout << "No songs found for : " << songTitle << std::endl;
        }
    }
    
    void Diary::saveToFile() const {
        std::ofstream file("diary.txt"); // "diary_bob.txt" --> "diary_" + username + ".txt", do the same for loadToFile()
    for (const auto& song : diary) {
        file << song.artist << ","
             << song.albumName << ","
             << song.songName << ","
             << song.popularity << ","
             << song.genre << std::endl;
    }
    file.close();
    }

    void Diary::loadFromFile() {
        std::ifstream file("diary.txt");
        std::string line;
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string artist, albumName, songName, popularity, genre;
            
            std::getline(ss, artist, ',');
            std::getline(ss, albumName, ',');
            std::getline(ss, songName, ',');
            std::getline(ss, popularity, ',');
            std::getline(ss, genre);
            
            Song song(artist, albumName, songName, popularity, genre);
            diary.push_back(song);
        }
        file.close();
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