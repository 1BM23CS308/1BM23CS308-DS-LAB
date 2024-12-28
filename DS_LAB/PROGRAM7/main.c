#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;
struct Node* front = NULL;
struct Node* rear = NULL;

struct Node* createNode(int value) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = value;
    ptr->next = NULL;
    return ptr;
}

void push(int value) {
    struct Node* ptr = createNode(value);
    ptr->next = top;
    top = ptr;
    printf("Pushed %d to stack\n", value);
}

void pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return;
    }
    struct Node* ptr = top;
    printf("Popped %d from stack\n", top->data);
    top = top->next;
    free(ptr);
}

void enqueue(int value) {
    struct Node* ptr = createNode(value);
    if (rear == NULL) {
        front = rear = ptr;
    } else {
        rear->next = ptr;
        rear = ptr;
    }
    printf("Enqueued %d to queue\n", value);
}

void dequeue() {
    if (front == NULL) {
        printf("Queue Underflow\n");
        return;
    }
    struct Node* ptr = front;
    printf("Dequeued %d from queue\n", front->data);
    front = front->next;
    if (front == NULL) {
        rear = NULL;
    }
    free(ptr);
}

void displayStack() {
    struct Node* ptr = top;
    if (ptr == NULL) {
        printf("Stack is Empty\n");
        return;
    }
    printf("Stack: ");
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

void displayQueue() {
    struct Node* ptr = front;
    if (ptr == NULL) {
        printf("Queue is Empty\n");
        return;
    }
    printf("Queue: ");
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

int main() {
    push(10);
    push(20);
    push(30);
    displayStack();
    pop();
    displayStack();
    enqueue(40);
    enqueue(50);
    enqueue(60);
    displayQueue();
    dequeue();
    displayQueue();
    return 0;
}
