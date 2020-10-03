
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

        Photon();
        Photon(float x, float y, float dir_x, float dir_y);

        const Vector2& getPosition();
        void setPosition(float x, float y);
        void setDirection(float dir_x, float dir_y);

        void update(BlackHole& blackhole, float dt);
        void draw(sf::RenderWindow& window);
};
