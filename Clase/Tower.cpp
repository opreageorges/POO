#include "Tower.h"

//Tower::Tower(const sf::Vector2i &loc){
//    std::cout << "\nTrunul a fost creat\n";
//    this->loc = loc;
//    sf::IntRect bor(loc, sf::Vector2i(62,62));
//}
//
//Tower::Tower(const Tower &t){
//    std::cout << "copy \npaste \n";
//    this->aspeed = t.aspeed;
//    this->adamage = t.adamage;
//    this->loc = t.loc;
//
//}
//
//Tower& Tower::operator=(const Tower &t){
//    std::cout << "= \n";
//    this->aspeed = t.aspeed;
//    this->adamage = t.adamage;
//    this->loc = t.loc;
//    return *this;
//}
//
//sf::Vector2i Tower::getpos() const{
//    return loc;
//}
//
//std::ostream& Tower::operator<<(std::ostream& out) const{
//    out << "Locatia turnului e:(" << loc.x << ", " << loc.y <<") \nTurnul are un damage de: " << adamage <<" si ataca la fiecare " << aspeed << " secunde";
//    return out;
//}
//
//int Tower::getAdamage() const {
//    return adamage;
//}
//
//int Tower::getAspeed() const {
//    return aspeed;
//}
//
//const sf::IntRect &Tower::getBorder() const {
//    return border;
//}
//
//Tower::~Tower(){
//    std::cout << "Turnul s-a distrus \n";
//}




Normal_tower::Normal_tower(sf::Vector2i) {
    std::cout << "\nTrunul a fost creat\n";
    this->loc = loc;
}

Normal_tower::Normal_tower(const Normal_tower &t) {
    this->adamage = t.adamage;
    this->aspeed = t.aspeed;
    this->loc = t.loc;
    this->price = t.price;
}
