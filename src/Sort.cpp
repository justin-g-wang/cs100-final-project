#include "../header/Sort.h"
#include "../header/SongCollection.h"
#include "../header/Diary.h"
#include "../header/ratings.h"
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <limits>



void Sort::promptAndSort(SongCollection& collection, const std::string& username) 
{
    std::string userChoice;
    bool isValidChoice = false;
    Diary myDiary;
    Ratings ratings;
    myDiary.loadFromFile(username);
    

        // while (!isValidChoice) {
        while (true) {
            std::cout << "Enter your choice for sorting: \n"
                      << "1. Artist\n"
                      << "2. Album Name\n"
                      << "3. Song Name\n"
                      << "4. Popularity\n"
                      << "5. Genre\n"
                      << "6. Quit\n";
            std::cin >> userChoice;
            
             if (userChoice == "6") {
                myDiary.saveToFile(username);
                break;
            }

            std::transform(userChoice.begin(), userChoice.end(), userChoice.begin(), ::tolower);

            if (userChoice == "1" || userChoice == "artist") {
                sortByArtist(collection);
                isValidChoice = true;
            } else if (userChoice == "2" || userChoice == "album name") {
                sortByAlbumName(collection);
                isValidChoice = true;
            } else if (userChoice == "3" || userChoice == "song name") {
                sortBySongName(collection);
                isValidChoice = true;
            } else if (userChoice == "4" || userChoice == "popularity") {
                sortByPopularity(collection);
                isValidChoice = true;
            }
            else if (userChoice == "5" || userChoice == "genre") {
                sortByGenre(collection);
                isValidChoice = true;
                myDiary.addSong(collection);
                myDiary.viewDiary(collection);
                ratings.setSongRating(collection, myDiary.getDiary());
            } else {
                std::cerr << "Invalid choice. Please try again." << std::endl;
            }

        }

        myDiary.saveToFile(username);
    }



  void Sort::sortByArtist(SongCollection& collection) 
  {
    std::string inputArtist;
    std::cout << "Sorting by Artist" << std::endl;
    std::cout << "Enter An Artist: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, inputArtist); 

    auto& songs = collection.getSongs();
    bool found = false;
    for (const auto& song : songs) 
    {
        if (song.artist == inputArtist) 
        {
            found = true;
            std::cout << "Artist: " << song.artist
                      << ", Album: " << song.albumName
                      << ", Song: " << song.songName
                      << ", Popularity: " << song.popularity
                      << ", Genre: " << song.genre << std::endl;
        }
    }

    if (!found) {
        std::cout << "No songs found for artist: " << inputArtist << std::endl;
    }
}
void Sort::sortByAlbumName(SongCollection& collection) {
    std::string albumName;
    std::cout << "Sorting by Album Name" << std::endl;
    std::cout << "Enter An Album Name: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, albumName);

    auto& songs = collection.getSongs();
    bool found = false;
    for (const auto& song : songs) 
    {
        if (song.albumName == albumName) 
        {
            found = true;
            std::cout << "Artist: " << song.artist
                      << ", Album: " << song.albumName
                      << ", Song: " << song.songName
                      << ", Popularity: " << song.popularity
                      << ", Genre: " << song.genre << std::endl;
        }
    }

    if (!found) {
        std::cout << "No songs found for album: " << albumName << std::endl;
    }
}

void Sort::sortBySongName(SongCollection& collection) 
{
    std::string songName ;
    std::cout << "Sorting by Song Name" << std::endl;
     std::cout << "Enter A Song Name: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, songName); 

    auto& songs = collection.getSongs();
    bool found = false;
    for (const auto& song : songs) 
    {
        if (song.songName == songName) 
        {
            found = true;
            std::cout << "Artist: " << song.artist
                      << ", Album: " << song.albumName
                      << ", Song: " << song.songName
                      << ", Popularity: " << song.popularity
                      << ", Genre: " << song.genre << std::endl;
        }
    }

    if (!found) {
        std::cout << "No songs found for name: " << songName << std::endl;
    }
}

void Sort::sortByPopularity(SongCollection& collection) 
{
    std::string PopularityInt;
    std::cout << "Sorting by Popularity" << std::endl;
    std::cout << "Enter A Popularity (from 0 - 75): ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, PopularityInt);

    auto& songs = collection.getSongs();
    bool found = false;

    for (const auto& song : songs) 
    {

        if (song.popularity == PopularityInt) 
        {
            found = true;
            std::cout << "Artist: " << song.artist
                      << ", Album: " << song.albumName
                      << ", Song: " << song.songName
                      << ", Popularity: " << song.popularity
                      << ", Genre: " << song.genre << std::endl;
        }
    }

    if (!found) {
        std::cout << "No songs found for popularity: " << PopularityInt << std::endl;
    }
}

void Sort::sortByGenre(SongCollection& collection) 
{   
    std::string genre ;
    std::cout << "Sorting by Genre" << std::endl;
    std::cout << "Enter A Genre: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, genre); 

    auto& songs = collection.getSongs();
    bool found = false;
    int counter = 0;
    for (const auto& song : songs) 
    {

        if (song.genre == genre + "\r")
        {
            found = true;
            std::cout << "Artist: " << song.artist
                      << ", Album: " << song.albumName
                      << ", Song: " << song.songName
                      << ", Popularity: " << song.popularity
                      << ", Genre: " << song.genre << std::endl;
        }
    }

    if (!found) {
        std::cout << "No songs found for Genre: " << genre << std::endl;
    }
}
