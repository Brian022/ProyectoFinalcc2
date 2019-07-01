#ifndef PLAYER1_H
#define PLAYER1_H
#include <SFML/Graphics.hpp>
#include "Character.h"
#include "Animation.h"
#include "Platform.h"


class Player1 : public Character
{
    public:
        static Player1* Instance()
        {
            if(!pInstance)
                pInstance = new Player1(Texture* texture, Vector2u imageCount, float switchTime, float speed, float jumpHeight);
            return pInstance;
        }
        void Update(float deltaTime, Platform x, Platform* y);
        bool Colisionando(Platform x);
        bool Colisionando1(Platform* x);

    private:
        Player1(Texture* texture, Vector2u imageCount, float switchTime, float speed, float jumpHeight);

        static Player1* pInstance(Texture* texture, Vector2u imageCount, float switchTime, float speed, float jumpHeight);

};

#endif // PLAYER1_H
