#ifndef CORE_H_
# define CORE_H_

#include <list>
#include "QuadTree.hh"
#include "../IRenderable.hh"

namespace DamnCute {
    class APhysics;
    class Core {
        public:
            static Core* getInstance();
            void reset();
            void freeAll();
            void addObject(IRenderable*);
            void delObject(IRenderable*);
            void addOnBg(IRenderable*);
            void flushScene();
            void createWin(unsigned int = 0, unsigned int = 0, bool = false);
            inline int  getWindowStatus() const {
                return _win->isOpen();
            }
            inline int  getWindowSizeX() const {
                return _win->getSize().x;
            }
            inline int  getWindowSizeY() const {
                return _win->getSize().y;
            }
            inline bool getGameStatus() const {
                return _gameStatus;
            }
            inline void switchGameStatus() {
                _gameStatus = !_gameStatus;
            }
            inline sf::Event getEvent() const {
                return event;
            }
            inline void setFPSDisplay(bool value) {
                _displayFPS = value;
            }
	    inline void addBulletsCounter() {
		++_numberOfBullets;
	    }
	    inline QuadTree<APhysics, 5>* getQuadTree() {
		return &_physicTree;
	    }
            void flushEvent();
        private:

            Core();
            ~Core();
            Core(const Core&);
            Core(const Core&&);
            Core& operator=(const Core&);
            Core& operator=(const Core&&);
            void refresh();

	    static Core* __coreInstance;
	    QuadTree<APhysics, 5> _physicTree;
	    sf::RenderWindow* _win;
	    std::list<IRenderable*> _objects;
	    bool _gameStatus;
	    bool _displayFPS;
	    unsigned int _numberOfBullets;
	    unsigned int _Pframmes;
	    unsigned int _tmpFrammes;

            sf::Clock _gameClock;
            sf::Event event;
    };
}

#define sCore Core::getInstance()

#endif /* !CORE_H_ */
