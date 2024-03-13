cmake_minimum_required(VERSION 3.0)
project(SoundNotes)

add_subdirectory(googletest)
enable_testing()

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(SongCollection main.cpp Song.cpp SongCollection.cpp Sort.cpp 
UserStorage.cpp UserAuthentication.cpp UserApplication.cpp UserProfile.cpp PasswordRecovery.cpp)

add_executable(googleTest UserLoginTesting.cpp UserStorage.cpp UserAuthentication.cpp UserApplication.cpp UserProfile.cpp PasswordRecovery.cpp)
target_link_libraries(googleTest gtest gtest_main)
add_test(NAME GoogleTest COMMAND googleTest)