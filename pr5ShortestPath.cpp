#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Pair to store (node, weight)
typedef pair<int, int> Edge;

class Graph {
public:
    int vertices;  // Number of vertices
    vector<vector<Edge>> adjList;  // Adjacency list

    // Constructor
    Graph(int vertices){
        this->vertices = vertices;
        adjList.resize(vertices);
    }

    // Add edge to the graph
    void addEdge(int src, int dest, int weight) {
        adjList[src].push_back({dest, weight});
        adjList[dest].push_back({src, weight});  // For undirected graph
    }

    // Dijkstra's algorithm to find the shortest path
    void shortestPath(int source, int destination) {
        vector<int> dist(vertices, INT_MAX);  // Distance array
        vector<int> parent(vertices, -1);    // To store the path
        priority_queue<Edge, vector<Edge>, greater<Edge>> pq;  // Min-heap

        dist[source] = 0;
        pq.push({0, source});  // (distance, node)

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            // Process neighbors
            for (const Edge& neighbor : adjList[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                // Relaxation step
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    parent[v] = u;
                    pq.push({dist[v], v});
                }
            }
        }

        // Print result
        if (dist[destination] == INT_MAX) {
            cout << "No path exists from " << source << " to " << destination << endl;
        } else {
            cout << "Shortest distance from " << source << " to " << destination << ": " 
                 << dist[destination] << endl;
            printPath(source, destination, parent);
        }
    }

    // Helper function to print the path
    void printPath(int source, int destination, const vector<int>& parent) {
        if (destination == -1) {
            cout << "No path exists.";
            return;
        }
        if (destination == source) {
            cout << source;
            return;
        }
        printPath(source, parent[destination], parent);
        cout << " -> " << destination;
    }
};

int main() {
    int vertices, edges;
    cout << "Enter number of vertices: ";
    cin >> vertices;

    Graph g(vertices);

    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter edges (src dest weight):\n";
    for (int i = 0; i < edges; i++) {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        g.addEdge(src, dest, weight);
    }

    int source, destination;
    cout << "Enter source vertex: ";
    cin >> source;
    cout << "Enter destination vertex: ";
    cin >> destination;

    g.shortestPath(source, destination);

    return 0;
}
