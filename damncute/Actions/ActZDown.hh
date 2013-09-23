#ifndef _ACTZDOWN_H_
# define _ACTZDOWN_H_

//#include "Position.hh"

class ActZDown : public DamnCute::AAction
{

    public:
	explicit ActZDown(DamnCute::APlayer *p, int k) :
	    AAction(p, k), _name("ActZDown") {}

	void execute()
	{
	    //_player->_pos.z -= 0.01;
	    _player->setLayer(_player->getLayer() - 0.01);
	    _player->getShader()->setVariable("origin", glm::translate(glm::mat4(), _player->getPos()));
	}

	const std::string getName() const
	{
	    return (_name);
	}

	virtual ~ActZDown() {}

    private:
	const std::string& _name;

};

#endif
