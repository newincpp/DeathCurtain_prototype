#ifndef _ACTFOCUS_H_
# define _ACTFOCUS_H_

class ActFocus : public DamnCute::AAction
{

    public:
        explicit ActFocus(DamnCute::APlayer *p, sf::Keyboard::Key k1, int button)
            : AAction(p, k1, button) {
            _name = "ActFocus";
        }

        bool hasInput(int nbPlayer) {

            if (sf::Keyboard::isKeyPressed(_key1))
                return true;               
            else if (sf::Joystick::isButtonPressed(nbPlayer, _stickButton) == true)
                return true;
            return false;
        }

        void execute() {
            std::cout << "focus" << std::endl;
        }

        virtual inline const std::string& getName() const { return (_name); }

        virtual ~ActFocus() = default;


    private:
        std::string _name;

};

#endif
