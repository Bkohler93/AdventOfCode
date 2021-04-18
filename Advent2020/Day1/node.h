
#include <iostream>

struct Node {
    int val;
    Node* left;
    Node* right;


    Node(int val) : val(val), left(nullptr), right(nullptr) {}
    Node() : val(0) ,left(nullptr), right(nullptr) {}
};