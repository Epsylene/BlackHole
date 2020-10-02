
#pragma once

#include "../Utilities/Vector2.h"
#include "SFML/Graphics.hpp"

namespace Constants
{
    const float c = 299792458.f; //Light speed
    const float G = 6.67E-11; //Gravitational constant
}

class BlackHole
{
    private:

        float mass;
        float rs; //Schwarzschild radius

        sf::CircleShape rsCircle;
        sf::CircleShape blackHole;

    public:

        BlackHole(float x, float y, float mass);

        Vector2 getPosition();
        float getMass();

        void setPosition(float x, float y);
        void draw(sf::RenderWindow& window);
};
