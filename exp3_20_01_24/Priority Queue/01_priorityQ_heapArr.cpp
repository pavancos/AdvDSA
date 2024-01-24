#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void heapify(vector<int>& heap, int i, int n) {
    int parent = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && heap[l] > heap[parent]) {
        parent = l;
    }

    if (r < n && heap[r] > heap[parent]) {
        parent = r;
    }

    if (parent != i) {
        swap(heap[i], heap[parent]);
        heapify(heap, parent, n);
    }
}

void Insert(vector<int>& heap, int val) {
    heap.push_back(val);
    int i = heap.size() - 1;
    while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
        swap(heap[(i - 1) / 2], heap[i]);
        i = (i - 1) / 2;
    }
}

int Delete(vector<int>& heap) {
    if (heap.empty()) {
        return -1;
    }

    int max = heap[0];
    heap[0] = heap.back();
    heap.pop_back();

    heapify(heap, 0, heap.size());

    return max;
}

vector<int> merge(vector<int> &heap1, vector<int> &heap2){
    heap1.reserve(heap1.size() + heap2.size());
    for(int i=0;i<heap2.size();i++)
        Insert(heap1,Delete(heap2));
    return heap1;
}

void Display(vector<int>& heap) {
    cout << "Priority Queue: ";
    for (int val : heap)
        cout << val << " ";
    cout << "\n";
}


int main(){
    vector<int>MaxHeap;int f=1;
    do{
        cout<<"1)Insert  2)Delete  3)Merge\n4)Display  5)Exit\n";
        int ch;
        cin>>ch;
        switch(ch){
            case 1:
                int i;
                cout<<"enter number to be inserted: ";
                cin>>i;
                Insert(MaxHeap,i);
            break;
            
            case 2:
                i=Delete(MaxHeap);
                cout<<"Popped: "<<i<<endl;
            break;
            
            case 3:{
                vector<int> anotherHeap;
                int j;
                cout << "Enter the number of elements: ";
                cin >> j;
                cout << "Enter the elements:\n";
                for (int i = 0; i < j; i++){
                    int e;
                    cin >> e;
                    anotherHeap.push_back(e);
                }
                MaxHeap = merge(MaxHeap, anotherHeap);
            }
            break;
            
            case 4:
                Display(MaxHeap);
            break;

            case 5:
                f=0;
            break;
        }
    }while(f);
}