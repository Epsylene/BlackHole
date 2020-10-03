
#include "Drawer.h"

Drawer::Drawer(): blackHole(640, 360, 5E28)
{
    window.create(sf::VideoMode(1280, 720), "Black hole");

    for (int i = 0; i < photons.size(); ++i)
    {
        photons[i].setPosition(0, i * 15 + 10);
        photons[i].setDirection(1, 0);
    }
}

void Drawer::update()
{
    dt = sfClock.getElapsedTime().asMicroseconds() / 1000000.f;

    while(window.pollEvent(sfEvent))
    {
        if(sfEvent.type == sf::Event::Closed)
            window.close();
    }

    for (auto& ph: photons) 
    {
        if(Vector2::distance(ph.getPosition(), blackHole.getPosition()) > 75)
            ph.update(blackHole, dt);
    }

//    std::cout << photons[0].getPosition();
    
    sfClock.restart();
}

void Drawer::render()
{
    window.clear(sf::Color::White);

    blackHole.draw(window);

    for (auto& ph: photons)
    {
        ph.draw(window);
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
