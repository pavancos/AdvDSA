#include <iostream>
#include <vector>
using namespace std;

template <typename T, int order = 3>
struct Node {
    int nOKeys;
    int nodeOrder;
    int pos = -1;
    T* keys;
    Node** childrn;

    Node(int ord) : nodeOrder(ord), nOKeys(0), keys(new T[ord]), childrn(new Node*[ord + 1]) {
        for (int i = 0; i <= ord; ++i) {
            childrn[i] = NULL;
        }
    }

    int Insert(T val) {
        if (childrn[0] == NULL) {
            keys[++pos] = val;
            ++nOKeys;
            for (int i = pos; i > 0; i--)
                if (keys[i] < keys[i - 1])
                    swap(keys[i], keys[i - 1]);
        } else {
            int i = 0;
            while (i < nOKeys && val > keys[i])
                i++;
            int flag = childrn[i]->Insert(val);
            if (flag) {
                T mid;
                int TEMP = i;
                Node<T, order>* newNode = split(childrn[i], &mid);
                while (i < nOKeys && mid > keys[i])
                    i++;
                for (int j = nOKeys; j > i; j--)
                    keys[j] = keys[j - 1];
                keys[i] = mid;
                ++nOKeys;
                ++pos;
                int k;
                for (k = nOKeys; k > TEMP + 1; k--)
                    childrn[k] = childrn[k - 1];
                childrn[k] = newNode;
            }
        }
        if (nOKeys == order)
            return 1;
        else
            return 0;
    }

    Node<T, order>* split(Node* node, T* med) {
        int NumberOfKeys = node->nOKeys;
        Node<T, order>* newNode = new Node<T, order>(order);
        int midval = NumberOfKeys / 2;
        *med = node->keys[midval];
        int i;
        for (i = midval + 1; i < NumberOfKeys; ++i) {
            newNode->keys[++newNode->pos] = node->keys[i];
            newNode->childrn[newNode->pos] = node->childrn[i];
            ++newNode->nOKeys;
            --node->pos;
            --node->nOKeys;
            node->childrn[i] = NULL;
        }
        newNode->childrn[newNode->pos + 1] = node->childrn[i];
        node->childrn[i] = NULL;
        --node->nOKeys;
        --node->pos;
        return newNode;
    }

    void PrintPaths() {
        vector<T> path;
        PrintPathsUtil(this, path);
    }

    void PrintPathsUtil(Node<T, order>* node, vector<T>& path) {
        if (node == nullptr)
            return;

        // Add the current node to the path
        path.push_back(node->keys[0]);

        // If it's a leaf node, print the path
        if (node->childrn[0] == nullptr) {
            cout << "Path: ";
            for (const T& key : path)
                cout << key << " ";
            cout << endl;
        } else {
            // Recursive call for all children
            for (int i = 0; i <= node->nOKeys; ++i)
                node->childrn[i]->PrintPathsUtil(node->childrn[i], path);
        }

        // Remove the current node from the path before backtracking
        path.pop_back();
    }

    bool IsLeaf() {
        return (childrn[0] == NULL);
    }
};

template <typename T>
void Insert(Node<T>*& root, T val) {
    if (root == NULL) {
        root = new Node<T>(3);
        root->keys[++root->pos] = val;
        root->nOKeys = 1;
    } else {
        int flag = root->Insert(val);
        if (flag) {
            T mid;
            Node<T>* splitNode = root->split(root, &mid);
            Node<T>* newNode = new Node<T>(3);
            newNode->keys[++newNode->pos] = mid;
            newNode->nOKeys = 1;
            newNode->childrn[0] = root;
            newNode->childrn[1] = splitNode;
            root = newNode;
        }
    }
}

int main() {
    Node<int>* root = nullptr;

    Insert(root, 10);
    Insert(root, 5);
    Insert(root, 20);
    Insert(root, 15);
    Insert(root, 25);
    Insert(root, 3);
    Insert(root, 7);

    cout << "All possible paths from root to leaf node:" << endl;
    root->PrintPaths();

    return 0;
}
