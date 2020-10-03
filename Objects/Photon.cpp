
#include "Photon.h"

Photon::Photon()
{
    pos.x = 0, pos.y = 0;
    vel.x = 0, vel.y = 0;

    trail.setPrimitiveType(sf::LineStrip);
}

Photon::Photon(float x, float y, float dir_x, float dir_y)
{
    pos.x = x, pos.y = y;
    vel.x = dir_x / Vector2(dir_x, dir_y).mag(), vel.y = dir_y / Vector2(dir_x, dir_y).mag();
    vel.setMag(Constants::c);

    trail.setPrimitiveType(sf::LineStrip);
    trail.append(sf::Vertex(pos, sf::Color::Red));
}

void Photon::update(BlackHole& blackhole, float dt)
{
    Vector2 rPos = pos - blackhole.getPosition();
    float r = Vector2::distance(pos, blackhole.getPosition());

    Vector2 dv = - Constants::G * blackhole.getMass() * 3.3E-6f / (r * r)
                    * std::sin(vel.angle() - rPos.angle()) * Vector2(vel.y, -vel.x).normalize();

    vel += dv * dt;
    pos += vel * 1.E-6f * dt;
    trail.append(sf::Vertex(pos, sf::Color::Red));

//    std::cout << dv << ", " << vel << ", " << pos << "\n";
}

void Photon::draw(sf::RenderWindow& window)
{
    window.draw(trail);
}

const Vector2& Photon::getPosition()
{
    return pos;
}

void Photon::setPosition(float x, float y)
{
    pos.x = x;
    pos.y = y;

    trail.append(sf::Vertex(pos, sf::Color::Red));
}

void Photon::setDirection(float dir_x, float dir_y)
{
    vel.x = dir_x / Vector2(dir_x, dir_y).mag();
    vel.y = dir_y / Vector2(dir_x, dir_y).mag();
    vel.setMag(Constants::c);
}
