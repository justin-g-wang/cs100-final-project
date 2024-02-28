cmake_minimum_required(VERSION 3.0)

project(SongCollection)

# Add all the source files needed to compile the executable
add_executable(SongCollection main.cpp Song.cpp SongCollection.cpp)

# If you have used any libraries, you need to link them as well
# target_link_libraries(SongCollection your_library)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)