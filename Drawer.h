
#pragma once

#include "SFML/Window.hpp"
#include "Utilities/Vector2.h"
#include "Objects/BlackHole.h"

class Drawer
{
    private:

        sf::RenderWindow window;
        sf::Event sfEvent;
        sf::Clock sfClock;
        float dt;

        BlackHole blackHole;

    public:

        Drawer();

        void update();
        void render();
        void run();
};
