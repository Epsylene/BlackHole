
#include "Drawer.h"

Drawer::Drawer()
{
    window.create(sf::VideoMode(1280, 720), "Game of Life");

    pPos.x = 300, pPos.y = 350;
    pVel.x = 10, pVel.y = 5;

    lines.setPrimitiveType(sf::LineStrip);
    lines.append(sf::Vertex(pPos, sf::Color::Black));

    blackHole.setRadius(10);
    blackHole.setFillColor(sf::Color::Black);
    blackHole.setPosition(500, 250);
    blackHole.setOrigin(5, 5);
}

void Drawer::update()
{
    dt = sfClock.getElapsedTime().asMicroseconds() / 80000.f;

    while(window.pollEvent(sfEvent))
    {
        if(sfEvent.type == sf::Event::Closed)
            window.close();
    }

    if(Vector2::distance(pPos, blackHole.getPosition()) > 5)
        updateParticle();

    sfClock.restart();
}

void Drawer::render()
{
    window.clear(sf::Color::White);

    window.draw(lines);
    window.draw(blackHole);

    if(Vector2::distance(pPos, blackHole.getPosition()) < 5
        && lines[lines.getVertexCount() - 1].position != blackHole.getPosition())
    {
        lines.append(sf::Vertex(blackHole.getPosition(), sf::Color::Black));
    }

    window.display();
}

void Drawer::run()
{
    while(window.isOpen())
    {
        update();
        render();
    }
}

void Drawer::updateParticle()
{
    pVel += -(sf::Vector2f(1000 * (pPos.x - 500) / (std::pow(pPos.x - 500, 2) + std::pow(pPos.y - 250, 2)),
                           1000 * (pPos.y - 250) / (std::pow(pPos.x - 500, 2) + std::pow(pPos.y - 250, 2)))) * dt;
    pPos += pVel * dt;

    lines.append(sf::Vertex(pPos, sf::Color::Black));
}
