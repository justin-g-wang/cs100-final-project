#include "../header/Recc.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <algorithm>
#include <limits>

using namespace std;

void Recc::saveToFile() const {
        std::ofstream file("recc.txt");
    for (const auto& song : recc) {
        file << song.artist << ","
             << song.albumName << ","
             << song.songName << ","
             << song.popularity << ","
             << song.genre << ","
             << song.rating << std::endl;
    }
    file.close();
    }

void Recc::loadFromFile() {
    std::ifstream file("recc.txt");
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string artist, albumName, songName, popularity, genre, rating;
            
        std::getline(ss, artist, ',');
        std::getline(ss, albumName, ',');
        std::getline(ss, songName, ',');
        std::getline(ss, popularity, ',');
        std::getline(ss, genre, ',');
        std::getline(ss, rating);
                        Song song(artist, albumName, songName, popularity, genre, rating);
        recc.push_back(song);
    }
    file.close();
    }


void Recc::viewRecc(SongCollection& collection) {
        std::cout << "===== Reccomendations =====" << std::endl;
        for (auto &song : recc) {
            std::cout << "Title: " << song.songName << ", Artist: " << song.artist << ", Album: " << song.albumName << std::endl;
        }
        std::cout << std::endl;
    }

std::vector<Song>& Recc::getRecc(){
        return recc;
    }

void Recc::addSong(const Song userSong) {
    recc.push_back(userSong);
}

void Recc::ReccBySong(SongCollection& collection, Diary& userDiary) {
    // first, its gonna go through the diary vector and stop everytime it finds a song rated at 8 or higher
    // then, everytime it stops, its going to look at the genre of the song
    // then, its gonna iterate through the RECC Vector (formerly a copy of the whole collection) and find a song with that same genre
    // then it will output the first 5 results.
    // Everytime, it will delete that song from the collection (no repeat recommendations)
    // then it will add the recommendations to a new vector of recommended music
    // "Enter (L) to load more recommendations, otherwise press (Q) to quit."

    cout << "Recommending by Song Name." << endl;
    std::cout << "Enter a Rating level (1 - 10): ";
    string ratingLevel;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, ratingLevel); 

    auto& allSongs = collection.getSongs();
    auto& diarySongs = userDiary.getDiary();
    bool found = false;

    for (const auto& song : diarySongs) 
    {
        if (song.rating == ratingLevel) {
            found = true;
            string tempGenre = "";
            tempGenre = song.genre;
            int reccCounter = 0;

            for (const auto& song : allSongs) 
            {
                if (song.genre == tempGenre + "\r") {
                    if (reccCounter < 5) {
                        addSong(song);
                        ++reccCounter;
                        std::cout << "Artist: " << song.artist
                        << ", Album: " << song.albumName
                        << ", Song: " << song.songName << std::endl;
                    }
                    else if (reccCounter == 5) {
                        cout << "\n" << "Enter (L) to load more recommendations, otherwise press (Q) to quit." << endl;
                        string userKey;
                        std::getline(std::cin, userKey);

                        if (userKey == "L") {
                            reccCounter = 0;
                        }
                        else if (userKey == "Q") {
                            break;
                        } 
                    }
                }
            }
        }
    }
}


void Recc::promptForRecc(SongCollection& collection, Diary& userDiary, std::vector<Song>& recc)
{
    std::string userChoice;
    bool isValidChoice = false;

        while (!isValidChoice) {
            std::cout << "Enter your choice for Recommending: \n"
                      << "1. Artist\n"
                      << "2. Album Name\n"
                      << "3. Song Name\n"
                      << "4. Popularity\n"
                      << "5. Genre\n";
            std::cin >> userChoice;
            std::transform(userChoice.begin(), userChoice.end(), userChoice.begin(), ::tolower);

            if (userChoice == "1" || userChoice == "artist") {
                //ReccByArtist(collection);
                isValidChoice = true;
            } else if (userChoice == "2" || userChoice == "album name") {
                //ReccByAlbum(collection);
                isValidChoice = true;
            } else if (userChoice == "3" || userChoice == "song name") {
                ReccBySong(collection, userDiary);
                isValidChoice = true;
            } else if (userChoice == "4" || userChoice == "popularity") {
                //ReccByPopularity(collection);
                isValidChoice = true;
            } else if (userChoice == "5" || userChoice == "genre") {
                //ReccByGenre(collection);
                isValidChoice = true;
            } else {
                std::cerr << "Invalid choice. Please try again." << std::endl;
            }
        }
    }

