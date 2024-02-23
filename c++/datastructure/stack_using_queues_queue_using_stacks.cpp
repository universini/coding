#include <iostream>
#include <stack>
#include <queue>

// Queue using two stacks
class QueueWithStacks {
private:
    std::stack<int> inbox;   // For enqueue operation
    std::stack<int> outbox;  // For dequeue operation

public:
    // Enqueue operation: O(1)
    void enqueue(int value) {
        inbox.push(value);
    }

    // Dequeue operation: Amortized O(1)
    int dequeue() {
        if (outbox.empty()) {
            // Transfer elements from inbox to outbox
            while (!inbox.empty()) {
                outbox.push(inbox.top());
                inbox.pop();
            }
        }

        if (outbox.empty()) {
            // Queue is empty
            std::cerr << "Queue is empty!" << std::endl;
            return -1;  // Error value
        }

        int frontElement = outbox.top();
        outbox.pop();
        return frontElement;
    }
};

// Stack using two queues
class StackWithQueues {
private:
    std::queue<int> queue1;
    std::queue<int> queue2;

public:
    // Push operation: O(1)
    void push(int value) {
        // Push the new element to an empty queue and transfer elements from the other queue
        if (queue1.empty()) {
            queue2.push(value);
            while (!queue1.empty()) {
                queue2.push(queue1.front());
                queue1.pop();
            }
        } else {
            queue1.push(value);
            while (!queue2.empty()) {
                queue1.push(queue2.front());
                queue2.pop();
            }
        }
    }

    // Pop operation: O(1)
    int pop() {
        if (empty()) {
            std::cerr << "Stack is empty!" << std::endl;
            return -1;  // Error value
        }

        int topElement;
        if (!queue1.empty()) {
            topElement = queue1.front();
            queue1.pop();
        } else {
            topElement = queue2.front();
            queue2.pop();
        }

        return topElement;
    }

    // Check if the stack is empty
    bool empty() const {
        return queue1.empty() && queue2.empty();
    }
};

int main() {
    // Queue using two stacks
    QueueWithStacks q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    std::cout << "Dequeue: " << q.dequeue() << std::endl;  // Should print 1

    // Stack using two queues
    StackWithQueues s;
    s.push(1);
    s.push(2);
    s.push(3);
    std::cout << "Pop: " << s.pop() << std::endl;  // Should print 3

    return 0;
}
