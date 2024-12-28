#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

int stack[SIZE], top = -1;

void push(int element) {
    if (top == SIZE - 1) {
        printf("Stack overflow: unable to push %d\n", element);
    } else {
        top++;
        stack[top] = element;
        printf("%d pushed onto the stack\n", element);
    }
}

void pop() {
    if (top == -1) {
        printf("Stack underflow: no element to pop\n");
    } else {
        printf("%d popped from the stack\n", stack[top]);
        top--;
    }
}

void display() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, element;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &element);
                push(element);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice, please try again\n");
        }
    }
    return 0;
}
