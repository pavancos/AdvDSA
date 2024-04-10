#include<bits/stdc++.h>
using namespace std;
int main(){
    cout << "1. From File" << endl;
    cout << "2. From User" << endl;
    cout << "Enter Choice: ";
    int choice;
    cin >> choice;
    cin.ignore(); // Consume newline character
    if (choice == 1) {
        ifstream file;
        file.open("input.txt");
        if (!file.is_open()) {
            cout << "Error: Could not open file!" << endl;
            return 1;
        }
        string text, pattern;
        getline(file, text);
        cout << "Enter Pattern: ";
        getline(cin, pattern);
        int n = text.length();
        int m = pattern.length();
        int lps[m];
        lps[0] = 0;
        int len = 0;
        int i = 1;
        while (i < m) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        int j = 0;
        i = 0;
        while (i < n) {
            if (pattern[j] == text[i]) {
                j++;
                i++;
            }
            if (j == m) {
                cout << "Pattern found at index " << i - j << endl;
                j = lps[j - 1];
            } else if (i < n && pattern[j] != text[i]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        file.close();
    } else {
        string text, pattern;
        cout << "Enter Text: ";
        getline(cin, text);
        cout << "Enter Pattern: ";
        getline(cin, pattern);
        int n = text.length();
        int m = pattern.length();
        int lps[m];
        lps[0] = 0;
        int len = 0;
        int i = 1;
        while (i < m) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        int j = 0;
        i = 0;
        while (i < n) {
            if (pattern[j] == text[i]) {
                j++;
                i++;
            }
            if (j == m) {
                cout << "Pattern found at index " << i - j << endl;
                j = lps[j - 1];
            } else if (i < n && pattern[j] != text[i]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
    }
}
