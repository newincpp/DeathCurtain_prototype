#ifndef _ACTMOVEY_H_
# define _ACTMOVEY_H_

class ActMoveY : public DamnCute::AAction
{

    public:
        explicit ActMoveY(DamnCute::APlayer *p, sf::Keyboard::Key k1, sf::Keyboard::Key k2, sf::Joystick::Axis s) : AAction(p, k1, k2, s) {
            _name = "ActMoveY";
        }

        void execute(int param)
        {
            if (param == 2 || param == 3)
                _player->move(0, 5);
            else if (param == 1 || param == 4)
                _player->move(0, -5);
        }

        virtual inline const std::string& getName() const { return (_name); }

        virtual ~ActMoveY() {}

    private:
        std::string _name;

};

#endif
