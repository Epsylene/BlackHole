
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

    rsCircle.setPosition(x, y);
    rsCircle.setOrigin(3*rs, 3*rs);
    rsCircle.setRadius(3*rs);
    rsCircle.setOutlineThickness(1);
    rsCircle.setOutlineColor(sf::Color::Black);
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
