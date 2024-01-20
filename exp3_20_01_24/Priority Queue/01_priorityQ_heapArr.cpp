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


int main(){
    vector<int>MaxHeap;int f=1;
    do{
        cout<<"1)Insert  2)Delete  3)Merge  4)Exit\n";
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
                int i=Delete(MaxHeap,i);
                cout<<"Popped: "<<i<<endl;
            break;
            
            case 4:
                f=0;
            break;
        }
    }while(f)
}