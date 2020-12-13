#ifndef FUNCTI_H_TOWER_H
#define FUNCTI_H_TOWER_H
#include <iostream>
#include "SFML/Graphics.hpp"
#include "Enemy.h"

//Baza pentru turnuri

class Tower{
    sf::Vector2i loc;
protected:
    sf::Texture texture;
    int adamage;
    int aspeed;
    int price;

public:

    explicit Tower(sf::Vector2i) ;

    Tower(const Tower &t);
    //Foloseam = default pentru ca imi da warning ca pot face asta
    // si l-am comentat pe ala facut de mine ca sa vezi ca e facut
    Tower& operator=(const Tower &t);

    std::ostream& operator<<(std::ostream& out) const;

    sf::Vector2i getpos() const;

    const sf::Texture &getTexture() const;

    int getAdamage() const;

    int getAspeed() const;

    int getPrice() const;

    virtual bool atack(std::vector<Enemy*> inamici) = 0;

    virtual ~Tower() = default;
};

// Un turn care ataca rapid cu putin damage

class Fast_tower: public Tower{

public:
    explicit Fast_tower(const sf::Vector2i &i);

    bool atack(std::vector<Enemy*> inamici) override;
};

class Slow_tower: public Tower{

public:
    explicit Slow_tower(const sf::Vector2i &i);

    bool atack(std::vector<Enemy*> inamici) override;
};


class Scatter_tower: public Tower{

public:
    explicit Scatter_tower(const sf::Vector2i &i);

    bool atack(std::vector<Enemy*> inamici) override;

};


#endif //FUNCTI_H_TOWER_H
