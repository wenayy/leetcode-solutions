class Solution {
public:
 

// Function to perform BFS and return the set of nodes in the connected component
unordered_set<int> bfs(int startNode, vector<vector<int>>& adjList, vector<bool>& visited) {
    queue<int> q;
    q.push(startNode);
    visited[startNode] = true;
    unordered_set<int> component;

    while (!q.empty()) {
        int currentNode = q.front();
        q.pop();
        component.insert(currentNode);

        // Traverse all neighbors of the current node
        for (int neighbor : adjList[currentNode]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    return component;
}

// Function to count the number of complete connected components
int countCompleteComponents(int n, vector<vector<int>>& edges) {
    // Step 1: Build the adjacency list
    vector<vector<int>> adjList(n);
    for (auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adjList[u].push_back(v);
        adjList[v].push_back(u); // Since the graph is undirected
    }

    // Step 2: Initialize visited array
    vector<bool> visited(n, false);

    // Step 3: Count complete connected components
    int completeComponents = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            // Find the connected component using BFS
            unordered_set<int> component = bfs(i, adjList, visited);

            // Step 4: Check if the component is complete
            int k = component.size(); // Number of vertices in the component
            int edgeCount = 0; // Number of edges in the component

            // Count the number of edges in the component
            for (int u : component) {
                for (int v : adjList[u]) {
                    if (component.count(v)) {
                        edgeCount++;
                    }
                }
            }

            // Since each edge is counted twice (u->v and v->u), divide by 2
            edgeCount /= 2;

            // Check if the component is complete
            if (edgeCount == k * (k - 1) / 2) {
                completeComponents++;
            }
        }
    }

    return completeComponents;
}

 
};