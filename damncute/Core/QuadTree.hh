#include <array>
#include <utility>

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
		enum _CQTREEVALUES_ {
		    _COMPLEXITY_ = LEVEL,
		};
	    private:
#include "TreeNode.hh"
		typedef std::array<TDir, LEVEL> __path_ar_;
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
		explicit QuadTree() : _head(new TreeNode<T>(LEVEL)) {}

		T* getDataTreeNode(__path_ar_& path) const {
		    return _getNode(path)->data;
		}

		void setCallback() {
		}

		void setTreeNode(T* value, const __path_ar_& path) {
		    _getNode(path)->data = value;
		}

		void swap(__path_ar_& path1, const __path_ar_& path2) {
		    T* a = _getNode(path1)->data;
		    T* b = _getNode(path2)->data;
		    T* tmp;

		    tmp = a;
		    a = b;
		    b = tmp;
		}

		bool thereIsObject(const __path_ar_& p) {
		    if (_getNode(p)->data) {
			return true;
		    }
		    return false;
		}

		inline unsigned int&& getLevel() const {
		    return std::move(LEVEL);
		}

		typedef __path_ar_ Array_Type_;
	};
}

#endif /* !QUADTREE_H_ */
