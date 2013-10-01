#ifndef APLAYER_H_
# define APLAYER_H_

#include <iostream>
#include <vector>
#include "AAction.hh"
#include "IRenderable.hh"
#include "Core/Core.hh"

namespace DamnCute
{

    class APlayer : public IRenderable
    {

        public:
            explicit APlayer(const std::string& = "ressources/player.tga",
                    float = 980, float = 950);
            virtual ~APlayer() { }

            void update(sf::RenderWindow*);
            void addAction(AAction*);

            void move(float x, float y) { _player.move(x, y); }
            const sf::Vector2<float>& getPos() { return _player.getPosition(); }

            void setActionInput(const std::string&, sf::Keyboard::Key);
            void setActionInput(const std::string&, sf::Joystick::Axis);

            std::vector<AAction*> getPlayerActions() const {
                return _actions;
            }

        private:
            void action();
            APlayer& operator=(const APlayer&);
            std::vector<AAction*> _actions;

            sf::Sprite _player;
            sf::Texture _tex;
            sf::Event _event;
    };

}

#endif
