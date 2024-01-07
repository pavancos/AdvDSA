#include<iostream>
#include<vector>
#include<algorithm>
#define M 11
using namespace std;
static int Count,C;
template <typename T>
class HASH{
public:
    T value;
    int hashing(T k){
        return (k%M);
    }
    void insert(HASH<T> *H, T val){
        if(H[hashing(val)].value==-1){
            H[hashing(val)].value=val;
            Count++;
            H->display(H);
            return;
        }
        else{
            C++;
            if(H[hashing(hashing(val)+C)].value==-1){
                H[hashing(hashing(val)+C)].value=val; 
                Count++;
                H->display(H);
                return;
            }
            else
                insert(&H[1], val);
        }
    }
    void dlt(HASH<T> *H, T val){
        for(int i=0;i<M;i++)
            if(H[i].value==val)
                H[i].value=-1;
        H->display(H);
    }
    void search(HASH<T> *H, T val){
        int key = hashing(val),coll=0;
        for(int i=0;i<M;i++)
            if(H[hashing((val)+coll)].value!=val)
                coll++;
        if (H[hashing(hashing(val)+coll)].value==val)
            cout << "Element of key: " << key <<" is present at: "<<hashing(hashing(val)+coll)<< endl;
        else
            cout << "Element not found.\n";
    }
    void size(){
        cout << "Size is " << Count << endl;
    }
    void display(HASH<T> *H){
        for (int i = 0; i < M; i++){
            cout << i << ":  ";
            if(H[i].value!=-1)
                cout<<H[i].value;
            cout << endl;
        }
    }
};

int main(){
    HASH<int> H[M];
    for(int i=0;i<M;i++)
        H[i].value=-1;
    H[1].dlt(&H[1], 21845);
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
