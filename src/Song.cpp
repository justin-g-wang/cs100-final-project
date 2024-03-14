#include "../header/Song.h"

Song::Song(const std::string& artist, const std::string& albumName, const std::string& songName, const std::string& popularity, const std::string& genre, const std::string& rating)
    : artist(artist), albumName(albumName), songName(songName), popularity(popularity), genre(genre), rating(rating) {}
