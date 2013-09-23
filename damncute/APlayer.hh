#ifndef APLAYER_H_
# define APLAYER_H_

#include <iostream>
#include <vector>
#include "AAction.hh"
#include "Actions/Position.hh"
#include "IRenderable.hh"
#include "Core/Core.hh"

namespace DamnCute
{

    class APlayer : public IRenderable
    {

        public:
            explicit APlayer(const std::string& = "ressources/player.tga",
                             float = 0, float = -0.9);
            virtual ~APlayer() { }

            virtual void update(sf::RenderWindow*);
            void addAction(AAction*);
            void setActionKey(const std::string&, int);
	    //GL::ShadeProgram* getShader() const ;
	    glm::vec3 getPos() const { return _pos; }
	    float getLayer() const { return _pos.z; }
	    void setPosX(float v) { _pos.x = v; }
	    void setPosY(float v) { _pos.y = v; }
	    void setLayer(float v) { _pos.z = v; }

            //DamnCute::Sprite _p;

        private:
            //GL::ShadeProgram *_shad;
	    glm::vec3 _pos;
            void action();
            APlayer& operator=(const APlayer&);
            std::vector<AAction*> _actions;

    };

}

#endif
