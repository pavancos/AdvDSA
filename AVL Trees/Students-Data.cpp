#include <iostream>
#include <map>
#include <string>

using namespace std;

struct Student
{
    int rollNo;
    string name;
    string classId;
};

class AVLTree
{
    map<int, Student> tree;

public:
    void insert(Student student)
    {
        tree[student.rollNo] = student;
    }

    void search(int rollNo)
    {
        if (tree.find(rollNo) != tree.end())
        {
            Student s = tree[rollNo];
            cout << "Name: " << s.name << endl;
            cout << "Class: " << s.classId << endl;
        }
        else
        {
            cout << "No student found with roll number " << rollNo << endl;
        }
    }
};

int main()
{
    AVLTree tree;

    Student s1 = {1, "John", "10A"};
    Student s2 = {2, "Sarah", "10B"};
    // Add more students

    tree.insert(s1);
    tree.insert(s2);

    int rollNo;
    cout << "Enter roll number to search: ";
    cin >> rollNo;

    tree.search(rollNo);

    return 0;
}