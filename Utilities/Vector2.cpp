
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

Vector2 Vector2::copy()
{
    return Vector(this->x, this->y);
}

/// Functions
Vector2 Vector2::mult(float c)
{
    this->x *= c;
    this->y *= c;
    
    return this;
}

Vector2 Vector2::div(float c)
{
    if (c == 0) {
        std::cout << "Tried to divide by 0";
        return void;
    }
    
    this->x /= c;
    this->y /= c;
    
    return this;
}

Vector2 Vector2::setMag(float m)
{
    this->m_mag = m;
    this->m_angle = std::atan2(y, x);

    x = m_mag * std::cos(m_angle);
    y = m_mag * std::sin(m_angle);

    return this;
}

Vector2 Vector2::setAngle(float alpha)
{
    this->m_angle = alpha;

    x = m_mag * std::cos(m_angle);
    y = m_mag * std::sin(m_angle);

    return this;
}

float Vector2::dot()
{
    return std::pow(this->x, 2) + std::pow(this->y, 2);
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

Vector2 Vector2::unit(Vector2 vec)
{
    return vec * 1.f / vec.mag();
}

float Vector2::distance(Vector2 vec1, Vector2 vec2)
{
    return Vector2(vec2 - vec1).mag();
}

bool operator=(const Vector2 vec)
{
    return (x == vec.x && y == vec.y);
}

Vector2& operator+(const Vector2 vec)
{
    x += vec.x;
    y += vec.y;
    return this;
}

Vector2& operator-(const Vector2 vec)
{
    x -= vec.x;
    y -= vec.y;
    return this;
}

std::ostream& operator<<(std::ostream& out, const Vector2& vec)
{
    return out << "(" << vec.x << ", " << vec.y << ")";
}

Vector2 Vector2::normalize()
{
    float mag = static_cast<float>(std::sqrt(x*x + y*y));
    m_mag = 1.0f;

    x /= mag;
    y /= mag;

    return this;
}
