#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

// Graph representation using adjacency list
class Graph {
public:
    // Each city has a vector of pairs, where each pair contains a neighboring city and the cost (time or fuel).
    unordered_map<string, vector<pair<string, int>>> adjList;

    void addFlight(string u, string v, int cost) {
        adjList[u].push_back({v, cost});
        adjList[v].push_back({u, cost});  // Assuming undirected graph (bidirectional flights)
    }

    bool isConnected() {
        if (adjList.empty()) return true;

        unordered_map<string, bool> visited;
        string start = adjList.begin()->first;

        // Perform BFS starting from an arbitrary city
        queue<string> q;
        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            string city = q.front();
            q.pop();

            for (auto neighbor : adjList[city]) {
                string nextCity = neighbor.first;
                if (!visited[nextCity]) {
                    visited[nextCity] = true;
                    q.push(nextCity);
                }
            }
        }

        for (auto city : adjList) {
            if (!visited[city.first]) return false;
        }
        return true;
    }

    void display() {
        for (auto city : adjList) {
            cout << city.first << ": ";
            for (auto flight : city.second) {
                cout << "(" << flight.first << ", " << flight.second << ") ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g;

    g.addFlight("Mumbai", "Pune", 300);
    g.addFlight("Mumbai", "Chicago", 150);
    g.addFlight("Chicago", "Denver", 200);
    g.addFlight("Denver", "Pune", 180);
    g.addFlight("Chicago", "Miami", 250);

    cout << "Adjacency List Representation of the Graph:" << endl;
    g.display();

    if (g.isConnected()) {
        cout << "The flight network is connected." << endl;
    } else {
        cout << "The flight network is not connected." << endl;
    }

    return 0;
}
