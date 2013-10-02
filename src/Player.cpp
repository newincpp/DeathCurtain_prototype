#include "Player.hh"

DamnCute::Player::Player(const std::string& texfile, float x, float y) :
    APlayer(texfile, x, y, 0)
{
    addAction(new ActMoveX(this, sf::Keyboard::Key::Left, sf::Keyboard::Key::Right, sf::Joystick::X));
    addAction(new ActMoveY(this, sf::Keyboard::Key::Up, sf::Keyboard::Key::Down, sf::Joystick::Y));
}

DamnCute::Player::~Player()
{
}
