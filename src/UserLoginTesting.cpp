#include "../header/UserApplication.h"
#include "../header/UserProfile.h"
#include "../header/UserStorage.h"
#include "../header/UserAuthentication.h"
#include "../header/PasswordRecovery.h"
#include "../header/ratings.h"
#include "../header/Diary.h"
#include <gtest/gtest.h>
#include <iostream>
#include <fstream>


TEST(UserProfileTest, getAndSetFirstName) 
{
    UserProfile user("John", "Doe", "1990-01-01");
    ASSERT_EQ(user.getFirstName(), "John");
    user.setFirstName("Jane");
    ASSERT_EQ(user.getFirstName(), "Jane");
}

TEST(UserProfileTest, getAndSetLastName) 
{
    UserProfile user("John", "Doe", "1990-01-01");
    ASSERT_EQ(user.getLastName(), "Doe");
    user.setLastName("Smith");
    ASSERT_EQ(user.getLastName(), "Smith");
}

TEST(UserProfileTest, getAndSetDateOfBirthName) 
{
    UserProfile user("John", "Doe", "1990-01-01");
    ASSERT_EQ(user.getDOB(), "1990-01-01");
    user.setDOB("1991-02-02");
    ASSERT_EQ(user.getDOB(), "1991-02-02");
}

TEST(UserStorageTest, SaveAndRetrieveUser) {
    UserStorage storage;
    UserProfile userProfile("Alice", "Wonderland", "2001-04-01");
    storage.saveUser("alice01", "password123", userProfile);

    ASSERT_TRUE(storage.userExists("alice01"));
    UserProfile retrievedProfile = storage.getUserProfile("alice01");
    ASSERT_EQ(retrievedProfile.getFirstName(), "Alice");
    ASSERT_EQ(retrievedProfile.getLastName(), "Wonderland");
    ASSERT_EQ(retrievedProfile.getDOB(), "2001-04-01");
}

TEST(UserAuthenticationTest, AuthenticateUser) {
    UserStorage storage;
    UserAuthentication auth(storage);
    UserProfile userProfile("Bob", "Builder", "1999-12-31");
    storage.saveUser("bob99", "securePass", userProfile);

    bool isAuthenticated = auth.authenticate("bob99", "securePass");
    ASSERT_TRUE(isAuthenticated);
}

TEST(UserApplicationTest, ValidatePassword) {
    UserApplication app;

    ASSERT_FALSE(app.isPasswordValid("short"));
    ASSERT_FALSE(app.isPasswordValid("longbutnonumbers"));
    ASSERT_TRUE(app.isPasswordValid("validPassword1"));
}

TEST(RatingsTest, SetAndGetSongRating) {
SongCollection collection;
Diary diary;
    Ratings ratings;
    collection.readSongsFromCSV("NoNumberingDataSet.csv"); 
    ASSERT_FALSE(collection.getSongs().empty()); 
    Song firstSong = collection.getSongs().front();
    diary.addSongDirectly(firstSong);
    int rating = 8; 
}

TEST(UserApplicationTest, ValidateDateOfBirth) {
    UserApplication app;

    ASSERT_FALSE(app.isDOBValid("199902"));
    ASSERT_FALSE(app.isDOBValid("99-02-02"));
    ASSERT_TRUE(app.isDOBValid("1999-02-02"));
}

TEST(UserAuthenticationTest, UnsuccessfulLogin) {
    UserStorage storage;
    UserAuthentication auth(storage);
    UserProfile userProfile("Eve", "Example", "1980-07-15");
    storage.saveUser("eve01", "password123", userProfile);
    bool isAuthenticated = auth.authenticate("eve01", "wrongPassword");
    ASSERT_FALSE(isAuthenticated);
}

TEST(UserStorageTest, DuplicateUserRegistration) {
    UserStorage storage;
    UserProfile initialProfile("Charlie", "Chaplin", "1889-04-16");
    storage.saveUser("charlie", "initialPass", initialProfile);

    UserProfile newProfile("Charlie", "Chaplin", "2000-01-01"); 
    storage.saveUser("charlie", "newPass", newProfile);
    UserProfile storedProfile = storage.getUserProfile("charlie");
    ASSERT_EQ(storedProfile.getFirstName(), initialProfile.getFirstName());
    ASSERT_EQ(storedProfile.getLastName(), initialProfile.getLastName());
    ASSERT_EQ(storedProfile.getDOB(), initialProfile.getDOB());
}
TEST(UserStorageTest, UpdateUserPasswordAndCheckIfOldFails) {
    UserStorage storage;
    UserProfile userProfile("Dave", "Developer", "1995-03-12");
    storage.saveUser("daveDev", "oldPassword", userProfile);

    storage.updateUserPassword("daveDev", "newSecurePassword");
    UserAuthentication auth(storage);
    ASSERT_FALSE(auth.authenticate("daveDev", "oldPassword"));
    ASSERT_TRUE(auth.authenticate("daveDev", "newSecurePassword"));
}

TEST(UserStorageTest, UpdatePassword) {
    UserStorage storage;
    storage.saveUser("user3", "oldPassword", UserProfile("User", "Three", "1993-03-03"));
    storage.updateUserPassword("user3", "newPassword");
    UserAuthentication auth(storage);
    ASSERT_TRUE(auth.authenticate("user3", "newPassword"));
    ASSERT_FALSE(auth.authenticate("user3", "oldPassword"));
}

TEST(UserStorageTest, RetrieveUserProfile) {
    UserStorage storage;
    UserProfile expectedProfile("User", "Four", "1994-04-04");
    storage.saveUser("user4", "password4", expectedProfile);
    UserProfile actualProfile = storage.getUserProfile("user4");
    ASSERT_EQ(actualProfile.getFirstName(), expectedProfile.getFirstName());
    ASSERT_EQ(actualProfile.getLastName(), expectedProfile.getLastName());
    ASSERT_EQ(actualProfile.getDOB(), expectedProfile.getDOB());
}
TEST(UserStorageTest, RegisterNewUser) {
    UserStorage storage;
    storage.saveUser("newUser", "password123", UserProfile("Test", "User", "2000-01-01"));
    ASSERT_TRUE(storage.userExists("newUser"));
}

TEST(UserStorageTest, UserExistsAfterRegistration) {
    UserStorage storage;
    UserProfile userProfile("Alice", "Example", "1995-05-05");
    storage.saveUser("alice", "password", userProfile);
    ASSERT_TRUE(storage.userExists("alice"));
}

TEST(UserAuthenticationTest, ValidateUserWithCorrectCredentials) {
    UserStorage storage;
    UserAuthentication auth(storage);
    storage.saveUser("bob", "12345", UserProfile("Bob", "Builder", "1990-01-01"));
    ASSERT_TRUE(storage.validateUser("bob", "12345"));
}

TEST(UserAuthenticationTest, InvalidateUserWithIncorrectCredentials) {
    UserStorage storage;
    UserAuthentication auth(storage);
    storage.saveUser("eve", "abcde", UserProfile("Eve", "Example", "1992-02-02"));
    ASSERT_FALSE(storage.validateUser("eve", "wrongpassword"));
}

TEST(DiaryTest, AddAndRetrieveSongs) {
    SongCollection collection;
    Diary diary;
    collection.readSongsFromCSV("NoNumberingDataSet.csv"); 
    ASSERT_FALSE(collection.getSongs().empty()); 
    Song firstSong = collection.getSongs().front();
    diary.addSongDirectly(firstSong);
    ASSERT_EQ(diary.getNumSongs(), 1);
    std::vector<Song> songsInDiary = diary.getDiary();
    ASSERT_EQ(songsInDiary.front().songName, firstSong.songName); 
    
}

TEST(DiaryTest, AddAlbum) {
    SongCollection collection;
    Diary diary;
    collection.readSongsFromCSV("NoNumberingDataSet.csv"); 

    ASSERT_FALSE(collection.getSongs().empty());
    std::string targetAlbumName = collection.getSongs().front().albumName;
    std::vector<Song> songsInTargetAlbum;
    for (const auto& song : collection.getSongs()) {
        if (song.albumName == targetAlbumName) {
            songsInTargetAlbum.push_back(song);
        }
    }

    ASSERT_FALSE(songsInTargetAlbum.empty());
}

TEST(DiaryTest, RemoveSong) {
    SongCollection collection;
    Diary diary;
    collection.readSongsFromCSV("NoNumberingDataSet.csv");
    ASSERT_FALSE(collection.getSongs().empty());
    Song firstSong = collection.getSongs().front();
    diary.addSongDirectly(firstSong);
    ASSERT_EQ(diary.getNumSongs(), 1);
    diary.removeSongDirectly(firstSong.songName);
    ASSERT_EQ(diary.getNumSongs(), 0);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
