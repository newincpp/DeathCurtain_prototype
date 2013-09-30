#ifndef _ACTMOVELEFT_H_
# define _ACTMOVELEFT_H_

#include "../damncute/AAction.hh"

class ActMoveLeft : public DamnCute::AAction
{

    public:
        explicit ActMoveLeft(DamnCute::APlayer *p, sf::Keyboard::Key k, sf::Joystick::Axis s) : AAction(p, k, s) {
            _name = "ActMoveLeft";
        }

        void execute()
        {
            _player->move(-5, 0);
        }

        virtual inline const std::string& getName() const { return (_name); }

        virtual ~ActMoveLeft() {}

    private:
        std::string _name;

};

#endif
