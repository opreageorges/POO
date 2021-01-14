#ifndef MAIN_CPP_BUTTON_FACTORY_H
#define MAIN_CPP_BUTTON_FACTORY_H
#include <SFML/Graphics.hpp>
#include <string>

class Button_factory {
public:
    static sf::IntRect button_usor();
    static sf::IntRect button_mediu();
    static sf::IntRect button_greu();
};


#endif
