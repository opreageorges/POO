// O metoda fara chesti complicate de a goli ecranul
void clearscreen(){
    for (int i=0; i<1000; i++){
        std::cout << '\n';
    }
}

//Afiseaza mesajul de la sfarsit
void endgame(int x){
    switch (x) {
        case 1:
            std::cout << "AI PIERDUT ;(\n";
            break;
        case 2:
            std::cout << "AI CASTIGAT\n";
            break;
        default:
            break;

    }
}

//Pentru a nu scrie de mana pozitiile turnurilor, in caz ca se modifica harta
void pozitiaturnurilor(const std::vector<std::vector<int>> &map, std::vector<pos> &pos_tur){
    for (int i = 0; i < map.size(); i++ ){
        for (int j = 0; j < map[0].size(); j++ ){
            if(map[i][j] == 84){
                pos_tur.push_back({i, j});
            }
        }
    }
}