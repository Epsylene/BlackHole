
#include "Drawer.h"

Drawer::Drawer(): blackHole(0, 0, 5E23), photon(0, 100, 1, 0)
{
    window.create(sf::VideoMode(1280, 720), "Black hole");

    blackHole.setPosition(window.getSize().x / 2.f,
                          window.getSize().y / 2.f);
}

void Drawer::update()
{
    dt = sfClock.getElapsedTime().asMicroseconds() / 1000000.f;

    while(window.pollEvent(sfEvent))
    {
        if(sfEvent.type == sf::Event::Closed)
            window.close();
    }

    photon.update(blackHole, dt);

    sfClock.restart();
}

void Drawer::render()
{
    window.clear(sf::Color::White);

    blackHole.draw(window);
    photon.draw(window);

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
