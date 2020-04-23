#include<iostream>
const int LIMIT=1000;

class Stack
{
    char contents[LIMIT];
    int StackTop;
public:
    Stack();
    int StackTopValue();
    bool isFull();
    bool isEmpty();
    void Push(char x);
    char Pop();     
};

#include "Stack.cpp"
