#ifndef _AACTION_H_
# define _AACTION_H_

#include "Core/Core.hh"
#include <SFML/Window/Joystick.hpp>
#include "APlayer.hh"

#define DC_INPUT_NONE 99999

namespace DamnCute
{

    class APlayer;

    class AAction
    {

        public:
            explicit AAction(APlayer *p, sf::Keyboard::Key k, sf::Joystick::Axis s)
                : _key1(k), _key2(sf::Keyboard::Unknown), _stickAxis(s), _stickButton(DC_INPUT_NONE), _hasAxis(true), _player(p) { }

            explicit AAction(APlayer *p, sf::Keyboard::Key k1, sf::Keyboard::Key k2, sf::Joystick::Axis s)
                : _key1(k1), _key2(k2), _stickAxis(s), _stickButton(DC_INPUT_NONE), _hasAxis(true), _player(p) { }

            explicit AAction(APlayer *p, sf::Keyboard::Key k, int s)
                : _key1(k), _key2(sf::Keyboard::Unknown), _stickAxis(sf::Joystick::Axis::X), _stickButton(s), _hasAxis(false), _player(p) { }

            virtual ~AAction() {}

            virtual void execute() = 0;
            virtual const std::string& getName() const = 0;
            virtual bool hasInput(int) = 0;

            inline bool hasStickAxis() const { return _hasAxis; }

            void setStickInput(sf::Joystick::Axis input) { _stickAxis = input; }
            void setStickInput(int input) { _stickButton = input; }
            void setKeyboardInput1(sf::Keyboard::Key input) { _key1 = input; }
            void setKeyboardInput2(sf::Keyboard::Key input) { _key2 = input; }

        protected:
            sf::Keyboard::Key _key1;
            sf::Keyboard::Key _key2;
            sf::Joystick::Axis _stickAxis;
            int _stickButton;
            bool _hasAxis;
            APlayer *_player;

    };

}

/*template <>
void DamnCute::AAction::setInput(sf::Joystick::Axis input)
{
    _stickAxis = input;
}*/

#endif
