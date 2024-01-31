#include <iostream>
using namespace std;
// Definition for singly-linked list.
struct Node{

    int val;
    Node *next;

    Node(int x):val(x),next(nullptr){}
};

class MyLinkedList {
public:
    Node *head;

    MyLinkedList() {
        head = nullptr;

    }

    int get(int index) {
        Node *current = head;
        for(int i =0;i<index && current ;++i){
            current = current->next;
        }
        if(current){
            return current->val;
        }
        else return -1;
    }

    void addAtHead(int val) {
        Node *newHead = new Node(val);
        if(!head){
            head = newHead;
            return;
        }
        else{
            newHead->next = head;
            head = newHead;
        }

    }

    void addAtTail(int val) {
        if(head == nullptr){
            Node *current = new Node(val);
            head = current;
            return;
        }
        Node *current = head;

        while(current->next){
            current = current->next;
        }
        if(current){
            Node*newTail = new Node(val);
            current->next = newTail;
        }

    }

    void addAtIndex(int index, int val) {
        /*
         *
         * void addAtIndex(int index, int val) Add a node of value val before the indexth node in the linked list. If index equals the length of the linked list, the node will be appended to the end of the linked list. If index is greater than the length, the node will not be inserted.

         *
         *
         *
         */
        Node* current = head;
        if(index == 0){
            addAtHead(val);
            return;
        }
        for(int i = 0;i<index-1 && current !=nullptr;++i){
            current = current->next;
        }
        if(current != nullptr){
            Node* newNode = new Node(val);
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    void deleteAtIndex(int index) {
        Node* Beforecurrent = head;
        if(index == 0 && head != nullptr){
            Node*temp = head->next;
            delete head;
            head = temp;
            return;
        }
        for (int i = 0; i < index - 1 && Beforecurrent != nullptr; ++i) {
            Beforecurrent = Beforecurrent->next;
        }

        if (Beforecurrent && Beforecurrent->next) {
            Node* temp = Beforecurrent->next;
            Beforecurrent->next = temp->next;
            delete temp;
        }
    }


};



