#ifndef BULLET_H
#define BULLET_H
#include <SFML\Graphics.hpp>
#include "Character.h"
using namespace sf;

class Bullet
{
    public:
        Bullet(Texture* texture, Vector2f size, Vector2f position);
        ~Bullet();
        void fire(float deltaTime)
        {
                body.move(deltaTime,0);
        }
        int getRight()
        {
            return body.getPosition().x+body.getSize().x;
        }
        int getLeft() {
            return body.getPosition().x;
        }
        void Draw(RenderWindow& window);


    RectangleShape body;
};

#endif // BULLET_H
