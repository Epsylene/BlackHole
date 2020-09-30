
#include "Photon.h"

Photon::Photon(float x, float y, float dir_vx, float dir_vy)
{
    pos.x = x, pos.y = y;
    vel.x = dir_vx, vel.y = dir_vy;
    vel.setMag(Constants::c);

    trail.setPrimitiveType(sf::LineStrip);
    trail.append(sf::Vertex(pos, sf::Color::Red));
}

void Photon::update(float dt)
{
    pos += vel * 1.E-7f * dt;
    trail.append(sf::Vertex(pos, sf::Color::Red));
}

void Photon::draw(sf::RenderWindow& window)
{
    window.draw(trail);
}
