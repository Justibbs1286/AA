#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;

    // Constructor
    Edge(int src, int dest, int weight) : src(src), dest(dest), weight(weight) {}

    // Comparison function for sorting edges by weight
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

class Graph {
private:
    int V, E;
    vector<Edge> edges;

public:
    // Constructor
    Graph(int v, int e) : V(v), E(e) {}

    // Function to add an edge to the graph
    void addEdge(int src, int dest, int weight) {
        edges.emplace_back(src, dest, weight);
    }

    // Function to find the subset of an element i
    int find(vector<int>& parent, int i) {
        if (parent[i] != i)
            parent[i] = find(parent, parent[i]);
        return parent[i];
    }

    // Function to perform union of two subsets
    void Union(vector<int>& parent, vector<int>& rank, int x, int y) {
        int xroot = find(parent, x);
        int yroot = find(parent, y);

        if (rank[xroot] < rank[yroot])
            parent[xroot] = yroot;
        else if (rank[xroot] > rank[yroot])
            parent[yroot] = xroot;
        else {
            parent[yroot] = xroot;
            rank[xroot]++;
        }
    }

    // Function to find the minimum spanning tree using Kruskal's algorithm
    void kruskalMST() {
        vector<Edge> result;
        vector<int> parent(V);
        vector<int> rank(V, 0);

        // Initialize parent array
        for (int i = 0; i < V; i++)
            parent[i] = i;

        // Sort all edges in non-decreasing order of their weight
        sort(edges.begin(), edges.end());

        int e = 0; // Index variable for result[]
        int i = 0; // Index variable for sorted edges[]
        while (e < V - 1 && i < edges.size()) {
            Edge nextEdge = edges[i++];

            int x = find(parent, nextEdge.src);
            int y = find(parent, nextEdge.dest);

            if (x != y) {
                result.push_back(nextEdge);
                Union(parent, rank, x, y);
                e++;
            }
        }

        // Print the minimum spanning tree
        cout << "Edges in the Minimum Spanning Tree:\n";
        for (const auto& edge : result) {
            cout << edge.src << " -- " << edge.dest << "   Weight: " << edge.weight << "\n";
        }
    }
};

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;

    cout << "Enter the number of edges: ";
    cin >> E;

    Graph graph(V, E);

    cout << "Enter the source, destination, and weight of each edge:\n";
    for (int i = 0; i < E; i++) {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        graph.addEdge(src, dest, weight);
    }

    graph.kruskalMST();

    return 0;
}
