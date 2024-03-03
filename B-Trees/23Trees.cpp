#include <iostream>
#include <algorithm>
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
        for (int i = 1; i <= height; ++i) {
            if (i == 1)
                PrintUtil(i, true);
            else
                PrintUtil(i, false);
            cout << endl;
        }
        cout << endl;
    }

    void PrintUtil(int height, bool flagroot) {
        if (height == 1 || flagroot) {
            for (int i = 0; i < nOKeys; i++) {
                if (i == 0)
                    cout << "|";
                cout << keys[i];
                if (i != nOKeys - 1)
                    cout << "|";
                if (i == nOKeys - 1)
                    cout << "|"
                        << " ";
            }
        } else {
            for (int i = 0; i <= nOKeys; i++)
                if (childrn[i] != NULL)
                    childrn[i]->PrintUtil(height - 1, false);
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

template <typename T>
void Print(Node<T>* root) {
    if (root != NULL)
        root->Print();
    else
        cout << "The B-Tree is Empty" << endl;
}

template <typename T>
bool Search(Node<T>* root, T val) {
    if (root == NULL)
        return false;
    else {
        int i = 0;
        while (i < root->nOKeys && val > root->keys[i])
            i++;
        if (root->keys[i] == val)
            return true;
        else if (!root->IsLeaf())
            return Search(root->childrn[i], val);
        else
            return false;
    }
}

template<typename T>
void Delete(Node<T>* root, T val) {
    if (root == NULL) {
        cout << "The B-Tree is Empty" << endl;
        return;
    }
    Node<T>* node = root;
    bool found = false;

    while (node != NULL) {
        int i = 0;
        while (i < node->nOKeys && val > node->keys[i])
            i++;
        if (i < node->nOKeys && node->keys[i] == val) {
            found = true;
            if (node->IsLeaf()) {
                for (int j = i; j < node->nOKeys - 1; j++)
                    node->keys[j] = node->keys[j + 1];
                node->nOKeys--;
                node->pos--;
                break;
            } else {
                Node<T>* successor = node->childrn[i + 1];
                while (successor->childrn[0] != NULL)
                    successor = successor->childrn[0];
                node->keys[i] = successor->keys[0];
                node = node->childrn[i + 1];
                val = successor->keys[0];
            }
        } else
            node = node->childrn[i];
    }
    if (!found)
        cout << "Element " << val << " not found in the B-Tree" << endl;
}

template <typename T>
Node<T>* getSuccessor(Node<T>* node, int index) {
    Node<T>* curr = node->childrn[index + 1];
    while (!curr->IsLeaf())
        curr = curr->childrn[0];
    return curr;
}

template<typename T>
void perform(){
    Node<T>* root = NULL;
    int ch, n;
    T val;
    cout<<"1.insert 2.delete 3.search 4.display"<<endl;
    do {
        cin>>ch;
        switch(ch){
        case 1:
            cout<<"Enter number of elements: ";
            cin>>n;
            cout<<"Enter element: ";
            for(int i=0;i<n;i++){
                cin>>val;
                Insert(root, val);
            }
            break;
        case 2:
            cout<<"Enter value: ";
            cin>>val;
            Delete(root, val);
            break;
        case 3:
            cout<<"Enter value: ";
            cin>>val;
            if(Search(root, val))
                cout<<val<<" found";
            else
                cout<<val<<" not found";
            break;
        case 4:
            cout << "2-3 Tree: "<<endl;
            Print(root);
            break;
        }
        cout << "\nto continue:(1): ";
        cin >> ch;
    } while (ch == 1);
}

int main() {
    perform<int>();
    return 0;
}
