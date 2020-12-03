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

const sf::Vector2f &Harta::getstart(){
    return start;
}

const std::vector<int> &Harta::getlungimi(){
    return lungimi;
}

const std::vector<char> &Harta::getdirectii(){
    return directii;
}

