#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverse(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* current = head;
    ListNode* next = nullptr;
    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

ListNode* subtractLinkedList(ListNode* l1, ListNode* l2) {
    l1 = reverse(l1);
    l2 = reverse(l2);
    
    ListNode* result = nullptr;
    ListNode* current = nullptr;
    int borrow = 0;

    while (l1 != nullptr || l2 != nullptr) {
        int diff = (l1 ? l1->val : 0) - (l2 ? l2->val : 0) - borrow;
        borrow = 0;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        }
        ListNode* newNode = new ListNode(diff);
        if (result == nullptr) {
            result = newNode;
            current = newNode;
        } else {
            current->next = newNode;
            current = current->next;
        }
        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
    }
    return reverse(result);
}

void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    ListNode* l1 = new ListNode(7);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);
    
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(1);
    
    std::cout << "List 1: ";
    printList(l1);
    std::cout << "List 2: ";
    printList(l2);
    
    ListNode* result = subtractLinkedList(l1, l2);
    std::cout << "Result: ";
    printList(result);
    
    return 0;
}
