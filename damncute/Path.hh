#ifndef PATTERN_H_
# define PATTERN_H_
#include <deque>
#include <map>
#include <glm/glm.hpp>
#include "APlayer.hh"
#include "Bullet.hh"
#include "IRenderable.hh"
#include "Core/Core.hh"

namespace DamnCute {
    class Path : public IRenderable {
	public:
	    explicit Path(const glm::mat4&, unsigned int frameStep = 5, const Bullet& = Bullet(glm::vec2(0,0)), const std::string& = "ressources/test.tga");
	    virtual ~Path();
	    virtual void update(sf::RenderWindow*);
	    void moveOrigin(const glm::vec2&);
	    bool isOn(APlayer*);
	    inline void switchGen() {
		_generate = !_generate;
	    }
	private:
	    sf::Texture _tex;
	    Bullet* _bulletModel;
	    std::deque<Bullet> _bullets;
	    unsigned int _timeLoad;
	    unsigned int _timeSeparator;
	    glm::mat4 _stepModifier;
	    std::map<float, glm::mat4> _modifier;
	    bool _generate;
    };
}

#endif /* !PATTERN_H_ */
