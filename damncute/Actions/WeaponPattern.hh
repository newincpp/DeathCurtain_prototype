#ifndef WEAPONPATTERN_H_
# define WEAPONPATTERN_H_

#include "../APattern.hh"

class WeaponPattern : public DamnCute::APattern {
    public:
	explicit WeaponPattern() : APattern() {
	    initialize();
	}
	virtual void initialize() {
	    glm::mat4 m = glm::translate(glm::mat4() , glm::vec3(0, 0.02, 0));
	    DamnCute::Path* p = new DamnCute::Path(m, 10, DamnCute::Bullet(glm::vec3(1,-1.0f,0.0f), 28, "ressources/mu.tga"));
	    addPath(p);
	}
    private:
	WeaponPattern(const WeaponPattern&);
};

#endif /* !WEAPONPATTERN_H_ */
