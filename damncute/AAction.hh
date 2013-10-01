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
                : _key1(k), _key2(sf::Keyboard::Unknown), _stickAxis(s), _stickButton(DC_INPUT_NONE), _player(p){}

            explicit AAction(APlayer *p, sf::Keyboard::Key k1, sf::Keyboard::Key k2, sf::Joystick::Axis s)
                : _key1(k1), _key2(k2), _stickAxis(s), _stickButton(DC_INPUT_NONE), _player(p) {}

            explicit AAction(APlayer *p, sf::Keyboard::Key k, int s)
                : _key1(k), _key2(sf::Keyboard::Unknown), _stickAxis(DC_INPUT_NONE), _stickButton(s), _player(p){}
            virtual ~AAction() {}

            virtual void execute() = 0;
            virtual const std::string& getName() const = 0;

            
            /*****************/
            /***** STICK *****/
            /*****************/

            /*sf::Joystick::Axis*/int getStickAxisInput() const { return _stickAxis; }
            int getStickButtonInput() const { return _stickButton; }

            void setStickInput(sf::Joystick::Axis input) { _stickAxis = input; }
            void setStickInput(int input) { _stickButton = input; }


            /****************/
            /*** KEYBOARD ***/
            /****************/
            
            sf::Keyboard::Key getKeyboardInput1() const { return (_key1); }
            sf::Keyboard::Key getKeyboardInput2() const { return (_key2); }

            void setKeyboardInput1(sf::Keyboard::Key input) { _key1 = input; }
            void setKeyboardInput2(sf::Keyboard::Key input) { _key2 = input; }

        protected:
            sf::Keyboard::Key _key1;
            sf::Keyboard::Key _key2;
            int _stickAxis; // should be a sf::Joystick::Axis but this isn't possible
            int _stickButton;
            APlayer *_player;

    };

}

#endif
