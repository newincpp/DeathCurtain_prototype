#include <glm/gtc/matrix_transform.hpp>
#include "Environment.hh"

DamnCute::Environment::Environment(const std::string& texfile) : _pos(1, 1, -1) , _tex() {
    _tex.loadFromFile(texfile);
    _tex.setSmooth(true);
    _tex.setRepeated(false);
    _bg.setTexture(_tex);
}

DamnCute::Environment::~Environment() {
}

void DamnCute::Environment::setSpeed(float x, float y) {
    _XSpeed = x;
    _YSpeed = y;
}

float DamnCute::Environment::getXSpeed() const {
    return _XSpeed;
}

float DamnCute::Environment::getYSpeed() const {
    return _YSpeed;
}

#include <iostream>

void DamnCute::Environment::update(sf::RenderWindow* w_ptr) {
    //_pos.x += _XSpeed / 10000;
    //_pos.y += _YSpeed / 10000;
    //std::cout << "speed = " << _XSpeed << " " << _YSpeed << std::endl;
    //std::cout << "_pos = " << _pos.x << " " << _pos.y << std::endl;
    //_bg.move(_pos.x,  _pos.y);
    _bg.move(_XSpeed, _YSpeed);
    w_ptr->draw(_bg);
}
