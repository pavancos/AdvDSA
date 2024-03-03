#include <iostream>
#include <queue>
#include <climits>
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

    void Print() {
        int height = getHeight();
        for (int i = 0; i < height; ++i) {
            cout << "Level " << i << ": ";
            PrintUtil(this, i);
            cout << endl;
        }
        cout << endl;
    }

    void PrintUtil(Node<T, order>* root, int level) {
        if (root == NULL)
            return;
        if (level == 0) {
            for (int i = 0; i < root->nOKeys; i++)
                cout << root->keys[i] << " ";
        } else {
            for (int i = 0; i <= root->nOKeys; i++)
                PrintUtil(root->childrn[i], level - 1);
        }
    }

    int getHeight() {
        int C = 1;
        Node<T, order>* curr = this;
        while (true) {
            if (curr->childrn[0] == NULL)
                return C;
            curr = curr->childrn[0];
            C++;
        }
    }

    bool IsLeaf() {
        return (childrn[0] == NULL);
    }
};

template <typename T>
void Insert(Node<T>* &root, T val) {
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

template<typename T>
void FindLargestInEachLevel(Node<T>* root) {
    if (root == NULL) {
        cout << "The 2-3 Tree is empty." << endl;
        return;
    }

    queue<Node<T>*> levelQueue;
    levelQueue.push(root);

    int currentLevel = 0;
    int nextLevel = 0;

    while (!levelQueue.empty()) {
        T largestNodeValue = INT_MIN;

        for (int i = 0; i <= currentLevel; ++i) {
            Node<T>* currentNode = levelQueue.front();
            levelQueue.pop();

            for (int j = 0; j < currentNode->nOKeys; ++j) {
                if (currentNode->keys[j] > largestNodeValue)
                    largestNodeValue = currentNode->keys[j];
            }

            for (int j = 0; j <= currentNode->nOKeys; ++j) {
                if (currentNode->childrn[j] != NULL) {
                    levelQueue.push(currentNode->childrn[j]);
                    nextLevel++;
                }
            }
        }

        cout << "Largest node value at level " << currentLevel << ": " << largestNodeValue << endl;

        currentLevel++;
    }
}

int main() {
    Node<int>* root = NULL;
    Insert(root, 10);
    Insert(root, 5);
    Insert(root, 20);
    Insert(root, 15);
    Insert(root, 25);
    Insert(root, 3);
    Insert(root, 7);

    cout << "Finding largest node in each level of the 2-3 tree:" << endl;
    FindLargestInEachLevel(root);

    return 0;
}
