#include <iostream>
#include<chrono>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class Stack {
private:
    Node* top;
    int max_size;
    int size;

public:
    // Constructor to initialize stack
    Stack(int size) {
        this->max_size = size;
        this->size = 0;
        this->top = nullptr;
    }

    // Push operation to insert data into the stack
    void push(int data) {
        if (isFull()) {
            cout << "Stack Overflow" << endl;
            return;
        }
        Node* newNode = new Node(data);
        newNode->next = top;
        top = newNode;
        size++;
    }

    // Pop operation to remove/delete data from the stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        int data = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        size--;
        return data;
    }

    // Check whether the stack is empty or not
    bool isEmpty() {
        return size == 0;
    }

    // Check whether the stack is full or not
    bool isFull() {
        return size == max_size;
    }

    // Peek operation to find what is at the top of the stack
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return top->data;
    }

    // Display all the elements of the stack
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Stack elements are: ";
        Node* current = top;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    int size;
    cout<< "enter the size of the array : " ;
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
