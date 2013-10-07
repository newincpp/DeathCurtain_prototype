#ifndef DISPLAYMANAGER_H_
# define DISPLAYMANAGER_H_

#ifndef __DWIDTH
#define __DWIDTH 1920
#define __DHEIGHT 1024
#endif

#include <iostream>
#include <SFML/Graphics.hpp>
#include <Core/Core.hh>

class DisplayManager {
    public:
        DisplayManager(int width = __DWIDTH, int height = __DHEIGHT, bool type = false);
        ~DisplayManager();
        void run();
        void gameMode();
        void menuMode();
    private:
        void update();
        DamnCute::Core* _engine;
        sf::RenderWindow _win;
        bool _alive;
};

#endif /* !DISPLAYMANAGER_H_ */
