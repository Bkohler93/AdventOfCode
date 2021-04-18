#include "bst.h"


void BST::fill_tree (int val, std::ifstream& inFile, Node* curr) {

    //check if root is null (not filled at all)
    if (curr == nullptr) {
        Node* new_node = new Node(val);
        curr = new_node;
        fill_tree(val, inFile, curr);
    }

    //check if inFile is done
    if (!inFile) return;

    //get new val from inFile
    int new_val;
    inFile >> new_val;


    // //check if sum of current val and new val is 2020
    // if (curr->val + new_val == 2020) {
    //     set_vals(curr->val, new_val);
    //     std::cout << curr->val << " and " << new_val << "'s sum is 2020.\n";
    // }


    if (new_val < curr->val) fill_tree(new_val, inFile, curr->left);

    else if (new_val > curr->val) fill_tree(new_val, inFile, curr->right);
}

BST::~BST() {

    //call recursive free function
    free_mem(this->root);
}


void BST::free_mem(Node* curr) {
    std::cout << "made it here" << std::endl;
    if (!curr) {
        delete curr;
        return;
    }
    //if left and right nullptr delete curr
    if (!curr->left && !curr->right) {
        delete curr;
        return;
    }

    //check if left not null, then traverse further
    if (curr->left) free_mem(curr->left);

    //check if right not null, then traverse further
    if (curr->right) free_mem(curr->right);
}

void BST::set_vals(int one, int two) {
    this->one = one;
    this->two = two;
}

void BST::find_two_sum() {

   //traverse through tree to test sums
   traverse_tree(this->get_root()); 
}

void BST::traverse_tree(Node* curr) {

    //check if nurr node null
    if (curr == nullptr) {
        return;
    }

    //
}