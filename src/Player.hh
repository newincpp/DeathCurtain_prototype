#ifndef PLAYER_H_
# define PLAYER_H_

#include <iostream>
#include <vector>
#include "../damncute/APlayer.hh"

#include "Actions/ActMoveX.hh"
#include "Actions/ActMoveY.hh"
#include "Actions/ActFocus.hh"

namespace DamnCute
{

    template <int I>
    class Player : public APlayer {

        public:
            explicit Player(const std::string& texfile = "ressources/player.tga",
                    float x = 980, float y = 950) :
                APlayer(texfile, x, y, I) {}

            virtual ~Player() = default;

            Player& operator=(const Player&) = delete;

        private:
            enum e {
                value = I
            };
    };

   template <>
   class Player<0> : public APlayer {

       public:
           explicit Player(const std::string& texfile = "ressources/player.tga",
                   float x = 980, float y = 950) : APlayer(texfile, x, y, 0)
           {
               addAction(new ActMoveX(this, sf::Keyboard::Key::Left,
                           sf::Keyboard::Key::Right, sf::Joystick::X));
               addAction(new ActMoveY(this, sf::Keyboard::Key::Up,
                           sf::Keyboard::Key::Down, sf::Joystick::Y));
               addAction(new ActFocus(this, sf::Keyboard::Key::LShift, 0));
           }
           virtual ~Player() = default;

           Player& operator=(const Player&) = delete;
   };

   template <>
   class Player<1> : public APlayer {

        public:
            explicit Player(const std::string& texfile = "ressources/player.tga",
                    float x = 980, float y = 950) : APlayer(texfile, x, y, 1)
            {
                addAction(new ActMoveX(this, sf::Keyboard::Key::Q,
                            sf::Keyboard::Key::D, sf::Joystick::X));
                addAction(new ActMoveY(this, sf::Keyboard::Key::Z,
                            sf::Keyboard::Key::S, sf::Joystick::Y));
                addAction(new ActFocus(this, sf::Keyboard::Key::RShift, 0));
            }
            virtual ~Player() = default;

            Player& operator=(const Player&) = delete;
    };

}

#endif
