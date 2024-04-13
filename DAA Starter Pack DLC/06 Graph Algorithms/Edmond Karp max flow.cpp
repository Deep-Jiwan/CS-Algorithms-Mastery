//Apply Edmond Karp Algorithm
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
#define INF INT_MAX

// Structure to represent a directed edge
struct Edge {
    int to, capacity, flow, rev; // rev is the index of the reverse edge
};
// Function to add an edge to the graph
void addEdge(vector<vector<Edge>>& graph, int u, int v, int capacity) {
    graph[u].push_back({v, capacity, 0, (int)graph[v].size()});
    graph[v].push_back({u, 0, 0, (int)graph[u].size() - 1});
}
// Function to find the maximum flow using Edmonds-Karp algorithm
int EdmondsmaxFlow(vector<vector<Edge>>& graph, int source, int sink) {
    int n = graph.size();
    vector<int> parent(n); // for stroring augmenting path
    int maxFlow = 0;

    while (true) {
        fill(parent.begin(), parent.end(), -1);
        queue<int> q;
        q.push(source);
        parent[source] = source;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (Edge& e : graph[u]) {
                int v = e.to;
                if (parent[v] == -1 && e.capacity > e.flow) {
                    parent[v] = u;
                    q.push(v);
                }
            }
        }
        // If no augmenting path found, break
        if (parent[sink] == -1) break;

        int pathFlow = INF;
        // find botttle neck capacity of the augmenting path
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            for (Edge& e : graph[u]) {
                if (e.to == v) {
                    pathFlow = min(pathFlow, e.capacity - e.flow);
                    break;
                }
            }
        }
        // update residual capacity of the edges and reverse edges
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            for (Edge& e : graph[u]) {
                if (e.to == v) {
                    e.flow += pathFlow;
                    graph[e.to][e.rev].flow -= pathFlow;
                    break;
                }
            }
        }
        // add path and total flow
        maxFlow += pathFlow;
    }
    return maxFlow;
}

int main() {
    int n, m;
    cout << "\nEnter the number of vertices: "; //6
    cin >> n;
    cout << "Enter the number of edges: "; //7
    cin >> m;

    cout << "\nEnter the edges in the form u -> v, w = cost as (u v w):\n";
    // Initialize graph with zero capacities
    vector<vector<Edge>> graph(n);

    // Input edges and capacities
    for (int i = 0; i < m; ++i) {
        int u, v, capacity;
        cin >> u >> v >> capacity;
        addEdge(graph, u, v, capacity);
    }
    cout << "\nEnter the source node and sink node as (source sink):\n"; 
    int source, sink;
    cin >> source >> sink;

    int maxRate = EdmondsmaxFlow(graph, source, sink);
    cout << "\nThe maximum possible flow (Edmond Karp method): "<< maxRate << endl;
    cout << "\n22BCE3789 - Deep Mukesh Jiwan 2024";
    return 0;
}
