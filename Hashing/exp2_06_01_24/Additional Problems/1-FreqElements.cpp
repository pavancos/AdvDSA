#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int main() {
    vector<int> arr;
    cout << "Enter the number of elements to be inserted: ";
    int n;
    cin >> n;
    cout << "Enter the elements to be inserted: ";
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
    unordered_map<int, int> freqMap;
    for ( auto e : arr) {
        freqMap[e]++;
    }
    for ( auto e : freqMap) {
        cout << e.first << " - " << e.second << endl;
    }
    return 0;
}