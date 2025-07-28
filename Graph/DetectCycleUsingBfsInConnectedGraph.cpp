#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to detect cycle in an undirected graph using BFS
bool isCycleDetected(vector<int> graph[]) {
    vector<bool> visited(8, false);     // Tracks visited nodes (1-based indexing, size = 8)
    queue<int> q;                       // Queue for BFS traversal
    vector<int> parent(8, -1);          // Tracks parent of each node to detect back edges

    q.push(1);                          // Start BFS from node 1 (assumes graph is connected)

    while (!q.empty()) {
        int src = q.front();            // Get the current node
        visited[src] = true;            // Mark it as visited

        // Explore all connected neighbors
        for (int connectedNode : graph[src]) {
            // If the neighbor is visited and not the parent of current node => cycle detected
            if (visited[connectedNode] && parent[src] != connectedNode)
                return true;

            // If not visited, mark and push it into the queue
            if (!visited[connectedNode])
                q.push(connectedNode);

            // Set the parent of the neighbor to current node
            parent[connectedNode] = src;
        }

        q.pop(); // Remove the current node from queue
    }

    return false; // No cycle found
}

// Function to create adjacency list from the given edge list
void generateAdjList(vector<int> graph[], int edges[][2], int n) {
    for (int i = 0; i < n; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        graph[u].push_back(v); // Add edge u -> v
        graph[v].push_back(u); // Since undirected, also add v -> u
    }
}

// Function to print the adjacency list of the graph
void printGraph(vector<int> graph[], int n) {
    for (int i = 1; i < n; i++) {
        cout << i << "->";
        for (int j : graph[i])
            cout << j << " ";
        cout << endl;
    }
}

int main() {
    // Edge list of the graph (undirected)
    int edges[6][2] = {
        {1, 2},
        {1, 3},
        {2, 5},
        {3, 6},
        {6, 7},
        {4, 3}  // This edge connects node 4 to node 3 (graph may be disconnected)
    };

    vector<int> graph[8]; // Adjacency list (1-based indexing: nodes 1 to 7)

    generateAdjList(graph, edges, 6);  // Build graph from edges
    printGraph(graph, 8);              // Print the graph

    // Check for cycle
    if (isCycleDetected(graph))
        cout << "Cycle detected";
    else
        cout << "Cycle not detected";

    return 0;
}
