#include <iostream>

using namespace std;

struct Node {
    int val;
    struct Node* left, * right;
};

Node* rotateLeft(Node* root) {
    Node* tmp = root->right;
    root->right = tmp->left;
    tmp->left = root;
    return tmp;
}

Node* rotateRight(Node* root) {
    Node* tmp = root->left;
    root->left = tmp->right;
    tmp->right = root;
    return tmp;
}

Node* rotateLeftRight(Node* root) {
    root->left = rotateLeft(root->left);
    return rotateRight(root);
}

Node* rotateRightLeft(Node* root) {
    root->right = rotateRight(root->right);
    return rotateLeft(root);
}

int getHeight(Node* root) {
    if (root == NULL) return 0;
    return max(getHeight(root->left), getHeight(root->right)) + 1;
}

Node* Insert(Node* root, int val) {
    if (root == NULL) {
        root = new Node();
        root->val = val;
        root->left = root->right = NULL;
    }
    else if (val < root->val) {
        root->left = Insert(root->left, val);
        if (getHeight(root->left) - getHeight(root->right) == 2)
            root = val < root->left->val ? rotateRight(root) : rotateLeftRight(root);
    }
    else {
        root->right = Insert(root->right, val);
        if (getHeight(root->right) - getHeight(root->left) == 2)
            root = val > root->right->val ? rotateLeft(root) : rotateRightLeft(root);
    }
    return root;
}

int main() {
    Node* root = nullptr;
    int n, val;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> val;
        root = Insert(root, val);
    }
    cout << root->val;
}