cmake_minimum_required(VERSION 3.15)
project(stlab-playground)

include(CTest)

############# CPM #############

# https://github.com/cpm-cmake/CPM.cmake

# Enable CPM caching to avoid re-downloading dependencies
set(CPM_SOURCE_CACHE ${CMAKE_SOURCE_DIR}/.cache/cpm CACHE PATH "Directory to cache CPM packages" FORCE)

include(cmake/CPM.cmake)

###############################

# Set C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Dependencies
CPMAddPackage("gh:stlab/libraries@2.1.3")

# clangd support

if(CMAKE_EXPORT_COMPILE_COMMANDS)
    add_custom_target(clangd_compile_commands ALL
        COMMAND ${CMAKE_COMMAND} -E create_symlink 
            ${CMAKE_BINARY_DIR}/compile_commands.json
            ${CMAKE_SOURCE_DIR}/compile_commands.json
        COMMENT "Creating symlink to compile_commands.json for clangd"
    )
endif()

# Function to add a test executable with all necessary setup
function(add_test_executable NAME)
    add_executable(${NAME} src/${NAME}.cpp)
    add_test(NAME ${NAME} COMMAND ${NAME})
    target_link_libraries(${NAME} PRIVATE stlab)
endfunction()

# Add test executables
add_test_executable(000-future)
add_test_executable(060-copy-on-write)
