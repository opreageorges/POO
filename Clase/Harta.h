
#ifndef FUNCTI_H_HARTA_H
#define FUNCTI_H_HARTA_H
#include "SFML/Graphics.hpp"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

class Harta {
    // Testure practic e o clasa, se pune drept compunere? :)
    sf::Texture background;
    sf::Vector2f start;
    std::vector<int> lungimi;
    std::vector<char> directii;
public:
    //Creaza harta
    explicit Harta(const std::string&);

    //Returneaza textura harti
    const sf::Texture &getback();

    const sf::Vector2f &getstart();

    const std::vector<int> &getlungimi();

    const std::vector<char> &getdirectii();


};


#endif //FUNCTI_H_HARTA_H
