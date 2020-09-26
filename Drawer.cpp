
#include "Drawer.h"

Drawer::Drawer(): blackHole(0, 0, 20E28)
{
    window.create(sf::VideoMode(1280, 720), "Game of Life");

    blackHole.setPosition(window.getSize().x / 2.f,
                          window.getSize().y / 2.f);
}

void Drawer::update()
{
    dt = sfClock.getElapsedTime().asMicroseconds() / 80000.f;

    while(window.pollEvent(sfEvent))
    {
        if(sfEvent.type == sf::Event::Closed)
            window.close();
    }

    sfClock.restart();
}

void Drawer::render()
{
    window.clear(sf::Color::White);

    blackHole.draw(window);

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


//    lines.append(sf::Vertex(pPos, sf::Color::Black));
}
