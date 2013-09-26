#include "Player.hh"

DamnCute::Player::Player(const std::string& texfile, float x, float y) :
    APlayer(texfile, x, y)
{

    /*addAction(new ActFocus(this, "ressources/player_focus.tga", 'A'));
    addAction(new ActMoveLeft(this, GLFW_KEY_LEFT));
    addAction(new ActMoveRight(this, GLFW_KEY_RIGHT));
    addAction(new ActMoveUp(this, GLFW_KEY_UP));
    addAction(new ActMoveDown(this, GLFW_KEY_DOWN));
    addAction(new ActZUp(this, 'E'));
    addAction(new ActZDown(this, 'D'));
    addAction(new ActWeapon(this, GLFW_KEY_SPACE));*/
    //setActionKey("ActFocus", GLFW_KEY_LSHIFT);
}

DamnCute::Player::~Player()
{
}
