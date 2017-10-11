/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   queue.h
 * Author: flavius
 *
 * Created on October 10, 2017, 4:06 PM
 */

#ifndef QUEUE_H
#define QUEUE_H

template<typename Item> 
class Queue{
private:
        enum {Q_SIZE = 10};
        class Node{
        public:
            Item item;
            Node * next;
            Node(const Item & i) : item(i), next(0){}
        };
        Node * front;
        Node * rear;
        int items;
        const int qsize;
        Queue(const Queue & q) : qsize(0){}
        Queue & operator=(const Queue & q){return *this;}
public:
        Queue(int qs = Q_SIZE);
        ~Queue(); 
        bool isempty(){return items == 0;}
        bool isfull(){return items == qsize;}
        int quecount() const {return items;}
        bool enqueue(const Item & item);
        bool dequeue(Item & item);
};

template <class Item>
Queue<Item>::Queue(int qs) : qsize(qs){
    front = rear = 0;
    items = 0;
}

template <typename Item>
Queue<Item>::~Queue(){
    Node *temp;
    while(front != 0){
        temp = front;
        front = front->next;
        items--;
    }
}

template<typename Item>
bool Queue<Item>::enqueue(const Item& item){
    if(isfull())
        return false;
    Node * add = new Node(item); //create node
    items++; // increase number of items
    if(front == 0) // if front points to 0
        front = add;// place node at front
    else
        rear->next = add; // place at rear
    rear = add; // make rear point to new node
    return true;
}

template<typename Item>
bool Queue<Item>::dequeue(Item& item){
    if(isempty())
        return false;
    item = front->item; // set item to first item in queue
    items--;    
    Node * temp = front; // save location of first element
    front = front->next; // reset front to next item
    delete temp; // delete former first item
    if(items == 0)
        rear = 0;
    return true;
}
#endif /* QUEUE_H */

