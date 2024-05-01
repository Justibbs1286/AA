

#include <stdio.h>
#include <stdlib.h>

#define V 100 // Maximum number of vertices

// Function to perform Depth First Search traversal
void DFS(int graph[][V], int vertex, int visited[], int vertices) {
    // Mark the current vertex as visited
    visited[vertex] = 1;
    printf("%d ", vertex);

    // Recursive traversal for all the vertices adjacent to this vertex
    for (int i = 0; i < vertices; i++) {
        if (graph[vertex][i] && !visited[i]) {
            DFS(graph, i, visited, vertices);
        }
    }
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
    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &start_vertex);

    int visited[V] = {0}; // Array to keep track of visited vertices

    printf("DFS Traversal starting from vertex %d: ", start_vertex);
    DFS(graph, start_vertex, visited, vertices);

    return 0;
}
