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
// ek level ke sare print karate chalo
void levelOrderTraversal(node* root) {
    queue<node*> treeData;
    // pehle root daal do
    treeData.push(root);
    treeData.push(nullptr);
    while (!treeData.empty()) {
        node* temp = treeData.front();
        treeData.pop();
        //jab bhi nullptr mil raha hai matlab ki ek line ho gayi puri,or uske sare child bhi ab queue
        //mai hai to agar queue null nahi hui to uske childs ke peechey ek nullptr pushkardo
        //jab tak nullptr ayega to ek level print ho jayega phir khali tab bhi na ho queue
        //to uske child ke aage bhi pushkardo nullptr
        if (temp==nullptr) {
            cout << endl;
            if (!treeData.empty()) {
                treeData.push(nullptr);
            }
        } else {
            cout << temp->data << " ";
            // agar root ke left ya right mai data ho to use queue mai push kardo
            // and chalte jao
            if (temp->left) {
                treeData.push(temp->left);
            }
            if (temp->right) {
                treeData.push(temp->right);
            }
        }
    }
}
// void reverseLevelOrderTraversal(node* root){
//     deque<node*> dq;
//     dq.push_back(root);
//     while(!dq.empty()){
//         node*temp=dq.front();
//         dq.pop_front();
//         if(temp->left){
//             dq.push_back(temp->left);
//         }
//         if(temp->right){
//             dq.push_back(temp->right);
//         }
//     }
//     while(!dq.empty()){
//         node*temp=dq.back();
//             cout<<temp->data<<" ";
//         dq.pop_back();
//     }
// }

void reverseLevelOrderTraversal(node* root) {
    if (!root) {
        return;
    }

    queue<node*> q;
    stack<node*> s;

    q.push(root);

    while (!q.empty()) {
        node* temp= q.front();
        q.pop();
        s.push(temp);

        if (temp->left) {
            q.push(temp->left);
        }
        if (temp->right) {
            q.push(temp->right);
        }
    }

    while (!s.empty()) {
        node * temp= s.top();
        s.pop();
        std::cout <<temp->data<< " ";
    }
}

int main() {
    node* root = nullptr;
    root = buildTree(root);
    // levelOrderTraversal(root);

    reverseLevelOrderTraversal(root);
}

//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1