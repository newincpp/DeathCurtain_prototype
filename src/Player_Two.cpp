#include "Player_Two.hh"

DamnCute::Player_Two::Player_Two(const std::string& texfile, float x, float y) :
    APlayer(texfile, x, y, 1)
{

    /*addAction(new ActFocus(this, "ressources/player_focus.tga", 'A'));*/

    addAction(new ActMoveLateral(this, sf::Keyboard::Key::Q, sf::Keyboard::Key::D, sf::Joystick::X));

    // MERGE THESE TWO
    //addAction(new ActMoveLeft(this, sf::Keyboard::Key::Q, sf::Joystick::X));
    //addAction(new ActMoveRight(this, sf::Keyboard::Key::D, sf::Joystick::X));
    
    /*addAction(new ActMoveUp(this, GLFW_KEY_UP));
    addAction(new ActMoveDown(this, GLFW_KEY_DOWN));
    addAction(new ActZUp(this, 'E'));
    addAction(new ActZDown(this, 'D'));
    addAction(new ActWeapon(this, GLFW_KEY_SPACE));*/
    //setActionKey("ActFocus", GLFW_KEY_LSHIFT);
}



DamnCute::Player_Two::~Player_Two()
{
}
