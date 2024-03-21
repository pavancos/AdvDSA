#include <iostream>
#include <list>
#include <stack>
#include <queue>
using namespace std;

class Graph {
    int V;
    list<int> *adj;
    
    void topoUtil(int v, bool visited[], stack<int> &Stack) {
        visited[v] = true;
        list<int>::iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); ++i)
            if (!visited[*i])
                topoUtil(*i, visited, Stack);
        Stack.push(v);
    }

public:
    Graph(int V) {
        this->V = V;
        adj = new list<int>[V];
    }
    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }

    void topologicalSort() {
        stack<int> Stack;
        bool *visited = new bool[V];
        for (int i = 0; i < V; i++)
            visited[i] = false;
        for (int i = 0; i < V; i++)
            if (visited[i] == false)
                topoUtil(i, visited, Stack);
        while (Stack.empty() == false){
            cout << Stack.top() << " ";
            Stack.pop();
        }
        cout << endl;
    }

    void topologicalSortWithQueue() {
        vector<int> inDegree(V, 0);
        queue<int> q;
        for (int i = 0; i < V; ++i) {
            for (int j : adj[i]) {
                inDegree[j]++;
            }
        }
        for (int i = 0; i < V; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int curNode = q.front();
            q.pop();
            cout << curNode << " ";
            for (int neighbor : adj[curNode]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }
};
int main() {
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    cout << "Topological Sort with Stack: ";
    g.topologicalSort();
    cout << "Topological Sort with Queue: ";
    g.topologicalSortWithQueue();
    return 0;
}
