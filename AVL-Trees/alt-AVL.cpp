#include <iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
#include<climits>
#include<cstring>
using namespace std;

template <typename T>
struct node
{
    T data;
    node<T> *left;
    node<T> *right;
};

template <typename T>
int calcHt(node<T> *root)
{
    if (root == NULL)
        return 0;
    int lH = calcHt(root->left);
    int rH = calcHt(root->right);
    return 1 + max(lH, rH);
}

template <typename T>
node<T> *createNewNode(T x)
{
    node<T> *newNode = new node<T>();
    newNode->data = x;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

template <typename T>
node<T> *rightRotate(node<T> *y)
{
    node<T> *x = y->left;
    node<T> *T2 = x->right;
    x->right = y;
    y->left = T2;
    return x;
}

template <typename T>
node<T> *leftRotate(node<T> *x)
{
    node<T> *y = x->right;
    node<T> *T2 = y->left;
    y->left = x;
    x->right = T2;
    return y;
}

template <typename T>
int calcB(node<T> *t)
{
    if (t == NULL)
        return 0;
            return calcHt(t->left) - calcHt(t->right);
}

template <typename T>
node<T> *insertNode(node<T> *node, T x)
{
    if (node == NULL)
        return createNewNode(x);
    if (x < node->data)
        node->left = insertNode(node->left, x);
    else if (x > node->data)
        node->right = insertNode(node->right, x);
    else
        return node;

    int balance = calcB(node);

    if (balance > 1 && x < node->left->data)
        return rightRotate(node);

    if (balance < -1 && x > node->right->data)
        return leftRotate(node);

    if (balance > 1 && x > node->left->data)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && x < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

template <typename T>
node<T> *findMinValueNode(node<T> *node)
{
    while (node->left != NULL)
        node = node->left;
    return node;
}

template <typename T>
node<T> *deleteNode(node<T> *root, T x)
{
    if (root == NULL)
    {
        cout << "Value " << x << " not found in the tree." << endl;
        return root;
    }

    if (x < root->data)
        root->left = deleteNode(root->left, x);

    else if (x > root->data)
        root->right = deleteNode(root->right, x);

    else
    {
        if (root->left == NULL || root->right == NULL)
        {
            node<T> *temp = root->left ? root->left : root->right;
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;
            delete temp;
        }
        else
        {
            node<T> *temp = findMinValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    if (root == NULL)
        return root;

    int balance = calcB(root);

    if (balance > 1 && calcB(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && calcB(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && calcB(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && calcB(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

template <typename T>
node<T> *searchNode(node<T> *root, T x)
{
    if (root == NULL || root->data == x)
        return root;
    else if (x < root->data)
        return searchNode(root->left, x);
    else
        return searchNode(root->right, x);
}

template <typename T>
void inO(node<T> *root)
{
    if (root != NULL)
    {
        inO(root->left);
        cout << root->data << " ";
        inO(root->right);
    }
}

int main()
{
    node<int> *root = NULL;
    int c;
    int v;
    cout << "1.insert 2.delete 3.search 4.display" << endl;
    do
    {
        cout << "Enter choice: ";
        cin >> c;
        switch (c)
        {
        case 1:
            cout << "Value to be inserted: ";
            cin >> v;
            root = insertNode(root, v);
            break;
        case 2:
            cout << "Value to be deleted: ";
            cin >> v;
            root = deleteNode(root, v);
            break;
        case 3:
            cout << "Value to be searched: ";
            cin >> v;
            if (searchNode(root, v))
                cout << v << " found";
            else
                cout << v << " not found";
            break;
        case 4:
            cout << "\nInorder traversal: ";
            inO(root);
            break;
        default:
            cout << "/ninvalid" << endl;
        }
        cout << "\ncontinue?";
        cin >> c;
    } while (c == 1);
    return 0;
}
