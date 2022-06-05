//
// Created by konstantine on 5/13/22.
//

#ifndef TWOSTACKQUEUE_H
#define TWOSTACKQUEUE_H

#include "../slow-stack-with-pointer-arrays/MyStack.h"


class TwoStackQueue
{
private:
    MyStack in, out;
    int log_len;
    //O(n)
    void dequeue();

public:
    //O(1)
    TwoStackQueue();
    //O(0)
    ~TwoStackQueue();
    //O(1)
    int queueSize();
    //O(1)
    bool isQueueEmpty();
    //O(n) or O(1)
    int queueFront();
    //O(n) or O(1)
    void queuePop();
    //O(1)
    void queuePush(int elem);
    //O(n)
    void printQueue();
};

#endif