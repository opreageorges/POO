#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"
#include "Clase/Harta.h"
#include "Clase/Button_factory.h"
#include "Clase/Tower.h"

//Afiseaza mesajul de la sfarsit
bool endgame(bool x, const sf::Font &arial) {
    sf::RenderWindow endgame(sf::VideoMode(700, 300), "Jocul s-a terminat", sf::Style::Close);
    endgame.clear();

    sf::Text end_tx, end_sub_tx;
    end_tx.setFont(arial);
    end_sub_tx.setFont(arial);

    end_tx.setCharacterSize(100);
    end_sub_tx.setCharacterSize(24);

    end_tx.setPosition(sf::Vector2f(30.f, (300.f / 2.f - 100.f)));
    end_sub_tx.setPosition(sf::Vector2f(30.f, (300.f / 2.f - 100.f + 100.f)));

    if (x) {
        end_tx.setString("AI CASTIGAT!");
        end_tx.setFillColor(sf::Color::Green);
    } else {
        end_tx.setString("AI PIERDUT ;(");
        end_tx.setFillColor(sf::Color::Red);
    }
    end_sub_tx.setString("Apasa R pentru a juca inca o data");
    end_sub_tx.setFillColor(sf::Color::Green);
    endgame.draw(end_tx);
    endgame.draw(end_sub_tx);
    endgame.display();

    sf::Event event;

    while (endgame.isOpen()) {
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

int difficulty() {
    sf::RenderWindow diff(sf::VideoMode(500, 500), "Alege nivelul de dificultate", sf::Style::Titlebar);
    diff.clear();
    std::vector<sf::Sprite> fun_dificultati;
    std::vector<sf::IntRect> border_dificultati;

    fun_dificultati.reserve(3);
    border_dificultati.reserve(3);

    //Creaza frumusetea de butoane
    for (int i = 0; i < 3; i++) {
        sf::IntRect border(sf::Vector2i(500 / 2 - 100, 50 * (i + 1) + 75 * i), sf::Vector2i(200, 75));
        sf::Texture t;

        switch (i) {
            case 0:
                t.loadFromFile("../Resurse/Imagini/Buton_usor.png");
                border_dificultati.push_back(Button_factory::button_usor());
                break;
            case 1:
                t.loadFromFile("../Resurse/Imagini/Buton_mediu.png");
                border_dificultati.push_back(Button_factory::button_mediu());
                break;
            case 2:
                t.loadFromFile("../Resurse/Imagini/Buton_greu.png");
                border_dificultati.push_back(Button_factory::button_greu());
                break;
            default:
                break;
        }
        sf::Sprite s(t);
        fun_dificultati.push_back(s);
        fun_dificultati[i].setPosition(sf::Vector2f(500 / 2 - 100, 50 * (i + 1) + 75 * i));

        diff.draw(fun_dificultati[i]);


    }
    diff.display();

    sf::Event event;
    while (diff.isOpen()) {

        while (diff.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    diff.close();
                case sf::Event::MouseButtonPressed:
                    //std::cout << sf::Mouse::getPosition(diff).x << " " << sf::Mouse::getPosition(diff).y << '\n'
                    // << fun_dificultati[1].getPosition().x << " " << fun_dificultati[1].getPosition().y <<'\n';
                    for (int i : {0, 1, 2}) {
                        if (border_dificultati[i].contains(sf::Mouse::getPosition(diff)))
                            return i + 1;
                    }
                    break;


            }
        }
        sf::sleep(sf::milliseconds(30));
    }

    return -1;
}

// O sa fie o fereastra in care vei alege tipul de turn
int towertype(const Harta &map, sf::Font arial, int money) {
    sf::RenderWindow towertypewin(sf::VideoMode(500, 300), "Alege tipul turnului", sf::Style::Close);
    towertypewin.clear();

    sf::Texture bg_type;
    std::vector<sf::IntRect> border_type;

    bg_type.loadFromFile("../Resurse/Imagini/TType.png");
    sf::Sprite s(bg_type);
    border_type.reserve(3);

    for (int i = 0; i < 3; i++) {
        sf::IntRect bord(0 + i * 166, 0, 166, 300);
        border_type.push_back(bord);
    }


    sf::Event event;

    while (towertypewin.isOpen()) {
        towertypewin.draw(s);
        while (towertypewin.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    towertypewin.close();
                    return -1;
                    break;
                case sf::Event::MouseButtonPressed:
                    for (int i = 0; i < 3; i++) {
                        if (border_type[i].contains(sf::Mouse::getPosition(towertypewin))) {
                            towertypewin.close();
                            if (money >= (20 + 20 * (i / 2))) {
                                return i + 1;
                            } else
                                return 0;
                        }
                    }
                    break;
            }
        }
        towertypewin.display();
        sf::sleep(sf::milliseconds(100));
    }

    return 0;
}

bool startgame(const sf::Font &arial, bool debug) {

    int diff = difficulty(), player_health = 100, money = 100 / diff;
    std::string map_name;

    if (!debug) {
        bool i = true;
        while (i) {
            std::cout << "Introdu numele harti pe care vrei sa o joci:\n map1\n";
            std::cin >> map_name;
            if (map_name == "map1")
                i = false;
        }
    } else {
        map_name = "map1";
    }

    sf::RenderWindow tdgame(sf::VideoMode(800, 600), "Tower Defence", sf::Style::Close);
    tdgame.clear();

    Harta map(map_name);

    sf::Texture build_spot;
    build_spot.loadFromFile("../Resurse/Imagini/Tower_spot.png");

    sf::Event event;
    while (tdgame.isOpen()) {
        tdgame.draw(sf::Sprite(map.getback()));
        for (int i = 0; i < map.gettowerspotcount(); i++) {
            sf::Sprite spot(build_spot);
            spot.setPosition(sf::Vector2f(map.getonetowerspot(i).left, map.getonetowerspot(i).top));
            tdgame.draw(spot);
        }
        for (int i = 0; i < map.gettowerscount(); i++) {
            sf::Sprite reder_tower(map.getTowers(i)->getTexture());
            reder_tower.setPosition(map.getTowers(i)->getpos().x, map.getTowers(i)->getpos().y);
            tdgame.draw(reder_tower);
        }
        while (tdgame.pollEvent(event)) {
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
                    for (int i = 0; i < map.gettowerspotcount(); i++) {
                        if (map.getonetowerspot(i).contains(sf::Mouse::getPosition(tdgame))) {
                            int ttype = 0;
                            ttype = towertype(map, arial, money);
                            std::cout << ttype << " " << i << "\n\n\n";
                            money -= map.transform(i, ttype);

                        }
                    }
                    break;
            }
        }
        tdgame.display();

        //Fara linia asta ia foc placa video
        sf::sleep(sf::milliseconds(100));
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
