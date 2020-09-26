
#pragma once

#include "SFML/Window.hpp"
#include "Vector2.h"

class Drawer
{
    private:

        sf::RenderWindow window;
        sf::Event sfEvent;
        sf::Clock sfClock;
        float dt;

        sf::CircleShape blackHole;

        Vector2 pPos;
        Vector2 pVel;
        sf::VertexArray lines;

    public:

        Drawer();

        void updateParticle();

        void update();
        void render();
        void run();
};
