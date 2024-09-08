#include "sllNode.h"
#include <iostream>
using namespace std;


template <class T>
class List{

    public:
    sllNode<T> *head;

    List(){
        head = NULL;
    }

    void insertAtBeginning(T x){
        
        sllNode<T> *newNode = new sllNode<T>(x);
        newNode->next = head;
        head = newNode;

    }

    void insertAtEnd(T x){

        if(this->isEmpty()){
            head = new sllNode <T>(x);
            return;
        }
        
        sllNode<T> *temp = head;

        while(temp->next!=NULL){
            temp = temp->next;
        }

        temp->next = new sllNode<T>(x); 

    }

    void deleteBeginning(){
        if(head == NULL){
            cout<< "List is Empty. Nothing to delete";
            return;
        }
        sllNode<T> *temp = head;
        head = head->next;

        delete temp;
    }

    void deleteEnd(){
        if(head ==NULL){
            cout<< "List is Empty. Nothing to delete";
            return;
        }

        sllNode<T> *temp = head;
        sllNode<T> *prev = NULL;
        while(temp->next !=NULL){
            prev = temp;
            temp = temp->next;
        }

        prev->next = temp->next;
        delete temp;

    }
    
    void DeleteAtIndex(int index){
        
        if(index<0 || index >= this->length()){
            cout<< "Invalid Attempt!";
            return;
        }

        if (index == 0){
            sllNode<T> *temp = head;
            head = head->next;
            delete temp;
            return;
        }


        int counter = 0;
        sllNode <T> *temp = head;

        while (counter<index-1){
            temp = temp->next;
            counter++;
        }

        sllNode<T> *deleteTemp = temp->next;
        temp->next = temp->next->next;


        delete deleteTemp;

    }

    void DeleteByValue(T x){


        if(head == NULL){
            cout<< "List is Empty!";
            return;
        }

        sllNode<T> *temp = head;

        if(head->data == x){
            temp = head;
            head = head->next;
            delete temp;
            return;
        }

        while(temp->next!=NULL && temp->next->data!= x){
            temp = temp->next;
        } 

        if(temp->next == NULL){
            cout<< "No sllNode with this value found.";
            return;
        }

        sllNode<T> *deleteTemp = temp->next;
        temp->next = temp->next->next;

        delete deleteTemp;

    }

    void DeleteAll(){
        if (head == NULL) {
            cout << "List is Empty!";
            return;
        }
        sllNode <T> *temp = NULL;
        while(head->next!= NULL){
            temp = head;
            head = head->next;
            delete temp;
        }

        temp = head;
        head= NULL;
        delete temp;
    }
        
    int findValue(T x){

        if(head == NULL){
            cout<< "List is Empty!";
            return 0;
        }

        sllNode<T> *temp = head;

        if(head->data == x){
            return 1;
        }

        while(temp->next!=NULL && temp->data!= x){
            temp = temp->next;
        } 

        if(temp->next == NULL){
            return 0;
        }
        else{
            return 1;
        }


    }
    
    int SearchbyIndex(int index){

        if(index<0){
            return -1;
        }

        sllNode<T> *temp = head;


        int counter = 0;
        while(temp!= NULL && counter<index){
            temp = temp->next;
            counter++;
        }

        if(temp==NULL){
            cout<<"\nIndex Out of Bounds Error!";
        }

        return temp->data;
    }

    void reverse(){
        sllNode<T> *current = head;
        sllNode<T> *prev = NULL;
        sllNode<T> *next = NULL;


        while (current != NULL){
            next = current->next;
            current->next = prev;
            prev = current;
            current= next;
        }

        head = prev;
    }

    bool detectLoop(){
            sllNode<T> *fast = head;
            sllNode<T> *slow = head;

            while(fast!=NULL && fast->next !=NULL){

                fast = fast->next;
                fast = fast->next;
                slow = slow->next;

                
                if(fast==slow){
                    return true;
                }
            }

            return false;

        }   

    T middleElement(){

        if(head==NULL){
            cout<<"List is Empty!";
            return T();
        }

        sllNode<T> *fast = head;
        sllNode<T> *slow = head;

        while(fast!=NULL && fast->next !=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow->data;

    }

    sllNode<T>* FindnthNodefromEnd(int n){

        if (head == NULL) {
            cout << "List is Empty!";
            return NULL;
        }

        sllNode<T> *first = head;
        sllNode<T> *second = head;

        for(int i =0; i<n; i++){
            if(first==NULL){
                cout<<"This list has fewer sllNodes that "<< n<< ".";
                return NULL;

            }
            first= first->next;
        }

        while(first!=NULL && first->next != NULL){
            first= first->next;
            second= second->next;
        }

        return second;

    }

    static List<T>* mergeTwoList(List<T> *L1, List<T> *L2){
        
        List<T> *mergedList = new List<T>();

        sllNode<T> *first = L1->head;
        sllNode<T> *second = L2->head;

        while (first && second){
            
            if(first->data <second->data){
                mergedList->insertAtEnd(first->data);
                first = first->next;
            }
            else{
                mergedList->insertAtEnd(second->data);
                second = second->next;
            }
        }

        while(first){
            mergedList->insertAtEnd(first->data);
            first = first->next;
        }

        while(second){
            mergedList->insertAtEnd(second->data);
            second = second->next;
        }


        return mergedList;
    }

    void removeDuplicates(){
        sllNode<T> *current = head;


        while(current && current->next){

            if(current->data == current->next->data){
                sllNode<T> *temp = current->next;
                current->next= current->next->next;
                delete temp;
            }
            else{
                current = current->next;
            }

        }
    }

    
    bool isEmpty(){
        return head==NULL;
    }

    int length (){

        sllNode<T> *temp = head;

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
        sllNode<T> *temp = head;

        while(temp->next!= NULL){
            cout<< temp->data << " -> ";
            temp = temp->next;
        }

        cout<< temp->data;
    }

};

int main()
{

    List<int> l1;
    l1.insertAtEnd(3);
    l1.insertAtEnd(4);
    l1.insertAtEnd(5);

    l1.printList();

    cout<<endl;
    List<int> l2;
    l2.insertAtEnd(3);
    l2.insertAtEnd(22);
    l2.insertAtEnd(33);

    l2.printList();

    List<int>* concatenated_list = List<int>::mergeTwoList(&l1, &l2);
    cout<<endl;
    concatenated_list->printList();


    delete concatenated_list;

    cout<<endl<< "_____________________\n";
    List <int> l3 ;
    l3.insertAtBeginning(3);
    l3.insertAtBeginning(6);
    l3.insertAtBeginning(2);
    l3.insertAtBeginning(6);
    l3.insertAtBeginning(6);
    l3.insertAtBeginning(68);
    l3.removeDuplicates();
    l3.printList();
    return 0;
}