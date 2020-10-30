struct pos{
    int x,y;
};
class Enemy{
    pos loc;
    std::vector<std::vector<int>> map;
    int health = 100;
    int mspeed = 20;
    int stime;

public:
    Enemy(int time, std::vector<std::vector<int>> map, pos xy = {0,0}  ){
        this->map = map;
        this->stime = time;
        this->loc = xy;
    }
    //Locatia inamicului
    pos getpos(){
        //std::cout << loc.x << " " << loc.y;
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
    int move(int time){
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
        return -1;
    }


};

class tower{
    int adamage = 50;
    int aspeed = 20;
    pos loc;
    int stime;
public:
    pos const getpos(){
        return loc;
    }
    int const getstime(){
        return stime;
    }

    tower(int time, pos loc){
        this->stime = time;
        loc = loc;
    }

    ~tower(){
        std::cout << "Turnul s-a distrus";
    }
    tower(const tower &t){
         std::cout << "copy \npaste \n";
         this->stime = t.stime;
         this->aspeed = t.aspeed;
         this->adamage = t.adamage;
         this->loc = t.loc;
    }
    int attack(int time){
        if (-this->stime - time >= this->aspeed) {
            this->stime = time;
            return adamage;
        }
        return 0;
    }



};
