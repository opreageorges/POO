#include <iostream>
#include <ctime>
#include <vector>
#include <unistd.h>

struct pos{
    int x,y;
};

class enemy{
    pos loc;
    std::vector<std::vector<int>> map;
    int health = 100;
    int mspeed = 20;
    int stime;

public:
    enemy(int time, std::vector<std::vector<int>> map, pos xy = {0,0}  ){
        this->loc = xy;
        this->map = map;
        this->stime = time;
    }
    //Locatia inamicului
    pos getpos(){
        std::cout << loc.x << " " << loc.y;
        return loc;
    }
    void takedamage(int damage){
        this->health = this->health - damage;
    }
    bool isAlive(){
        if (this->health >= 1)
            return true;
        else
            return false;
    }
    char move(int time){
        //Coloanele din margine si ultima linie(mai putin iesirea) mereu vor fi peret
        if (-this->stime + time >= this->mspeed) {
            this->stime += mspeed;
            if (this->map[this->loc.x][this->loc.y] == 6587)
                return 0;
            else if (this->map[this->loc.x - 1][this->loc.y] == 1 || this->map[this->loc.x - 1][this->loc.y] == 6587) {
                this->loc.x = this->loc.x - 1;
                return 1;
            } else if (this->map[this->loc.x][this->loc.y - 1] == 1) {
                this->loc.y = this->loc.y - 1;
                return 1;
            } else if (this->map[this->loc.x][this->loc.y + 1] == 1) {
                this->loc.y = this->loc.y + 1;
                return 1;
            }
        }
    }


};

class tower{
    int adamage = 50;
    int aspeed = 20;
    int stime;

public:
    tower(int time){
        this->stime = time;
    }
    int attack(int time){
        if (-this->stime - time >= this->aspeed)
            return adamage;
        return 0;
    }
};

int main()
{
    std::vector<std::vector<int>> map(5, std::vector<int>(5));
    int start_time = time(0);
    sleep(2);
    std::cout << start_time - time(0) <<"\n";
    map = {{0,   0,  1,  0, 0 },
           {0,  84,  1,  0, 0 },
           {0,   1,  1,  0, 0 },
           {0,   1,  84, 0, 0 },
           {84,6587, 0,  0, 0 }};
    pos start = {0,2};
    std::cout << map[0][2] << "\n";
    enemy en(start_time, map, start);
    en.getpos();

    return 0;
}
