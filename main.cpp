#include "librari_si_sysdetect.h"
#include "clase_si_structuri.h"

int main()
{
        std::vector<std::vector<int>> map(5, std::vector<int>(5));
        int start_time = time(nullptr);
        //sleep(1);
        std::cout << start_time - time(nullptr) << "\n";
        map = {{0,  0,    1,  0, 0},
               {0,  84,   1,  0, 0},
               {0,  1,    1,  0, 0},
               {0,  1,    84, 0, 0},
               {84, 6587, 0,  0, 0}};
        pos start = { x:0, y:2};
        std::cout << map[0][2] << "\n";
        Enemy en(start_time, map, start);
        //CLEAR;
        tower t1(start_time, start), t2(11 , start);
        t2 = t1;
        std::cout << t2.getstime() << "\n" << t1;


    return 0;
}
