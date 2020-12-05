#include "Tower.h"

Tower::Tower(sf::Vector2i loc) {
    std::cout << "\nTrunul a fost creat\n";
    this->loc = loc;
    adamage = 20;
    aspeed = 20;
    price = 100;
}

Tower::Tower(const Tower &t) {
    this->adamage = t.adamage;
    this->aspeed = t.aspeed;
    this->loc = t.loc;
    this->price = t.price;
}

std::ostream& Tower::operator<<(std::ostream& out) const{
    out << "Locatia turnului e:(" << loc.x << ", " << loc.y <<") \nTurnul are un damage de: " << adamage <<" si ataca la fiecare " << aspeed << " secunde";
    return out;
}

sf::Vector2i Tower::getpos() const {
    return loc;
}

int Tower::getAdamage() const {
    return adamage;
}

int Tower::getAspeed() const {
    return aspeed;
}

int Tower::getPrice() const {
    return price;
}


//Fast tower

Fast_tower::Fast_tower(const sf::Vector2i &i) : Tower(i) {
    adamage = 10;
    aspeed = 10;
}

bool Fast_tower::atack(std::vector<int>) {
    int i=1;
    i+=i;
    return true;
}

