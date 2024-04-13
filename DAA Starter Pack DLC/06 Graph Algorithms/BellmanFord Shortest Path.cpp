//Bellman Ford algorithm
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Edge {
    int source, destination, weight;
};

void bellmanFord(vector<Edge>& edges, int n, int m, int source) {
    vector<int> distance(n, INT_MAX);
    distance[source] = 0;

    // Relax all edges (n - 1) times
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m; ++j) {
            int u = edges[j].source;
            int v = edges[j].destination;
            int w = edges[j].weight;
            if (distance[u] != INT_MAX && distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
            }
        }
    }

    // Print distances
    cout << "\nVertex \tDistance from the Source: " << source <<"\n";
    for (int i = 0; i < n; ++i) {
        cout << i << "\t" << distance[i] << endl;
    }
}

int main() {
    int n, E;
    cout << "\nEnter the number of vertices: "; //5
    cin >> n;
    cout << "\nEnter the number of edges: "; //8
    cin >> E;

    cout << "\nEnter the edges in the form u -> v, w = weight as (u v w):\n";
    vector<Edge> edges(E);
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u, v, w};
    }

    int source;
    cout << "\nEnter the source/starting node: "; //0
    cin >> source;

    bellmanFord(edges, n, E, source);
    cout << "\n22BCE3789 - Deep Mukesh Jiwan 2024";
    return 0;
}
