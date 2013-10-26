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
            virtual ~Path() = default;
            virtual void update(sf::RenderWindow*);
	    void countdownSetMoveModifier(int, const glm::mat4&);
            inline void moveOrigin(glm::vec2&& n) noexcept {
                _bulletModel.moveOrigin(std::move(n));
            }
            inline void switchGen() {
                _generate = !_generate;
            }
            inline void setStatusGen(bool&& b) {
                _generate = b;
            }
	    inline void setTimeSeparator(unsigned int newTs) {
		_timeSeparator = newTs;
	    }
	private:
            sf::Texture _tex;
            Bullet _bulletModel;
            std::list<Bullet> _bullets;
            unsigned int _timeLoad;
            unsigned int _timeSeparator;
            glm::mat4 _stepModifier;
            bool _generate;

	    unsigned int _futureframe;
            glm::mat4 _newMat;
    };
}

#endif /* !PATTERN_H_ */
