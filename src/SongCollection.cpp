#include "../header/SongCollection.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iostream>


// Reads The Song From A Vector And Puts It Into The Song Vector
void SongCollection::readSongsFromCSV(const std::string& filename) 
{
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed To Open File: " << filename << std::endl;
        return;
    }

    std::string line;
   // Skip Header Of CSV File
    std::getline(file, line);

    while (std::getline(file, line)) 
    {
        std::stringstream in(line);
        std::string artist, albumName, songName, genre, popularity;
        std::getline(in, artist, ',');
        std::getline(in, albumName, ',');
        std::getline(in, songName, ',');
        std::getline(in, popularity, ',');
        std::getline(in, genre);
            

        songs.emplace_back(artist, albumName, songName, popularity, genre, "");
    }
}

std::vector<Song>& SongCollection::getSongs() 
{
    return songs;
}