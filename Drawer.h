
#pragma once

#include "SFML/Window.hpp"
#include "Vector2.h"
#include "BlackHole.h"

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

        void updateParticle();

        void update();
        void render();
        void run();
};
