#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list
struct ListNode {
    int val;
    struct ListNode* next;
};

// Function to create a new node
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Function to find the nth node from the end of the linked list
struct ListNode* findNthFromEnd(struct ListNode* head, int n) {
    if (head == NULL || n <= 0) {
        return NULL;
    }

    struct ListNode* fast = head;
    struct ListNode* slow = head;

    // Move fast pointer n steps ahead
    for (int i = 0; i < n; i++) {
        if (fast == NULL) {
            return NULL; // The list has less than n nodes
        }
        fast = fast->next;
    }

    // Move both pointers together until fast pointer reaches the end
    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    // At this point, slow points to the nth node from the end
    return slow;
}

// Function to print the linked list
void printList(struct ListNode* head) {
    struct ListNode* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    // Creating a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    int n = 2; // Find the 2nd node from the end

    printf("Original List: ");
    printList(head);

    // Find the nth node from the end
    struct ListNode* nthFromEnd = findNthFromEnd(head, n);

    if (nthFromEnd != NULL) {
        printf("The %dth node from the end is: %d\n", n, nthFromEnd->val);
    } else {
        printf("The list has less than %d nodes\n", n);
    }

    // Clean up memory
    while (head != NULL) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
