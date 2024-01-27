#include <iostream>
#include <unordered_set>
using namespace std;
void PalindromicSubstrings(string s) 
{
    int n = s.size();
    unordered_set<string> Set;
    for (int i = 0; i < n; i++) {
        int l = i, r = i;
        while (l >= 0 && r < n && s[l] == s[r]) {
            Set.insert(s.substr(l, r - l + 1));
            l--;
            r++;
        }
        l = i;
        r = i + 1;
        while (l >= 0 && r < n && s[l] == s[r]) 
        {
            Set.insert(s.substr(l, r - l + 1));
            l--;
            r++;
        }
    }
    cout << "Palindromic Count: " << Set.size() << endl;
    cout << "Palindromic Sub-strings: " << endl;
    for ( auto pal : Set) {
        cout << pal << endl;
    }
}
int main() {
    string str;
    cout << "Enter the string: ";
    cin >> str;
    PalindromicSubstrings(str);
    return 0;
}