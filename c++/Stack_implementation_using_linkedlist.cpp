#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(NULL) {}
};

class Stack {
private:
    Node* top;

public:
    Stack() : top(NULL) {}

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        std::cout << "Pushed " << value << " onto the stack." << std::endl;
    }

    void pop() {
        if (isEmpty()) {
            std::cout << "Stack is empty. Cannot pop." << std::endl;
            return;
        }

        Node* temp = top;
        top = top->next;
        std::cout << "Popped " << temp->data << " from the stack." << std::endl;
        delete temp;
    }

    bool isEmpty() {
        return top == NULL;
    }

    void display() {
        if (isEmpty()) {
            std::cout << "Stack is empty." << std::endl;
            return;
        }

        std::cout << "Stack elements: ";
        Node* current = top;
        while (current != NULL) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

   
};

int main() {
    Stack stack;
    int choice, value;

    do {
        std::cout << "\nStack Menu:" << std::endl;
        std::cout << "1. Push" << std::endl;
        std::cout << "2. Pop" << std::endl;
        std::cout << "3. Check if the stack is empty" << std::endl;
        std::cout << "4. Display stack elements" << std::endl;
        std::cout << "5. Quit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter value to push: ";
                std::cin >> value;
                stack.push(value);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                if (stack.isEmpty()) {
                    std::cout << "Stack is empty." << std::endl;
                } else {
                    std::cout << "Stack is not empty." << std::endl;
                }
                break;
            case 4:
                stack.display();
                break;
            case 5:
                std::cout << "Exiting program." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Try again." << std::endl;
        }
    } while (choice != 5);

    return 0;
}
