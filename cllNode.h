#include <iostream>
using namespace std;

template <class T>
class cllNode{

    public:
    T data;
    cllNode *next;

    cllNode(){
        data = 0;
        next = nullptr;
    }

    cllNode(T x){
        data = x;
        next = nullptr;
    }
};