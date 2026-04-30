//
// Created by grerg on 24/04/2026.
//

#include "../include/hangman.h"
#include <algorithm>
#include <iostream>
#include <ostream>

hangman::hangman() {
    vastus = "placeholder";
    vastuse_pikkus = vastus.length();
}

hangman::hangman(std::string arva) {
    vastus = arva;
    std::transform(vastus.begin(), vastus.end(), vastus.begin(),
    [](unsigned char c){ return std::tolower(c); });
    vastuse_pikkus = arva.length();
}

void hangman::esita() {
    for (int i{0}; i < vastuse_pikkus; ++i) {
        if (arvatud_map.find(i) != arvatud_map.end()) {
            std::cout << vastus[i] << " ";
        } else {
            std::cout << "_ ";
        }
    }
}

bool hangman::kontrolli() {
    if (arvatud_map.size() < vastuse_pikkus) return false;
    for (int i{0}; i < vastuse_pikkus; ++i) {
        if (arvatud_map[i] == vastus[i]) continue;
        return false;
    } return true;
}

bool hangman::kontrolli(char arvamus) {
    std::size_t pos = vastus.find(arvamus);
    if (pos == std::string::npos) return false;
    while (pos != std::string::npos) {
        arvatud_map[pos] = arvamus;
        pos = vastus.find(arvamus, pos + 1);
    } return true;
}

bool hangman::kaotus() {
    return vale_arvamusi >= 5;
}

void hangman::esitapilt() {
    if (vale_arvamusi == 0) {
        std::cout << "     ------|\n           |\n           |\n           |\n           |\n           |\n           |\n___________|";
    }
    if (vale_arvamusi == 1) {
        std::cout << "     ------|\n     |     |\n           |\n           |\n           |\n           |\n           |\n___________|";
    }
    if (vale_arvamusi == 2) {
        std::cout << "     ------|\n     |     |\n     O     |\n           |\n           |\n           |\n           |\n___________|";
    }
    if (vale_arvamusi == 3) {
        std::cout << "     ------|\n     |     |\n     O     |\n    /|\\    |\n           |\n           |\n           |\n___________|";
    }
    if (vale_arvamusi == 4) {
        std::cout << "     ------|\n     |     |\n     O     |\n    /|\\    |\n     |     |\n           |\n           |\n___________|";
    }
    if (vale_arvamusi >= 5) {
        std::cout << "     ------|\n     |     |\n     O     |\n    /|\\    |\n     |     |\n    / \\    |\n           |\n___________|";
    }

}

std::map<size_t, char> hangman::mangiRound(char arvamus) {

    if (std::find(arvatud_tahed.begin(), arvatud_tahed.end(), arvamus) != arvatud_tahed.end()) {
        std::cout << "Seda tähte juba arvasid! Proovi uut!\n";
        return arvatud_map;
    }

    if (this -> kontrolli(arvamus)) {
        std::cout << arvamus << " on sõnas olemas!\n";
    } else {
        std::cout << arvamus << " ei ole sõnas!\n";
        ++vale_arvamusi;
        this->esitapilt();
        std::cout << "\n";
    }
    return arvatud_map;
}
