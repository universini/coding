#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* rotateRight(ListNode* head, int k) {
    if (!head || k == 0) return head;

    // Calculate the length of the linked list
    int length = 1;
    ListNode* tail = head;
    while (tail->next) {
        tail = tail->next;
        length++;
    }

    // Adjust k to handle cases where k is larger than the length
    k = k % length;
    if (k == 0) return head;

    // Find the new tail and break the linked list
    ListNode* new_tail = head;
    for (int i = 0; i < length - k - 1; i++) {
        new_tail = new_tail->next;
    }

    ListNode* new_head = new_tail->next;
    new_tail->next = nullptr;
    tail->next = head;

    return new_head;
}

// Utility function to print a linked list
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val;
        current = current->next;
        if (current != nullptr) {
            std::cout << " -> ";
        }
    }
    std::cout << std::endl;
}

int main() {
    // Create a sample linked list
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 2;

    std::cout << "Original List:" << std::endl;
    printList(head);

    ListNode* rotated_head = rotateRight(head, k);

    std::cout << "\nList after rotation:" << std::endl;
    printList(rotated_head);

    // Clean up memory
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
