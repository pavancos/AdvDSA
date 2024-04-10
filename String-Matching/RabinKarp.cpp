#include<bits/stdc++.h>
using namespace std;
int main() {
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
        int d = 256;
        int q = 101;
        int h = 1;
        for (int i = 0; i < m - 1; i++) {
            h = (h * d) % q;
        }
        int p = 0;
        int t = 0;
        for (int i = 0; i < m; i++) {
            p = (d * p + pattern[i]) % q;
            t = (d * t + text[i]) % q;
        }
        for (int i = 0; i <= n - m; i++) {
            if (p == t) {
                int j;
                for (j = 0; j < m; j++) {
                    if (text[i + j] != pattern[j]) {
                        break;
                    }
                }
                if (j == m) {
                    cout << "Pattern found at index " << i << endl;
                }
            }
            if (i < n - m) {
                t = (d * (t - text[i] * h) + text[i + m]) % q;
                if (t < 0) {
                    t += q; 
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
        int d = 256;
        int q = 101;
        int h = 1;
        for (int i = 0; i < m - 1; i++) {
            h = (h * d) % q;
        }
        int p = 0;
        int t = 0;
        for (int i = 0; i < m; i++) {
            p = (d * p + pattern[i]) % q;
            t = (d * t + text[i]) % q;
        }
        for (int i = 0; i <= n - m; i++) {
            if (p == t) {
                int j;
                for (j = 0; j < m; j++) {
                    if (text[i + j] != pattern[j]) {
                        break;
                    }
                }
                if (j == m) {
                    cout << "Pattern found at index " << i << endl;
                }
            }
            if (i < n - m) {
                t = (d * (t - text[i] * h) + text[i + m]) % q;
                if (t < 0) {
                    t += q; 
                }
            }
        }
    }
    return 0;
}
