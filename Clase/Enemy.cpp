#include "Enemy.h"

Enemy::Enemy(int time, Harta map, pos xy = {0,0}){
    this->map = map;
    this->stime = time;
    this->loc = xy;
}

pos Enemy::getpos(){
    //std::cout << loc.x << " " << loc.y;
    return loc;
}

void Enemy::takedamage(int damage){
    this->health = this->health - damage;
}

bool Enemy::isAlive(){
    if (this->health >= 1)
        return true;
    else
        return false;
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
