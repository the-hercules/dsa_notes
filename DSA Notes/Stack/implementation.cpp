#include "bits/stdc++.h"

using namespace std;

class Stack {
public:
    int size;
    int *arr;
    int top;

    Stack(int size) {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element) {
        if (top >= size) {
            cout << "stack overflow" << endl;
        } else {
            top++;
            arr[top] = element;
        }
    }

    void pop() {
        if (top >= 0) {
            top--;
        }
    }

    int peek() {
        if (top >= 0 && top < size) {
            return arr[top];
        } else
            cout << "index error" << endl;
    }

};


int main() {
    Stack myStack(5);

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    std::cout << "Top element: " << myStack.peek() << std::endl;

    myStack.pop();
    std::cout << "Top element after pop: " << myStack.peek() << std::endl;

    myStack.push(40);
    myStack.push(50);
    myStack.push(60);
    myStack.push(70);
    myStack.push(80);
}
