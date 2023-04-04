#include <iostream>
#include <chrono>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct Stack {
    Node* top;

    Stack() {
        top = NULL;
    }

    void push(int x) {
        Node* newNode = new Node;
        newNode->data = x;
        newNode->next = top;
        top = newNode;
        cout << "Pushed " << x << " onto the stack.\n";
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

    void display() {
        if (top == NULL) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack: [";
        Node* curr = top;
        while (curr != NULL) {
            cout << curr->data << " - ";
            curr = curr->next;
        }
        cout << "]\n";
    }
};

int main() {
    Stack s;
    auto start = chrono::high_resolution_clock::now();
    s.push(8);
    s.push(10);
    s.push(5);
    s.push(11);
    s.push(15);
    s.push(23);
    s.push(6);
    s.push(18);
    s.push(20);
    s.push(17);
    cout<<endl;
    s.display();
    cout<<endl;
    for (int i = 0; i < 5; i++) {
        s.pop();
    }

    cout<<endl;
    s.display();
    cout<<endl;

    s.push(4);
    s.push(30);
    s.push(3);
    s.push(1);

    cout<<endl;
    s.display();
    cout<<endl;

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Time taken for execution: " << duration.count() << " microseconds\n";
    cout<<endl;
    return 0;
}
