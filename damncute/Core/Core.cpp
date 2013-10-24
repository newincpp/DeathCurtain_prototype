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
    for (std::list<IRenderable*>::iterator it = _objects.begin() ; it != _objects.end(); ++it) {
        delete (*it);
    }
    _objects.clear();
}

void DamnCute::Core::reset() {
    delete __coreInstance;
    __coreInstance = NULL;
}

void DamnCute::Core::refresh() {
    for (std::list<IRenderable*>::iterator it = _objects.begin() ; it != _objects.end(); ++it) {
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

    std::stringstream ss;
    ss << ceil(1 / frate);
    sf::Font font;
    font.loadFromFile("resources/font.ttf");
    sf::Text t(ss.str() + " fps", font);
    t.setCharacterSize(24);
    t.setColor(sf::Color::Green);
    t.setPosition(900, 10);

    if (_displayFPS) {
        _win->draw(t);
    }
    _gameClock.restart();
    _win->display();
}

void DamnCute::Core::addObject(IRenderable* a) {
    _objects.push_back(a);
}
void DamnCute::Core::addOnBg(IRenderable* a) {
    _objects.push_front(a);
}

void DamnCute::Core::createWin(unsigned int width, unsigned int height, bool full) {
    unsigned int style = full << 3;

    if (width == 0 && height == 0) {
        _win = new sf::RenderWindow(sf::VideoMode::getDesktopMode(), "Death Curtain", style);
    } else {
        _win = new sf::RenderWindow(sf::VideoMode(width, height), "Death Curtain", style);
    }
    _win->setVerticalSyncEnabled(true);
    _win->setFramerateLimit(60);
}

void DamnCute::Core::delObject(IRenderable* a) {
    for (std::list<IRenderable*>::iterator it = _objects.begin() ; it != _objects.end(); ++it) {
        if ((*it) == a) {
            _objects.erase(it);
            delete a;
            return;
        }
    }
}

DamnCute::Core::Core() : _gameStatus(false), _displayFPS(false) {
}

DamnCute::Core::Core(const DamnCute::Core&) {
}

DamnCute::Core::Core(const DamnCute::Core&&) {
}

DamnCute::Core::~Core() {
    freeAll();
    delete _win;
}

DamnCute::Core& DamnCute::Core::operator=(const DamnCute::Core&) {
    return *__coreInstance;
}

DamnCute::Core& DamnCute::Core::operator=(const DamnCute::Core&&) {
    return *__coreInstance;
}
