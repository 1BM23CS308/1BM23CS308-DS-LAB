#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *top = NULL;

struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(int value) {
    struct Node *newNode = createNode(value);
    if (top == NULL) {
        top = newNode;
        return;
    }
    struct Node *ptr = top;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = newNode;
}

void deleteFromBeginning() {
    if (top == NULL) {
        printf("The list is empty. Nothing to delete.\n");
        return;
    }
    struct Node *temp = top;
    top = top->next;
    printf("Deleted %d from the beginning.\n", temp->data);
    free(temp);
}

void deleteFromEnd() {
    if (top == NULL) {
        printf("The list is empty. Nothing to delete.\n");
        return;
    }
    struct Node *ptr = top;
    if (ptr->next == NULL) {
        printf("Deleted %d from the end.\n", ptr->data);
        free(ptr);
        top = NULL;
        return;
    }
    while (ptr->next->next != NULL) {
        ptr = ptr->next;
    }
    struct Node *temp = ptr->next;
    printf("Deleted %d from the end.\n", temp->data);
    ptr->next = NULL;
    free(temp);
}

void deleteByValue(int value) {
    if (top == NULL) {
        printf("The list is empty. Nothing to delete.\n");
        return;
    }
    struct Node *ptr = top, *prev = NULL;
    if (ptr != NULL && ptr->data == value) {
        top = ptr->next;
        printf("Deleted %d from the list.\n", ptr->data);
        free(ptr);
        return;
    }
    while (ptr != NULL && ptr->data != value) {
        prev = ptr;
        ptr = ptr->next;
    }
    if (ptr == NULL) {
        printf("Value %d not found in the list.\n", value);
        return;
    }
    prev->next = ptr->next;
    printf("Deleted %d from the list.\n", ptr->data);
    free(ptr);
}

void displayList() {
    if (top == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node *ptr = top;
    printf("Linked list: ");
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, value;
    while (1) {
        printf("\nMenu:\n1. Insert at end\n2. Delete from beginning\n3. Delete from end\n4. Delete by value\n5. Display list\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter value to insert at end: ");
            scanf("%d", &value);
            insertAtEnd(value);
            break;
        case 2:
            deleteFromBeginning();
            break;
        case 3:
            deleteFromEnd();
            break;
        case 4:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            deleteByValue(value);
            break;
        case 5:
            displayList();
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
