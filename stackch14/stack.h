/* 
 * File:   stack.h
 * Author: flavius
 *
 * Created on October 8, 2017, 1:32 PM
 */

#ifndef STACK_H
#define	STACK_H

template <typename Type>

class Stack{
private:
    enum {SIZE = 10};
    //Type items[MAX];
    int stacksize; // adding stacsize
    Type * items; // adding poiter to stack instead of fixed size array
    int top;
public:
    explicit Stack(int size = SIZE);
    Stack(const Stack & st);
    ~Stack() {delete [] items;}
    bool isempty() {return top == 0;}
    bool isfull() {return top == stacksize;}
    bool push(Type & item);
    bool pop(Type & item);
    Stack & operator=(const Stack & st);
};

template <typename Type>
Stack<Type>::Stack(int size) : stacksize(size), top(0) {
    items = new Type[stacksize];
}

template <typename Type>
Stack<Type>::Stack(const Stack& st){
    stacksize = st.stacksize;
    top = st.top;
    items = new Type[stacksize];
    int i;
    for(i = 0; i < stacksize; i++){
        items[i] = st.items[i];
    }
}

template <typename Type>
bool Stack<Type>::pop(Type& item){
    if(top > 0){
        item = items[--top];
        return true;
    }
    return false;    
}

template <typename Type>
bool Stack<Type>::push(Type& item){
    if(top < stacksize){
        item = items[top++];
        return true;
    }
    return false;
}

template <typename Type>
Stack<Type> & Stack<Type>::operator=(const Stack<Type> & st){
    if(this == &st)
        return *this;
    delete [] items;
    stacksize = st.stacksize;
    top = st.top;
    items = new Type[stacksize];
    int i;
    for(i = 0; i < stacksize; i++){
        items[i] = st.items[i];
    }
    return *this;
}

#endif	/* STACK_H */

