
#pragma once

#include "../Utilities/Vector2.h"
#include "SFML/Graphics.hpp"
#include "BlackHole.h"

class Photon
{
    private:

        Vector2 pos;
        Vector2 vel;
        sf::VertexArray trail;

    public:

        Photon(float x, float y, float dir_vx, float dir_vy);

        void move(float dx, float dy, float dt);
        void draw(sf::RenderWindow& window);
};
