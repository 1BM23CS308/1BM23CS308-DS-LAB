#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

void insertLeft(struct Node** head, struct Node* targetNode, int data) {
    if (targetNode == NULL) {
        printf("Target node is NULL. Insertion failed.\n");
        return;
    }
    struct Node* newNode = createNode(data);
    newNode->next = targetNode;
    newNode->prev = targetNode->prev;
    if (targetNode->prev != NULL) {
        targetNode->prev->next = newNode;
    } else {
        *head = newNode;
    }
    targetNode->prev = newNode;
}

void deleteNode(struct Node** head, int value) {
    struct Node* temp = *head;
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node with value %d not found.\n", value);
        return;
    }
    if (*head == temp) {
        *head = temp->next;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    free(temp);
    printf("Node with value %d deleted.\n", value);
}

void displayList(struct Node* head) {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("The list is empty.\n");
        return;
    }
    printf("List contents: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    head = createNode(10);
    struct Node* second = createNode(20);
    struct Node* third = createNode(30);

    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;

    printf("Initial list:\n");
    displayList(head);

    insertLeft(&head, second, 15);
    printf("\nList after inserting 15 to the left of 20:\n");
    displayList(head);

    deleteNode(&head, 20);
    printf("\nList after deleting node with value 20:\n");
    displayList(head);

    deleteNode(&head, 100);
    printf("\nList after attempting to delete node with value 100:\n");
    displayList(head);

    return 0;
}
