#include <stdio.h>
#include <stdlib.h>

// Structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
};

// Structure to represent a subset for union-find
struct Subset {
    int parent;
    int rank;
};

// Function to create a graph with V vertices and E edges
struct Edge* createGraph(int V, int E) {
    struct Edge* graph = (struct Edge*)malloc(E * sizeof(struct Edge));
    return graph;
}

// Function to find the subset of an element i
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Function to perform union of two subsets
void Union(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Comparison function to sort edges by weight
int compareEdges(const void* a, const void* b) {
    struct Edge* edge1 = (struct Edge*)a;
    struct Edge* edge2 = (struct Edge*)b;
    return edge1->weight - edge2->weight;
}

// Function to find the minimum spanning tree using Kruskal's algorithm
void KruskalMST(struct Edge* graph, int V, int E) {
    // Allocate memory for the result
    struct Edge* result = (struct Edge*)malloc((V - 1) * sizeof(struct Edge));

    // Sort all the edges in the graph in non-decreasing order of their weight
    qsort(graph, E, sizeof(graph[0]), compareEdges);

    // Allocate memory for creating V subsets
    struct Subset* subsets = (struct Subset*)malloc(V * sizeof(struct Subset));

    // Initialize subsets with single elements
    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Index variable used for result[]
    int e = 0;

    // Index variable used for sorted edges[]
    int i = 0;
    while (e < V - 1 && i < E) {
        struct Edge nextEdge = graph[i++];

        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);

        if (x != y) {
            result[e++] = nextEdge;
            Union(subsets, x, y);
        }
    }

    // Print the minimum spanning tree
    printf("Edges in the Minimum Spanning Tree:\n");
    for (int i = 0; i < e; ++i)
        printf("%d -- %d   Weight: %d\n", result[i].src, result[i].dest, result[i].weight);

    free(result);
    free(subsets);
}

int main() {
    int V, E;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    printf("Enter the number of edges: ");
    scanf("%d", &E);

    struct Edge* graph = createGraph(V, E);

    printf("Enter the source, destination, and weight of each edge:\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &graph[i].src, &graph[i].dest, &graph[i].weight);
    }

    KruskalMST(graph, V, E);

    free(graph);

    return 0;
}