#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

int isEmpty() {
    return (front == -1 || front > rear);
}

int isFull() {
    return (rear == MAX - 1);
}

void insert(int value) {
    if (isFull()) {
        printf("Queue Overflow\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        queue[++rear] = value;
        printf("Inserted %d into the queue\n", value);
    }
}

void delete() {
    if (isEmpty()) {
        printf("Queue Underflow\n");
    } else {
        printf("Deleted %d from the queue\n", queue[front]);
        front++;
        if (front > rear) {
            front = rear = -1;
        }
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
