#ifndef SONG_H
#define SONG_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

struct Song 
{

    
    std::string artist;
    std::string albumName;
    std::string songName;
    std::string popularity; 
    std::string genre;
    std::string rating;

    Song(const std::string& artist, const std::string& albumName, const std::string& songName, const std::string& popularity, const std::string& genre , const std::string& rating);
};


#endif // SONG_H