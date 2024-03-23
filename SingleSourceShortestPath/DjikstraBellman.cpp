#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

#define INF INT_MAX

struct Vertex {
    int id;
    int weight;
    Vertex(int _id, int _weight) : id(_id), weight(_weight) {}
};

struct Edge {
    int src, dest, weight;
    Edge(int _src, int _dest, int _weight) : src(_src), dest(_dest), weight(_weight) {}
};

class Graph {
private:
    int V;
    vector<Edge> edges;

public:
    Graph(int V) : V(V) {}

    void addEdge(int src, int dest, int weight) {
        edges.push_back(Edge(src, dest, weight));
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

            for (const auto& edge : edges) {
                if (edge.src == u) {
                    int v = edge.dest;
                    int w = edge.weight;
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
            for (const auto& edge : edges) {
                int u = edge.src;
                int v = edge.dest;
                int w = edge.weight;
                if (dist[u] != INF && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }

        for (const auto& edge : edges) {
            int u = edge.src;
            int v = edge.dest;
            int w = edge.weight;
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                cout << "Graph contains negative-weight cycle\n";
                return {};
            }
        }

        return dist;
    }
};

int main() {
    Graph g(5);

    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 1);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 5);
    g.addEdge(2, 3, 2);
    g.addEdge(2, 4, 1);
    g.addEdge(3, 4, 3);

    int source = 0;

    vector<int> dijkstraDistances = g.dijkstra(source);
    cout << "Shortest distances from vertex " << source << " using Dijkstra's algorithm:\n";
    for (int i = 0; i < dijkstraDistances.size(); ++i) {
        cout << "Vertex " << i << ": " << dijkstraDistances[i] << "\n";
    }

    vector<int> bellmanFordDistances = g.bellmanFord(source);
    if (!bellmanFordDistances.empty()) {
        cout << "\nShortest distances from vertex " << source << " using Bellman-Ford algorithm:\n";
        for (int i = 0; i < bellmanFordDistances.size(); ++i) {
            cout << "Vertex " << i << ": " << bellmanFordDistances[i] << "\n";
        }
    }

    return 0;
}
