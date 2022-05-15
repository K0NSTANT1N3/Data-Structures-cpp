//
// Created by konstantine on 5/13/22.
//

#ifndef MYSTACK_H
#define MYSTACK_H

#include<iostream>
using namespace std;


class MyStack
{
private:
    int* data;
    int log_len, alloc_len;
    //O(logx * n + (x - logx) * 1)
    void stackGrow();
    //O(1)
    void clearStackData(int* curData);

public:
    //O(1)
    MyStack();
    //O(1)
    ~MyStack();

    //O(1)
    int stackSize();
    //O(1)
    bool isStackEmpty();
    //O(logx * n + (x - logx) * 1)
    void stackPush(int elem);
    //O(1)
    void stackPop();
    //O(1)
    int stackTop();
    //O(n)
    void  printStack();
    //O(n)
    void printReverseStack();
};

#endif