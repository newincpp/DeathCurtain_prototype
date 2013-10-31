#include <functional>
#include <array>

#ifndef QUADTREE_H_
# define QUADTREE_H_

namespace {
    template <typename T, unsigned int LEVEL>
	class QuadTree {
	    public:
		enum TDir {
		    AZone,
		    BZone,
		    CZone,
		    DZone
		};
	    private:
#include "TreeNode.hh"
		typedef std::array<TDir, LEVEL> __path_ar_;
		const unsigned int _level;
		TreeNode<T>* _head;

		inline TreeNode<T>* _getNode(__path_ar_ path) const {
		    TreeNode<T>* x = _head;
		    for (typename __path_ar_::const_iterator it = path.cbegin(); it != path.cend(); ++it) {
			if (*it == AZone)
			    x = x->up;
			else if (*it == BZone)
			    x = x->down;
			else if (*it == CZone)
			    x = x->right;
			else if (*it == DZone)
			    x = x->left;
		    }
		    return x;
		}

	    public:
		explicit QuadTree() : _level(LEVEL), _head(new TreeNode<T>(LEVEL)) {}

		T* getDataTreeNode(__path_ar_& path) const {
		    return *_getNode(path)->data;
		}

		void setTreeNode(T* value, __path_ar_& path) {
		    _getNode(path)->data = value;
		}

		void swap(__path_ar_& path1, __path_ar_ path2) {
		    T* a = _getNode(path1)->data;
		    T* b = _getNode(path2)->data;
		    T* tmp;

		    tmp = a;
		    a = b;
		    b = tmp;
		}

		inline unsigned int getLevel() const {
		    return _level;
		}

		typedef __path_ar_ Array_Type_;
	};
}

#endif /* !QUADTREE_H_ */
