#include <iostream>
#include <chrono> // for measuring time
using namespace std;

const int MAX_SIZE = 100; // maximum size of stack

int arr[MAX_SIZE]; // array to store the stack elements
int top = -1;      // index of the top element in the stack

void push(int x)
{
    if (top >= MAX_SIZE - 1)
    {
        cout << "Stack Overflow\n";
        return;
    }
    arr[++top] = x;
    cout << "Pushed " << x << " onto the stack.\n";
}

int pop()
{
    if (top < 0)
    {
        cout << "Stack Underflow\n";
        return -1;
    }
    int x = arr[top--];
    cout << "Popped " << x << " from the stack.\n";
    return x;
}

bool isEmpty()
{
    return (top < 0);
}

int peek()
{
    if (top < 0)
    {
        cout << "Stack is empty\n";
        return -1;
    }
    int x = arr[top];
    return x;
}

void display()
{
    if (top < 0)
    {
        cout << "Stack is empty\n";
        return;
    }
    cout << "Stack: [ ";
    for (int i = 0; i <= top; i++)
    {
        cout << arr[i] << " - ";
    }
    cout << "]\n";
}

int main()
{
    auto start = chrono::high_resolution_clock::now();
    push(8);
    push(10);
    push(5);
    push(11);
    push(15);
    push(23);
    push(6);
    push(18);
    push(20);
    push(17);
    cout << endl;
    display();
    cout << endl;
    for (int i = 0; i < 5; i++)
    {
        pop();
    }

    cout << endl;
    display();
    cout << endl;

    push(4);
    push(30);
    push(3);
    push(1);

    cout << endl;
    display();
    cout << endl;

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Time taken for execution: " << duration.count() << " microseconds\n";
    cout << endl;
    return 0;
}
