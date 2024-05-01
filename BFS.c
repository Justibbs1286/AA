
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define V 100 // Maximum number of vertices

// Queue data structure for BFS traversal
struct Queue {
    int items[V];
    int front;
    int rear;
};

// Function to create a queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// Function to check if the queue is empty
bool isEmpty(struct Queue* queue) {
    return queue->rear == -1;
}

// Function to add an item to the queue
void enqueue(struct Queue* queue, int value) {
    if (queue->rear == V - 1)
        printf("Queue is full\n");
    else {
        if (queue->front == -1)
            queue->front = 0;
        queue->rear++;
        queue->items[queue->rear] = value;
    }
}

// Function to remove an item from the queue
int dequeue(struct Queue* queue) {
    int item;
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        item = -1;
    } else {
        item = queue->items[queue->front];
        queue->front++;
        if (queue->front > queue->rear) {
            queue->front = queue->rear = -1;
        }
    }
    return item;
}

// Function to perform Breadth First Search traversal
void BFS(int graph[][V], int start_vertex, int visited[], int vertices) {
    struct Queue* queue = createQueue();

    visited[start_vertex] = 1;
    enqueue(queue, start_vertex);

    printf("BFS Traversal starting from vertex %d: ", start_vertex);

    while (!isEmpty(queue)) {
        int current_vertex = dequeue(queue);
        printf("%d ", current_vertex);

        for (int i = 0; i < vertices; ++i) {
            if (graph[current_vertex][i] && !visited[i]) {
                visited[i] = 1;
                enqueue(queue, i);
            }
        }
    }

    free(queue);
}

int main() {
    int vertices;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    int graph[V][V] = {0}; // Adjacency matrix to represent the graph

    printf("Enter the adjacency matrix (1 for connected, 0 for not connected):\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int start_vertex;
    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &start_vertex);

    int visited[V] = {0}; // Array to keep track of visited vertices

    BFS(graph, start_vertex, visited, vertices);

    return 0;
}
