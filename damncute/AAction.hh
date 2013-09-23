#ifndef _AACTION_H_
# define _AACTION_H_

#include <GL/glew.h>
#include <GL/glfw.h>
#include "APlayer.hh"

namespace DamnCute
{

    class APlayer;

    class AAction
    {

        public:
            explicit AAction(APlayer *p, int k) : _key(k), _player(p) {}
            virtual ~AAction() {}

            virtual void execute() = 0;
            virtual const std::string getName() const = 0;

            int getKey() const { return (_key); }
            void setKey(int key)
            {
                _key = key;
            }

        protected:
            int _key;
            APlayer *_player;

    };

}

#endif
