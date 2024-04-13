// Ford Fulkerson
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

#define INF INT_MAX

// Structure to represent a directed edge
struct Edge {
    int u, v, capacity;
};

// Function to add an edge to the graph
void addEdge(vector<vector<int>>& graph, int u, int v, int capacity) {
    graph[u][v] = capacity;
}

// Function to find the maximum flow using Ford-Fulkerson algorithm
int fordFulkerson(vector<vector<int>>& graph, int source, int sink) {
    int n = graph.size();
    vector<vector<int>> residualGraph(graph); // Residual graph
    vector<int> parent(n); // Store parent of each node in augmented path
    int maxFlow = 0; // Initialize max flow

    // Find augmenting paths and update residual graph
    while (true) {
        fill(parent.begin(), parent.end(), -1);
        queue<int> q;
        q.push(source);
        parent[source] = source;

        while (!q.empty() && parent[sink] == -1) {
            int u = q.front();
            q.pop();
            for (int v = 0; v < n; ++v) {
                if (parent[v] == -1 && residualGraph[u][v] > 0) {
                    parent[v] = u;
                    q.push(v);
                }
            }
        }

        // If no augmenting path found, break
        if (parent[sink] == -1) break;

        int pathFlow = INF;
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            pathFlow = min(pathFlow, residualGraph[u][v]);
        }

        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            residualGraph[u][v] -= pathFlow;
            residualGraph[v][u] += pathFlow;
        }

        maxFlow += pathFlow;
    }

    return maxFlow;
}

int main() {
    int n, m;
    cout << "\nEnter the number of vertices: "; //6
    cin >> n;
    cout << "\nEnter the number of edges: "; //10
    cin >> m;

    cout << "\nEnter the edges in the form u -> v, w = cost as (u v w):\n";
    // Initialize graph with zero capacities
    vector<vector<int>> graph(n, vector<int>(n, 0));

    // Input edges and capacities
    for (int i = 0; i < m; ++i) {
        int u, v, capacity;
        cin >> u >> v >> capacity;
        addEdge(graph, u, v, capacity);
    }
    cout << "\nEnter the source node and sink node as (source sink):\n";
    int source, sink;
    cin >> source >> sink;

    int maxFlow = fordFulkerson(graph, source, sink);
    cout << "\nThe maximum possible flow: "<< maxFlow << endl;
    cout << "\n22BCE3789 - Deep Mukesh Jiwan 2024";
    return 0;
}
/*
    graph=
           0  1   2    3   4   5 
    {   0{ 0, 16, 13,  0,  0,  0  }, 
        1{ 0, 0,  10,  12, 0,  0  },
        2{ 0, 4,  0,   0,  14, 0  },  
        3{ 0, 0,  9,   0,  0,  20 },
        4{ 0, 0,  0,   7,  0,  4  },   
        5{ 0, 0,  0,   0,  0,  0  } 
};*/

