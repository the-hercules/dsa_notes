 #include<bits/stdc++.h>
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
//for every node max of left or right node is returned
//for every node max curve path is calcuated  by its own value and maxleft and maxright sum
    int maxPathSumHelper(TreeNode* root,int &maxi){
        if(root==nullptr){
            return 0;
        }
        //here we have added max(0,...) so that negative sum is not returned.

       int  leftSum=max(0,maxPathSumHelper(root->left,maxi));
        int rightSum=max(0,maxPathSumHelper(root->right,maxi));
        maxi=max(maxi,root->val+(leftSum+rightSum));
        return root->val+max(leftSum,rightSum); 
    }
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        maxPathSumHelper(root,maxi);
        return maxi;

    }
};