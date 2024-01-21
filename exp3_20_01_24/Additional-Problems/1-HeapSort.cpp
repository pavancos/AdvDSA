#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>arr;
    int num; cout<<"Enter the number of elements: ";
    cin>>num;
    arr.reserve(num);
    for(int i=0;i<num;i++){
        int e;
        cin>>e;
        arr.push_back(e);
    }
    
    
}