#include <iostream>
#include <ctime>
#include <vector>
#include <unistd.h>
#include "Clase/Harta.h"
#include "Clase/Enemy.h"
#include "Clase/Tower.h"

// O metoda fara chesti complicate de a goli ecranul
void clearscreen(){
    for (int i=0; i<100; i++){
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

int main() {

    std::vector<pos> pos_tur;
    std::vector<Enemy *> inamici;
    std::vector<Tower *> turnuri;
    int start_time = time(nullptr), wol = 2;
    Harta map;
    int player_h = 100;

    map.importmap("map1");

    std::cout << map;
    return 0;
}
/*
    pozitiaturnurilor(map, pos_tur);

    std::string dif;
    while (true) {
        std::cout << "Alege dificultatea:\nGreu\nMediu\nUsor\n";
        std::cin >> dif;
        if(dif == "Greu" || dif == "Mediu" || dif == "Usor")
            break;
        else {
            std::cout << "Dificultatea aleasa nu exista\n";
            sleep(1);
            clearscreen();
        }
    }

    clearscreen();


    for(pos i : pos_tur){
        std::string input;
        std::cout << "Construiesti tur pe casuta de la pozitia: ("<< i.x << ", " << i.y <<") ?\n";
        std::cout << "Variante:\nDa\nNu\n";
        std::cin >> input;
        if(input == "Da") {
            //std::cout << "Variante: Artilerie....
            turnuri.push_back(new tower(start_time, i));
            sleep(1);
        }
        else{
            map[i.x][i.y] = 178;
        }
        clearscreen();
    }

    while (true){
        sleep(1);
        if(turnuri.size()<2)
            wol = 1;

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (map[i][j] > 10) {
                    char x = map[i][j];
                    std::cout << x;
                } else
                    std::cout << map[i][j];
            }
            std::cout << "\n";
        }

        if(wol != 0){
            endgame(wol);
            break;
        }
        //break;
    }

    for(auto & i : turnuri)
        delete i;

    return 0;
}
*/