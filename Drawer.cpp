
#include "Drawer.h"

Drawer::Drawer(): blackHole(0, 0, 5E28), photon(0, 0, 1, 1)
{
    window.create(sf::VideoMode(1280, 720), "Black hole");

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

    photon.update(dt);

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
