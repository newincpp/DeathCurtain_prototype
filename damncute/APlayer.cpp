#include "APlayer.hh"

DamnCute::APlayer::APlayer(const std::string& texfile, float x, float y, int nb) :
    _tex(), _nbPlayer(nb)
{
    _tex.loadFromFile(texfile);
    _player.setTexture(_tex);
    _player.setPosition(x, y);    
}

void DamnCute::APlayer::update(sf::RenderWindow* w_ptr)
{
    action();
    w_ptr->draw(_player);
}

void DamnCute::APlayer::action()
{
    for (size_t i = 0; i < _actions.size(); ++i) {

        if (sf::Keyboard::isKeyPressed(_actions[i]->getKeyboardInput1())) {
            (_actions[i])->execute(1);
        }

        else if (sf::Keyboard::isKeyPressed(_actions[i]->getKeyboardInput2())) {
            (_actions[i])->execute(2);
        }

        else if (_actions[i]->hasStickAxis() == true) {

            if (sf::Joystick::getAxisPosition(_nbPlayer, _actions[i]->getStickAxisInput()) > 50) {
                (_actions[i])->execute(3);
            }

            else if (sf::Joystick::getAxisPosition(_nbPlayer, _actions[i]->getStickAxisInput()) < -50) {
                (_actions[i])->execute(4);
            }

        }
    }
}

void DamnCute::APlayer::setActionInput(const std::string& name, sf::Keyboard::Key key)
{
    for (size_t i = 0; i < _actions.size(); ++i) {
        std::cout << name << " ; " << (_actions[i])->getName() << std::endl;
        if (name == (_actions[i])->getName()) {
            (_actions[i])->setKeyboardInput1(key);
        }
    }
}

void DamnCute::APlayer::setActionInput(const std::string& name, sf::Joystick::Axis key)
{
    for (size_t i = 0; i < _actions.size(); ++i) {
        std::cout << name << " ; " << (_actions[i])->getName() << std::endl;
        if (name == (_actions[i])->getName()) {
            (_actions[i])->setStickInput(key);
        }
    }
}

void DamnCute::APlayer::addAction(AAction* act)
{
    _actions.push_back(act);
}
