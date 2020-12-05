#ifndef FUNCTI_H_TOWER_H
#define FUNCTI_H_TOWER_H
#include <iostream>
#include "SFML/Graphics.hpp"

class Base_Tower {
protected:
    int adamage;
    int aspeed;
    sf::Vector2i loc;
    int price;

public:
    //Base_Tower(const Base_Tower &t);
    //Base_Tower& operator=(const Base_Tower &t);
    //std::ostream& operator<<(std::ostream& out) const;

    //Arata pozitia turnului
    virtual sf::Vector2i getpos() const = 0;

    virtual const sf::IntRect &getBorder() const = 0;

    virtual  int getAdamage() const = 0;

    virtual int getAspeed() const = 0;

    virtual ~Base_Tower() =0 ;

};

class Normal_tower:Base_Tower{
public:
    Normal_tower(sf::Vector2i);
    Normal_tower(const Normal_tower &t);

};



#endif //FUNCTI_H_TOWER_H
