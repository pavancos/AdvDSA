#include<iostream>
#include<vector>
#include<algorithm>
#define M 11
using namespace std;
static int Count;
class HASH{
    public:
    vector<int>L;
    int hashing(int k){
        return (k%M);
    }
    void insert(HASH *H,int val){
        H[hashing(val)].L.push_back(val);
        Count++;
        H[1].display(H);
    }
    void dlt(HASH *H,int val){
        remove(H[hashing(val)].L.begin(),H[hashing(val)].L.end(),val);
        H[1].display(H);
    }
    void search(HASH *H,int val){
        int key=hashing(val);
        auto it = find(H[key].L.begin(), H[key].L.end(), val);
        if (it!=H[hashing(val)].L.end()){
            cout<<"Element found at key: "<<hashing(val)<<endl;
        }
        else
            cout<<"Element not found.\n";
    }
    void size(){
        cout<<"Size is"<<Count<<endl;
    }
    void display(HASH *H){
        for(int i=0;i<M;i++){
            cout<<i<<":  ";
            for(auto v:H[i].L){
                cout<<v<<" -> ";
            }
            cout<<endl;
        }
    }

};
int main(){
    HASH H[M];
    int ch;
    do{
        cout<<"MENU:\n1)Insert\t2)Delete\n3)Search\t4)Size\n5)Display\t0)Exit\n";
        cout<<"enter the choice: ";
        int V;
        cin>>ch;
        switch(ch){
            case 0:break;
            case 1: cout<<"Enter Element to be inserted: ";
                cin>>V;
                H[1].insert(H,V);
                break;
            case 2: cout<<"Enter Element to be deleted: ";
                cin>>V;
                H[1].dlt(H,V);
                break;
            case 3: cout<<"Enter Element to be seached: ";
                cin>>V;
                H[1].search(H,V);
                break;
            case 4:
                H[1].size();
                break;
            case 5:
                H[1].display(H);
                break;
            default:
                break;
        }
    }while(ch);
}