#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"
#include "Clase/Harta.h"
//#include "Clase/Enemy.h"
//#include "Clase/Tower.h"

//Afiseaza mesajul de la sfarsit
bool endgame(bool x, const sf::Font &arial){
    sf::RenderWindow endgame(sf::VideoMode(700,300),"Jocul s-a terminat", sf::Style::Close);
    endgame.clear();

    sf::Text end_tx, end_sub_tx;
    end_tx.setFont(arial);
    end_sub_tx.setFont(arial);

    end_tx.setCharacterSize(100);
    end_sub_tx.setCharacterSize(24);

    end_tx.setPosition(sf::Vector2f(30.f, (300.f/2.f-100.f)));
    end_sub_tx.setPosition(sf::Vector2f(30.f, (300.f/2.f-100.f +100.f)));

    if (x) {
        end_tx.setString("AI CASTIGAT!");
        end_tx.setFillColor(sf::Color::Green);
    }
    else{
        end_tx.setString("AI PIERDUT ;(" );
        end_tx.setFillColor(sf::Color::Red);
    }
    end_sub_tx.setString("Apasa R pentru a juca inca o data");
    end_sub_tx.setFillColor(sf::Color::Green);
    endgame.draw(end_tx);
    endgame.draw(end_sub_tx);
    endgame.display();

    sf::Event event;

    while(endgame.isOpen()) {
        while (endgame.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    return false;
                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::R) {
                        return true;
                    }
            }
        }
    }
    return false;
}

int difficulty(const sf::Font &arial){
    sf::RenderWindow diff(sf::VideoMode(500, 500), "Alege nivelul de dificultate", sf::Style::Titlebar);
    diff.clear();

    std::vector<sf::RectangleShape> fun_dificultati;
    std::vector<sf::IntRect> border_dificultati;
    std::vector<sf::Text> tx_dificultati;

    fun_dificultati.reserve(3);
    tx_dificultati.reserve(3);
    border_dificultati.reserve(3);

    //Creaza frumusetea de butoane
    for(int i = 0; i < 3; i++){
        sf::RectangleShape r(sf::Vector2f(200,75));
        sf::Text t;
        sf::IntRect border(sf::Vector2i(500/2-100, 50*(i+1) + 75*i ), sf::Vector2i(200,75));

        border_dificultati.push_back(border);
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
            default:
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

    sf::Event event;
    while(diff.isOpen()){

        while (diff.pollEvent(event))
        {
            switch (event.type) {
                case sf::Event::Closed:
                    diff.close();
                case sf::Event::MouseButtonPressed:
                    //std::cout << sf::Mouse::getPosition(diff).x << " " << sf::Mouse::getPosition(diff).y << '\n'
                    // << fun_dificultati[1].getPosition().x << " " << fun_dificultati[1].getPosition().y <<'\n';
                    for(int i : {0,1,2}) {
                        if(border_dificultati[i].contains(sf::Mouse::getPosition(diff)))
                            return i+1;
                    }
                    break;
                case sf::Event::Resized:
                    diff.display();
                    break;
            }
        }
    }

    return -1;
}

// O sa fie o fereastra in care vei alege tipul de turn
int towertype(){
    return 1;
}

bool startgame(const sf::Font &arial, bool debug){
    int diff = difficulty(arial), player_health = 100, money = 100/diff;
    std::string map_name;

    bool i = true;
    while (i) {
        //Cred ca pot sa fac un text box cu SFML dar e mai simplu asa
        std::cout << "Introdu numele harti pe care vrei sa o joci:\n map1\n";
        std::cin >> map_name;
        if(map_name == "map1")
            i = false;
    }

    sf::RenderWindow tdgame(sf::VideoMode(800, 600), "Tower Defence", sf::Style::Close);
    tdgame.clear();

    Harta map(map_name);
    int ttype=0;
    sf::Texture build_spot;
    build_spot.loadFromFile("../Resurse/Imagini/Tower_spot.png");

    sf::Event event;
    while(tdgame.isOpen()){
        tdgame.draw(sf::Sprite(map.getback()));
        for(int i = 0; i < map.gettowercount() ; i++){
            sf::Sprite spot(build_spot);
            spot.setPosition(sf::Vector2f (map.getonetower(i).left,map.getonetower(i).top ));
            tdgame.draw(spot);
        }
        while (tdgame.pollEvent(event))
        {
            switch (event.type) {
                case sf::Event::Closed:
                    return false;
                    break;
                case sf::Event::KeyPressed:
                    //Asta practic e un cheat pentru ca daca inchizi prin metoda asta si ai viata >0 castigi
                    if (event.key.code == sf::Keyboard::Q) {
                        tdgame.close();
                    }
                    break;
                case sf::Event::MouseButtonPressed:
                    for(int i = 0; i < map.gettowercount() ; i++){
                        if(map.getonetower(i).contains(sf::Mouse::getPosition(tdgame)))
                            map.removeonetower(i);
                            ttype = towertype();
                    }
                    break;
            }
        }
        tdgame.display();

        //Fara linia asta ia foc placa video
        sf::sleep(sf::milliseconds(4));
    }
    if (player_health > 0)
        return true;
    else
        return false;
}

int main() {
    bool test_build = 0;
    sf::Font arial;
    bool i = true;
    arial.loadFromFile("../Resurse/ArialUnicodeMS.ttf");
    while (i) {
        bool wol = startgame(arial, test_build);
        i = endgame(wol, arial);
    }

}
