#include "Harta.h"


std::ostream& operator<<(std::ostream& out, Harta &h){
    for (auto & i : h.map){
        out << i;
        out << '\n';
    }
    return out;
}

const std::vector<std::string> & Harta::exportmap(){
    return map;
}

void Harta::importmap(const std::string &numele_harti) {
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

void Harta::pos_turnuri(std::vector<pos> &trn){
    trn.reserve(3);
    for(int i = 0; i < map.size(); i++){
        for(int j = 0; j < map[i].size(); j++){
            if(map[i][j] == 'T'){
                trn.push_back({i , j});
            }
        }
    }
}

void Harta::no_tower(const pos &turn){

    map[turn.x][turn.y] = ' ';
}