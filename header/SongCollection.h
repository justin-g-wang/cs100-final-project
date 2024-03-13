#ifndef SONG_COLLECTION_H
#define SONG_COLLECTION_H

#include "Song.h" 
#include <vector>
#include <string>

class SongCollection 
{
private:

    std::vector<Song> songs;

public:

    void readSongsFromCSV(const std::string& filename);
    std::vector<Song>& getSongs();
  
};

#endif // SONG_COLLECTION_H