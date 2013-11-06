#ifndef APHISICS_H_
# define APHISICS_H_

#include <iostream>
#include "Core/Core.hh"

/*
 * -----
 * |A|B|
 * -----
 * |C|D|
 * -----
 */

namespace DamnCute {
    class APhysics {
	private:
	    bool _physicallyActive;
	    QuadTree<APhysics, 5>* _quadTree;
	    QuadTree<APhysics, 5>::Array_Type_ _path;

	    QuadTree<APhysics, 5>::Array_Type_ generateQuadTreePos(unsigned int x, unsigned int y) {
		unsigned int nodeX = sCore->getWindowSizeX() / 2;
		unsigned int nodeY = sCore->getWindowSizeY() / 2;

		for (unsigned int i = 0; i < _quadTree->getLevel(); ++i)
		{
		    if (x < nodeX && y > nodeY)
		    {
			_path[i] = QuadTree<APhysics, 5>::AZone;
			nodeX -= nodeX / 2;
			nodeY += nodeY / 2;
		    }
		    else if (x > nodeX && y > nodeY)
		    {
			_path[i] = QuadTree<APhysics, 5>::BZone;
			nodeX += nodeX / 2;
			nodeY += nodeY / 2;
		    }
		    else if (x < nodeX && y < nodeY)
		    {
			_path[i] = QuadTree<APhysics, 5>::CZone;
			nodeX -= nodeX / 2;
			nodeY -= nodeY / 2;
		    }
		    else
		    {
			_path[i] = QuadTree<APhysics, 5>::DZone;
			nodeX += nodeX / 2;
			nodeY -= nodeY / 2;
		    }
		}
		return _path;
	    }
	public:
	    APhysics(unsigned int x, unsigned int y) : _physicallyActive(true), _quadTree(Core::getInstance()->getQuadTree()) ,_path(generateQuadTreePos(x, y)) {
	    }

	    void collision() {
		std::cout << "SLASH" << std::endl;
	    }

	    void updateQuadTreePos(unsigned int x, unsigned int y) {
		_path = generateQuadTreePos(x, y);
		if (_quadTree->thereIsObject(_path)) {
		    if (_physicallyActive) {
			collision();
		    }
		}
		//_quadTree->getDataTreeNode(_path)->collision();
		_quadTree->setTreeNode(this, _path);
	    }
    };
}

#endif /* !APHISICS_H_ */
