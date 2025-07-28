
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool bfs(int start, vector<int> graph[], vector<bool>& visited) {
    queue<int> q;
    vector<int> parent(8, -1);
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int src = q.front();
        q.pop();

        for (int connectedNode : graph[src]) {
            if (visited[connectedNode] && parent[src] != connectedNode)
                return true;
            if (!visited[connectedNode]) {
                visited[connectedNode] = true;
                parent[connectedNode] = src;
                q.push(connectedNode);
            }
        }
    }
    return false;
}

bool isCycleDetected(vector<int> graph[]) {
    vector<bool> visited(8, false); // 1-based indexing

    // Loop over all nodes to handle disconnected components
    for (int i = 1; i <= 7; i++) {
        // If the node is not visited yet, perform BFS from it
        // This ensures even disconnected components are covered
        if (!visited[i]) {
            if (bfs(i, graph, visited))  // Call BFS for each unvisited component
                return true;             // If any component has a cycle, return true
        }
    }
    return false; // No cycle found in any component
}


void generateAdjList(vector<int>graph[], int edges[][2], int n){
    for(int i = 0; i < n; i++){
       int u = edges[i][0];
       int v = edges[i][1];
       graph[u].push_back(v);
       graph[v].push_back(u);
    }
}
void printGraph(vector<int>graph[],int n){
    for(int i = 1; i < n; i++){
        cout << i << "->";
        for(int j : graph[i])
            cout << j << " ";
        cout << endl;
    }
}
int main() {
    int edges[6][2]={{1,2},{1,3},{2,5},{3,6},{6,7},{4,3}};
    vector<int> graph[8];
    vector<bool>visited(8,false);
    
    // generate adjacency List
    generateAdjList(graph,edges,6);
    printGraph(graph,8);

    if(isCycleDetected(graph))
      cout << "Cycle detected";
    else 
      cout << "Cycle not detected";
    return 0;
}
