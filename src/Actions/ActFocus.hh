#ifndef _ACTFOCUS_H_
# define _ACTFOCUS_H_

#include <SFML/Graphics.hpp>

class ActFocus : public DamnCute::AAction<DamnCute::APlayer>
{

    public:
        explicit ActFocus(DamnCute::APlayer *p, sf::Keyboard::Key k1, int button)
            : AAction(p, k1, button), _focusTex() {
                _name = "ActFocus";
            }

        bool hasInput(int nbPlayer) {

            _nbPlayer = nbPlayer;
            return true;
        }

        void execute() {

            // @TODO: should not refresh texture at every frame, lazy programmers
            if (sf::Keyboard::isKeyPressed(_key1) ||
                    sf::Joystick::isButtonPressed(_nbPlayer, _stickButton) == true) {
                _entity->getSpeed() = 2;
                if (_nbPlayer == 0) {
                    _focusTex.loadFromFile("resources/player_focus1.tga");
                    _entity->getPlayer().setTexture(_focusTex);
                }
                if (_nbPlayer == 1) {
                    _focusTex.loadFromFile("resources/player_focus2.tga");
                    _entity->getPlayer().setTexture(_focusTex);
                }
            }
            else {
                _entity->getPlayer().setTexture(_entity->getTexture());
                _entity->getSpeed() = 5;
            } 
        }

        virtual inline const std::string& getName() const { return _name; }

        virtual ~ActFocus() = default;

    private:
        int _nbPlayer;
        std::string _name;
        sf::Texture _focusTex;

};

#endif
