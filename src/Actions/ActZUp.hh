#ifndef _ACTZUP_H_
# define _ACTZUP_H_

//#include "Position.hh"

class ActZUp : public DamnCute::AAction
{

    public:
	explicit ActZUp(DamnCute::APlayer *p, int k) : AAction(p, k), _name("ActZUp") {}

	void execute()
	{
	    //_player->_pos.z += 0.01;
	    _player->setLayer(_player->getLayer() + 0.01);
	    _player->getShader()->setVariable("origin", glm::translate(glm::mat4(), _player->getPos()));
	}

	const std::string getName() const
	{
	    return (_name);
	}

	virtual ~ActZUp() {}

    private:
	const std::string& _name;

};

#endif
