#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Structure to represent a graph edge (node, weight)
typedef pair<int, int> Edge;

class Graph {
public:
    int V;  // Number of vertices
    vector<vector<Edge>> adjList;  // Adjacency list to store graph

    // Constructor to initialize the graph with V vertices
    Graph(int V) {
        this->V = V;
        adjList.resize(V);
    }

    // Function to add an edge to the graph
    void addEdge(int u, int v, int weight) {
        adjList[u].push_back({v, weight});
        adjList[v].push_back({u, weight});
        cout << "Edge added: " << u << " --(" << weight << ")--> " << v << endl;
    }

    // Function to display the adjacency list of the graph
    void displayGraph() {
        cout << "\nGraph Adjacency List:" << endl;
        for (int i = 0; i < V; i++) {
            cout << "Node " << i << ": ";
            for (auto neighbor : adjList[i]) {
                cout << "(" << neighbor.first << ", " << neighbor.second << ") ";
            }
            cout << endl;
        }
    }

    // Function to implement Prim's algorithm and return the MST's total weight
    int primMST() {
        priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
        vector<bool> inMST(V, false);
        pq.push({0, 0});  // Start from node 0
        int totalWeight = 0;
        vector<int> parent(V, -1);

        while (!pq.empty()) {
            int weight = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (inMST[u]) continue;
            inMST[u] = true;
            totalWeight += weight;

            for (auto neighbor : adjList[u]) {
                int v = neighbor.first;
                int edgeWeight = neighbor.second;

                if (!inMST[v]) {
                    pq.push({edgeWeight, v});
                    parent[v] = u;
                }
            }
        }

        cout << "Edges in the MST:" << endl;
        for (int i = 1; i < V; i++) {
            if (parent[i] != -1) {
                cout << parent[i] << " -- " << i << endl;
            }
        }

        return totalWeight;
    }
};

int main() {
    int V, choice;
    cout << "Enter the number of vertices in the graph: ";
    cin >> V;

    Graph g(V);

    do {
        cout << "\nMenu:\n";
        cout << "1. Add Edge\n";
        cout << "2. Display Graph\n";
        cout << "3. Find Minimum Spanning Tree (Prim's Algorithm)\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int u, v, weight;
            cout << "Enter edge (start node, end node, weight): ";
            cin >> u >> v >> weight;
            g.addEdge(u, v, weight);
            break;
        }
        case 2:
            g.displayGraph();
            break;
        case 3: {
            int totalWeight = g.primMST();
            cout << "Total weight of the Minimum Spanning Tree: " << totalWeight << endl;
            break;
        }
        case 4:
            cout << "Exiting program. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
