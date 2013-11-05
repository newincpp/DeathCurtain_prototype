#ifndef APHISICS_H_
# define APHISICS_H_

#include <iostream>
#include "Core/Core.hh"

namespace DamnCute {
    class APhysics {
	private:
	    bool _physicalyActive;
	    QuadTree<APhysics, 5>* _quadTree;
	    QuadTree<APhysics, 5>::Array_Type_ _path;

	    QuadTree<APhysics, 5>::Array_Type_ generateQuadTreePos(unsigned int x, unsigned int y) {
		(void) x;
		(void) y;
		return _path;
	    }
	public:
	    APhysics(unsigned int x, unsigned int y) : _physicalyActive(true), _quadTree(Core::getInstance()->getQuadTree()) ,_path(generateQuadTreePos(x, y)) {
	    }

	    void collision() {
		if (_physicalyActive) {
		    std::cout << "SLASH !" << std::endl;
		} else {
		    std::cout << "like a ghost !" << std::endl;
		}
	    }

	    void updateQuadTreePos(unsigned int x, unsigned int y) {
		_path = generateQuadTreePos(x, y);
		if (_quadTree->thereIsObject(_path)) {
		    collision();
		}
		_quadTree->getDataTreeNode(_path)->collision();
	    }
    };
}

#endif /* !APHISICS_H_ */
