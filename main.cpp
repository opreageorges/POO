#include "librari.h"
#include "clase_si_structuri.h"
#include "functi.h"


//main-ul nu face mai nimic
int main()
{
        std::vector<std::vector<int>> map(5, std::vector<int>(5));
        std::vector<pos> pos_tur;
        std::vector<Enemy*> inamici;
        std::vector<tower*> turnuri;
        int start_time = time(nullptr), wol = 2;
        pos start;

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

        for(int i = 0; i< pos_tur.size(); i++){
            std::string input;
            std::cout << "Construiesti tur pe casuta de la pozitia: ("<< pos_tur[i].x << ", " << pos_tur[i].y <<") ?\n";
            std::cout << "Variante:\nDa\nNu\n";
            std::cin >> input;
            if(input == "Da") {
                //std::cout << "Variante: Artilerie....
                turnuri.push_back(new tower(start_time, pos_tur[i]));
                sleep(1);
            }
            else{
                map[pos_tur[i].x][pos_tur[i].y] = 178;
            }
            clearscreen();
        }

        while (true){
                sleep(1);
                if(turnuri.size()<2)
                    wol = 1;
                //clearscreen();
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

        for(int i = 0; i<turnuri.size(); i++)
            delete turnuri[i];
        // Cmd-ul din windows se inchide automat
        #ifdef _WIN32
            std::cout << "(apasa pe orice tasta apoi pe enter)\n";
            //int t;
            //std::cin >> t;
        #endif
    return 0;
}
