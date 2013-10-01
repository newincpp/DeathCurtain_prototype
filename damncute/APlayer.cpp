#include <glm/gtc/matrix_transform.hpp>
#include "APlayer.hh"

DamnCute::APlayer::APlayer(const std::string& texfile, float x, float y) :
    _tex()
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

        if (sf::Keyboard::isKeyPressed(_actions[i]->getKeyboardInput2())) {
            (_actions[i])->execute(2);
        }

        if (_actions[i]->hasStickAxis() == true) {

            if (sf::Joystick::getAxisPosition(1, _actions[i]->getStickAxisInput()) > 50) {
                (_actions[i])->execute(3);
            }

            if (sf::Joystick::getAxisPosition(1, _actions[i]->getStickAxisInput()) < -50) {
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
