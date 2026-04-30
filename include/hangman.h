//
// Created by grerg on 24/04/2026.
//

#ifndef CPP_HANGMAN_HANGMAN_H
#define CPP_HANGMAN_HANGMAN_H
#include <float.h>
#include <string>
#include <vector>
#include <map>


class hangman {
private:
    std::string vastus;
    int vastuse_pikkus;
    int arvamusi{0};
    int vale_arvamusi{0};
    std::vector <char> arvatud_tahed = std::vector<char>();
    std::map<size_t, char> arvatud_map{};
public:
    hangman();
    hangman(std::string);

    void arva(char taht);

    void esita();

    void esitapilt();

    bool kontrolli();

    bool kontrolli(char arvamus);

    bool kaotus();

    std::map<size_t, char> mangiRound(char arvamus);
};


#endif //CPP_HANGMAN_HANGMAN_H