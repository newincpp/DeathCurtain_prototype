#include "Player.hh"

DamnCute::Player::Player(const std::string& texfile, float x, float y) :
    APlayer(texfile, x, y)
{

    /*addAction(new ActFocus(this, "ressources/player_focus.tga", 'A'));*/

    addAction(new ActMoveLateral(this, sf::Keyboard::Key::Left, sf::Keyboard::Key::Right, sf::Joystick::X));

    //addAction(new ActMoveRight(this, sf::Keyboard::Key::N, sf::Joystick::X));
    //setActionInput("ActMoveRight", sf::Keyboard::Key::Right);
    /*addAction(new ActMoveUp(this, GLFW_KEY_UP));
    addAction(new ActMoveDown(this, GLFW_KEY_DOWN));
    addAction(new ActZUp(this, 'E'));
    addAction(new ActZDown(this, 'D'));
    addAction(new ActWeapon(this, GLFW_KEY_SPACE));*/
    //setActionKey("ActFocus", GLFW_KEY_LSHIFT);
}

DamnCute::Player::~Player()
{
}
