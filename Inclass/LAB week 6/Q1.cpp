#include <iostream>
using namespace std;

const int MAX_SIZE = 100; // maximum size of stack

int arr[MAX_SIZE]; // array to store the stack elements
int top = -1; // index of the top element in the stack

void push(int x) {
    if (top >= MAX_SIZE - 1) {
        cout << "Stack Overflow\n";
        return;
    }
    arr[++top] = x;
    cout << "Pushed " << x << " onto the stack.\n";
    cout << "Stack: [";
    for (int i = 0; i <= top; i++) {
        cout << arr[i] << " , ";
    }
    cout << "]\n";
}

int pop() {
    if (top < 0) {
        cout << "Stack Underflow\n";
        return -1;
    }
    int x = arr[top--];
    cout << "Popped " << x << " from the stack.\n";
    cout << "Stack: [ ";
    for (int i = 0; i <= top; i++) {
        cout << arr[i] << " , ";
    }
    cout << "]\n";
    return x;
}

bool isEmpty() {
    return (top < 0);
}

int peek() {
    if (top < 0) {
        cout << "Stack is empty\n";
        return -1;
    }
    int x = arr[top];
    return x;
}

int main() {
    push(45);
    push(100);
    push(12);
    push(10);
    push(46);
    pop();
    pop();
    push(46);
    pop();
    pop();
    return 0;
}
