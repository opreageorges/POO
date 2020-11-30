//
// Created by George on 11/29/2020.
//

#ifndef FUNCTI_H_HARTA_H
#define FUNCTI_H_HARTA_H

#include <fstream>
#include <vector>
#include <string>
#include "Structuri.h"


class Harta {
    std::vector<std::string> map;
    pos start;
public:

    friend std::ostream &operator<<(std::ostream& out, Harta &h);

    const std::vector<std::string> &exportmap();

    void importmap(std::string numele_harti);

};


#endif //FUNCTI_H_HARTA_H
