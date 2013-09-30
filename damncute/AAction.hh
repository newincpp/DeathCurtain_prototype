#ifndef _AACTION_H_
# define _AACTION_H_

#include "Core/Core.hh"
#include <SFML/Window/Joystick.hpp>
#include "APlayer.hh"

namespace DamnCute
{

    class APlayer;

    class AAction
    {

        public:
            explicit AAction(APlayer *p, sf::Keyboard::Key k, sf::Joystick::Axis s)
                : _keyboard(k), _stick(s), _player(p) {}
            virtual ~AAction() {}

            virtual void execute() = 0;
            virtual const std::string& getName() const = 0;

            /*sf::Joystick::Axis getStickInput() const {
                return sf::Joystick::getAxisPosition(char, sf::Joystick);
            }*/
            void setStickInput(sf::Joystick::Axis input) { _stick = input; }

            sf::Keyboard::Key getKeyboardInput() const { return (_keyboard); }
            void setKeyboardInput(sf::Keyboard::Key input) { _keyboard = input; }

        protected:
            sf::Keyboard::Key _keyboard;
            sf::Joystick::Axis _stick;
            APlayer *_player;

    };

}

#endif
