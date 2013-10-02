#ifndef _ACTMOVEY_H_
# define _ACTMOVEY_H_

#define K1 0
#define K2 1
#define ST1 2
#define ST2 3

class ActMoveY : public DamnCute::AAction
{

    public:
        explicit ActMoveY(DamnCute::APlayer *p, sf::Keyboard::Key k1, sf::Keyboard::Key k2, sf::Joystick::Axis stAxis) : AAction(p, k1, k2, stAxis) {
            _name = "ActMoveY";
        }

        bool hasInput(int nbPlayer) {
            if (sf::Keyboard::isKeyPressed(_key1)) {
                _who = K1;
                return true;
            }

            else if (sf::Keyboard::isKeyPressed(_key2)) {
                _who = K2;
                return true;
            }

            else if (hasStickAxis() == true) {

                if (sf::Joystick::getAxisPosition(nbPlayer, _stickAxis) < -50) {
                    _who = ST1;
                    return true;
                }

                else if (sf::Joystick::getAxisPosition(nbPlayer, _stickAxis) > 50) {
                    _who = ST2;
                    return true;
                }

            }
            return false;
        }

        void execute() {
            if (_who == K2 || _who == ST2)
                _player->move(0, 5);
            if (_who == K1 || _who == ST1)
                _player->move(0, -5);
        }

        virtual inline const std::string& getName() const { return (_name); }

        virtual ~ActMoveY() = default;

    private:
        int _who;
        std::string _name;

};

#endif
