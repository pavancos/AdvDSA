#include<iostream>
#include<vector>
#include<algorithm>
#define M 11
using namespace std;
static int Count;
template <typename T>
class HASH{
public:
    vector<T> L;
    int hashing(T k){
        return (k%M);
    }
    void insert(HASH<T> *H, T val){
        H->L.push_back(val);
        Count++;
        H->display(H);
    }
    void dlt(HASH<T> *H, T val){
        remove(H->L.begin(), H->L.end(), val);
        H->display(H);
    }
    void search(HASH<T> *H, T val){
        int key = hashing(val);
        auto it = find(H->L.begin(), H->L.end(), val);
        if (it != H->L.end()){
            cout << "Element found at key: " << key << endl;
        }
        else
            cout << "Element not found.\n";
    }
    void size(){
        cout << "Size is " << Count << endl;
    }
    void display(HASH<T> *H){
        for (int i = 0; i < M; i++){
            cout << i << ":  ";
            for (auto v : H->L){
                cout << v << " -> ";
            }
            cout << endl;
        }
    }
};

int main(){
    HASH<int> H[M];
    int ch;
    do{
        cout << "MENU:\n1)Insert\t2)Delete\n3)Search\t4)Size\n5)Display\t0)Exit\n";
        cout << "Enter the choice: ";
        int V;
        cin >> ch;
        switch (ch){
            case 0: break;
            case 1: cout << "Enter Element to be inserted: ";
                    cin >> V;
                    H[1].insert(&H[1], V);
                    break;
            case 2: cout << "Enter Element to be deleted: ";
                    cin >> V;
                    H[1].dlt(&H[1], V);
                    break;
            case 3: cout << "Enter Element to be searched: ";
                    cin >> V;
                    H[1].search(&H[1], V);
                    break;
            case 4: H[1].size();
                    break;
            case 5: H[1].display(&H[1]);
                    break;
            default: break;
        }
    } while (ch);
}
