#include <bits/stdc++.h>
using namespace std;
void heapify(vector<int>&arr, int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
void heapSort(vector<int>&arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
void printArray(vector<int>&arr, int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}
int main()
{
    vector<int> arr;
    int num;
    cout << "Enter the number of elements: ";
    cin >> num;
    arr.reserve(num);
    for (int i = 0; i < num; i++)
    {
        int e;
        cin >> e;
        arr.push_back(e);
    }
    heapSort(arr, num);

    cout << "Sorted array is \n";
    printArray(arr, num);

    return 0;
}