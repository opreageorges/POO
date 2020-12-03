// Resure -> DLL le-am pus acolo sa nu le pierd
#include <iostream>
//#include <ctime>
#include <vector>
//#include <unistd.h>
#include "SFML/Graphics.hpp"
//#include "Clase/Structuri.h"
//#include "Clase/Harta.h"
//#include "Clase/Enemy.h"
//#include "Clase/Tower.h"

//Afiseaza mesajul de la sfarsit
void endgame(int x){
    sf::Font arial;
    arial.loadFromFile("../Resurse/ArialUnicodeMS.ttf");

    sf::Text end_tx;
    switch (x) {
        case 1:
            end_tx.setString( "AI PIERDUT ;(");
            break;
        case 2:
            std::cout << "AI CASTIGAT\n";
            break;
        default:
            break;

    }
}

int difficulty(){
    sf::RenderWindow diff(sf::VideoMode(500, 500), "Alege nivelul de dificultate");
    diff.clear();

    sf::Font arial;
    arial.loadFromFile("../Resurse/ArialUnicodeMS.ttf");

    std::vector<sf::RectangleShape> fun_dificultati;
    std::vector<sf::Text> tx_dificultati;

    fun_dificultati.reserve(3);
    tx_dificultati.reserve(3);

    //Creaza frumusetea de butoane
    for(int i = 0; i < 3; i++){
        sf::RectangleShape r(sf::Vector2f(200,75));
        sf::Text t;
        fun_dificultati.push_back(r);
        tx_dificultati.push_back(t);
        tx_dificultati[i].setFont(arial);
        sf::Color culoare;
        switch (i) {
            case 0:
                tx_dificultati[i].setString("Usor");
                culoare = sf::Color::Green;
                break;
            case 1:
                tx_dificultati[i].setString("Mediu");
                culoare = sf::Color::Yellow;
                break;
            case 2:
                tx_dificultati[i].setString("Greu");
                culoare = sf::Color::Red;
                break;

        }
        fun_dificultati[i].setFillColor(culoare);
        fun_dificultati[i].setPosition(sf::Vector2f(500/2-100, 50*(i+1) + 75*i ));
        tx_dificultati[i].setFillColor(sf::Color::Black);
        tx_dificultati[i].setPosition(fun_dificultati[i].getPosition());
        tx_dificultati[i].setCharacterSize(72);
        diff.draw(fun_dificultati[i]);
        diff.draw(tx_dificultati[i]);


    }
    diff.display();

    while(diff.isOpen()){
        sf::Event event;
        while (diff.pollEvent(event))
        {
            switch (event.type) {
                case sf::Event::Closed:
                    diff.close();
                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::Q) {
                        diff.close();
                    }
                    break;
                case sf::Event::MouseButtonPressed:
                    //std::cout << sf::Mouse::getPosition(diff).x << " " << sf::Mouse::getPosition(diff).y << '\n'
                    // << fun_dificultati[1].getPosition().x << " " << fun_dificultati[1].getPosition().y <<'\n';
                    for(int i : {0,1,2}) {
                        if((sf::Mouse::getPosition(diff).x > fun_dificultati[i].getPosition().x && sf::Mouse::getPosition(diff).y > fun_dificultati[i].getPosition().y) &&
                        (sf::Mouse::getPosition(diff).x < fun_dificultati[i].getPosition().x+200 && sf::Mouse::getPosition(diff).y < fun_dificultati[i].getPosition().y+75))
                            return i;
                    }
                case sf::Event::Resized:
                    diff.display();
            }
        }
    }

    return -1;
}


int main() {
    short int diff;
    diff = difficulty();
    sf::RenderWindow tdgame(sf::VideoMode(800, 600), "Tower Defence", sf::Style::Close);
    tdgame.close();
    int i = 1;
    while(tdgame.isOpen()){
        if(i < 9) {
            std::cout << "test" << '\n';
            i++;
        }

        sf::Event event;
        while (tdgame.pollEvent(event))
        {
            switch (event.type) {
                case sf::Event::Closed:
                    tdgame.close();
                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::Q) {
                        tdgame.close();
                    }
            }
        }

    }
}
//
//
//    std::vector<pos> pos_tur, type_tur;
//    std::vector<Enemy *> inamici;
//    std::vector<Tower *> turnuri;
//    int start_time = time(nullptr), wol = 2, player_h = 100;
//    Harta map;
//    map.importmap("map1");
//    map.pos_turnuri(pos_tur);
//
//    std::cout << map;
//
//    int diff = difficulty();
//
//    clearscreen();
//
//    for(pos i : pos_tur){
//        std::string input;
//        std::cout << "Construiesti tur pe casuta de la pozitia: ("<< i.x << ", " << i.y <<") ?\n";
//        std::cout << "Variante:\nDa\nNu\n";
//        std::cin >> input;
//        if(input != "Da") {
//            //std::cout << "Variante: Artilerie....
//            turnuri.push_back(new Tower(start_time, i));
//            sleep(1);
//        }
//        else{
//            map.no_tower(i);
//        }
//        clearscreen();
//    }
//
//    while (true){
//        std::cout << map;
//        sleep(1);
//        if(turnuri.size()<2) {
//            wol = 1;
//        }
//
//        if(wol != 0){
//
//            endgame(wol);
//            break;
//        }
//
//    }
//
//    for(auto & i : turnuri)
//        delete i;
//
//    return 0;
//}
