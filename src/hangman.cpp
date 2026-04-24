//
// Created by grerg on 24/04/2026.
//

#include "hangman.h"
#include <algorithm>
#include <iostream>
#include <ostream>

hangman::hangman() {
    vastus = "placeholder";
    pikkus = vastus.length();
}

hangman::hangman(std::string arva) {
    vastus = arva;
    std::transform(vastus.begin(), vastus.end(), vastus.begin(),
    [](unsigned char c){ return std::tolower(c); });
    pikkus = arva.length();
}

void hangman::esita() {
    for (int i = 0; i < pikkus; i++) {
        if (std::find(arvatud_tahed.begin(), arvatud_tahed.end(), vastus[i]) != arvatud_tahed.end()) {
            std::cout << vastus[i] << " ";
        } else {
            std::cout << "_ ";
        }
    }
}

bool hangman::kontrolli() {
    for (int i = 0; i < pikkus; i++) {
        if (std::find(arvatud_tahed.begin(), arvatud_tahed.end(), vastus[i]) != arvatud_tahed.end()) {
            continue;
        }
        return false;
    }
    return true;
}

bool hangman::kontrolli(char arvamus) {
    if (vastus.find(arvamus) != std::string::npos) {
        return true;
    }
    return false;
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

void hangman::mangi() {
    std::cout << "Tervitused palun hakka arvama sõna: " << std::endl;
    char arvamus;
    for (; vale_arvamusi < 5; ) {
        this->esita();
        std::cout << "\nSisesta täht: " << std::endl;
        std::cin >> arvamus;
        arvamus = tolower(arvamus);

        if (std::find(arvatud_tahed.begin(), arvatud_tahed.end(), arvamus) != arvatud_tahed.end()) {
            std::cout << "Seda tähte juba arvasid! Proovi uut!\n";
            continue;
        }

        arvatud_tahed.push_back(arvamus);

        if (this -> kontrolli(arvamus)) {
            std::cout << arvamus << " on sõnas olemas!\n";
            if (this->kontrolli()) {
                std::cout << "Võit!\n";
                this->esita();
                break;
            }
            continue;
        }else {
            std::cout << arvamus << " ei ole sõnas!\n";
            vale_arvamusi++;
            this->esitapilt();
            std::cout << "\n";
            if (vale_arvamusi >= 5) {
                std::cout << "Kaotus!";
            }
        }
    }
}
