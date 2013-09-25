#ifndef ENVIRONMENT_H_
# define ENVIRONMENT_H_

#include <string>
#include <glm/glm.hpp>
#include <SFML/Graphics.hpp>
#include "IRenderable.hh"
#include "Core/Core.hh"

namespace DamnCute {
    class Background : public IRenderable {
	public:
	    Background(const std::string&);
	    ~Background();
	    void setScrollSpeed(float, float);
	    float getXScrollSpeed() const ;
	    float getYScrollSpeed() const ;
	    virtual void update(sf::RenderWindow*);
	private:
	    Background(const Background&);
	    float _XSpeed;
	    float _YSpeed;
	    sf::Sprite _bg;
	    sf::Texture _tex;
    };
}

#endif /* !ENVIRONMENT_H_ */
