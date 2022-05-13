//
// Created by konstantine on 5/13/22.
//
#include"BST.h"

//private functions
void BST::inOrder(Node* node){
    //base case
    if(node == NULL)return;

    //main case
    inOrder(node -> left);
    cout << node -> data << ' ';
    inOrder(node -> right);
}

void BST::preOrder(Node* node){
    //base case
    if(node == NULL)return;

    //main case
    cout << node -> data << ' ';
    preOrder(node -> left);
    preOrder(node -> right);
}

void BST::postOrder(Node* node){
    //base case
    if(node == NULL)return;

    //main case
    postOrder(node -> left);
    postOrder(node -> right);
    cout << node -> data << ' ';
}

void BST::destroyBST(Node* node){
    //base case
    if(node == NULL)return;

    //main case
    destroyBST(node -> left);
    destroyBST(node -> right);
    delete node;
}

Node* BST::findNode(Node* node, int value){
    if(node == NULL)return node;

    if(node ->left == NULL && node->right == NULL){
        return node -> left;
    }


    if(node -> left == NULL){
        if(node -> right -> data == value)return node;
    }

    if(node -> right == NULL){
        if(node -> left -> data == value)return node;
    }

    if(node -> right != NULL && node -> right -> data == value)return node;
    if(node -> left != NULL && node -> left -> data == value)return node;

    if(node -> data < value){
        if(node -> right == NULL)return node -> right;

        return findNode(node -> right, value);
    }

    if(node -> left == NULL)return node -> left;
    return findNode(node -> left, value);
}

Node* BST::getMaxNodeI(Node* node){
    //base case
    if(node -> right == NULL)return node;

    //main case
    return getMaxNodeI(node -> right);
}

Node* BST::getMinNodeI(Node* node){
    //base case
    if(node -> left == NULL)return node;

    //main case
    return getMinNodeI(node -> left);
}

void BST::insertLeafI(Node* node, int value){
    //there is two case

    //inserting right
    if(value > node -> data){
        //base case for right side
        if(node -> right == NULL){
            Node* newNode = makeNode(value);
            node -> right = newNode;
            return;
        }
        //recursive step for right side
        insertLeafI(node -> right, value);
        return;
    }
        //inserting left
    else{
        //base case for left side
        if(node -> left == NULL){
            Node* newNode = makeNode(value);
            node -> left = newNode;
            return;
        }
        //recursive step for left side
        insertLeafI(node -> left, value);
        return;
    }
}

void BST::PrintRangeQueryI(Node* node, int from, int to){
    if(node == NULL)return;
    if(node -> data == from){
        cout << node -> data << ' ';
        PrintRangeQueryI(node -> right, from, to);
    }
    else if(node -> data == to){
        PrintRangeQueryI(node -> left, from, to);
        cout << node -> data << ' ';
    }

    else if(node -> data < from || node -> data > to){
        return;
    }

    else{
        PrintRangeQueryI(node -> left, from, to);
        cout << node -> data << ' ';
        PrintRangeQueryI(node -> right, from, to);
    }
}

Node* BST::makeNode(int value){
    //return node with data of value and leafs of NULLs
    Node* newNode = new Node;
    newNode -> data = value;
    newNode -> left = newNode -> right = NULL;
    return newNode;
}

Node* BST::makeBSTI(vector<int>& v, int from, int to){
    //for 0 element
    if(from > to)return NULL;

    Node* node;
    //for 1 element
    if(from == to){
        int value = v[to];
        node = makeNode(value);
        return node;
    }

    int middle = (from + to) / 2;
    //node must be middle element of vector
    int value = v[middle];

    node = makeNode(value);
    // recursively get BST for left vector and make it left child of node
    node -> left = makeBSTI(v, from, middle - 1);
    // recursively get BST for right vector and make it right child of node
    node -> right = makeBSTI(v, middle + 1, to);
    return node;
}

//public functions
BST::BST(vector<int>& v){
    log_len = v.size();
    sort(v.begin(), v.begin() + v.size() - 1);
    root = makeBSTI(v, 0, v.size() - 1);
}

BST::~BST(){
    destroyBST(root);
}

void BST::printBST(string order){
    if(order == "inorder")inOrder(root);
    else if(order == "preorder")preOrder(root);
    else if(order == "postorder")postOrder(root);
    else cout << "Invalid Input" << endl;
}

bool BST::containsNode(int value){
    if(root -> data == value)return true;
    Node* node = findNode(root, value);
    if(node == NULL)return false;
    else return true;
}

int BST::getMaxNode(){
    Node* mx = getMaxNodeI(root);
    return mx ->data;
}

int BST::getMinNode(){
    Node* mn = getMinNodeI(root);
    return mn -> data;
}

void BST::insertLeaf(int value){
    log_len++;
    insertLeafI(root, value);
}

void BST::PrintRangeQuery(int from, int to){
    PrintRangeQueryI(root, from, to);
}

void BST::removeNode(int value){
    //if node is root
    if(root -> data == value){
        log_len --;
        Node* l = root -> left;
        Node* r = root -> right;
        delete root;

        root = r;
        Node* mn = getMinNodeI(r);
        mn -> left = l;
        return;
    }

    Node* node = findNode(root, value);
    if(node == NULL)return;
    // if element is on left
    if(node -> left != NULL && node -> left -> data == value){
        log_len--;

        Node* l = node -> left -> left;
        Node* r = node -> left -> right;

        delete node -> left;

        if(l != NULL){
            node -> left = l;

            Node* mx = getMaxNodeI(l);
            mx -> right = r;
            return;
        }
        if(r != NULL){
            node -> left = r;

            Node* mn = getMinNodeI(r);
            mn -> left = l;
            return;
        }
        node -> left = NULL;
        return;
    }
    //if element is on right
    if(node -> right != NULL && node -> right -> data == value){
        log_len--;

        Node* l = node -> right -> left;
        Node* r = node -> right -> right;

        delete node -> right;

        if(l != NULL){
            node -> right = l;

            Node* mx = getMaxNodeI(l);
            mx -> right = r;
            return;
        }
        if(r != NULL){
            node -> right = r;

            Node* mn = getMinNodeI(r);
            mn -> left = l;
            return;
        }
        node -> right = NULL;
        return;
    }
}

int BST::treeSize(){
    return log_len;
}