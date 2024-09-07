#include<iostream>
using namespace std;

template <class T>
class Node {

    public:
    T data;
    Node<T> *next;

    Node(){
        this->data = 0;
        this->next = NULL;
    }

    Node(T x){
        this->data = x;
        this->next = NULL;
    }
};