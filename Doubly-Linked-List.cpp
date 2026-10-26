
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int value) {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList {
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        cout << value << " inserted\n";
    }

    void deleteValue(int value) {
        Node* temp = head;

        while (temp != nullptr && temp->data != value) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Value not found\n";
            return;
        }

        if (temp->prev != nullptr)
            temp->prev->next = temp->next;
        else
            head = temp->next;

        if (temp->next != nullptr)
            temp->next->prev = temp->prev;
        else
            tail = temp->prev;

        delete temp;
        cout << "Node deleted\n";
    }

    void displayForward() {
        Node* temp = head;
        cout << "Forward: ";

        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }

        cout << "NULL\n";
    }

    void displayBackward() {
        Node* temp = tail;
        cout << "Backward: ";

        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->prev;
        }

        cout << "NULL\n";
    }

    ~DoublyLinkedList() {
        Node* temp = head;

        while (temp != nullptr) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }
};

int main() {
    DoublyLinkedList list;
    int choice, value;

    do {
        cout << "\n1. Insert at End\n";
        cout << "2. Delete Value\n";
        cout << "3. Display Forward\n";
        cout << "4. Display Backward\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            list.insertAtEnd(value);
            break;

        case 2:
            cout << "Enter value to delete: ";
            cin >> value;
            list.deleteValue(value);
            break;

        case 3:
            list.displayForward();
            break;

        case 4:
            list.displayBackward();
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
