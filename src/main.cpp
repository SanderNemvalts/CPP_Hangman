//
// Created by Sander Nemvalts on 24.04.2026.
//

#include <iostream>
#include <fstream>
#include <filesystem>
#include <__chrono/file_clock.h>

#include "../include/hangman.h"
#include "../include/algorithm.h"
#include "../include/utils.h"

int main() {
    std::filesystem::path path = "../data/sonad.txt";
    std::ifstream file(path);
    size_t current{0};
    size_t linenr{14392}; //placeholder
    std::string word;
    while (current < linenr && getline(file, word)) ++current;

    std::cout << word << "\n";
    hangman mang = hangman(word);
    std::cout << "Mäng:\n\tTervitused palun hakka arvama sõna: " << std::endl;
    std::map<size_t, char> arvatud_map{};

    arvaja arvaja{};
    arvaja.filterLen(mang.sonaPikkus());

    while (true) {
        mang.esita();
        std::cout << "\n";

        std::cout << "Arvaja:" << "\n";
        arvaja.arva();

        std::string input_line;
        std::getline(std::cin, input_line);
        if (input_line.empty()) continue;
        char arvamus = tolower(input_line[0]);

        std::cout << "Mäng: " << "\n";
        arvaja.addGuess(arvamus);
        arvatud_map = mang.mangiRound(arvamus);
        arvaja.handleNewMap(arvatud_map);

        if (mang.kontrolli()) {
            std::cout << "Võit!" << "\n";
            break;
        }
        if (mang.kaotus()) {
            std::cout << "Kaotus!" << "\n";
            break;
        }
    }
}
