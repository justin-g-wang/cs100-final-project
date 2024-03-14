#ifndef ratings_h
#define ratings_h
#include "Diary.h"



class Ratings {
    private:
        Diary diary;
        int songRating;
        int albumRating;
        int artistRating;
        int rating;

    public:
        //void setRating(int rating);
        //void getRating();
        void setSongRating(SongCollection& collection, std::vector<Song>& Diary);
        void setAlbumRating(SongCollection& collection,std::vector<Song>& Diary);
        void setArtistRating(SongCollection& collection,std::vector<Song>& Diary);
        void getSongRating(SongCollection& collection, std::vector<Song>& Diary);
        void getAlbumRating(SongCollection& collection, std::vector<Song>& Diary);
        void getArtistsRating(SongCollection& collection,std::vector<Song>& Diary);
};

#endif //ratings_h