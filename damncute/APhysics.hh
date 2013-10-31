#ifndef APHISICS_H_
# define APHISICS_H_

#include <iostream>
#include "Core/Core.hh"

namespace DamnCute {
    class APhysics {
	private:
	    bool _phisicalyActive;
	    QuadTree<APhysics, 5>::Array_Type_ _path;
	    QuadTree<APhysics, 5>::Array_Type_ generateQuadTreePos(unsigned int x, unsigned int y) {
		QuadTree<APhysics, 5> _quadTree = Core::getInstance()->getQuadTree();
		(void) _quadTree;
		(void) x;
		(void) y;
		return _path;
	    }
	public:
	    APhysics(unsigned int x, unsigned int y) : _phisicalyActive(true), _path(generateQuadTreePos(x, y)) {
	    }
	    void collision(APhysics* vs) {
		(void) vs;
		if (_phisicalyActive) {
		std::cout << "SLASH !" << std::endl;
		} else {
		    std::cout << "like a ghost !" << std::endl;
		}
	    }
	    void updateQuadTreePos(unsigned int x, unsigned int y) {
		_path = generateQuadTreePos(x, y);
	    }
    };
}

#endif /* !APHISICS_H_ */
