//
// Created by Sander Nemvalts on 30.04.2026.
//

#include <fstream>
#include <filesystem>
#include <iostream>
#include <cmath>

#include "../include/algorithm.h"
#include "../include/utils.h"

arvaja::arvaja() {
    std::filesystem::path path = "../data/sonad.txt";
    std::ifstream file(path);
    std::string word;
    while (file >> word) words.push_back(word);
}

void arvaja::addGuess(const char guess) {
    guessed.push_back(guess);
}

void arvaja::filterLen(const size_t len) {
    std::vector<std::string> newWords{};
    for (auto it{words.begin()}; it != words.end(); ++it) {
        if (it->length() == len) newWords.push_back(*it);
    }
    words = newWords;
}

void arvaja::filterLetter(const char letter, const size_t pos) {
    std::vector<std::string> newWords{};
    for (auto it{words.begin()}; it != words.end(); ++it) {
        if ((*it)[pos] == letter) newWords.push_back(*it);
    }
    words = newWords;
}

std::map<char, size_t> arvaja::letterFrequency() {
    std::map<char, size_t> letterFreqMap{};
    for (auto it{words.begin()}; it != words.end(); ++it) {
        std::vector<char> found{};
        for (size_t i{0}; i < it->length(); ++i) {
            if (std::find(found.begin(), found.end(), (*it)[i]) == found.end()) {
                ++letterFreqMap[(*it)[i]];
                found.push_back((*it)[i]);
            }
        }
    }
    return letterFreqMap;
}

char arvaja::arva() {
    char best{};
    int bestFreq{-1};
    size_t medianFreq{(size_t)ceil(words.size() / 2)};
    std::map<char, size_t> letterFreqMap = letterFrequency();

    std::cout << letterFreqMap << "\n";

    for (auto it{letterFreqMap.begin()}; it != letterFreqMap.end(); ++it) {
        if (bestFreq == -1 ||
            (std::find(guessed.begin(), guessed.end(), it->first) == guessed.end() &&
            abs((int)medianFreq - bestFreq) >= abs((int)it->second - bestFreq))) {
            best = it->first;
            bestFreq = it->second;
        }
        if (words.size() == 1) {
            std::cout << "\tSõna on \"" << words[0] << "\"\n";
            return '.';
        }

    }
    std::cout << "\tParim valik on \"" << best << "\"" << "\n";
    return best;
}

void arvaja::handleNewMap(std::map<size_t, char>& newMap) {
    if (arvatud_map.size() == newMap.size()) return;
    for (auto it{newMap.begin()}; it != newMap.end(); ++it) {
        if (std::find(arvatud_map.begin(), arvatud_map.end(), *it) == arvatud_map.end()) {
            filterLetter(it->second, it->first);
        }
    }
}

