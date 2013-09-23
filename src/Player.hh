#ifndef PLAYER_H_
# define PLAYER_H_

#include <iostream>
#include <vector>
#include "../APlayer.hh"
#include "../Actions/ActFocus.hh"
#include "../Actions/ActMoveLeft.hh"
#include "../Actions/ActMoveRight.hh"
#include "../Actions/ActMoveUp.hh"
#include "../Actions/ActMoveDown.hh"
#include "../Actions/ActZDown.hh"
#include "../Actions/ActZUp.hh"
#include "../Actions/ActWeapon.hh"

namespace DamnCute
{

    class Player : public APlayer
    {

        public:
            explicit Player(const std::string& = "ressources/tmpPlayer.tga",
                            float = 0, float = -0.5);
            virtual ~Player();

        private:
            Player& operator=(const Player&);

    };

}

#endif
