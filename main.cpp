#include <iostream>
#include <ctime>
#include <vector>
#include <unistd.h>
#include <limits>
#include "clase_si_structuri.h"
#include "functi.h"


int main(){

    std::vector<std::vector<int>> map(5, std::vector<int>(5));
    std::vector<pos> pos_tur;
    std::vector<Enemy*> inamici;
    std::vector<tower*> turnuri;
    int start_time = time(nullptr), wol = 2;
    pos start;
    int player_h = 100;

    map = {{178, 178, 88,  178, 178},
           {178, 84,  186, 178, 178},
           {178, 201, 188, 178, 178},
           {178, 186, 84,  178, 178},
           {84,  88,  178, 178, 178}};

    for(int i = 0; i<map[0].size(); i++) {
        if (map[0][i] == 88)
            start = {0, i};
    }

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
    };

    for(auto & i : turnuri)
        delete i;

    // Cmd-ul din windows se inchide automat
    #ifdef _WIN32
        std::cout << "(apasa pe orice tasta apoi pe enter)\n";
        int t;
        // std::cin >> t;
    #endif
    return 0;
}
