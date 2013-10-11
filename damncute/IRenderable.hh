#ifndef IRENDERABLE_H_
# define IRENDERABLE_H_

#include <SFML/Graphics.hpp>

namespace DamnCute {
    class IRenderable {
	public:
	    virtual void update(sf::RenderWindow*) = 0;
	    virtual ~IRenderable() {}
    };
}

#endif /* !IRENDERABLE_H_ */
