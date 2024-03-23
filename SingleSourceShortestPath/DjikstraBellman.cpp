#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
#define INF INT_MAX
class Graph {
private:
    int V;
    vector<vector<int>> adj;

public:
    Graph(int V) : V(V) {
        adj.resize(V, vector<int>(V, INF));
    }

    void addEdge(int src, int dest, int weight) {
        adj[src][dest] = weight;
    }

    vector<int> dijkstra(int source) {
        vector<int> dist(V, INF);
        dist[source] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, source});

        while (!pq.empty()) {
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();

            if (d > dist[u]) continue;

            for (int v = 0; v < V; ++v) {
                if (adj[u][v] != INF) {
                    int w = adj[u][v];
                    if (dist[u] + w < dist[v]) {
                        dist[v] = dist[u] + w;
                        pq.push({dist[v], v});
                    }
                }
            }
        }
        return dist;
    }

    vector<int> bellmanFord(int source) {
        vector<int> dist(V, INF);
        dist[source] = 0;

        for (int i = 0; i < V - 1; ++i) {
            for (int u = 0; u < V; ++u) {
                for (int v = 0; v < V; ++v) {
                    if (adj[u][v] != INF) {
                        int w = adj[u][v];
                        if (dist[u] != INF && dist[u] + w < dist[v]) {
                            dist[v] = dist[u] + w;
                        }
                    }
                }
            }
        }
        for (int u = 0; u < V; ++u) {
            for (int v = 0; v < V; ++v) {
                if (adj[u][v] != INF) {
                    int w = adj[u][v];
                    if (dist[u] != INF && dist[u] + w < dist[v]) {
                        cout << "Graph contains negative-weight cycle\n";
                        return {};
                    }
                }
            }
        }
        return dist;
    }
};

int main() {
    Graph gDijkstra(5);
    gDijkstra.addEdge(0, 1, 4);
    gDijkstra.addEdge(0, 2, 1);
    gDijkstra.addEdge(1, 2, 2);
    gDijkstra.addEdge(1, 3, 5);
    gDijkstra.addEdge(2, 3, 2);
    gDijkstra.addEdge(2, 4, 1);
    gDijkstra.addEdge(3, 4, 3);

    Graph gBellmanFord(5);
    gBellmanFord.addEdge(0, 1, -4);
    gBellmanFord.addEdge(0, 2, 1);
    gBellmanFord.addEdge(1, 2, -2);
    gBellmanFord.addEdge(1, 3, -5);
    gBellmanFord.addEdge(2, 3, 2);
    gBellmanFord.addEdge(2, 4, -1);
    gBellmanFord.addEdge(3, 4, 3);

    int src = 0;

    vector<int> dijkstraDistances = gDijkstra.dijkstra(src);
    cout << "Starting vertex " << src << ", Dijkstra's:\n";
    for (int i = 0; i < dijkstraDistances.size(); ++i)
        cout << "Vertex " << i << ": " << dijkstraDistances[i] << "\n";

    vector<int> bellmanFordDistances = gBellmanFord.bellmanFord(src);
    if (!bellmanFordDistances.empty()) {
        cout << "\nStarting vertex " << src << ", Bellman-Ford:\n";
        for (int i = 0; i < bellmanFordDistances.size(); ++i)
            cout << "Vertex " << i << ": " << bellmanFordDistances[i] << "\n";
    }

    return 0;
}
