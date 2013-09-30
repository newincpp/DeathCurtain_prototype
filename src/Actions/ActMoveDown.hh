#ifndef _ACTMOVEDOWN_H_
# define _ACTMOVEDOWN_H_

#include <glm/gtc/matrix_transform.hpp>
//#include "Position.hh"

class ActMoveDown : public DamnCute::AAction
{

    public:
	explicit ActMoveDown(DamnCute::APlayer *p, int k) :
	    AAction(p, k), _name("ActMoveDown") {}

	void execute()
	{
	    if (_player->getPos().y > -1) {
		//_player->_pos.y -= 0.01;
		_player->setPosY(_player->getPos().y - 0.01);
		_player->getShader()->setVariable("origin", glm::translate(glm::mat4(), _player->getPos()));
	    }
	}

	const std::string getName() const
	{
	    return (_name);
	}

	virtual ~ActMoveDown() {}

    private:
	const std::string& _name;

};

#endif
