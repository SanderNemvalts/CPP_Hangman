//
// Created by Sander Nemvalts on 30.04.2026.
//

#ifndef CPP_HANGMAN_UTILS_H
#define CPP_HANGMAN_UTILS_H

#include <map>
#include <ostream>

template <typename T, typename K>
std::ostream& operator<<(std::ostream& out, const std::map<T, K>& mp) {
    out << "{" << "\n";
    for (typename std::map<T, K>::const_iterator it{mp.begin()}; it != mp.end(); ++it) {
        out << "\t" << it->first << " : " << it->second << "\n";
    }
    out << "}" << "\n";
    return out;
}

#endif //CPP_HANGMAN_UTILS_H