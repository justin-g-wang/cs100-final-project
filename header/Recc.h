    #include "../header/SongCollection.h"

        class Recc
        {
        public:
            void ReccByArtist(SongCollection& collection);
            void ReccByAlbum(SongCollection& collection);
            void ReccBySong(SongCollection& collection);
            void ReccByPopularity(SongCollection& collection);
            void ReccByGenre(SongCollection& collection);
            void promptForRecc(SongCollection& collection);
        };
