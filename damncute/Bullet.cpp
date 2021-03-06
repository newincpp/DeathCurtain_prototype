#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include "Bullet.hh"
#include "Core/Core.hh"

DamnCute::Bullet::Bullet(const glm::vec2& origin, const float rot, unsigned int lifeTime) : APhysics(origin.x, origin.y, false), _origin(origin), _rot(rot), _selfTransform(glm::translate(glm::rotate(glm::mat4(), rot, glm::vec3(0.0f, 0.0f, 1.0f)), glm::vec3(-origin.x, -origin.y, 0))), _tex(NULL), _lifeTime(lifeTime) {
}

DamnCute::Bullet::Bullet(DamnCute::Bullet&& b) : APhysics(b._origin.x, b._origin.y), _origin(b._origin), _rot(b._rot), _selfTransform(glm::translate(glm::rotate(glm::mat4(), b._rot, glm::vec3(0.0f, 0.0f, 1.0f)), glm::vec3(-b._origin.x, -b._origin.y, 0))), _tex(b._tex), _lifeTime(b._lifeTime) {
    if (b._tex) {
        _s.setTexture(*_tex);
    }
}

DamnCute::Bullet& DamnCute::Bullet::operator=(Bullet&& b) {
    _s = b._s;
    _lifeTime = b._lifeTime;
    return *this;
}

void DamnCute::Bullet::update(const glm::mat4& transform, sf::RenderTarget* w_ptr) {
    _selfTransform *= transform;

    glm::mat3 rotMat(_selfTransform);
    glm::vec3 d(_selfTransform[3]);
    glm::vec3 retVec = -d * rotMat;

    _s.setPosition(retVec.x, retVec.y);
    updateQuadTreePos(retVec.x, retVec.y);
    w_ptr->draw(_s);
    DamnCute::Core::getInstance()->addBulletsCounter();
}

void DamnCute::Bullet::setTexure(sf::Texture* tex) {
    _tex = tex;
    _s.setTexture(*_tex);
}

float DamnCute::Bullet::decreaseLifeTime() {
    --_lifeTime;
    return _lifeTime;
}

void DamnCute::Bullet::collisionHandler(APhysics* other) {
    (void) other;
}
