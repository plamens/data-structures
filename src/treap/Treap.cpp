#include <stack>
#include "Treap.h"

Treap::Treap() :
        root(0) {
}

Treap::~Treap() {
    // free memory
}

void Treap::insert(int key) {
    insert(key, root);
}

void Treap::insert(int const & key, TreapNode *& node) {
    if (node == 0) {
        node = new TreapNode { key };
    } else {
        if (node->key > key) {
            insert(key, node->left);
            if (node->priority > node->left->priority) {
                rightRotate(node);
            }
        } else {
            insert(key, node->right);
            if (node->priority > node->right->priority) {
                leftRotate(node);
            }
        }
    }
}

bool Treap::containsKey(int key) const {
    TreapNode * const * p = &root;
    while (*p != 0) {
        if ((*p)->key == key) {
            return true;
        }
        if ((*p)->key > key) {
            p = &((*p)->left);
        } else {
            p = &((*p)->right);
        }
    }
    return false;
}

void Treap::rightRotate(TreapNode *& node) {
    TreapNode * a = node;
    node = a->left;
    a->left = node->right;
    node->right = a;
}

void Treap::leftRotate(TreapNode *& node) {
    TreapNode * a = node;
    node = a->right;
    a->right = node->left;
    node->left = a;
}

void Treap::print() {
    if (root != 0) {
        root->print(0);
    }
}
