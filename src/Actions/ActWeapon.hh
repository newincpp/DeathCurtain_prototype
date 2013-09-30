#ifndef ACTWEAPON_H_
# define ACTWEAPON_H_

#include "WeaponPattern.hh"
#include "../Core/Core.hh"

class ActWeapon : public DamnCute::AAction
{

    public:
	explicit ActWeapon(DamnCute::APlayer *p, int k) :
	    AAction(p, k), _name("ActExample"), _wp() {
		DamnCute::Core::Core::getInstance()->addObject(&_wp);
		_wp.toogleRendering();
	    }
	void execute()
	{
	    _wp.toogleRendering();
	    _wp.moveOrigin(_player->getPos());
	}

	const std::string getName() const
	{
	    return (_name);
	}

	virtual ~ActWeapon() {
		DamnCute::Core::Core::getInstance()->delObject(&_wp);
	}
    private:
	const std::string& _name;
	WeaponPattern _wp;
};

#endif /* !ACTWEAPON_H_ */
