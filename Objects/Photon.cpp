
#include "Photon.h"

Photon::Photon(float x, float y, float dir_vx, float dir_vy)
{
    pos.x = x, pos.y = y;
    vel.x = dir_vx / Vector2(dir_vx, dir_vy).mag(), vel.y = dir_vy / Vector2(dir_vx, dir_vy).mag();
    vel.setMag(Constants::c);

    trail.setPrimitiveType(sf::LineStrip);
    trail.append(sf::Vertex(pos, sf::Color::Red));
}

void Photon::update(BlackHole& blackhole, float dt)
{
    Vector2 acc, iVel = vel;

    Vector2 rPos = pos - blackhole.getPosition(); //Relative position of the
                                                  // photon with respect to
                                                  // the blackhole
    float r = Vector2::distance(pos, blackhole.getPosition());
    acc = - Constants::G * blackhole.getMass() / (r * r)
                    * std::sin(vel.angle() - rPos.angle()) * Vector2(vel.y, -vel.x).normalize();

    vel += acc * dt;
    pos += iVel * 1.E-6f * dt;
    trail.append(sf::Vertex(pos, sf::Color::Red));

    std::cout << acc << ", " << vel << ", " << pos << "\n";
}

void Photon::draw(sf::RenderWindow& window)
{
    window.draw(trail);
}
