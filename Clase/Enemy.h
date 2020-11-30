#ifndef FUNCTI_H_ENEMY_H
#define FUNCTI_H_ENEMY_H
#include "Harta.h"

class Enemy {
    pos loc;
    Harta map;
    int health = 100;
    int mspeed = 20;
    int stime;

public:
    Enemy(int time, Harta map, pos xy);
    //Arata pozitia inamicului
    pos getpos();

    //Scade viata inamicului
    void takedamage(int damage);

    //Verifica daca inamicul mai e in viata
    bool isAlive();

    //Misca inamicul
    int move(int time, char x);

};

#endif //FUNCTI_H_ENEMY_H