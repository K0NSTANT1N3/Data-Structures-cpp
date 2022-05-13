//
// Created by konstantine on 5/13/22.
//

#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H
#include<bits/stdc++.h>
using namespace std;


struct Node
{
    int value;
    Node* next;
};


class LinkedQueue
{
private:
    Node* head;
    Node* tail;
    int log_len;
public:
    //O(1)
    LinkedQueue();
    //O(n)
    ~LinkedQueue();
    //O(1)
    void qPushBack(int elem);
    //O(1)
    int qFront();
    //O(1)
    void qPopFront();
    //O(1)
    int qSize();
    //O(1)
    bool qEmpty();
    //O(n)
    void printQ();
};

#endif