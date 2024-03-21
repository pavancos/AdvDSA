#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Graph {
    unordered_map<char, unordered_set<char>> adj;

public:
    void addEdge(char u, char v) {
        adj[u].insert(v);
    }

    vector<char> topologicalSort() {
        unordered_map<char, int> inDegree;
        for (auto& [u, neighbors] : adj) {
            inDegree[u] = 0;
        }

        for (auto& [u, neighbors] : adj) {
            for (char v : neighbors) {
                inDegree[v]++;
            }
        }

        queue<char> q;
        for (auto& [u, degree] : inDegree) {
            if (degree == 0) {
                q.push(u);
            }
        }

        vector<char> result;
        while (!q.empty()) {
            char u = q.front();
            q.pop();
            result.push_back(u);
            for (char v : adj[u]) {
                inDegree[v]--;
                if (inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        return result;
    }
};

void printOrder(vector<char>& order) {
    cout << "Order of characters is: ";
    for (char ch : order) {
        cout << ch << " ";
    }
    cout << endl;
}
void findOrder(vector<string>& words) {
    Graph g;
    for (int i = 0; i < words.size() - 1; ++i) {
        string word1 = words[i];
        string word2 = words[i + 1];
        int minLength = min(word1.length(), word2.length());
        for (int j = 0; j < minLength; ++j) {
            if (word1[j] != word2[j]) {
                g.addEdge(word1[j], word2[j]);
                break;
            }
        }
    }

    vector<char> order = g.topologicalSort();
    printOrder(order);
}

int main() {
    vector<string> words1 = {"baa", "abcd", "abca", "cab", "cad"};
    findOrder(words1);

    vector<string> words2 = {"caa", "aaa", "aab"};
    findOrder(words2);

    return 0;
}
