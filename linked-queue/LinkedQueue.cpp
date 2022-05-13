//
// Created by konstantine on 5/13/22.
//

#include"LinkedQueue.h"

//public functions

LinkedQueue::LinkedQueue(){
    log_len = 0;
    head = new Node;
    tail = new Node;
    head -> next = tail;
    tail -> next = head;
}
LinkedQueue::~LinkedQueue(){
    for(Node* i = head; i != NULL;){
        Node* cur = i;
        i = i -> next;
        delete cur;
    }
}
void LinkedQueue::qPushBack(int elem){
    Node* tmp = new Node;
    tmp -> value = elem;
    tmp -> next = tail;

    tail -> next -> next = tmp;
    tail -> next = tmp;
    log_len++;
}
int LinkedQueue::qFront(){
    return head -> next -> value;
}
void LinkedQueue::qPopFront(){
    if(log_len > 0){
        Node* tmp = head -> next;
        head -> next = head -> next -> next;
        delete tmp;
        log_len--;
    }
}
int LinkedQueue::qSize(){
    return log_len;
}
bool LinkedQueue::qEmpty(){
    return log_len > 0 ? false : true;
}

void LinkedQueue::printQ(){
    for(Node* itr = head -> next; itr != tail; itr = itr -> next){
        cout << itr -> value; cout << endl;
    }
}