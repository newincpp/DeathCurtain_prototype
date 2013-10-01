#ifndef _ACTMOVELATERAL_H_
# define _ACTMOVELATERAL_H_

class ActMoveLateral : public DamnCute::AAction
{

    public:
        explicit ActMoveLateral(DamnCute::APlayer *p, sf::Keyboard::Key k1, sf::Keyboard::Key k2, sf::Joystick::Axis s) : AAction(p, k1, k2, s) {
            _name = "ActMoveRight";
        }

        void execute(int param)
        {
            if (param == 1 || param == 3)
                _player->move(5, 0);
            else if (param == 2 || param == 4)
                _player->move(-5, 0);
        }

        virtual inline const std::string& getName() const { return (_name); }

        virtual ~ActMoveLateral() {}

    private:
        std::string _name;

};

#endif
