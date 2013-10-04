#include "APlayer.hh"

DamnCute::APlayer::APlayer(const std::string& texfile, float x, float y, int nb, int speed) :
    _tex(), _speed(speed), _nbPlayer(nb)
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
        if (_actions[i]->hasInput(_nbPlayer) == true)
            _actions[i]->execute();
    }
}

void DamnCute::APlayer::addAction(AAction* act)
{
    _actions.push_back(act);
}


template <>
void DamnCute::APlayer::setActionInput<sf::Keyboard::Key>(int i, sf::Keyboard::Key key, int inputNumber) {
    if (inputNumber == 1)
        (_actions[i])->setKeyboardInput1(key);
    else if (inputNumber == 2)
        (_actions[i])->setKeyboardInput2(key);
    else
        std::cerr << "Error: key should be 1 or 2" << std::endl;
}

template <>
void DamnCute::APlayer::setActionInput<sf::Joystick::Axis>(int i, sf::Joystick::Axis axis, int a) {
    (void)a;
    (_actions[i])->setStickInput(axis);
}

template <>
void DamnCute::APlayer::setActionInput<int>(int i, int button, int a) {
    (void)a;
    (_actions[i])->setStickInput(button);
}
