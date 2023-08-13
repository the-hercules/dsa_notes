#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node *prev;
    Node *next;
//constructor
    Node(int data) {
        this->data = data;
        prev= nullptr;
        next=nullptr;
    }
};
void printLL(Node * head){
    Node *temp = head;
    while(temp!= nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
void printLength(Node *head){
    int i=0;
    Node * temp=head;
    while(temp!= nullptr){
        temp=temp->next;
        i++;
    }
    cout<<i<<endl;
}
void insertAtHead(Node*&head,int data){
    Node * temp=new Node(data);
    temp->next=head;
    head->prev=temp;
    head=temp;
}
void insertAtTail(Node*&head,int data){
    Node * curr=head;
    while(curr->next!= nullptr){
        curr=curr->next;
    }
    Node * temp=new Node(data);
    curr->next=temp;
    temp->prev=curr;
}

int main() {
    Node *newNode = new Node(0);
    Node * head = newNode;
//    insertAtHead(head,1);
//    insertAtHead(head,2);
//    insertAtHead(head,3);
//    insertAtHead(head,4);
    insertAtTail(head,1);
    insertAtTail(head,1);
    insertAtTail(head,1);
    insertAtTail(head,1);
    insertAtTail(head,1);
    insertAtTail(head,1);
    printLength(head);
    printLL(head );
}
