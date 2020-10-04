
#pragma once

#include <cmath>
#include <iostream>
#include "SFML/Graphics.hpp"

class Vector2: public sf::Vector2f
{
    public:

        float m_mag, m_angle;

        Vector2();
        Vector2(float x, float y);
        Vector2(sf::Vector2f vec);
        Vector2(Vector2& vec);
        
        Vector2 copy();

        Vector2 setMag(float m);
        Vector2 setAngle(float alpha);
        Vector2 normalize();
        
        Vector2 mult(float c);
        Vector2 div(float c);

        static float getMag(Vector2 vec);
        static float getAngle(Vector2 vec1, Vector2 vec2);
        static Vector2 unit(Vector2 vec);

        float mag();
        float angle();
        static float distance(Vector2 vec1, Vector2 vec2);

        friend std::ostream& operator<<(std::ostream& out, const Vector2& vec);
};
