#include <iostream>
#include <vector>
using namespace std;
vector<int> par;
vector<int> rnk;
void init(int n) {
    par.resize(n);rnk.resize(n, 0);
    for (int i = 0; i < n; ++i) par[i] = i;
}
int findPar(int node) {
    if (node == par[node])  return node;
    return par[node] = findPar(par[node]);
}
void simpleunion(int x, int y) {
    x = findPar(x);y = findPar(y);
    if (rnk[x] < rnk[y])  par[x] = y;
    else if (rnk[y] < rnk[x]) par[y] = x;
    else{  par[y] = x; rnk[x]++; }
}
int main() {
    int n;
    cout<<"Enter n.of vertices: ";cin >> n;
    init(n);
    char ch;
    do {
        cout << "'u'-> union\n'f'-> find\n'q'-> quit\n";
        cin >> ch;
        if (ch == 'u') {
            int u, v;
            cout << "Enter values u and v: ";
            cin >> u >> v;
            simpleunion(u, v);
        } else if (ch == 'f') {
            int node;
            cout << "Enter value of node: ";
            cin >> node;
            cout << "Parent of " << node << "= " << findPar(node) << endl;
        }
    } while (ch != 'q');
}
