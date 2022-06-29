#include <iostream>
#include <cmath>
#include<SFML/Graphics.hpp>
#include<string.h>


using namespace std;
using namespace sf;

int main()

{
    RenderWindow window(VideoMode(600, 600), "Le Maze");

    Vector2i player = Vector2i(13, 13);
    RectangleShape playerRect = RectangleShape(Vector2f(40.f, 40.f));
    playerRect.setPosition(player.x * 40.0f, player.y * 40.0f);

    Vector2i treasure = Vector2i(13, 13);
    RectangleShape mash = RectangleShape(Vector2f(40.f, 40.f));
    mash.setPosition(40, 520);

    int gameMap[15 * 15];

    sf::Texture playerTexture;
    playerTexture.loadFromFile("../player.png");
    playerRect.setTexture(&playerTexture);
    sf::Sprite mario;
    mario.setTexture(playerTexture);
    mario.setPosition(520, 520);


    sf::Texture treasureTexture;
    treasureTexture.loadFromFile("../final.png");
    mash.setTexture(&treasureTexture);


    sf::RectangleShape displayRects[15 * 15];


    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            displayRects[i + j * 15].setPosition(i * 40.f, j * 40.f);
            displayRects[i + j * 15].setSize(sf::Vector2f(40.f, 40.f));
            displayRects[i + j * 15].setOutlineThickness(1.f);
            displayRects[i + j * 15].setOutlineColor(Color(238, 238, 238));

            if (std::rand() / (float)RAND_MAX < 0.267f || i == 0 || j == 0 || i == 14 || j == 14)
            {
                gameMap[i + j * 15] = 1;
                displayRects[i + j * 15].setFillColor(Color(34, 40, 49));
            }

        }
    }


    sf::Font font;
    font.loadFromFile("../ufo.ttf");
    sf::Text text;
    text.setFont(font);
    text.setString("Oh yeah! Mario Time!");
    text.setCharacterSize(50);
    text.setFillColor(sf::Color(214,90,48));
    text.setPosition(40, 290);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();

            else if (event.type == sf::Event::KeyPressed) {
                switch (event.key.code) {
                case sf::Keyboard::Up:
                    while (gameMap[player.x + (player.y - 1) * 15] != 1)
                    {

                        player.y--;
                        playerRect.setPosition(player.x * 40.0f, player.y * 40.0f);
                    }
                    break;
                case sf::Keyboard::Down:
                    while (gameMap[player.x + (player.y + 1) * 15] != 1)
                    {
                        player.y += 1;
                        playerRect.setPosition(player.x * 40.0f, player.y * 40.0f);
                    }
                    break;
                case sf::Keyboard::Right:
                    while (gameMap[(player.x + 1) + player.y * 15] != 1)
                    {
                        player.x += 1;
                        playerRect.setPosition(player.x * 40.0f, player.y * 40.0f);
                    }
                    break;
                case sf::Keyboard::Left:
                    while (gameMap[(player.x - 1) + player.y * 15] != 1) {
                        player.x -= 1;
                        playerRect.setPosition(player.x * 40.0f, player.y * 40.0f);
                    }
                    break;
                }
            }
        }

        window.clear(Color(214, 90, 48));
        for (int i = 0; i < 15 * 15; i++) {
            window.draw(displayRects[i]);
        }

        window.draw(mash);
        window.draw(playerRect);

        if (playerRect.getPosition().x == mash.getPosition().x && playerRect.getPosition().y == mash.getPosition().y)
        {
            window.draw(text);
        }

        


        window.display();

    }
}