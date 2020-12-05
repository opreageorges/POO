#include "Harta.h"

Harta::Harta(const std::string& nume_in){
    nume = nume_in;
    //Seteaza calea pana la fisierele hartii
    std::string path_bg, path_pct, path_tower;
    path_bg = "../Resurse/Imagini/"+ nume +"/mapbg.jpg";
    path_pct = "../Resurse/Imagini/"+ nume +"/Puncte";
    path_tower = "../Resurse/Imagini/"+ nume +"/Turnuri";

    //Incarca background-ul
    background.loadFromFile(path_bg);

    //Citeste fisierul Puncte
    int n;
    std::ifstream in;
    in.open(path_pct);
    in >> n >> start.x >> start.y;
    lungimi.reserve(n);
    directii.reserve(n);

    for(int i = 0; i < n;i++){
        in >> lungimi[i] >> directii[i];
    }
    in.close();

    //Citeste locatia turnurilor
    in.open(path_tower);
    in >> n;
    turnuri.reserve(n);
    for(int i = 0; i < n;i++){
        int x,y;
        in >> x >> y;
        sf::IntRect r(sf::Vector2i(x,y), sf::Vector2i(62,62));
        turnuri.push_back(r);
    }
    in.close();
}

sf::Texture Harta::getback() const{
    return background;
}

sf::Vector2f Harta::getstart() const{
    return start;
}

std::vector<int> Harta::getlungimi() const{
    return lungimi;
}

std::vector<char> Harta::getdirectii() const{
    return directii;
}

sf::IntRect Harta::getonetower(int x) const{
    return turnuri[x];
}

std::string Harta::getname() const{
    return nume;
}

void Harta::removeonetower(int x) {
    turnuri.erase(turnuri.begin()+x);
}

int Harta::gettowercount() const {
    return turnuri.size();
}

