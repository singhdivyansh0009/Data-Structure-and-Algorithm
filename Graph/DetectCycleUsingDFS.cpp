#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// DFS function to detect cycle in an undirected graph
// 'node' is the current node, 'parent' is the node we came from
bool dfs(int node, int parent, vector<int> graph[], vector<bool>& visited) {
    visited[node] = true; // Mark the current node as visited

    // Traverse all adjacent (neighboring) nodes
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            // Recur for unvisited neighbor
            if (dfs(neighbor, node, graph, visited))
                return true; // Cycle found in recursion
        } else if (neighbor != parent) {
            // If neighbor is visited and not the parent, a cycle exists
            return true;
        }
    }

    return false; // No cycle found from this path
}

// Function to detect cycle in an undirected graph
// Handles disconnected components by checking all nodes
bool isCycleDetected(vector<int> graph[]) {
    vector<bool> visited(8, false); // Visited array (1-based indexing, size = 8)

    // Check each node (1 to 7), to handle disconnected components
    for (int i = 1; i <= 7; i++) {
        if (!visited[i]) {
            // Call DFS for unvisited node, with parent set as -1
            if (dfs(i, -1, graph, visited))
                return true; // Cycle found
        }
    }

    return false; // No cycle found in any component
}

// Function to build adjacency list from edge list
void generateAdjList(vector<int> graph[], int edges[][2], int n) {
    for (int i = 0; i < n; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        graph[u].push_back(v); // Add edge u -> v
        graph[v].push_back(u); // Add edge v -> u (undirected)
    }
}

// Function to print the adjacency list representation of the graph
void printGraph(vector<int> graph[], int n) {
    for (int i = 1; i < n; i++) {
        cout << i << " -> ";
        for (int j : graph[i])
            cout << j << " ";
        cout << endl;
    }
}

int main() {
    // Edge list of an undirected graph
    int edges[7][2] = {
        {1, 2},
        {1, 3},
        {2, 5},
        {5, 7},
        {3, 6},
        {6, 7},
        {4, 3}  // This ensures one disconnected node (4) is connected to the main graph
    };

    vector<int> graph[8];              // Graph with 1-based indexing (1 to 7)
    vector<bool> visited(8, false);    // Visited array

    // Generate the graph from edges
    generateAdjList(graph, edges, 7);

    // Print the adjacency list of the graph
    printGraph(graph, 8);

    // Check if the graph contains a cycle
    if (isCycleDetected(graph))
        cout << "Cycle detected";
    else
        cout << "Cycle not detected";

    return 0;
}
