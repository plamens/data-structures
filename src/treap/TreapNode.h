#ifndef TREAPNODE_H_
#define TREAPNODE_H_

#include <cstdlib>
#include <iostream>

class TreapNode
{
public:
  TreapNode(int k)
  {
    key = k;
    priority = (float) rand() / RAND_MAX;
    left = 0;
    right = 0;
  }
  int key;	// key provided by user
  float priority;	// node's generated priority
  TreapNode* left;	// pointer for the left subtree
  TreapNode* right;	// pointer for the right subtree

  void print(int indent) {
	for (int i = 0; i < indent; ++i) {
		std::cout<<"   ";
	}
	std::cout<<key<<":"<<priority<<std::endl;
	if (left != 0) {
		left->print(indent + 1);
	}
	if (right != 0) {
		right->print(indent + 1);
	}
  }
};



#endif /* TREAPNODE_H_ */
