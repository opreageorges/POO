#include "Enemy.h"

Enemy::Enemy(int time, sf::Vector2i xy = {0,0}){
    this->stime = time;
    this->loc = xy;
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
    //Coloanele din margine si ultima linie(mai putin iesirea) mereu vor fi pereti
    enum swi{ D, L, R };
    if ( time - this->stime >= this->mspeed) {

        this->stime += mspeed;

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

    }
    return -1;
}
