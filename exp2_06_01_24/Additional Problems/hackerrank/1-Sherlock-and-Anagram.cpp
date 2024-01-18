#include <bits/stdc++.h>
using namespace std;
string ltrim(const string &);
string rtrim(const string &);
int sherlockAndAnagrams(string s) {
    int n = s.length();
    unordered_map<string, int> substringFrequency;
    for (int i = 0; i < n; i++) 
    {
        string substring;
        for (int j = i; j < n; j++) 
        {
            substring = s.substr(i, j - i + 1);
            sort(substring.begin(), substring.end());
            substringFrequency[substring]++;
        }
    }
    int count = 0;
    for (auto& entry : substringFrequency) {
        int freq = entry.second;
        count += (freq * (freq - 1)) / 2;
    }
    return count;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
    string q_temp;
    getline(cin, q_temp);
    int q = stoi(ltrim(rtrim(q_temp)));
    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);
        int result = sherlockAndAnagrams(s);
        fout << result << "\n";
    }
    fout.close();
    return 0;
}
string ltrim(const string &str) {
    string s(str);
    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );
    return s;
}
string rtrim(const string &str) {
    string s(str);
    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );
    return s;
}
