#include <iostream>
#include <vector>

template<typename T>
class Stack {
private:
    std::vector<T> elements;

public:
    // Push element onto the stack
    void push(const T& element) {
        elements.push_back(element);
    }

    // Remove and return the top element of the stack
    T pop() {
        if (isEmpty()) {
            std::cerr << "Error: Stack is empty\n";
            exit(1);
        }
        T topElement = elements.back();
        elements.pop_back();
        return topElement;
    }

    // Return the top element of the stack without removing it
    T& top() {
        if (isEmpty()) {
            std::cerr << "Error: Stack is empty\n";
            exit(1);
        }
        return elements.back();
    }

    // Check if the stack is empty
    bool isEmpty() const {
        return elements.empty();
    }

    // Return the size of the stack
    size_t size() const {
        return elements.size();
    }
};

int main() {
    Stack<int> stack;

    // Push elements onto the stack
    stack.push(5);
    stack.push(10);
    stack.push(15);

    // Print the top element
    std::cout << "Top element: " << stack.top() << std::endl;

    // Pop elements from the stack
    std::cout << "Popped element: " << stack.pop() << std::endl;
    std::cout << "Popped element: " << stack.pop() << std::endl;

    // Check if the stack is empty
    std::cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << std::endl;

    return 0;
}
