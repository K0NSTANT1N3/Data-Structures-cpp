//
// Created by konstantine on 5/13/22.
//

#include"MyStack.h"

//private functions
void MyStack::stackGrow(){
    int* newData = new int[alloc_len *= 2];
    for(int i = 0; i < log_len; i++){
        newData[i] = data[i];
    }
    clearStackData(data);
    data = newData;
}

void MyStack::clearStackData(int* curData){
    delete[] curData;
}

//public functions
MyStack::MyStack(){
    data = new int[4];
    log_len = 0;
    alloc_len = 4;
}
MyStack::~MyStack(){
    clearStackData(data);
}

int MyStack::stackSize(){
    return log_len;
}
bool MyStack::isStackEmpty(){
    return log_len == 0 ? true : false;
}
void MyStack::stackPush(int elem){
    if(log_len >= alloc_len)stackGrow();

    data[log_len] = elem;
    log_len ++;
}
void MyStack::stackPop(){
    log_len --;
}
int MyStack::stackTop(){
    return data[log_len - 1];
}

void MyStack::printStack(){
    for(int i = log_len - 1; i >= 0; i--){
        cout << data[i] << ' ';
    }
}

void MyStack::printReverseStack(){
    for(int i = 0; i < log_len; i++){
        cout << data[i] << ' ';
    }
}