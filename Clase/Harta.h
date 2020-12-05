
#ifndef FUNCTI_H_HARTA_H
#define FUNCTI_H_HARTA_H
#include "SFML/Graphics.hpp"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

class Harta {
    // sf::Texture practic e o clasa, se pune drept compunere? :)
    std::string nume;
    sf::Texture background;
    sf::Vector2f start;
    std::vector<int> lungimi;
    std::vector<char> directii;
    std::vector<sf::IntRect> turnuri;
public:
    //Creaza harta
    explicit Harta(const std::string&);

    //Returneaza textura harti
    sf::Texture getback () const;

    //Retruneaza locul de start al inamicilor
    sf::Vector2f getstart () const;

    //Returneaza cat trebuie inamicul sa mearga intr-o directie
    std::vector<int> getlungimi () const;

    //Returneaza directiile in care trebuie sa mearga un inamic
    std::vector<char> getdirectii () const;

    //Returneaza pozitia unui loc in care poate fi construit un turn
    sf::IntRect getonetower(int) const;

    //Sterge o pozitie in care poate fi construit un turn
    void removeonetower(int);

    //Retruneaza numele hartii
    std::string getname() const;

    int gettowercount() const;

};


#endif //FUNCTI_H_HARTA_H
