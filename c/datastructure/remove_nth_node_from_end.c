#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode* next;
} ListNode;

ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (head == NULL || n <= 0) {
        return head;
    }

    ListNode* fast = head;
    ListNode* slow = head;

    // Move the fast pointer n nodes ahead
    for (int i = 0; i < n; i++) {
        if (fast == NULL) {
            return head;
        }
        fast = fast->next;
    }

    // If the fast pointer reaches the end of the list,
    // remove the head node
    if (fast == NULL) {
        ListNode* tmp = head;
        head = head->next;
        free(tmp);
        return head;
    }

    // Move the slow pointer and the fast pointer at the same speed
    // until the fast pointer reaches the end of the list
    while (fast->next != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    // Remove the nth node from the end of the list
    ListNode* tmp = slow->next;
    slow->next = slow->next->next;
    free(tmp);

    return head;
}

void printList(ListNode* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int main() {
    ListNode* head = (ListNode*)malloc(sizeof(ListNode));
    head->val = 1;

    ListNode* node2 = (ListNode*)malloc(sizeof(ListNode));
    node2->val = 2;
    head->next = node2;

    ListNode* node3 = (ListNode*)malloc(sizeof(ListNode));
    node3->val = 3;
    node2->next = node3;

    ListNode* node4 = (ListNode*)malloc(sizeof(ListNode));
    node4->val = 4;
    node3->next = node4;

    ListNode* node5 = (ListNode*)malloc(sizeof(ListNode));
    node5->val = 5;
    node4->next = node5;

    node5->next = NULL;

    printf("Original list: ");
    printList(head);

    head = removeNthFromEnd(head, 2);

    printf("List after removing 2nd node from end: ");
    printList(head);

    return 0;
}
