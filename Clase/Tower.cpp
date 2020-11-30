#include "Tower.h"

Tower::Tower(int time, pos loc){
    std::cout << "\nTrunul a fost creat\n";
    this->stime = time;
    this->loc.x = loc.x;
    this->loc.y = loc.y;
}

Tower::Tower(const Tower &t){
    std::cout << "copy \npaste \n";
    this->stime = t.stime;
    this->aspeed = t.aspeed;
    this->adamage = t.adamage;
    this->loc.x = t.loc.x;
    this->loc.y = t.loc.y;
}

Tower& Tower::operator=(const Tower &t){
    std::cout << "= \n";
    this->stime = t.stime;
    this->aspeed = t.aspeed;
    this->adamage = t.adamage;
    this->loc = t.loc;
    return *this;
}

pos const Tower::getpos(){
    return loc;
}

int const Tower::getstime(){
    return stime;
}

int Tower::attack(int time){
    if (time - this->stime >= this->aspeed) {
        this->stime = time;
        return adamage;
    }
    return 0;
}

std::ostream& Tower::operator<<(std::ostream& out){
    out << "Locatia turnului e:(" << loc.x << ", " << loc.y <<") \nTurnul are un damage de: " << adamage <<" si ataca la fiecare " << aspeed << " secunde";
    return out;
}

Tower::~Tower(){
    std::cout << "Turnul s-a distrus \n";
}