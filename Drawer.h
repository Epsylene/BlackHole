
#pragma once

#include "SFML/Window.hpp"
#include "Utilities/Vector2.h"
#include "Objects/BlackHole.h"
#include "Objects/Photon.h"

class Drawer
{
    private:

        sf::RenderWindow window;
        sf::Event sfEvent;
        sf::Clock sfClock;
        float dt;

        BlackHole blackHole;
        std::array<Photon, 20> photons;

    public:

        Drawer();

        void update();
        void render();
        void run();
};
