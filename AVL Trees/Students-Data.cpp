#include <iostream>
#include <map>
#include <string>
using namespace std;
struct stud{
    int roll;
    string name;
    string Class;
};
class AVL{
    map<int, stud> T;

public:
    void insert(stud stud){
        T[stud.roll] = stud;
    }

    void search(int roll){
        if (T.find(roll) != T.end()){
            stud s = T[roll];
            cout << "Name: " << s.name << endl;
            cout << "Class: " << s.Class << endl;
        }
        else
            cout << "No student found" << roll << endl;
    }
};
int main(){
    AVL T;
    stud students[10] = {
        {1, "tony", "10A"},
        {2, "steve", "10B"},
        {3, "bruce", "10A"},
        {4, "natasha", "10B"},
        {5, "clint", "10C"},
        {6, "wanda", "10A"},
        {7, "vision", "10B"},
        {8, "thor", "10C"},
        {9, "peter", "10A"},
        {10, "carol", "10C"}
    };
    for (int i = 0; i < 10; ++i)
        T.insert(students[i]);
    int r;
    cout << "enter a roll: ";
    cin >> r;
    T.search(r);
    return 0;
}