#ifndef CORE_H_
# define CORE_H_

#include <vector>
#include <SFML/Graphics.hpp>
#include "../IRenderable.hh"

namespace DamnCute {
    class Core {
	public:
	    static Core* getInstance();
	    void reset();
	    void freeAll();
	    void addObject(IRenderable*);
	    void delObject(IRenderable*);
	    void flushScene();
	    void createWin(unsigned int, unsigned int, bool);
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
	    sf::RenderWindow* _win;
	    std::vector<IRenderable*> objects;
	    bool _gameStatus;

	    sf::Event event;
    };
}

#endif /* !CORE_H_ */
