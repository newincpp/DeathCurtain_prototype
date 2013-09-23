#ifndef INPUT_H_
# define INPUT_H_

#include <GL/glew.h>
#include <GL/glfw.h>

namespace DamnCute
{

    class Input {

        public:
            explicit Input() {}
            virtual ~Input() {}
            int getKey();

        private:
    };

}

#endif /* !INPUT_H_ */
