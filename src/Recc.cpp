#include "../header/Recc.h"
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <limits>

void Recc::promptForRecc(SongCollection& collection)
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
                ReccByArtist(collection);
                isValidChoice = true;
            } else if (userChoice == "2" || userChoice == "album name") {
                ReccByAlbum(collection);
                isValidChoice = true;
            } else if (userChoice == "3" || userChoice == "song name") {
                ReccBySong(collection);
                isValidChoice = true;
            } else if (userChoice == "4" || userChoice == "popularity") {
                ReccByPopularity(collection);
                isValidChoice = true;
            } else if (userChoice == "5" || userChoice == "genre") {
                ReccByGenre(collection);
                isValidChoice = true;
            } else {
                std::cerr << "Invalid choice. Please try again." << std::endl;
            }
        }
    }
