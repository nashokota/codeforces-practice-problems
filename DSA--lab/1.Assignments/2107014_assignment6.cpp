#include <bits/stdc++.h>
using namespace std;

template<class E>
class BinaryTree {
public:
    E data;
    BinaryTree *left, *right, *parent;
    BinaryTree() {
        left = right = parent = NULL;
    }
    BinaryTree(E value) {
        data = value;
        left = right = parent = NULL;
    }
    BinaryTree(E value, BinaryTree<E> *par) {
        data = value;
        left = right = NULL;
        parent = par;
    }
    BinaryTree(E value, BinaryTree<E> *left, BinaryTree<E> *right) {
        data = value;
        this->left = left;
        this->right = right;
        parent = NULL;
    }

    void ins(E value) {
        if (data > value) {
            if (left) left->ins(value);
            else left = new BinaryTree<E>(value, this);
        }
        else {
            if (right) right->ins(value);
            else right = new BinaryTree<E>(value, this);
        }
    }

    int height() {
        int l = 1;
        if (left != NULL) l = max(l, 1 + left->height());
        if (right != NULL) l = max(l, 1 + right->height());
        return l;
    }
    void setValue(E value) {
        data = value;
    }
    void setLeft(BinaryTree<E>* newLeft) {
        left = newLeft;
    }
    void setRight(BinaryTree<E>* newRight) {
        right = newRight;
    }
    void setParent(BinaryTree<E>* newParent) {
        parent = newParent;
    }
    bool isBalanced() {
        bool l = true, r = true;
        int lh = 0, rh = 0, height = 0;
        if (left) {
            lh = left->height();
            l = left->isBalanced();
        }
        if (right) {
            rh = right->height();
            r = right->isBalanced();
        }
        if (abs(lh - rh) > 1) return false;
        else return l && r;
    }
    bool isComplete() {
        queue<BinaryTree<E>*>q;
        q.push(this);
        bool flag = false;
        while (!q.empty()) {
            BinaryTree<E> *top = q.front();
            q.pop();
            if (top->left) {
                if (flag) return false;
                q.push(top->left);
            }
            else flag = true;
            if (top->right) {
                if (flag) return false;
                q.push(top->right);
            }
            else flag = true;
            if (top->right == NULL && top->left == NULL) flag = false;
        }
        return true;
    }
    bool isFull() {
        if (left == NULL && right == NULL) return true;
        else if (left && right) return (left->isFull() && right->isFull());
        else return false;
    }
    int maxval() {
        int mx = data;
        if (left) mx = max(mx, left->maxval());
        if (right) mx = max(mx, right->maxval());
        return mx;
    }
    int minval() {
        int mn = data;
        if (left) mn = min(mn, left->minval());
        if (right) mn = min(mn, right->minval());
        return mn;
    }

    bool isBinarySearchTree() {
        bool flag = true;
        int lmx = INT_MIN;
        int rmn = INT_MAX;
        if (left) {
            lmx = left->maxval();
        }
        if (right) {
            rmn = right->minval();
        }
        if (data > lmx && data < rmn) {
            if (left) flag = flag && left->isBinarySearchTree();
            if (right) flag = flag && right->isBinarySearchTree();
            return flag;
        }
        else return false;
    }
    void inorder(vector<E>&tmp) {
        if (left) left->inorder(tmp);
        tmp.push_back(data);
        if (right) right->inorder(tmp);
    }
    void preorder(vector<E>&tmp) {
        tmp.push_back(data);
        if (left) left->preorder(tmp);
        if (right) right->preorder(tmp);
    }
    void postorder(vector<E>&tmp) {
        if (left) left->postorder(tmp);
        if (right) right->postorder(tmp);
        tmp.push_back(data);
    }
    BinaryTree<E>* gen_balance_tree(vector<E>&tmp, int l, int r) {
        if (r < 0 || l < 0 || l > r) return NULL;
        if (l == r) {
            return (new BinaryTree<E>(tmp[l], this));
        }
        int mid = (l + r) / 2;
        BinaryTree<E>* new_root = new BinaryTree<E>(tmp[mid], this);
        new_root->left = gen_balance_tree(tmp, l, mid - 1);
        new_root->right = gen_balance_tree(tmp, mid + 1, r);
        return new_root;
    }
    BinaryTree<E>* balance_tree(BinaryTree<E> *root) {
        vector<E>tmp;
        root->inorder(tmp);
        root = gen_balance_tree(tmp, 0, tmp.size() - 1);
        return root;
    }
};

int main() {
    // Create instances of BinaryTree class
    BinaryTree<int> root(5); // Root node with value 5

    // Populate the tree with nodes
    root.ins(3);
    root.ins(7);
    root.ins(2);
    root.ins(4);
    root.ins(6);
    root.ins(8);
    root.ins(10);
    root.ins(9);
    root.ins(11);

    // Displaying properties of the tree
    cout << "Height of the tree: " << root.height() << endl;
    cout << "Is the tree balanced? " << (root.isBalanced() ? "Yes" : "No") << endl;
    cout << "Is the tree complete? " << (root.isComplete() ? "Yes" : "No") << endl;
    cout << "Is the tree full? " << (root.isFull() ? "Yes" : "No") << endl;
    cout << "Is the tree a binary search tree? " << (root.isBinarySearchTree() ? "Yes" : "No") << endl;

    // Perform tree traversals
    vector<int> inorder_result;
    root.inorder(inorder_result);
    cout << "Inorder traversal: ";
    for (int val : inorder_result) {
        cout << val << " ";
    }
    cout << endl;

    vector<int> preorder_result;
    root.preorder(preorder_result);
    cout << "Preorder traversal: ";
    for (int val : preorder_result) {
        cout << val << " ";
    }
    cout << endl;

    vector<int> postorder_result;
    root.postorder(postorder_result);
    cout << "Postorder traversal: ";
    for (int val : postorder_result) {
        cout << val << " ";
    }
    cout << endl;

    // Balance the tree and display properties after balancing
    BinaryTree<int>* balanced_root = root.balance_tree(&root);
    cout << "Height of the balanced tree: " << balanced_root->height() << endl;
    cout << "Is the tree balanced? " << (balanced_root->isBalanced() ? "Yes" : "No") << endl;
    cout << "Is the balanced tree complete? " << (balanced_root->isComplete() ? "Yes" : "No") << endl;
    cout << "Is the balanced tree full? " << (balanced_root->isFull() ? "Yes" : "No") << endl;
    cout << "Is the balanced tree a binary search tree? " << (balanced_root->isBinarySearchTree() ? "Yes" : "No") << endl;

    // Free memory by deleting the balanced root
    delete balanced_root;

    return 0;
}
