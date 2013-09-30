#ifndef _ACTMOVERIGHT_H_
# define _ACTMOVERIGHT_H_

class ActMoveRight : public DamnCute::AAction
{

    public:
        explicit ActMoveRight(DamnCute::APlayer *p, sf::Keyboard::Key k, sf::Joystick::Axis s) : AAction(p, k, s) {
            _name = "ActMoveRight";
        }

        void execute()
        {
            _player->move(5, 0);
        }

        virtual inline const std::string& getName() const { return (_name); }

        virtual ~ActMoveRight() {}

    private:
        std::string _name;

};

#endif
