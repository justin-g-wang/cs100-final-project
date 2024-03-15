#include "../header/ratings.h"
#include "../header/Diary.h"
#include "../header/Song.h"
#include "../header/Sort.h"
#include "../header/SongCollection.h"
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
            std::cout << "Title: " << song.songName << ", Artist: " << song.artist << ", Album: " << song.albumName << ", Rating: " << song.rating << std::endl;
        }
        std::cout << std::endl;
    }

    std::vector<Song>& Diary::getDiary(){
        return diary;
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
                auto hello = Song(song.artist, song.albumName, song.songName, song.genre, "", ""); // <---- Edit whatever here
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
        // askForUserLogin userLogin;
        // std::string username = userLogin.getUsername();
        std::ofstream file("diary.txt"); // "diary_bob.txt" --> "diary_" + username + ".txt", do the same for loadToFile()
    for (const auto& song : diary) {
        file << song.artist << ","
             << song.albumName << ","
             << song.songName << ","
             << song.popularity << ","
             << song.genre << ","
             << song.rating << std::endl;
    }
    file.close();
    }

    void Diary::loadFromFile() {
        std::ifstream file("diary.txt");
        std::string line;
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string artist, albumName, songName, popularity, genre, rating;
            
            std::getline(ss, artist, ',');
            std::getline(ss, albumName, ',');
            std::getline(ss, songName, ',');
            std::getline(ss, popularity, ',');
            std::getline(ss, genre, ',');
            std::getline(ss, rating);
            
            Song song(artist, albumName, songName, popularity, genre, rating);
            diary.push_back(song);
        }
        file.close();
    }


    void Diary::addAlbum(SongCollection& collection){
        std::string albumTitle;
        std::cout << "Enter the title of the Album: ";
        // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, albumTitle);

        auto& songs = collection.getSongs();
        bool found = false;
        for (const auto& song : songs) 
        {
            if (song.albumName == albumTitle) 
            {
                found = true;
                numAlbums++;
                auto hello = Song(song.artist, song.albumName, "", "", "",""); // <---- Edit whatever here
                diary.push_back(hello);   
                std::cout << ", Album: " << song.albumName << std::endl;
                        
                std::cout << albumTitle << " added to the diary!" << std::endl;
                break;
            }   
        }
         
        if (!found) {
            std::cout << "No albums found for : " << albumTitle << std::endl;
        }
    }
    
    
    void Diary::addArtist(SongCollection& collection){
        std::string artistName;
        std::cout << "Enter the name of the Artist: ";
        // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, artistName);

        auto& songs = collection.getSongs();
        bool found = false;
        for (const auto& song : songs) 
        {
            if (song.artist == artistName) 
            {
                found = true;
                numAlbums++;
                auto hello = Song(song.artist, "", "", "", "", ""); // <---- Edit whatever here
                diary.push_back(hello);   
                std::cout << ", Artist: " << song.artist << std::endl;
                        
                std::cout << artistName << " added to the diary!" << std::endl;
                break;
            }   
        }
         
        if (!found) {
            std::cout << "No albums found for : " << artistName << std::endl;
        }
    }

    void Diary::removeSong(SongCollection& collection){
        std::string songTitle;
        std::cout << "Enter the title of the song to remove: ";
        std::getline(std::cin, songTitle);

    // Iterate through the diary and remove the song if found
        auto it = std::remove_if(diary.begin(), diary.end(), [&](const Song& song) {
            return song.songName == songTitle;
        });

        // If song is found and removed, update counters
        if (it != diary.end()) {
            diary.erase(it, diary.end());
            numSongs--;
            std::cout << "Song \"" << songTitle << "\" removed from diary." << std::endl;
        } else {
            std::cout << "Song \"" << songTitle << "\" not found in diary." << std::endl;
        }
        }
    void Diary::removeAlbum(SongCollection& collection){
    std::string albumTitle;
    std::cout << "Enter the title of the album to remove: ";
    std::getline(std::cin, albumTitle);

    // Iterate through the diary and remove songs belonging to the album
    auto it = std::remove_if(diary.begin(), diary.end(), [&](const Song& song) {
        return song.albumName == albumTitle;
    });

    // If songs are found and removed, update counters
    if (it != diary.end()) {
        diary.erase(it, diary.end());
        numAlbums--;
        std::cout << "Album \"" << albumTitle << "\" removed from diary." << std::endl;
    } else {
        std::cout << "Album \"" << albumTitle << "\" not found in diary." << std::endl;
    }
}
    void Diary::removeArtist(SongCollection& collection){
    std::string artistName;
    std::cout << "Enter the name of the artist to remove: ";
    std::getline(std::cin, artistName);

    // Iterate through the diary and remove songs belonging to the artist
    auto it = std::remove_if(diary.begin(), diary.end(), [&](const Song& song) {
        return song.artist == artistName;
    });

    // If songs are found and removed, update counters
    if (it != diary.end()) {
        diary.erase(it, diary.end());
        numArtists--;
        std::cout << "Artist \"" << artistName << "\" removed from diary." << std::endl;
    } else {
        std::cout << "Artist \"" << artistName << "\" not found in diary." << std::endl;
    }
    }

    std::vector<Song>& getDiarySongs() {
        return diary;
    }
