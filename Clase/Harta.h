
#ifndef FUNCTI_H_HARTA_H
#define FUNCTI_H_HARTA_H
#include "SFML/Graphics.hpp"
#include "Tower.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <memory>

class Harta {
    std::string nume;
    sf::Texture background;
    sf::Vector2f start;
    std::vector<int> lungimi;
    std::vector<char> directii;
    std::vector<sf::IntRect> tower_spot;
    std::vector<std::unique_ptr<Tower>> towers;
//    std::vector<Tower*> towers;

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
    sf::IntRect getonetowerspot(int) const;

    //Sterge o pozitie in care poate fi construit un turn
    int transform(int,int);

    //Retruneaza numele hartii
    std::string getname() const;

    //Retruneaza numarul de locuri disponibile pentru construit turnuri
    int gettowerspotcount();

    //Returneaza numarul de turnuri
    int gettowerscount();

    //Returneaza un turn construit
    const std::unique_ptr<Tower> &getTowers(int);

    //Incepe urmatorul rand de inamici
    bool nextwave();

//    ~Harta();
};


#endif //FUNCTI_H_HARTA_H
