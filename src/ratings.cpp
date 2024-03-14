#include "../header/ratings.h"
#include "../header/Diary.h"
#include "../header/Song.h"
#include "../header/SongCollection.h"
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <limits>
#include <fstream>
#include <sstream>
#include <vector>

/*void Ratings::setRating(int rating) {
    std::string songTitle;
    int rating;
    std::cout << "Enter the title of the song to set rating: ";
    std::getline(std::cin, songTitle);

    // Prompt the user to enter the rating
    std::cout << "Enter the rating for the song (1-10): ";
    std::cin >> rating;

    // Clear the input buffer
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Find the song in the diary and set its rating
    bool found = false;
    auto& diarySongs = diary.getDiary();
    for (auto& song : diarySongs) {
        if (song.songName == songTitle) {
            found = true;
            setRating(rating);
            std::cout << "Rating for song \"" << songTitle << "\" set to " << rating << std::endl;
            break;
        }
    }

    if (!found) {
        std::cout << "Song \"" << songTitle << "\" not found in the diary." << std::endl;
    }
}

void Ratings::getRating() {
    std::string songTitle;
    std::cout << "Enter the title of the song to get rating: ";
    std::getline(std::cin, songTitle);

    // Find the song in the diary and get its rating
    bool found = false;
    for (const auto& songRatingPair : ) {
        if (songRatingPair.first == songTitle) {
            found = true;
            std::cout << "Rating for song \"" << songTitle << "\" is: " << songRatingPair.second << std::endl;
            break;
        }
    }

    if (!found) {
        std::cout << "Song \"" << songTitle << "\" not found in the diary." << std::endl;
    }
} */

void Ratings::setSongRating(SongCollection& collection, std::vector<Song>& Diary) {
    std::string songTitle;
    int rating;
    std::cout << "Enter the title of the song to rate: ";
    std::getline(std::cin, songTitle);

    // Find the song in the diary and set its rating
    std::vector<Song>& diarySongs = Diary;
    bool found = false;
    for (auto& song : diarySongs) {
        if (song.songName == songTitle) {
            found = true;
            std::cout << "Enter the rating for the song (1-10): ";
            std::cin >> rating;
            //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
            song.rating = std::to_string(rating); // Update the rating directly in the Song object
            std::cout << "Rating for song \"" << songTitle << "\" set to " << rating << std::endl;
            break;
        }
    }

    if (!found) {
        std::cout << "Song \"" << songTitle << "\" not found in the diary." << std::endl;
    }
}

void Ratings::setAlbumRating(SongCollection& collection,std::vector<Song>& Diary) {
    std::string albumTitle;
    int rating;
    std::cout << "Enter the title of the album to rate: ";
    std::getline(std::cin, albumTitle);

    // Find all songs in the diary belonging to the album and set their ratings
    std::vector<Song>& diarySongs = Diary;
    bool found = false;
    for (auto& song : diarySongs) {
        if (song.albumName == albumTitle) {
            found = true;
            std::cout << "Enter the rating for the album (1-10): ";
            std::cin >> rating;
            //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
            song.rating = std::to_string(rating); // Update the rating directly in the Song object
        }
    }

    if (!found) {
        std::cout << "Album \"" << albumTitle << "\" not found in the diary." << std::endl;
    }
}

void Ratings::setArtistRating(SongCollection& collection,std::vector<Song>& Diary) {
    std::string artistName;
    int rating;
    std::cout << "Enter the name of the artist to rate: ";
    std::getline(std::cin, artistName);

    // Find all songs in the diary belonging to the artist and set their ratings
    std::vector<Song>& diarySongs = Diary;
    bool found = false;
    for (auto& song : diarySongs) {
        if (song.artist == artistName) {
            found = true;
            std::cout << "Enter the rating for the artist (1-10): ";
            std::cin >> rating;
            //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
            song.rating = std::to_string(rating); // Update the rating directly in the Song object
        }
    }

    if (!found) {
        std::cout << "Artist \"" << artistName << "\" not found in the diary." << std::endl;
    }
}

void Ratings::getSongRating(SongCollection& collection, std::vector<Song>& Diary) {
    std::string songTitle;
    std::cout << "Enter the title of the song to get rating: ";
    std::getline(std::cin, songTitle);

    // Find the song in the diary and get its rating
    const std::vector<Song>& diarySongs = Diary;
    bool found = false;
    for (const auto& song : diarySongs) {
        if (song.songName == songTitle) {
            found = true;
            std::cout << "Rating for song \"" << songTitle << "\" is: " << song.rating << std::endl;
            break;
        }
    }

    if (!found) {
        std::cout << "Song \"" << songTitle << "\" not found in the diary." << std::endl;
    }
}

void Ratings::getAlbumRating(SongCollection& collection, std::vector<Song>& Diary) {
    std::string albumTitle;
    std::cout << "Enter the Album name to get rating: ";
    std::getline(std::cin, albumTitle);

    // Find the song in the diary and get its rating
    const std::vector<Song>& diarySongs = Diary;
    bool found = false;
    for (const auto& song : diarySongs) {
        if (song.songName == albumTitle) {
            found = true;
            std::cout << "Rating for album \"" << albumTitle << "\" is: " << song.rating << std::endl;
            break;
        }
    }

    if (!found) {
        std::cout << "Album \"" << albumTitle << "\" not found in the diary." << std::endl;
    }
}

void Ratings::getArtistsRating(SongCollection& collection, std::vector<Song>& Diary) {
    std::string artistName;
    std::cout << "Enter the title of the song to get rating: ";
    std::getline(std::cin, artistName);

    // Find the song in the diary and get its rating
    const std::vector<Song>& diarySongs = Diary;
    bool found = false;
    for (const auto& song : diarySongs) {
        if (song.songName == artistName) {
            found = true;
            std::cout << "Rating for artist \"" << artistName << "\" is: " << song.rating << std::endl;
            break;
        }
    }

    if (!found) {
        std::cout << "Artist \"" << artistName << "\" not found in the diary." << std::endl;
    }
}
