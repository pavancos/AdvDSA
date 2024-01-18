#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;
int main() {
    unordered_map<int, vector<string>> stu_map;
    while (true) {
        cout << "1. Add details\n";
        cout << "2. Search student\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        int ch;
        cin >> ch;
        switch (ch) {
            case 1: {
                vector<string> stuDets;
                int rollNo;
                cout << "Enter roll number: ";
                cin >> rollNo;
                cout << "Enter student Name: ";
                cin.ignore();
                string name;
                getline(cin, name);
                stuDets.push_back(name);
                cout << "Enter Department: ";
                string dept;
                cin >> dept;
                stuDets.push_back(dept);
                cout << "Enter Section: ";
                string Section;
                cin >> Section;
                stuDets.push_back(Section);
                stu_map[rollNo] = stuDets;
                break;
            }
            case 2: {
                int rollNo;
                cout << "Enter the roll number to search: ";
                cin >> rollNo;
                auto it = stu_map.find(rollNo);
                if (it != stu_map.end()) {
                    cout << "Student details for Roll : " << rollNo << ": ";
                    for (auto dets : it->second) {
                        cout << dets << " ";
                    }
                    cout << endl;
                } else {
                    cout << "Student with Roll " << rollNo << " not found." << endl;
                }
                break;
            }
            case 3:
                cout << "End-of-Execution.\n";
                return 0;
            default:
                cout << "Invalid\n";
        }
    }
    return 0;
}