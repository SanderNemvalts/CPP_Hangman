set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Hangman-game src/main.cpp
        src/hangman.cpp
        include/hangman.h
        include/utils.h
        include/algorithm.h
        src/algorithm.cpp
)
