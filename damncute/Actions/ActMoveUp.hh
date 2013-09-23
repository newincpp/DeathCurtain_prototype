#ifndef _ACTMOVEUP_H_
# define _ACTMOVEUP_H_

#include <glm/gtc/matrix_transform.hpp>
//#include "Position.hh"

class ActMoveUp : public DamnCute::AAction
{

    public:
	explicit ActMoveUp(DamnCute::APlayer *p, int k) :
	    AAction(p, k), _name("ActMoveUp") {}

	void execute()
	{
	    if (_player->getPos().y < 0.88) {
		//_player->_pos.y += 0.01;
		_player->setPosY(_player->getPos().y + 0.01);
		_player->getShader()->setVariable("origin", glm::translate(glm::mat4(), _player->getPos()));
	    }
	}

	const std::string getName() const
	{
	    return (_name);
	}

	virtual ~ActMoveUp() {}

    private:
	const std::string& _name;

};

#endif
