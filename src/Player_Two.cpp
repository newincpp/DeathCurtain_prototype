#include "Player_Two.hh"

DamnCute::Player_Two::Player_Two(const std::string& texfile, float x, float y) :
    APlayer(texfile, x, y, 1)
{
    addAction(new ActMoveX(this, sf::Keyboard::Key::Q, sf::Keyboard::Key::D, sf::Joystick::X));
    addAction(new ActMoveY(this, sf::Keyboard::Key::Z, sf::Keyboard::Key::S, sf::Joystick::Y));
}



DamnCute::Player_Two::~Player_Two()
{
}
