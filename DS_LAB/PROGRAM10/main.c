#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100

struct Queue {
    int items[MAX];
    int front;
    int rear;
};

void initQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(struct Queue* q) {
    return q->front == -1;
}

void enqueue(struct Queue* q, int value) {
    if (q->rear == MAX - 1) {
        printf("Queue is full\n");
        return;
    }
    if (q->front == -1) q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
}

int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    int value = q->items[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return value;
}

void BFS(int graph[MAX][MAX], int start, int n) {
    bool visited[MAX] = {false};
    struct Queue q;
    initQueue(&q);
    enqueue(&q, start);
    visited[start] = true;

    while (!isEmpty(&q)) {
        int node = dequeue(&q);
        printf("%d ", node);
        for (int i = 0; i < n; i++) {
            if (graph[node][i] == 1 && !visited[i]) {
                enqueue(&q, i);
                visited[i] = true;
            }
        }
    }
}

void DFS(int graph[MAX][MAX], int node, bool visited[MAX], int n) {
    visited[node] = true;
    printf("%d ", node);
    for (int i = 0; i < n; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            DFS(graph, i, visited, n);
        }
    }
}

int main() {
    int n = 6;
    int graph[MAX][MAX] = {
        {0, 1, 1, 0, 0, 0},
        {1, 0, 1, 1, 0, 0},
        {1, 1, 0, 1, 0, 0},
        {0, 1, 1, 0, 1, 1},
        {0, 0, 0, 1, 0, 1},
        {0, 0, 0, 1, 1, 0}
    };

    printf("BFS starting from node 0: ");
    BFS(graph, 0, n);
    printf("\n");

    bool visited[MAX] = {false};
    printf("DFS starting from node 0: ");
    DFS(graph, 0, visited, n);
    printf("\n");

    return 0;
}
