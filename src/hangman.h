//
// Created by grerg on 24/04/2026.
//

#ifndef CPP_HANGMAN_HANGMAN_H
#define CPP_HANGMAN_HANGMAN_H
#include <string>
#include <vector>


class hangman {
private:
    std::string vastus;
    int pikkus;
    int arvamusi{0};
    int vale_arvamusi{0};
    std::vector <char> arvatud_tahed = std::vector<char>();
public:
    hangman();
    hangman(std::string);

    void mangi();

    void arva(char taht);

    void esita();

    void esitapilt();

    bool kontrolli();

    bool kontrolli(char arvamus);

};


#endif //CPP_HANGMAN_HANGMAN_H