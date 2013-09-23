#include <glm/gtc/matrix_transform.hpp>
#include "APlayer.hh"

DamnCute::APlayer::APlayer(const std::string& texfile, float x, float y) :
    _p(texfile, 500, 200),
{
    _pos.x = x;
    _pos.y = y;
    _pos.z = 0;
    _p.setShader(_shad);
    //    _shad->setVariable("origin", glm::translate(glm::mat4(), glm::vec3(_pos.x, _pos.y,_pos.z)));
}

//GL::ShadeProgram* DamnCute::APlayer::getShader() const {
//    return _shad;
//}

void DamnCute::APlayer::action()
{
    //    for (size_t i = 0; i < _actions.size(); ++i) {
    //	if (glfwGetKey(_actions[i]->getKey()) == GLFW_PRESS) {
    //	    (_actions[i])->execute();
    //	}
    //    }
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

void DamnCute::APlayer::update()
{
    action();
    //    _shad->enable();
    //_p.render();
    //    _shad->disable();
}

void DamnCute::APlayer::addAction(AAction* act)
{
    _actions.push_back(act);
}
