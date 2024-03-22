#include <iostream>
#include <queue>

template<typename T>
class Queue {
private:
    std::queue<T> elements;

public:
    // Push element onto the queue
    void enqueue(const T& element) {
        elements.push(element);
    }

    // Remove and return the front element of the queue
    T dequeue() {
        if (isEmpty()) {
            std::cerr << "Error: Queue is empty\n";
            exit(1);
        }
        T frontElement = elements.front();
        elements.pop();
        return frontElement;
    }

    // Return the front element of the queue without removing it
    T& front() {
        if (isEmpty()) {
            std::cerr << "Error: Queue is empty\n";
            exit(1);
        }
        return elements.front();
    }

    // Check if the queue is empty
    bool isEmpty() const {
        return elements.empty();
    }

    // Return the size of the queue
    size_t size() const {
        return elements.size();
    }
};

int main() {
    Queue<int> queue;

    // Enqueue elements into the queue
    queue.enqueue(5);
    queue.enqueue(10);
    queue.enqueue(15);

    // Print the front element
    std::cout << "Front element: " << queue.front() << std::endl;

    // Dequeue elements from the queue
    std::cout << "Dequeued element: " << queue.dequeue() << std::endl;
    std::cout << "Dequeued element: " << queue.dequeue() << std::endl;

    // Check if the queue is empty
    std::cout << "Is queue empty? " << (queue.isEmpty() ? "Yes" : "No") << std::endl;

    return 0;
}
