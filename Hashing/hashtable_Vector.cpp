#include<iostream>
#include<vector>
#include<algorithm>
#define M 11
using namespace std;

static int Count;

template <typename T>
class HASH {
public:
    vector<T> V;
    int hashing(T k) {
        return (k % M);
    }
    void insert(HASH<T>* H, T val) {
        H[hashing(val)].V.push_back(val);
        Count++;
        H[1].display(H);
    }
    void dlt(HASH<T>* H, T val) {
        auto it = find(H[hashing(val)].V.begin(), H[hashing(val)].V.end(), val);
        if (it != H[hashing(val)].V.end()) {
            H[hashing(val)].V.erase(it);
            Count--;
        }
        H[1].display(H);
    }
    void search(HASH<T>* H, T val) {
        int key = hashing(val);
        auto it = find(H[key].V.begin(), H[key].V.end(), val);
        if (it != H[key].V.end()) {
            cout << "Element found at key: " << key << endl;
        }
        else
            cout << "Element not found.\n";
    }
    void size() {
        cout << "Size is " << Count << endl;
    }
    void display(HASH<T>* H) {
        for (int i = 0; i < M; i++) {
            cout << i << ":  ";
            for (auto v : H[i].V) {
                // cout << v << " -> ";
                cout << v << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    HASH<int> H[M];
    int ch;
    do {
        cout << "MENU:\n1)Insert\t2)Delete\n3)Search\t4)Size\n5)Display\t0)Exit\n";
        cout << "Enter the choice: ";
        int V;
        cin >> ch;
        switch (ch) {
            case 0: break;
            case 1: cout << "Enter Element to be inserted: ";
                    cin >> V;
                    H[1].insert(H, V);
                    break;
            case 2: cout << "Enter Element to be deleted: ";
                    cin >> V;
                    H[1].dlt(H, V);
                    break;
            case 3: cout << "Enter Element to be searched: ";
                    cin >> V;
                    H[1].search(H, V);
                    break;
            case 4: H[1].size();
                    break;
            case 5: H[1].display(H);
                    break;
            default: break;
        }
    } while (ch);
}
