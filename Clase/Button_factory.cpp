//
// Created by George on 14-Jan-21.
//

#include "Button_factory.h"


sf::IntRect Button_factory::button_usor() {
    return sf::IntRect(sf::Vector2i(150, 50),sf::Vector2i(200, 75));
}

sf::IntRect Button_factory::button_mediu() {
    return sf::IntRect(sf::Vector2i(150, 175),sf::Vector2i(200, 75));
}

sf::IntRect Button_factory::button_greu() {
    return sf::IntRect(sf::Vector2i(150, 300),sf::Vector2i(200, 75));
}
