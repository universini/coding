#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode dummy;
    struct ListNode* prev = &dummy;
    prev->next = head;

    while (prev->next && prev->next->next) {
        struct ListNode* node1 = prev->next;
        struct ListNode* node2 = node1->next;
        struct ListNode* next = node2->next;

        node2->next = node1;
        node1->next = next;
        prev->next = node2;

        prev = node1;
    }

    return dummy.next;
}

void swapValue(int *v1, int *v2)
{
    int temp;

    temp = *v1;
    *v1 = *v2;
    *v2 = temp;
}

void swapPairs2(struct ListNode *head)
{
    struct ListNode *temp = head;

    while(temp && temp->next)
    {
        swapValue(&temp->val, &temp->next->val);
        temp = temp->next->next;
    }
}

int main() {
    // Example usage
    struct ListNode* head = malloc(sizeof(struct ListNode));
    head->val = 1;
    head->next = malloc(sizeof(struct ListNode));
    head->next->val = 2;
    head->next->next = malloc(sizeof(struct ListNode));
    head->next->next->val = 3;
    head->next->next->next = malloc(sizeof(struct ListNode));
    head->next->next->next->val = 4;
    head->next->next->next->next = NULL;

    printf("Before swapping:\n");
    struct ListNode* node = head;
    while (node) {
        printf("%d ", node->val);
        node = node->next;
    }
    printf("\n");

    swapPairs2(head);

    printf("After swapping:\n");
    node = head;
    while (node) {
        printf("%d ", node->val);
        node = node->next;
    }
    printf("\n");

    struct ListNode* new_head = swapPairs(head);

    printf("After swapping:\n");
    node = new_head;
    while (node) {
        printf("%d ", node->val);
        node = node->next;
    }
    printf("\n");

    return 0;
}
