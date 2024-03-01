#ifndef ratings_h
#define ratings_h



class Ratings {
    private:
        int songRating;
        int albumRating;
        int artistRating;

    public:
        void setSongRating();
        void setAlbumRating();
        void setArtistRating();
        void getSongRating();
        void getAlbumRating();
        void getArtistsRating();
}

#endif //ratings_h