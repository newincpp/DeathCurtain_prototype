#ifndef BULLET_H_
# define BULLET_H_

#include <glm/glm.hpp>
#include <SFML/Graphics.hpp>

namespace DamnCute {
    class Bullet {
	public:
	    explicit Bullet(const glm::vec2&, const float = 0.0f, unsigned int = 60);
	    explicit Bullet(const Bullet&);
	    explicit Bullet(Bullet&&);
	    virtual ~Bullet();
	    Bullet& operator=(const Bullet&);
	    void update(const glm::mat4&, sf::RenderWindow*);
	    float decreaseLifeTime();
	    inline const glm::vec2& getOrigin() const {
		return _origin;
	    }
	    inline float getRot() const {
		return _rot;
	    }
	    inline unsigned int getLife() const {
		return _lifeTime;
	    }
	    inline void moveOrigin(glm::vec2&& n) {
		_origin = n;
	    }
	    void setTexure(sf::Texture*);
	private:
	    glm::vec2 _origin;
	    float _rot;
	    glm::mat4 _selfTransform;
	    sf::Texture* _tex; // need to be deleted or changed by referance
	    sf::Sprite _s;
	    unsigned int _lifeTime;
    };
}

#endif
