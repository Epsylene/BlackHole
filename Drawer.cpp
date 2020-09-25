
#include "Drawer.h"

Drawer::Drawer()
{
    window.create(sf::VideoMode(1024, 576), "Game of Life");

    backgroundImg.create(1024, 576, sf::Color::White);
    backgroundTex.create(1024, 576);
    background.setTexture(backgroundTex);
}

void Drawer::update()
{
    while(window.pollEvent(sfEvent))
    {
        if(sfEvent.type == sf::Event::Closed)
            window.close();
    }

    backgroundTex.update(backgroundImg);
}

void Drawer::render()
{
    window.clear();

    window.draw(background);

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
