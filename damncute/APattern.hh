#ifndef APATTERN_H_
# define APATTERN_H_

#include <type_traits>
#include <vector>
#include <glm/gtc/matrix_transform.hpp>
#include "Path.hh"
#include "Core/Core.hh"
#include "IRenderable.hh"

namespace DamnCute {
    class APattern : public IRenderable {
	public:
	    APattern() {
	    }
	    ~APattern() {
		for (unsigned int i = 0; i != _paths.size(); ++i) {
		    delete _paths[i];
		}
	    }
	    virtual void initialize() = 0;
	    virtual void addPath(Path* p) {
		_paths.push_back(p);
	    }
	    virtual void update(sf::RenderWindow* w_ptr) {
		for (unsigned int i = 0; i != _paths.size(); ++i) {
		    _paths[i]->update(w_ptr);
		}
	    }
	    virtual void moveOrigin(glm::vec2&& n) {
		for (unsigned int i = 0; i != _paths.size(); ++i) {
		    _paths[i]->moveOrigin(std::move(n));
		}
	    }
	    virtual void switchGen() {
		for (unsigned int i = 0; i != _paths.size(); ++i) {
		    _paths[i]->switchGen();
		}
	    }
	private:
	    std::vector<Path*> _paths;
    };
}

#endif /* !APATTERN_H_ */
