
#ifndef FUNCTI_H_HARTA_H
#define FUNCTI_H_HARTA_H
#include "SFML/Graphics.hpp"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

class Harta {
    sf::Texture background;
    sf::Vector2f start;
    std::vector<int> lungimi;
    std::vector<char> directii;
public:
    //Creaza harta
    explicit Harta(const std::string&);

    //Returneaza textura harti
    const sf::Texture &getback();


};


#endif //FUNCTI_H_HARTA_H
