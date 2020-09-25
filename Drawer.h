
#pragma once

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

class Drawer
{
    private:

        sf::RenderWindow window;
        sf::Event sfEvent;

        sf::Texture backgroundTex;
        sf::Image backgroundImg;
        sf::Sprite background;

    public:

        Drawer();

        void update();
        void render();
        void run();
};
