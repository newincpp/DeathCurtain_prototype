#ifndef PLAYER_H_
# define PLAYER_H_

#include <iostream>
#include <vector>
#include "APlayer.hh"

#include "Actions/ActMoveX.hh"
#include "Actions/ActMoveY.hh"
#include "Actions/ActFocus.hh"
#include "Actions/ActWeapon.hh"

namespace DamnCute
{

    template <int I>
    class Player : public APlayer {

        public:
            explicit Player(const std::string& texfile = "resources/player.tga", float x = 980, float y = 950, int speed = 5) :
                APlayer(texfile, x, y, I, speed) {}

            virtual ~Player() = default;
            Player& operator=(const Player&) = delete;

        private:
            enum e {
                value = I
            };
    };

    template <>
    Player<0>::Player(const std::string& texfile, float x, float y, int speed) : APlayer(texfile, x, y, value, speed)
    {
        addAction(new ActMoveX(this, sf::Keyboard::Key::Left,
                    sf::Keyboard::Key::Right, sf::Joystick::X));
        addAction(new ActMoveY(this, sf::Keyboard::Key::Up,
                    sf::Keyboard::Key::Down, sf::Joystick::Y));
        addAction(new ActFocus(this, sf::Keyboard::Key::LShift, 2));
        addAction(new ActWeapon(this, sf::Keyboard::Key::W, 0));
    }

    template <>
    Player<1>::Player(const std::string& texfile, float x, float y, int speed) : APlayer(texfile, x, y, value, speed)
    {
        addAction(new ActMoveX(this, sf::Keyboard::Key::Q,
                    sf::Keyboard::Key::D, sf::Joystick::X));
        addAction(new ActMoveY(this, sf::Keyboard::Key::Z,
                    sf::Keyboard::Key::S, sf::Joystick::Y));
        addAction(new ActFocus(this, sf::Keyboard::Key::RShift, 2));
        addAction(new ActWeapon(this, sf::Keyboard::Key::M, 0));
    }
}

#endif
