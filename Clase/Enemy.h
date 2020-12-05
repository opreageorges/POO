#ifndef FUNCTI_H_ENEMY_H
#define FUNCTI_H_ENEMY_H
#include "SFML/Graphics.hpp"

class Enemy {
    sf::Vector2i loc;
    int health = 100;
    int mspeed = 20;
    int stime;

public:
    Enemy(int time, sf::Vector2i xy);
    //Arata pozitia inamicului
    sf::Vector2i getpos() const;

    //Scade viata inamicului
    bool takedamage(int damage);

    //Misca inamicul
    int move(int time, char x);

};

#endif //FUNCTI_H_ENEMY_H