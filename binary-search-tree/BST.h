//
// Created by konstantine on 5/13/22.
//

#ifndef BST_H
#define BST_H
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* right;
    Node* left;
};

class BST{
private:
    Node* root;
    int log_len;
    void inOrder(Node* node);
    void preOrder(Node* node);
    void postOrder(Node* node);
    void destroyBST(Node* node);
    Node* findNode(Node* node, int value);
    Node* getMaxNodeI(Node* node);
    Node* getMinNodeI(Node* node);
    void insertLeafI(Node* node, int value);
    void PrintRangeQueryI(Node* node, int from, int to);
    Node* makeNode(int value);
    Node* makeBSTI(vector<int>& v, int from, int to);
public:
    BST(vector<int>& v);
    ~BST();

    void printBST(string order);
    bool containsNode(int value);
    int getMaxNode();
    int getMinNode();
    void insertLeaf(int value);
    void PrintRangeQuery(int from, int to);
    void removeNode(int value);
    int treeSize();
};

#endif