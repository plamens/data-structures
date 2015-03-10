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

	void print();

private:
	Treap& operator=(const Treap&); // Do not implement me!
	Treap(const Treap&); // Do not implement me!

	/**
	 * Pointer to the root of the tree
	 */
	TreapNode *root;

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
};

#endif /* TREAP_H_ */
