/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> outerVector;
        if(root==nullptr){
            return outerVector;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int queueSize=q.size();
            vector<int> innerVector;
            for(int i=0;i<queueSize;i++){
                TreeNode* temp=q.front();
                q.pop();
                innerVector.push_back(temp->val);
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            outerVector.push_back(innerVector);
        }
        return outerVector;
    }
    
};