#ifndef FUNCTI_H_TOWER_H
#define FUNCTI_H_TOWER_H
#include <iostream>
#include "Structuri.h"

class Tower {
    int adamage = 50;
    int aspeed = 20;
    pos loc;
    int stime;
    //int price = 20;
   // friend std::ostream& operator<<(std::ostream& out, const Tower &t);

public:
    Tower(int time, pos loc);

    Tower(const Tower &t);
    Tower& operator=(const Tower &t);
    std::ostream& operator<<(std::ostream& out);

    //Arata pozitia turnului
    pos const getpos();

    //Timpul la care s-a interactiona ultima data cu turnul
    int const getstime();

    //Verifica daca turnul poate sa atace si daca poate o face
    int attack(int time);

    ~Tower();

};

#endif //FUNCTI_H_TOWER_H
