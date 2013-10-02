#ifndef _ACTMOVEX_H_
# define _ACTMOVEX_H_

class ActMoveX : public DamnCute::AAction
{

    public:
        explicit ActMoveX(DamnCute::APlayer *p, sf::Keyboard::Key k1, sf::Keyboard::Key k2, sf::Joystick::Axis s) : AAction(p, k1, k2, s) {
            _name = "ActMoveX";
        }

        void execute(int param)
        {
            if (param == 2 || param == 3)
                _player->move(5, 0);
            else if (param == 1 || param == 4)
                _player->move(-5, 0);
        }

        virtual inline const std::string& getName() const { return (_name); }

        virtual ~ActMoveX() {}

    private:
        std::string _name;

};

#endif
