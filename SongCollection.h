#include "Song.h" 
#include <vector>
#include <string>

class SongCollection {
private:

    std::vector<Song> songs;

public:
    void readSongsFromCSV(const std::string& filename);
    void sortByArtist();
    void sortByAlbumName();
    void sortBySongName();
    void sortByPopularity();
    void sortByGenre();
    void printSongs() const;
};