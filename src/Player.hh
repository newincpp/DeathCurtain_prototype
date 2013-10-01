#ifndef PLAYER_H_
# define PLAYER_H_

#include <iostream>
#include <vector>
#include "../damncute/APlayer.hh"
/*#include "../Actions/ActFocus.hh"*/
/*#include "Actions/ActMoveLeft.hh"
#include "Actions/ActMoveRight.hh"*/

#include "Actions/ActMoveLateral.hh"

/*#include "../Actions/ActMoveUp.hh"
#include "../Actions/ActMoveDown.hh"
#include "../Actions/ActZDown.hh"
#include "../Actions/ActZUp.hh"
#include "../Actions/ActWeapon.hh"*/

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
