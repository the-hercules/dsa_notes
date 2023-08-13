#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node *next;

//constructor
    Node(int data) {
        this->data = data;
    }
};

void insertAtHead(Node *&head, int data) {
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

void inserAtTail(Node *&tail, int data) {
    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

void insertAtPosition(Node *&head, int position, int data) {
    Node *temp = head;
    int cnt = 1;
    while (cnt < position - 1) {
        temp = temp->next;
        cnt++;
    }
    Node *nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}
void printLL(Node *&head) {
    Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;

    }
    cout << endl;
}


int main() {
    Node *newNode = new Node(1);
    Node *head = newNode;
    Node *tail = newNode;
//    insertAtHead(head,15);
//    insertAtHead(head,20);
//    insertAtHead(head,25);
    inserAtTail(tail, 2);
    inserAtTail(tail, 3);
    inserAtTail(tail, 4);
    printLL(head);

}
