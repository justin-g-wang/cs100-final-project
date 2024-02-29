#include "Sort.h"
#include <iostream>
#include <algorithm>
#include <limits>


void Sort::promptAndSort(SongCollection& collection) 
{
    int userChoice;
    std::cout << "Enter your choice for sorting: \n"
              << "1. Artist\n"
              << "2. Album Name\n"
              << "3. Song Name\n"
              << "4. Popularity\n"
              << "5. Genre\n";
    std::cin >> userChoice;

    switch(userChoice) {
        case 1: sortByArtist(collection); 
        break;
        case 2: sortByAlbumName(collection);
         break;
        case 3: sortBySongName(collection); 
        break;
        case 4: sortByPopularity(collection); 
        break;
        case 5: sortByGenre(collection); 
        break;
        default: std::cerr << "Invalid choice" << std::endl;
    }
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
void Sort::sortByAlbumName(SongCollection& collection) 
{
    std::cout << "Sorting by Album Name" << std::endl;
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
        std::cout << "No songs found for artist: " << songName << std::endl;
    }
}


void Sort::sortByPopularity(SongCollection& collection) 
{
    std::cout << "Sorting by Popularity" << std::endl;
}

void Sort::sortByGenre(SongCollection& collection) 
{
    std::cout << "Sorting by Genre" << std::endl;
}