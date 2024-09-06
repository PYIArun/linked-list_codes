#include "Node.h"
#include <iostream>
using namespace std;


template <class T>
class List{

    public:
    Node<T> *head;

    List(){
        head = NULL;
    }

    void insertAtBeginning(T x){
        
        Node<T> *newNode = new Node<T>(x);
        newNode->next = head;
        head = newNode;

    }

    void insertAtEnd(T x){

        if(this->isEmpty()){
            head = new Node <T>(x);
            return;
        }
        
        Node<T> *temp = head;

        while(temp->next!=NULL){
            temp = temp->next;
        }

        temp->next = new Node<T>(x); 

    }

    void DeleteAtIndex(int index){
        
        if(index<0 || index >= this->length()){
            cout<< "Invalid Attempt!";
            return;
        }

        if (index == 0){
            Node<T> *temp = head;
            head = head->next;
            delete temp;
            return;
        }


        int counter = 0;
        Node <T> *temp = head;

        while (counter<index-1){
            temp = temp->next;
            counter++;
        }

        Node<T> *deleteTemp = temp->next;
        temp->next = temp->next->next;


        delete deleteTemp;

    }

    void DeleteByValue(T x){

        if(head == NULL){
            cout<< "List is Empty!";
            return;
        }

        Node<T> *temp = head;

        if(head->data == x){
            temp = head;
            head = head->next;
            delete temp;
            return;
        }

        while(temp->next!=NULL & temp->next->data!= x){
            temp = temp->next;
        } 

        Node<T> *deleteTemp = temp->next;
        temp->next = temp->next->next;

        delete deleteTemp;

    }
    void deleteBeginning(){
        if(head == NULL){
            cout<< "List is Empty. Nothing to delete";
            return;
        }
        Node<T> *temp = head;
        head = head->next;

        delete temp;
    }

    void deleteEnd(){
        if(head ==NULL){
            cout<< "List is Empty. Nothing to delete";
            return;
        }

        Node<T> *temp = head;
        Node<T> *prev = NULL;
        while(temp->next !=NULL){
            prev = temp;
            temp = temp->next;
        }

        prev->next = temp->next;
        delete temp;

    }
    bool isEmpty(){
        return head==NULL;
    }

    int length (){

        Node<T> *temp = head;

        int length = 1;

        while(temp->next!=NULL){
            temp = temp->next;
            length++;
        }
        return length;
    }
    void printList(){

        if(this->isEmpty()){
            cout<<"List is Empty!";
        }
        Node<T> *temp = head;

        while(temp->next!= NULL){
            cout<< temp->data << " -> ";
            temp = temp->next;
        }

        cout<< temp->data;
    }



};

int main()
{

    List<int> l;
    l.insertAtEnd(3);
    l.insertAtEnd(4);
    l.insertAtEnd(5);
    l.insertAtBeginning(1);
    l.printList();
    return 0;
}