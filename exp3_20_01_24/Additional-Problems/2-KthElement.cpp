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
    if (heap.empty())
        return -1;
    int max = heap[0];
    heap[0] = heap.back();
    heap.pop_back();

    heapify(heap, 0, heap.size());

    return max;
}

void Display(vector<int>& heap) {
    cout << "Priority Queue: ";
    for (int val : heap)
        cout << val << " ";
    cout << "\n";
}


int main(){
    vector<int>MaxHeap;
    int num;
    cout<<"Enter the number: ";
    cin>>num;
    cout<<"Enter elements:\n";
    for(int i=0;i<num;i++){
        int h;
        cin>>h;
        Insert(MaxHeap,h);
    }
    int k;
    cout<<"Enter k value: ";
    cin>>k;
    int Kth;
    for(int i=0;i<k;i++){
        Kth=Delete(MaxHeap);
    }
    cout<<k<<"th Element: "<<Kth<<endl;
}