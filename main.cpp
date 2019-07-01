#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Character.h"
#include "Player.h"
#include "Player1.h"
#include "Platform.h"
#include "Bullet.h"
using namespace sf;
using namespace std;

static const float viewHeight = 1200;
void ResizeView(const RenderWindow& window, View& view)
{
    float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
    view.setSize(viewHeight * aspectRatio, viewHeight);
}

int main()
{
    RenderWindow window(VideoMode(1200, 600), "SFML works!", Style::Resize | Style::Close);
    View view(Vector2f(0.0f,0.0f), Vector2f(600, 600));
    view.setViewport(sf::FloatRect(0.f, 0.f, 0.5f, 1.f));

    View view1(Vector2f(0.0f,0.f), Vector2f(600, 600));
    view1.setViewport(sf::FloatRect(0.5f, 0.f, 0.5f, 1.f));
    //background sprite
    RectangleShape background(Vector2f(1200, 600));
    background.setTextureRect(sf::IntRect(0, 0, 1200, 600));
    Texture backgroundtexture;
    backgroundtexture.loadFromFile("../cityArt.jpg");
    background.setTexture(&backgroundtexture);
    //TEXTURA DEL PRIMER JUGADOR
    Texture playerTexture;
    playerTexture.loadFromFile("../Boy1.png");
    //TEXTURA DE OTRO JUGADOR
    Texture player1Texture;
    player1Texture.loadFromFile("../Girl1.png");
    Texture ground;
    ground.loadFromFile("../ground.png");

    Player player(&playerTexture, Vector2u(4,4), 0.3, 200.0f, 150.0f);
    Player1 player1(&player1Texture, Vector2u(8,4), 0.3f, 200.0f, 150.0f);

    Texture ball;
    ball.loadFromFile("../bala.png");


    vector<Bullet> bulletvec;
    vector<Bullet> bulletvec1;


    Platform platform1(&ground, Vector2f(3000.0f, 25.0f), Vector2f(0.0f,500.0f));
    platform1.GetPosition();

    vector<Platform*> plataformas;

    plataformas.push_back(Platform::Crear(1, &ground,Vector2f(245.0f, 25.0f), Vector2f(0.0f,500.0f)));
    plataformas[0]->GetPosition();







    float deltaTime = 0.0f;
    Clock clock;

    while (window.isOpen() )
    {
        deltaTime = clock.restart().asSeconds();
        if(deltaTime > 1.0f/20.0f)
            deltaTime = 1.0f/20.0f;

        Event evnt;
        while (window.pollEvent(evnt))
        {
            switch(evnt.type)
            {
            case Event::Closed:
                window.close();
                break;
            case Event::Resized:
                ResizeView(window, view);
                ResizeView(window, view1);
                break;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
                player.isFiring= true;
        }


        player.Update(deltaTime, platform1, plataformas[0]);
        player1.Update(deltaTime,platform1, plataformas[0]);

        if (player.isFiring == true)
        {
            Bullet newBullet(&ball,Vector2f(50.0f,50.0f),Vector2f(player.GetPosition()));
            bulletvec.push_back(newBullet);
            player.isFiring = false;
        }
        window.clear();

        window.setView(view);
        view.setCenter(player.GetPosition());
        window.draw(background);
        plataformas[0]->Draw(window);
        for (int i = 0; i < bulletvec.size(); i++)
        {
            bulletvec[i].Draw(window);
            if(player.faceRight == true)
                bulletvec[i].fire(3);
            else
                bulletvec[i].fire(-3);
        }
        player.Draw(window);
        player1.Draw(window);
        platform1.Draw(window);


        window.setView(view1);
        view1.setCenter(player1.GetPosition());
        window.draw(background);
        plataformas[0]->Draw(window);
        for (int i = 0; i < bulletvec.size(); i++)
        {
            bulletvec[i].Draw(window);
            if(player.faceRight == true)
                bulletvec[i].fire(3);
            else
                bulletvec[i].fire(-20);
        }
        player.Draw(window);
        player1.Draw(window);
        platform1.Draw(window);


        window.display();
    }

    for(int i=0; i<plataformas.size();i++)
    {
        delete plataformas[i];
    }

    return 0;
}
