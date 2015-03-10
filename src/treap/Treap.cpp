#include <iostream>
#include "Treap.h"

Treap::Treap() :
        root(0) {
}

Treap::~Treap() {
    if (root != 0) {
        delete root;
    }
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

TreapNode * & Treap::toLeaf(TreapNode * & node) {
    if (node->left == 0 && node->right == 0) {
        return node;
    }
    if (node->right == 0) {
        rightRotate(node);
        return toLeaf(node->right);
    }
    if (node->left == 0){
        leftRotate(node);
        return toLeaf(node->left);
    }
    if (node->left->priority > node->right->priority) {
        leftRotate(node);
        return toLeaf(node->left);
    }
    rightRotate(node);
    return toLeaf(node->right);
}

void Treap::remove(int key) {
    remove(key, root);
}

void Treap::remove(int const & key, TreapNode * & node) {
    if (node == 0) {
        return;
    }
    if (node->key == key) {
        TreapNode * & toDelete = toLeaf(node);
        delete toDelete;
        toDelete = 0;
        return;
    }
    if (node->key > key) {
        return remove(key, node->left);
    }
    return remove(key, node->right);
}

bool Treap::containsKey(int key) const {
    TreapNode * const * p = &root;
    while (*p != 0) {
        if ((*p)->key == key) {
            return p;
        }
        if ((*p)->key > key) {
            p = &((*p)->left);
        } else {
            p = &((*p)->right);
        }
    }
    return 0;
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

int Treap::height() {
    return height(root);
}

int Treap::height(TreapNode * & node) {
    if (node == 0) {
        return 0;
    }
    int l = height(node->left);
    int r = height(node->right);
    return (l > r ? l : r) + 1;
}

bool Treap::isTreap() {
    return isTreap(root);
}

bool Treap::isTreap(TreapNode * & node) {
    if (node == 0) {
        return true;
    }
    if (node->left != 0) {
        if (node->priority > node->left->priority || node->key < node->left->key) {
            return false;
        }
    }
    if (node->right != 0) {
        if (node->priority > node->right->priority || node->key > node->right->key) {
            return false;
        }
    }
    return isTreap(node->left) && isTreap(node->right);
}

void Treap::print() {
    if (root != 0) {
        print(0, root);
    }
}

void Treap::print(int indent, TreapNode * & node) {
    for (int i = 0; i < indent; ++i) {
        std::cout << "   ";
    }
    std::cout << node->key << ":" << node->priority << std::endl;
    if (node->left != 0) {
        print(indent + 1, node->left);
    }
    if (node->right != 0) {
        print(indent + 1, node->right);
    }
}
