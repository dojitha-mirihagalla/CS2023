#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct LinkedList {
    Node* top;

    LinkedList() {
        top = NULL;
    }

    void push(int x) {
        Node* newNode = new Node;
        newNode->data = x;
        newNode->next = top;
        top = newNode;
        cout << "Pushed " << x << " onto the stack.\n";
        cout << "Stack: [ ";
        Node* curr = top;
        while (curr != NULL) {
            cout << curr->data << " , ";
            curr = curr->next;
        }
        cout << "]\n";
    }

    int pop() {
        if (top == NULL) {
            cout << "Stack Underflow\n";
            return -1;
        }
        int x = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        cout << "Popped " << x << " from the stack.\n";
        cout << "Stack: [ ";
        Node* curr = top;
        while (curr != NULL) {
            cout << curr->data << " , ";
            curr = curr->next;
        }
        cout << "]\n";
        return x;
    }

    bool isEmpty() {
        return (top == NULL);
    }

    int peek() {
        if (top == NULL) {
            cout << "Stack is empty\n";
            return -1;
        }
        int x = top->data;
        return x;
    }
};

int main() {
    LinkedList stack;
    stack.push(11);
    stack.push(120);
    stack.push(350);
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.push(10);
    stack.push(75);
    stack.push(63);
    stack.push(12);
    stack.push(5);
    stack.pop();
    stack.pop();
    return 0;
}
