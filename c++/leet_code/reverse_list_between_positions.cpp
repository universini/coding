#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseBetween(ListNode* head, int m, int n) {
    if (head == nullptr || m == n) return head;

    ListNode dummy(0);
    dummy.next = head;
    ListNode* prev = &dummy;

    // Move to the mth node
    for (int i = 1; i < m; ++i) {
        if (!prev->next) return head; // m exceeds list length
        prev = prev->next;
    }

    ListNode* curr = prev->next;
    ListNode* tail = curr;

    // Reverse the nodes from m to n
    for (int i = m; i <= n; ++i) {
        ListNode* next = curr->next;
        curr->next = prev->next;
        prev->next = curr;
        curr = next;
    }

    tail->next = curr;

    return dummy.next;
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

    int m = 2;
    int n = 4;

    std::cout << "Original List:" << std::endl;
    printList(head);

    ListNode* reversed_head = reverseBetween(head, m, n);

    std::cout << "\nList after reversing between positions " << m << " and " << n << ":" << std::endl;
    printList(reversed_head);

    // Clean up memory
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
