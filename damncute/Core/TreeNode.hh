#ifndef NODE_H_
# define NODE_H_

template <typename DATANODE>
struct TreeNode {
    explicit TreeNode(unsigned short level) {
	if (level) {
	    up = new TreeNode<T>(level - 1);
	    down = new TreeNode<T>(level - 1);
	    left = new TreeNode<T>(level - 1);
	    right = new TreeNode<T>(level - 1);
	} else {
	    up = NULL;
	    down = NULL;
	    left = NULL;
	    right = NULL;
	}
	data = NULL;
    }

    virtual ~TreeNode() {
	delete up;
	delete down;
	delete left;
	delete right;
    }

    DATANODE* data; // TODO must exist only for final recurtion
    TreeNode<T>* up;
    TreeNode<T>* down;
    TreeNode<T>* right;
    TreeNode<T>* left;
};

#endif /* !NODE_H_ */
