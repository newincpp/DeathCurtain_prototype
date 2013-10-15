#include <glm/gtc/matrix_transform.hpp>
#include "Path.hh"

DamnCute::Path::Path(const glm::mat4& m, unsigned int timestep, DamnCute::Bullet&& model, const std::string& texfile) : _bulletModel(std::move(model)), _timeLoad(0), _timeSeparator(timestep), _stepModifier(m), _generate(true) {
    _tex.loadFromFile(texfile);
    _tex.setSmooth(true);
    _tex.setRepeated(false);
    _bulletModel.setTexure(&_tex);
}

DamnCute::Path::~Path() {
}

void DamnCute::Path::update(sf::RenderWindow* w_ptr) {
    for (std::list<Bullet>::iterator it = _bullets.begin(); it != _bullets.end();) {
	(*it).update(_stepModifier, w_ptr);
	if ((*it).decreaseLifeTime() <= 0) {
	    it = _bullets.erase(it);
	} else {
	    ++it;
	}
    }
    ++_timeLoad;
    if ((( _timeLoad / _timeSeparator) > 1) && (_generate)) {
	_timeLoad = 0;
	_bullets.push_back(std::move(_bulletModel));
    }
}
