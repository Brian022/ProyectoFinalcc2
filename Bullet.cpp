#include "Bullet.h"
#include "Character.h"
Bullet::Bullet(Texture* texture, Vector2f size, Vector2f position)
{
        body.setSize(size);
        body.setTexture(texture);
        body.setPosition(position);
}

Bullet::~Bullet()
{
    //dtor
}

void Bullet::Draw(RenderWindow& window)
{
    window.draw(body);
}

