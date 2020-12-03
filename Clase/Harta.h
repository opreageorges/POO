
#ifndef FUNCTI_H_HARTA_H
#define FUNCTI_H_HARTA_H
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Structuri.h"

class Harta {
    std::vector<std::string> map;
    pos start;
public:

    //Afiseaza harta
    friend std::ostream &operator<<(std::ostream& out, Harta &h);

    //Returneaza harta
    const std::vector<std::string> &exportmap();

    //Importa harta din fisier
    void importmap(const std::string &numele_harti);

    //Pentru a afla pozitia turnurilor
    void pos_turnuri(std::vector<pos> &trn);

    //Pentru a sterge reprentarea trunurilor de pe harta
    void no_tower(const pos &turn);
};


#endif //FUNCTI_H_HARTA_H
