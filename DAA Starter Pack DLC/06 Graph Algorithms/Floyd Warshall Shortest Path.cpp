//Floyd Warshall algorithm

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void floydWarshall(vector<vector<int>>& graph, int n) {
    vector<vector<int>> dist(graph); // Copy the graph to store the distances

    // Apply Floyd Warshall algorithm
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && 
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the shortest distances
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dist[i][j] == INT_MAX) {
                cout << "INF\t";
            } else {
                cout << dist[i][j] << "\t";
            }
        }
        cout << endl;
    }
}

int main() {
    /* Input graph
    vertices : 4 edges : 6
     vector<vector<int>> graph = {
          0   1  2   3  
       0 {0, 3, INF, 5},
       1 {2, 0, INF, 4},
       2 {INF, 1, 0, INF},
       3 {INF, INF, 2, 0}
    };*/

    int n, E;
    cout << "Enter the number of Vertices: ";
    cin >> n;
    cout << "Enter the number of Edges: ";
    cin >> E;
    cout << "Enter the edges in the form u -> v, w = weight as (u v w):\n";

    vector<vector<int>> graph(n, vector<int>(n, INT_MAX));

    // Input the graph
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
    }
    // Set distance from a node to itself as 0
    for (int i = 0; i < n; ++i) {
        graph[i][i] = 0;
    
    }
    cout << "\n\nThe Shortest distance between all the vertices is: \n";
    floydWarshall(graph, n);
    cout << "\n22BCE3789 - Deep Mukesh Jiwan 2024";
    return 0;
}

/*
    Graph:
             5
       (0)------->(3)
       /|\   /|\   /|\
    2/3 |   /4     |
        |  /       | 2
       \|/         |
       (1)------->(2)
            1         
*/
