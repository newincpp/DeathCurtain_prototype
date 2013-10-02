#ifndef PLAYER_H_
# define PLAYER_H_

#include <iostream>
#include <vector>
#include "../damncute/APlayer.hh"

#include "Actions/ActMoveX.hh"
#include "Actions/ActMoveY.hh"

namespace DamnCute
{

    class Player : public APlayer
    {

        public:
            explicit Player(const std::string& = "ressources/player.tga",
                            float = 980, float = 950);
            virtual ~Player();

        private:
            Player& operator=(const Player&);

    };

}

#endif
