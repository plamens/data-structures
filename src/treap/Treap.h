#ifndef TREAP_H_
#define TREAP_H_

#include "TreapNode.h"

class Treap {

public:
    Treap();
    ~Treap();

    /**
     * Inserts a node in the treap with the provided @key
     *
     * @param key: key to be inserted
     */
    void insert(int key);

    /**
     * Removes the node from the treap with the provided @key
     *
     * @param key: key to be removed
     */
    void remove(int key);

    /**
     * Checks whether a given @key is already in the treap
     *
     * @param key: key to be searched for
     * @return true, if the key is in the treap, and false, otherwise
     */
    bool containsKey(int key) const;

    /**
     * Calculates the height of the tree
     *
     * @return the height of the tree
     */
    int height();

    /**
     * Verifies the heap and BST properties
     *
     * @return false if the treap is broken
     */
    bool isTreap();

    void print();

private:
    Treap& operator=(const Treap&); // Do not implement me!
    Treap(const Treap&); // Do not implement me!

    /**
     * Pointer to the root of the tree
     */
    TreapNode *root;

    /**
     * Finds a node by its key
     *
     * @param key: key to search for
     * @return pointer to the node if found, or 0
     */
    TreapNode * & find(int const& key) const;

    /**
     * Removes the node from the tree with the provided @key
     *
     * @param key: key to be removed
     * @param node: the tree to remove from
     */
    void remove(int const & key, TreapNode * & node);

    /**
     * Recursively rotates the tree and pushed the node down until it is a leaf
     *
     * @param node: node to turn into a leaf
     * @return reference to the leaf
     */
    TreapNode * & toLeaf(TreapNode * & node);

    /**
     * Inserts a node in the treap with the provided @key
     *
     * @param key: key to be inserted
     * @param node: node to start the search at
     */
    void insert(int const& key, TreapNode *& node);

    /**
     * Does a left rotation at the supplied node
     *
     * @param node: node to rotate
     */
    void leftRotate(TreapNode *& node);

    /**
     * Does a right rotation at the supplied node
     *
     * @param node: node to rotate
     */
    void rightRotate(TreapNode *& node);

    /**
     * Calculates the height of a given node
     *
     * @return the height of the node
     */
    int height(TreapNode * & node);

    bool isTreap(TreapNode * & node);

    void print(int indent, TreapNode * & node);
};

#endif /* TREAP_H_ */
