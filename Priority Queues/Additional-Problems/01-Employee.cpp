#include<bits/stdc++.h>
using namespace std;
// EMPID
// Ename
// Designation
// Age
// Height
#define NUM 10
typedef struct EInfo
{
    int ID;
    string Name;
    string Des;
    int Age;
    float Height;
} EInfo;

typedef struct cmpAge
{
    int operator()(EInfo &a, EInfo &b){
        return a.Age > b.Age;
    }
} cmpAge;
int main()
{
    EInfo a[2];
    a[0] = {100,"aaa","manager",56,5.6};
    a[1] = {101,"aaa","manager",30,5.9};
    priority_queue<EInfo, vector<EInfo>, cmpAge> EList;
    for(auto i:a)
        EList.push(i);
    cout<<"Employee List:\n";
    while(!EList.empty()){
        cout << EList.top().ID << "\t";
        cout << EList.top().Name << "\t";
        cout << EList.top().Des << "\t";
        cout << EList.top().Age << "\t";
        cout << EList.top().Height << "\t";
        cout << endl;
        EList.pop();
    }
}
