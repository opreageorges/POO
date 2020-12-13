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

Tower& Tower::operator=(const Tower &t){
    this->adamage = t.adamage;
    this->aspeed = t.aspeed;
    this->loc = t.loc;
    this->price = t.price;
    return *this;
}

std::ostream& Tower::operator<<(std::ostream& out) const{
    out << "Locatia turnului e:(" << loc.x << ", " << loc.y <<") \nTurnul are un damage de: " << adamage <<" si ataca la fiecare " << aspeed << " secunde";
    return out;
}

sf::Vector2i Tower::getpos() const {
    return loc;
}

const sf::Texture &Tower::getTexture() const {
    return texture;
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
    texture.loadFromFile("../Resurse/Imagini/Fast_tower.png");
    adamage = 10;
    aspeed = 10;
    price = 20;
}

bool Fast_tower::atack(std::vector<Enemy*> inamici) {
    int t;
    for (auto i : inamici ){

    }

    return false;
}




//Slow tower

Slow_tower::Slow_tower(const sf::Vector2i &i) : Tower(i) {
    texture.loadFromFile("../Resurse/Imagini/Slow_tower.png");
    adamage = 40;
    aspeed = 40;
    price = 20;
}

bool Slow_tower::atack(std::vector<Enemy*> inamici) {
//    for (int i = inamici.size() ){
//
//    }

    return true;
}




//Scatter tower

Scatter_tower::Scatter_tower(const sf::Vector2i &i) : Tower(i) {
    texture.loadFromFile("../Resurse/Imagini/Scatter_tower.png");
    adamage = 6;
    aspeed = 45;
    price = 40;
}

bool Scatter_tower::atack(std::vector<Enemy*> inamici) {
    for (auto i : inamici ){

    }

    return true;
}