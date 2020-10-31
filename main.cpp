#include "librari_si_sysdetect.h"
#include "clase_si_structuri.h"

int main()
{
        std::vector<std::vector<int>> map(5, std::vector<int>(5));
        int start_time = time(nullptr);
        sleep(1);
        std::cout << start_time - time(nullptr) << "\n";
        map = {{178,  178,    88,  178, 178},
               {178,  84,   186,  178, 178},
               {178,  201,    188,  178, 178},
               {178,  186,    84, 178, 178},
               {84, 88, 178,  178, 178}};
        pos start = { x:0, y:2};
        std::cout << map[0][2] << "\n";
        Enemy en(start_time, map, start);

        tower t1(start_time, start), t2(11 , start);
        t2 = t1;
        std::cout << t2.getstime() << "\n" << t1;
        CLEAR;
        for(int i=0; i<5; i++){
            for(int j=0; j<5; j++){
                if(map[i][j] > 10)
                {
                    char x = map[i][j];
                    std::cout << x;
                }
                else
                    std::cout << map[i][j];
            }
            std::cout << "\n" ;
        }

    return 0;
}
