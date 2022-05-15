//
// Created by konstantine on 5/13/22.
//

#include"TwoStackQueue.h"

//private functions
void TwoStackQueue::dequeue(){
    while (!in.isStackEmpty()){
        int element = in.stackTop();
        in.stackPop();
        out.stackPush(element);
    }
}


//public functions
TwoStackQueue::TwoStackQueue(){
    log_len = 0;
}

TwoStackQueue::~TwoStackQueue(){

}

int TwoStackQueue::queueSize(){
    return log_len;
}

bool TwoStackQueue::isQueueEmpty(){
    return log_len == 0 ? true : false;
}

int TwoStackQueue::queueFront(){
    if(out.isStackEmpty()){
        dequeue();
    }
    return out.stackTop();
}

void TwoStackQueue::queuePop(){
    if(out.isStackEmpty()){
        dequeue();
    }
    out.stackPop();
    log_len --;
}

void TwoStackQueue::queuePush(int elem){
    in.stackPush(elem);
    log_len ++;
}

void TwoStackQueue::printQueue(){
    if(!out.isStackEmpty()){
        out.printStack();
    }
    in.printReverseStack();
}