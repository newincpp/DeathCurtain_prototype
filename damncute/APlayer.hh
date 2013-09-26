#ifndef APLAYER_H_
# define APLAYER_H_

#include <iostream>
#include <vector>
#include "AAction.hh"
#include "Actions/Position.hh"
#include "IRenderable.hh"
#include "Core/Core.hh"

namespace DamnCute
{

    class APlayer : public IRenderable
    {

        public:
            explicit APlayer(const std::string& = "ressources/player.tga",
                    float = 0, float = -0.9);
            virtual ~APlayer() { }

            void update(sf::RenderWindow*);
            void addAction(AAction*);
            void setActionKey(const std::string&, int);
            void setPos(float x, float y) { _player.setPosition(x, y); }

        private:
            void action();
            APlayer& operator=(const APlayer&);
            std::vector<AAction*> _actions;

            sf::Sprite _player;
            sf::Texture _tex;

    };

}

#endif
