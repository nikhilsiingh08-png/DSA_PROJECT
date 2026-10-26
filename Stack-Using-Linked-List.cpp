
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Stack {
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;

        cout << value << " pushed into stack\n";
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return;
        }

        Node* temp = top;
        cout << "Popped element: " << top->data << "\n";
        top = top->next;
        delete temp;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }

        cout << "Top element: " << top->data << "\n";
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }

        Node* temp = top;
        cout << "Stack elements: ";

        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << "\n";
    }

    ~Stack() {
        while (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main() {
    Stack s;
    int choice, value;

    do {
        cout << "\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            s.push(value);
            break;

        case 2:
            s.pop();
            break;

        case 3:
            s.peek();
            break;

        case 4:
            s.display();
            break;

        case 5:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice\n";
        }
    } while (choice != 5);

    return 0;
}
