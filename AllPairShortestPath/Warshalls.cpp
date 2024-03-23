#include <bits/stdc++.h>
using namespace std;
#define V 5
#define INF INT_MAX
void addEdge(int g[][V],int i,int j,int w){
    g[i][j]=w;
}
void print(int g[][V]){
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (g[i][j] == INF)
                cout << "INF"
                     << " ";
            else
                cout << g[i][j] << "   ";
        }
        cout << endl;
    }
}
void apsp(int g[][V]){
    int i, j, k;
    for (k = 0; k < V; k++)
        for (i = 0; i < V; i++)
            for (j = 0; j < V; j++)
                if (g[i][j] > (g[i][k] + g[k][j]) && (g[k][j] != INF && g[i][k] != INF))
                    g[i][j] = g[i][k] + g[k][j];
    print(g);
}
int main(){
    // int graph[V][V] = {
    //     {0, 2, 7, INF, INF},
    //     {5, 0, INF, 7, 4},
    //     {3, INF, 0, 6, INF},
    //     {INF, 5, 1, 0, INF},
    //     {INF, INF, INF, 3, 0}
    // };
    int graph[V][V];
    cout<<"Enter The Vertices (Src-Dest-Wt)\n";
    for(int i=0;i<V*V;i++){
        int s,d,w;
        cin>>s>>d>>w;
        addEdge(graph,s-1,d-1,w);
    }
    print(graph);
    cout<<"\nAll Pair Shortest Path:\n";
    apsp(graph);
}