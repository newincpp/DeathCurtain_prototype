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
    w_ptr->draw(_player);
}

/*
void DamnCute::APlayer::action()
{
    for (size_t i = 0; i < _actions.size(); ++i) {
        if (glfwGetKey(_actions[i]->getKey()) == GLFW_PRESS) {
            (_actions[i])->execute();
        }
    }
}

void DamnCute::APlayer::setActionKey(const std::string& name, int key)
{
    for (size_t i = 0; i < _actions.size(); ++i) {
        std::cout << name << " ; " << (_actions[i])->getName() << std::endl;
        if (name == (_actions[i])->getName()) {
            (_actions[i])->setKey(key);
        }
    }
}

void DamnCute::APlayer::addAction(AAction* act)
{
    _actions.push_back(act);
}
*/
