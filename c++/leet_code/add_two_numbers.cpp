#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummy_head = new ListNode(0);
    ListNode* current = dummy_head;
    int carry = 0;

    while (l1 != nullptr || l2 != nullptr) {
        int x = (l1 != nullptr) ? l1->val : 0;
        int y = (l2 != nullptr) ? l2->val : 0;

        int sum = carry + x + y;
        carry = sum / 10;

        current->next = new ListNode(sum % 10);
        current = current->next;

        if (l1 != nullptr) l1 = l1->next;
        if (l2 != nullptr) l2 = l2->next;
    }

    if (carry > 0) {
        current->next = new ListNode(carry);
    }

    ListNode* result = dummy_head->next;
    delete dummy_head;
    return result;
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
    // Create two example linked lists representing numbers 243 and 465
    ListNode* l1 = new ListNode(3);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(2);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    std::cout << "Input Lists:" << std::endl;
    std::cout << "List 1: ";
    printList(l1);

    std::cout << "List 2: ";
    printList(l2);

    ListNode* sum_list = addTwoNumbers(l1, l2);

    std::cout << "\nSum of the two numbers:" << std::endl;
    printList(sum_list);

    // Clean up memory
    while (l1 != nullptr) {
        ListNode* temp = l1;
        l1 = l1->next;
        delete temp;
    }

    while (l2 != nullptr) {
        ListNode* temp = l2;
        l2 = l2->next;
        delete temp;
    }

    while (sum_list != nullptr) {
        ListNode* temp = sum_list;
        sum_list = sum_list->next;
        delete temp;
    }

    return 0;
}
