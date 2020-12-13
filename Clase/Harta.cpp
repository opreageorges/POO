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
    towers.reserve(n);
    tower_spot.reserve(n);
    for(int i = 0; i < n;i++){
        int x,y;
        in >> x >> y;
        sf::IntRect r(sf::Vector2i(x,y), sf::Vector2i(62,62));
        tower_spot.push_back(r);
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

sf::IntRect Harta::getonetowerspot(int x) const{
    return tower_spot[x];
}

std::string Harta::getname() const{
    return nume;
}

int Harta::transform(int x, int type) {
    if(type > 0) {
        //= std::make_unique<Fast_tower>(sf::Vector2i()); //c++ 14
        switch (type) {
            case 1:
                towers.push_back(std::make_unique<Fast_tower>(sf::Vector2i (tower_spot[x].left,tower_spot[x].top )));
                break;

            case 2:
                towers.push_back(std::make_unique<Slow_tower>(sf::Vector2i (tower_spot[x].left,tower_spot[x].top )));
                break;

            case 3:
                towers.push_back(std::make_unique<Scatter_tower>(sf::Vector2i (tower_spot[x].left,tower_spot[x].top )));
                break;
            default:

                break;
        }

        int out = towers.back()->getPrice();
        tower_spot.erase(tower_spot.begin() + x);
        return out;
    }
    else if(type == 0){
        std::cout << "N-ai suficienti bani \n";
        return 0;
    }
    return 0;
}


int Harta::gettowerspotcount(){
    return tower_spot.size();
}

int Harta::gettowerscount() {
    return towers.size();
}

const std::unique_ptr<Tower> &Harta::getTowers(int i) {
    return towers[i];
}

bool Harta::nextwave() {
    return false;
}





//Harta::~Harta() {
//
//
//}





