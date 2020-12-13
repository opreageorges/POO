#include "Enemy.h"

Enemy::Enemy(sf::Vector2i xy){
    this->loc = xy;
    health = 100;
    mspeed = 20;
    texture.loadFromFile("../Resurse/Imagini/Enemy_1.png");
}

sf::Vector2i Enemy::getpos() const{
    //std::cout << loc.x << " " << loc.y;
    return loc;
}

bool Enemy::takedamage(int damage){
    this->health = this->health - damage;
    return health > 0;
}

int Enemy::move(int time, char x){

    enum swi{ D, L, R };
        switch (swi(x)) {
            case D:
                this->loc.x++;
                break;
            case L:
                this->loc.y--;
                break;
            case R:
                this->loc.y++;
                break;
        }

    return -1;
}
