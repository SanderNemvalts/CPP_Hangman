//
// Created by Sander Nemvalts on 24.04.2026.
//

#include <iostream>

#include "../include/hangman.h"
#include "../include/utils.h"

int main() {
    hangman mang = hangman("looder");

    std::cout << "Tervitused palun hakka arvama sõna: " << std::endl;
    std::map<size_t, char> arvatud_map{};
    while (true) {
        mang.esita();
        std::cout << "\n";

        std::string input_line;
        std::getline(std::cin, input_line);
        if (input_line.empty()) continue;
        char arvamus = tolower(input_line[0]);

        arvatud_map = mang.mangiRound(arvamus);
        std::cout << arvatud_map;

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
