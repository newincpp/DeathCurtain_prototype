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
            Background(const std::string&, int = 0, int = 0);
            virtual ~Background() = default;
            void setScrollSpeed(float, float);
            float getXScrollSpeed() const ;
            float getYScrollSpeed() const ;
	    void setPosition(int, int);
            virtual void update(sf::RenderTarget*);
        private:
            Background(const Background&);
            float _XSpeed;
            float _YSpeed;
            sf::Sprite _bg;
            sf::Texture _tex;
    };
}

#endif /* !ENVIRONMENT_H_ */
