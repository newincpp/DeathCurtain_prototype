#ifndef ENVIRONMENT_H_
# define ENVIRONMENT_H_

#include <string>
#include <glm/glm.hpp>
#include <SFML/Graphics.hpp>
#include "IRenderable.hh"
#include "Core/Core.hh"

namespace DamnCute {
    class Environment : public IRenderable {
	public:
	    Environment(const std::string&);
	    void setSpeed(float, float);
	    float getXSpeed() const ;
	    float getYSpeed() const ;
	    virtual void update(sf::RenderWindow*);
	    ~Environment();
	private:
	    Environment(const Environment&);
	    float _XSpeed;
	    float _YSpeed;
	    sf::Sprite _bg;
	    glm::vec3 _pos;
	    sf::Texture _tex;
    };
}

#endif /* !ENVIRONMENT_H_ */
