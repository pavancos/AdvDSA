#include <bits/stdc++.h>
using namespace std;
#define NUM 4

typedef struct pinfo
{
    string pname;
    int Atime;
    int Btime;
} pinfo;

typedef struct cmpBtime
{
    int operator()(const pinfo &a,
                   const pinfo &b)
    {
        return a.Btime > b.Btime;
    }
} cmpBtime;

void SJF(pinfo *a)
{
    {
        int temp = 0;
        for (int i = 0; i < NUM - 1; i++)
        {
            temp = i;
            for (int j = i + 1; j < NUM; j++)
            {
                if (a[j].Atime < a[temp].Atime)
                {
                    temp = j;
                }
            }
            swap(a[i], a[temp]);
        }
    }
    int RunT = a[0].Atime;

    priority_queue<pinfo, vector<pinfo>, cmpBtime> RUN;
    priority_queue<pinfo, vector<pinfo>, cmpBtime> pq;
    int temp = a[0].Atime;
    RUN.push(a[0]);
    a[0].Atime = -1;
    cout << "PID"
         << "\t";
    cout << "Arrival time"
         << "\t";
    cout << "Burst time"
         << "\t";
    cout << endl;
    while (!RUN.empty())
    {
        cout << RUN.top().pname << "\t";
        cout << RUN.top().Atime << "\t\t";
        cout << RUN.top().Btime << "\t";
        cout << endl;
        RunT += RUN.top().Btime;
        RUN.pop();
        for (int i = 0; i < NUM; i++)
        {
            if ((a[i].Atime <= RunT && a[i].Atime != -1))
            {
                RUN.push(a[i]);
                a[i].Atime = -1;
            }
        }
    }
}

int main()
{
    pinfo a[NUM];
    a[0] = {"p1", 4, 3};
    a[1] = {"p2", 0, 8};
    a[2] = {"p3", 5, 4};
    a[3] = {"p4", 9, 2};
    cout << "Schedeuled Jobs ";
    cout << "\n"
         << endl;
    SJF(a);
    cout<<endl;
}
