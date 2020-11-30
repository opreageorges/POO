#include "Harta.h"


std::ostream& operator<<(std::ostream& out, Harta &h){
    for (int i = 0; i < h.map.size(); i++){
        out << h.map[i];
        out << '\n';
    }
    return out;
}

const std::vector<std::string> & Harta::exportmap(){
    return map;
}

void Harta::importmap(std::string numele_harti) {
    int mapsize;
    std::ifstream mapin;
    std::string nh = "../harti/";

    nh += numele_harti;

    mapin.open (nh);
    mapin >> mapsize;
    map.reserve(mapsize);
    //Fac asta sa scap de linia de spati de dupa marime
    std::string dum;
    std::getline(mapin, dum);

    for(int i = 0 ; i < mapsize; i++){
        std::string x;
        std::getline(mapin, x);
        map.push_back(x);
    }
    mapin >> start.x >> start.y;
    mapin.close();
}