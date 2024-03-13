cmake_minimum_required(VERSION 3.0)
project(SoundNotes)

add_subdirectory(googletest)
enable_testing()

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(SongCollection src/main.cpp src/Song.cpp src/SongCollection.cpp src/Sort.cpp 
src/UserStorage.cpp src/UserAuthentication.cpp src/UserApplication.cpp src/UserProfile.cpp src/PasswordRecovery.cpp src/Diary.cpp src/ratings.cpp) 

add_executable(googleTest src/UserLoginTesting.cpp src/UserStorage.cpp src/UserAuthentication.cpp src/UserApplication.cpp 
src/UserProfile.cpp src/PasswordRecovery.cpp)

target_link_libraries(googleTest gtest gtest_main)
add_test(NAME GoogleTest COMMAND googleTest)