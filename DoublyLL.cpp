#include "dllNode.h"
#include <iostream>

using namespace std;

template <class T>
class dList{

    public:
    dllNode<T> *head;


    dList(){
        this->head = nullptr;
    }

    void insertAtBeginning(T x){
        dllNode<T> *newNode = new dllNode<T>(x);

        if(isEmpty()){
            head = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void insertAtEnd(T x){
        dllNode<T> *newNode = new dllNode<T>(x);

        if (isEmpty()){
            head = newNode;
            return;
        }

        dllNode<T> *temp = head;

        while(temp->next != nullptr){
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;


    }

    void insertAtIndex(T x, int index){
        
        if (isEmpty()){
            cout<<"List is Empty!"<<endl;
            return;
        }

        if (index<0 || index>=length()){
            cout<<"Invalid Index"<<endl;;
            return;
        }

        if(index ==0){
            insertAtBeginning(x);
            return;
        }

        dllNode<T> *newNode = new dllNode<T> (x); 
    

        int counter = 0;
        dllNode<T> *temp = head;

        while(counter<index && temp->next!=nullptr){
            counter++;
            temp = temp->next;
        }


        temp->prev->next = newNode;
        newNode->prev = temp->prev;
        newNode->next = temp;
        temp->prev = newNode;

    }
    
    void deleteBeginning(){

        if(isEmpty()){
            cout<<"List is Empty!"<<endl;
            return;
        }

        dllNode<T> *temp = head;
    
        if(head->next !=NULL){

        head = head->next;
        head->prev = nullptr;
        }
        else{
            head= nullptr;
        }

        delete temp;

    }

    void deleteEnd(){

        if(isEmpty()){
            cout<<"List is Empty!"<<endl;
            return;
        }
        
        dllNode<T> *temp = head;

        if(head->next == nullptr){
            head= nullptr;
            delete temp;
            return;
        }
        while(temp->next != nullptr){
            temp = temp->next;
        }

        temp->prev->next = nullptr;
        delete temp;

    }

    void deleteAtIndex(int index){

        if(isEmpty()){
            cout<<"List is Empty!";
            return;
        }

        
        if(index<0 || index>=length()){
            cout<<"Invalid Index!"<<endl;
            return;
        }

        int counter =0;
        dllNode<T> *temp = head;

        while (counter<index && temp->next!=nullptr)
        {
            counter++;
            temp= temp->next;
        }

        if(temp==head){
            head = temp->next;

            if(head!= nullptr){
                head->prev = nullptr;
            }
            delete temp;
            return;
        }
        if(temp->next == nullptr){
            temp->prev->next = nullptr;
            delete temp;
            return;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        delete temp;

    }

    int length(){
        if(head==nullptr){
            return 0;
        }
        int length = 1;

        dllNode<T> *temp = head;

        while(temp->next !=nullptr){
            length++;
            temp = temp->next;
        }
        return length;
    }
    bool isEmpty(){
        if (head==NULL){
            return true;
        }

        return false;
    }
    void printList(){

        dllNode<T> *temp = head;
        if(isEmpty()){
            return;
        }
        while(temp->next != nullptr){
            cout<< '('<<temp->data<<')'<< "-><-";
            temp = temp-> next;
        }

        cout<<temp->data;
    }


    void reverse(){
        if(head==nullptr){
            return;
        }


        dllNode<T> *temp = nullptr;
        dllNode<T> *current = head;
        
        while(current != nullptr){

            temp = current->prev;
            current->prev = current->next;
            current->next = temp;


            current = current->prev;
        }


        if(temp!=nullptr){
            head = temp->prev;
        }
    }
};


int main(){


    dList<int> L1;
    L1.insertAtBeginning(5);
    L1.insertAtBeginning(8);
    L1.insertAtBeginning(2);
    L1.insertAtEnd(33);
    L1.insertAtEnd(24);
    L1.printList();
    cout<<endl;
    cout<< "Length of List is: "<< L1.length();
    cout<<endl;
    L1.printList();
    L1.reverse();
    cout<<endl;
    L1.printList();
    return 0;
}