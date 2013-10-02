#ifndef PLAYER_TWO_H_
# define PLAYER_TWO_H_

#include <iostream>
#include <vector>
#include "../damncute/APlayer.hh"

#include "Actions/ActMoveX.hh"
#include "Actions/ActMoveY.hh"

namespace DamnCute
{

    class Player_Two : public APlayer
    {

        public:
            explicit Player_Two(const std::string& = "ressources/player.tga",
                            float = 980, float = 950);
            virtual ~Player_Two();

        private:
            Player_Two& operator=(const Player_Two&);

    };

}

#endif
