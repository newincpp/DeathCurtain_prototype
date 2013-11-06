#ifndef APHISICS_H_
# define APHISICS_H_

#include <iostream>
#include <utility>
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
	    bool _destructible;
	    QuadTree<APhysics, __DQUADTREE_COMPLEXITY__>* _quadTree;
	    QuadTree<APhysics, __DQUADTREE_COMPLEXITY__>::Array_Type_ _path;

	    template <unsigned short iter>
		inline QuadTree<APhysics, __DQUADTREE_COMPLEXITY__>::Array_Type_&& generateQuadTreePos(unsigned int x, unsigned int y) noexcept {
		    unsigned int nodeX = sCore->getWindowSizeX() / 2;
		    unsigned int nodeY = sCore->getWindowSizeY() / 2;

		    for (unsigned short i = 0; i < iter; ++i)
		    {
			if (x < nodeX && y > nodeY)
			{
			    _path[i] = QuadTree<APhysics, __DQUADTREE_COMPLEXITY__>::AZone;
			    nodeX -= nodeX / 2;
			    nodeY += nodeY / 2;
			}
			else if (x > nodeX && y > nodeY)
			{
			    _path[i] = QuadTree<APhysics, __DQUADTREE_COMPLEXITY__>::BZone;
			    nodeX += nodeX / 2;
			    nodeY += nodeY / 2;
			}
			else if (x < nodeX && y < nodeY)
			{
			    _path[i] = QuadTree<APhysics, __DQUADTREE_COMPLEXITY__>::CZone;
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
		    return std::move(_path);
		}

	public:
	    APhysics(unsigned int x, unsigned int y, bool destructibility = true) : _physicallyActive(true), _destructible(destructibility), _quadTree(Core::getInstance()->getQuadTree()) {
		generateQuadTreePos<__DQUADTREE_COMPLEXITY__>(x, y);
	    }
	    inline bool isDestructible() {
		return _destructible;
	    }

	protected:
	    virtual void collisionHandler(APhysics*) = 0;

	    void updateQuadTreePos(unsigned int x, unsigned int y) {
		_quadTree->setTreeNode(NULL, _path);
		generateQuadTreePos<__DQUADTREE_COMPLEXITY__>(x, y);

		if (_quadTree->thereIsObject(_path) && _physicallyActive) {
		    collisionHandler(_quadTree->getDataTreeNode(_path));
		    //_quadTree->getDataTreeNode(_path)->collision();
		}
		_quadTree->setTreeNode(this, _path);
	    }
    };
}

#endif /* !APHISICS_H_ */
