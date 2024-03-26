#include <stdio.h>
#include <stdlib.h>

// Definition for a linked list node
struct Node {
    int val;
    struct Node *next;
};

// Function to merge two sorted linked lists
struct Node* mergeTwoLists(struct Node* l1, struct Node* l2) {
    struct Node dummy;
    struct Node* tail = &dummy;
    
    while (l1 && l2) {
        if (l1->val <= l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    
    tail->next = (l1 != NULL) ? l1 : l2;
    
    return dummy.next;
}

// Function to merge k sorted linked lists
struct Node* mergeKLists(struct Node** lists, int k) {
    if (k == 0) return NULL;
    
    // Perform pairwise merging until only one list remains
    while (k > 1) {
        for (int i = 0; i < k / 2; ++i) {
            lists[i] = mergeTwoLists(lists[i], lists[k - i - 1]);
        }
        k = (k + 1) / 2; // Update the number of lists after merging
    }
    
    return lists[0];
}

// Function to print a linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

// Function to create a new node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

int main() {
    // Example usage
    struct Node* list1 = createNode(1);
    list1->next = createNode(4);
    list1->next->next = createNode(5);

    struct Node* list2 = createNode(1);
    list2->next = createNode(3);
    list2->next->next = createNode(4);

    struct Node* list3 = createNode(2);
    list3->next = createNode(6);

    struct Node* lists[3] = {list1, list2, list3};

    struct Node* mergedList = mergeKLists(lists, 3);
    printList(mergedList);

    // Free memory
    for (int i = 0; i < 3; ++i) {
        struct Node* temp;
        while (lists[i] != NULL) {
            temp = lists[i];
            lists[i] = lists[i]->next;
            free(temp);
        }
    }

    return 0;
}
