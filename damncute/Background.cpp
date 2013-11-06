#include <glm/gtc/matrix_transform.hpp>
#include "Background.hh"

DamnCute::Background::Background(const std::string& texfile, int xscroll, int yscroll) : _XSpeed(xscroll), _YSpeed(yscroll), _tex() {
    _tex.loadFromFile(texfile);
    _tex.setSmooth(true);
    _tex.setRepeated(false);
    _bg.setTexture(_tex);
}

void DamnCute::Background::setScrollSpeed(float x, float y) {
    _XSpeed = x;
    _YSpeed = y;
}

float DamnCute::Background::getXScrollSpeed() const {
    return _XSpeed;
}

float DamnCute::Background::getYScrollSpeed() const {
    return _YSpeed;
}

void DamnCute::Background::setPosition(int x, int y) {
    _bg.setPosition(x, y);
}

void DamnCute::Background::update(sf::RenderWindow* w_ptr) {
    _bg.move(_XSpeed, _YSpeed);
    w_ptr->draw(_bg);
}
