#ifndef _ACTMOVELEFT_H_
# define _ACTMOVELEFT_H_

#include <glm/gtc/matrix_transform.hpp>
//#include "Position.hh"

class ActMoveLeft : public DamnCute::AAction
{

    public:
	explicit ActMoveLeft(DamnCute::APlayer *p, int k) :
	    AAction(p, k), _name("ActMoveLeft") {}

	void execute()
	{
	    if (_player->getPos().x > -1) {
		//_player->_pos.x -= 0.01;
		_player->setPosX(_player->getPos().x - 0.01);
		_player->getShader()->setVariable("origin", glm::translate(glm::mat4(), _player->getPos()));
	    }
	}

	const std::string getName() const
	{
	    return (_name);
	}

	virtual ~ActMoveLeft() {}

    private:
	const std::string& _name;

};

#endif
