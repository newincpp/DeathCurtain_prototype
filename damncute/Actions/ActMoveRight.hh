#ifndef _ACTMOVERIGHT_H_
# define _ACTMOVERIGHT_H_

#include <glm/gtc/matrix_transform.hpp>
//#include "Position.hh"

class ActMoveRight : public DamnCute::AAction
{

    public:
	explicit ActMoveRight(DamnCute::APlayer *p, int k) :
	    AAction(p, k), _name("ActMoveRight") {}

	void execute()
	{
	    if (_player->getPos().x < 0.9) {
		//_player->_pos.x += 0.01;
		_player->setPosX(_player->getPos().x + 0.01);
		_player->getShader()->setVariable("origin", glm::translate(glm::mat4(), _player->getPos()));
	    }
	}

	const std::string getName() const
	{
	    return (_name);
	}

	virtual ~ActMoveRight() {}

    private:
	const std::string& _name;

};

#endif
