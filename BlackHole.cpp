
#include "BlackHole.h"

BlackHole::BlackHole(float x, float y, float mass)
{
    using namespace Constants;

    this->mass = mass;
    rs = (2 * G * mass) / (c * c);

    blackHole.setPosition(x, y);
    blackHole.setOrigin(rs / 2.f, rs / 2.f);
    blackHole.setRadius(rs / 2.f);
    blackHole.setFillColor(sf::Color::Black);

    rsCircle.setPosition(x, y);
    rsCircle.setOrigin(rs, rs);
    rsCircle.setRadius(rs);
    rsCircle.setOutlineThickness(1);
    rsCircle.setOutlineColor(sf::Color::Black);
    rsCircle.setPointCount(50);
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
