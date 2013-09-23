#include <glm/gtc/matrix_transform.hpp>
#include "Path.hh"

DamnCute::Path::Path(const glm::mat4& m, unsigned int timestep, const DamnCute::Bullet& model, const std::string& texfile) : _bulletModel(model), _timeLoad(0), _timeSeparator(timestep), _stepModifier(m) {
    _tex.loadFromFile(texfile);
    _tex.setSmooth(true);
    _tex.setRepeated(false);
    _bulletModel.setTexure(&_tex);
}

DamnCute::Path::~Path() {
}

void DamnCute::Path::update(sf::RenderWindow* w_ptr) {
    for (std::deque<Bullet>::iterator it = _bullets.begin(); it < _bullets.end();) {
	(*it).update(_stepModifier, w_ptr);
	if ((*it).decreaseLifeTime() <= 0) {
	    it = _bullets.erase(it);
	} else {
	    ++it;
	}
    }
    ++_timeLoad;
    if (( _timeLoad / _timeSeparator) > 1) {
	_timeLoad = 0;
	_bullets.push_back(_bulletModel);
    }
}

void DamnCute::Path::moveOrigin(const glm::vec2& n) {
    _bulletModel = Bullet(n, _bulletModel.getRot(), _bulletModel.getLife());
}

