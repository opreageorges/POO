#include "Harta.h"

Harta::Harta(const std::string& nume){

    std::string path_bg , path_pct;
    path_bg = "../Resurse/Imagini/"+ nume +"/mapbg.jpg";
    path_pct = "../Resurse/Imagini/"+ nume +"/Puncte";

    background.loadFromFile(path_bg);

    int n;
    std::ifstream pct_in;
    pct_in.open(path_pct);
    pct_in >> n >> start.x >> start.y;
    lungimi.reserve(n);
    directii.reserve(n);

    for(int i = 0; i < n;i++){
        pct_in >> lungimi[i] >> directii[i];
    }

}

const sf::Texture & Harta::getback(){
    return background;
}


//void Harta::pos_turnuri(std::vector<pos> &trn){
//    trn.reserve(3);
//    for(int i = 0; i < map.size(); i++){
//        for(int j = 0; j < map[i].size(); j++){
//            if(map[i][j] == 'T'){
//                trn.push_back({i , j});
//            }
//        }
//    }
//}
//
//void Harta::no_tower(const pos &turn){
//
//    map[turn.x][turn.y] = ' ';
//}