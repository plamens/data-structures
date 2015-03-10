#ifndef TREAPNODE_H_
#define TREAPNODE_H_

#include <cstdlib>

class TreapNode {
public:
    TreapNode(int k) {
        key = k;
        priority = (float) rand() / RAND_MAX;
        left = 0;
        right = 0;
    }
    ~TreapNode() {
        if (left != 0) {
            delete left;
        }
        if (right != 0) {
            delete right;
        }
    }
    int key;	// key provided by user
    float priority;	// node's generated priority
    TreapNode* left;	// pointer for the left subtree
    TreapNode* right;	// pointer for the right subtree
};

#endif /* TREAPNODE_H_ */
