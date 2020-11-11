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
    int move(int time, char x){
        //Coloanele din margine si ultima linie(mai putin iesirea) mereu vor fi peret
        enum swi{ D, L, R };
        if ( time - this->stime >= this->mspeed) {

            this->stime += mspeed;

            switch (swi(x)) {
                case D:
                    this->loc.x++;
                    break;
                case L:
                    this->loc.y--;
                    break;
                case R:
                    this->loc.y++;
                    break;
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
    int price = 20;
    friend std::ostream& operator<<(std::ostream& out, const tower &t);

public:

    pos const getpos(){
        return loc;
    }

    int const getstime(){
        return stime;
    }

    tower(int time, pos loc){
        std::cout << "\nTrunul a fost creat\n";
        this->stime = time;
        this->loc = loc;
    }

    ~tower(){
        std::cout << "Turnul s-a distrus \n";
    }

    tower& operator=(const tower &t){
        std::cout << "= \n";
        this->stime = t.stime;
        this->aspeed = t.aspeed;
        this->adamage = t.adamage;
        this->loc = t.loc;
        return *this;
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

std::ostream& operator<<(std::ostream& out, const tower &t){
    out << "Locatia turnului e:(" << t.loc.x << ", " << t.loc.y <<") \nTurnul are un damage de: " << t.adamage <<" si ataca la fiecare " << t.aspeed << " secunde";
    return out;
}
