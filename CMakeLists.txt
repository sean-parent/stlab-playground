cmake_minimum_required(VERSION 3.15)
project(stlab-playground)

# Enable testing for this project
include(CTest)
enable_testing()

############# CPM #############

file(
  DOWNLOAD
  https://github.com/cpm-cmake/CPM.cmake/releases/download/v0.40.8/CPM.cmake
  ${CMAKE_CURRENT_BINARY_DIR}/cmake/CPM.cmake
  EXPECTED_HASH SHA256=78ba32abdf798bc616bab7c73aac32a17bbd7b06ad9e26a6add69de8f3ae4791
)
include(${CMAKE_CURRENT_BINARY_DIR}/cmake/CPM.cmake)

# Enable CPM caching to avoid re-downloading dependencies
set(CPM_SOURCE_CACHE ${CMAKE_SOURCE_DIR}/.cpm-cache CACHE PATH "Directory to cache CPM packages" FORCE)

###############################

CPMAddPackage("gh:stlab/libraries#main")

# Set C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define ADOBE_STD_SERIALIZATION for all builds
add_compile_definitions(ADOBE_STD_SERIALIZATION)

# Function to add a test executable with all necessary setup
function(add_test_executable NAME)
    add_executable(${NAME} src/${NAME}.cpp)
    add_test(NAME ${NAME} COMMAND ${NAME})
    target_link_libraries(${NAME} PRIVATE stlab)
endfunction()

# Add test executables
add_test_executable(000-future)
add_test_executable(060-copy-on-write)
