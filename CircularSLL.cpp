#include "cllNode.h"
#include <iostream>
using namespace std;

template <class T>
class List{

    public:
    cllNode<T> *head;

    List(){

        head  = nullptr;
    }

    void insertAtBeginning(T x){
        cllNode<T> *newNode = new cllNode<T>(x);

        if(head == nullptr){
            head = newNode;
            newNode->next = head;    
            return;
        }

        cllNode<T> *temp = head;
        while(temp->next !=head ){
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = head;
        head = newNode;

    }

    void printList(){

        if(head==nullptr){
            cout<<"List is Empty!";
            return;
        }

        cllNode<T> *temp = head;


        do{
            cout<<temp->data << "->";
            temp = temp->next;

        }while(temp->next!=head);
        
        cout<<temp->data;
        cout << endl;  // Add a newline for clean output

    }

    void insertAtEnd(T x){

        if(head==nullptr){
            return;
        }
        cllNode<T> *newNode = new cllNode<T>(x);
        cllNode<T> *temp = head;

        while(temp->next !=head ){
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next =head;
    }

   void deleteAtBeginning() {
        if (head == nullptr) {
            return;
        }

        cllNode<T> *temp = head;
        
        if (temp->next == head) {
            // Only one node in the list
            head = nullptr;
            delete temp;
        } else {
            // More than one node in the list
            cllNode<T> *last = head;
            while (last->next != head) {
                last = last->next;
            }
            head = head->next;
            last->next = head;
            delete temp;
        }
    }

    void deleteAtEnd() {
        if (head == nullptr) {
            return;
        }

        cllNode<T> *temp = head;
        if (temp->next == head) {

            delete temp;
            head = nullptr;
            return;
        }

        
        cllNode<T> *prev = nullptr;


        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }


        if (prev != nullptr) {
            prev->next = head;  
    }
    
    
}
};


int main(){

    List<int> L1;
    L1.insertAtBeginning(5);
    L1.insertAtBeginning(5);
    L1.insertAtBeginning(12);
    L1.insertAtEnd(12);
    L1.insertAtEnd(43);
    L1.deleteAtBeginning();
    L1.deleteAtBeginning();
    L1.deleteAtEnd();
    L1.deleteAtEnd();
    L1.printList();
    
}