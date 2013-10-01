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
    _event = Core::getInstance()->getEvent();
    action();
    w_ptr->draw(_player);
}

void DamnCute::APlayer::action()
{
    if (_event.type == sf::Event::KeyPressed) {
        /*for (size_t i = 0; i < _actions.size(); ++i) {
          if (_event.key.code == _actions[i]->getKeyboardInput1())
          (_actions[i])->execute();
          }*/
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
