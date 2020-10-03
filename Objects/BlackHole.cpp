
#include "BlackHole.h"

BlackHole::BlackHole(float x, float y, float mass)
{
    using namespace Constants;

    this->mass = mass;
    rs = (2 * G * mass) / (c * c);

    blackHole.setPosition(x, y);
    blackHole.setOrigin(rs, rs);
    blackHole.setRadius(rs);
    blackHole.setFillColor(sf::Color::Black);
    blackHole.setPointCount(50);

    rsCircle.setPosition(x, y);
    rsCircle.setOrigin(3*rs, 3*rs);
    rsCircle.setRadius(3*rs);
    rsCircle.setOutlineThickness(10);
    rsCircle.setOutlineColor(sf::Color(150, 150, 150));
    rsCircle.setFillColor(sf::Color::Transparent);
    rsCircle.setPointCount(100);
}

void BlackHole::draw(sf::RenderWindow &window)
{
    window.draw(rsCircle);
    window.draw(blackHole);
}

void BlackHole::setPosition(float x, float y)
{
    blackHole.setPosition(x, y);
    rsCircle.setPosition(x, y);
}

Vector2 BlackHole::getPosition()
{
    return blackHole.getPosition();
}

float BlackHole::getMass()
{
    return mass;
}
