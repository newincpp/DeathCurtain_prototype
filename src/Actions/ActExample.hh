#ifndef _ACTEXMPL_H_
# define _ACTEXMPL_H_

class ActExample : public AAction
{

    public:
	explicit ActExample(APlayer *p, int k) :
	    AAction(p, k), _name("ActExample") {}

	void execute()
	{
	    std::cout << _player->getPos().y << std::endl;
	}

	const std::string getName() const
	{
	    return (_name);
	}

	virtual ~ActExample() {}

    private:
	const std::string& _name;

}

#endif
