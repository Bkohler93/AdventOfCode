#ifndef BST_H
#define BST_H

#include "node.h"
#include <iostream>
#include <fstream>


class BST {
    Node* root;
    int one;
    int two;

public:
    BST() : root(nullptr) {}
    ~BST();

    void fill_tree (int val, std::ifstream& inFile, Node* curr);
    Node* get_root() {return root;}
    void free_mem(Node* curr);
    void set_vals(int one, int two);
    void find_two_sum();
    void traverse_tree(Node* curr);
};

#endif