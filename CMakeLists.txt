cmake_minimum_required(VERSION 3.27)
project(leetcode)

set(CMAKE_CXX_STANDARD 20)

# Find all .cpp files in the directory (adjust the path if they are in a subfolder like 'src/')
file(GLOB CPP_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

foreach(CPP_FILE ${CPP_FILES})
    # Extract the file name without the extension (e.g., "main.cpp" becomes "main")
    get_filename_component(TARGET_NAME ${CPP_FILE} NAME_WE)
    
    # Create an executable target for each file
    add_executable(${TARGET_NAME} ${CPP_FILE})
endforeach()