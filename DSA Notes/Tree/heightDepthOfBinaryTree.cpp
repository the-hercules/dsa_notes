
//height is longest path between root and leaf node.


//recursive way

#include<bits/stdc++.h>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        int depth=0;
        if(!root){
            return 0;
        }
        depth=max(maxDepth(root->left),maxDepth(root->right))+1;
    return depth;
    }
   
};

//iterative way using levelOrderTraversal

class Solution {
public:
int levelOrderTraversal(TreeNode* root){
    if (root==nullptr){
        return 0;
    }
    int level=0;
    queue<TreeNode*>q;
    q.push(root);
    q.push(nullptr);
    while(!q.empty()){
        TreeNode* temp=q.front();
        q.pop();
        if(temp==nullptr){
            level++;
            if(!q.empty()){
                q.push(nullptr);
            }
        }
        else{
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
        }

    }
    return level;
}

    int maxDepth(TreeNode* root) {
       int depth=levelOrderTraversal(root);

       return depth;
       
    }
};