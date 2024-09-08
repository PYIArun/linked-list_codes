#include <iostream>
using namespace std;

template <class T>
class dllNode{

    public:
    T data;
    dllNode<T> *prev= nullptr;
    dllNode<T> *next= nullptr;

    dllNode(){
        this->data = 0;
        prev= nullptr;
        next= nullptr; 
    }
    

    dllNode(T x){
        this->data = x;
        prev= nullptr;
        next= nullptr; 
    }
};