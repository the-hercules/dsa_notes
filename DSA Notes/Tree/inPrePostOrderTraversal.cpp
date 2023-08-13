
// create binary tree

#include <bits/stdc++.h>
using namespace std;

class node {
    // binary tree ki node,ek data or 2 agal bagal wali
   public:
    int data;
    node* left;
    node* right;

    node(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

node* buildTree(node* root) {
    cout << "Enter data" << endl;
    int data;
    cin >> data;
    root = new node(data);
    // stopping condition
    if (data == -1) {
        return nullptr;
    }
    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);
    return root;
}

void inOrder(node* root) {
    // LNR(Left NodePrint Right)

    // base case of recursion
    if (root == nullptr) {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
void preOrder(node* root) {
    //NLR(NodePrint Left Right)
    // base case of recursion
    if (root == nullptr) {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
void postOrder(node* root) {
    //LRN(Left Right NodePrint)

    // base case of recursion
    if (root == nullptr) {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main() {
    node* root = nullptr;
    root = buildTree(root);
    inOrder(root);
    // cout<<endl;
    // preOrder(root);
    // cout<<endl;
    // postOrder(root);
}

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1