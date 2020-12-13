#ifndef FUNCTI_H_ENEMY_H
#define FUNCTI_H_ENEMY_H
#include "SFML/Graphics.hpp"

class Enemy {
protected:
    sf::Texture texture;
    sf::Vector2i loc;
    int health;
    int mspeed;

public:
    explicit Enemy(sf::Vector2i);

    //Arata pozitia inamicului
    sf::Vector2i getpos() const;

    //Scade viata inamicului
    bool takedamage(int damage);

    //Misca inamicul
    int move(int time, char x);

};

//class Boss:Enemy{
//
//};
#endif //FUNCTI_H_ENEMY_H