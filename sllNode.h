#include<iostream>
using namespace std;

template <class T>
class sllNode {

    public:
    T data;
   sllNode<T> *next;

   sllNode(){
        this->data = 0;
        this->next = NULL;
    }

   sllNode(T x){
        this->data = x;
        this->next = NULL;
    }
};