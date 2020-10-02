
#include "Vector2.h"

/// Constructors

Vector2::Vector2(): m_mag(0.f), m_angle(0.f)
{}

Vector2::Vector2(float x, float y)
{
    this->x = x;
    this->y = y;

    m_mag = static_cast<float>(std::sqrt(std::pow(x, 2) + std::pow(y, 2)));
    m_angle = static_cast<float>(std::atan2(y, x));
}

Vector2::Vector2(sf::Vector2f vec)
{
    this->x = vec.x;
    this->y = vec.y;

    m_mag = static_cast<float>(std::sqrt(std::pow(x, 2) + std::pow(y, 2)));
    m_angle = std::atan2(y, x);
}

Vector2::Vector2(Vector2 &vec)
{
    this->x = vec.x;
    this->y = vec.y;

    m_mag = vec.mag();
    m_angle = vec.angle();
}

/// Functions

Vector2 Vector2::setMag(float m)
{
    this->m_mag = m;
    this->m_angle = std::atan2(y, x);

    x = m_mag * std::cos(m_angle);
    y = m_mag * std::sin(m_angle);

    return Vector2(x, y);
}

sf::Vector2f Vector2::setAngle(float alpha)
{
    this->m_angle = alpha;

    x = m_mag * std::cos(m_angle);
    y = m_mag * std::sin(m_angle);

    return sf::Vector2f(x, y);
}

float Vector2::mag()
{
    return static_cast<float>(std::sqrt(std::pow(x, 2) + std::pow(y, 2)));
}

float Vector2::angle()
{
    return std::atan2(y, x);
}

float Vector2::getMag(Vector2 vec)
{
    return static_cast<float>(std::sqrt(std::pow(vec.x, 2) + std::pow(vec.y, 2)));
}

float Vector2::getAngle(Vector2 vec1, Vector2 vec2)
{
return vec2.angle() - vec1.angle();
}

float Vector2::distance(Vector2 vec1, Vector2 vec2)
{
    return Vector2(vec2 - vec1).mag();
}

std::ostream& operator<<(std::ostream& out, const Vector2& vec)
{
    return out << "(" << vec.x << ", " << vec.y << ")";
}
