#include <iostream>
#include <vector>
using namespace std;
class DisjointSet {
private:
    vector<int> par;vector<int> rnk;
public:
    DisjointSet(int n) {
        par.resize(n);rnk.resize(n, 0);
        for (int i = 0; i < n; ++i) par[i] = i;
    }
    int find(int x) {
        if (par[x] != x) par[x] = find(par[x]);
        return par[x];
    }
    void unionSets(int u, int v) {
        int rou = find(u), rov = find(v);
        if (rou != rov) {
            if (rnk[rou] < rnk[rov]) par[rou] = rov;
            else if (rnk[rou] > rnk[rov]) par[rov] = rou;
            else {  par[rov] = rou; rnk[rou]++; }
        }
    }
};
int main() {
    int n;cout << "Enter n.of elements: "; cin >> n;
    DisjointSet ds(n);
    while (true) {
        int x, y;
        cout << "Enter two elements: "; cin >> x;
        if (x == -1) break;
        cin >> y;ds.unionSets(x, y);
    }
    while (true) {
        int x, y;
        cout << "Enter two elements: ";cin >> x;
        if (x == -1) break;cin >> y;
        cout<< x << " and " << y << " same set? " << (ds.find(x) == ds.find(y) ? "Yes" : "No") << endl;
    }
  return 0;
}
