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
	    bool _physicalyActive;
	    QuadTree<APhysics, 5>* _quadTree;
	    QuadTree<APhysics, 5>::Array_Type_ _path;

	    QuadTree<APhysics, 5>::Array_Type_ generateQuadTreePos(unsigned int x, unsigned int y) {
            int nodeX = sCore->getWindowSizeX() / 2;
            int nodeY = sCore->getWindowSizeY() / 2;

            int i;
            for (i = 0; i < _quadTree->getLevel(); ++i)
            {
                if (x < nodeX && y > nodeY)
                {
                    _path[i] = QuadTree::AZone;
                    nodeX -= nodeX / 2;
                    nodeY += nodeY / 2;
                }
                else if (x > nodeX && y > nodeY)
                {
                    _path[i] = QuadTree::BZone;
                    nodeX += nodeX / 2;
                    nodeY += nodeY / 2;
                }
                else if (x < nodeX && y < nodeY)
                {
                    _path[i] = QuadTree::CZone;
                    nodeX -= nodeX / 2;
                    nodeY -= nodeY / 2;
                }
                else
                {
                    _path[i] = QuadTree::DZone;
                    nodeX += nodeX / 2;
                    nodeY -= nodeY / 2;
                }
            }

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
