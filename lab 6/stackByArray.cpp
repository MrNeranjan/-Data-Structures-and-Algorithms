#include <iostream>
#include<chrono>
using namespace std;

class Stack {
private:
    int max_size;
    int top;
    int* stack;

public:
    // Constructor to initialize stack
    Stack(int size) {
        max_size = size;
        top = -1;
        stack = new int[max_size];
    }

    // Push operation to insert data into the stack
    void push(int data) {
        if (isFull()) {
            cout << "Stack Overflow" << endl;
            return;
        }
        top++;
        stack[top] = data;
    }

    // Pop operation to remove/delete data from the stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        int data = stack[top];
        top--;
        return data;
    }

    // Check whether the stack is empty or not
    bool isEmpty() {
        return top == -1;
    }

    // Check whether the stack is full or not
    bool isFull() {
        return top == max_size - 1;
    }

    // Peek operation to find what is at the top of the stack
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return stack[top];
    }

    // Display all the elements of the stack
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Stack elements are: ";
        for (int i = top; i >= 0; i--) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int size;
    cout<< "enter the size of the Stack : " ;
    cin>> size;
    Stack demo(size);

    auto start_time = chrono::high_resolution_clock::now(); 

    for (int i=0;i<size;i++){
    demo.push(rand()%size);
  }

demo.display();
for (int i=0;i<size/2;i++){
    demo.pop();
}

demo.display();
    for (int i=0;i<size/3;i++){
    demo.push(rand()%size);
  }

demo.display();

    auto end_time = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
    cout << "Execution time: " << duration << " microseconds" ;   

}
