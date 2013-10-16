#ifndef PATTERN_H_
# define PATTERN_H_

#include <list>
//#include <map>
#include <glm/glm.hpp>
#include <utility>
#include "APlayer.hh"
#include "Bullet.hh"
#include "IRenderable.hh"
#include "Core/Core.hh"

namespace DamnCute {
    class Path : public IRenderable {
	public:
	    explicit Path(const glm::mat4&, unsigned int frameStep = 5, Bullet&& = Bullet(glm::vec2(0,0)), const std::string& = "resources/test.tga");
	    virtual ~Path();
	    virtual void update(sf::RenderWindow*);
	    inline void moveOrigin(glm::vec2&& n) noexcept {
		_bulletModel.moveOrigin(std::move(n));
	    }
	    bool isOn(APlayer*);
	    inline void switchGen() {
		_generate = !_generate;
	    }
	    inline void setStatusGen(bool&& b) {
		_generate = b;
	    }
	private:
	    sf::Texture _tex;
	    Bullet _bulletModel;
	    std::list<Bullet> _bullets;
	    unsigned int _timeLoad;
	    unsigned int _timeSeparator;
	    glm::mat4 _stepModifier;
	    //std::map<float, glm::mat4> _modifier;
	    bool _generate;
    };
}

#endif /* !PATTERN_H_ */
