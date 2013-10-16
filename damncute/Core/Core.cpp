#include <sstream>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Core.hh"

namespace DamnCute {
    Core* Core::__coreInstance = NULL;
}

DamnCute::Core* DamnCute::Core::getInstance() {
    if (!__coreInstance) {
	__coreInstance = new DamnCute::Core;
    }
    return __coreInstance;
}

void DamnCute::Core::freeAll() {
    for (std::list<IRenderable*>::iterator it = objects.begin() ; it != objects.end(); ++it) {
	delete (*it);
    }
    objects.clear();
}

void DamnCute::Core::reset() {
    delete __coreInstance;
    __coreInstance = NULL;
}

void DamnCute::Core::refresh() {
    //for (unsigned int i = 0; i < objects.size(); ++i) {
    for (std::list<IRenderable*>::iterator it = objects.begin() ; it != objects.end(); ++it) {
	(*it)->update(_win);
    }
}

void DamnCute::Core::flushEvent() {
    while (_win->pollEvent(event))
    {
	if (event.type == sf::Event::KeyPressed)
	    if (event.key.code == sf::Keyboard::Escape)
		_win->close();
    }
}

void DamnCute::Core::flushScene() {
    float frate = _gameClock.getElapsedTime().asSeconds();

    _win->clear();
    refresh();

    //std::cout << 1 / frate << " FPS" << std::endl;
    //std::stringstream ss;
    //ss << 1 / frate;
    //sf::Text t(ss.str(), sf::Font());
    //t.setColor(sf::Color::Green);
    //t.setPosition(40,90);
    //_win->draw(t);
    _gameClock.restart();

    _win->display();
}

void DamnCute::Core::addObject(IRenderable* a) {
    objects.push_back(a);
}
void DamnCute::Core::addOnBg(IRenderable* a) {
    objects.push_front(a);
}

void DamnCute::Core::createWin(unsigned int width, unsigned int height, bool full) {
    unsigned int style = full << 3;
    //_win = new sf::RenderWindow(sf::VideoMode(width, height), "Death Curtain", style);
    //sf::VideoMode::getDesktopMode()

    if (width == 0 && height == 0) {
	_win = new sf::RenderWindow(sf::VideoMode::getDesktopMode(), "Death Curtain", style);
    } else {
	_win = new sf::RenderWindow(sf::VideoMode(width, height), "Death Curtain", style);
    }
    _win->setFramerateLimit(60);
}

void DamnCute::Core::delObject(IRenderable* a) {
    for (std::list<IRenderable*>::iterator it = objects.begin() ; it != objects.end(); ++it) {
	if ((*it) == a) {
	    objects.erase(it);
	    delete *it;
	    return;
	}
    }
}

DamnCute::Core::Core() : _gameStatus(false) {
}

DamnCute::Core::Core(const DamnCute::Core&) {
}

DamnCute::Core::Core(const DamnCute::Core&&) {
}

DamnCute::Core::~Core() {
    freeAll();
}

DamnCute::Core& DamnCute::Core::operator=(const DamnCute::Core&) {
    return *__coreInstance;
}

DamnCute::Core& DamnCute::Core::operator=(const DamnCute::Core&&) {
    return *__coreInstance;
}
