//
// Created by Sander Nemvalts on 30.04.2026.
//

#ifndef CPP_HANGMAN_ALGORITHM_H
#define CPP_HANGMAN_ALGORITHM_H

#include <vector>
#include <map>

class arvaja {
private:
    std::vector<std::string> words;
    std::map<size_t, char> arvatud_map{};
    std::vector<char> guessed{};
public:
    arvaja();
    void filterLen(size_t);
    void filterLetter(char, size_t);
    std::map<char, size_t> letterFrequency();
    char arva();
    void addGuess(char);
    void handleNewMap(std::map<size_t, char>&);
};

#endif //CPP_HANGMAN_ALGORITHM_H